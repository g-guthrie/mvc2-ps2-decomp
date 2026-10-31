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


def parse_asm(path, starts=None, targets=None):
    """glabel -> [("I", op, operands) | ("L", label, "")].  starts (address ->
    name, config/matches.csv) splits a glabel that holds several matched
    functions (main.s still has some unsplit: func_00197470 runs on into
    func_00197490)."""
    funcs, cur = {}, None
    starts = _starts() if starts is None else starts
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
            if starts and not funcs[cur]:
                nm = starts.get(int(m.group(1), 16))
                if nm and nm != cur and nm not in funcs:
                    funcs[nm] = funcs[cur]      # D_0014C0D0 / residual_00245120 = func_...
            elif starts:
                nm = starts.get(int(m.group(1), 16))
                if nm and nm != cur and nm not in funcs:
                    carry = []
                    while funcs[cur] and funcs[cur][-1][0] == "L":
                        carry.insert(0, funcs[cur].pop())
                    cur = nm
                    funcs[cur] = carry
            if targets:
                ad = int(m.group(1), 16)
                if ad in targets:
                    lb = ".L%08X" % ad
                    # a switch case the table names by raw address: give it a label
                    if not any(x[0] == "L" and x[1] == lb for x in funcs[cur][-3:]):
                        funcs[cur].append(("L", lb, ""))
            funcs[cur].append(("I", m.group(2), m.group(3).strip()))
            continue
        m = re.match(r"\s*(\.L[0-9A-Fa-f_]+):", l)
        if m:
            funcs[cur].append(("L", m.group(1), ""))
    return funcs


LOADS = {"lw": "u32", "lh": "s16", "lhu": "u16", "lb": "s8", "lbu": "u8"}


def sym_add(tok, k):
    """tok + k for a symbolic token (an entry register, or a load from one:
    "E$a0", "E$a0@136", "lw(E$a0@20)@8"); None if tok is not symbolic."""
    if not tok or not tok.startswith(("E$", "lw(", "lh(", "lhu(", "lb(", "lbu(")):
        return None
    if "@" in tok and tok.rfind("@") > tok.rfind(")"):
        base, off = tok.rsplit("@", 1)
        k += int(off)
    else:
        base = tok
    return base if k == 0 else "%s@%d" % (base, k)


def transfer(st, op, opr):
    rs = re.findall(r"\$\w+", opr)
    # symbolic values (R12 sites the register passthrough cannot explain):
    # "entry register + constant" and loads through it, two levels deep
    m = re.match(r"(\$\w+),\s*(\$\w+),\s*(-?(?:0x[0-9A-Fa-f]+|\d+))$", opr)
    if op in ("addiu", "daddiu") and m:
        t = sym_add(st.get(m.group(2), "X"), int(m.group(3), 0))
        st[m.group(1)] = t if t else "X"
        return
    m = re.match(r"(\$\w+),\s*(-?(?:0x[0-9A-Fa-f]+|\d+))\((\$\w+)\)$", opr)
    if op in LOADS and m:
        base = sym_add(st.get(m.group(3), "X"), int(m.group(2), 0))
        st[m.group(1)] = "%s(%s)" % (op, base) if base and base.count("(") < 2 else "X"
        return
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


ADDRNAME = {}     # address -> name (config/matches.csv), set by load_starts()


def load_starts():
    for r in csv.DictReader(open(ROOT / "config/matches.csv")):
        try:
            ADDRNAME[int(r["address"], 16)] = r["name"]
        except ValueError:
            pass
    return ADDRNAME


def fname(a):
    return ADDRNAME.get(a, "func_%08X" % a)


def jtbl_targets(path):
    """code addresses jump tables name by number (0x0041DBF8): switch cases
    main.s has no label for."""
    out = set()
    for ent in parse_jtbls(path).values():
        out.update(a for a in ent if a > 0 and a not in ADDRNAME)
    return out


def parse_jtbls(path):
    """jtbl_X -> entry addresses (0 for null/unknown)."""
    out, cur = {}, None
    for l in open(path):
        m = re.match(r"(?:dlabel|glabel) (jtbl_[0-9A-Fa-f]+)", l)
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
                w = m.group(1)
                ms = re.fullmatch(r"[A-Za-z_]\w*_([0-9A-Fa-f]{8})", w)
                if w.startswith(".L"):
                    out[cur].append(-1)  # .L label: a switch table
                elif ms:
                    out[cur].append(int(ms.group(1), 16))   # func_ / residual_ / D_
                elif w.startswith("0x"):
                    out[cur].append(int(w, 16))
                else:
                    out[cur].append(-1)
    return out


def dispatch_heads(funcs, jtbls, known):
    """Functions whose entry block tail-jumps through a table of other functions."""
    out = set()
    for F, body in funcs.items():
        try:
            lo = int(F.rsplit("_", 1)[-1], 16)
        except ValueError:
            continue
        hi = lo + 4 * sum(1 for x in body if x[0] == "I")
        for x in body:
            if x[0] == "L":
                break
            m = re.search(r"(jtbl_[0-9A-Fa-f]+)", x[2])
            if m and m.group(1) in jtbls:
                ent = [a for a in jtbls[m.group(1)] if a != 0]
                # a switch table lists code labels; a dispatch table lists
                # functions.  The asm's table label has no end marker when
                # data follows directly, so take the leading run of known
                # functions (a switch table starts with a code label: -1)
                run = []
                for a in ent:
                    if a <= 0 or a not in known:
                        break
                    run.append(a)
                if run and (len(run) == len(ent) or len(run) >= 2):
                    out.add(F)
                break
    return out


def leaf_writes(funcs):
    """name -> registers a leaf function (no calls) may write.  The EE code
    relies on such a callee leaving the other argument registers alone
    (func_00173A50 calls func_001734D0(p), then func_00173650 with $a0 still
    p)."""
    out = {}
    for F, body in funcs.items():
        w, leaf = set(), True
        for x in body:
            if x[0] != "I":
                continue
            op, opr = x[1], x[2]
            if op in ("jal", "jalr") or (op in ("j",) and not opr.startswith(".L")):
                leaf = False
                break
            if op == "jr" and opr.strip() != "$ra":
                leaf = False
                break
            rs = re.findall(r"\$\w+", opr)
            if op in STORE or op in COND or op in ("b", "j", "jr", "nop", "sync", "sync.p", "mthi", "mtlo",
                                                    "ctc1", "teq", "tne") or not rs:
                continue
            if op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1") and len(rs) == 2:
                continue
            w.add(rs[1] if op in ("mtc1", "dmtc1") and len(rs) > 1 else rs[0])
        if leaf:
            out[F] = w
    return out


def flow(funcs, ind=None):
    """(caller, callee) -> {arg register: entry token 'E$aN' or 'X'} over all sites.
    ind: if a dict, also gets caller -> [(instruction index, snapshot)] for
    every indirect call (jalr, or a jr through a register other than $ra)."""
    result = {}
    leaves = leaf_writes(funcs)
    for F, body in funcs.items():
        lab = {x[1]: k for k, x in enumerate(body) if x[0] == "L"}
        first_label = min(lab.values()) if lab else len(body)
        IN = [None] * (len(body) + 1)
        IN[0] = {r: "E" + r for r in ARGR}
        work, sites, isites = [0], {}, {}

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
                    if op == "jalr" and ind is not None:
                        snap = {r: st.get(r, "X") for r in ARGR}
                        prev = isites.get(k)
                        isites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
                    if op == "jal":
                        snap = {r: st.get(r, "X") for r in ARGR}
                        prev = sites.get(k)
                        sites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
                    lw = leaves.get(opr.strip()) if op == "jal" else None
                    for r in CALLER_SAVED:
                        if lw is None or r in lw or r in ("$v0", "$v1", "$ra"):
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
                        if opr.strip() != "$ra" and ind is not None:
                            snap = {r: st.get(r, "X") for r in ARGR}
                            prev = isites.get(k)
                            isites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
                        if opr.strip() != "$ra" and k < first_label:
                            # indirect tail call of a dispatch head (the jr ends the
                            # entry block, before any label): record what the argument registers
                            # hold, under the key "*jr*"
                            snap = {r: st.get(r, "X") for r in ARGR}
                            prev = sites.get(k)
                            sites[k] = snap if prev is None else {r: (prev[r] if prev[r] == snap[r] else "X") for r in ARGR}
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
        if ind is not None and isites:
            ind[F] = sorted(isites.items())
        for k, snap in sites.items():
            key = (F, "*jr*" if body[k][1] == "jr" else body[k][2].split(",")[-1].strip())
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


# ---------------------------------------------------------------------------
# R12 locals (Port J, robust pass): what an unresolved padded register held.
#
# vflow() is flow() with a richer value lattice: besides the entry token
# "E$aN" a register can hold
#   K:n            a constant
#   H:sym          %hi(sym) (lui)
#   A:sym:off      the address sym+off (%hi/%lo pair, %gp_rel, func_ address)
#   V:op:sym:off   the value loaded (op = lw/lh/...) from sym+off
#   P:imm:T        T + imm (pointer arithmetic on another token)
#   L:op:off:T     the value loaded from T + off
#   R:k            the return value ($v0) of the jal at body index k
#   D:k            the value defined by body instruction k (opaque)
# joined to X when paths disagree.  An opaque D/R/L token is named after the
# C variable the same function passes in that register to another call (or
# assigns from the matched call), see resolve_locals().
# liveness() says which argument registers a function reads before writing
# them on some path (through its callees, tail calls and dispatch tables): a
# padded argument whose register the callee never reads is harmless.
# ---------------------------------------------------------------------------
LOADS = {"lw": "int", "lh": "short", "lhu": "unsigned short", "lb": "signed char",
         "lbu": "unsigned char", "ld": "long long", "lwu": "unsigned int", "lwc1": "float"}


def _imm(x):
    x = x.strip()
    try:
        return int(x, 0)
    except ValueError:
        return None


def _sym(x):
    """%lo(D_x + 0x10) / %gp_rel(D_x) -> (kind, sym, off)."""
    m = re.fullmatch(r"%(lo|hi|gp_rel)\(\s*([A-Za-z_]\w*)\s*(?:\+\s*(0x[0-9A-Fa-f]+|\d+))?\s*\)", x.strip())
    if not m:
        return None
    return m.group(1), m.group(2), int(m.group(3), 0) if m.group(3) else 0


def _depth(t):
    return t.count(":")


def vtok(st, r):
    return "K:0" if r == "$zero" else st.get(r, "X")


def vtransfer(st, op, opr, k):
    rs = re.findall(r"\$\w+", opr)
    if op in STORE or op in COND or op in ("b", "j", "jr", "nop", "sync", "sync.p", "syscall", "mthi",
                                            "mtlo", "ctc1", "teq", "tne", "cache") or not rs:
        return
    if op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1") and len(rs) == 2:
        return
    if op.startswith("c.") or op in ("mtc0", "dmtc0", "qmtc2.ni", "ctc2.ni", "mtsa", "mtsah", "mthi1",
                                     "mtlo1", "adda.s", "mula.s", "suba.s", "tge", "tgeu", "tlt", "tltu", "tgei"):
        return
    ops = [x.strip() for x in re.split(r",(?![^(]*\))", opr)]
    d = rs[0]
    D = "D:%d" % k
    if op in ("mtc1", "dmtc1"):
        if len(rs) > 1:
            st[rs[1]] = "K:0" if vtok(st, rs[0]) == "K:0" else D
        return
    if op == "mov.s" and len(rs) == 2:
        st[d] = vtok(st, rs[1])
        return
    if op in ("daddu", "addu", "or", "move") and len(rs) == 3 and rs[2] == "$zero":
        st[d] = vtok(st, rs[1])
        return
    if op in ("daddu", "addu", "or") and len(rs) == 3 and rs[1] == "$zero":
        st[d] = vtok(st, rs[2])
        return
    if op == "move" and len(rs) == 2:
        st[d] = vtok(st, rs[1])
        return
    if op == "lui" and len(ops) == 2:
        sy = _sym(ops[1])
        n = _imm(ops[1])
        st[d] = ("H:%s" % sy[1]) if sy and sy[0] == "hi" else ("K:%d" % ((n << 16) & 0xFFFFFFFF)
                                                                if n is not None else D)
        if sy and sy[0] == "hi" and sy[2]:
            st[d] = D
        return
    if op in ("addiu", "daddiu", "addi", "daddi") and len(ops) == 3 and len(rs) == 2:
        b = vtok(st, rs[1])
        n = _imm(ops[2])
        sy = _sym(ops[2])
        if n is not None:
            if b.startswith("K:"):
                st[d] = "K:%d" % ((int(b[2:]) + n) & 0xFFFFFFFF)
            elif b.startswith("A:"):
                _, sym, o = b.split(":")
                st[d] = "A:%s:%d" % (sym, int(o) + n)
            elif b.startswith("P:") and _depth(b) < 6:
                _, o, t = b.split(":", 2)
                st[d] = "P:%d:%s" % (int(o) + n, t)
            elif b != "X" and not b.startswith("H:") and _depth(b) < 6:
                st[d] = "P:%d:%s" % (n, b)
            else:
                st[d] = D
        elif sy and sy[0] == "lo" and b == "H:" + sy[1]:
            st[d] = "A:%s:%d" % (sy[1], sy[2])
        elif sy and sy[0] == "gp_rel" and rs[1] == "$gp":
            st[d] = "A:%s:%d" % (sy[1], sy[2])
        else:
            st[d] = D
        return
    if op == "ori" and len(ops) == 3 and len(rs) == 2:
        b = vtok(st, rs[1])
        n = _imm(ops[2])
        st[d] = "K:%d" % (int(b[2:]) | n) if b.startswith("K:") and n is not None else D
        return
    if op in LOADS and len(ops) == 2:
        m = re.fullmatch(r"(.*)\((\$\w+)\)", ops[1])
        if m:
            off, base = m.group(1).strip(), m.group(2)
            b = vtok(st, base)
            sy = _sym(off) if off else None
            n = _imm(off) if off else 0
            if sy and sy[0] == "gp_rel" and base == "$gp":
                st[d] = "V:%s:%s:%d:%d" % (op, sy[1], sy[2], k)
                return
            if sy and sy[0] == "lo" and b == "H:" + sy[1]:
                st[d] = "V:%s:%s:%d:%d" % (op, sy[1], sy[2], k)
                return
            if n is not None and b.startswith("A:"):
                _, sym, o = b.split(":")
                st[d] = "V:%s:%s:%d:%d" % (op, sym, int(o) + n, k)
                return
            if n is not None and b != "X" and not b.startswith(("H:", "K:")) and _depth(b) < 6:
                if b.startswith("P:"):
                    _, o, t = b.split(":", 2)
                    st[d] = "L:%s:%d:%d:%s" % (op, int(o) + n, k, t)
                else:
                    st[d] = "L:%s:%d:%d:%s" % (op, n, k, b)
                return
    st[d] = D


def _vfunc(body, summ):
    """one function: (sites {body index: (callee, {reg: token})}, exit tokens)."""
    lab = {x[1]: k for k, x in enumerate(body) if x[0] == "L"}
    IN = [None] * (len(body) + 1)
    IN[0] = {r: "E" + r for r in ARGR}
    work, sites, exits = [0], {}, []

    def push(idx, st):
        # a join keeps a value both paths agree on, else the phi "F:idx:reg"
        a = IN[idx]
        if a is None:
            n = dict(st)
        else:
            n = {}
            for r in set(a) | set(st):
                x, y = a.get(r, "X"), st.get(r, "X")
                n[r] = x if x == y else "F:%d:%s" % (idx, r)
        if n != IN[idx]:
            IN[idx] = n
            work.append(idx)

    def call(st, callee, k):
        sm = summ.get(callee)
        before = dict(st)
        for r in CALLER_SAVED:
            t = sm.get(r, "X") if sm else "X"
            st[r] = before.get(t[1:], "X") if t.startswith("E$") else \
                t if t.startswith(("K:", "A:")) else "U:%d:%s" % (k, callee or "jalr")
        st["$v0"] = "R:%d" % k
    guard = 0
    while work:
        guard += 1
        if guard > 200000:
            break
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
            dl = body[k + 1] if k + 1 < len(body) else None
            if op in ("jal", "jalr"):
                if dl and dl[0] == "I":
                    vtransfer(st, dl[1], dl[2], k + 1)
                tgt = opr.split(",")[-1].strip()
                if op == "jal":
                    sites[k] = (tgt, {r: st.get(r, "X") for r in ARGR})  # states only grow: last visit holds
                call(st, tgt if op == "jal" else None, k)
                k += 2
                continue
            if op in COND or op in ("b", "j", "jr"):
                tgt = opr.split(",")[-1].strip()
                if op in COND and op.endswith("l"):
                    if k + 2 < len(body):
                        push(k + 2, st)      # not taken: the delay slot is skipped
                    if dl and dl[0] == "I":
                        vtransfer(st, dl[1], dl[2], k + 1)
                    if tgt in lab:
                        push(lab[tgt], st)
                    break
                if dl and dl[0] == "I":
                    vtransfer(st, dl[1], dl[2], k + 1)
                if op == "j" and tgt not in lab:
                    sites[k] = (tgt, {r: st.get(r, "X") for r in ARGR})
                    call(st, tgt, k)
                    exits.append(st)
                    break
                if op == "jr":
                    if opr.strip() != "$ra":
                        for idx in lab.values():
                            push(idx, st)
                    else:
                        exits.append(st)
                    break
                if tgt in lab:
                    push(lab[tgt], st)
                if op not in ("b", "j") and k + 2 < len(body):
                    push(k + 2, st)
                break
            vtransfer(st, op, opr, k)
            k += 1
    ex = {}
    for r in CALLER_SAVED:
        vals = {x.get(r, "X") for x in exits}
        if any(v.startswith("U:") for v in vals):
            continue
        t = vals.pop() if len(vals) == 1 else "X"
        if t.startswith(("E$", "K:", "A:")):
            ex[r] = t
    return sites, ex


def _bottom_up(funcs):
    """function names, callees before callers (DFS post-order over jal / tail j)."""
    calls = {}
    for F, body in funcs.items():
        calls[F] = [x[2].split(",")[-1].strip() for x in body
                    if x[0] == "I" and x[1] in ("jal", "j") and not x[2].strip().startswith(".L")]
    seen, order = set(), []
    for root in funcs:
        if root in seen:
            continue
        stack = [(root, iter(calls[root]))]
        seen.add(root)
        while stack:
            F, it = stack[-1]
            nxt = next(it, None)
            if nxt is None:
                stack.pop()
                order.append(F)
            elif nxt in funcs and nxt not in seen:
                seen.add(nxt)
                stack.append((nxt, iter(calls[nxt])))
    return order


def vflow(funcs, rounds=4):
    """F -> [(body index, callee, {reg: token})] for every jal / tail j, in
    address order; tokens joined over all paths reaching that site.  A call
    leaves the argument registers its callee does not change (or sets to a
    constant) on every return path: per-function exit summaries, `rounds`
    passes (recursion stays unknown)."""
    summ = {}
    order = _bottom_up(funcs)
    for it in range(rounds):
        out, changed = {}, False
        for F in order:      # callees first: most summaries settle in one pass
            sites, ex = _vfunc(funcs[F], summ)
            if summ.get(F) != ex:
                summ[F] = ex
                changed = True
            out[F] = sorted((k, c, snap) for k, (c, snap) in sites.items())
        if not changed:
            break
    vflow.summ = summ
    return out


USE_ONLY = STORE | set(COND) | {"jr", "teq", "tne", "tge", "tgeu", "tlt", "tltu", "tgei", "mthi", "mtlo",
                                "mthi1", "mtlo1", "mtsa", "mtsah", "ctc1", "ctc2.ni", "qmtc2.ni", "mtc0",
                                "dmtc0", "adda.s", "mula.s", "suba.s", "cache", "sqc2", "swc2"}


def _ud(op, opr):
    """(registers used, registers defined) by one instruction (conservative:
    an unknown form only uses)."""
    rs = [r for r in re.findall(r"\$\w+", opr) if r != "$zero"]
    if op in USE_ONLY or op.startswith("c.") or op in ("bc1f", "bc1t", "bc1fl", "bc1tl", "bc0f", "bc2f"):
        return set(rs), set()
    if op in ("mtc1", "dmtc1") and len(rs) == 2:
        return {rs[0]}, {rs[1]}
    if op in ("mult", "multu", "div", "divu", "mult1", "multu1", "div1", "divu1", "dmult", "dmultu",
              "ddiv", "ddivu") and len(rs) == 2:
        return set(rs), set()
    if op in ("movz", "movn", "lwl", "lwr", "ldl", "ldr", "sc", "scd"):
        return set(rs), {rs[0]} if rs else set()
    if op == "syscall":
        return set(ARGR), set()
    if op in ("nop", "sync", "sync.p", "break", "eret", "ei", "di", ".word", "vnop", "vwaitq") or not rs:
        return set(), set()
    return set(rs[1:]), {rs[0]}


def _cfg(body, jtbls):
    """instruction list, label -> index, and for every `jr $reg` the jump
    table referenced last before it (None: unknown target)."""
    ins, lab, jr_tab, last = [], {}, {}, None
    for x in body:
        if x[0] == "L":
            lab[x[1]] = len(ins)
            continue
        m = re.search(r"(jtbl_[0-9A-Fa-f]+)", x[2])
        if m and m.group(1) in jtbls:
            last = jtbls[m.group(1)]
        if x[1] == "jr" and x[2].strip() != "$ra":
            jr_tab[len(ins)] = last
        ins.append((x[1], x[2]))
    return ins, lab, jr_tab


def mustdef(funcs, rounds=4):
    """F -> argument registers F writes on every path to its return (so a
    caller's value there does not survive the call)."""
    ALLA = set(ARGR)
    MD = {}
    for it in range(rounds):
        nmd = {}
        for F, body in funcs.items():
            lab = {x[1]: k for k, x in enumerate(body) if x[0] == "L"}
            IN = [None] * (len(body) + 1)
            IN[0] = frozenset()
            work, exits = [0], []

            def push(idx, st):
                n = st if IN[idx] is None else IN[idx] & st
                if n != IN[idx]:
                    IN[idx] = n
                    work.append(idx)
            guard = 0
            while work and guard < 100000:
                guard += 1
                p = work.pop()
                st = set(IN[p])
                k = p
                while k < len(body):
                    e = body[k]
                    if e[0] == "L":
                        if k != p:
                            push(k, frozenset(st))
                            break
                        k += 1
                        continue
                    op, opr = e[1], e[2]
                    dl = body[k + 1] if k + 1 < len(body) else None
                    tgt = opr.split(",")[-1].strip()
                    if op in ("jal", "jalr"):
                        if dl and dl[0] == "I":
                            st |= _ud(dl[1], dl[2])[1] & ALLA
                        if op == "jal":
                            st |= MD.get(tgt, set())
                        k += 2
                        continue
                    if op in COND or op in ("b", "j", "jr"):
                        if op in COND and op.endswith("l"):
                            if k + 2 < len(body):
                                push(k + 2, frozenset(st))
                            if dl and dl[0] == "I":
                                st |= _ud(dl[1], dl[2])[1] & ALLA
                            if tgt in lab:
                                push(lab[tgt], frozenset(st))
                            break
                        if dl and dl[0] == "I":
                            st |= _ud(dl[1], dl[2])[1] & ALLA
                        if op == "j" and tgt not in lab:
                            exits.append(st | MD.get(tgt, set()))
                            break
                        if op == "jr":
                            if opr.strip() == "$ra":
                                exits.append(st)
                            else:
                                for idx in lab.values():
                                    push(idx, frozenset(st))
                            break
                        if tgt in lab:
                            push(lab[tgt], frozenset(st))
                        if op not in ("b", "j") and k + 2 < len(body):
                            push(k + 2, frozenset(st))
                        break
                    st |= _ud(op, opr)[1] & ALLA
                    k += 1
            nmd[F] = set.intersection(*exits) if exits else set(ALLA)
        if nmd == MD:
            break
        MD = nmd
    return MD


def liveness(funcs, jtbls):
    """F -> set of argument registers F may read before writing (any path,
    through calls, tail calls and dispatch tables); an unknown or indirect
    target reads every argument register.  A call kills only what its callee
    writes on every path (mustdef)."""
    known = set(funcs)
    ALLA = set(ARGR)
    MD = mustdef(funcs)
    prep = {F: _cfg(body, jtbls) for F, body in funcs.items()}
    live = {F: set() for F in funcs}
    # undecoded words between instructions: treat the function as unknown
    opaque = set()
    for F, (ins, _, _) in prep.items():
        w = [k for k, x in enumerate(ins) if x[0] in (".word", "c1")]
        if w and any(x[0] not in (".word", "nop", "c1") for x in ins[w[0]:]):
            opaque.add(F)

    def callee_uses(name):
        if name not in known or name in opaque:
            return ALLA
        return live[name] & ALLA

    def one(F):
        ins, lab, jr_tab = prep[F]
        n = len(ins)
        if F in opaque:
            return set(ALLA)
        U = [set() for _ in range(n)]
        Dd = [set() for _ in range(n)]
        succ = [[] for _ in range(n)]
        extra, kill = {}, {}
        k = 0
        while k < n:
            op, opr = ins[k]
            tgt = opr.split(",")[-1].strip()
            if op in ("jal", "jalr"):
                U[k] = set(r for r in re.findall(r"\$\w+", opr) if r not in ("$ra", "$zero")) \
                    if op == "jalr" else set()
                succ[k] = [k + 1]
                if k + 1 < n:
                    U[k + 1], Dd[k + 1] = _ud(*ins[k + 1])
                    extra[k + 1] = callee_uses(tgt) if op == "jal" else ALLA
                    kill[k + 1] = MD.get(tgt, set()) if op == "jal" else set()
                    succ[k + 1] = [k + 2] if k + 2 < n else []
                k += 2
                continue
            if op in COND or op in ("b", "j", "jr"):
                U[k], _ = _ud(op, opr)
                targets, ex = [], set()
                if op == "jr":
                    if opr.strip() != "$ra":
                        tab = jr_tab.get(k)
                        if tab is None:
                            ex = set(ALLA)
                        elif any(a == -1 or ".L%08X" % a in lab for a in tab):  # a switch: any label
                            targets = sorted(set(lab.values()))
                        else:                                # a dispatch table
                            for a in tab:
                                if a:
                                    ex |= callee_uses(fname(a))
                elif op == "j" and tgt not in lab:
                    ex = callee_uses(tgt)
                elif tgt in lab:
                    targets.append(lab[tgt])
                fall = [k + 2] if op not in ("b", "j", "jr") and k + 2 < n else []
                likely = op in COND and op.endswith("l")
                succ[k] = [k + 1] + (fall if likely else [])
                if k + 1 < n:
                    U[k + 1], Dd[k + 1] = _ud(*ins[k + 1])
                    succ[k + 1] = targets if likely else targets + fall
                    if ex:
                        extra[k + 1] = ex
                k += 2
                continue
            U[k], Dd[k] = _ud(op, opr)
            succ[k] = [k + 1] if k + 1 < n else []
            k += 1
        LIN = [set() for _ in range(n)]
        changed = True
        while changed:
            changed = False
            for k in range(n - 1, -1, -1):
                out = set()
                for s_ in succ[k]:
                    if s_ < n:
                        out |= LIN[s_]
                if k in kill:
                    out -= kill[k]
                out |= extra.get(k, set())
                nin = U[k] | (out - Dd[k])
                if nin != LIN[k]:
                    LIN[k] = nin
                    changed = True
        return (LIN[0] if n else set()) & ALLA

    for it in range(50):
        grown = 0
        for F in funcs:
            l = one(F)
            if l != live[F]:
                live[F] = l
                grown += 1
        if not grown:
            break
    return live


C_KW = {"if", "while", "for", "switch", "return", "sizeof", "do", "else", "case", "goto", "break",
        "continue", "default", "struct", "union", "enum", "typedef", "extern", "static", "const",
        "volatile", "register", "unsigned", "signed", "void", "int", "char", "short", "long", "float",
        "double", "u8", "s8", "u16", "s16", "u32", "s32", "u64", "s64", "f32", "f64", "inline"}


def c_functions(text):
    """name -> {params, toks, calls: [(callee, close index, [arg toks]), ...]
    in execution order (inner call first), assigns: {ident: [token index]}}"""
    import hostify as H
    toks = [t for t in H.lex(text) if t[0] not in ("ws", "comment", "pp")]
    out, i, depth = {}, 0, 0
    filescope = set()
    while i < len(toks):
        t = toks[i]
        if t[1] == "{" and depth == 0 and i > 0 and toks[i - 1][1] == ")":
            # definition head: ident ( ... ) {
            e = i - 1
            d, j = 0, e
            while j >= 0:
                if toks[j][1] == ")":
                    d += 1
                elif toks[j][1] == "(":
                    d -= 1
                    if d == 0:
                        break
                j -= 1
            if j > 0 and toks[j - 1][0] == "ident":
                name = toks[j - 1][1]
                params = []
                for a in H.split_top(toks[j + 1:e], ","):
                    ids = [x[1] for x in a if x[0] == "ident"]
                    params.append(ids[-1] if ids and ids[-1] not in C_KW else None)
                end = H.match_close(toks, i, "{", "}")
                out[name] = {"params": params, "toks": toks[i:end + 1]}
                i = end + 1
                continue
        if t[1] in "{(":
            depth += 1
        elif t[1] in "})":
            depth -= 1
        elif t[0] == "ident" and depth == 0:
            filescope.add(t[1])
        i += 1
    for name, f in out.items():
        b = f["toks"]
        calls, assigns, addr = [], {}, set()
        decl, spans = set(), []
        for k, t in enumerate(b):
            if t[0] != "ident":
                continue
            nx = b[k + 1][1] if k + 1 < len(b) else ""
            nx2 = b[k + 2][1] if k + 2 < len(b) else ""
            pv = b[k - 1] if k else ("", "")
            if nx == "(" and t[1] not in C_KW:
                if pv[0] == "ident" and pv[1] not in ("return", "else", "case", "do"):
                    continue   # a declaration `void f(...)`
                if pv[1] == "*" and k > 1 and b[k - 2][0] == "ident" and b[k - 2][1] in C_KW:
                    continue
                if pv[1] in (".",) or (pv[1] == ">" and k > 1 and b[k - 2][1] == "-"):
                    continue
                e = H.match_close(b, k + 1, "(", ")")
                args = H.split_top(b[k + 2:e], ",")
                if len(args) == 1 and not args[0]:
                    args = []
                calls.append((t[1], e, args, k))
                q = k + 2
                for j, a in enumerate(args):      # token span of each argument
                    spans.append((q, q + len(a), t[1], j))
                    q += len(a) + 1
                continue
            if (nx == "=" and nx2 != "=") or (nx in "+-*/%&|^" and nx2 == "=") or \
                    (nx in "<>" and nx2 == nx and k + 3 < len(b) and b[k + 3][1] == "=") or \
                    (nx in "+-" and nx2 == nx) or (pv[1] in "+-" and k > 1 and b[k - 2][1] == pv[1]):
                if not (pv[1] in (".",) or (pv[1] == ">" and k > 1 and b[k - 2][1] == "-")):
                    assigns.setdefault(t[1], []).append(k)
            if pv[1] == "&" and not (k > 1 and (b[k - 2][0] in ("ident", "number") or b[k - 2][1] in (")", "]"))) \
                    and not (nx in (".", "[") or (nx == "-" and nx2 == ">")):
                addr.add(t[1])
            if pv[0] == "ident" and (pv[1] in C_KW or pv[1] in filescope) and nx in (";", "=", ",", "["):
                decl.add(t[1])
            if pv[1] == "*" and nx in (";", "=", ",", "[") and k > 1 and \
                    (b[k - 2][0] == "ident" or b[k - 2][1] == "*"):
                decl.add(t[1])
        calls.sort(key=lambda c: c[1])
        f.update(calls=calls, assigns=assigns, addr=addr, locals=decl | {p for p in f["params"] if p},
                 filescope=filescope, spans=spans)
    return out


def _strip_casts(a):
    """[tokens] of an argument without leading casts and outer parentheses."""
    a = list(a)
    while a:
        if a[0][1] == "(":
            # (type) x  or  (expr)
            depth, e = 0, None
            for q, t in enumerate(a):
                if t[1] == "(":
                    depth += 1
                elif t[1] == ")":
                    depth -= 1
                    if depth == 0:
                        e = q
                        break
            if e is None:
                return a
            inner = a[1:e]
            if e == len(a) - 1:
                a = inner
                continue
            if inner and all(t[0] == "ident" or t[1] == "*" for t in inner) and \
                    (inner[0][1] in C_KW or inner[-1][1] == "*" or len(inner) == 1):
                a = a[e + 1:]
                continue
        return a
    return a


def arg_expr(a, f):
    """C text of a call argument usable as a register value elsewhere: a
    local/parameter, possibly cast, `&local`, or local +/- constant."""
    a = _strip_casts(a)
    if len(a) == 1 and a[0][0] == "ident" and a[0][1] in f["locals"]:
        return a[0][1], {a[0][1]}
    if len(a) == 2 and a[0][1] == "&" and a[1][0] == "ident" and a[1][1] in f["locals"]:
        return "&" + a[1][1], set()     # address of a local: never changes
    if len(a) == 3 and a[0][0] == "ident" and a[0][1] in f["locals"] and a[1][1] in "+-" and \
            a[2][0] == "number":
        return "(" + "".join(x[1] for x in a) + ")", {a[0][1]}
    return None, None


def _ctype(op):
    return LOADS.get(op, "int")


class Resolver:
    def __init__(self, src_text, cf, vf, canon, fname, src, body=None):
        self.text, self.cf, self.vf, self.canon, self.F, self.src = src_text, cf, vf, canon, fname, src
        self.body = body or []
        self.site = None     # body index of the jal being resolved
        self.f = cf.get(fname)
        self.sites = vf.get(fname, [])
        self.names = {}     # token -> (expr, vars, C close index)

    def jals(self, callee):
        return [x for x in self.sites if x[1] == callee]

    def ccalls(self, callee):
        return [c for c in self.f["calls"] if c[0] == callee] if self.f else []

    def build(self):
        """map opaque tokens to C expressions via other calls of this function"""
        if not self.f:
            return
        bycallee = collections.defaultdict(list)
        for c in self.f["calls"]:
            bycallee[c[0]].append(c)
        bad = set()
        for callee, cs in bycallee.items():
            js = self.jals(callee)
            if len(js) != len(cs):
                continue
            c = self.canon.get(callee)
            # the register of argument j is only certain when the callee takes
            # ints only and the call passes all of them (a padded or float
            # call may map C arguments to other registers, hostify R12 classes)
            intonly = bool(c) and not c.get("variadic") and \
                not any(t in ("float", "double") for t in c["params"])
            creg = regs(c["params"]) if intonly else []
            for (cn, close, args, start), (k, _, snap) in zip(cs, js):
                for j, a in enumerate(args if len(args) == len(creg) else ()):
                    if j >= len(creg) or creg[j] == "?":
                        continue
                    tok = snap.get(creg[j], "X")
                    if tok == "X" or tok.startswith(("K:", "A:", "E$", "H:")):
                        continue
                    ex, vs = arg_expr(a, self.f)
                    if ex is None:
                        continue
                    prev = self.names.get(tok)
                    if prev and prev[0] != ex:
                        bad.add(tok)
                    self.names.setdefault(tok, (ex, vs, close))
                # `v = callee(...)`: R:k is v
                b = self.f["toks"]
                q = start - 1
                while q > 0 and b[q][1] == ")":    # a cast before the call
                    d = 0
                    while q > 0:
                        if b[q][1] == ")":
                            d += 1
                        elif b[q][1] == "(":
                            d -= 1
                            if d == 0:
                                break
                        q -= 1
                    q -= 1
                if q > 0 and b[q][1] == "=" and b[q - 1][0] == "ident" and b[q - 1][1] in self.f["locals"] \
                        and b[q - 2][1] not in (".", ">", "=", "!", "<"):
                    tok = "R:%d" % k
                    v = b[q - 1][1]
                    prev = self.names.get(tok)
                    if prev and prev[0] != v:
                        bad.add(tok)
                    self.names.setdefault(tok, (v, {v}, close))
        for t in bad:
            self.names.pop(t, None)

    def stale(self, lk):
        """why the value loaded at body index lk may differ from that memory
        at the call (None: same).  The load must come before the call in one
        straight run (no label), with no call and no store to the same base
        register at an overlapping offset in between (incl. the delay slot);
        stores through other base registers are assumed not to alias."""
        if self.site is not None and lk == self.site + 1:
            return None          # loaded in the call's delay slot
        if self.site is None or not (lk < self.site):
            return "load after the call"
        ld = self.body[lk]
        m = re.search(r"([-\w%()+ ]*)\((\$\w+)\)", ld[2])
        if not m:
            return "load form"
        base = m.group(2)
        lo = _imm(m.group(1)) if m.group(1).strip() else 0
        w = {"lb": 1, "lbu": 1, "lh": 2, "lhu": 2, "ld": 8, "lq": 16}.get(ld[1], 4)
        for q in range(lk + 1, self.site + 2):
            x = self.body[q]
            if x[0] == "L":
                return "load in another block"
            if x[1] in ("jal", "jalr") and q != self.site:
                return "a call between load and use"
            if x[1] in STORE:
                m2 = re.search(r"([-\w%()+ ]*)\((\$\w+)\)", x[2])
                if not m2:
                    return "store form"
                if m2.group(2) == base or (lo is None):
                    so = _imm(m2.group(1)) if m2.group(1).strip() else 0
                    sw = {"sb": 1, "sh": 2, "sd": 8, "sq": 16, "sdl": 8, "sdr": 8}.get(x[1], 4)
                    if so is None or lo is None or (so < lo + w and lo < so + sw):
                        return "memory stored between load and use"
            rs = re.findall(r"\$\w+", x[2])
            if x[1] not in STORE and x[1] not in COND and rs and rs[0] == base and q != lk:
                base = None      # base register reused: later stores unknown, be strict
                lo = None
        return None

    def declared(self, sym):
        return re.search(r"\b%s\b" % re.escape(sym), self.text) is not None

    def expr(self, tok, at, depth=0):
        """C expression for token at C close index `at`, or (None, why)."""
        if depth > 4:
            return None, "deep"
        if tok.startswith("K:"):
            n = int(tok[2:])
            return (str(n) if n < 0x10000 else hex(n)), None
        if tok.startswith("A:"):
            _, sym, o = tok.split(":")
            if not self.declared(sym):
                return None, "symbol %s not declared in the TU" % sym
            base = "((char *)&%s)" % sym if not sym.startswith("func_") else "((char *)%s)" % sym
            return ("(%s + %s)" % (base, o) if int(o) else ("(void *)&%s" % sym if not sym.startswith("func_")
                                                            else "(void *)%s" % sym)), None
        if tok.startswith("V:"):
            _, op, sym, o, lk = tok.split(":")
            why = self.stale(int(lk))
            if why:
                return None, why
            if not self.declared(sym):
                return None, "symbol %s not declared in the TU" % sym
            return "(*(%s *)((char *)&%s + %s))" % (_ctype(op), sym, o), None
        if tok.startswith("E$"):
            fc = self.canon.get(self.F)
            if not fc or not self.f:
                return None, "no caller prototype"
            fr = regs(fc["params"])
            if tok[1:] not in fr:
                return None, "entry register %s not a parameter" % tok[1:]
            q = fr.index(tok[1:])
            ps = self.f["params"]
            if q >= len(ps) or not ps[q]:
                return None, "unnamed parameter"
            if ps[q] in self.f["assigns"] or ps[q] in self.f["addr"]:
                return None, "parameter %s is assigned" % ps[q]
            return ps[q], None
        if tok.startswith("P:"):
            _, o, t = tok.split(":", 2)
            e, why = self.expr(t, at, depth + 1)
            return (None, why) if e is None else ("((char *)(%s) + %s)" % (e, o), None)
        if tok.startswith("L:"):
            _, op, o, lk, t = tok.split(":", 4)
            why = self.stale(int(lk))
            if why:
                return (self.named(tok, at) if tok in self.names else (None, why))
            e, why = self.expr(t, at, depth + 1)
            if e is None and tok in self.names:
                return self.named(tok, at)
            return (None, why) if e is None else ("(*(%s *)((char *)(%s) + %s))" % (_ctype(op), e, o), None)
        if tok in self.names:
            return self.named(tok, at)
        return None, "opaque %s" % tok.split(":")[0]

    def named(self, tok, at):
        ex, vs, close = self.names[tok]
        lo, hi = sorted((close, at))
        for v in vs:
            if v in self.f["addr"]:
                return None, "%s has its address taken" % v
            if any(lo < p < hi for p in self.f["assigns"].get(v, ())):
                return None, "%s reassigned between the calls" % v
        return ex, None


def host_usage(srcs, canon, regpass_rows, tailfwd, heads_tab=None):
    """(F, k) pairs whose parameter k the host build of F may use: the
    credited C names it outside a plain call argument, or passes it as
    argument j of g where (g, j) is used; a widened (R20) parameter is used
    where an R12 passthrough row forwards it to a used argument, or F is a
    tail-forwarding head (R22).  Functions without credited C, host
    implementations and variadic functions use everything."""
    import hostify as H
    hostimpl = set()
    for l in open(ROOT / "port/host/host_impl.csv"):
        if l.strip() and not l.startswith(("#", "name,")):
            hostimpl.add(l.split(",")[0].strip())
    defs = {}
    owned = collections.defaultdict(set)
    for r in csv.DictReader(open(ROOT / "config/matches.csv")):
        owned[r["source"]].add(r["name"])
    for src in srcs:
        try:
            text = (ROOT / src).read_text(encoding="latin-1")
            cf = c_functions(text)
            if owned[src] - set(cf):
                # functions made by a local macro (STATE_UPDATE(func_0017D710)):
                # expand the file's own macros (not its headers) and parse again
                import subprocess
                body = "".join(l for l in text.splitlines(True) if not re.match(r"\s*#\s*include\b", l))
                pp = subprocess.run(["cpp", "-P", "-w", "-undef"], input=body, capture_output=True,
                                    text=True, encoding="latin-1")
                if pp.returncode == 0:
                    cf2 = c_functions(pp.stdout)
                    for n in owned[src] - set(cf):
                        if n in cf2:
                            cf[n] = cf2[n]
        except Exception:
            continue
        for n, f in cf.items():
            defs.setdefault(n, (src, f))
    deps = collections.defaultdict(set)    # (g, j) -> {(F, k)} used if (g, j) is
    used = set()
    unknown = set()
    for F, c in canon.items():
        if F not in defs or F in hostimpl or c.get("variadic") or (F in tailfwd and F not in (heads_tab or {})):
            unknown.add(F)
            continue
        src, f = defs[F]
        ps = f["params"]
        b = f["toks"]
        cover = {}
        for (q0, q1, g, j) in f["spans"]:
            a = _strip_casts(b[q0:q1])
            if len(a) == 1 and a[0][0] == "ident":
                # the whole argument is one identifier at this position
                for q in range(q0, q1):
                    if b[q] is a[0]:
                        cover[q] = (g, j)
        for k, nm in enumerate(ps):
            if not nm:
                continue
            for q, t in enumerate(b):
                if t[0] != "ident" or t[1] != nm:
                    continue
                if q > 0 and (b[q - 1][1] == "." or (b[q - 1][1] == ">" and q > 1 and b[q - 2][1] == "-")):
                    continue      # a member of the same name
                if q in cover:
                    deps[cover[q]].add((F, k))
                else:
                    used.add((F, k))
    for (src, F, g, j, cp) in regpass_rows:
        deps[(g, int(j))].add((F, int(cp)))
    # R22: a tail-forwarding head passes its parameters on to every table entry
    for F, ents in (heads_tab or {}).items():
        if F not in tailfwd or F not in canon:
            continue
        for k in range(len(canon[F]["params"])):
            for e in ents:
                deps[(e, k)].add((F, k))
    # propagate: a dependency on an unknown function or a used argument is a use
    work = list(used)
    via = {x: "named in the C" for x in used}
    for (g, j), fs in list(deps.items()):
        cg = canon.get(g)
        if g in unknown or cg is None:
            for x in fs:
                if x not in used:
                    used.add(x)
                    via[x] = "passed to %s (unknown)" % g
                    work.append(x)
    while work:
        x = work.pop()
        for y in deps.get(x, ()):
            if y not in used:
                used.add(y)
                via[y] = x
                work.append(y)

    def is_used(F, k):
        return F in unknown or (F, k) in used

    def trace(F, k):
        out, x = [], (F, k)
        while isinstance(x, tuple) and len(out) < 30:
            out.append(x)
            x = via.get(x, "unknown function" if x[0] in unknown else "?")
        return out + [x]
    is_used.trace = trace
    return is_used


def resolve_locals(a, funcs, canon, padlog, rows_set, jtbls, outdir, vf=None, srcs=(), tailfwd=(), symkeys=()):
    """Classify every padded argument R12 does not pass a caller parameter
    for: auto-resolved expression, harmless (callee never reads the
    register), or left (with the reason)."""
    vf = vflow(funcs) if vf is None else vf
    live = liveness(funcs, jtbls)
    hand = {}
    for r in csv.DictReader(l for l in open(HERE / "r12_regexpr.csv") if not l.startswith("#")):
        hand[(r["source"], r["caller"], r["callee"], int(r["arg"]))] = r["expr"]
    if os.environ.get("REGPASS_NOHAND"):    # cross-check the hand rows
        hand = {}
    heads_tab = {}
    for F, body in funcs.items():
        for x in body:
            if x[0] == "L":
                break
            m = re.search(r"(jtbl_[0-9A-Fa-f]+)", x[2])
            if m and m.group(1) in jtbls:
                ent = jtbls[m.group(1)]
                labs = {y[1] for y in body if y[0] == "L"}
                if ent and all(e >= 0 and ".L%08X" % e not in labs for e in ent):
                    # a null entry is never dispatched (the EE would jump to 0)
                    heads_tab[F] = [fname(e) for e in ent if e]
                break
    is_used = host_usage(srcs, canon, rows_set, set(tailfwd), heads_tab)
    resolve_locals.is_used = is_used
    rows_set = {r[:4] for r in rows_set} | {tuple(k[:4]) for k in symkeys}
    cache = {}
    res = []
    for (src, callee, ks, fn, nth) in padlog:
        c = canon.get(callee)
        if not c:
            continue
        creg = regs(c["params"])
        if src not in cache:
            t = (ROOT / src).read_text(encoding="latin-1")
            cache[src] = (t, c_functions(t))
        text, cf = cache[src]
        for k in ks:
            key = (src, fn, callee, k)
            if key in rows_set:
                continue
            rec = dict(source=src, caller=fn or "", callee=callee, arg=k, nth="" if nth is None else nth,
                       reg=creg[k], holds="", status="", expr="", why="")
            if k >= len(c["params"]) or creg[k] == "?":
                rec.update(status="left", why="stack argument")
                res.append(rec)
                continue
            r = creg[k]
            if callee in live and r not in live[callee]:
                rec.update(status="harmless", why="callee never reads %s" % r)
            elif not is_used(callee, k):
                rec.update(status="harmless", why="the host callee never uses argument %d" % k)
            if key in hand:
                rec.update(status="hand", expr=hand[key], why=rec["why"])
                res.append(rec)
                continue
            if rec["status"]:
                res.append(rec)
                continue
            if not fn:
                rec.update(status="left", why="call in a macro (no caller)")
                res.append(rec)
                continue
            R = Resolver(text, cf, vf, canon, fn, src, funcs.get(fn))
            R.build()
            js = R.jals(callee)
            cs = R.ccalls(callee)
            if not js:
                rec.update(status="left", why="no jal %s in the caller's asm" % callee)
                res.append(rec)
                continue
            if nth is not None and len(js) == len(cs) and nth < len(js):
                tok = js[nth][2].get(r, "X")
                at = cs[nth][1]
                R.site = js[nth][0]
            else:
                toks = {j[2].get(r, "X") for j in js}
                tok = toks.pop() if len(toks) == 1 else "X"
                R.site = js[0][0] if len(js) == 1 else None
                at = cs[nth][1] if (nth is not None and nth < len(cs)) else (cs[0][1] if cs else 0)
            rec["holds"] = tok
            if tok == "X":
                rec.update(status="left", why="register differs between paths/sites")
                res.append(rec)
                continue
            e, why = R.expr(tok, at)
            ma = re.fullmatch(r"A:\w*?([0-9A-Fa-f]{8}):(-?\d+)", tok)
            if ma and not c["params"][k].endswith("*"):
                # an address passed as a number: the EE value (the host address differs)
                e, why = hex((int(ma.group(1), 16) + int(ma.group(2))) & 0xFFFFFFFF), None
            if e is None:
                rec.update(status="left", why=why)
            else:
                if c["params"][k].endswith("*") and not e.startswith("(void *)"):
                    e = "(void *)(%s)" % e
                rec.update(status="auto", expr=e)
            res.append(rec)
    os.makedirs(outdir, exist_ok=True)
    with open(os.path.join(outdir, "r12_sites.csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(res[0].keys()) if res else ["source"])
        w.writeheader()
        for r in sorted(res, key=lambda r: (r["source"], r["caller"], r["callee"], str(r["nth"]), r["arg"])):
            w.writerow(r)
    return res, live, vf


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sigs", default=str(ROOT / "build/port-i386/host_sigs.json"))
    ap.add_argument("--asm", default=str(ROOT / "asm/main.s"))
    ap.add_argument("--out", default=str(HERE / "r12_regpass.csv"))
    ap.add_argument("--unresolved", help="also write the padded args no caller parameter explains (csv)")
    ap.add_argument("--sites", help="robust pass: classify every unresolved padded argument into DIR/r12_sites.csv "
                    "and write the auto-resolved ones to r12_regauto.csv")
    a = ap.parse_args()
    import hostify
    import link_catalog as L
    srcs = sorted({r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv")) if r["source"].endswith(".c")})
    funcs = parse_asm(a.asm, load_starts(), jtbl_targets(a.asm))
    fl = flow(funcs)
    # the value dataflow also sees entry values that survive a call (callee
    # exit summaries): take its entry tokens where flow() lost them
    vf = vflow(funcs)
    for F, sites in vf.items():
        agg = {}
        for _, callee, snap in sites:
            if callee in agg:
                agg[callee] = {r: (agg[callee][r] if agg[callee][r] == snap[r] else "X") for r in ARGR}
            else:
                agg[callee] = dict(snap)
        for callee, snap in agg.items():
            old = fl.get((F, callee), {})
            fl[(F, callee)] = {r: (snap[r] if snap[r].startswith("E$") else old.get(r, "X")) for r in ARGR}
    known = set()
    for r in csv.DictReader(open(ROOT / "config/matches.csv")):
        try:
            known.add(int(r["address"], 16))
        except ValueError:
            pass
    heads = dispatch_heads(funcs, parse_jtbls(a.asm), known)
    bysrc = collections.defaultdict(list)
    for r in csv.DictReader(open(ROOT / "config/matches.csv")):
        bysrc[r["source"]].append(r["name"])
    owner = {r["name"]: r["source"] for r in csv.DictReader(open(ROOT / "config/matches.csv"))}
    # R20 fixpoint: a caller that forwards an incoming register its C does not
    # declare gets that parameter (r12_widen.csv); its callers then pass it
    L.WIDEN = {}
    tailfwd = set()
    for it in range(8):
        log = tempfile.NamedTemporaryFile(delete=False, suffix=".csv").name
        os.environ["HOSTIFY_PAD_LOG"] = log
        hostify.REGPASS = {}
        hostify.REGEXPR = {}
        hostify.REGSYM = {}
        hostify.configure(a.sigs)
        for s in srcs:
            hostify.transform((ROOT / s).read_text(encoding="latin-1"), s)
        canon = hostify.SIGS["canon"]
        rows = set()
        syms = set()
        unres = set()
        widen = {}
        padlog = []
        for line in open(log):
            src, callee, have, _want, ks, *rest = line.strip().split(",")
            ks = [int(x) for x in ks.split(";") if x]
            fn = rest[0] if rest and rest[0] else None
            nth = int(rest[1]) if len(rest) > 1 and rest[1] else None
            padlog.append((src, callee, ks, fn, nth))
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
                    if re.fullmatch(r"E\$\w+", tok) and tok[1:] in freg:
                        rows.add((src, F, callee, k, freg.index(tok[1:])))
                    elif sym_add(tok, 0) and not re.fullmatch(r"E\$\w+", tok) and not creg[k].startswith("$f"):
                        # "param + k" or a load through the caller's parameter
                        # (hostify r12_regsym.csv); the base register must be a
                        # parameter the caller's C declares
                        bad = [r for r in re.findall(r"E(\$\w+)", tok) if r not in freg]
                        if bad:
                            unres.add((src, F, callee, k, tok))
                        else:
                            syms.add((src, F, callee, k, re.sub(r"E(\$\w+)", lambda mm: "P%d" % freg.index(mm.group(1)), tok)))
                    else:
                        unres.add((src, F, callee, k, tok))
                        if re.fullmatch(r"E\$\w+", tok) and owner.get(F) == src and not fc.get("variadic"):
                            widen.setdefault(F, set()).add(tok[1:])
        os.unlink(log)
        # R22: a dispatch head `f(p) { table[i](p); }` whose asm tail-jumps
        # (`jr $v0`) with $a1.. still holding its own entry values passes them
        # on to the table entry: widen f to them (hostify forwards them)
        for (F, key), snap in fl.items():
            if key != "*jr*" or F not in heads or F not in canon or owner.get(F) not in bysrc:
                continue
            fc = canon[F]
            if fc.get("variadic"):
                continue
            freg = regs(L.WIDEN.get(F, fc["params"]))
            for r in ARGR[1:4]:
                if snap.get(r) == "E" + r and r not in freg:
                    widen.setdefault(F, set()).add(r)
                    tailfwd.add(F)
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
    with open(HERE / "r12_tailfwd.csv" if a.out == str(HERE / "r12_regpass.csv") else a.out + ".tailfwd.csv",
              "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["function"])
        for F in sorted(tailfwd):
            w.writerow([F])
    print(f"tail-forwarding dispatch heads: {len(tailfwd)}")
    with open(a.out, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["source", "caller", "callee", "arg", "caller_param"])
        for r in sorted(rows):
            w.writerow(r)
    print(f"{a.out}: {len(rows)} rows")
    symf = HERE / "r12_regsym.csv" if a.out == str(HERE / "r12_regpass.csv") else a.out + ".regsym.csv"
    with open(symf, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["source", "caller", "callee", "arg", "value"])
        for r in sorted(syms):
            w.writerow(r)
    print(f"{symf}: {len(syms)} symbolic rows (parameter + offset / loads through it)")
    if a.sites:
        jt = parse_jtbls(a.asm)
        if os.environ.get("REGPASS_DUMP"):
            import pickle
            pickle.dump((canon, padlog, rows), open(os.environ["REGPASS_DUMP"], "wb"))
        res, live, _ = resolve_locals(a, funcs, canon, padlog, rows, jt, a.sites, vf, srcs, tailfwd, syms)
        cnt = collections.Counter(r["status"] for r in res)
        print(f"{a.sites}/r12_sites.csv: {len(res)} padded arguments without a caller parameter: " +
              ", ".join(f"{k} {v}" for k, v in sorted(cnt.items())))
        auto = HERE / "r12_regauto.csv" if a.out == str(HERE / "r12_regpass.csv") else a.out + ".auto.csv"
        with open(auto, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["source", "caller", "callee", "arg", "nth", "expr"])
            for r in sorted({(r["source"], r["caller"], r["callee"], r["arg"], r["nth"], r["expr"])
                             for r in res if r["status"] == "auto"}):
                w.writerow(r)
        print(f"{auto}: {cnt.get('auto', 0)} rows")
    if a.unresolved:
        with open(a.unresolved, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["source", "caller", "callee", "arg", "register_holds"])
            for r in sorted(unres):
                w.writerow(r)
        print(f"{a.unresolved}: {len(unres)} unresolved padded args")


if __name__ == "__main__":
    main()
