#!/usr/bin/env python3
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
    """C for a token: 'E$aN' (index into the caller's registers) or a symbolic
    value; None when not expressible."""
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


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sigs", default=str(ROOT / "build/port-i386/host_sigs.json"))
    ap.add_argument("--asm", default=str(ROOT / "asm/main.s"))
    ap.add_argument("--out", default=str(HERE / "r12_indirect.csv"))
    a = ap.parse_args()
    canon = json.load(open(a.sigs))["canon"]
    byaddr = {}
    for n in canon:
        m = re.search(r"_([0-9A-Fa-f]{8})$", n)
        if m:
            byaddr[int(m.group(1), 16)] = n
    tabs = tables(a.asm)
    funcs = G.parse_asm(a.asm)
    ind = {}
    G.flow(funcs, ind)
    srcs = sorted({r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv")) if r["source"].endswith(".c")})
    rows, skipped = [], []
    for s in srcs:
        txt = (ROOT / s).read_text(encoding="latin-1")
        defs = [(m.start(), m.group(1), m.group(2)) for m in FDEF.finditer(txt)]
        found = []
        for m in CALL.finditer(txt):
            t = m.group(1)
            ent = [x for x in tabs.get(t, []) if x in byaddr]
            npar = max([len(canon[byaddr[x]]["params"]) for x in ent] or [0])
            if npar == 0:
                continue
            d = [x for x in defs if x[0] < m.start()]
            if not d:
                continue  # a declaration at file scope
            st, fn, plist = d[-1]
            if fn not in funcs or fn not in canon:
                continue
            found.append((fn, m.group(0), npar, param_names(plist), st))
        for fn, call, npar, names, st in found:
            # this function's indirect jumps through a table of functions (not switches)
            body = funcs[fn]
            sites = []
            for k, snap in ind.get(fn, []):
                sym = None
                for j in range(k - 1, max(-1, k - 12), -1):
                    x = body[j]
                    mm = re.search(r"%(?:hi|lo|gp_rel)\(((?:D|jtbl|data)_\w+)\)", x[2]) if x[0] == "I" else None
                    if mm:
                        sym = mm.group(1)
                        break
                if sym and any(v in byaddr for v in tabs.get(sym, [])):
                    sites.append((sym, snap))
            same = [x for x in sites if x[0] == call.split("[")[0].strip()]
            if len(same) != 1 or sum(1 for f2, c2, *_ in found if f2 == fn and c2.split("[")[0] == call.split("[")[0]) != 1:
                skipped.append((s, fn, call, "%d asm sites" % len(same)))
                continue
            snap = same[0][1]
            freg = G.regs(canon[fn]["params"])
            end = txt.find("\n}", st)
            fbody = txt[st:end]
            args = []
            for r in G.ARGR[:npar]:
                tok = snap.get(r, "X")
                if re.fullmatch(r"E\$\w+", tok) and tok[1:] in freg:
                    tok = "P%d" % freg.index(tok[1:])
                elif G.sym_add(tok, 0) and all(x in freg for x in re.findall(r"E(\$\w+)", tok)):
                    tok = re.sub(r"E(\$\w+)", lambda mm: "P%d" % freg.index(mm.group(1)), tok)
                else:
                    tok = None
                c = render(tok, names, fbody) if tok else None
                args.append(c if c else "0")
            while args and args[-1] == "0":
                args.pop()
            if not args:
                skipped.append((s, fn, call, "nothing known"))
                continue
            if txt.count(call) != 1:
                skipped.append((s, fn, call, "text not unique"))
                continue
            rows.append((s, fn, call, ", ".join(args)))
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["source", "caller", "call", "args"])
        for r in rows:
            w.writerow(r)
    print(f"{a.out}: {len(rows)} indirect call sites; skipped {len(skipped)}")
    for x in skipped:
        print("  skipped", *x)


if __name__ == "__main__":
    main()
