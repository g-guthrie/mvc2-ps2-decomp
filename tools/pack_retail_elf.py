#!/usr/bin/env python3
"""Deterministically wrap the exact SLUS-20486 loaded image in its retail ELF layout."""

from __future__ import annotations

import argparse
import hashlib
import struct
from pathlib import Path


IMAGE_SIZE = 0x003C2580
IMAGE_OFFSET = 0x80
BSS_ADDRESS = 0x004C2580
BSS_SIZE = 0x00171E00
MEMORY_END = BSS_ADDRESS + BSS_SIZE
ENTRY_POINT = 0x00100008
LOAD_ADDRESS = 0x00100000
GLOBAL_POINTER = 0x004C7270

SHSTRTAB_OFFSET = 0x003C2600
COMMENT_OFFSET = 0x003C262D
REGINFO_OFFSET = 0x003C2658
SECTION_HEADERS_OFFSET = 0x003C2670
OUTPUT_SIZE = 0x003C27B0

EXPECTED_IMAGE_SHA256 = "c5206f568f068e5bd93ba47676500764c3d45719890865fa71ada10afadcd26f"
EXPECTED_ELF_SHA256 = "48ebf907d8149122ca9bd622ed11c290d5f93173078ea5bd570e1ac5566f13d7"

ELF_IDENT = b"\x7fELF\x01\x01\x01" + b"\0" * 9
SHSTRTAB = b"\0.shstrtab\0.strtab\0.symtab\0.comment\0.reginfo\0"
COMMENT = b"MW MIPS C Compiler (2.4.1.01)\0PlayStation2\0"


def section_header(
    name: int,
    section_type: int,
    flags: int,
    address: int,
    offset: int,
    size: int,
    link: int,
    info: int,
    alignment: int,
    entry_size: int,
) -> bytes:
    return struct.pack(
        "<10I",
        name,
        section_type,
        flags,
        address,
        offset,
        size,
        link,
        info,
        alignment,
        entry_size,
    )


def build_elf(loaded_image: bytes) -> bytes:
    if len(loaded_image) != IMAGE_SIZE:
        raise ValueError(f"loaded image is {len(loaded_image)} bytes, expected {IMAGE_SIZE}")

    elf_header = struct.pack(
        "<16sHHIIIIIHHHHHH",
        ELF_IDENT,
        2,  # ET_EXEC
        8,  # EM_MIPS
        1,  # EV_CURRENT
        ENTRY_POINT,
        52,
        SECTION_HEADERS_OFFSET,
        0x20924000,  # EF_MIPS_ARCH_3 | EF_MIPS_MACH_5900 | EABI64
        52,
        32,
        2,
        40,
        8,
        1,
    )
    program_headers = b"".join(
        [
            struct.pack(
                "<8I",
                1,
                IMAGE_OFFSET,
                LOAD_ADDRESS,
                LOAD_ADDRESS,
                IMAGE_SIZE,
                MEMORY_END - LOAD_ADDRESS,
                7,
                0x80,
            ),
            struct.pack(
                "<8I",
                1,
                SHSTRTAB_OFFSET,
                MEMORY_END,
                MEMORY_END,
                0,
                0,
                6,
                0x10,
            ),
        ]
    )
    prefix = elf_header + program_headers
    prefix += bytes(IMAGE_OFFSET - len(prefix))

    reginfo = struct.pack(
        "<6I",
        0xF7FFFFFE,
        0,
        0xFFFFFFFF,
        0,
        0,
        GLOBAL_POINTER,
    )
    section_headers = b"".join(
        [
            section_header(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
            section_header(1, 3, 0, 0, SHSTRTAB_OFFSET, len(SHSTRTAB), 0, 0, 1, 1),
            section_header(0x0B, 3, 0, 0, 0, 0, 0, 0, 1, 1),
            section_header(0x13, 2, 0, 0, 0, 0, 2, 0, 1, 0x10),
            section_header(0, 1, 7, LOAD_ADDRESS, IMAGE_OFFSET, IMAGE_SIZE, 0, 0, 0x80, 1),
            section_header(0, 1, 3, MEMORY_END, SHSTRTAB_OFFSET, 0, 0, 0, 0x10, 1),
            section_header(0x1B, 1, 0, 0, COMMENT_OFFSET, len(COMMENT), 0, 0, 1, 1),
            section_header(0x24, 0x70000006, 0, 0, REGINFO_OFFSET, len(reginfo), 0, 0, 4, 1),
        ]
    )

    result = prefix + loaded_image + SHSTRTAB + COMMENT + reginfo + section_headers
    if len(result) != OUTPUT_SIZE:
        raise AssertionError(f"packed ELF is 0x{len(result):x}, expected 0x{OUTPUT_SIZE:x}")
    return result


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("image", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument("--expected-image-sha256", default=EXPECTED_IMAGE_SHA256)
    parser.add_argument("--expected-elf-sha256", default=EXPECTED_ELF_SHA256)
    args = parser.parse_args()

    loaded_image = args.image.read_bytes()
    image_hash = sha256(loaded_image)
    if image_hash != args.expected_image_sha256:
        raise SystemExit(
            f"loaded-image SHA-256 mismatch: {image_hash} != {args.expected_image_sha256}"
        )
    elf = build_elf(loaded_image)
    elf_hash = sha256(elf)
    if elf_hash != args.expected_elf_sha256:
        raise SystemExit(f"ELF SHA-256 mismatch: {elf_hash} != {args.expected_elf_sha256}")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes(elf)
    print(f"exact retail ELF: {len(elf)} bytes")
    print(f"sha256: {elf_hash}")


if __name__ == "__main__":
    main()
