#!/usr/bin/env python3
"""Per-character coverage of the pairing and the screen (ARCADE_DIFF.md 10).

    python3 -I coverage.py NAOMI_ROOT naomi.pkl ps2.pkl pairs.json screen.tsv [--hits N]

A character's NAOMI code is the range from its init function (the
per-character init table at 0x0C23BCD8) to the next character's; the
code before the first one (0x0C04C000..) is the CPU AI and shared state
code, and the code after the last (0x0C131600..0x0C18D000) the shared
projectile and effect actors.  Prints, per character: functions and bytes, paired functions and
bytes, screened units that are clean (score <= 1), units with a
difference on a confident pair (similarity >= 0.8, score > 1), and
doubtful pairs (similarity < 0.6).  With --hits, the N highest-scoring
confident differences.
"""
import csv
import json
import pickle
import struct
import sys

sys.path.insert(0, __import__('os').path.dirname(__file__))
from sh4idx import load_image, BASE  # noqa: E402


def main():
    root, npkl, ppkl, pj, tsv = sys.argv[1:6]
    nh = int(sys.argv[sys.argv.index('--hits') + 1]) if '--hits' in sys.argv else 0
    img = load_image(root)
    u32 = lambda a: struct.unpack_from('<I', img, a - BASE)[0]
    N = pickle.load(open(npkl, 'rb'))['funcs']
    J = json.load(open(pj))
    inits = sorted((u32(0x0C23BCD8 + 4 * i), i) for i in range(59))
    # after the last character (Servbot, 0x3A) the range holds the shared
    # projectile / effect actors (their PS2 twins are at 0x00328000..)
    bounds = ([(0x0C04C000, 'shared')] + [(a, '%02x' % i) for a, i in inits] +
              [(0x0C131600, 'effects'), (0x0C18D000, None)])
    rows = list(csv.DictReader(open(tsv), delimiter='\t'))
    out = []
    tot = [0] * 8
    for (lo, name), (hi, _) in zip(bounds, bounds[1:]):
        fs = [a for a in N if lo <= a < hi and N[a]['size'] >= 4]
        pa = [a for a in fs if '%08x' % a in J['pairs']]
        rr = [r for r in rows if lo <= int(r['naomi'], 16) < hi]
        clean = sum(1 for r in rr if float(r['score']) <= 1)
        conf = [r for r in rr if float(r['score']) > 1 and json.loads(r['diff'])['sim'] >= 0.8]
        doubt = sum(1 for r in rr if json.loads(r['diff'])['sim'] < 0.6 and float(r['score']) > 1)
        v = [len(fs), sum(N[a]['size'] for a in fs), len(pa), sum(N[a]['size'] for a in pa), len(rr), clean,
             len(conf), doubt]
        tot = [x + y for x, y in zip(tot, v)]
        out.append((name, lo, v, conf))
    print('| Char | NAOMI range | Functions | Paired | Bytes paired | Units | Clean | Diff (sim>=0.8) | Doubtful |')
    print('|---|---|---|---|---|---|---|---|---|')
    for name, lo, v, conf in out:
        print('| %s | 0x%08X | %d | %d | %.0f %% | %d | %d | %d | %d |' % (
            name, lo, v[0], v[2], 100.0 * v[3] / max(1, v[1]), v[4], v[5], v[6], v[7]))
    print('| all | | %d | %d | %.0f %% | %d | %d | %d | %d |' % (
        tot[0], tot[2], 100.0 * tot[3] / max(1, tot[1]), tot[4], tot[5], tot[6], tot[7]))
    if nh:
        allc = sorted(((float(r['score']), name, r) for name, lo, v, conf in out for r in conf),
                      key=lambda t: -t[0])[:nh]
        for s, name, r in allc:
            d = json.loads(r['diff'])
            d.pop('shape', None)
            d.pop('ok', None)
            print(name, r['naomi'], r['name'], s, json.dumps(d)[:300])


if __name__ == '__main__':
    main()
