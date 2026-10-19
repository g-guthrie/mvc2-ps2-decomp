#!/usr/bin/env python3
"""Cross-check the ledger, the build script, and the sources.

Four invariants:

1. Every source credited in config/matches.csv is compiled and verified by
   tools/compile_matching.sh. A credited-but-uncompiled source means functions
   counted as matched with nothing checking them.
2. Every source the build script verifies is credited. Otherwise the build
   fails with "no matching functions selected".
3. Every non-static func_ body in src/ is registered. An unregistered body is
   unverified code that reads as if it matched; it is usually a leftover from
   an attempt whose ledger row was removed but whose source was not. Recipe-2
   helper leaves are exempt because they are declared static.
4. The data build runs after code compilation so table verifiers can resolve
   every native function owner from a freshly compiled object.
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


def malformed_compile_continuations(script: str) -> list[str]:
    """Catch escaped spaces in compiler argv before flags or other arguments."""
    return [
        line.strip()
        for line in script.splitlines()
        if not line.lstrip().startswith("#")
        and "-c" in line
        and re.search(r"\\[ \t]+\S", line)
    ]


def detached_object_verification_commands(script: str) -> list[str]:
    """Catch object/ROM verification arguments that lost the verifier prefix."""
    lines = script.splitlines()
    object_head = re.compile(
        r'^\s*(?:"\$BUILD/[\w./-]+\.o"|\$BUILD/[\w./-]+\.o)'
        r'\s+private/[\w./-]+\.(?:rom|elf)(?:\s|\\|$)'
    )
    return [
        line.strip()
        for index, line in enumerate(lines)
        if object_head.match(line)
        and (index == 0 or not lines[index - 1].rstrip().endswith("\\"))
    ]


def premature_data_build_commands(script: str) -> list[str]:
    """Require data tables to compile after all code-owner translation units."""
    lines = script.splitlines()
    calls = [
        index
        for index, line in enumerate(lines)
        if re.search(r"\btools/compile_matching_data\.sh\b", line)
    ]
    if len(calls) != 1:
        return [f"expected one data build call, found {len(calls)}"]

    later_compiles = []
    for line in lines[calls[0] + 1 :]:
        if re.search(r"\bsrc/[\w./-]+\.c\s+-c\b", line) or re.match(
            r"\s*for unit in ", line
        ):
            later_compiles.append(line.strip())
    return later_compiles


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
    malformed_continuations = malformed_compile_continuations(script)
    for command in malformed_continuations:
        print(f"shell continuation has text after its backslash: {command}")
    detached_verification = detached_object_verification_commands(script)
    for command in detached_verification:
        print(f"object verification command missing verifier prefix: {command}")
    premature_data_build = premature_data_build_commands(script)
    for command in premature_data_build:
        print(f"data build occurs before code compilation is complete: {command}")
    orphans = orphan_bodies()
    for source, name in orphans:
        print(f"unregistered body: {name} in {source}")
    if (
        uncompiled
        or uncredited
        or orphans
        or detached
        or malformed_continuations
        or detached_verification
        or premature_data_build
    ):
        print(
            f"FAIL: {len(uncompiled)} uncompiled, {len(uncredited)} uncredited, "
            f"{len(orphans)} unregistered bodies, {len(detached)} detached compile commands, "
            f"{len(malformed_continuations)} malformed shell continuations, "
            f"{len(detached_verification)} detached object verification commands, "
            f"{len(premature_data_build)} code compiles after the data build"
        )
        return 1
    print(
        f"ok: {len(credited)} sources both credited and verified by the build, "
        "no unregistered bodies"
    )
    return 0


if __name__ == "__main__":
    sys.exit(main())
