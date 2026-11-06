#!/usr/bin/env python3
"""Propose translation-unit extents: runs of reviewed code and pools that no
branch crosses.

SHC flushes a literal pool mid-file, so one retail unit holds several pools.
A boundary is a pool that code before it does not branch over and that code
after it does not call back across with bsr or bra. Spans between boundaries
that start with a real function start are candidate units.

    python3 tools/unit_spans.py --min 200 --max 1400 --limit 40
    python3 tools/unit_spans.py --start 0x0c025528 --explain
"""
import argparse
import bisect
import json
import struct

from core import ROOT, load, number, verify_rom
from pool_clusters import pc_relative_target


def branch_target(word, pc):
    if word >> 12 in (0xa, 0xb):
        d = word & 0xfff
        return pc + 4 + (d - 0x1000 if d & 0x800 else d) * 2
    if word >> 8 in (0x89, 0x8b, 0x8d, 0x8f):
        d = word & 0xff
        return pc + 4 + (d - 0x100 if d & 0x80 else d) * 2
    return None


def owned_code_sections(units):
    return [(number(p['address']), number(p['address']) + number(p['size']))
            for u in units for p in u['sections'] if p['kind'] == 'code']


def span_evidence(image, base, ranges, units, start, size):
    """Show the pools, owners, and control-flow/literal dependencies of a span."""
    end = start + size
    parts = [(lo, lo + n, kind) for lo, n, kind in ranges
             if lo < end and lo + n > start]
    pools = [(lo, hi) for lo, hi, kind in parts if kind == 'data']
    pool_rows = []
    for lo, hi in pools:
        owners = sorted({u['id'] for u in units for p in u['sections']
                         if p['kind'] == 'data' and number(p['address']) < hi
                         and number(p['address']) + number(p['size']) > lo})
        pool_rows.append({'address': f'0x{lo:08x}', 'size': hi - lo, 'owners': owners})
    dependencies = []
    for lo, hi, kind in parts:
        if kind != 'code':
            continue
        for pc in range(max(lo, start), min(hi, end), 2):
            word = struct.unpack_from('<H', image, pc - base)[0]
            branch = branch_target(word, pc)
            literal = pc_relative_target(word, pc)
            for edge_kind, target in [('branch', branch),
                                      ('literal', literal[0] if literal else None)]:
                if target is None:
                    continue
                crossed = [f'0x{a:08x}' for a, b in pools
                           if (pc < a <= target or target < b <= pc)]
                if crossed or not start <= target < end:
                    dependencies.append({'kind': edge_kind, 'source': f'0x{pc:08x}',
                                         'target': f'0x{target:08x}',
                                         'crossed_pools': crossed,
                                         'external': not start <= target < end})
    from boundaries import BoundaryIndex
    audit = BoundaryIndex(image, base, ranges).audit(
        [{'kind': 'code', 'address': start, 'size': size}], [start])
    return {'pools': pool_rows, 'dependencies': dependencies, 'boundary_audit': audit}


def spans(image, base, ranges, owned):
    merged = []
    for lo, size, kind in sorted(ranges, key=lambda r: r[0]):
        if merged and kind == 'data' and merged[-1][2] == 'data' and merged[-1][0] + merged[-1][1] == lo:
            merged[-1] = (merged[-1][0], merged[-1][1] + size, kind)
        else:
            merged.append((lo, size, kind))
    ranges = merged
    words = lambda lo, hi: [struct.unpack_from('<H', image, a - base)[0] for a in range(lo, hi, 2)]
    # Branches and PC-relative loads both tie code to bytes across a pool.
    edges = []
    incoming_branches = []
    literal_edges = []
    for lo, size, kind in ranges:
        if kind != 'code':
            continue
        for i, w in enumerate(words(lo, lo + size)):
            pc = lo + 2 * i
            t = branch_target(w, pc)
            if t is not None:
                edges.append((pc, t))
                # A call may enter a new function at its first instruction.
                # Any other branch into a proposal joins its control flow to
                # earlier code, even when a pool or mapping gap separates it.
                incoming_branches.append((t, pc, w >> 12 == 0xb))
            literal = pc_relative_target(w, pc)
            if literal is not None:
                edges.append((pc, literal[0]))
                literal_edges.append((literal[0], pc))
    literal_edges.sort()
    incoming_branches.sort()
    # boundary candidates: each data range end (pool end) and start
    result = []
    i = 0
    while i < len(ranges):
        lo, size, kind = ranges[i]
        if kind != 'code':
            i += 1
            continue
        # a unit start: previous range is data or previous code ends with rts/delay
        if i and ranges[i - 1][2] == 'code':
            plo, psize, _ = ranges[i - 1]
            tail = words(plo + psize - 4, plo + psize) if psize >= 4 else []
            if 0x000b not in tail and not any(w >> 12 == 0xa for w in tail):
                i += 1
                continue
        start, j = lo, i
        closed = False
        previous_end = lo
        while j < len(ranges):
            rlo, rsize, rkind = ranges[j]
            if rlo != previous_end:
                break  # An unreviewed gap cannot belong to a proposed unit.
            end = rlo + rsize
            previous_end = end
            j += 1
            if rkind != 'data':
                continue
            # pool ends at `end`: does anything cross it?
            crossing = any(((a < end <= t) or (t < end <= a)) for a, t in edges
                           if a >= start and t >= start)
            if not crossing:
                closed = True
                break
        if not closed:
            i = max(j, i + 1)
            continue
        end = ranges[j - 1][0] + ranges[j - 1][1]
        # A reader before this start still owns a literal in the proposed
        # extent. The unit must start earlier, even if a gap or prior owner
        # prevented the earlier scan from reaching this pool.
        first = bisect.bisect_left(literal_edges, (start, -1))
        last = bisect.bisect_left(literal_edges, (end, -1))
        incoming_literal = any(pc < start for _, pc in literal_edges[first:last])
        first_branch = bisect.bisect_left(incoming_branches, (start, -1))
        last_branch = bisect.bisect_left(incoming_branches, (end, -1))
        incoming_branch = any(pc < start and (not call or target != start)
                              for target, pc, call
                              in incoming_branches[first_branch:last_branch])
        if ranges[j - 1][2] == 'data' and not incoming_literal and not incoming_branch:
            result.append((start, end - start))
        i = j
    from boundaries import BoundaryIndex
    index = BoundaryIndex(image, base, ranges)
    return [(s, n) for s, n in result
            if not any(o_lo < s + n and o_hi > s for o_lo, o_hi in owned)
            and not index.audit([{'kind': 'code', 'address': s, 'size': n}], [s])['issues']]


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('--min', type=int, default=200)
    parser.add_argument('--max', type=int, default=1400)
    parser.add_argument('--limit', type=int, default=50)
    parser.add_argument('--below', type=number, default=0x0c1e9000, help='only spans below this address (game code)')
    parser.add_argument('--start', type=number, help='show only the proposal at this address')
    parser.add_argument('--json', action='store_true')
    parser.add_argument('--explain', action='store_true', help='JSON with pool ownership and branch/literal dependencies')
    args = parser.parse_args()
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    image = program[offset:offset + size]
    ranges = [(number(r['address']), number(r['size']), r['kind']) for r in load(ROOT / 'config/mapping.json')['ranges']]
    # Registered data pools can be released and reassigned when a C unit is
    # registered. Only existing code ownership makes a span unavailable.
    units = load(ROOT / 'config/units.json')
    owned = owned_code_sections(units)
    found = [(s, n) for s, n in spans(image, base, ranges, owned)
             if (args.start is not None or args.min <= n <= args.max)
             and s < args.below and (args.start is None or s == args.start)]
    found = found[:args.limit]
    if args.explain:
        print(json.dumps([{'start': f'0x{s:08x}', 'size': n,
                           **span_evidence(image, base, ranges, units, s, n)}
                          for s, n in found], indent=2))
    elif args.json:
        print(json.dumps([{'start': f'0x{s:08x}', 'size': n} for s, n in found]))
    else:
        for s, n in found:
            print(f'0x{s:08x} size {n}')
    return 0


if __name__ == '__main__':
    main()
