#!/usr/bin/env python3
"""Link-level check of the host objects (no link is attempted).

usage: python3 port/tools/host_link_check.py [OBJDIR] [--csv OUT.csv]
OBJDIR defaults to build/port_probe/i386/obj (port/tools/probe_host_build.py).

Runs nm over every object and reports
  * duplicate strong definitions (same global symbol in more than one object)
  * credited functions (config/matches.csv `complete`, C sources) that no
    object defines globally
  * symbols referenced but defined nowhere, classified by where their address
    falls (config/symbol_addrs.txt, else the _XXXXXXXX suffix):
      data inside a data unit  -> resolvable as unit + offset
      data not in a data unit  -> needs a data definition
      bss                      -> needs a host definition (zeroed storage)
      text: alias -> same address as a credited function under another
                     name (func_X vs residual_X); resolvable by an alias
      text label / C-less function / placeholder -> code with no C
      host runtime             -> compiler/libc/platform-layer symbols
"""
import argparse
import bisect
import collections
import csv
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEXT_END, DATA_END, BSS_END = 0x00424200, 0x004C2580, 0x00634380
NM = shutil.which("llvm-nm") or "nm"  # llvm-nm also reads wasm objects


def num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def nm(objs, *flags):
    out = []
    for i in range(0, len(objs), 500):
        p = subprocess.run([NM, "-A", *flags, *objs[i:i + 500]],
                           capture_output=True, text=True)
        out.extend(p.stdout.splitlines())
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("objdir", nargs="?", default=str(ROOT / "build/port_probe/i386/obj"))
    ap.add_argument("--csv", help="write undefined symbols + class here")
    a = ap.parse_args()
    objs = sorted(str(p) for p in Path(a.objdir).glob("*.o"))
    if not objs:
        sys.exit(f"no objects in {a.objdir}")
    defs = collections.defaultdict(list)
    for line in nm(objs, "--defined-only"):
        m = re.match(r"(\S+?\.o):\s*(?:[0-9a-f]+)?\s+([A-Za-z])\s+(\S+)$", line)
        if m and m.group(2) in "TDBRVW":
            defs[m.group(3)].append((Path(m.group(1)).name, m.group(2)))
    refs = collections.Counter()
    for line in nm(objs, "-u"):
        p = line.split()
        if p:
            refs[p[-1]] += 1
    dups = {s: v for s, v in defs.items() if sum(k not in "VW" for _, k in v) > 1}
    print(f"objects: {len(objs)}  global definitions: {len(defs)}  "
          f"duplicate strong definitions: {len(dups)}")
    for s, v in sorted(dups.items())[:50]:
        print(f"  DUP {s}: {', '.join(o for o, _ in v)}")

    with open(ROOT / "config/matches.csv", newline="") as f:
        mt = {r["name"]: r for r in csv.DictReader(f)}
    cred = [n for n, r in mt.items() if r["status"] == "complete" and r["source"].endswith(".c")]
    nodef = [n for n in cred if n not in defs]
    print(f"credited C functions with no global definition: {len(nodef)}")
    for n in nodef[:20]:
        print(f"  {n} ({mt[n]['source']})")

    addrs = {}
    for line in open(ROOT / "config/symbol_addrs.txt"):
        m = re.match(r"\s*(\S+)\s*=\s*(0x[0-9a-fA-F]+)", line)
        if m:
            addrs[m.group(1)] = int(m.group(2), 16)
    with open(ROOT / "config/data_matches.csv", newline="") as f:
        du = sorted((num(r["address"]), num(r["size"])) for r in csv.DictReader(f))
    starts = [d[0] for d in du]
    cred_at = {num(r["address"]): n for n, r in mt.items() if r["status"] == "complete"}
    cls = collections.Counter()
    ex = collections.defaultdict(list)
    rows = []
    for s, c in sorted(refs.items()):
        if s in defs:
            continue
        ad = addrs.get(s)
        if ad is None:
            m = re.search(r"_([0-9A-Fa-f]{8})$", s)
            ad = int(m.group(1), 16) if m else None
        if ad is None:
            k = "host runtime (compiler/libc/platform layer)"
        elif ad < TEXT_END:
            if s in mt and mt[s]["status"] == "placeholder":
                k = "text: placeholder function"
            elif s in mt:
                k = "text: credited in a .S source"
            elif ad in cred_at and cred_at[ad] in defs:
                k = "text: other name of a credited function (alias)"
            elif s.startswith(("func_", "residual_")):
                k = "text: C-less function"
            else:
                k = "text: label/table inside code"
        elif ad < DATA_END:
            i = bisect.bisect_right(starts, ad) - 1
            inside = i >= 0 and du[i][0] <= ad < du[i][0] + du[i][1]
            k = "data: inside a data unit (unit+offset)" if inside else "data: no data unit"
        elif ad < BSS_END:
            k = "bss: needs host storage"
        else:
            k = "outside image (scratchpad/hw/end marker)"
        cls[k] += 1
        ex[k].append(s)
        rows.append((s, c, f"0x{ad:08X}" if ad is not None else "", k))
    print(f"undefined everywhere: {len(rows)}")
    for k, v in cls.most_common():
        print(f"  {v:6d} {k}   e.g. {' '.join(ex[k][:4])}")
    if a.csv:
        with open(a.csv, "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["symbol", "refs", "address", "class"])
            w.writerows(rows)


if __name__ == "__main__":
    main()
