#!/usr/bin/env python3
"""Symbol-resolution generator for the host link (Port G).

usage:
  gen_link_glue.py glue --out DIR --target i386|emscripten|wasm32
                   [--sigs host_sigs.json] INPUT...
  gen_link_glue.py sigs --out host_sigs.json [--stub-objs DIR] WASM_OBJDIR...
  gen_link_glue.py sigs --out host_sigs.json --raw-build DIR
      (runs the raw wasm build itself: probe_host_build.py --target emscripten
       --diag --resume --out DIR, and port/stubs with emcc into DIR/stubobj)

INPUT is a directory of objects or a static library (the mvc2_game build).
Nothing here is written per symbol by hand: every resolution is derived from
the catalogs (port/tools/link_catalog.py) and from nm/wasm symbol tables.

`glue` writes into DIR:
  mvc2_glue_data.c   zero storage + aliases: the EE BSS as one blob
                     (0x004C2580..0x00634380, so the layout and the end-of-BSS
                     marker are kept), stand-ins for the data units that are
                     not C (VU1 microcode .vsm, src/data_asm/*.s), the gaps
                     between credited units (data with no unit), the 16 KB
                     scratchpad, and a blob of distinct addresses for the
                     code-interior labels that data tables reference
  mvc2_glue_stubs.c  logging stubs for every function with no C (C-less,
                     FN() placeholders, constant-address table entries,
                     code labels referenced as functions), and thunks for
                     code addresses known under a second name
  mvc2_glue_table.c  mvc2_fakes[]: every faked symbol, generated or
                     hand-written (port/stubs, found by MVC2_STUB_ENTER),
                     and every host implementation (port/host/host_impl.csv)
  mvc2_host_protos.h canonical prototypes of the host implementations
                     (generated stubs are weak, so port/host overrides them)
  link_extra.rsp     linker arguments (ELF --defsym for code aliases)
  stubs.csv          the same list as mvc2_fakes[]
  link_glue.csv      every symbol the game references but does not define,
                     with how it is resolved
  summary.txt        counts

`sigs` reads wasm32 objects of a build WITHOUT hostify R12/R13 and writes the
canonical signature of every function (from its definition, or for a stub
from its callers) plus the per-object mismatches, for hostify R12/R13.
"""
import argparse
import collections
import csv
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import link_catalog as L  # noqa: E402

ROOT = L.ROOT
STUBS_DIR = ROOT / "port/stubs"
NM = shutil.which("llvm-nm") or os.path.join(os.environ.get("EMSDK", "/home/user/emsdk"),
                                             "upstream/bin/llvm-nm")
# provided by the linker / the wasm runtime, never by game or glue code
LINKER_SYMBOLS = {"_GLOBAL_OFFSET_TABLE_", "__indirect_function_table", "__stack_pointer",
                  "__memory_base", "__table_base", "__dso_handle"}
# defined by the generated glue itself (mvc2_glue_table.c)
GLUE_SYMBOLS = {"mvc2_fakes", "mvc2_fake_count", "mvc2_ee_code_label_addr",
                "mvc2_ee_code_label_count"}
CTYPE = {"i32": "int", "i64": "long long", "f32": "float", "f64": "double", "void": "void"}


# ---------------------------------------------------------------- inputs
def objects(inputs):
    out = []
    for p in inputs:
        p = Path(p)
        if p.is_dir():
            out.extend(sorted(str(x) for x in p.glob("*.o")))
        elif p.exists():
            out.append(str(p))
    return out


def nm_scan(paths):
    """(defined: name -> [kinds], undefined: Counter, weak_undef: set)."""
    defs = collections.defaultdict(list)
    undef = collections.Counter()
    wundef = set()
    for i in range(0, len(paths), 400):
        r = subprocess.run([NM, "-A", *paths[i:i + 400]], capture_output=True, text=True)
        for line in r.stdout.splitlines():
            m = re.match(r"^.*?:\s+(?:[0-9a-fA-F]+\s+)?([A-Za-z?-])\s+(\S+)$", line)
            if not m:
                continue
            k, n = m.group(1), m.group(2)
            if k == "U":
                undef[n] += 1
            elif k in "wv":
                wundef.add(n)
            elif k not in "t d b r":
                defs[n].append(k)
    return defs, undef, wundef


def hand_stubs():
    """name -> (addr, kind, file) for MVC2_STUB_ENTER markers in port/stubs."""
    out = {}
    pat = re.compile(r'MVC2_STUB_ENTER\(\s*"(\w+)"\s*,\s*(0x[0-9A-Fa-f]+|0)u?\s*,\s*"([^"]*)"')
    fwd = re.compile(r'FWD\(\s*"(\w+)"\s*,\s*(0x[0-9A-Fa-f]+)u?\s*,\s*"([^"]*)"')
    for f in sorted(STUBS_DIR.glob("*.c")):
        text = f.read_text()
        for m in pat.finditer(text):
            out.setdefault(m.group(1), (int(m.group(2), 16), m.group(3), f.name))
        for m in fwd.finditer(text):
            out.setdefault(m.group(1), (int(m.group(2), 16), "libc forward: " + m.group(3), f.name))
    return out


def load_sigs(path):
    if not path or not Path(path).exists():
        return None
    return json.loads(Path(path).read_text())


# ---------------------------------------------------------------- glue
def proto(name, sig, fallback_ret="int"):
    """C prototype pieces (ret, params text) for a stub/thunk."""
    if sig:
        ret = sig["ret"]
        params = sig["params"]
        ptxt = ", ".join(f"{t} a{i}" for i, t in enumerate(params)) or "void"
        if sig.get("variadic"):
            ptxt = (ptxt if params else "") + (", ..." if params else "...")
        return ret, ptxt, params
    return fallback_ret, "void", []


def ret_zero(ret):
    if ret == "void":
        return ""
    return " return 0;"


def gen_glue(a):
    inputs = objects(a.inputs)
    if not inputs:
        sys.exit("gen_link_glue: no objects in inputs")
    defs, undef, wundef = nm_scan(inputs)
    sigs = load_sigs(a.sigs)
    func_refs = set(sigs["func_names"]) if sigs else None
    canon = L.apply_host_sig_overrides(sigs["canon"]) if sigs else {}
    host = L.host_runtime_names()
    hand = hand_stubs()
    himpl = L.host_impl()
    addrs = L.symbol_addrs()
    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    wasm = a.target in ("emscripten", "wasm32")

    rows = []        # link_glue.csv
    fakes = []       # (name, addr, kind, how, origin)
    bss, nonc, gaps, labels_data, stubs, thunks, defsyms, errors = [], {}, {}, [], [], [], [], []
    scratch = []
    hand_used = set()

    def is_func(n, default):
        if func_refs is None:
            return default
        return n in func_refs

    cat_at = L.credited_at()
    for n in sorted(undef):
        if n in defs or n in wundef:
            continue
        ad = L.address_of(n)
        if n in hand:
            hand_used.add(n)
            rows.append((n, undef[n], ad, "stub (hand-written)", hand[n][2]))
            continue
        if n in GLUE_SYMBOLS:
            continue
        if n in LINKER_SYMBOLS or (n in host and not L.ADDR_SUFFIX.search(n)):
            rows.append((n, undef[n], ad, "host runtime", "host libc / compiler-rt"))
            continue
        if ad is None:
            errors.append(n)
            rows.append((n, undef[n], "", "UNRESOLVED", "no catalog address"))
            continue
        cls = L.classify_address(n, ad)
        if cls == "text":
            f = L.function_containing(ad)
            target = None
            if ad in cat_at and cat_at[ad] != n:
                target = cat_at[ad]
            elif f and f[0] == ad and f[2] != n and (f[2] in defs or f[2] in hand):
                target = f[2]
            if target is not None:
                fn = is_func(n, not n.startswith(("lbl_", "D_")))
                if not wasm:
                    defsyms.append((n, target))
                    rows.append((n, undef[n], ad, "code alias (--defsym)", target))
                elif fn:
                    thunks.append((n, target, ad))
                    rows.append((n, undef[n], ad, "code alias (thunk)", target))
                else:
                    errors.append(n)
                    rows.append((n, undef[n], ad, "UNRESOLVED", f"data-declared code address of {target} (hostify R13)"))
                continue
            st = L.matches().get(n, {}).get("status")
            if f is None:
                kind = "const-address entry"
            elif f[0] != ad:
                kind = "code label"
            elif st == "placeholder":
                kind = "placeholder (FN asm)"
            elif st == "complete":
                kind = "credited asm"
            else:
                kind = "c-less " + f[3]
            if kind == "code label" and not is_func(n, False):
                labels_data.append((n, ad))
                rows.append((n, undef[n], ad, "code label (data slot)", "mvc2_ee_code_labels"))
                fakes.append((n, ad, "code label (data)", "distinct zero slot in mvc2_ee_code_labels", "generated"))
                continue
            stubs.append((n, ad, kind))
            rows.append((n, undef[n], ad, "stub (generated)", kind))
            continue
        if cls == "data":
            u = L.unit_containing(ad)
            if u is not None and not u[3].endswith(".c"):
                nonc.setdefault(u, []).append((n, ad))
                rows.append((n, undef[n], ad, "non-C data unit stand-in", u[2]))
                continue
            if u is not None:
                gaps.setdefault((ad, ad + 4, "unresolved-in-unit:" + u[2]), []).append((n, ad))
                rows.append((n, undef[n], ad, "zero stand-in (inside C unit, not aliased)", u[2]))
                continue
            gaps.setdefault(gap_of(ad), []).append((n, ad))
            rows.append((n, undef[n], ad, "zero stand-in (no data unit)", ""))
            continue
        if cls == "bss":
            bss.append((n, ad))
            rows.append((n, undef[n], ad, "EE BSS blob alias", "mvc2_ee_bss"))
            continue
        if cls == "scratchpad":
            scratch.append((n, ad))
            rows.append((n, undef[n], ad, "scratchpad array", "mvc2_ee_scratchpad"))
            continue
        if cls == "null":
            errors.append(n)
            rows.append((n, undef[n], ad, "UNRESOLVED", "null address (hostify R16 makes it weak)"))
            continue
        gaps.setdefault((ad, ad + 4, "outside"), []).append((n, ad))
        rows.append((n, undef[n], ad, "zero stand-in (outside image)", ""))

    # ---- data glue ------------------------------------------------------
    D = []
    D.append("/* generated by port/tools/gen_link_glue.py - do not edit */")
    D.append("/* Zero storage and aliases for data the game references but no C defines. */")
    if wasm:
        D.append('#define GLUE_ALIAS(name, base, off, size) __asm__(".globl " #name "\\n.set " #name ", " #base "+" #off "\\n");')
    else:
        D.append('#define GLUE_ALIAS(name, base, off, size) __asm__(".globl " #name "\\n.type " #name ",@object\\n.set " #name ", " #base "+" #off "\\n.size " #name ", " #size "\\n");')
    # BSS blob, sizes from neighbouring catalog addresses
    bss_size = L.BSS_END - L.BSS_START
    D.append(f"\n/* EE BSS 0x{L.BSS_START:08X}..0x{L.BSS_END:08X} (crt0 zeroes it; so does the host loader) */")
    D.append(f"__attribute__((aligned(128))) unsigned char mvc2_ee_bss[0x{bss_size:X} + 16];")
    cuts = sorted({a2 for a2 in addrs.values() if L.BSS_START <= a2 <= L.BSS_END} | {L.BSS_END})
    import bisect
    for n, ad in sorted(bss, key=lambda x: x[1]):
        i = bisect.bisect_right(cuts, ad)
        nxt = cuts[i] if i < len(cuts) else L.BSS_END
        size = max(nxt - ad, 1) if ad < L.BSS_END else 0
        D.append(f"GLUE_ALIAS({n}, mvc2_ee_bss, 0x{ad - L.BSS_START:X}, 0x{size:X})")
        if ad == L.BSS_END:
            fakes.append((n, ad, "end-of-BSS marker", "alias at the end of mvc2_ee_bss", "generated"))
    # non-C data units
    for u, lst in sorted(nonc.items()):
        base = u[2]
        bname = base if base not in defs else f"mvc2_nonc_{base}"
        D.append(f"\n/* {u[3]}: data unit that is not C on the host (zero stand-in, 0x{u[1]:X} bytes) */")
        D.append(f"__attribute__((aligned(16))) unsigned char {bname}[0x{u[1]:X}];")
        fakes.append((base, u[0], "non-C data unit", f"zero stand-in for {u[3]}", "generated"))
        for n, ad in sorted(lst, key=lambda x: x[1]):
            if n == bname:
                continue
            D.append(f"GLUE_ALIAS({n}, {bname}, 0x{ad - u[0]:X}, 0x4)")
            fakes.append((n, ad, "non-C data unit", f"inside zero stand-in of {u[2]}", "generated"))
    # gaps
    for (lo, hi, why), lst in sorted(gaps.items()):
        gname = f"mvc2_gap_{lo:08X}"
        al = lo & -lo
        al = min(al if al else 16, 16)
        D.append(f"\n/* 0x{lo:08X}..0x{hi:08X} {why or 'between credited data units'}: values unknown on the host (zero) */")
        D.append(f"__attribute__((aligned({al}))) unsigned char {gname}[0x{max(hi - lo, 1):X}];")
        for n, ad in sorted(lst, key=lambda x: x[1]):
            D.append(f"GLUE_ALIAS({n}, {gname}, 0x{ad - lo:X}, 0x{max(hi - ad, 1):X})")
            fakes.append((n, ad, "data (no C)", f"zero bytes in {gname} ({why or 'gap between units'})", "generated"))
    # scratchpad
    D.append("\n/* EE scratchpad 0x70000000, 16 KB */")
    D.append("__attribute__((aligned(64))) unsigned char mvc2_ee_scratchpad[0x4000];")
    for n, ad in scratch:
        D.append(f"GLUE_ALIAS({n}, mvc2_ee_scratchpad, 0x{ad - L.SCRATCHPAD:X}, 0x{0x4000 - (ad - L.SCRATCHPAD):X})")
        fakes.append((n, ad, "scratchpad", "host array mvc2_ee_scratchpad", "generated"))
    # code labels referenced as data
    D.append("\n/* EE code-interior labels taken as data (switch/jump tables): one distinct")
    D.append("   4-byte slot each; mvc2_ee_code_label_addr[] maps slot -> EE address. */")
    D.append(f"__attribute__((aligned(16))) const unsigned char mvc2_ee_code_labels[{4 * max(len(labels_data), 1)}];")
    for i, (n, ad) in enumerate(sorted(labels_data, key=lambda x: x[1])):
        D.append(f"GLUE_ALIAS({n}, mvc2_ee_code_labels, 0x{4 * i:X}, 0x4)")
    D.append("const unsigned mvc2_ee_code_label_addr[] = {")
    D.extend(f"    0x{ad:08X}u, /* {n} */" for n, ad in sorted(labels_data, key=lambda x: x[1]))
    D.append("    0 };")
    D.append(f"const unsigned mvc2_ee_code_label_count = {len(labels_data)};")
    (out / "mvc2_glue_data.c").write_text("\n".join(D) + "\n")

    # ---- generated stubs ------------------------------------------------
    S = ["/* generated by port/tools/gen_link_glue.py - do not edit */",
         '#include "mvc2_stubs.h"', ""]
    for n, ad, kind in sorted(stubs, key=lambda x: x[1]):
        sig = canon.get(n)
        ret, ptxt, _ = proto(n, sig)
        # weak: a host implementation (port/host, host_impl.csv) overrides it
        S.append(f"__attribute__((weak)) {ret} {n}({ptxt}) {{ MVC2_STUB_ENTER(\"{n}\", 0x{ad:08X}u, \"{kind}\");{ret_zero(ret)} }}")
        if n in himpl:
            continue
        fakes.append((n, ad, kind, "logs, returns 0" if ret != "void" else "logs", "generated"))
    for n, target, ad in sorted(thunks):
        sig = canon.get(target)
        ret, ptxt, params = proto(target, sig)
        if sig and sig.get("variadic"):
            S.append(f"/* {n}: variadic {target}; thunk forwards no varargs */")
        S.append(f"extern {ret} {target}({ptxt});")
        args = ", ".join(f"a{i}" for i in range(len(params)))
        call = f"{target}({args})"
        S.append(f"{ret} {n}({ptxt}) {{ {'return ' if ret != 'void' else ''}{call}; }}")
        fakes.append((n, ad, "code alias thunk", f"calls {target}", "generated"))
    (out / "mvc2_glue_stubs.c").write_text("\n".join(S) + "\n")

    # ---- host implementations (port/host/host_impl.csv) -----------------
    H = ["/* generated by port/tools/gen_link_glue.py - do not edit */",
         "/* Canonical prototypes (host_sigs.json) of the functions port/host implements;",
         "   name__game is the game's own body of a replaced credited function (hostify R17). */",
         "#ifndef MVC2_HOST_PROTOS_H", "#define MVC2_HOST_PROTOS_H"]
    for n, r in sorted(himpl.items()):
        sig = canon.get(n)
        ret, ptxt, _ = proto(n, sig, "int")
        ad = L.address_of(n) or 0
        st = L.matches().get(n, {}).get("status", "")
        credited = st in ("complete", "placeholder") and n in defs
        H.append(f"{ret} {n}({ptxt});" + ("" if sig else "  /* no canonical signature */"))
        if credited and not (r.get("ret") or "").strip():
            H.append(f"{ret} {n}__game({ptxt});")
        kind = "host: replaces credited C" if credited else "host: replaces C-less code"
        fakes.append((n, ad, kind, r.get("what", ""), f"port/host/{r.get('file', '')} ({r.get('group', 'core')})"))
    H.append("#endif")
    (out / "mvc2_host_protos.h").write_text("\n".join(H) + "\n")

    # ---- hand-written stubs and defsyms ---------------------------------
    for n, (ad, kind, fname) in sorted(hand.items()):
        fakes.append((n, ad, kind, "hand-written", f"port/stubs/{fname}"))
    rsp = []
    for n, target in sorted(defsyms):
        rsp.append(f"-Wl,--defsym={n}={target}")
        fakes.append((n, L.address_of(n) or 0, "code alias", f"--defsym to {target}", "generated"))
    (out / "link_extra.rsp").write_text("\n".join(rsp) + ("\n" if rsp else ""))

    # ---- table ----------------------------------------------------------
    fakes.sort(key=lambda r: (r[2], r[1], r[0]))
    T = ["/* generated by port/tools/gen_link_glue.py - do not edit */",
         '#include "mvc2_stubs.h"', "const struct mvc2_fake mvc2_fakes[] = {"]
    for n, ad, kind, how, origin in fakes:
        T.append(f'    {{"{n}", 0x{ad:08X}u, "{kind}", "{how} [{origin}]"}},')
    T.append('    {0, 0, 0, 0}};')
    T.append(f"const unsigned mvc2_fake_count = {len(fakes)};")
    (out / "mvc2_glue_table.c").write_text("\n".join(T) + "\n")
    with open(out / "stubs.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["symbol", "ee_address", "kind", "host_behaviour", "origin"])
        for n, ad, kind, how, origin in fakes:
            w.writerow([n, f"0x{ad:08X}", kind, how, origin])
    with open(out / "link_glue.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["symbol", "refs", "ee_address", "resolution", "detail"])
        for n, c, ad, res, det in rows:
            w.writerow([n, c, f"0x{ad:08X}" if isinstance(ad, int) else (ad or ""), res, det])
    summ = collections.Counter(r[3] for r in rows)
    fk = collections.Counter(r[2] for r in fakes)
    lines = [f"target {a.target}: {len(inputs)} objects, {len(defs)} defined, "
             f"{sum(1 for n in undef if n not in defs and n not in wundef)} undefined before glue",
             "resolutions:"] + [f"  {v:6d}  {k}" for k, v in summ.most_common()]
    lines += ["faked symbols by kind:"] + [f"  {v:6d}  {k}" for k, v in fk.most_common()]
    lines += [f"faked total: {len(fakes)}", f"unresolved: {len(errors)}"] + [f"  {e}" for e in errors]
    (out / "summary.txt").write_text("\n".join(lines) + "\n")
    print("\n".join(lines))
    return 1 if errors and not a.allow_unresolved else 0




def gap_of(ad):
    """(lo, hi, why) of the hole between credited data units around `ad`."""
    import bisect
    du = L.data_units()
    starts = [u[0] for u in du]
    i = bisect.bisect_right(starts, ad) - 1
    lo = du[i][0] + du[i][1] if i >= 0 else L.TEXT_END
    hi = du[i + 1][0] if i + 1 < len(du) else L.DATA_END
    return (lo, hi, "")


# ---------------------------------------------------------------- sigs
def main():
    ap = argparse.ArgumentParser()
    sub = ap.add_subparsers(dest="cmd", required=True)
    g = sub.add_parser("glue")
    g.add_argument("--out", required=True)
    g.add_argument("--target", required=True, choices=["i386", "emscripten", "wasm32"])
    g.add_argument("--sigs")
    g.add_argument("--allow-unresolved", action="store_true")
    g.add_argument("inputs", nargs="+")
    s = sub.add_parser("sigs")
    s.add_argument("--out", required=True)
    s.add_argument("--stub-objs", action="append", default=[])
    s.add_argument("--raw-build", help="run the raw wasm build into this directory first")
    s.add_argument("inputs", nargs="*")
    a = ap.parse_args()
    if a.cmd == "glue":
        sys.exit(gen_glue(a))
    if a.raw_build:
        raw_build(Path(a.raw_build))
        a.inputs = [str(Path(a.raw_build) / "obj")]
        a.stub_objs.append(str(Path(a.raw_build) / "stubobj"))
    if not a.inputs:
        sys.exit("gen_link_glue.py sigs: no inputs (give WASM_OBJDIR or --raw-build)")
    import host_sigs
    sys.exit(host_sigs.main_sigs(a))


def raw_build(d):
    """The wasm build with hostify R12-R14 off, plus wasm objects of the
    hand-written stubs: the input of `sigs`."""
    emsdk = os.environ.get("EMSDK", "/home/user/emsdk")
    emcc = shutil.which("emcc") or os.path.join(emsdk, "upstream/emscripten/emcc")
    target = "emscripten" if os.path.exists(emcc) else "wasm32"
    env = {k: v for k, v in os.environ.items() if k != "MVC2_HOST_SIGS"}
    subprocess.run([sys.executable, str(HERE / "probe_host_build.py"), "--target", target,
                    "--diag", "--resume", "--out", str(d)], check=True, env=env)
    so = d / "stubobj"
    so.mkdir(parents=True, exist_ok=True)
    if target == "emscripten":
        for c in sorted(STUBS_DIR.glob("*.c")):
            o = so / (c.stem + ".o")
            if not o.exists() or o.stat().st_mtime < max(c.stat().st_mtime,
                                                         (STUBS_DIR / "mvc2_stubs.h").stat().st_mtime):
                subprocess.run([emcc, "-O1", f"-I{STUBS_DIR}", "-c", str(c), "-o", str(o)], check=True)
    else:
        print("gen_link_glue.py: no emcc; hand-written stub signatures come from their callers")


if __name__ == "__main__":
    main()
