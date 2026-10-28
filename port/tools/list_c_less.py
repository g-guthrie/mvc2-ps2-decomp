#!/usr/bin/env python3
"""List the text spans and data units that have no honest C for the host port.

usage: python3 port/tools/list_c_less.py [--csv OUT.csv] [--summary] [--data]

"Honest C" = a `complete` row of config/matches.csv (verified matching C, the
only C that DECOMP.md credits).  Everything else in the text span must come
from somewhere else in the port: a platform replacement, a fresh rewrite, or
the retail assembly read by hand.  Classes:

  unmatched     functions.csv `code` span with no matches.csv row
  residual      functions.csv `assembly_residual` span with no matches.csv row
  placeholder   matches.csv `placeholder`: C exists and is readable but still
                carries an asm barrier / constraint (uncredited); the host build
                compiles it with the barrier removed (hostify R4/R5)
  gap           config/gaps.csv text gap (no catalog entry at all)
  padding       alignment_padding / padding spans (no code; listed only with
                --all)

With --data, data units whose data_matches.csv progress is `placeholder` (raw
arrays/fills, uncredited) are listed as class `data-placeholder`.

Sizes accept both `0x..` hex and plain decimal (both occur in the catalogs).
"""
import argparse
import collections
import csv
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
TEXT_END = 0x00424200


def num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith("0x") else int(s)


def rows(name):
    with open(ROOT / "config" / name, newline="") as f:
        return list(csv.DictReader(f))


def collect(include_padding=False, include_data=False):
    funcs = {num(r["address"]): r for r in rows("functions.csv")}
    matches = {num(r["address"]): r for r in rows("matches.csv")}
    out = []  # (class, name, addr, size, source)
    for a, r in sorted(funcs.items()):
        cls = r["classification"]
        size = num(r["size"])
        m = matches.get(a)
        if m is not None:
            if m["status"] == "complete":
                continue
            out.append(("placeholder", r["name"], a, size, m["source"]))
            continue
        if cls == "code":
            out.append(("unmatched", r["name"], a, size, ""))
        elif cls == "assembly_residual":
            out.append(("residual", r["name"], a, size, ""))
        elif include_padding:
            out.append(("padding", r["name"], a, size, ""))
    for r in rows("gaps.csv"):
        a = num(r["start"])
        if a < TEXT_END:
            out.append(("gap", f"gap_{a:08X}", a, num(r["size"]), ""))
    if include_data:
        for r in rows("data_matches.csv"):
            if r.get("progress") == "placeholder":
                out.append(("data-placeholder", r["name"], num(r["address"]),
                            num(r["size"]), r["source"]))
    out.sort(key=lambda x: x[2])
    return out


def summary(items):
    funcs = {num(r["address"]): r for r in rows("functions.csv")}
    matches = rows("matches.csv")
    credited = [r for r in matches if r["status"] == "complete"]
    cb = sum(num(r["size"]) for r in credited)
    total = sum(num(r["size"]) for r in funcs.values()
                if r["classification"] in ("code", "assembly_residual"))
    print(f"credited functions: {len(credited)} ({cb} bytes) in "
          f"{len({r['source'] for r in credited})} sources")
    print(f"code+residual spans in functions.csv: {total} bytes; credited "
          f"{100.0 * cb / total:.2f}%")
    c = collections.Counter()
    b = collections.Counter()
    for cls, _, _, size, _ in items:
        c[cls] += 1
        b[cls] += size
    for cls in sorted(c):
        print(f"  {cls:17s} {c[cls]:6d} spans {b[cls]:9d} bytes")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--csv", help="write the list as CSV here (default stdout)")
    ap.add_argument("--summary", action="store_true", help="print counts/bytes only")
    ap.add_argument("--all", action="store_true", help="also list padding spans")
    ap.add_argument("--data", action="store_true", help="also list placeholder data units")
    a = ap.parse_args()
    items = collect(a.all, a.data)
    if a.summary:
        summary(items)
        return
    f = open(a.csv, "w", newline="") if a.csv else sys.stdout
    w = csv.writer(f)
    w.writerow(["class", "name", "address", "size", "source"])
    for cls, name, addr, size, src in items:
        w.writerow([cls, name, f"0x{addr:08X}", f"0x{size:X}", src])
    if a.csv:
        f.close()
        summary(items)


if __name__ == "__main__":
    main()
