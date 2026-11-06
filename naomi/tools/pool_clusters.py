#!/usr/bin/env python3
"""Group reviewed code that shares a literal pool into translation-unit candidates.

SHC places a translation unit's literal pool in the same linked section as its
code, after the functions that read it. Reviewed code ranges whose PC-relative
loads land in one reviewed data range therefore belong to one object, and that
run of code plus the pool is a candidate unit.
"""
import argparse
import bisect
import json

from core import ROOT, load, number, verify_rom


def pc_relative_target(word, pc):
    """Destination of mov.l (0xD), mov.w (0x9) and mova (0xC7) literal loads."""
    if word >> 12 == 0xD:
        return ((pc + 4) & ~3) + (word & 0xFF) * 4, 4
    if word >> 12 == 0x9:
        return pc + 4 + (word & 0xFF) * 2, 2
    if word >> 8 == 0xC7:
        return ((pc + 4) & ~3) + (word & 0xFF) * 4, 4
    return None


def coalesce(ranges, kind):
    """Adjacent ledger ranges of one kind are one region; a pool is often split."""
    blocks = []
    for lo, hi, this in ranges:
        if this != kind:
            continue
        if blocks and blocks[-1][1] == lo:
            blocks[-1][1] = hi
        else:
            blocks.append([lo, hi])
    return [tuple(block) for block in blocks]


def clusters(image, base):
    ranges = sorted(
        (number(p['address']), number(p['address']) + p['size'], p['kind'])
        for p in load(ROOT / 'config/mapping.json')['ranges'])
    starts = [lo for lo, _hi, _kind in ranges]
    pools = coalesce(ranges, 'data')
    pool_starts = [lo for lo, _hi in pools]
    code = [(lo, hi) for lo, hi, kind in ranges if kind == 'code']

    def pool_of(address, width):
        index = bisect.bisect_right(pool_starts, address) - 1
        if index < 0:
            return None
        lo, hi = pools[index]
        return (lo, hi) if lo <= address and address + width <= hi else None

    readers = {}
    for lo, hi in code:
        for pc in range(lo, hi - 1, 2):
            word = image[pc - base] | (image[pc - base + 1] << 8)
            hit = pc_relative_target(word, pc)
            if hit is None:
                continue
            found = pool_of(*hit)
            if found:
                readers.setdefault(found, set()).add((lo, hi))

    out = []
    by_end = {hi: (lo, hi) for lo, hi in code}
    for (pool_lo, pool_hi), users in readers.items():
        # SHC emits the pool after the code of its own object. Walk back from the
        # pool through code blocks that are adjacent and read this same pool.
        chain = []
        edge = pool_lo
        while edge in by_end and by_end[edge] in users:
            block = by_end[edge]
            chain.append(block)
            edge = block[0]
        if len(chain) < 2:
            continue
        start = chain[-1][0]
        out.append({
            'start': f'0x{start:08x}',
            'code_bytes': pool_lo - start,
            'pool': f'0x{pool_lo:08x}',
            'pool_bytes': pool_hi - pool_lo,
            'total': pool_hi - start,
            'readers': len(chain),
        })
    out.sort(key=lambda row: -row['total'])
    return out


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--json', action='store_true')
    parser.add_argument('--limit', type=int, default=20)
    args = parser.parse_args()
    target = load(ROOT / 'config/target.json')
    main_image = target['main']
    base, offset, size = (number(main_image[k]) for k in ('address', 'rom_offset', 'size'))
    image = verify_rom(target)[offset:offset + size]
    found = clusters(image, base)
    if args.json:
        print(json.dumps(found, indent=2))
        return
    print(f'{len(found)} candidate units, {sum(r["total"] for r in found):,} bytes')
    for row in found[:args.limit]:
        print(f'  {row["start"]}  {row["readers"]:>3} fn  code {row["code_bytes"]:>6}  '
              f'pool {row["pool"]} +{row["pool_bytes"]:<5} total {row["total"]:>6}')


if __name__ == '__main__':
    main()
