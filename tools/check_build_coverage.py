#!/usr/bin/env python3
"""Cross-check config/matches.csv against tools/compile_matching.sh.

Every source credited in the ledger must be compiled and verified by the build
script, and every source the build script verifies must be credited. A source
that is credited but never compiled means functions counted as matched without
anything checking them; a source compiled but not credited makes the build fail
with "no matching functions selected".
"""
import csv
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def wired_sources(script: str) -> set[str]:
    sources = set(re.findall(r'--source\s+"?(src/[\w./-]+\.c)"?', script))
    for units in re.findall(r'^for unit in ([^;]+); do', script, re.M):
        sources.update(f"src/{unit}.c" for unit in units.split())
    # loops that verify "src/$unit.c" are covered by the expansion above
    return {s for s in sources if "$" not in s}


def credited_sources(path: Path) -> set[str]:
    with path.open(newline="") as handle:
        return {row["source"].strip() for row in csv.DictReader(handle) if row.get("source")}


def main() -> int:
    script = (ROOT / "tools/compile_matching.sh").read_text()
    wired = wired_sources(script)
    credited = credited_sources(ROOT / "config/matches.csv")
    uncompiled = sorted(credited - wired)
    uncredited = sorted(wired - credited)
    for source in uncompiled:
        print(f"credited but never compiled: {source}")
    for source in uncredited:
        print(f"compiled but not credited: {source}")
    if uncompiled or uncredited:
        print(f"FAIL: {len(uncompiled)} uncompiled, {len(uncredited)} uncredited")
        return 1
    print(f"ok: {len(credited)} sources both credited and verified by the build")
    return 0


if __name__ == "__main__":
    sys.exit(main())
