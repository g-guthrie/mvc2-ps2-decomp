#!/usr/bin/env python3
"""R12 register passthrough table (Port J): port/tools/r12_regpass.csv.

When a credited C call passes fewer arguments than the callee's canonical
prototype, hostify R12 fills the missing ones.  The EE passed whatever the
argument registers held; very often that is the caller's own incoming
argument (`f(a, b) { g(); }` where g reads $a0/$a1).  This tool finds those
sites: it collects every padded call (hostify with HOSTIFY_PAD_LOG), runs a
forward dataflow over each caller's retail asm (asm/main.s: which entry
argument each argument register holds at every `jal`, through register
moves, joins over branches, clobbered by calls), and writes one row per
(source, caller, callee, missing arg) whose register holds the caller's
parameter `caller_param` at every call site.  Names and indices only.

usage: gen_regpass.py [--sigs build/port-i386/host_sigs.json] [--asm asm/main.s]
"""
import argparse, collections, csv, json, os, re, sys, tempfile
from pathlib import Path
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(HERE))

ARGR = ["$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3"] + ["$f%d" % i for i in range(12, 20)]
CALLER_SAVED = set(ARGR) | {"$v0", "$v1", "$at", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9", "$ra"} | \
    {"$f%d" % i for i in range(0, 20)}
STORE = {"sw", "sh", "sb", "sd", "sq", "swc1", "sdc1", "sqc2", "swl", "swr", "sdl", "sdr"}
COND = ("beq", "bne", "beqz", "bnez", "bgez", "bltz", "bgtz", "blez", "beql", "bnel", "beqzl", "bnezl",
        "bgezl", "bltzl", "bgtzl", "blezl", "bc1t", "bc1f", "bc1tl", "bc1fl")


def parse_asm(path):
    funcs, cur = {}, None
    for l in open(path):
        m = re.match(r"glabel (\S+)", l)
        if m:
            cur = m.group(1)
            funcs[cur] = []
            continue
        if cur is None:
            continue
        m = re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]+) [0-9A-F]+ \*/\s+(\S+)\s*(.*)$", l)
        if m:
            funcs[cur].append(("I", m.group(2), m.group(3).strip()))
            continue
        m = re.match(r"\s*(\.L[0-9A-Fa-f_]+):", l)
        if m:
            funcs[cur].append(("L", m.group(1), ""))
    return funcs


def transfer(st, op, opr):
    rs = re.findall(r"\$\w+", opr)
    if op in STORE or op in COND or op in ("b", "j", "jr", "nop", "sync", "sync.p", "syscall", "mthi",
                                            "mtlo", "ctc1", "teq", "tne") or not rs:
        return
    if op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1") and len(rs) == 2:
        return
    if op in ("mtc1", "dmtc1"):
        if len(rs) > 1:
            st[rs[1]] = "X"
        return
    if op == "mov.s" and len(rs) == 2:
        st[rs[0]] = st.get(rs[1], "X")
        return
    if op in ("daddu", "addu", "or") and len(rs) == 3 and rs[2] == "$zero":
        st[rs[0]] = st.get(rs[1], "X")
        return
    if op in ("daddu", "addu", "or") and len(rs) == 3 and rs[1] == "$zero":
        st[rs[0]] = st.get(rs[2], "X")
        return
    if op == "move" and len(rs) == 2:
        st[rs[0]] = st.get(rs[1], "X")
        return
    st[rs[0]] = "X"


def join(a, b):
    if a is None:
        return dict(b)
    return {k: (a.get(k, "X") if a.get(k, "X") == b.get(k, "X") else "X") for k in set(a) | set(b)}


def flow(funcs):
    """(caller, callee) -> {arg register: entry token 'E$aN' or 'X'} over all sites."""
    result = {}
    for F, body in funcs.items():
        lab = {x[1]: k for k, x in enumerate(body) if x[0] == "L"}
        IN = [None] * (len(body) + 1)
        IN[0] = {r: "E" + r for r in ARGR}
        work, sites = [0], {}

        def push(idx, st):
            n = join(IN[idx], st)
            if n != IN[idx]:
                IN[idx] = n
                work.append(idx)
        while work:
            p = work.pop()
            st = dict(IN[p])
            k = p
            while k < len(body):
                e = body[k]
                if e[0] == "L":
                    if k != p:
                        push(k, st)
                        break
                    k += 1
                    continue
                op, opr = e[1], e[2]
                d = body[k + 1] if k + 1 < len(body) else None
                if op in ("jal", "jalr"):
                    if d and d[0] == "I":
                        transfer(st, d[1], d[2])
                    if op == "jal":
                        snap = {r: st.get(r, "X") for r in ARGR}
                        prev = sites.get(k)
                        sites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
                    for r in CALLER_SAVED:
                        st[r] = "X"
                    k += 2
                    continue
                if op in COND or op in ("b", "j", "jr"):
                    if d and d[0] == "I":
                        transfer(st, d[1], d[2])
                    tgt = opr.split(",")[-1].strip()
                    if op == "j" and tgt not in lab:  # tail call: every register passes through
                        snap = {r: st.get(r, "X") for r in ARGR}
                        prev = sites.get(k)
                        sites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
                        break
                    if op == "jr":
                        if opr.strip() != "$ra":
                            for idx in lab.values():
                                push(idx, st)
                        break
                    if tgt in lab:
                        push(lab[tgt], st)
                    if op not in ("b", "j") and k + 2 < len(body):
                        push(k + 2, st)
                    break
                transfer(st, op, opr)
                k += 1
        for k, snap in sites.items():
            key = (F, body[k][2].split(",")[-1].strip())
            if key in result:
                result[key] = {r: (result[key][r] if result[key][r] == snap[r] else "X") for r in ARGR}
            else:
                result[key] = snap
    return result


def regs(params):
    out, ni, nf = [], 0, 0
    for t in params:
        if t in ("float", "double"):
            out.append("$f%d" % (12 + nf))
            nf += 1
        else:
            out.append(ARGR[ni] if ni < 8 else "?")
            ni += 1
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sigs", default=str(ROOT / "build/port-i386/host_sigs.json"))
    ap.add_argument("--asm", default=str(ROOT / "asm/main.s"))
    ap.add_argument("--out", default=str(HERE / "r12_regpass.csv"))
    ap.add_argument("--unresolved", help="also write the padded args no caller parameter explains (csv)")
    a = ap.parse_args()
    import hostify
    import link_catalog as L
    srcs = sorted({r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv")) if r["source"].endswith(".c")})
    fl = flow(parse_asm(a.asm))
    bysrc = collections.defaultdict(list)
    for r in csv.DictReader(open(ROOT / "config/matches.csv")):
        bysrc[r["source"]].append(r["name"])
    owner = {r["name"]: r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv"))}
    # R20 fixpoint: a caller that forwards an incoming register its C does not
    # declare gets that parameter (r12_widen.csv); its callers then pass it
    L.WIDEN = {}
    for it in range(8):
        log = tempfile.NamedTemporaryFile(delete=False, suffix=".csv").name
        os.environ["HOSTIFY_PAD_LOG"] = log
        hostify.REGPASS = {}
        hostify.REGEXPR = {}
        hostify.configure(a.sigs)
        for s in srcs:
            hostify.transform((ROOT / s).read_text(encoding="latin-1"), s)
        canon = hostify.SIGS["canon"]
        rows = set()
        unres = set()
        widen = {}
        for line in open(log):
            src, callee, have, _want, ks = line.strip().split(",")
            ks = [int(x) for x in ks.split(";") if x]
            c = canon.get(callee)
            if not c:
                continue
            creg = regs(c["params"])
            for F in bysrc.get(src, []):
                agg = fl.get((F, callee))
                fc = canon.get(F)
                if not agg or not fc:
                    continue
                freg = regs(fc["params"])
                for k in ks:
                    tok = agg.get(creg[k], "X")
                    if tok.startswith("E") and tok[1:] in freg:
                        rows.add((src, F, callee, k, freg.index(tok[1:])))
                    else:
                        unres.add((src, F, callee, k, tok))
                        if tok.startswith("E") and owner.get(F) == src and not fc.get("variadic"):
                            widen.setdefault(F, set()).add(tok[1:])
        os.unlink(log)
        grown = 0
        for F, rs in widen.items():
            ps = list(L.WIDEN.get(F, canon[F]["params"]))
            for r in sorted(rs):
                if r.startswith("$f"):
                    need = int(r[2:]) - 12 + 1
                    have = sum(1 for x in ps if x in ("float", "double"))
                    ps += ["float"] * max(0, need - have)
                elif r in ARGR:
                    need = ARGR.index(r) + 1
                    have = sum(1 for x in ps if x not in ("float", "double"))
                    ps += ["int"] * max(0, need - have)
            if ps != list(L.WIDEN.get(F, canon[F]["params"])):
                L.WIDEN[F] = ps
                grown += 1
        print(f"pass {it}: {len(rows)} rows, {len(unres)} unresolved, {grown} functions widened "
              f"({len(L.WIDEN)} total)")
        if not grown:
            break
    with open(HERE / "r12_widen.csv" if a.out == str(HERE / "r12_regpass.csv") else a.out + ".widen.csv",
              "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["function", "params"])
        for F in sorted(L.WIDEN):
            w.writerow([F, ";".join(L.WIDEN[F])])
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["source", "caller", "callee", "arg", "caller_param"])
        for r in sorted(rows):
            w.writerow(r)
    print(f"{a.out}: {len(rows)} rows")
    if a.unresolved:
        with open(a.unresolved, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["source", "caller", "callee", "arg", "register_holds"])
            for r in sorted(unres):
                w.writerow(r)
        print(f"{a.unresolved}: {len(unres)} unresolved padded args")


if __name__ == "__main__":
    main()
