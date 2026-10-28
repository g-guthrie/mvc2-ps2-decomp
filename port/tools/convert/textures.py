#!/usr/bin/env python3
"""Textures from the user's ISO -> PNG (no asset bytes embedded).

  textures.py ISO OUTDIR font                 /FONT8_8.TM2
  textures.py ISO OUTDIR afs ID [ID...]        AFS02 entries: TIM2 files, or
                                                *TEX.BIN packs (LZ16 or raw)
TEX pack (after func_00176230 LZ16 decode, relocated by func_0016F4D0):
  16-byte records {s16 w(>0), u16 h, u32 flags, u32 offset, s32 attr},
  terminated by w <= 0. flags>>16 = kind (func_00415250): 0 = func_00415B00,
  1 = TIM2 (func_00418200), 2 = func_00418570, 3 = func_00418410.
  offset is relative to the start of the decoded pack.
"""
import os, struct, sys
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from iso import Iso
from afs import Afs
import tim2
import mvc2_lz16


def records(d):
    q = 0
    out = []
    while q + 16 <= len(d) and struct.unpack_from('<h', d, q)[0] > 0:
        out.append(struct.unpack_from('<hHIIi', d, q))
        q += 16
    return out


def table12(d):
    """func_00416180 container: 12-byte entries {s32 tag (<0 ends), u32 size,
    u32 offset from the container base}."""
    q = 0
    out = []
    while q + 12 <= len(d):
        tag, size, off = struct.unpack_from('<iII', d, q)
        if tag < 0:
            return out
        if off >= len(d) or off + size > len(d) + 16:
            return []
        out.append((tag, size, off))
        q += 12
    return []


def looks_like_pack(d):
    r = records(d[:4096])
    return bool(r) and all(fl >> 16 in (0, 1, 2, 3) and off < len(d)
                           for _, _, fl, off, _ in r) and \
        any(fl >> 16 == 1 and d[off:off + 4] == b'TIM2' for _, _, fl, off, _ in r)


def decode_pack(raw):
    if looks_like_pack(raw):
        return raw, False
    return mvc2_lz16.decode(raw), True


def convert_entry(a, idx, outdir):
    raw = a.read(idx)
    name = a.name(idx)
    stem = os.path.join(outdir, '%03d_%s' % (idx, os.path.splitext(name)[0]))
    if raw[:4] == b'TIM2':
        for n, p in zip(tim2.write_pngs(tim2.parse(raw), stem), tim2.parse(raw)):
            print(n, p['w'], p['h'], 'type', p['imageType'], 'clut', p['clutColors'])
        return
    d, packed = decode_pack(raw)
    recs = records(d)
    if not recs:
        t = table12(d)
        if t:
            print('%s: %s %d -> %d bytes, 12-byte table, %d entries (func_00416180)' % (
                name, 'LZ16' if packed else 'raw', len(raw), len(d), len(t)))
            os.makedirs(stem, exist_ok=True)
            man = []
            for i, (tag, size, off) in enumerate(t):
                line = '%3d tag=%d size=%#x off=%#x' % (i, tag, size, off)
                if d[off:off + 4] == b'TIM2':
                    pics = tim2.parse(d, off)
                    tim2.write_pngs(pics, os.path.join(stem, '%03d' % i))
                    line += ' TIM2 %dx%d type=%d clut=%d' % (pics[0]['w'], pics[0]['h'],
                                                             pics[0]['imageType'], pics[0]['clutColors'])
                else:
                    line += ' magic=%s' % d[off:off + 4].hex()
                man.append(line)
            open(os.path.join(stem, 'manifest.txt'), 'w').write('\n'.join(man) + '\n')
            print('\n'.join(man))
            return
    print('%s: %s %d -> %d bytes, %d records' % (name, 'LZ16' if packed else 'raw', len(raw), len(d), len(recs)))
    os.makedirs(stem, exist_ok=True)
    man = []
    for i, (w, h, fl, off, attr) in enumerate(recs):
        kind = fl >> 16
        line = '%3d w=%d h=%d flags=%#x kind=%d off=%#x attr=%#x' % (i, w, h, fl, kind, off, attr)
        if kind == 1 and d[off:off + 4] == b'TIM2':
            pics = tim2.parse(d, off)
            tim2.write_pngs(pics, os.path.join(stem, '%03d' % i))
            p = pics[0]
            line += ' TIM2 %dx%d type=%d clut=%d' % (p['w'], p['h'], p['imageType'], p['clutColors'])
        man.append(line)
    open(os.path.join(stem, 'manifest.txt'), 'w').write('\n'.join(man) + '\n')
    print('\n'.join(man[:8]) + ('\n...' if len(man) > 8 else ''))


if __name__ == '__main__':
    iso = Iso(sys.argv[1]); outdir = sys.argv[2]; cmd = sys.argv[3]
    os.makedirs(outdir, exist_ok=True)
    if cmd == 'font':
        pics = tim2.parse(iso.read('/FONT8_8.TM2'))
        for n, p in zip(tim2.write_pngs(pics, os.path.join(outdir, 'FONT8_8')), pics):
            print(n, p['w'], p['h'], 'type', p['imageType'], 'clut', hex(p['clutType']), p['clutColors'])
    elif cmd == 'afs':
        a = Afs(iso, 2)
        for s in sys.argv[4:]:
            try:
                convert_entry(a, int(s), outdir)
            except Exception as e:  # unknown container/compression: report, go on
                print('%s: not converted (%s: %s)' % (a.name(int(s)), type(e).__name__, e))
