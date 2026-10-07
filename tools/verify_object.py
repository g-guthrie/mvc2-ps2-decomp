#!/usr/bin/env python3
"""Resolve common MIPS relocations and compare matched functions with retail."""

import argparse
import csv
import re
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile

BASE_ADDRESS = 0x00100000
R_MIPS_32 = 2
R_MIPS_26 = 4
R_MIPS_HI16 = 5
R_MIPS_LO16 = 6
R_MIPS_GPREL16 = 7


def load_addresses(path: Path) -> dict[str, int]:
    result = {}
    pattern = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
    for line in path.read_text(encoding="utf-8").splitlines():
        match = pattern.match(line.strip())
        if match:
            result[match.group(1)] = int(match.group(2), 0)
    return result


def load_matches(path: Path, source: str | None = None) -> list[dict]:
    with path.open(newline="", encoding="utf-8") as stream:
        return [
            row
            for row in csv.DictReader(stream)
            if row["status"] in {"matching", "complete", "placeholder"}
            and (source is None or row["source"] == source)
        ]


def patch_relocation(word: int, relocation_type: int, value: int, gp: int) -> int:
    if relocation_type == R_MIPS_32:
        return value & 0xFFFFFFFF
    if relocation_type == R_MIPS_26:
        return (word & 0xFC000000) | ((value >> 2) & 0x03FFFFFF)
    if relocation_type == R_MIPS_HI16:
        return (word & 0xFFFF0000) | (((value + 0x8000) >> 16) & 0xFFFF)
    if relocation_type == R_MIPS_LO16:
        return (word & 0xFFFF0000) | (value & 0xFFFF)
    if relocation_type == R_MIPS_GPREL16:
        displacement = value - gp
        if not -0x8000 <= displacement <= 0x7FFF:
            raise SystemExit(f"GP-relative displacement out of range: {displacement}")
        return (word & 0xFFFF0000) | (displacement & 0xFFFF)
    raise SystemExit(f"unsupported MIPS relocation type {relocation_type}")


def relocate_bytes(body: bytes, relocations: list[tuple], gp: int) -> bytes:
    """Resolve REL instruction addends, pairing HI16 with its following LO16."""
    compiled = bytearray(body)
    pending_high = {}
    for offset, kind, value, name, explicit_addend in relocations:
        if offset < 0 or offset + 4 > len(compiled):
            raise SystemExit(f"relocation outside function: {name} at {offset}")
        word = struct.unpack_from("<I", compiled, offset)[0]
        if explicit_addend is not None:
            addend = explicit_addend
        elif kind == R_MIPS_HI16:
            pending_high.setdefault(name, []).append((offset, word, value))
            continue
        elif kind in {R_MIPS_LO16, R_MIPS_GPREL16}:
            low = word & 0xFFFF
            addend = low - 0x10000 if low & 0x8000 else low
            if kind == R_MIPS_LO16:
                for high_offset, high_word, high_value in pending_high.pop(name, []):
                    full_addend = ((high_word & 0xFFFF) << 16) + addend
                    patched = patch_relocation(
                        high_word, R_MIPS_HI16, high_value + full_addend, gp
                    )
                    struct.pack_into("<I", compiled, high_offset, patched)
        elif kind == R_MIPS_26:
            addend = (word & 0x03FFFFFF) << 2
        elif kind == R_MIPS_32:
            addend = word
        else:
            raise SystemExit(f"unsupported MIPS relocation type {kind}")
        patched = patch_relocation(word, kind, value + addend, gp)
        struct.pack_into("<I", compiled, offset, patched)
    if pending_high:
        raise SystemExit(f"HI16 relocation without LO16: {', '.join(pending_high)}")
    return bytes(compiled)


def verify(
    object_path: Path,
    target_path: Path,
    matches_path: Path,
    symbols_path: Path,
    source: str | None = None,
) -> None:
    addresses = load_addresses(symbols_path)
    gp = addresses.get("_gp")
    if gp is None:
        raise SystemExit("symbol map has no _gp value")
    matches = load_matches(matches_path, source)
    if not matches:
        raise SystemExit("no matching functions selected")
    target = target_path.read_bytes()

    with object_path.open("rb") as stream:
        elf = ELFFile(stream)
        symbol_table = elf.get_section_by_name(".symtab")
        if symbol_table is None:
            raise SystemExit("object has no symbol table")
        symbols = {symbol.name: symbol for symbol in symbol_table.iter_symbols() if symbol.name}

        relocations_by_section = {}
        for section in elf.iter_sections():
            if section.header.sh_type not in {"SHT_REL", "SHT_RELA"}:
                continue
            relocations_by_section.setdefault(section.header.sh_info, []).extend(
                section.iter_relocations()
            )

        for match in matches:
            name = match["name"]
            address = int(match["address"], 0)
            expected_size = int(match["size"], 0)
            symbol = symbols.get(name)
            if symbol is None or not isinstance(symbol["st_shndx"], int):
                raise SystemExit(f"compiled function missing: {name}")
            section_index = symbol["st_shndx"]
            section = elf.get_section(section_index)
            start = symbol["st_value"]
            size = symbol["st_size"] or expected_size
            if size != expected_size:
                raise SystemExit(f"compiled size mismatch for {name}: {size} != {expected_size}")
            compiled = section.data()[start : start + size]
            function_relocations = []

            for relocation in relocations_by_section.get(section_index, []):
                offset = relocation["r_offset"]
                if not (start <= offset < start + size):
                    continue
                relocation_symbol = symbol_table.get_symbol(relocation["r_info_sym"])
                relocation_value = addresses.get(relocation_symbol.name)
                if relocation_value is None:
                    raise SystemExit(
                        f"no target address for relocation {relocation_symbol.name} in {name}"
                    )
                local_offset = offset - start
                function_relocations.append((
                    local_offset, relocation["r_info_type"], relocation_value,
                    relocation_symbol.name,
                    relocation["r_addend"] if relocation.is_RELA() else None,
                ))

            compiled = relocate_bytes(compiled, function_relocations, gp)

            target_offset = address - BASE_ADDRESS
            expected = target[target_offset : target_offset + size]
            if bytes(compiled) != expected:
                mismatch = next(
                    index for index, (left, right) in enumerate(zip(compiled, expected)) if left != right
                )
                raise SystemExit(
                    f"{name} mismatch at +0x{mismatch:x}: "
                    f"compiled={compiled[mismatch]:02x} target={expected[mismatch]:02x}"
                )
            print(f"exact: {name} ({size} bytes)")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("object", type=Path)
    parser.add_argument("target", type=Path)
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    parser.add_argument("--symbols", type=Path, default=Path("config/symbol_addrs.txt"))
    parser.add_argument("--source")
    args = parser.parse_args()
    verify(args.object, args.target, args.matches, args.symbols, args.source)


if __name__ == "__main__":
    main()
