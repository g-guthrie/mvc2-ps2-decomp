#!/usr/bin/env python3
"""Validate SLUS_204.86 and extract its first PT_LOAD file image."""

import argparse
import hashlib
from pathlib import Path

from elftools.elf.elffile import ELFFile

ELF_SHA1 = "dd8558a04891b0b1472ea1d8ae2bb84947ae8937"
ELF_SHA256 = "48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7"
ROM_SHA1 = "a425c36425bbc1072114ea091ac4577c98c59a6a"
LOAD_OFFSET = 0x80
LOAD_VADDR = 0x00100000
LOAD_FILESZ = 0x3C2580
LOAD_MEMSZ = 0x534380
ENTRY = 0x00100008


def digest(data: bytes, algorithm: str) -> str:
    return hashlib.new(algorithm, data).hexdigest()


def extract(source: Path, output: Path) -> None:
    data = source.read_bytes()
    if digest(data, "sha1") != ELF_SHA1 or digest(data, "sha256") != ELF_SHA256:
        raise SystemExit("unsupported SLUS_204.86 revision")

    with source.open("rb") as stream:
        elf = ELFFile(stream)
        loads = [segment for segment in elf.iter_segments() if segment.header.p_type == "PT_LOAD"]
        if not loads:
            raise SystemExit("ELF has no PT_LOAD segment")
        load = loads[0].header
        actual = (
            load.p_offset,
            load.p_vaddr,
            load.p_filesz,
            load.p_memsz,
            elf.header.e_entry,
        )
        expected = (LOAD_OFFSET, LOAD_VADDR, LOAD_FILESZ, LOAD_MEMSZ, ENTRY)
        if actual != expected:
            raise SystemExit(f"unexpected ELF layout: {actual!r}")

    image = data[LOAD_OFFSET : LOAD_OFFSET + LOAD_FILESZ]
    if len(image) != LOAD_FILESZ or digest(image, "sha1") != ROM_SHA1:
        raise SystemExit("loaded-image validation failed")
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_bytes(image)
    print(f"wrote {output} ({len(image)} bytes, SHA-1 {ROM_SHA1})")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("source", type=Path)
    parser.add_argument("output", type=Path)
    args = parser.parse_args()
    extract(args.source, args.output)


if __name__ == "__main__":
    main()

