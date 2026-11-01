#!/usr/bin/env python3
"""R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with no arguments,
`D_004C1EA8[p[5]]();`, where the EE code jumps (jalr, or a tail `jr`) with
$a0.. still holding the caller's values, and the table's entries read them
(func_003A5790(p, q)).  A host compiler passes nothing, so the callee reads
garbage.  This tool finds those sites: the call's table (asm/main.s) lists
functions whose canonical prototypes take arguments, and the dataflow over
the caller's asm (gen_regpass.flow) says what each argument register holds
at the indirect jump: the caller's parameter, or a value derived from it
("p + k", loads through it; see r12_regsym.csv).  One row per site:
  source, caller, call (exact text), args (C, comma separated)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV]
"""R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""
import argparse, csv, json, re, sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))
import gen_regpass as G

CALL = re.compile(r"(\w+)\s*\[((?:[^\[\]]|\[[^\[\]]*\])*)\]\s*\(\s*\)")
FDEF = re.compile(r"^[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(([^;{}]*)\)\s*\{", re.M)


def tables(path):
    out, cur = {}, None
    for l in open(path):
        m = re.match(r"(?:dlabel|glabel) ((?:D|jtbl|data)_\w+)", l)
        if m:
            cur = m.group(1)
            out[cur] = []
            continue
        if cur and l.startswith(("enddlabel", "endlabel")):
            cur = None
            continue
        if cur:
            m = re.search(r"\.word\s+(\S+)", l)
            if m:
                mm = re.fullmatch(r"(?:func|residual)_([0-9A-Fa-f]{8})", m.group(1))
                out[cur].append(int(mm.group(1), 16) if mm else -1)
    return out


def param_names(plist):
    names = []
    for p in plist.split(","):
        p = p.strip()
        if not p or p == "void" or p == "...":
            continue
        m = re.search(r"(\w+)\s*(?:\[[^\]]*\])?$", p)
        names.append(m.group(1) if m else "")
    return names


def modified(body, name):
    return re.search(r"(?<![\w.>])%s\s*(?:[-+*/|&^%%]|<<|>>)?=(?!=)|(?<![\w.>])%s\s*(?:\+\+|--)|(?:\+\+|--|&)\s*%s\b"
                     % ((re.escape(name),) * 3), body) is not None


def render(tok, names, body):
    """R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""C for a token: 'E$aN' (index into the caller's registers) or a symbolic
    value; None when not expressible."""R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""
    if "@" in tok and tok.rfind("@") > tok.rfind(")"):
        base, off = tok.rsplit("@", 1)
        off = int(off)
    else:
        base, off = tok, 0
    m = re.fullmatch(r"P(\d+)", base)
    if m:
        q = int(m.group(1))
        if q >= len(names) or not names[q] or modified(body, names[q]):
            return None
        b = names[q] if not off else "(__UINTPTR_TYPE__)(%s)" % names[q]
    else:
        m = re.fullmatch(r"(\w+)\((.*)\)", base)
        T = {"lw": "unsigned int", "lh": "short", "lhu": "unsigned short", "lb": "signed char", "lbu": "unsigned char"}
        if not m or m.group(1) not in T:
            return None
        inner = render(m.group(2) if "@" in m.group(2) or not m.group(2).startswith("P") else m.group(2) + "@0",
                       names, body)
        if inner is None:
            return None
        b = "(__UINTPTR_TYPE__)(*(%s *)(__UINTPTR_TYPE__)(%s))" % (T[m.group(1)], inner)
    return "(%s + %d)" % (b, off) if off else b


def _args(txt, start):
    """R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""(argument texts, end index) of the call whose '(' is at start."""R12 for indirect calls (Port J): port/tools/r12_indirect.csv.

The decomp often writes a call through a function table with fewer
arguments than the entries read, `D_004C1EA8[p[5]]();`, where the EE code
jumps (jalr, or a tail `jr`) with $a0.. still holding the caller's values.
A host compiler passes nothing, so the callee reads garbage (0 under
EMULATE_FUNCTION_POINTER_CASTS).  This tool finds those sites: the asm
liveness (gen_regpass.liveness) of the table's entries says which of
$a0..$a3 they read beyond the C arguments, and the dataflow over the
caller's asm (gen_regpass.flow + value tokens with callee summaries) says
what each register holds at the indirect jump: the caller's parameter, a
widened parameter (`__rpN`: R20, or R23 = gen_regpass widened the caller for
this call, r12_tblfwd.csv), or a value derived from it ("p + k", loads
through it).  One row per site:
  source, caller, call (exact text), args (C, comma separated, all of them)
hostify applies each row as a text replacement inside that source (like
host_overrides.py) and casts the table entry to an unprototyped pointer.
R22 dispatch heads are left to hostify's tail forwarding.  Run after
gen_regpass.py (it reads r12_widen.csv / r12_tailfwd.csv).  --report CSV
lists every table call whose entries read more than the C passes, with what
was done (row / R22 / unresolved: the register's value token).

usage: gen_indirect.py [--sigs host_sigs.json] [--asm asm/main.s] [--out CSV] [--report CSV]
"""
    d, k, cur, out = 0, start, [], []
    while k < len(txt):
        c = txt[k]
        if c in "([":
            d += 1
            if d == 1:
                k += 1
                continue
        elif c in ")]":
            d -= 1
            if d == 0:
                break
        elif c == "," and d == 1:
            out.append("".join(cur).strip())
            cur = []
            k += 1
            continue
        cur.append(c)
        k += 1
    last = "".join(cur).strip()
    if last or out:
        out.append(last)
    return out, k + 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sigs", default=str(ROOT / "build/port-i386/host_sigs.json"))
    ap.add_argument("--asm", default=str(ROOT / "asm/main.s"))
    ap.add_argument("--out", default=str(HERE / "r12_indirect.csv"))
    ap.add_argument("--report", help="also write every table call whose entries read more argument "
                    "registers than the C passes, with what was done (csv)")
    a = ap.parse_args()
    canon = json.load(open(a.sigs))["canon"]
    byaddr = {}
    for n in canon:
        m = re.search(r"_([0-9A-Fa-f]{8})$", n)
        if m:
            byaddr[int(m.group(1), 16)] = n
    widen = {r["function"]: r["params"].split(";") for r in csv.DictReader(open(HERE / "r12_widen.csv"))}
    tailfwd = {r["function"] for r in csv.DictReader(open(HERE / "r12_tailfwd.csv"))}
    tabs = tables(a.asm)
    funcs = G.parse_asm(a.asm, G.load_starts(), G.jtbl_targets(a.asm))
    jt = G.parse_jtbls(a.asm)
    G.load_dtables(a.asm)
    live = G.liveness(funcs, jt)
    ind = {}
    G.flow(funcs, ind)
    # entry values that survive a call (callee exit summaries)
    G.vflow(funcs)
    vind = G.ind_vtokens(funcs, G.vflow.summ, list(ind))
    for F in ind:
        ind[F] = [(k, {r: (vind.get(F, {}).get(k, {}).get(r, "X")
                           if vind.get(F, {}).get(k, {}).get(r, "X").startswith("E$") else snap.get(r, "X"))
                       for r in G.ARGR}) for k, snap in ind[F]]
    srcs = sorted({r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv")) if r["source"].endswith(".c")})
    rows, skipped, report = [], [], []
    for s in srcs:
        txt = (ROOT / s).read_text(encoding="latin-1")
        defs = [(m.start(), m.group(1), m.group(2)) for m in FDEF.finditer(txt)]
        found = []
        for m in CALL_ANY.finditer(txt):
            t = m.group(1)
            ent = [x for x in tabs.get(t, []) if x in byaddr and G.text_entry(x)]
            if not ent:
                continue
            cargs, end = _args(txt, m.end() - 1)
            d = [x for x in defs if x[0] < m.start()]
            if not d:
                continue  # a declaration at file scope
            st, fn, plist = d[-1]
            if fn not in funcs or fn not in canon:
                continue
            # argument registers some entry reads (asm liveness through its callees)
            rd = set()
            for x in ent:
                rd |= live.get(G.fname(x), set(G.ARGR))
            need = [r for r in G.ARGR[len(cargs):4] if r in rd]
            if not need:
                continue
            found.append((fn, txt[m.start():end], t, cargs, need, param_names(plist), st))
        for fn, call, t, cargs, need, names, st in found:
            rep = dict(source=s, caller=fn, call=call, passes=len(cargs), entries_read=";".join(need),
                       status="", args="")
            report.append(rep)
            if fn in tailfwd:
                rep["status"] = "R22 tail forwarding (hostify passes the head's parameters)"
                continue
            # this function's indirect jumps through table t
            body = funcs[fn]
            sites = []
            for k, snap in ind.get(fn, []):
                sym = None
                for j in range(k - 1, max(-1, k - 16), -1):
                    x = body[j]
                    if x[0] == "L":
                        break
                    if x[1] in G.STORE:
                        continue    # sw $v1, %gp_rel(D_004C29A4)($gp) between the table base and the jump
                    mm = re.search(r"%(?:hi|lo|gp_rel)\(((?:D|jtbl|data)_\w+)\)", x[2])
                    if mm and any(v in byaddr for v in tabs.get(mm.group(1), [])):
                        sym = mm.group(1)   # the first symbol back that is a table of functions
                        break
                if sym == t:
                    sites.append(snap)
            ncalls = sum(1 for f2, c2, t2, *_ in found if f2 == fn and t2 == t)
            if not sites or ncalls != 1:
                skipped.append((s, fn, call, "%d asm sites, %d C calls" % (len(sites), ncalls)))
                rep["status"] = "left: %d asm sites, %d C calls through %s" % (len(sites), ncalls, t)
                continue
            snap = {r: (sites[0][r] if all(x[r] == sites[0][r] for x in sites) else "X") for r in G.ARGR}
            params = widen.get(fn, canon[fn]["params"])
            freg = G.regs(params)
            allnames = names + ["__rp%d" % i for i in range(len(names), len(params))]
            end = txt.find("\n}", st)
            fbody = txt[st:end]
            extra, bad = [], []
            for r in G.ARGR[len(cargs):4]:
                # every register whose value is known is passed (the liveness
                # behind `need` is conservative the other way: a register no
                # entry reads is passed when known, 0 otherwise)
                tok = snap.get(r, "X")
                if re.fullmatch(r"E\$\w+", tok) and tok[1:] in freg:
                    tok = "P%d" % freg.index(tok[1:])
                elif G.sym_add(tok, 0) and all(x in freg for x in re.findall(r"E(\$\w+)", tok)):
                    tok = re.sub(r"E(\$\w+)", lambda mm: "P%d" % freg.index(mm.group(1)), tok)
                else:
                    tok = None
                c = render(tok, allnames, fbody) if tok else None
                if c is None and r in need:
                    bad.append("%s=%s" % (r, snap.get(r, "X")))
                extra.append(c if c else "0")
            while extra and extra[-1] == "0":
                extra.pop()
            if bad:
                rep["status"] = "unresolved " + " ".join(bad)
            if not extra:
                skipped.append((s, fn, call, "nothing known"))
                rep["status"] = rep["status"] or "nothing known"
                continue
            if txt.count(call) != 1:
                skipped.append((s, fn, call, "text not unique"))
                rep["status"] = "left: call text not unique"
                continue
            args = ", ".join(cargs + extra)
            rows.append((s, fn, call, args))
            rep["args"] = args
            rep["status"] = rep["status"] or "row"
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["source", "caller", "call", "args"])
        for r in sorted(rows):
            w.writerow(r)
    print(f"{a.out}: {len(rows)} indirect call sites; skipped {len(skipped)}")
    for x in skipped:
        print("  skipped", *x)
    if a.report:
        with open(a.report, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(report[0].keys()))
            w.writeheader()
            for r in sorted(report, key=lambda r: (r["source"], r["caller"], r["call"])):
                w.writerow(r)


CALL_ANY = re.compile(r"(\w+)\s*\[((?:[^\[\]]|\[[^\[\]]*\])*)\]\s*\(")


if __name__ == "__main__":
    main()
