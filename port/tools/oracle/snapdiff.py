#!/usr/bin/env python3
"""Word diff of two raw EE BSS snapshots (--snap / MVC2_STATE_SNAP), with the
nearest EE symbol (config/symbol_addrs.txt) of each differing word.

  snapdiff.py PORT.snap ORACLE.snap [--max N] [--from ADDR] [--to ADDR]
A word whose untranslated port value (PORT.snap.raw) equals the oracle's
is not a difference.
"""
import argparse
import bisect
import os
import re
import struct

LO = 0x004C2580
ROOT = os.path.dirname(os.path.abspath(__file__)) + '/../../..'


def symbols():
    syms = {}
    for fn in ('config/symbol_addrs.txt',):
        for ln in open(os.path.join(ROOT, fn)):
            m = re.match(r'(\w+)\s*=\s*0x([0-9A-Fa-f]+)', ln)
            if m:
                a = int(m.group(2), 16)
                if LO <= a < 0x02000000:
                    syms.setdefault(a, m.group(1))
    keys = sorted(syms)
    return keys, syms


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('port')
    ap.add_argument('oracle')
    ap.add_argument('--max', type=int, default=200)
    ap.add_argument('--base', nargs=2, metavar=('PORT', 'ORACLE'),
                    help='ignore words that already differ in this earlier pair of snapshots')
    ap.add_argument('--from', dest='lo', type=lambda x: int(x, 0), default=0)
    ap.add_argument('--to', dest='hi', type=lambda x: int(x, 0), default=1 << 32)
    a = ap.parse_args()
    p = open(a.port, 'rb').read()
    o = open(a.oracle, 'rb').read()
    raw = open(a.port + '.raw', 'rb').read() if os.path.exists(a.port + '.raw') else None
    keys, syms = symbols()
    base = None
    if a.base:
        bp = open(a.base[0], 'rb').read()
        bo = open(a.base[1], 'rb').read()
        braw = open(a.base[0] + '.raw', 'rb').read() if os.path.exists(a.base[0] + '.raw') else None
        base = set(off for off in range(0, min(len(bp), len(bo)) - 3, 4)
                   if bp[off:off + 4] != bo[off:off + 4] and (braw is None or braw[off:off + 4] != bo[off:off + 4]))
    n = 0
    runs = []
    for off in range(0, min(len(p), len(o)) - 3, 4):
        if base is not None and off in base:
            continue
        if p[off:off + 4] != o[off:off + 4] and (raw is None or raw[off:off + 4] != o[off:off + 4]):
            addr = LO + off
            if runs and runs[-1][1] == addr:
                runs[-1][1] = addr + 4
                runs[-1][2] += 1
            else:
                runs.append([addr, addr + 4, 1])
    print(f'{sum(r[2] for r in runs)} words differ in {len(runs)} runs')
    runs = [r for r in runs if a.lo <= r[0] < a.hi]
    for lo, hi, cnt in runs[:a.max]:
        i = bisect.bisect_right(keys, lo) - 1
        s = f'{syms[keys[i]]}+0x{lo - keys[i]:X}' if i >= 0 else '?'
        pv, = struct.unpack_from('<I', p, lo - LO)
        ov, = struct.unpack_from('<I', o, lo - LO)
        print(f'0x{lo:08X}..0x{hi:08X} ({cnt:5d} words) {s:32s} port {pv:08X} oracle {ov:08X}')


if __name__ == '__main__':
    main()
