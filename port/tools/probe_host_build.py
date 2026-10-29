#!/usr/bin/env python3
"""Compile every credited game/data C source for a 32-bit host target and
classify the failures.  Fast standalone counterpart of port/CMakeLists.txt
(same flags, same filter) for iterating on ps2_compat.h / hostify.py.

usage: python3 port/tools/probe_host_build.py [--target emscripten|i386|wasm32] [--jobs N]
           [--out DIR] [--only FILE...] [--no-hostify] [--resume]
           [--diag] [--sigs host_sigs.json]
Writes DIR/results.csv (source,ok,class,first_error) and prints a summary.
--diag records implicit declarations and missing returns in DIR/diag.csv
(input of `gen_link_glue.py sigs`); --sigs turns on hostify R12-R14.
"""
import argparse, csv, os, re, subprocess, sys, collections
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import hostify  # noqa: E402
from host_flags import TARGETS, common_flags, compiler  # noqa: E402


def credited_sources():
    code, data = set(), set()
    with open(ROOT / "config/matches.csv") as f:
        for r in csv.DictReader(f):
            if r["source"].endswith(".c"):
                code.add(r["source"])
    with open(ROOT / "config/data_matches.csv") as f:
        for r in csv.DictReader(f):
            if r["source"].endswith(".c"):
                data.add(r["source"])
    return sorted(code), sorted(data)


CLASSES = [
    ("inline-asm", r"invalid instruction|unknown register name|invalid operand for instruction|unknown token in expression|unrecognized instruction|invalid output constraint|invalid input constraint|asm"),
    ("int128/TI-mode", r"mode\(TI\)|unable to emulate|__int128|TImode|'TI'"),
    ("conflicting-types", r"conflicting types|redefinition of|redeclaration|previous definition"),
    ("incomplete/unknown-type", r"unknown type name|incomplete type|undeclared identifier"),
    ("mw-syntax", r"expected|extraneous|missing terminating"),
    ("section-attr", r"section"),
    ("init-not-constant", r"initializer element is not a compile-time constant|not a compile-time constant"),
    ("pointer-int", r"pointer|integer"),
]


def classify(err):
    for name, pat in CLASSES:
        if re.search(pat, err):
            return name
    return "other"


DIAG_FLAGS = ["-Wno-everything", "-Wimplicit-function-declaration", "-Wreturn-type",
              "-Wreturn-mismatch"]
DIAG_RE = re.compile(r"^(?P<file>[^:\s]+):(?P<line>\d+):(?P<col>\d+): warning: (?P<msg>.*?)(?: \[-W[\w-]+\])?$")


def diag_rows(src, stderr):
    rows = []
    for l in stderr.splitlines():
        m = DIAG_RE.match(l)
        if not m:
            continue
        msg = m.group("msg")
        k = re.search(r"(?:call to undeclared function|implicit declaration of function) '(\w+)'", msg)
        if k:
            rows.append((src, m.group("file"), m.group("line"), "implicit", k.group(1)))
        elif "does not return a value" in msg:
            rows.append((src, m.group("file"), m.group("line"), "noreturn", ""))
        elif "should return a value" in msg:
            rows.append((src, m.group("file"), m.group("line"), "bare-return", ""))
    return rows


def compile_one(src, target, outdir, use_hostify, diag=False):
    srcp = ROOT / src
    obj = outdir / "obj" / (src.replace("/", "__") + ".o")
    obj.parent.mkdir(parents=True, exist_ok=True)
    cmd = [compiler(target)] + TARGETS[target] + common_flags(ROOT)
    if diag:
        cmd = [c for c in cmd if c != "-w"] + DIAG_FLAGS
    if use_hostify:
        text = hostify.transform(srcp.read_text(encoding="latin-1"), src)
        hsrc = outdir / "hsrc" / src
        hsrc.parent.mkdir(parents=True, exist_ok=True)
        if not hsrc.exists() or hsrc.read_text(encoding="latin-1") != text:
            hsrc.write_text(text, encoding="latin-1")
        cmd += ["-I", str(outdir / "hsrc/src"), "-I", str(outdir / "hsrc/src/data"),
                "-I", str(srcp.parent), str(hsrc)]
    else:
        cmd += [str(srcp)]
    cmd += ["-c", "-o", str(obj)]
    p = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    errs = [l for l in p.stderr.splitlines() if ": error:" in l or "fatal error" in l]
    if diag:
        (outdir / "diag").mkdir(exist_ok=True)
        dp = outdir / "diag" / (src.replace("/", "__") + ".csv")
        rows = diag_rows(src, p.stderr)
        with open(dp, "w", newline="") as f:
            csv.writer(f).writerows(rows)
    if p.returncode == 0:
        return src, True, "", ""
    first = errs[0] if errs else p.stderr.strip().splitlines()[-1:] and p.stderr.strip().splitlines()[-1] or "?"
    first = re.sub(r"^.*?: (fatal )?error: ", "", first)
    return src, False, classify(first), first


def hostify_headers(outdir):
    """Filtered copies of every project header, found before src/ because the
    filtered .c files live next to them."""
    for h in list((ROOT / "src").glob("*.h")) + list((ROOT / "src/data").glob("*.h")):
        rel = h.relative_to(ROOT)
        dst = outdir / "hsrc" / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        text = hostify.transform(h.read_text(encoding="latin-1"), str(rel))
        if not dst.exists() or dst.read_text(encoding="latin-1") != text:
            dst.write_text(text, encoding="latin-1")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--target", default="i386", choices=sorted(TARGETS))
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    ap.add_argument("--out", default=None)
    ap.add_argument("--only", nargs="*")
    ap.add_argument("--no-hostify", action="store_true")
    ap.add_argument("--resume", action="store_true",
                    help="keep earlier ok rows whose object is newer than the filtered source")
    ap.add_argument("--diag", action="store_true",
                    help="record implicit declarations and missing returns (diag/*.csv, diag.csv)")
    ap.add_argument("--sigs", default=None,
                    help="host_sigs.json for hostify R12-R14 (gen_link_glue.py sigs)")
    ap.add_argument("--chunk", type=int, default=1000,
                    help="results.csv is rewritten after every CHUNK TUs (restart-safe)")
    a = ap.parse_args()
    out = Path(a.out or ROOT / "build/port_probe" / a.target)
    out.mkdir(parents=True, exist_ok=True)
    hostify.configure(a.sigs)
    code, data = credited_sources()
    allsrc = a.only or sorted(set(code) | set(data))
    if not a.no_hostify:
        hostify_headers(out)
    prev = {}
    rpath = out / "results.csv"
    if rpath.exists():  # merged back in; reused only with --resume
        with open(rpath) as f:
            for r in csv.DictReader(f):
                prev[r["source"]] = (r["source"], r["ok"] == "True", r["class"], r["first_error"])
    done = {}

    diag_marker = out / "diag" / ".flags"
    diag_same = (not a.diag) or (diag_marker.exists() and diag_marker.read_text() == " ".join(DIAG_FLAGS))

    def fresh(s):
        r = prev.get(s)
        if not a.resume or not r or not r[1] or not diag_same:
            return False
        if a.diag and not (out / "diag" / (s.replace("/", "__") + ".csv")).exists():
            return False
        obj = out / "obj" / (s.replace("/", "__") + ".o")
        hs = out / "hsrc" / s
        if a.no_hostify or not obj.exists() or not hs.exists():
            return False
        if hostify.transform((ROOT / s).read_text(encoding="latin-1"), s) != hs.read_text(encoding="latin-1"):
            return False
        return obj.stat().st_mtime >= hs.stat().st_mtime

    todo = []
    for s in allsrc:
        if fresh(s):
            done[s] = prev[s]
        else:
            todo.append(s)

    def flush():
        merged = dict(prev)
        merged.update(done)
        with open(rpath, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["source", "ok", "class", "first_error"])
            w.writerows(merged[k] for k in sorted(merged))

    with ThreadPoolExecutor(a.jobs) as ex:
        for i in range(0, len(todo), a.chunk):
            for r in ex.map(lambda s: compile_one(s, a.target, out, not a.no_hostify, a.diag), todo[i:i + a.chunk]):
                done[r[0]] = r
            flush()
            print(f"  .. {min(i + a.chunk, len(todo))}/{len(todo)} compiled", flush=True)
    flush()
    if a.diag:
        diag_marker.parent.mkdir(exist_ok=True)
        diag_marker.write_text(" ".join(DIAG_FLAGS))
        with open(out / "diag.csv", "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["source", "file", "line", "kind", "name"])
            for s_ in allsrc:
                dp = out / "diag" / (s_.replace("/", "__") + ".csv")
                if dp.exists():
                    w.writerows(csv.reader(open(dp)))
    res = [done[s] for s in allsrc]
    ok = sum(1 for r in res if r[1])
    cs = set(code)
    okc = sum(1 for r in res if r[1] and r[0] in cs)
    okd = sum(1 for r in res if r[1] and r[0] not in cs)
    print(f"target={a.target} TUs={len(res)} ok={ok} fail={len(res)-ok} "
          f"(game ok {okc}/{len(cs & set(allsrc))}, data-only ok {okd}/{len(set(allsrc)-cs)})")
    c = collections.Counter(r[2] for r in res if not r[1])
    for k, v in c.most_common():
        print(f"  {v:6d} {k}")
    if a.only:
        for r in res:
            if not r[1]:
                print(r[0], r[3])


if __name__ == "__main__":
    main()
