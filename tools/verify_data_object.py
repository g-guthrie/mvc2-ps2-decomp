#!/usr/bin/env python3
"""Verify source-owned initialized data against a private loaded image."""

from __future__ import annotations

import argparse
import csv
import struct
from dataclasses import dataclass
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.enums import ENUM_RELOC_TYPE_MIPS


BASE = 0x00100000


@dataclass(frozen=True)
class Unit:
    name: str
    address: int
    size: int
    section: str


def load_unit(path: Path, name: str) -> Unit:
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            if row["name"] == name:
                return Unit(name, int(row["address"], 0), int(row["size"], 0), row["section"])
    raise SystemExit(f"unknown data unit: {name}")


def load_symbols(path: Path) -> dict[str, int]:
    values = {}
    if not path.is_file():
        return values
    for line in path.read_text(encoding="utf-8").splitlines():
        fields = line.replace("=", " ").replace(";", " ").split()
        if len(fields) >= 2 and fields[1].startswith("0x"):
            values[fields[0]] = int(fields[1], 0)
    return values


def resolved_data(unit: Unit, object_path: Path, symbols: dict[str, int]) -> bytes:
    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        table = elf.get_section_by_name(".symtab")
        if table is None:
            raise SystemExit("object has no symbol table")
        entries = {entry.name: entry for entry in table.iter_symbols() if entry.name}
        symbol = entries.get(unit.name)
        if symbol is None or not isinstance(symbol["st_shndx"], int):
            raise SystemExit(f"missing data symbol: {unit.name}")
        section = elf.get_section(symbol["st_shndx"])
        if section.name != unit.section or symbol["st_value"] != 0:
            raise SystemExit(f"unexpected data placement in object: {unit.name}")
        body = bytearray(section.data())
        if len(body) != unit.size or symbol["st_size"] != unit.size:
            raise SystemExit(f"size mismatch for {unit.name}")
        relocation_sections = [
            item for item in elf.iter_sections()
            if item.header.sh_type in {"SHT_REL", "SHT_RELA"}
            and item.header.sh_info == symbol["st_shndx"]
        ]
        for reloc_section in relocation_sections:
            for relocation in reloc_section.iter_relocations():
                offset = relocation["r_offset"]
                if offset + 4 > len(body):
                    raise SystemExit(f"relocation outside {unit.name}")
                kind = {
                    value: name
                    for name, value in ENUM_RELOC_TYPE_MIPS.items()
                    if isinstance(value, int)
                }.get(relocation["r_info_type"])
                if kind != "R_MIPS_32":
                    raise SystemExit(f"unsupported data relocation {kind} in {unit.name}")
                target = table.get_symbol(relocation["r_info_sym"]).name
                if target not in symbols:
                    raise SystemExit(f"unmapped data relocation target: {target}")
                addend = relocation["r_addend"] if relocation.is_RELA() else struct.unpack_from("<I", body, offset)[0]
                struct.pack_into("<I", body, offset, (symbols[target] + addend) & 0xFFFFFFFF)
    return bytes(body)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("object", type=Path)
    parser.add_argument("target", type=Path)
    parser.add_argument("--name", required=True)
    parser.add_argument("--units", type=Path, default=Path("config/data_units.csv"))
    parser.add_argument("--symbols", type=Path, default=Path("config/data_symbol_addrs.txt"))
    args = parser.parse_args()
    unit = load_unit(args.units, args.name)
    body = resolved_data(unit, args.object, load_symbols(args.symbols))
    target = args.target.read_bytes()[unit.address - BASE:unit.address - BASE + unit.size]
    if body != target:
        raise SystemExit(f"private target mismatch: {unit.name}")
    print(f"exact compiled data: {unit.name} @ 0x{unit.address:08X} ({unit.size} bytes)")


if __name__ == "__main__":
    main()
