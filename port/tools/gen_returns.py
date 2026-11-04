#!/usr/bin/env python3
"""R24 return values (Port J): port/tools/r12_returns.csv.

The credited C sometimes drops a value the EE code returns:
- a non-void function falls off the end (hostify R14 adds `return 0;`) or
  says `return;` while the asm leaves the last callee's result in $v0;
- a function credited `void` whose callers use its value (hostify R12
  wraps those calls as `(f(), 0)`), where the asm returns with $v0 = the
  last callee's result (a tail call, or a jal / jalr then `jr $ra`).
This tool reads, for every such function, what $v0 holds at each return
(the value dataflow of gen_regpass with callee summaries): the result of
the call at body index k ("call X", "icall" through a table), a constant,
the caller's own $v0 (garbage), or something else; and whether any caller
uses the value (asm: $v0 read after the call before it is redefined, or
returned on to a caller that uses it; through tail calls and dispatch
tables; a function whose address is stored is assumed used).

Output (one row per function): function, source, why (r14 / bare / wrap),
v0 (the exit tokens, `;`-joined), used (yes / no / callback), action:
  return-last   every return path ends in a call (direct or through a
                table) whose $v0 is returned: hostify R24 makes the host
                return that call's value (the callee too, if it is void)
  const:N       every return path returns the constant N
  harmless      no caller uses the value
  left          anything else (reason in v0)

usage: gen_returns.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV]
"""
import argparse, collections, csv, json, re, sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
import gen_regpass as G

FDEF = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(([^;{}]*)\)\s*\{", re.M)


def fn_at_lines(text):
    """[(first line, last line, name)] of the function definitions."""
    out = []
    for m in FDEF.finditer(text):
        i = text.index("{", m.end() - 1)
        d, k = 0, i
        while k < len(text):
            if text[k] == "{":
                d += 1
            elif text[k] == "}":
                d -= 1
                if d == 0:
                    break
            k += 1
        out.append((text.count("\n", 0, m.start()) + 1, text.count("\n", 0, k) + 1, m.group(1)))
    return out


def explicit_returns(src, name):
    """the integer literals of `return N;` statements in name's C body (src
    relative to the repository), or None when the body is not found"""
    try:
        text = (ROOT / src).read_text(encoding="latin-1")
    except OSError:
        return None
    for m in FDEF.finditer(text):
        if m.group(1) != name:
            continue
        i = text.index("{", m.end() - 1)
        d, k = 0, i
        while k < len(text):
            if text[k] == "{":
                d += 1
            elif text[k] == "}":
                d -= 1
                if d == 0:
                    break
            k += 1
        return {int(x, 0) for x in re.findall(r"\breturn\s+\(?\s*(-?(?:0x[0-9A-Fa-f]+|\d+))\s*\)?\s*;", text[i:k])}
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sigs", default=str(ROOT / "build/port-i386/host_sigs.json"))
    ap.add_argument("--asm", default=str(ROOT / "asm/main.s"))
    ap.add_argument("--out", default=str(HERE / "r12_returns.csv"))
    a = ap.parse_args()
    sigs = json.load(open(a.sigs))
    canon = sigs["canon"]
    funcs = G.parse_asm(a.asm, G.load_starts(), G.jtbl_targets(a.asm))
    jt = G.parse_jtbls(a.asm)
    G.load_dtables(a.asm)
    # a D_ table that runs straight on into the next D_ table of functions is
    # one table (D_00448E30: 7 handlers, a 0, then D_00448E50's 35 handlers,
    # all indexed by func_00185010's p[7]); for "is the value used" and the
    # void entries this errs on the side of more entries
    starts, sizes = {}, {}
    cur = None
    for l in open(a.asm):
        m = re.match(r"dlabel (\S+)", l)
        if m:
            cur = m.group(1)
            continue
        if l.startswith("enddlabel"):
            cur = None
            continue
        m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]+ \*/\s+\.word", l)
        if cur and m:
            starts.setdefault(cur, int(m.group(1), 16))
            sizes[cur] = sizes.get(cur, 0) + 4
    byaddr = {v: k for k, v in starts.items()}
    for name in list(G.DTABLES):
        ent, nxt = list(G.DTABLES[name]), name
        while nxt in starts and starts[nxt] + sizes[nxt] in byaddr:
            nxt = byaddr[starts[nxt] + sizes[nxt]]
            if nxt not in G.DTABLES:
                break
            ent += G.DTABLES[nxt]
        G.DTABLES[name] = ent
    G.vflow(funcs)
    summ = G.vflow.summ
    owner = {r["name"]: r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv"))}
    asmtext = open(a.asm).read()
    addr_taken = set(re.findall(r"%lo\((\w+)\)", asmtext))

    # targets
    want = collections.defaultdict(set)     # F -> {why}
    for path, lines in sigs["noreturn"].items():
        spans = fn_at_lines((ROOT / path).read_text(encoding="latin-1"))
        for ln in lines:
            for lo, hi, name in spans:
                if lo <= ln <= hi:
                    want[name].add("r14")
    for path, lines in sigs.get("bare_return", {}).items():
        spans = fn_at_lines((ROOT / path).read_text(encoding="latin-1"))
        for ln in lines:
            for lo, hi, name in spans:
                if lo <= ln <= hi:
                    want[name].add("bare")
    for path, names in sigs["wrap"].items():
        for n in names:
            want[n].add("wrap")

    # who calls / tail-calls / dispatches whom
    cfg = {F: G._cfg(body, jt) for F, body in funcs.items()}
    jal_sites = collections.defaultdict(list)   # callee -> [(G, ins index of the call)]
    tail_sites = collections.defaultdict(list)  # callee -> [G]
    disp_reg = collections.defaultdict(set)     # table entry -> registers it is reached through
    direct = collections.Counter()              # callee -> direct jal / j sites
    for F, (ins, lab, jr_tab) in cfg.items():
        for k, (op, opr) in enumerate(ins):
            t = opr.split(",")[-1].strip()
            if op == "jal":
                jal_sites[t].append((F, k))
                direct[t] += 1
            elif op == "j" and t not in lab:
                tail_sites[t].append(F)
                direct[t] += 1
            elif op == "jalr" and jr_tab.get(k):
                for e in jr_tab[k]:
                    if G.text_entry(e):
                        jal_sites[G.fname(e)].append((F, k))
                        disp_reg[G.fname(e)].add(opr.strip())
            elif op == "jr" and opr.strip() != "$ra" and jr_tab.get(k) and \
                    not any(e == -1 or ".L%08X" % e in lab for e in jr_tab[k]):
                for e in jr_tab[k]:
                    if G.text_entry(e):
                        tail_sites[G.fname(e)].append(F)
                        disp_reg[G.fname(e)].add(opr.strip())

    def v0_defs(F):
        """the instructions whose $v0 may reach a return of F (a call
        counts as defining $v0; "entry" = the caller's $v0)."""
        ins, lab, jr_tab = cfg[F]
        n = len(ins)
        IN = [None] * (n + 1)
        out = set()
        work = [(0, frozenset(["entry"]))]
        while work:
            i, st = work.pop()
            if i >= n:
                continue
            if IN[i] is not None and st <= IN[i]:
                continue
            st = st | (IN[i] or frozenset())
            IN[i] = st
            op, opr = ins[i]
            t = opr.split(",")[-1].strip()
            if op in ("jal", "jalr"):
                work.append((i + 2, frozenset([i])))
                continue
            if op in G.COND or op in ("b", "j", "jr"):
                dl = ins[i + 1] if i + 1 < n else ("nop", "")
                st2 = frozenset([i + 1]) if "$v0" in G._ud(*dl)[1] else st
                if op == "jr" and opr.strip() == "$ra":
                    out |= st2
                    continue
                if op == "j" and t not in lab:
                    out.add(i)             # tail call: the callee's $v0
                    continue
                if op == "jr":
                    tab = jr_tab.get(i)
                    if tab and not any(e == -1 or ".L%08X" % e in lab for e in tab):
                        out.add(i)         # tail jump through a dispatch table
                    else:
                        for idx in set(lab.values()):
                            work.append((idx, st2))
                    continue
                if t in lab:
                    work.append((lab[t], st2))
                if op not in ("b", "j"):
                    # the likely-branch delay slot runs only when taken
                    work.append((i + 2, st if op.endswith("l") and op in G.COND else st2))
                continue
            if "$v0" in G._ud(op, opr)[1] or op == "syscall":
                st = frozenset([i])
            work.append((i + 1, st))
        return out

    memo = {}

    def after_call_uses(F, k):
        """$v0 read after the call at ins index k of F (its delay slot is k+1)."""
        ins, lab, jr_tab = cfg[F]
        n = len(ins)
        work, seen = [k + 2], set()
        while work:
            i = work.pop()
            if i >= n or i in seen:
                continue
            seen.add(i)
            op, opr = ins[i]
            u, d = G._ud(op, opr)
            if "$v0" in u:
                return True
            if op in ("jal", "jalr"):
                dl = ins[i + 1] if i + 1 < n else ("nop", "")
                if "$v0" in G._ud(*dl)[0]:
                    return True
                continue        # the callee sets $v0
            if op in G.COND or op in ("b", "j", "jr"):
                dl = ins[i + 1] if i + 1 < n else ("nop", "")
                du, dd = G._ud(*dl)
                if "$v0" in du:
                    return True
                if "$v0" in dd:
                    continue
                t = opr.split(",")[-1].strip()
                if op == "jr" and opr.strip() == "$ra":
                    if v0_used(F):
                        return True
                    continue
                if op == "jr" or (op == "j" and t not in lab):
                    continue
                if t in lab:
                    work.append(lab[t])
                if op not in ("b", "j"):
                    work.append(i + 2)
                continue
            if "$v0" in d:
                continue
            work.append(i + 1)
        return False

    def v0_used(F):
        if F in memo:
            return memo[F]
        memo[F] = False         # recursion: assume unused while in progress
        r = F in addr_taken
        if not r:
            for (Gn, k) in jal_sites.get(F, ()):
                if after_call_uses(Gn, k):
                    r = True
                    break
        if not r:
            for Gn in tail_sites.get(F, ()):
                if v0_used(Gn):
                    r = True
                    break
        memo[F] = r
        return r

    hostimpl = set()
    for l in open(ROOT / "port/host/host_impl.csv"):
        if l.strip() and not l.startswith(("#", "name,")):
            hostimpl.add(l.split(",")[0].strip())
    rows = {}
    deps = {}
    queue = sorted(want)
    while queue:
        F = queue.pop(0)
        if F in rows:
            continue
        body = funcs.get(F)
        why = ";".join(sorted(want[F]))
        src = owner.get(F, "")
        if body is None:
            rows[F] = (F, src, why, "no asm", "?", "left")
            continue
        defs = v0_defs(F)
        used = "callback" if F in addr_taken else ("yes" if v0_used(F) else "no")
        toks, kinds = [], set()
        for d in sorted(defs, key=str):
            if d == "entry":
                toks.append("caller's $v0")
                kinds.add("garbage")
                continue
            op, opr = cfg[F][0][d]
            if op in ("jal", "j"):
                X = opr.strip()
                toks.append("call " + X)
                kinds.add("call")
                if used != "no" and canon.get(X, {}).get("ret") == "void" and X not in hostimpl:
                    want[X].add("void callee of " + F)
                    queue.append(X)
            elif op in ("jalr", "jr"):
                toks.append("icall")
                kinds.add("call")
                for e in (cfg[F][2].get(d) or ()):
                    X = G.fname(e) if G.text_entry(e) else None
                    if X and used != "no" and canon.get(X, {}).get("ret") == "void" and X not in hostimpl:
                        want[X].add("void table entry of " + F)
                        queue.append(X)
            elif op == "syscall":
                toks.append("syscall")
                kinds.add("syscall")
            else:
                mk = re.fullmatch(r"(?:addiu|daddiu|ori)\s*\$v0, \$zero, (-?\w+)", op + " " + opr) or \
                    re.fullmatch(r"(?:daddu|addu|or)\s*\$v0, \$zero, \$zero", op + " " + opr)
                if mk:
                    toks.append("const %d" % (int(mk.group(1), 0) if mk.groups() and mk.group(1) else 0))
                    kinds.add("const")
                else:
                    toks.append("%s %s" % (op, opr))
                    kinds.add("other")
        if F in hostimpl:
            act = "host"
        elif not src:
            act = "left"            # no credited definition under this name (an alias)
            toks.append("alias: no credited definition")            # the port implements F (host_impl.csv, `ret` column)
        elif used == "no":
            act = "harmless"
        elif kinds and kinds <= {"call", "garbage"} and "call" in kinds:
            act = "return-last"     # a garbage path (caller's $v0) returns 0, as before
        elif kinds and kinds <= {"call", "garbage", "const"} and "call" in kinds and \
                {int(t.split()[1]) for t in toks if t.startswith("const ")} <= (explicit_returns(src, F) or set()):
            # every constant is an explicit `return N;` in the C (kept as it
            # is); where the C falls off the end, $v0 is the last call's
            # (oracle fuzz seed 8: func_00164C50, script opcode 38, returns
            # func_00164E90's 1 and func_00169600 steps again that frame)
            act = "return-last"
        elif kinds == {"const"} and len(set(toks)) == 1:
            act = "const:" + toks[0].split()[1]
        else:
            act = "left"
        if act == "left" and toks == ["caller's $v0"]:
            act = "transparent"     # never sets $v0: callers keep their own
        rows[F] = (F, src, why, ";".join(sorted(set(toks))), used, act)
        deps[F] = defs
    # fixpoint: return-last needs every reaching call to give a host value:
    # a direct callee that is non-void (not float), R24 itself, or
    # transparent; table entries non-void or R24
    def hret(X):
        r = canon.get(X, {}).get("ret")
        if r is None:
            return None
        if X in rows and (rows[X][5] == "return-last" or rows[X][5].startswith("const:")):
            return "int"
        return r
    # a call of a function that never sets $v0 passes the caller's own $v0
    # through: such a def is the caller's entry $v0
    trans = {F for F, r in rows.items() if r[5] == "transparent"}
    changed = True
    while changed:
        changed = False
        for F, row in list(rows.items()):
            if row[5] not in ("return-last", "left"):
                continue
            nd = set()
            for d in deps[F]:
                if d != "entry" and cfg[F][0][d][0] in ("jal", "j") and cfg[F][0][d][1].strip() in trans:
                    nd.add("entry")
                else:
                    nd.add(d)
            if nd != deps[F]:
                deps[F] = nd
                if nd == {"entry"}:
                    rows[F] = row[:3] + ("caller's $v0 (through " + row[3] + ")", row[4], "transparent")
                    trans.add(F)
                changed = True
    # a transparent function reached only through `jalr $v0` / `jr $v0`
    # returns its own address (the dispatcher's $v0 is the entry it loaded)
    for F in sorted(trans):
        if rows[F][4] != "no" and not direct[F] and disp_reg.get(F) == {"$v0"} and F not in addr_taken:
            ad = int(F.rsplit("_", 1)[1], 16)
            rows[F] = rows[F][:3] + (rows[F][3] + "; entered through jalr/jr $v0", rows[F][4], "const:0x%X" % ad)
    changed = True
    while changed:
        changed = False
        for F, row in list(rows.items()):
            if row[5] != "return-last":
                continue
            bad = []
            for d in deps[F]:
                if d == "entry":
                    continue
                op, opr = cfg[F][0][d]
                if op in ("jal", "j"):
                    X = opr.strip()
                    if X in rows and rows[X][5] == "transparent":
                        continue
                    if hret(X) in (None, "void", "float", "double"):
                        bad.append(X)
                elif op in ("jalr", "jr"):
                    for e in (cfg[F][2].get(d) or ()):
                        if G.text_entry(e) and hret(G.fname(e)) in (None, "void", "float", "double"):
                            bad.append(G.fname(e))
            if bad:
                rows[F] = row[:5] + ("left",)
                rows[F] = (row[0], row[1], row[2], row[3] + "; no host value from " + " ".join(sorted(set(bad))[:4]),
                           row[4], "left")
                changed = True
    rows = [rows[F] for F in sorted(rows)]
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["function", "source", "why", "v0", "used", "action"])
        for r in rows:
            w.writerow(r)
    c = collections.Counter(r[5].split(":")[0] for r in rows)
    print(f"{a.out}: {len(rows)} functions: " + ", ".join(f"{k} {v}" for k, v in sorted(c.items())))


if __name__ == "__main__":
    main()
