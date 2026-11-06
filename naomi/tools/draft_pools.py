#!/usr/bin/env python3
"""Substitute literal-pool words into a Ghidra draft.

    python3 tools/draft_pools.py DRAFT.c [DRAFT.c ...]
    python3 tools/draft_pools.py build/drafts

A draft names each PC-relative literal as _DAT_0cXXXXXX. The value is in the
ROM: 16 bits for a mov.w load, 32 bits for mov.l and mova. This rewrites the
draft in place with the literal's value, hex for offsets and addresses, and
the float spelling as a comment when the 32-bit pattern is a plausible float.
"""
import re
import struct
import sys
from pathlib import Path

from core import ROOT, load, number, verify_rom


def widths(image, base):
    """Address -> width for every PC-relative literal load in reviewed code."""
    found = {}
    for r in load(ROOT / 'config/mapping.json')['ranges']:
        if r['kind'] != 'code':
            continue
        lo, size = number(r['address']), number(r['size'])
        for pc in range(lo, lo + size, 2):
            w = struct.unpack_from('<H', image, pc - base)[0]
            if w >> 12 == 0xD or w >> 8 == 0xC7:
                found[((pc + 4) & ~3) + (w & 0xFF) * 4] = 4
            elif w >> 12 == 0x9:
                found.setdefault(pc + 4 + (w & 0xFF) * 2, 2)
    return found


def literal(image, base, address, width):
    raw = image[address - base:address - base + width]
    value = int.from_bytes(raw, 'little')
    if width == 2:
        signed = value - 0x10000 if value & 0x8000 else value
        return f'0x{value:x}' if signed >= 0 else str(signed)
    if 0x0c000000 <= value < 0x0c400000:
        return f'0x{value:08x}'
    f = struct.unpack('<f', raw)[0]
    if f == f and 1e-6 < abs(f) < 1e7:
        return f'{f:.7g}f /* 0x{value:08x} */'
    return f'0x{value:x}'


def main():
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    image = program[offset:offset + size]
    table = widths(image, base)
    paths = []
    for arg in sys.argv[1:]:
        path = Path(arg)
        paths.extend(sorted(path.glob('func_*.c')) if path.is_dir() else [path])
    for path in paths:
        text = open(path).read()
        def sub(m):
            a = int(m.group(1), 16)
            w = table.get(a)
            return literal(image, base, a, w) if w else m.group(0)
        text = re.sub(r'_DAT_(0c[0-9a-f]{6})', sub, text)
        def sub_array(m):
            a = int(m.group(1), 16) + int(m.group(2))
            w = int(m.group(3))
            return literal(image, base, a, w) if w in (2, 4) else m.group(0)
        text = re.sub(r'(?:\((?:short|int|uint|ushort)\))?BYTE_ARRAY_(0c[0-9a-f]{6})\._(\d+)_(\d)_', sub_array, text)
        text = re.sub(r'BYTE_ARRAY_(0c[0-9a-f]{6})\b', lambda m: '0x' + m.group(1), text)
        open(path, 'w').write(text)


if __name__ == '__main__':
    main()
