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
        reader = csv.DictReader(stream)
        result = []
        for row in reader:
            if None in row or any(
                not row.get(key)
                for key in ("name", "address", "size", "source", "status")
            ):
                raise SystemExit(f"malformed code match row: {path}:{reader.line_num}")
            if row["status"] in {"matching", "complete", "placeholder"} and (
                source is None or row["source"] == source
            ):
                result.append(row)
        return result


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


def report_words(
    name: str, compiled: bytes, expected: bytes, unrelocated: bool = False
) -> None:
    """Print a per-word diff, so a near miss can be judged at a glance.

    The first differing byte says almost nothing about how close a function is:
    one wrong register early reads the same as a completely wrong body. Counting
    differing 32-bit words, and showing where they are, distinguishes "one
    register off" from "not this toolchain".
    """
    words = min(len(compiled), len(expected)) // 4
    bad = [
        i for i in range(words)
        if compiled[i * 4 : i * 4 + 4] != expected[i * 4 : i * 4 + 4]
    ]
    print(
        f"diff: {name} {len(bad)}/{words} words differ"
        f"{'' if len(compiled) == len(expected) else f' (size {len(compiled)} vs {len(expected)})'}"
        f"{' [pre-relocation: call and %hi/%lo fields read as 0]' if unrelocated else ''}"
    )
    for i in bad[:24]:
        got = struct.unpack_from("<I", compiled, i * 4)[0]
        want = struct.unpack_from("<I", expected, i * 4)[0]
        print(f"  +0x{i * 4:04x}  compiled={got:08x}  target={want:08x}")
    if len(bad) > 24:
        print(f"  ... {len(bad) - 24} more")


def relocation_target(symbol, symbols, addresses, section_bases=None):
    """Resolve local section references from consistent, known symbol anchors."""
    if symbol.name in addresses:
        return addresses[symbol.name], symbol.name
    section_index = symbol["st_shndx"]
    if not isinstance(section_index, int):
        raise SystemExit(f"no target address for relocation {symbol.name!r}")
    if section_bases and section_index in section_bases:
        return (section_bases[section_index] + symbol["st_value"],
                f"@section:{section_index}:{symbol['st_value']}")
    bases = {
        addresses[anchor.name] - anchor["st_value"]
        for anchor in symbols
        if anchor["st_shndx"] == section_index and anchor.name in addresses
    }
    if not bases:
        raise SystemExit(f"no target address for relocation {symbol.name!r}")
    if len(bases) != 1:
        raise SystemExit(f"inconsistent retail base for section {section_index}")
    value = bases.pop() + symbol["st_value"]
    return value, f"@section:{section_index}:{symbol['st_value']}"


def whole_function_anchors(elf, symbols, matches):
    """Only infer addresses for sections wholly owned by a selected function."""
    anchors = []
    for match in matches:
        symbol = symbols.get(match["name"])
        size = int(match["size"], 0)
        if symbol is None or not isinstance(symbol["st_shndx"], int):
            continue
        section = elf.get_section(symbol["st_shndx"])
        if (symbol["st_info"]["type"] == "STT_FUNC"
                and symbol["st_value"] == 0 and symbol["st_size"] == size
                and section.data_size == size and section["sh_flags"] & 4):
            anchors.append(symbol)
    return anchors


def load_readonly_sections(path=Path("config/readonly_sections.csv")):
    """Explicit compiler-constant locations; these do not award data credit."""
    if not path.is_file():
        return []
    with path.open(newline="", encoding="utf-8") as stream:
        return list(csv.DictReader(stream))


def validated_readonly_bases(elf, symbols, matches, addresses, target, mappings):
    """Anchor a complete readonly section only after checking every byte.

    Jump-table entries must resolve inside a whole selected function. Unknown
    symbols, partial sections, writable sections and escaped labels are rejected.
    The constants remain uncredited placeholders in the hybrid image.
    """
    sources = {row["source"] for row in matches if row["name"] in symbols}
    selected = [row for row in mappings if row["source"] in sources]
    if not selected:
        return {}
    anchors = whole_function_anchors(elf, symbols, matches)
    table = elf.get_section_by_name(".symtab")
    sections = list(elf.iter_sections())
    result = {}
    for row in selected:
        candidates = [(i, sec) for i, sec in enumerate(sections)
                      if sec.name == row["section"]]
        if len(candidates) != 1:
            raise SystemExit(f"readonly section missing or ambiguous: {row['section']}")
        index, section = candidates[0]
        size, address = int(row["size"], 0), int(row["address"], 0)
        offset = address - BASE_ADDRESS
        if (section["sh_type"] != "SHT_PROGBITS"
                or section["sh_flags"] & 7 != 2
                or size <= 0 or section.data_size != size
                or offset < 0 or offset + size > len(target)):
            raise SystemExit(f"invalid whole readonly section: {row['section']}")
        relocations = []
        for relsec in sections:
            if (relsec["sh_type"] not in {"SHT_REL", "SHT_RELA"}
                    or relsec["sh_info"] != index):
                continue
            for rel in relsec.iter_relocations():
                pos = rel["r_offset"]
                if rel["r_info_type"] != R_MIPS_32 or pos % 4 or not 0 <= pos <= size - 4:
                    raise SystemExit("unsupported readonly relocation or offset")
                symbol = table.get_symbol(rel["r_info_sym"])
                owners = [a for a in anchors if a["st_shndx"] == symbol["st_shndx"]]
                if not owners:
                    raise SystemExit("readonly relocation has no whole function owner")
                value, key = relocation_target(symbol, anchors, addresses)
                addend = (rel["r_addend"] if rel.is_RELA()
                          else struct.unpack_from("<I", section.data(), pos)[0])
                if not any(addresses[a.name] <= value + addend
                           < addresses[a.name] + a["st_size"] for a in owners):
                    raise SystemExit("readonly label outside whole function")
                relocations.append((pos, R_MIPS_32, value, key,
                                    rel["r_addend"] if rel.is_RELA() else None))
        body = relocate_bytes(section.data(), relocations, addresses["_gp"])
        if body != target[offset:offset + size]:
            raise SystemExit(f"readonly section differs from retail: {row['section']}")
        if index in result:
            raise SystemExit(f"duplicate readonly mapping: {row['section']}")
        result[index] = address
    return result


def verify(
    object_path: Path,
    target_path: Path,
    matches_path: Path,
    symbols_path: Path,
    source: str | None = None,
    diff: bool = False,
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
        section_anchors = whole_function_anchors(elf, symbols, matches)
        readonly_bases = validated_readonly_bases(
            elf, symbols, matches, addresses, target, load_readonly_sections())

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
                if diff:
                    # Relocations are resolved further down, so the bytes here
                    # still have zeroed relocation fields; calls and %hi/%lo
                    # halves will read as differences that are not real.
                    body = section.data()[start : start + size]
                    target_offset = address - BASE_ADDRESS
                    report_words(
                        name, body, target[target_offset : target_offset + expected_size],
                        unrelocated=True,
                    )
                raise SystemExit(f"compiled size mismatch for {name}: {size} != {expected_size}")
            compiled = section.data()[start : start + size]
            function_relocations = []

            for relocation in relocations_by_section.get(section_index, []):
                offset = relocation["r_offset"]
                if not (start <= offset < start + size):
                    continue
                relocation_symbol = symbol_table.get_symbol(relocation["r_info_sym"])
                relocation_value, relocation_key = relocation_target(
                    relocation_symbol, section_anchors, addresses, readonly_bases
                )
                local_offset = offset - start
                function_relocations.append((
                    local_offset, relocation["r_info_type"], relocation_value,
                    relocation_key,
                    relocation["r_addend"] if relocation.is_RELA() else None,
                ))

            compiled = relocate_bytes(compiled, function_relocations, gp)

            target_offset = address - BASE_ADDRESS
            expected = target[target_offset : target_offset + size]
            if bytes(compiled) != expected:
                if diff:
                    report_words(name, bytes(compiled), expected)
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
    parser.add_argument(
        "--diff",
        action="store_true",
        help="on a mismatch, list the differing 32-bit words before exiting",
    )
    args = parser.parse_args()
    verify(args.object, args.target, args.matches, args.symbols, args.source, args.diff)


if __name__ == "__main__":
    main()
