#!/usr/bin/env python3
"""Generate raw placeholder chunks and per-function MW object slices for a hybrid relink."""

from __future__ import annotations

import argparse
import csv
import re
import struct
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.enums import ENUM_RELOC_TYPE_MIPS


SYMBOL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;")
NAME_RE = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
MIPS_RELOCATION_NAMES = {
    value: name for name, value in ENUM_RELOC_TYPE_MIPS.items() if isinstance(value, int)
}


@dataclass(frozen=True)
class ExternalRelocation:
    offset: int
    type_name: str
    symbol_name: str
    addend: int = 0


@dataclass(frozen=True)
class CompiledFunction:
    body: bytes
    relocations: tuple[ExternalRelocation, ...]


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


def default_object_path(source: str, compiled_dir: Path) -> Path:
    source_path = Path(source)
    if source_path.is_absolute() or ".." in source_path.parts:
        raise SystemExit(f"source path must stay within the project: {source}")
    relative = source_path
    if relative.parts and relative.parts[0] == "src":
        relative = Path(*relative.parts[1:])
    return compiled_dir / relative.with_suffix(".o")


def load_compiled_objects(
    values: list[str],
    matches: list[tuple[str, int, int, str]],
    compiled_dir: Path,
) -> dict[str, Path]:
    result = {}
    for value in values:
        if "=" not in value:
            raise SystemExit("--compiled-object must be SOURCE=PATH")
        source, path = value.split("=", 1)
        if not source or not path:
            raise SystemExit("--compiled-object must be SOURCE=PATH")
        result[source] = Path(path)
    for source in {source for _, _, _, source in matches}:
        result.setdefault(source, default_object_path(source, compiled_dir))
    for source, path in result.items():
        if not path.is_file():
            raise SystemExit(f"compiled object missing for {source}: {path}")
    return result


def load_symbols(path: Path) -> list[tuple[str, int]]:
    symbols = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = SYMBOL_RE.match(line.strip())
        if match:
            symbols.append((match.group(1), int(match.group(2), 0)))
    return symbols


def extract_compiled_functions(
    matches: list[tuple[str, int, int, str]],
    compiled_objects: dict[str, Path],
    addresses: dict[str, int],
) -> tuple[dict[str, CompiledFunction], dict[str, int]]:
    by_source: dict[str, list[tuple[str, int, int]]] = {}
    for name, address, size, source in matches:
        by_source.setdefault(source, []).append((name, address, size))

    result: dict[str, CompiledFunction] = {}
    synthetic_symbols: dict[str, int] = {}
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
            section_bases: dict[int, int] = {}
            for symbol in symbol_table.iter_symbols():
                section_index = symbol["st_shndx"]
                address = addresses.get(symbol.name)
                if address is None or not isinstance(section_index, int):
                    continue
                candidate = address - symbol["st_value"]
                previous = section_bases.setdefault(section_index, candidate)
                if previous != candidate:
                    raise SystemExit(
                        f"inconsistent retail base for section {section_index} in {object_path}"
                    )
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
                compiled = bytes(section.data()[start : start + size])
                if len(compiled) != size:
                    raise SystemExit(f"truncated compiled section for {name}")

                external_relocations: list[ExternalRelocation] = []
                for relocation in relocations_by_section.get(section_index, []):
                    offset = relocation["r_offset"]
                    if not (start <= offset < start + size):
                        continue
                    relocation_symbol = symbol_table.get_symbol(relocation["r_info_sym"])
                    local_offset = offset - start
                    if local_offset + 4 > size:
                        raise SystemExit(f"relocation outside function body: {name}")
                    relocation_type = relocation["r_info_type"]
                    type_name = MIPS_RELOCATION_NAMES.get(relocation_type)
                    if type_name is None:
                        raise SystemExit(
                            f"unknown MIPS relocation type {relocation_type} in {name}"
                        )

                    symbol_name = relocation_symbol.name
                    if symbol_name not in addresses:
                        target_section = relocation_symbol["st_shndx"]
                        if not isinstance(target_section, int) or target_section not in section_bases:
                            raise SystemExit(
                                f"no retail address for relocation symbol {symbol_name!r} in {name}"
                            )
                        value = section_bases[target_section] + relocation_symbol["st_value"]
                        object_token = re.sub(r"[^A-Za-z0-9_]", "_", object_path.stem)
                        symbol_name = (
                            f"__mw_{object_token}_s{target_section}_v{relocation_symbol['st_value']:x}"
                        )
                        synthetic_symbols[symbol_name] = value

                    addend = relocation["r_addend"] if relocation.is_RELA() else 0
                    external_relocations.append(
                        ExternalRelocation(local_offset, type_name, symbol_name, addend)
                    )

                result[name] = CompiledFunction(compiled, tuple(external_relocations))
    return result, synthetic_symbols


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", type=Path, default=Path("private/SLUS_204.86.rom"))
    parser.add_argument("--matches", type=Path, default=Path("config/matches.csv"))
    parser.add_argument("--symbols", type=Path, default=Path("config/symbol_addrs.txt"))
    parser.add_argument("--compiled-object", action="append", default=[])
    parser.add_argument("--compiled-dir", type=Path, default=Path("build/matching"))
    parser.add_argument("--build", type=Path, default=Path("build/hybrid"))
    parser.add_argument("--base", type=lambda value: int(value, 0), default=0x00100000)
    parser.add_argument("--bss-address", type=lambda value: int(value, 0), default=0x004C2580)
    parser.add_argument("--bss-object", type=Path, default=Path("build/hybrid/main_bss.o"))
    args = parser.parse_args()

    target = args.target.read_bytes()
    image_size = len(target)
    matches = load_matches(args.matches, args.base, image_size)
    compiled_objects = load_compiled_objects(args.compiled_object, matches, args.compiled_dir)
    symbols = load_symbols(args.symbols)
    addresses = dict(symbols)
    addresses.update({name: address for name, address, _, _ in matches})
    compiled_functions, synthetic_symbols = extract_compiled_functions(
        matches, compiled_objects, addresses
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
        function = compiled_functions[name]
        body = function.body
        words = [struct.unpack_from("<I", body, offset)[0] for offset in range(0, size, 4)]
        compiled_lines.extend([
            f'.section {compiled_section}, "ax", @progbits',
            f".global {name}",
            f".type {name}, @function",
            f"{name}:",
            *[f"    .word 0x{word:08X}" for word in words],
            *[
                f"    .reloc {name}+0x{relocation.offset:x}, {relocation.type_name}, "
                f"{relocation.symbol_name}"
                + (f"{relocation.addend:+#x}" if relocation.addend else "")
                for relocation in function.relocations
            ],
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
    symbol_lines.extend(
        f"    {name} = 0x{address:08x};"
        for name, address in sorted(synthetic_symbols.items())
    )
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
    relocation_counts = Counter(
        relocation.type_name
        for function in compiled_functions.values()
        for relocation in function.relocations
    )
    relocation_summary = ", ".join(
        f"{name}={count}" for name, count in sorted(relocation_counts.items())
    ) or "none"
    print(f"generated {len(matches)} isolated compiled-function sections")
    print(f"externalized relocations: {relocation_summary}")


if __name__ == "__main__":
    main()
