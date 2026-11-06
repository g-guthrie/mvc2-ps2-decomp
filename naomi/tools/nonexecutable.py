#!/usr/bin/env python3
"""Propose unknown runs that encode no SH-4 instruction as data.

SH-4 instructions are two bytes and two-byte aligned, so every even address
inside executed code is an instruction boundary. A run of even addresses whose
words all encode no instruction therefore cannot be executed, and the image
holds only code and data.
"""
import argparse
import json

from core import ROOT, load, number, sha, verify_rom
from vendor.sh4dis import sh4

# One undecodable word already proves the address is not executed, but a lone
# word is usually two-byte alignment padding, which this project deliberately
# leaves unknown rather than folding into a neighbouring pool. Two consecutive
# undecodable words are past that and still far short of the decoder's 9.6%
# rejection rate mattering.
MINIMUM = 4


def undecodable_table():
    return bytes(sh4.disasm(word, 0) == 'error' for word in range(1 << 16))


def unknown_ranges(base, size):
    known = []
    for part in load(ROOT / 'config/mapping.json')['ranges']:
        start = number(part['address'])
        known.append((start, start + part['size']))
    known.sort()
    cursor, gaps = base, []
    for start, end in known:
        if start > cursor:
            gaps.append((cursor, start))
        cursor = max(cursor, end)
    if cursor < base + size:
        gaps.append((cursor, base + size))
    return gaps


def proposals(image, base, minimum=MINIMUM):
    bad = undecodable_table()
    out = []
    for start, end in unknown_ranges(base, len(image)):
        run = None
        position = start + (start % 2)
        while position < end - 1:
            word = image[position - base] | (image[position - base + 1] << 8)
            if bad[word]:
                if run is None:
                    run = position
            elif run is not None:
                if position - run >= minimum:
                    out.append((run, position - run))
                run = None
            position += 2
        if run is not None and end - run >= minimum:
            out.append((run, end - run))
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--json', action='store_true')
    parser.add_argument('--minimum', type=int, default=MINIMUM)
    args = parser.parse_args()
    target = load(ROOT / 'config/target.json')
    main_image = target['main']
    base, offset, size = (number(main_image[k]) for k in ('address', 'rom_offset', 'size'))
    image = verify_rom(target)[offset:offset + size]
    found = proposals(image, base, args.minimum)
    rows = [{
        'address': f'0x{start:08x}',
        'size': length,
        'kind': 'data',
        'sha256': sha(image[start - base:start - base + length]),
        'evidence': (
            'No aligned halfword in this range encodes an SH-4 instruction, so no '
            'instruction stream executes through it; the image holds only code and data.'
        ),
    } for start, length in found]
    if args.json:
        print(json.dumps(rows, indent=2))
    else:
        print(f'{len(rows)} runs, {sum(r["size"] for r in rows):,} bytes')


if __name__ == '__main__':
    main()
