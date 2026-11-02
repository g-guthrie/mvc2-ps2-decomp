#!/usr/bin/env python3
"""Pair NAOMI functions with PS2 functions (ARCADE_DIFF.md section 10).

    python3 -I pair.py NAOMI_ROOT naomi.pkl ps2.pkl PS2_ELF OUT.json

Inputs: the indexes of sh4idx.py and mipsidx.py, the NAOMI decomp checkout
(its ROM, read at run time) and the PS2 executable (SLUS_204.86, read at run
time for data tables).  Output: {"pairs": {naomi_hex: ps2_hex}, "how": ...,
"data": {naomi_hex: ps2_hex}} of addresses only.

Method, strongest evidence first:
  1. Seeds: the per-character init tables (NAOMI 0x0C23BCD8, PS2
     0x00448D00, 59 entries) and the twins read by hand in section 7/10.
  2. Tables: a paired data address whose words on both sides are code or
     data pointers is walked in step; equal-kind entries are paired.
  3. Call graph: the callee sequences of a paired function are aligned
     (anchored on already-paired callees; gaps of equal length are paired
     in order).  Same for the data references and function pointers.
  4. Repeat until nothing new.
A candidate is accepted only if neither side is already paired (first
evidence wins; conflicts are counted).
"""
import bisect
import json
import math
import pickle
import struct
import sys
from collections import deque

sys.path.insert(0, __import__('os').path.dirname(__file__))
from sh4idx import load_image, BASE  # noqa: E402

# Hand-read twins (ARCADE_DIFF.md 7, 10.1)
SEEDS = [
    (0x0C039928, 0x00179590), (0x0C04B61C, 0x00190710), (0x0C048274, 0x0018B500),
    (0x0C04221C, 0x001823C0), (0x0C04231C, 0x001825F0), (0x0C042414, 0x001827B0),
    (0x0C02849A, 0x00174170), (0x0C028394, 0x00170C30), (0x0C02AB50, 0x003D7030),
    (0x0C046700, 0x00188860), (0x0C03B74C, 0x0017BDA0), (0x0C036DB8, 0x00327570),
    (0x0C0411C8, 0x00180A30), (0x0C04CFB4, 0x00168C10),
    # CPU AI driver helpers (read side by side, ARCADE_DIFF.md 10.5)
    (0x0C04D0DA, 0x00168D90), (0x0C04D17C, 0x00168E80), (0x0C04D5E6, 0x001695A0),
    (0x0C04D63C, 0x00169600), (0x0C04DA30, 0x00169C30),
    # Abyss (third form) per-frame update, vtable slot 24 (10.5)
    (0x0C0BB598, 0x0027FBB0),
    # per-frame team routine and its draw-priority sort (10.5)
    (0x0C0362F4, 0x00326700), (0x0C041B8A, 0x001817E0), (0x0C039580, 0x001710C0),
]
TABLE_SEEDS = [(0x0C23BCD8, 0x00448D00, 59)]


class Elf:
    def __init__(self, path):
        b = open(path, 'rb').read()
        phoff, = struct.unpack_from('<I', b, 0x1C)
        phnum, = struct.unpack_from('<H', b, 0x2C)
        self.segs = []
        for i in range(phnum):
            t, off, va, pa, fs, ms = struct.unpack_from('<6I', b, phoff + 32 * i)
            if t == 1:
                self.segs.append((va, va + fs, b[off:off + fs]))

    def u32(self, a):
        for s, e, d in self.segs:
            if s <= a and a + 4 <= e:
                return struct.unpack_from('<I', d, a - s)[0]
        return None


def dedupe(seq):
    out = []
    for x in seq:
        if x is not None and (not out or out[-1] != x):
            out.append(x)
    return out


class Pairer:
    def __init__(self, nroot, npkl, ppkl, elf):
        self.img = load_image(nroot)
        self.N = pickle.load(open(npkl, 'rb'))
        self.P = pickle.load(open(ppkl, 'rb'))
        self.elf = Elf(elf)
        self.nf = self.N['funcs']
        self.pf = self.P['funcs']
        self.pair, self.rpair, self.how = {}, {}, {}
        self.dpair, self.rdpair = {}, {}
        self.q = deque()
        self.conflicts = 0
        for f in self.pf.values():   # PS2 refs that are function starts are function pointers
            f['fnptrs'] = [r for r in f['refs'] if r in self.pf]
            f['drefs'] = [r for r in f['refs'] if r not in self.pf]
        for f in self.nf.values():
            f['drefs'] = list(f['refs'])

    def nu32(self, a):
        if BASE <= a and a + 4 <= BASE + len(self.img):
            return struct.unpack_from('<I', self.img, a - BASE)[0]
        return None

    def nkind(self, v):
        if v in self.nf:
            return 'x' if self.nf[v].get('unmapped') else 'f'
        if v == 0:
            return '0'
        if 0x0C000000 <= v < 0x0D000000:
            return 'd'
        return None

    def pkind(self, v):
        if v in self.pf:
            return 'f'
        if v == 0:
            return '0'
        if 0x00100000 <= v < 0x02000000:
            return 'd'
        return None

    def add(self, a, b, how):
        if a in self.pair or b in self.rpair:
            if self.pair.get(a) != b:
                self.conflicts += 1
            return False
        if a not in self.nf or b not in self.pf:
            return False
        self.pair[a], self.rpair[b], self.how[a] = b, a, how
        self.q.append(('f', a, b))
        return True

    def addd(self, a, b):
        if a in self.dpair or b in self.rdpair:
            return False
        self.dpair[a], self.rdpair[b] = b, a
        self.q.append(('d', a, b))
        return True

    def walk_table(self, a, b, n=None, how='table'):
        if n is None:
            # the PS2 asm labels each data object: walk to its end
            end = self.P['tables'].get(b)
            if end is None:
                return 0
            n = (end - b) // 4
            loose = True
        else:
            loose = False
        i = miss = 0
        while i < (n or 1024):
            va, vb = self.nu32(a + 4 * i), self.elf.u32(b + 4 * i)
            if va is None or vb is None:
                break
            ka, kb = self.nkind(va), self.pkind(vb)
            if ka == 'x' and kb in ('f', 'd'):
                ka = kb
            if loose and (ka is None or kb is None or ka != kb):
                miss += 1
                if miss > 2 or ka is None or kb is None:
                    break
                i += 1
                continue
            miss = 0
            if ka == 'f' and kb == 'f':
                self.add(va, vb, how)
            elif ka == 'd' and kb == 'd':
                self.addd(va, vb)
            i += 1
        return i

    def align(self, xs, ys, mp, cb):
        """Pair the elements of xs (NAOMI) and ys (PS2) between anchors."""
        if not xs or not ys:
            return
        anchors = [(-1, -1)]
        j0 = 0
        for i, x in enumerate(xs):
            t = mp.get(x)
            if t is None:
                continue
            for j in range(j0, len(ys)):
                if ys[j] == t:
                    anchors.append((i, j))
                    j0 = j + 1
                    break
        anchors.append((len(xs), len(ys)))
        for (i0, j0), (i1, j1) in zip(anchors, anchors[1:]):
            gx, gy = xs[i0 + 1:i1], ys[j0 + 1:j1]
            if gx and len(gx) == len(gy):
                for x, y in zip(gx, gy):
                    cb(x, y)

    def step(self, kind, a, b):
        if kind == 'f':
            fa, fb = self.nf[a], self.pf[b]
            ca = dedupe([c for c in fa['calls'] if c in self.nf])
            cb = dedupe([c for c in fb['calls'] if c in self.pf])
            self.align(ca, cb, self.pair, lambda x, y: self.add(x, y, 'call:%x' % a))
            fa_ = dedupe(fa['fnptrs'])
            fb_ = dedupe(fb['fnptrs'])
            self.align(fa_, fb_, self.pair, lambda x, y: self.add(x, y, 'fnptr:%x' % a))
            da = dedupe(sorted(set(fa['drefs']), key=fa['drefs'].index))
            db = dedupe(sorted(set(fb['drefs']), key=fb['drefs'].index))
            self.align(da, db, self.dpair, self.addd)
        else:
            self.walk_table(a, b, how='data:%x' % a)

    def by_callees(self):
        """Pair unpaired functions whose paired callees agree: for a PS2
        function with at least two paired callees, the NAOMI function that
        calls the most of their twins, if it is the unique best and covers
        at least 60 % of both callee sets."""
        callers = {}
        for a, f in self.nf.items():
            if a in self.pair:
                continue
            for c in set(f['calls']):
                callers.setdefault(c, set()).add(a)
        got = 0
        for b, g in self.pf.items():
            if b in self.rpair:
                continue
            mc = {self.rpair[c] for c in g['calls'] if c in self.rpair}
            if len(mc) < 2:
                continue
            score = {}
            for c in mc:
                for a in callers.get(c, ()):
                    score[a] = score.get(a, 0) + 1
            if not score:
                continue
            best = sorted(score.items(), key=lambda kv: -kv[1])
            a, s = best[0]
            if len(best) > 1 and best[1][1] == s:
                continue
            na = len({c for c in self.nf[a]['calls'] if c in self.pair})
            if s >= 2 and s >= 0.6 * len(mc) and s >= 0.6 * max(na, 1):
                if self.add(a, b, 'callees'):
                    got += 1
        return got

    def gap_fill(self):
        """Address order: both builds kept each source file's function
        order.  Between consecutive pairs of the monotonic chain, align the
        unpaired functions of the two gaps by size (EE bytes ~ 1.5 x SH-4
        bytes) with a DP that may skip a function on either side; accept
        aligned pairs whose sizes agree within a factor of 2."""
        ps = sorted(self.pair.items())
        tails, idx, prev = [], [], [-1] * len(ps)
        for i, (a, b) in enumerate(ps):
            k = bisect.bisect_left(tails, b)
            if k == len(tails):
                tails.append(b)
                idx.append(i)
            else:
                tails[k], idx[k] = b, i
            prev[i] = idx[k - 1] if k else -1
        ch, i = [], idx[-1] if idx else -1
        while i >= 0:
            ch.append(ps[i])
            i = prev[i]
        ch.reverse()
        ns, pss = sorted(self.nf), sorted(self.pf)
        got = 0
        lg = lambda x: math.log2(x + 24)
        for (a0, b0), (a1, b1) in zip(ch, ch[1:]):
            ga = [x for x in ns[bisect.bisect_right(ns, a0):bisect.bisect_left(ns, a1)]
                  if x not in self.pair and self.nf[x]['size'] >= 4]
            gb = [x for x in pss[bisect.bisect_right(pss, b0):bisect.bisect_left(pss, b1)]
                  if x not in self.rpair]
            if not ga or not gb or len(ga) > 60 or len(gb) > 60:
                continue
            sa = [lg(self.nf[x]['size'] * 1.5) for x in ga]
            sb = [lg(self.pf[x]['n'] * 4) for x in gb]
            n, m = len(ga), len(gb)
            INF = 1e9
            D = [[INF] * (m + 1) for _ in range(n + 1)]
            B = [[None] * (m + 1) for _ in range(n + 1)]
            D[0][0] = 0
            for i in range(n + 1):
                for j in range(m + 1):
                    if D[i][j] >= INF:
                        continue
                    if i < n and D[i][j] + 1.0 < D[i + 1][j]:
                        D[i + 1][j], B[i + 1][j] = D[i][j] + 1.0, (i, j, 0)
                    if j < m and D[i][j] + 1.0 < D[i][j + 1]:
                        D[i][j + 1], B[i][j + 1] = D[i][j] + 1.0, (i, j, 0)
                    if i < n and j < m:
                        c = abs(sa[i] - sb[j])
                        if D[i][j] + c < D[i + 1][j + 1]:
                            D[i + 1][j + 1], B[i + 1][j + 1] = D[i][j] + c, (i, j, 1)
            i, j = n, m
            while (i, j) != (0, 0):
                pi, pj, mt = B[i][j]
                if mt and abs(sa[pi] - sb[pj]) <= 1.0:
                    if self.add(ga[pi], gb[pj], 'order'):
                        got += 1
                i, j = pi, pj
        return got

    def run(self):
        for a, b, n in TABLE_SEEDS:
            self.addd(a, b)
            self.walk_table(a, b, n, how='init-table')
        starts = sorted(self.nf)
        for a, b in SEEDS:
            if a not in self.nf:   # an address inside the function: its entry
                a = starts[bisect.bisect_right(starts, a) - 1]
            self.add(a, b, 'seed')
        while True:
            while self.q:
                self.step(*self.q.popleft())
            if not self.by_callees() and not self.gap_fill():
                break


def main():
    nroot, npkl, ppkl, elf, out = sys.argv[1:6]
    p = Pairer(nroot, npkl, ppkl, elf)
    p.run()
    json.dump({'pairs': {'%08x' % a: '%08x' % b for a, b in p.pair.items()},
               'how': {'%08x' % a: h for a, h in p.how.items()},
               'data': {'%08x' % a: '%08x' % b for a, b in p.dpair.items()}}, open(out, 'w'), indent=0)
    print(len(p.pair), 'function pairs,', len(p.dpair), 'data pairs,', p.conflicts, 'conflicts')


if __name__ == '__main__':
    main()
