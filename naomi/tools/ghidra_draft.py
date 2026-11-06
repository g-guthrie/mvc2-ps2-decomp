#!/usr/bin/env python3
"""Write a Ghidra decompilation draft for every reviewed function.

    python3 tools/ghidra_draft.py --ghidra /path/to/ghidra_11.x_PUBLIC

Ghidra is not bundled; pass its install directory. The main image is
imported as SuperH4 little-endian at its load address, functions are created
at every reviewed code range that starts a function (previous range is data,
or the previous code ends in rts or bra), reviewed data is marked as bytes so
the decompiler never reads a pool as code, and the decompiler output lands in
build/drafts/func_0cXXXXXX.c with build/drafts/index.txt, with every pool
literal substituted by tools/draft_pools.py.

A draft is a starting point for reading a function, never source: it has the
control flow and field offsets, not the shape that reproduces the bytes.
"""
import argparse
import shutil
import struct
import subprocess
import sys
from pathlib import Path

from core import ROOT, load, number, verify_rom


def function_starts(image, base, ranges):
    """Reviewed code range starts that begin a function: after data, after a
    range ending in rts or bra, or the target of a bsr or of a pool pointer."""
    ranges = sorted(ranges)
    code = [(lo, lo + size) for lo, size, kind in ranges if kind == 'code']
    starts = set()
    for lo, size, kind in ranges:
        if kind == 'code':
            for pc in range(lo, lo + size, 2):
                w = struct.unpack_from('<H', image, pc - base)[0]
                if w >> 12 == 0xB:
                    d = w & 0xFFF
                    starts.add(pc + 4 + (d - 0x1000 if d & 0x800 else d) * 2)
        else:
            for a in range(lo & ~3, lo + size - 3, 4):
                v = struct.unpack_from('<I', image, a - base)[0]
                if v % 2 == 0 and base <= v < base + len(image):
                    starts.add(v)
    heads = {lo for lo, size, kind in ranges if kind == 'code'}
    starts = {a for a in starts if a in heads}
    starts = list(starts)
    for i, (lo, size, kind) in enumerate(ranges):
        if kind != 'code':
            continue
        if i == 0 or ranges[i - 1][2] != 'code':
            starts.append(lo)
            continue
        plo, psize, _ = ranges[i - 1]
        tail = [struct.unpack_from('<H', image, a - base)[0] for a in range(max(plo, plo + psize - 4), plo + psize, 2)]
        if 0x000b in tail or any(w >> 12 == 0xa or w & 0xf0ff == 0x402b for w in tail):
            starts.append(lo)
    return sorted(set(starts))


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--ghidra', required=True, help='Ghidra install directory')
    parser.add_argument('--out', default=str(ROOT / 'build' / 'drafts'), type=lambda p: str(Path(p).resolve()))
    args = parser.parse_args()
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    image = program[offset:offset + size]
    work = ROOT / 'build' / 'ghidra'
    if work.exists():
        shutil.rmtree(work)
    work.mkdir(parents=True)
    (work / 'main.bin').write_bytes(image)
    ranges = [(number(r['address']), number(r['size']), r['kind']) for r in load(ROOT / 'config/mapping.json')['ranges']]
    starts = set(function_starts(image, base, ranges))
    with open(work / 'spec.txt', 'w') as spec:
        for lo, n, kind in sorted(ranges):
            spec.write(f"0x{lo:08x} {n} {'data' if kind == 'data' else 'function' if lo in starts else 'code'}\n")
    headless = args.ghidra.rstrip('/') + '/support/analyzeHeadless'
    command = [headless, str(work), 'mvc2', '-import', str(work / 'main.bin'), '-processor', 'SuperH4:LE:32:default',
               '-loader', 'BinaryLoader', '-loader-baseAddr', f'0x{base:08x}', '-scriptPath', str(ROOT / 'tools' / 'ghidra'),
               '-noanalysis', '-postScript', 'DraftExport.java', str(work / 'spec.txt'), args.out]
    print(' '.join(command), flush=True)
    result = subprocess.run(command, cwd=work)
    if result.returncode == 0:
        subprocess.run([sys.executable, str(ROOT / 'tools' / 'draft_pools.py'), args.out], check=True)
    return result.returncode


if __name__ == '__main__':
    raise SystemExit(main())
