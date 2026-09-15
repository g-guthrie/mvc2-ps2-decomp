#!/usr/bin/env python3
"""Fail if code/data catalogs would publish lying decomp.dev stats."""

import csv
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
    print(
        f"catalog ok: linked code {complete_code}/{TEXT_SIZE} "
        f"({complete_code * 100.0 / TEXT_SIZE:.4f}%), "
        f"linked data {complete_data}/{DATA_SIZE} "
        f"({complete_data * 100.0 / DATA_SIZE:.4f}%), "
        f"matched code {matched_code}, matched data {matched_data}"
    )


if __name__ == "__main__":
    main()
