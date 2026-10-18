#!/usr/bin/env python3
"""Fail if code/data catalogs would publish lying decomp.dev stats."""

import csv
import re
from pathlib import Path

from tools.objdiff_report import load_data_matches, load_functions, load_matches
from tools.progress_catalog import (
    DATA_SIZE,
    TEXT_SIZE,
    code_progress,
    data_progress,
    validate_code_catalog,
    validate_data_catalog,
)


# These small COP0 primitives fall under DECOMP.md's required CPU-operation
# exception. Other instruction-stream lifts must remain placeholders.
CPU_ASSEMBLY_PRIMITIVES = {
    ("src/s0h.c", "func_0010CA20"),
    ("src/k5h.c", "func_0010CA68"),
    ("src/k2s.c", "func_001048B0"),
}


def validate_source_credit(matches, root=Path(".")):
    """Reject credited instruction streams using the repository's FN macro."""
    by_source = {}
    for name, row in matches.items():
        by_source.setdefault(row["source"], set()).add(name)
    for source, credited in by_source.items():
        text = (root / source).read_text()
        if not re.search(r"#define\s+FN\([^\n]*__asm__", text):
            continue
        lifted = set(re.findall(r"^\s*FN\(\s*(func_[0-9A-Fa-f]{8})\s*,", text, re.MULTILINE))
        for name in sorted(credited & lifted):
            if (source, name) not in CPU_ASSEMBLY_PRIMITIVES:
                raise SystemExit(f"assembly instruction stream credited as C: {name} ({source})")


def main() -> None:
    root = Path(".")
    functions = load_functions(root / "config/functions.csv")
    matches = load_matches(root / "config/matches.csv")
    data_matches = load_data_matches(
        root / "config/data_units.csv", root / "config/data_matches.csv"
    )
    units = {}
    with (root / "config/data_units.csv").open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            units[row["name"]] = (int(row["address"], 0), int(row["size"], 0))
    validate_code_catalog(functions, matches)
    validate_data_catalog(units, data_matches)
    matched_code, complete_code = code_progress(matches)
    matched_data, complete_data = data_progress(data_matches)
    for source in {row["source"] for row in matches.values()} | {
        row["source"] for row in data_matches.values()
    }:
        if not Path(source).is_file():
            raise SystemExit(f"catalog source missing: {source}")
    validate_source_credit(matches)
    print(
        f"catalog ok: linked code {complete_code}/{TEXT_SIZE} "
        f"({complete_code * 100.0 / TEXT_SIZE:.4f}%), "
        f"linked data {complete_data}/{DATA_SIZE} "
        f"({complete_data * 100.0 / DATA_SIZE:.4f}%), "
        f"matched code {matched_code}, matched data {matched_data}"
    )


if __name__ == "__main__":
    main()
