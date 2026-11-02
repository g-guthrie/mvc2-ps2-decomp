#!/usr/bin/env python3
"""Screen paired NAOMI/PS2 functions for code differences (ARCADE_DIFF.md 10).

    python3 -I screen.py naomi.pkl ps2.pkl pairs.json PS2_ELF OUT.tsv [--min SCORE]

For every pair from pair.py it compares, after the compilers' usual
differences are removed:
  floats   the set of |float| constants (SH-4 literal pool or MOVA; EE
           lui+mtc1 or a .rodata load); 0 and 1 are ignored (FLDI0/FLDI1)
  offs     struct offsets >= 0xC0, NAOMI mapped to PS2 by the player-struct
           shift (+0x10 for 0x108..0x17B, +0x14 from 0x19C; 0x17C..0x19B
           and 0xC0..0x107 try 0, 4, 0x10, 0x14)
  calls    the multiset of callees, NAOMI callees translated by the pairs;
           unpaired callees compared by count only
  consts   small integer constants 2..0x7F used in compares or moves
           (a weak signal: the compilers materialise constants differently)
  shape    branch count and size ratio
and writes one line per pair with a score and the differences, highest
score first.  The hits are leads to read by hand, not verdicts.
"""
import bisect
import json
import pickle
import struct
import sys
from collections import Counter

sys.path.insert(0, __import__('os').path.dirname(__file__))
from pair import Elf  # noqa: E402

TRIVIAL_F = {0, 0x3F800000, 0x3F000000}


def shifts(o):
    if o < 0xC0:
        return (0,)
    if o < 0x108:
        return (0, 4, 0x10, 0x14)
    if o < 0x17C:
        return (0x10,)
    if o < 0x19C:
        return (0x10, 0x14, 0x20, 0x24)
    return (0x14,)


def fset(vals):
    return {v & 0x7FFFFFFF for v in vals if (v & 0x7FFFFFFF) not in TRIVIAL_F}


def f32(v):
    return struct.unpack('<f', struct.pack('<I', v & 0xFFFFFFFF))[0]


YS = 14.0 / 15.0   # PS2 vertical scale 448/224 = 2 against the NAOMI 480/224 = 15/7


def near(a, bs, ys=1.0):
    """a float equal to one of bs to a relative 1e-5 (folded constants
    round differently); ys scales a first (the PS2's vertical scale)"""
    x = f32(a) * ys
    return any(abs(x - f32(b)) <= 1e-5 * max(abs(x), 1e-6) for b in bs)


def compare(fa, fb, pair, elf):
    out = {}
    # floats
    fb_vals = list(fb['floats']) + [v for v in fb.get('ints', []) if 0x60 <= (v >> 23) & 0xFF <= 0x9F]
    # a lui alone (low half 0) also builds float bits for an integer store
    fb_loose = fb_vals + [v for v in fb.get('luis', []) if 0x60 <= (v >> 23) & 0xFF <= 0x9F]
    for r in fb.get('frefs', ()):
        v = elf.u32(r)
        if v is not None:
            fb_vals.append(v)
    na, nb = fset(fa['floats']), fset(fb_vals)
    only_n = sorted(x for x in na if not near(x, fset(fb_loose)))
    only_p = sorted(x for x in nb if not near(x, na))
    # EE soft-double constants: a lui/ori pair builds the high word of an
    # f64 (the EE build evaluates some expressions in double precision)
    def dhi(v):
        return struct.unpack('<d', struct.pack('<Q', (v & 0xFFFFFFFF) << 32))[0]
    dh = [x for x in only_p if any(abs(dhi(x) - f32(y)) <= 1e-4 * max(1.0, abs(f32(y))) for y in na)]
    if dh:
        out['f64'] = len(dh)
        only_p = [x for x in only_p if x not in dh]
        only_n = [y for y in only_n if not any(abs(dhi(x) - f32(y)) <= 1e-4 * max(1.0, abs(f32(y))) for x in dh)]
    # the PS2's 448-line vertical scale: NAOMI k*15/7 where the PS2 has k*2
    yn = [x for x in only_n if near(x, only_p, YS)]
    if yn:
        out['yscale'] = len(yn)
        only_n = [x for x in only_n if x not in yn]
        only_p = [x for x in only_p if not any(near(y, [x], YS) for y in yn)]
    if only_n or only_p:
        out['floats'] = (only_n, only_p)
    # offsets
    pb = {o for k, o in fb['offs'] if o >= 0xC0}
    pa = {o for k, o in fa['offs'] if o >= 0xC0} | {v for v in fa['w16'] if 0xC0 <= v < 0x600}
    miss_n = sorted(o for o in pa if not any(o + d in pb for d in shifts(o)) and o in {x for k, x in fa['offs']})
    expl = {o + d for o in pa for d in shifts(o)}
    miss_p = sorted(o for o in pb if o not in expl and o < 0x600)
    if miss_n or miss_p:
        out['offs'] = (miss_n, miss_p)
    # calls
    ca = Counter(pair.get(c, 'n?') for c in fa['calls'] if c is not None)
    cb = Counter(c if c in pair.values() else 'p?' for c in fb['calls'])
    cnt_a = Counter({k: v for k, v in ca.items() if k != 'n?'})
    cnt_b = Counter({k: v for k, v in cb.items() if k != 'p?'})
    # callee sets (either compiler may duplicate a call on two paths)
    d1 = Counter({k: v for k, v in cnt_a.items() if k not in cnt_b})
    d2 = Counter({k: v for k, v in cnt_b.items() if k not in cnt_a})
    ua, ub = ca.get('n?', 0), cb.get('p?', 0)
    if d1 or d2 or (ua == 0) != (ub == 0):
        out['calls'] = ({('%x' % k): v for k, v in d1.items()}, {('%x' % k): v for k, v in d2.items()}, ua, ub)
    # small constants
    used_as_off = {o for k, o in fa['offs']}
    ka = {v for v in fa['cmpimm'] + fa['imm'] if 2 <= v <= 0x7F and v not in used_as_off}
    kb = {v for v in fb['cmpimm'] + fb['imm'] if 2 <= v <= 0x7F}
    if ka ^ kb:
        out['consts'] = (sorted(ka - kb), sorted(kb - ka))
    # shape
    out['shape'] = (fa['branches'], fb['branches'], fa['size'], fb['n'] * 4)
    # similarity of the two token sets: a low value means a doubtful pair
    # rather than a code difference
    A = {('o', o + next((d for d in shifts(o) if o + d in pb), shifts(o)[0])) for k, o in fa['offs'] if o >= 8}
    B = {('o', o) for k, o in fb['offs'] if o >= 8}
    A |= {('c', k) for k in cnt_a} | {('f', x) for x in na} | {('k', v) for v in ka}
    B |= {('c', k) for k in cnt_b} | {('f', x) for x in nb if any(near(y, [x]) for y in na) or True} | {('k', v) for v in kb}
    out['sim'] = round(len(A & B) / max(1, len(A | B)), 2)
    return out


def score(d):
    s = 0
    if 'floats' in d:
        s += 3 * (len(d['floats'][0]) + len(d['floats'][1]))
    if 'offs' in d:
        s += 2 * (len(d['offs'][0]) + len(d['offs'][1]))
    if 'calls' in d:
        c = d['calls']
        s += 3 * (len(c[0]) + len(c[1])) + (2 if (c[2] == 0) != (c[3] == 0) else 0)
    if 'consts' in d:
        s += 0.5 * (len(d['consts'][0]) + len(d['consts'][1]))
    ba, bb, sa, sb = d['shape']
    s += abs(ba - bb) * 0.5
    return s


def chain(pairs):
    """The longest run of pairs in the same address order on both sides
    (the per-file layout both compilers kept)."""
    ps = sorted(pairs)
    tails, idx, prev = [], [], [-1] * len(ps)
    for i, (a, b) in enumerate(ps):
        k = bisect.bisect_left(tails, b)
        if k == len(tails):
            tails.append(b)
            idx.append(i)
        else:
            tails[k], idx[k] = b, i
        prev[i] = idx[k - 1] if k else -1
    out, i = [], idx[-1] if idx else -1
    while i >= 0:
        out.append(ps[i])
        i = prev[i]
    return out[::-1]


def merged(funcs, keys):
    m = {'floats': [], 'frefs': [], 'ints': [], 'luis': [], 'offs': [], 'w16': [], 'calls': [], 'cmpimm': [],
         'imm': [], 'branches': 0,
         'size': 0, 'n': 0}
    for k in keys:
        f = funcs[k]
        for x in ('floats', 'frefs', 'ints', 'luis', 'offs', 'w16', 'calls', 'cmpimm', 'imm'):
            m[x] += f.get(x, [])
        m['branches'] += f['branches']
        m['size'] += f.get('size', 0)
        m['n'] += f['n']
    return m


def ok(N, P, ka, kb):
    """Sizes compatible with the same source (EE code is 1.1 to 2.3 times
    the SH-4 bytes for this game; small functions vary more)."""
    sa = sum(N[k]['size'] for k in ka)
    sb = sum(P[k]['n'] * 4 for k in kb)
    if sa < 64 and sb < 160:
        return True
    return 0.9 <= (sb + 16) / (sa + 16) <= 2.6


def units(N, P, pair):
    """Comparison units: consecutive pairs of the monotonic chain bound a
    NAOMI span and a PS2 span (so a switch the EE build split into case
    functions, or a function either compiler split, is compared whole);
    pairs off the chain are compared function to function."""
    ch = chain(pair.items())
    ns, ps = sorted(N), sorted(P)
    on = set(a for a, b in ch)
    out = []
    for i, (a, b) in enumerate(ch):
        a1, b1 = ch[i + 1] if i + 1 < len(ch) else (a + 1, b + 1)
        ka = ns[bisect.bisect_left(ns, a):bisect.bisect_left(ns, a1)]
        kb = ps[bisect.bisect_left(ps, b):bisect.bisect_left(ps, b1)]
        if len(ka) > 40 or len(kb) > 40:   # a long gap: compare the pair alone
            ka, kb = [a], [b]
        if not ok(N, P, [a], [b]) and ok(N, P, ka, kb):
            out.append((a, b, ka, kb))
        else:
            out.append((a, b, [a], [b]))
    for a, b in pair.items():
        if a not in on:
            out.append((a, b, [a], [b]))
    return out


def main():
    npkl, ppkl, pj, elf, out = sys.argv[1:6]
    mn = float(sys.argv[sys.argv.index('--min') + 1]) if '--min' in sys.argv else 0
    N = pickle.load(open(npkl, 'rb'))['funcs']
    P = pickle.load(open(ppkl, 'rb'))['funcs']
    J = json.load(open(pj))
    pair = {int(a, 16): int(b, 16) for a, b in J['pairs'].items()}
    e = Elf(elf)
    rows = []
    for a, b, ka, kb in units(N, P, pair):
        d = compare(merged(N, ka), merged(P, kb), pair, e)
        s = score(d)
        d['ok'] = ok(N, P, ka, kb)
        if not d['ok']:
            s = -1
        if s >= mn:
            rows.append((s, a, b, '%s+%d/%d' % (P[b]['name'], len(ka), len(kb)), J['how'].get('%08x' % a, ''), d))
    rows.sort(key=lambda r: (-r[0], r[1]))

    def fmt(v):
        return json.dumps(v, default=lambda x: x) if not isinstance(v, str) else v
    with open(out, 'w') as fh:
        fh.write('score\tnaomi\tps2\tname\thow\tdiff\n')
        for s, a, b, n, how, d in rows:
            dd = {k: v for k, v in d.items()}
            if 'floats' in dd:
                dd['floats'] = [['%08x' % x for x in dd['floats'][0]], ['%08x' % x for x in dd['floats'][1]]]
            if 'offs' in dd:
                dd['offs'] = [['%x' % x for x in dd['offs'][0]], ['%x' % x for x in dd['offs'][1]]]
            fh.write('%.1f\t%08x\t%08x\t%s\t%s\t%s\n' % (s, a, b, n, how, fmt(dd)))
    print(len(rows), 'units;', sum(1 for r in rows if r[0] < 0), 'not comparable (sizes);',
          sum(1 for r in rows if 0 <= r[0] <= 1), 'clean (score <= 1)')


if __name__ == '__main__':
    main()
