#!/usr/bin/env python3
"""Map the PS2 common sound effects (AFS01 #59, #60) to the Dreamcast disc's
SE_COMN.BIN samples and write port/audio/dcse_map.h.

Most of the common effects (hits, blocks, menu and round sounds) are stored
at 8 kHz on the PS2 and at 11-16 kHz on the Dreamcast.  Both discs hold the
same recordings, so the port can play the Dreamcast versions
(port/audio/dcse.c) when the player supplies their own Dreamcast disc.  The
header holds indices, lengths, rates and fingerprints, never sample bytes.

A PS2 sample is mapped only when one Dreamcast sample is clearly the same
recording:
  - same duration (within 1.2% + 10 ms);
  - waveforms, both low-passed to 3 kHz and resampled to the PS2 rate,
    correlate (best lag within +-300 samples) at >= 0.4 and >= 3x the
    runner-up, or >= 0.5 above it;
  - 20 ms RMS envelopes correlate at >= 0.9;
  - not looped on the PS2 (the looped ones are 11 kHz on both discs).

usage: dc_se_map.py PS2.iso DC_DISC [OUT.h]
  DC_DISC: a .gdi, or the GD-ROM data track (track 3) as .bin (2352-byte
  sectors) or .iso (2048).  For a .chd: chdman extractcd -i X.chd -o X.gdi
Needs numpy (only this generator; the port does not).
"""
import os, struct, sys
import numpy as np
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from afs import Afs
from hdbd import parse_bank, vag_decode

GD_BASE = 45000  # LBA of the GD-ROM high-density data track

# DTPK sample-playback rate codes seen in SE_COMN.BIN -> Hz (AICA OCT/FNS;
# matches the table in Preppy's DTPKDump notes where they overlap)
DTPK_RATE = {0xe21d: 8000, 0xe500: 9400, 0xe600: 9900, 0xe800: 11025, 0xe91e: 12000,
             0xeb00: 13100, 0xec00: 14000, 0xed00: 14700, 0xed1d: 15000, 0xee00: 15600,
             0xee1d: 16000, 0xee31: 16300, 0xf400: 22050, 0xf51e: 24000}


class GdTrack:
    """ISO9660 on a GD-ROM data track (absolute LBAs start at GD_BASE)."""
    def __init__(self, path):
        if path.lower().endswith('.gdi'):
            lines = open(path).read().split('\n')[1:]
            tr = [l.split() for l in lines if len(l.split()) >= 5]
            t = [x for x in tr if int(x[1]) >= GD_BASE and x[2] == '4'][0]
            path = os.path.join(os.path.dirname(path), t[4].strip('"'))
        self.f = open(path, 'rb')
        for ss, hdr in ((2048, 0), (2352, 16), (2352, 24)):
            self.f.seek(16 * ss + hdr)
            if self.f.read(6)[1:6] == b'CD001':
                self.ss, self.hdr = ss, hdr
                break
        else:
            raise SystemExit('%s: no ISO9660 volume descriptor' % path)
        self.base = 0
        pvd = self.sectors(16, 1)
        root = pvd[156:]
        self.base = GD_BASE if struct.unpack_from('<I', root, 2)[0] >= GD_BASE else 0
        self.files = {}
        self._walk(struct.unpack_from('<I', root, 2)[0], struct.unpack_from('<I', root, 10)[0], '')

    def sectors(self, lba, n):
        rel = lba - self.base if lba >= self.base and self.base else lba
        out = bytearray()
        for i in range(n):
            self.f.seek((rel + i) * self.ss + self.hdr)
            out += self.f.read(2048)
        return bytes(out)

    def _walk(self, lba, size, pre):
        d = self.sectors(lba, (size + 2047) // 2048)
        p = 0
        while p < len(d):
            ln = d[p]
            if ln == 0:
                p = (p // 2048 + 1) * 2048
                continue
            ext, sz = struct.unpack_from('<I', d, p + 2)[0], struct.unpack_from('<I', d, p + 10)[0]
            fl, nl = d[p + 25], d[p + 32]
            nm = d[p + 33:p + 33 + nl].split(b';')[0].decode('latin1')
            p += ln
            if nl == 1 and nm in ('\x00', '\x01'):
                continue
            if fl & 2:
                self._walk(ext, sz, pre + nm + '/')
            else:
                self.files[pre + nm] = (ext, sz)

    def read(self, name):
        ext, sz = self.files[name]
        return self.sectors(ext, (sz + 2047) // 2048)[:sz]


def aica_adpcm(b):
    """Yamaha ADPCM as the AICA decodes it (flycast core/hw/aica DecodeADPCM)"""
    out = np.empty(len(b) * 2, np.int32)
    s, q, k = 0, 127, 0
    qs = (0xe6, 0xe6, 0xe6, 0xe6, 0x133, 0x199, 0x200, 0x266)
    for byte in b:
        for n in (byte & 15, byte >> 4):
            m = min(0x7fff, (q * (2 * (n & 7) + 1)) >> 3)
            s = max(-32768, min(32767, s - m if n & 8 else s + m))
            q = max(127, min(24576, (q * qs[n & 7]) >> 8))
            out[k] = s
            k += 1
    return out


def dtpk_samples(d):
    assert d[:4] == b'DTPK'
    t = struct.unpack_from('<8I', d, 0x20)
    spi, smp = t[4], t[7]
    rate = {}
    for i in range(d[spi + 0x10] + 1):
        e = spi + 0x50 + 0x40 * i
        rate.setdefault(d[e + 2], d[e + 0xa] << 8 | d[e + 0xb])
    out = []
    for i in range(struct.unpack_from('<I', d, smp)[0] + 1):
        loc, ls, le, st, ln = struct.unpack_from('<IHHII', d, smp + 4 + 16 * i)
        code = rate.get(i)
        hz = DTPK_RATE.get(code)
        if hz is None or st:
            out.append(None)
            continue
        off = loc & 0x7FFFFF
        if loc & 0x1000000:
            x = aica_adpcm(d[off:off + ln])
        else:
            x = np.frombuffer(d[off:off + ln], '<i2').astype(np.int32)
        out.append(dict(i=i, code=code, hz=hz, adpcm=bool(loc & 0x1000000), x=x.astype(float)))
    return out


def fnv1a(b):
    h = 0x811C9DC5
    for c in b:
        h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h


def lp(x, r, f=3000):
    X = np.fft.rfft(x)
    X[np.fft.rfftfreq(len(x), 1 / r) > f] = 0
    return np.fft.irfft(X, len(x))


def resample(x, r0, r1):
    n1 = int(round(len(x) * r1 / r0))
    X = np.fft.rfft(x)
    Y = np.zeros(n1 // 2 + 1, complex)
    k = min(len(Y), len(X))
    Y[:k] = X[:k]
    return np.fft.irfft(Y, n1) * n1 / len(x)


def wave_corr(a, b, r, lag=300):
    n = min(len(a), len(b))
    a, b = lp(a[:n], r), lp(b[:n], r)
    N = 1 << int(np.ceil(np.log2(2 * n)))
    c = np.fft.irfft(np.fft.rfft(a, N) * np.conj(np.fft.rfft(b, N)), N)
    w = np.concatenate([c[-lag:], c[:lag + 1]])
    return float(w.max() / np.sqrt((a * a).sum() * (b * b).sum() + 1e-9))


def env_corr(a, b, r):
    h = int(r * 0.02)
    e = []
    for x in (a, b):
        n = len(x) // h
        e.append(np.sqrt((x[:n * h].reshape(n, h) ** 2).mean(1)))
    n = min(len(e[0]), len(e[1]))
    if n < 3:
        return 0.0
    ea, eb = e[0][:n] - e[0][:n].mean(), e[1][:n] - e[1][:n].mean()
    return float((ea * eb).sum() / np.sqrt((ea * ea).sum() * (eb * eb).sum() + 1e-9))


def main():
    ps2, dcp = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), '..', '..', 'audio', 'dcse_map.h')
    gd = GdTrack(dcp)
    se = gd.read('SE_COMN.BIN')
    dc = dtpk_samples(se)
    a = Afs(ps2, 1)
    rows, banks = [], []
    for bank in (59, 60):
        b = parse_bank(a.read(bank))
        bd = b['bd']
        banks.append((bank, len(bd), fnv1a(bd)))
        offs = sorted(set(v[0] for v in b['vags'])) + [len(bd)]
        for k, (off, pr, lpb, _) in enumerate(b['vags']):
            pcm, loop = vag_decode(bd, off, offs[offs.index(off) + 1])
            p = np.frombuffer(bytes(pcm), '<i2').astype(float)
            if loop or len(p) < 200:
                continue
            t = len(p) / pr
            cand = []
            for s in dc:
                if s is None or abs(len(s['x']) / s['hz'] - t) > 0.012 * t + 0.01 or s['hz'] <= pr:
                    continue
                xr = resample(s['x'], s['hz'], pr)
                cand.append((wave_corr(xr, p, pr), env_corr(xr, p, pr), s))
            if not cand:
                continue
            cand.sort(key=lambda c: -c[0])
            c, ec, s = cand[0]
            c2 = cand[1][0] if len(cand) > 1 else 0.0
            if ec >= 0.9 and ((c >= 0.4 and c >= 3 * c2) or c - c2 >= 0.5):
                rows.append((bank, k, len(p), pr, s['i'], s['code'], s['hz'], len(s['x']), c))
    with open(out, 'w') as f:
        f.write('/* Generated by port/tools/convert/dc_se_map.py: do not edit.\n'
                ' * PS2 AFS01 common-SE samples -> Dreamcast SE_COMN.BIN samples (same\n'
                ' * recordings, higher rate).  Indices, lengths, rates and fingerprints\n'
                ' * only; the samples come from the player\'s own Dreamcast disc. */\n')
        f.write('#define DCSE_SE_COMN_SIZE %du\n#define DCSE_SE_COMN_FNV 0x%08Xu\n' % (len(se), fnv1a(se)))
        f.write('static const struct { int afs01; uint32_t bd_size, bd_fnv; } DCSE_BANKS[] = {\n')
        for bk, n, h in banks:
            f.write('    { %d, %du, 0x%08Xu },\n' % (bk, n, h))
        f.write('};\n')
        f.write('/* afs01, vag, ps2 samples, ps2 Hz, dc sample, dc rate code, dc Hz, dc samples (corr) */\n')
        f.write('static const struct { uint8_t afs01; uint8_t vag; uint32_t ps2_len; uint16_t ps2_hz;\n'
                '                      uint16_t dc; uint16_t dc_code; uint16_t dc_hz; uint32_t dc_len; } DCSE_MAP[] = {\n')
        for bk, k, pl, pr, i, code, hz, dl, c in rows:
            f.write('    { %d, %3d, %6d, %5d, %3d, 0x%04X, %5d, %6d }, /* %.3f */\n' % (bk, k, pl, pr, i, code, hz, dl, c))
        f.write('};\n')
    print('%d of the PS2 common samples mapped -> %s' % (len(rows), out))


if __name__ == '__main__':
    main()
