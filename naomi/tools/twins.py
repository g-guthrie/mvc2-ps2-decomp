#!/usr/bin/env python3
"""For each function in a span, find a verified function of the same shape.

    python3 tools/twins.py 0x0c118fc8 276
    python3 tools/twins.py 0x0c03052a 16 --register-renaming

Two functions have the same shape when their instructions agree once
immediates, displacements, branch targets and pool literals are masked. The
game stamps its state handlers from a few templates, so a verified twin's C
is usually the target's C with other constants, offsets and callees. The tool
prints, per function, the twin's source with its address, and the words that
differ so the constants can be read off the disassembly. With the opt-in flag,
it also reports consistent register-renaming hints with verified source
provenance. Those hints never feed clone.py or count as byte equality.
"""
import argparse
import bisect
import collections
import re
import struct
import sys

from core import ROOT, load, number, verify_rom
from ghidra_draft import function_starts


def shape(image, base, lo, hi):
    out = []
    for pc in range(lo, hi, 2):
        w = struct.unpack_from('<H', image, pc - base)[0]
        top = w >> 12
        if top in (0x9, 0xd, 0xe, 0x7):
            out.append(top << 12 | (w & 0x0f00))
        elif top in (0xa, 0xb, 0xc):
            out.append(top << 12)
        elif top == 0x8:
            out.append(w & 0xff00)
        elif top in (0x1, 0x5):
            out.append(w & 0xfff0)
        else:
            out.append(w)
    return tuple(out)


def register_shape(image, base, lo, hi):
    """Conservative discovery signature plus physical-to-canonical register map.

    Unlike shape(), branch displacements remain intact. A register has one
    identity for the entire function, including saves/restores and delay slots.
    Keep default-ABI argument/result/SP registers fixed and never exchange volatile and
    preserved registers. Unsupported instructions (including CPU/FPU mode
    changes) reject the function rather than guess. Single-precision FPU mode
    is assumed, as in this repository's game compiler settings. Custom runtime
    helper conventions (such as implicit R1/R2 operands) require native review;
    this signature is not a behavioral-equivalence proof.
    """
    registers = {}
    counts = collections.Counter()

    def register(kind, value):
        fixed = {0, 4, 5, 6, 7, 15} if kind == 'r' else {0, *range(4, 12)}
        if value in fixed:
            return (kind, 'fixed', value)
        group = 'saved' if value >= (8 if kind == 'r' else 12) else 'scratch'
        key = (kind, value)
        if key not in registers:
            registers[key] = (kind, group, counts[kind, group])
            counts[kind, group] += 1
        return registers[key]

    out = []
    for pc in range(lo, hi, 2):
        w = struct.unpack_from('<H', image, pc - base)[0]
        top, low = w >> 12, w & 15
        operands, masked = [], w

        def operand(shift, kind='r'):
            nonlocal masked
            operands.append(register(kind, (w >> shift) & 15))
            masked &= ~(15 << shift)

        if top in (1, 5):
            operand(8); operand(4); masked &= 0xfff0
        elif top in (2, 3, 6) and (top != 2 or low != 3) and (top != 3 or low not in (1, 9)):
            operand(8); operand(4)
        elif top in (7, 9, 13, 14):
            operand(8); masked &= 0xff00
        elif top in (10, 11):
            pass  # control-flow edges must retain their instruction offsets
        elif top == 8 and (w >> 8) in (0x80, 0x81, 0x84, 0x85):
            operand(4); masked &= 0xfff0  # implicit r0 remains fixed
        elif top == 8 and (w >> 8) in (0x89, 0x8b, 0x8d, 0x8f):
            pass
        elif top == 8 and (w >> 8) == 0x88:
            masked &= 0xff00
        elif top == 12 and (w >> 8) != 0xc3:
            masked &= 0xff00  # implicit r0/GBR, including MOVA
        elif top == 0 and low in (4, 5, 6, 7, 12, 13, 14, 15):
            operand(8); operand(4)
        elif top == 0 and (w & 0xff) in (0x03, 0x23, 0x29, 0x0a, 0x1a, 0x2a):
            operand(8)
        elif w in (0x0009, 0x000b, 0x0008, 0x0018, 0x0019, 0x0028):
            pass
        elif top == 4 and low in (12, 13):
            operand(8); operand(4)
        elif top == 4 and (w & 0xff) in (
                0x00, 0x01, 0x04, 0x05, 0x08, 0x09, 0x10, 0x11,
                0x15, 0x18, 0x19, 0x20, 0x21, 0x24, 0x25, 0x28, 0x29,
                0x0b, 0x2b, 0x1b, 0x02, 0x12, 0x22, 0x06, 0x16, 0x26,
                0x0a, 0x1a, 0x2a):
            operand(8)
        elif top == 15 and low in (0, 1, 2, 3, 4, 5, 12):
            operand(8, 'fr'); operand(4, 'fr')
        elif top == 15 and low in (6, 8, 9):
            operand(8, 'fr'); operand(4)
        elif top == 15 and low in (7, 10, 11):
            operand(8); operand(4, 'fr')
        elif top == 15 and (w & 0xff) in (0x0d, 0x1d, 0x2d, 0x3d, 0x4d, 0x5d, 0x6d, 0x7d, 0x8d, 0x9d):
            operand(8, 'fr')
        else:
            return None
        out.append((masked, tuple(operands)))
    return tuple(out), registers


def renamed_twins(image, base, start, end, starts, extent, verified):
    """Return only additional hints, never used by clone or registration."""
    target = register_shape(image, base, start, end)
    if target is None:
        return []
    result = []
    for address in starts:
        if address == start or address not in verified or extent(address) - address != end - start:
            continue
        candidate = register_shape(image, base, address, extent(address))
        if candidate is None or candidate[0] != target[0]:
            continue
        if shape(image, base, address, extent(address)) == shape(image, base, start, end):
            continue
        reverse = {v: k for k, v in target[1].items()}
        mapping = {f'{kind}{n}': f'{reverse[value][0]}{reverse[value][1]}'
                   for (kind, n), value in candidate[1].items()}
        result.append({'address': address, 'source': verified[address],
                       'twin_to_target_registers': mapping})
    return result


def discovery_index():
    """Read reviewed function extents and verified source provenance once."""
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, total = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    image = program[offset:offset + total]
    ranges = [(number(r['address']), number(r['size']), r['kind']) for r in load(ROOT / 'config/mapping.json')['ranges']]
    starts = sorted(function_starts(image, base, ranges))
    code = sorted((lo, lo + n) for lo, n, kind in ranges if kind == 'code')
    heads = [c[0] for c in code]

    def extent(a):
        i = bisect.bisect_right(starts, a)
        nxt = starts[i] if i < len(starts) else None
        j = bisect.bisect_right(heads, a) - 1
        end = code[j][1]
        while j + 1 < len(code) and code[j + 1][0] == end:
            j += 1
            end = code[j][1]
        return min(end, nxt) if nxt else end

    verified = {}
    for unit in load(ROOT / 'config/units.json'):
        if unit['mode'] != 'verified':
            continue
        for symbol, address in unit.get('exports', {}).items():
            if symbol.startswith('_func_'):
                verified[number(address)] = unit['source']
    return image, base, starts, extent, verified


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('start', type=number)
    parser.add_argument('size', type=lambda value: int(value, 0))
    parser.add_argument('--register-renaming', action='store_true', help='additional conservative discovery hints; never exact proof or clone input')
    args = parser.parse_args()
    start, size = args.start, args.size
    image, base, starts, extent, verified = discovery_index()
    groups = collections.defaultdict(list)
    for a in starts:
        groups[shape(image, base, a, extent(a))].append(a)
    for a in [s for s in starts if start <= s < start + size]:
        e = extent(a)
        group = groups[shape(image, base, a, e)]
        twins = [t for t in group if t in verified and t != a]
        print(f'func_{a:08x} {e - a} bytes: shape shared by {len(group)} functions, {len(twins)} verified')
        if args.register_renaming:
            for hint in renamed_twins(image, base, a, e, starts, extent, verified):
                print(f"  register-renamed hint func_{hint['address']:08x} in {hint['source']}: {hint['twin_to_target_registers']} (discovery only; recompile and compare whole unit)")
        if not twins:
            continue
        t = twins[0]
        text = open(ROOT / verified[t]).read()
        m = re.search(rf'^[^\n;]*\bfunc_{t:08x}\s*\([^;{{]*\)\s*\n\{{.*?^\}}', text, re.S | re.M)
        if m:
            print(f'  twin func_{t:08x} in {verified[t]}:')
            print('    ' + m.group(0).replace('\n', '\n    '))
        diffs = []
        for i in range(0, min(e - a, extent(t) - t), 2):
            w1 = struct.unpack_from('<H', image, a + i - base)[0]
            w2 = struct.unpack_from('<H', image, t + i - base)[0]
            if w1 != w2:
                diffs.append(f'+{i:#x}: twin {w2:04x} target {w1:04x}')
        print('  differing words: ' + ('; '.join(diffs) if diffs else 'none in code (pool literals may differ)'))
    return 0


if __name__ == '__main__':
    sys.exit(main())
