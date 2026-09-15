#!/usr/bin/env python3
"""Validate the CSV layout inventory in config/ for internal consistency.

This tool never reads the retail image.  It only checks that the committed
bookkeeping agrees with itself: ranges are well formed, functions and gaps tile
the conservative text span exactly once, every match names a real inventory
entry and a source file that exists, and every data label sits inside the code
range it claims.
"""

from __future__ import annotations

import argparse
import csv
from pathlib import Path

TEXT_START = 0x00100000
TEXT_END = 0x00424200
DATA_START = 0x00424200
DATA_END = 0x004C2580

CODE_ALIGNMENT = 4
MAX_REPORTED = 50


def parse_int(value: str) -> int:
    return int(value, 0)


def read_rows(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        return list(csv.DictReader(stream))


class Report:
    """Collects human-readable problems without aborting the first failure."""

    def __init__(self) -> None:
        self.problems: list[str] = []
        self.notes: list[str] = []

    def fail(self, message: str) -> None:
        self.problems.append(message)

    def note(self, message: str) -> None:
        self.notes.append(message)

    @property
    def ok(self) -> bool:
        return not self.problems


def check_row_arithmetic(report: Report, label: str, rows: list[dict[str, str]]) -> None:
    for index, row in enumerate(rows, start=2):
        key = "address" if "address" in row else "start"
        if "size" not in row or key not in row:
            continue
        start = parse_int(row[key])
        size = parse_int(row["size"])
        if size < 0:
            report.fail(f"{label}:{index}: negative size {row['size']}")
        elif size == 0:
            # A matching-C head split can consume its whole original range,
            # leaving an empty residual placeholder. Empty rows are inert for
            # tiling but still occupy a slot in the reported unit denominator.
            if row.get("classification") == "assembly_residual":
                report.note(
                    f"{label}:{index}: empty {row.get('name', '?')} "
                    f"at {start:#010x} (head-split consumed full range)"
                )
            else:
                report.fail(f"{label}:{index}: non-positive size {row['size']}")
        if "end" in row and row["end"]:
            end = parse_int(row["end"])
            if start + size != end:
                report.fail(
                    f"{label}:{index}: address+size != end "
                    f"({start:#010x}+{size:#x} != {end:#010x})"
                )


def check_functions(report: Report, functions: list[dict[str, str]]) -> None:
    names: set[str] = set()
    previous_start = None
    previous_end = None
    previous_name = None
    for index, row in enumerate(functions, start=2):
        name = row["name"]
        if name in names:
            report.fail(f"functions.csv:{index}: duplicate name {name}")
        names.add(name)
        start = parse_int(row["address"])
        end = start + parse_int(row["size"])
        if start % CODE_ALIGNMENT:
            report.fail(f"functions.csv:{index}: {name} is not 4-byte aligned ({start:#010x})")
        if parse_int(row["size"]) % CODE_ALIGNMENT:
            report.fail(f"functions.csv:{index}: {name} size is not a multiple of 4")
        if not TEXT_START <= start < TEXT_END or end > TEXT_END:
            report.fail(
                f"functions.csv:{index}: {name} {start:#010x}..{end:#010x} "
                f"is outside the text span {TEXT_START:#010x}..{TEXT_END:#010x}"
            )
        if previous_start is not None and start <= previous_start:
            report.fail(
                f"functions.csv:{index}: {name} at {start:#010x} is not strictly after "
                f"{previous_name} at {previous_start:#010x}"
            )
        elif previous_end is not None and start < previous_end:
            report.fail(
                f"functions.csv:{index}: {name} at {start:#010x} overlaps "
                f"{previous_name} ending {previous_end:#010x}"
            )
        previous_start = start
        previous_end = end
        previous_name = name


def check_gaps(report: Report, gaps: list[dict[str, str]]) -> None:
    previous_end = None
    for index, row in enumerate(gaps, start=2):
        start, end = parse_int(row["start"]), parse_int(row["end"])
        if end <= start:
            report.fail(f"gaps.csv:{index}: empty or reversed range {start:#010x}..{end:#010x}")
        if not TEXT_START <= start < TEXT_END or end > TEXT_END:
            report.fail(
                f"gaps.csv:{index}: {start:#010x}..{end:#010x} is outside the text span"
            )
        if previous_end is not None and start < previous_end:
            report.fail(
                f"gaps.csv:{index}: {start:#010x} overlaps the previous gap "
                f"ending {previous_end:#010x}"
            )
        previous_end = end


def check_tiling(report: Report, functions: list[dict[str, str]], gaps: list[dict[str, str]]) -> None:
    """Functions and gaps must cover the text span exactly once."""
    spans: list[tuple[int, int, str]] = []
    for row in functions:
        start = parse_int(row["address"])
        spans.append((start, start + parse_int(row["size"]), f"function {row['name']}"))
    for row in gaps:
        spans.append((parse_int(row["start"]), parse_int(row["end"]), "gap"))
    spans.sort()

    cursor = TEXT_START
    previous = None
    for start, end, label in spans:
        if start < cursor:
            report.fail(
                f"double coverage: {label} {start:#010x}..{end:#010x} overlaps "
                f"{previous} which ends at {cursor:#010x}"
            )
        elif start > cursor:
            report.fail(
                f"unexplained hole {cursor:#010x}..{start:#010x} "
                f"({start - cursor:#x} bytes) before {label}"
            )
        cursor = max(cursor, end)
        previous = label
    if cursor != TEXT_END:
        report.fail(
            f"text span not fully tiled: coverage ends at {cursor:#010x}, "
            f"expected {TEXT_END:#010x} ({TEXT_END - cursor:#x} bytes uncovered)"
        )


def check_matches(
    report: Report,
    label: str,
    matches: list[dict[str, str]],
    inventory: list[dict[str, str]],
    root: Path,
) -> None:
    by_name = {row["name"]: row for row in inventory}
    seen: set[str] = set()
    for index, row in enumerate(matches, start=2):
        name = row["name"]
        if name in seen:
            report.fail(f"{label}:{index}: duplicate match {name}")
        seen.add(name)
        entry = by_name.get(name)
        if entry is None:
            report.fail(f"{label}:{index}: {name} has no inventory entry")
            continue
        if parse_int(row["address"]) != parse_int(entry["address"]):
            report.fail(
                f"{label}:{index}: {name} address {row['address']} "
                f"!= inventory {entry['address']}"
            )
        if parse_int(row["size"]) != parse_int(entry["size"]):
            report.fail(
                f"{label}:{index}: {name} size {row['size']} != inventory {entry['size']}"
            )
        source = row["source"]
        if not (root / source).is_file():
            report.fail(f"{label}:{index}: {name} names a missing source file {source}")
        if "source" in entry and entry["source"] and entry["source"] != source:
            report.fail(
                f"{label}:{index}: {name} source {source} != inventory {entry['source']}"
            )


def check_data_units(report: Report, units: list[dict[str, str]], root: Path) -> None:
    spans: list[tuple[int, int, str]] = []
    for index, row in enumerate(units, start=2):
        start = parse_int(row["address"])
        end = start + parse_int(row["size"])
        if not DATA_START <= start < DATA_END or end > DATA_END:
            report.fail(
                f"data_units.csv:{index}: {row['name']} {start:#010x}..{end:#010x} "
                f"is outside the initialized-data span "
                f"{DATA_START:#010x}..{DATA_END:#010x}"
            )
        source = row.get("source")
        if source and not (root / source).is_file():
            report.fail(f"data_units.csv:{index}: {row['name']} missing source file {source}")
        spans.append((start, end, row["name"]))
    spans.sort()
    for (start, end, name), (next_start, _, next_name) in zip(spans, spans[1:]):
        if next_start < end:
            report.fail(
                f"data_units.csv: {name} {start:#010x}..{end:#010x} overlaps {next_name}"
            )


def check_zero_regions(
    report: Report, regions: list[dict[str, str]], units: list[dict[str, str]]
) -> None:
    by_name = {row["name"]: row for row in units}
    for index, row in enumerate(regions, start=2):
        start = parse_int(row["address"])
        end = start + parse_int(row["size"])
        if not DATA_START <= start < DATA_END or end > DATA_END:
            report.fail(
                f"zero_initialized_regions.csv:{index}: {row['name']} "
                f"{start:#010x}..{end:#010x} is outside the initialized-data span"
            )
        entry = by_name.get(row["name"])
        if entry is None:
            continue
        if parse_int(entry["address"]) != start or parse_int(entry["size"]) != end - start:
            report.fail(
                f"zero_initialized_regions.csv:{index}: {row['name']} "
                f"disagrees with its data_units.csv entry"
            )


def check_data_labels(
    report: Report, labels: list[dict[str, str]], functions: list[dict[str, str]]
) -> None:
    by_start = {parse_int(row["address"]): row for row in functions}
    for index, row in enumerate(labels, start=2):
        address = parse_int(row["address"])
        start = parse_int(row["containing_start"])
        end = parse_int(row["containing_end"])
        offset = parse_int(row["offset"])
        if not start <= address < end:
            report.fail(
                f"data_labels.csv:{index}: {row['name']} {address:#010x} is not inside "
                f"{start:#010x}..{end:#010x}"
            )
        if address - start != offset:
            report.fail(
                f"data_labels.csv:{index}: {row['name']} offset {offset:#x} "
                f"!= address-containing_start {address - start:#x}"
            )
        owner = by_start.get(start)
        if owner is None:
            report.fail(
                f"data_labels.csv:{index}: {row['name']} containing_start {start:#010x} "
                f"is not a functions.csv entry"
            )
            continue
        if owner["name"] != row["containing_function"]:
            report.fail(
                f"data_labels.csv:{index}: {row['name']} containing_function "
                f"{row['containing_function']} != {owner['name']}"
            )
        if parse_int(owner["address"]) + parse_int(owner["size"]) != end:
            report.fail(
                f"data_labels.csv:{index}: {row['name']} containing_end {end:#010x} "
                f"disagrees with functions.csv"
            )


def validate(config: Path, root: Path) -> Report:
    report = Report()
    functions = read_rows(config / "functions.csv")
    gaps = read_rows(config / "gaps.csv")
    matches = read_rows(config / "matches.csv")
    data_units = read_rows(config / "data_units.csv")
    data_matches = read_rows(config / "data_matches.csv")
    data_labels = read_rows(config / "data_labels.csv")
    zero_regions = read_rows(config / "zero_initialized_regions.csv")

    check_row_arithmetic(report, "functions.csv", functions)
    check_row_arithmetic(report, "gaps.csv", gaps)
    check_functions(report, functions)
    check_gaps(report, gaps)
    check_tiling(report, functions, gaps)
    check_matches(report, "matches.csv", matches, functions, root)
    check_data_units(report, data_units, root)
    check_matches(report, "data_matches.csv", data_matches, data_units, root)
    check_zero_regions(report, zero_regions, data_units)
    check_data_labels(report, data_labels, functions)

    report.note(f"{len(functions)} functions, {len(gaps)} text gaps")
    report.note(f"{len(matches)} matched functions, {len(data_matches)} matched data units")
    report.note(f"{len(data_units)} data units, {len(data_labels)} interior code labels")
    return report


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--config", type=Path, default=Path("config"))
    parser.add_argument("--root", type=Path, default=Path("."))
    args = parser.parse_args()
    report = validate(args.config, args.root)
    if not report.ok:
        print(f"config inventory FAILED: {len(report.problems)} problem(s)")
        for problem in report.problems[:MAX_REPORTED]:
            print(f"  {problem}")
        if len(report.problems) > MAX_REPORTED:
            print(f"  ... {len(report.problems) - MAX_REPORTED} more")
        return 1
    print("config inventory consistent")
    for note in report.notes:
        print(f"  {note}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
