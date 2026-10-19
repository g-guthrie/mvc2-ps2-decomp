#!/usr/bin/env python3
"""Cross-check the ledger, the build script, and the sources.

Three invariants:

1. Every source credited in config/matches.csv is compiled and verified by
   tools/compile_matching.sh. A credited-but-uncompiled source means functions
   counted as matched with nothing checking them.
2. Every source the build script verifies is credited. Otherwise the build
   fails with "no matching functions selected".
3. Every non-static func_ body in src/ is registered. An unregistered body is
   unverified code that reads as if it matched; it is usually a leftover from
   an attempt whose ledger row was removed but whose source was not. Recipe-2
   helper leaves are exempt because they are declared static.
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


def orphan_bodies() -> list[tuple[str, str]]:
    credited = set()
    with (ROOT / "config/matches.csv").open(newline="") as handle:
        credited = {row["name"].strip() for row in csv.DictReader(handle) if row.get("name")}
    orphans = []
    for source in sorted((ROOT / "src").rglob("*.c")):
        text = source.read_text(errors="ignore")
        for match in re.finditer(
            r"^(?!static\b)[A-Za-z_][\w *]*\b(func_[0-9A-Fa-f]{8})\s*\([^;]*\)\s*\{",
            text,
            re.M,
        ):
            name = match.group(1)
            if name in credited:
                continue
            if re.search(r"\bstatic\b[^\n]*\b" + name + r"\b", text):
                continue
            orphans.append((str(source.relative_to(ROOT)), name))
    return orphans


def detached_source_commands(script: str) -> list[str]:
    """Catch appended source lines that lost their compiler command prefix."""
    lines = script.splitlines()
    return [
        line.strip()
        for index, line in enumerate(lines)
        if re.match(r"\s*src/[\w./-]+\.c\s+-c\b", line)
        and (index == 0 or not lines[index - 1].rstrip().endswith("\\"))
    ]


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
    detached = detached_source_commands(script)
    for command in detached:
        print(f"source command missing compiler prefix: {command}")
    orphans = orphan_bodies()
    for source, name in orphans:
        print(f"unregistered body: {name} in {source}")
    if uncompiled or uncredited or orphans or detached:
        print(
            f"FAIL: {len(uncompiled)} uncompiled, {len(uncredited)} uncredited, "
            f"{len(orphans)} unregistered bodies, {len(detached)} detached compile commands"
        )
        return 1
    print(
        f"ok: {len(credited)} sources both credited and verified by the build, "
        "no unregistered bodies"
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
