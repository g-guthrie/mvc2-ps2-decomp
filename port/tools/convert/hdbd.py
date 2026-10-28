#!/usr/bin/env python3
"""AFS01 sound bank (Sony IECS HD + BD) -> one WAV per VAG sample.

No asset bytes embedded. Layout of an AFS01 entry:
  0x00: up to 8 x {u32 offset, u32 size} (zero pairs = unused); seen:
        [0] HD (IECS Vers/Head/Vagi/Smpl/Sset/Prog), [1] BD (raw SPU2 ADPCM),
        [2],[3] two further blocks (not decoded; sequence/map data [inferred]).
HD chunks: 'IECS' + reversed tag ('sreV','daeH','igaV','lpmS','tesS','gorP'),
  u32 chunkSize, ...
  Head: +0x08 chunkSize, +0x0C hdSize, +0x10 bdSize, +0x14 progOfs,
        +0x18 ssetOfs, +0x1C smplOfs, +0x20 vagiOfs, rest 0xFFFFFFFF.
  Vagi/Smpl/Sset/Prog: +0x08 chunkSize, +0x0C maxIndex, +0x10 u32
        offsets[maxIndex+1] (relative to the chunk start).
  Vagi entry (8 bytes): u32 bdOffset, u16 sampleRate, u8 loop, u8 0xFF.
VAG (SPU2 ADPCM): 16-byte blocks {u8 predict<<4|shift, u8 flags, 14 bytes =
  28 nibbles, low nibble first}. flags: 1 = end, 2 = repeat, 4 = loop start.
  s = (nibble<<12 sign-extended) >> shift + (h1*f0 + h2*f1) / 64,
  f = (0,0) (60,0) (115,-52) (98,-55) (122,-60).

usage: hdbd.py ISO OUTDIR BANKINDEX [--max N]
"""
import os, struct, sys
from afs import Afs
from adx import write_wav

F = [(0, 0), (60, 0), (115, -52), (98, -55), (122, -60)]


def vag_decode(bd, off, end):
    out = bytearray()
    h1 = h2 = 0
    p = off
    loop_start = None
    loop = False
    while p + 16 <= end:
        ps, fl = bd[p], bd[p + 1]
        sh, pr = ps & 0xF, ps >> 4
        f0, f1 = F[pr] if pr < 5 else (0, 0)
        if fl & 4 and loop_start is None:
            loop_start = len(out) // 2
        for k in range(28):
            b = bd[p + 2 + (k >> 1)]
            n = (b >> 4) if k & 1 else (b & 0xF)
            s = (n << 12)
            if s & 0x8000:
                s -= 0x10000
            s = (s >> sh) + ((h1 * f0 + h2 * f1) >> 6)
            s = -32768 if s < -32768 else 32767 if s > 32767 else s
            h2, h1 = h1, s
            out += struct.pack('<h', s)
        p += 16
        if fl & 1:
            loop = bool(fl & 2)
            break
    n = len(out) // 2
    return out, (dict(start=loop_start or 0, end=n) if loop else None)


def chunk_table(hd, ofs):
    size, mx = struct.unpack_from('<II', hd, ofs + 8)
    return [ofs + o for o in struct.unpack_from('<%dI' % (mx + 1), hd, ofs + 16)]


def parse_bank(d):
    pairs = [struct.unpack_from('<II', d, 8 * i) for i in range(8)]
    ho, hs = pairs[0]
    bo, bs = pairs[1]
    hd, bd = d[ho:ho + hs], d[bo:bo + bs]
    assert hd[0:8] == b'IECSsreV' and hd[0x10:0x18] == b'IECSdaeH'
    head = struct.unpack_from('<IIIIIII', hd, 0x10 + 8)
    _, hd_size, bd_size, prog, sset, smpl, vagi = head
    vags = [struct.unpack_from('<IHBB', hd, o) for o in chunk_table(hd, vagi)]
    return dict(pairs=pairs, hd=hd, bd=bd, prog=prog, sset=sset, smpl=smpl,
                vagi=vagi, vags=vags)


if __name__ == '__main__':
    a = Afs(sys.argv[1], 1)
    outdir = sys.argv[2]
    idx = int(sys.argv[3])
    mx = int(sys.argv[sys.argv.index('--max') + 1]) if '--max' in sys.argv else 1 << 30
    b = parse_bank(a.read(idx))
    od = os.path.join(outdir, 'afs01_%02d' % idx)
    os.makedirs(od, exist_ok=True)
    bd = b['bd']
    offs = sorted(set(v[0] for v in b['vags'])) + [len(bd)]
    lines = ['pairs ' + ' '.join('(%#x,%#x)' % p for p in b['pairs'] if p != (0, 0)),
             'chunks prog=%#x sset=%#x smpl=%#x vagi=%#x' % (b['prog'], b['sset'], b['smpl'], b['vagi']),
             'nVag=%d nSmpl=%d nSset=%d nProg=%d' % (
                 len(b['vags']), len(chunk_table(b['hd'], b['smpl'])),
                 len(chunk_table(b['hd'], b['sset'])), len(chunk_table(b['hd'], b['prog'])))]
    for i, (off, rate, lp, pad) in enumerate(b['vags'][:mx]):
        end = offs[offs.index(off) + 1]
        pcm, loop = vag_decode(bd, off, end)
        p = os.path.join(od, 'vag%03d.wav' % i)
        write_wav(p, [pcm], rate, loop)
        lines.append('vag%03d bd=%#07x rate=%5d loopByte=%d samples=%d (%.2fs) loop=%s' % (
            i, off, rate, lp, len(pcm) // 2, len(pcm) / 2 / rate, loop))
    open(os.path.join(od, 'bank.txt'), 'w').write('\n'.join(lines) + '\n')
    print('\n'.join(lines[:3] + lines[3:13]))
