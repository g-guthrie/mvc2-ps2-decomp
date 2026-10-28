#!/usr/bin/env python3
"""CRI ADX (type 3, 4-bit, fixed coefficients) -> 16-bit PCM WAV with loop points.

Public format; no asset bytes embedded. Header (big-endian):
  0x00 u16 0x8000          0x02 u16 copyrightOffset (data at +4)
  0x04 u8 encoding (3)     0x05 u8 blockSize (18)  0x06 u8 bits (4)
  0x07 u8 channels         0x08 u32 sampleRate     0x0C u32 totalSamples
  0x10 u16 highpassHz      0x12 u8 version (3/4)   0x13 u8 flags
  v3: 0x14 u16 loopAlign, u16 loopEnabled(1)... 0x18 u32 loopFlag,
      0x1C u32 loopStartSample, 0x20 u32 loopStartByte,
      0x24 u32 loopEndSample, 0x28 u32 loopEndByte
  v4: same block shifted by +0x0C (after 4 history words).
Frame: per channel, u16 BE scale then 32 signed nibbles (high nibble first);
channels interleave frame by frame.
  s = nib * scale + ((c1*h1 + c2*h2) >> 12)
  c1/c2 from highpass: a = sqrt2 - cos(2pi*hp/rate), b = sqrt2 - 1,
  c = (a - sqrt((a+b)(a-b)))/b, c1 = floor(c*8192), c2 = floor(-c*c*4096).

usage: adx.py ISO OUTDIR INDEX [INDEX...]   (AFS00 entries)
"""
import math, os, struct, sys
from afs import Afs


def header(d):
    if d[0:2] != b'\x80\x00':
        raise ValueError('not ADX')
    (cofs, enc, bs, bits, ch, rate, total, hp, ver, flags) = struct.unpack_from('>HBBBBIIHBB', d, 2)
    h = dict(data=cofs + 4, enc=enc, block=bs, bits=bits, ch=ch, rate=rate,
             total=total, hp=hp, ver=ver, loop=None)
    lo = 0x18 if ver == 3 else 0x24
    if lo + 0x14 <= cofs + 4:
        lf, ls, lsb, le, leb = struct.unpack_from('>IIIII', d, lo)
        if lf == 1:
            h['loop'] = dict(start=ls, start_byte=lsb, end=le, end_byte=leb)
    return h


def coefs(hp, rate):
    a = math.sqrt(2) - math.cos(2 * math.pi * hp / rate)
    b = math.sqrt(2) - 1
    c = (a - math.sqrt((a + b) * (a - b))) / b
    return int(math.floor(c * 8192)), int(math.floor(-c * c * 4096))


def decode(d, h):
    ch, bs = h['ch'], h['block']
    spf = (bs - 2) * 2
    c1, c2 = coefs(h['hp'], h['rate'])
    hist = [[0, 0] for _ in range(ch)]
    out = [bytearray() for _ in range(ch)]
    p = h['data']
    n = 0
    total = h['total']
    while n < total and p + bs * ch <= len(d):
        for c in range(ch):
            f = p + bs * c
            scale = (d[f] << 8 | d[f + 1])
            h1, h2 = hist[c]
            o = out[c]
            for k in range(spf):
                b = d[f + 2 + (k >> 1)]
                nib = (b >> 4) if not (k & 1) else (b & 0xF)
                if nib & 8:
                    nib -= 16
                s = nib * scale + ((c1 * h1 + c2 * h2) >> 12)
                s = -32768 if s < -32768 else 32767 if s > 32767 else s
                h2, h1 = h1, s
                o += struct.pack('<h', s)
            hist[c] = [h1, h2]
        p += bs * ch
        n += spf
    for c in range(ch):
        del out[c][total * 2:]
    return out


def write_wav(path, chans, rate, loop=None):
    ch = len(chans)
    n = len(chans[0]) // 2
    inter = bytearray(n * 2 * ch)
    for c in range(ch):
        inter[c * 2::ch * 2] = chans[c][0::2]
        inter[c * 2 + 1::ch * 2] = chans[c][1::2]
    fmt = struct.pack('<HHIIHH', 1, ch, rate, rate * ch * 2, ch * 2, 16)
    chunks = b'fmt ' + struct.pack('<I', len(fmt)) + fmt
    if loop:
        # 'smpl' chunk: one forward loop, end inclusive (ADX end sample is exclusive)
        smpl = struct.pack('<9I', 0, 0, int(1e9 / rate), 60, 0, 0, 0, 1, 0)
        smpl += struct.pack('<6I', 0, 0, loop['start'], loop['end'] - 1, 0, 0)
        chunks += b'smpl' + struct.pack('<I', len(smpl)) + smpl
    chunks += b'data' + struct.pack('<I', len(inter)) + bytes(inter)
    with open(path, 'wb') as f:
        f.write(b'RIFF' + struct.pack('<I', 4 + len(chunks)) + b'WAVE' + chunks)


if __name__ == '__main__':
    a = Afs(sys.argv[1], 0)
    outdir = sys.argv[2]
    os.makedirs(outdir, exist_ok=True)
    for s in sys.argv[3:]:
        i = int(s)
        d = a.read(i)
        h = header(d)
        chans = decode(d, h)
        p = os.path.join(outdir, 'afs00_%02d.wav' % i)
        write_wav(p, chans, h['rate'], h['loop'])
        print(p, '%d ch %d Hz %d samples (%.2f s) hp=%d v%d loop=%s' % (
            h['ch'], h['rate'], h['total'], h['total'] / h['rate'], h['hp'], h['ver'], h['loop']))
