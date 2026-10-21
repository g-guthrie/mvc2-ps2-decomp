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

if __package__:
    from . import verify_object
else:
    import verify_object


BASE = 0x00100000


@dataclass(frozen=True)
class Unit:
    name: str
    address: int
    size: int
    section: str
    source: str = ""
    kind: str = ""


def load_unit(path: Path, name: str) -> Unit:
    with path.open(newline="", encoding="utf-8") as stream:
        for row in csv.DictReader(stream):
            if row["name"] == name:
                return Unit(
                    name,
                    int(row["address"], 0),
                    int(row["size"], 0),
                    row["section"],
                    row.get("source", ""),
                    row.get("kind", ""),
                )
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


def _credited_owner_rows(matches_path: Path, source: str) -> list[dict]:
    source_path = Path(source)
    if (source_path.is_absolute() or ".." in source_path.parts
            or source_path.suffix != ".c" or not source_path.parts
            or source_path.parts[0] != "src"):
        raise SystemExit(f"invalid compiler switch table owner source: {source}")
    with matches_path.open(newline="", encoding="utf-8") as stream:
        rows = list(csv.DictReader(stream))
    owner_rows = [row for row in rows if row.get("source") == source]
    if not owner_rows:
        raise SystemExit(f"compiler switch table owner is not registered: {source}")
    if any(row.get("status") not in {"matching", "complete"} for row in owner_rows):
        raise SystemExit(f"compiler switch table owner is not fully credited: {source}")
    return owner_rows


def _readonly_anchor(
    readonly_sections_path: Path, source: str, section: str
) -> dict | None:
    rows = verify_object.load_readonly_sections(readonly_sections_path)
    owner_rows = [row for row in rows if row.get("source") == source]
    if not owner_rows:
        return None
    anchors = [row for row in owner_rows if row.get("section") == section]
    if len(anchors) != 1:
        raise SystemExit(
            f"compiler switch table owner section mismatch: {source} {section}"
        )
    anchor = anchors[0]
    try:
        address = int(anchor["address"], 0)
        size = int(anchor["size"], 0)
    except (KeyError, ValueError) as error:
        raise SystemExit(f"invalid readonly owner anchor: {source} {section}") from error
    if address < BASE or size <= 0:
        raise SystemExit(f"invalid readonly owner bounds: {source} {section}")
    return {"source": source, "section": section, "address": address, "size": size}


def embedded_switch_table_data(
    unit: Unit,
    object_path: Path,
    target_path: Path,
    *,
    matches_path: Path,
    code_symbols_path: Path,
    readonly_sections_path: Path,
) -> bytes | None:
    """Verify and extract a registered switch table embedded in its C owner's rodata.

    None means the owner has no explicit readonly-section anchor, so the caller
    must retain the existing standalone-symbol path. Embedded extraction is
    limited to compiler-generated switch tables and uses verify_object's whole
    function/readonly-section relocation proof.
    """
    if unit.kind != "compiler_switch_table":
        return None
    if not unit.source:
        raise SystemExit(f"compiler switch table has no C owner: {unit.name}")
    if unit.size <= 0 or unit.address < BASE:
        raise SystemExit(f"invalid compiler switch table bounds: {unit.name}")
    if unit.address % 4 or unit.size % 4:
        raise SystemExit(f"compiler switch table is not word-aligned: {unit.name}")
    _credited_owner_rows(matches_path, unit.source)
    anchor = _readonly_anchor(readonly_sections_path, unit.source, unit.section)
    if anchor is None:
        return None

    offset = unit.address - anchor["address"]
    if offset < 0 or offset + unit.size > anchor["size"]:
        raise SystemExit(f"compiler switch table outside readonly owner: {unit.name}")

    resolved_sections: dict[tuple[str, str], tuple[int, bytes, tuple[int, ...]]] = {}
    verify_object.verify(
        object_path,
        target_path,
        matches_path,
        code_symbols_path,
        source=unit.source,
        readonly_sections_path=readonly_sections_path,
        resolved_readonly_sections=resolved_sections,
    )
    owner = resolved_sections.get((unit.source, unit.section))
    if owner is None:
        raise SystemExit(f"verified readonly owner section missing: {unit.source} {unit.section}")
    owner_address, owner_body, owner_relocations = owner
    if owner_address != anchor["address"] or len(owner_body) != anchor["size"]:
        raise SystemExit(f"verified readonly owner extent mismatch: {unit.source} {unit.section}")

    required_relocations = list(range(offset, offset + unit.size, 4))
    table_relocations = sorted(
        position for position in owner_relocations
        if offset <= position < offset + unit.size
    )
    if table_relocations != required_relocations:
        raise SystemExit(f"compiler switch table lacks complete word relocations: {unit.name}")

    body = owner_body[offset:offset + unit.size]
    target = target_path.read_bytes()
    target_offset = unit.address - BASE
    if target_offset < 0 or target_offset + unit.size > len(target):
        raise SystemExit(f"compiler switch table outside loaded image: {unit.name}")
    expected = target[target_offset:target_offset + unit.size]
    if body != expected:
        raise SystemExit(f"private target mismatch: {unit.name}")
    return body


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("object", type=Path)
    parser.add_argument("target", type=Path)
    parser.add_argument("--name", required=True)
    parser.add_argument("--units", type=Path, default=Path("config/data_units.csv"))
    parser.add_argument("--symbols", type=Path, default=Path("config/data_symbol_addrs.txt"))
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    parser.add_argument("--code-symbols", type=Path, default=Path("config/symbol_addrs.txt"))
    parser.add_argument(
        "--readonly-sections",
        type=Path,
        default=Path("config/readonly_sections.csv"),
    )
    args = parser.parse_args()
    unit = load_unit(args.units, args.name)
    body = embedded_switch_table_data(
        unit,
        args.object,
        args.target,
        matches_path=args.matches,
        code_symbols_path=args.code_symbols,
        readonly_sections_path=args.readonly_sections,
    )
    embedded = body is not None
    if body is None:
        body = resolved_data(unit, args.object, load_symbols(args.symbols))
    target = args.target.read_bytes()[unit.address - BASE:unit.address - BASE + unit.size]
    if body != target:
        raise SystemExit(f"private target mismatch: {unit.name}")
    if embedded:
        print(
            f"exact embedded compiler switch table: {unit.name} @ "
            f"0x{unit.address:08X} ({unit.size} bytes)"
        )
    else:
        print(f"exact compiled data: {unit.name} @ 0x{unit.address:08X} ({unit.size} bytes)")


if __name__ == "__main__":
    main()
