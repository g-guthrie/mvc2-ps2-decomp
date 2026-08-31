#!/usr/bin/env python3
"""Verify that every matching C function is linked at its declared retail address and size."""

import argparse
import csv
from pathlib import Path

from elftools.elf.elffile import ELFFile


def load_matches(path: Path) -> list[dict[str, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        return [
            row for row in csv.DictReader(stream) if row["status"] in {"matching", "complete"}
        ]


def verify_placements(matches: list[dict[str, str]], symbols: dict) -> list[str]:
    messages = []
    for match in matches:
        name = match["name"]
        expected_address = int(match["address"], 0)
        expected_size = int(match["size"], 0)
        symbol = symbols.get(name)
        if symbol is None:
            raise SystemExit(f"linked function missing: {name}")
        address = symbol["st_value"]
        size = symbol["st_size"]
        if address != expected_address or size != expected_size:
            raise SystemExit(
                f"linked placement mismatch for {name}: "
                f"0x{address:x}/0x{size:x} != 0x{expected_address:x}/0x{expected_size:x}"
            )
        messages.append(f"placed: {name} @ 0x{address:08x} (0x{size:x})")
    return messages


def verify(elf_path: Path, matches_path: Path) -> int:
    matches = load_matches(matches_path)
    with elf_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbol_table = elf.get_section_by_name(".symtab")
        if symbol_table is None:
            raise SystemExit("linked ELF has no symbol table")
        symbols = {symbol.name: symbol for symbol in symbol_table.iter_symbols() if symbol.name}
        messages = verify_placements(matches, symbols)
    for message in messages:
        print(message)
    return len(messages)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("elf", type=Path)
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    args = parser.parse_args()
    verify(args.elf, args.matches)


if __name__ == "__main__":
    main()
