#!/usr/bin/env python3
"""Validate source-only provenance for symbolic interior code labels.

This deliberately validates names and addresses, never target table bytes.  A
table initializer may name a code-start function or a registered interior
label; data symbols and unknown pointer names are rejected.
"""

from __future__ import annotations

import argparse
import csv
import re
from pathlib import Path

LABEL = re.compile(r"^lbl_([0-9A-Fa-f]{8})$")
FUNCTION = re.compile(r"^func_([0-9A-Fa-f]{8})$")
IDENTIFIER = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\b")


def parse_int(value: str) -> int:
    return int(value, 0)


def load_functions(path: Path) -> dict[int, dict[str, object]]:
    result: dict[int, dict[str, object]] = {}
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            classification = row.get("classification", row.get("kind"))
            if classification != "code":
                continue
            start, size = parse_int(row["address"]), parse_int(row["size"])
            result[start] = {"name": row["name"], "start": start, "end": start + size}
    return result


def load_labels(path: Path) -> dict[str, dict[str, object]]:
    result: dict[str, dict[str, object]] = {}
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            name = row["name"]
            if name in result:
                raise ValueError(f"duplicate data label: {name}")
            result[name] = {key: (parse_int(value) if key in {
                "address", "containing_start", "containing_end", "offset", "occurrences"
            } else value) for key, value in row.items()}
    return result


def validate_registry(functions: dict[int, dict[str, object]], labels: dict[str, dict[str, object]]) -> None:
    for name, entry in labels.items():
        match = LABEL.fullmatch(name)
        if not match:
            raise ValueError(f"label has non-canonical name: {name}")
        if int(match.group(1), 16) != entry["address"]:
            raise ValueError(f"label/address mismatch: {name}")
        if entry["kind"] != "code_interior":
            raise ValueError(f"label is not code_interior: {name}")
        start, end = entry["containing_start"], entry["containing_end"]
        if not start < entry["address"] < end:
            raise ValueError(f"label is not strictly inside its owner: {name}")
        owner = functions.get(start)
        if owner is None or owner["name"] != entry["containing_function"] or owner["end"] != end:
            raise ValueError(f"label owner is not an exact code range: {name}")
        if entry["address"] - start != entry["offset"]:
            raise ValueError(f"label offset mismatch: {name}")


def initializer_identifiers(source: Path) -> list[str]:
    text = source.read_text(encoding="utf-8")
    match = re.search(r"=\s*\{(.*?)\};", text, flags=re.DOTALL)
    if match is None:
        raise ValueError(f"no initializer found in {source}")
    return IDENTIFIER.findall(match.group(1))


def validate_table_source(source: Path, functions: dict[int, dict[str, object]], labels: dict[str, dict[str, object]]) -> None:
    seen_labels: dict[str, int] = {}
    for name in initializer_identifiers(source):
        label = LABEL.fullmatch(name)
        if label:
            if name not in labels:
                raise ValueError(f"unknown interior pointer in {source}: {name}")
            seen_labels[name] = seen_labels.get(name, 0) + 1
            continue
        function = FUNCTION.fullmatch(name)
        if function:
            address = int(function.group(1), 16)
            if address not in functions:
                raise ValueError(f"unknown/non-start function pointer in {source}: {name}")
            continue
        raise ValueError(f"data or unknown pointer in {source}: {name}")
    for name, entry in labels.items():
        actual = seen_labels.get(name, 0)
        if actual != entry["occurrences"]:
            raise ValueError(f"label occurrence mismatch for {name}: {actual} != {entry['occurrences']}")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--functions", type=Path, required=True)
    parser.add_argument("--labels", type=Path, required=True)
    parser.add_argument("--table", type=Path, required=True)
    args = parser.parse_args()
    functions = load_functions(args.functions)
    labels = load_labels(args.labels)
    validate_registry(functions, labels)
    validate_table_source(args.table, functions, labels)
    print(f"exact provenance: {len(labels)} interior code labels")


if __name__ == "__main__":
    main()
