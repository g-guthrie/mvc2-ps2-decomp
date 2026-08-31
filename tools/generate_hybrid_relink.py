#!/usr/bin/env python3
"""Generate raw placeholder chunks and per-function MW object slices for a hybrid relink."""

from __future__ import annotations

import argparse
import csv
import re
import struct
from pathlib import Path

from elftools.elf.elffile import ELFFile


SYMBOL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
R_MIPS_32 = 2
R_MIPS_26 = 4
R_MIPS_HI16 = 5
R_MIPS_LO16 = 6
R_MIPS_GPREL16 = 7


def load_matches(path: Path, base: int, image_size: int) -> list[tuple[str, int, int, str]]:
    with path.open(newline="", encoding="utf-8") as stream:
        rows = [
            row
            for row in csv.DictReader(stream)
            if row["status"] in {"matching", "complete"}
        ]
    matches = []
    for row in rows:
        name = row["name"]
        if not NAME_RE.fullmatch(name):
            raise SystemExit(f"invalid function name: {name}")
        address = int(row["address"], 0)
        size = int(row["size"], 0)
        start = address - base
        if start < 0 or size <= 0 or start + size > image_size:
            raise SystemExit(f"function outside loaded image: {name}")
        matches.append((name, address, size, row["source"]))
    matches.sort(key=lambda item: item[1])
    previous_end = base
    for name, address, size, _ in matches:
        if address < previous_end:
            raise SystemExit(f"overlapping function window: {name}")
        previous_end = address + size
    if not matches:
        raise SystemExit("no matching functions found")
    return matches


def load_compiled_objects(values: list[str]) -> dict[str, Path]:
    result = {}
    for value in values:
        if "=" not in value:
            raise SystemExit("--compiled-object must be SOURCE=PATH")
        source, path = value.split("=", 1)
        if not source or not path:
            raise SystemExit("--compiled-object must be SOURCE=PATH")
        result[source] = Path(path)
    return result


def load_symbols(path: Path) -> list[tuple[str, int]]:
    symbols = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = SYMBOL_RE.match(line.strip())
        if match:
            symbols.append((match.group(1), int(match.group(2), 0)))
    return symbols


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


def extract_compiled_functions(
    matches: list[tuple[str, int, int, str]],
    compiled_objects: dict[str, Path],
    addresses: dict[str, int],
    target: bytes,
    base: int,
) -> dict[str, bytes]:
    gp = addresses.get("_gp")
    if gp is None:
        raise SystemExit("symbol map has no _gp value")
    by_source: dict[str, list[tuple[str, int, int]]] = {}
    for name, address, size, source in matches:
        by_source.setdefault(source, []).append((name, address, size))

    result: dict[str, bytes] = {}
    for source, source_matches in by_source.items():
        object_path = compiled_objects.get(source)
        if object_path is None:
            raise SystemExit(f"no compiled object for source {source}")
        with object_path.open("rb") as stream:
            elf = ELFFile(stream)
            symbol_table = elf.get_section_by_name(".symtab")
            if symbol_table is None:
                raise SystemExit(f"object has no symbol table: {object_path}")
            symbols = {symbol.name: symbol for symbol in symbol_table.iter_symbols() if symbol.name}
            relocations_by_section: dict[int, list] = {}
            for section in elf.iter_sections():
                if section.header.sh_type in {"SHT_REL", "SHT_RELA"}:
                    relocations_by_section.setdefault(section.header.sh_info, []).extend(
                        section.iter_relocations()
                    )

            for name, address, expected_size in source_matches:
                symbol = symbols.get(name)
                if symbol is None or not isinstance(symbol["st_shndx"], int):
                    raise SystemExit(f"compiled function missing: {name} in {object_path}")
                section_index = symbol["st_shndx"]
                section = elf.get_section(section_index)
                start = symbol["st_value"]
                size = symbol["st_size"] or expected_size
                if size != expected_size or size % 4:
                    raise SystemExit(
                        f"compiled size mismatch for {name}: 0x{size:x} != 0x{expected_size:x}"
                    )
                compiled = bytearray(section.data()[start : start + size])
                if len(compiled) != size:
                    raise SystemExit(f"truncated compiled section for {name}")

                for relocation in relocations_by_section.get(section_index, []):
                    offset = relocation["r_offset"]
                    if not (start <= offset < start + size):
                        continue
                    relocation_symbol = symbol_table.get_symbol(relocation["r_info_sym"])
                    value = addresses.get(relocation_symbol.name)
                    if value is None:
                        raise SystemExit(
                            f"no target address for relocation {relocation_symbol.name} in {name}"
                        )
                    local_offset = offset - start
                    if local_offset + 4 > size:
                        raise SystemExit(f"relocation outside function body: {name}")
                    word = struct.unpack_from("<I", compiled, local_offset)[0]
                    patched = patch_relocation(
                        word, relocation["r_info_type"], value, gp
                    )
                    struct.pack_into("<I", compiled, local_offset, patched)

                target_start = address - base
                expected = target[target_start : target_start + size]
                if bytes(compiled) != expected:
                    mismatch = next(
                        index
                        for index, (left, right) in enumerate(zip(compiled, expected))
                        if left != right
                    )
                    raise SystemExit(
                        f"compiled mismatch for {name} at +0x{mismatch:x}: "
                        f"{compiled[mismatch]:02x} != {expected[mismatch]:02x}"
                    )
                result[name] = bytes(compiled)
    return result


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=Path, default=Path("private/SLUS_204.86.rom"))
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    parser.add_argument("--symbols", type=Path, default=Path("config/symbol_addrs.txt"))
    parser.add_argument("--compiled-object", action="append", required=True)
    parser.add_argument("--build", type=Path, default=Path("build/hybrid"))
    parser.add_argument("--base", type=lambda value: int(value, 0), default=0x00100000)
    parser.add_argument("--bss-address", type=lambda value: int(value, 0), default=0x004C2580)
    parser.add_argument("--bss-object", type=Path, default=Path("build/hybrid/main_bss.o"))
    args = parser.parse_args()

    target = args.target.read_bytes()
    image_size = len(target)
    matches = load_matches(args.matches, args.base, image_size)
    compiled_objects = load_compiled_objects(args.compiled_object)
    symbols = load_symbols(args.symbols)
    addresses = dict(symbols)
    addresses.update({name: address for name, address, _, _ in matches})
    compiled_functions = extract_compiled_functions(
        matches, compiled_objects, addresses, target, args.base
    )
    build = args.build
    build.mkdir(parents=True, exist_ok=True)

    target_text = args.target.as_posix()
    if '"' in target_text or "\\" in target_text:
        raise SystemExit("target path cannot contain a quote or backslash")

    raw_asm = build / "raw_chunks.s"
    compiled_asm = build / "compiled_sections.s"
    linker_script = build / "hybrid.ld"
    raw_lines = [".set noreorder", ""]
    compiled_lines = [".set noreorder", ""]
    link_inputs: list[str] = []
    cursor = 0
    for index, (name, address, size, _) in enumerate(matches):
        start = address - args.base
        if start > cursor:
            section = f".raw.{index:04d}"
            raw_lines.extend([
                f'.section {section}, "ax", @progbits',
                f'.incbin "{target_text}", 0x{cursor:x}, 0x{start - cursor:x}',
                "",
            ])
            link_inputs.append(f"        {build.as_posix()}/raw_chunks.o({section})")
        compiled_section = f".compiled.{name}"
        body = compiled_functions[name]
        words = [struct.unpack_from("<I", body, offset)[0] for offset in range(0, size, 4)]
        compiled_lines.extend([
            f'.section {compiled_section}, "ax", @progbits',
            f".global {name}",
            f".type {name}, @function",
            f"{name}:",
            *[f"    .word 0x{word:08X}" for word in words],
            f".size {name}, . - {name}",
            "",
        ])
        link_inputs.append(
            f"        {build.as_posix()}/compiled_sections.o({compiled_section})"
        )
        cursor = start + size
    if cursor < image_size:
        section = f".raw.{len(matches):04d}"
        raw_lines.extend([
            f'.section {section}, "ax", @progbits',
            f'.incbin "{target_text}", 0x{cursor:x}, 0x{image_size - cursor:x}',
            "",
        ])
        link_inputs.append(f"        {build.as_posix()}/raw_chunks.o({section})")
    raw_asm.write_text("\n".join(raw_lines), encoding="utf-8")
    compiled_asm.write_text("\n".join(compiled_lines), encoding="utf-8")

    compiled_names = {name for name, _, _, _ in matches}
    symbol_lines = [
        f"    {name} = 0x{address:08x};"
        for name, address in symbols
        if name not in compiled_names
    ]
    ld_lines = [
        "OUTPUT_ARCH(mips)",
        "ENTRY(_start)",
        "",
        "SECTIONS",
        "{",
        f"    . = 0x{args.base:08x};",
        "    .text : SUBALIGN(1)",
        "    {",
        *link_inputs,
        "    }",
        "",
        f"    . = 0x{args.bss_address:08x};",
        "    .bss (NOLOAD) : SUBALIGN(1)",
        "    {",
        f"        {args.bss_object.as_posix()}(.bss)",
        "    }",
        "",
        *symbol_lines,
        "",
        "    /DISCARD/ :",
        "    {",
        "        *(.data)",
        "        *(.reginfo)",
        "        *(.MIPS.abiflags)",
        "        *(.pdr)",
        "        *(.mwcats*)",
        "        *(.comment)",
        "        *(.gnu.attributes)",
        "        *(.note*)",
        "    }",
        "}",
        "",
    ]
    linker_script.write_text("\n".join(ld_lines), encoding="utf-8")
    print(f"generated {len(matches)} isolated compiled-function sections")


if __name__ == "__main__":
    main()
