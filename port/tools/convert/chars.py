#!/usr/bin/env python3
"""MvC2 PS2 character sprite bank (section 0 of PLxxPAK.BIN) -> PNG frames.

Contains no asset bytes; reads the user's ISO. See port/docs/ASSET_FORMATS.md.
Layouts follow the decomp:
  func_00411C10 (src/xl14_a.c)  palettes, ARGB1555 -> GS RGBA (A = bit15 ? 0x80 : 0)
  func_00413A80 (src/p3r.c)     byte LZ for tile pixels
  func_00412260 (asm/main.s)    frame/part/tile walk, square sub-block split, flips
  func_00413600 (asm/main.s)    UV swap for H/V flip

usage: chars.py ISO CHARID OUTDIR [--frames a,b,c|a-b] [--pal N] [--sheet]
"""
import os, struct, sys
from afs import Afs
import png

PAK_BASE_ID = 209          # AFS02 index of PL00PAK.BIN; PLxxPAK = 209 + xx


def lz_decode(src, pos, out_len):
    """func_00413A80: flag byte (MSB first); 1 = match byte b: copy (b&15)+2
    bytes from dst-((b>>4)+1); 0 = literal. Runs until dst >= end."""
    out = bytearray()
    mask = 0
    flags = 0
    while len(out) < out_len:
        if mask == 0:
            flags = src[pos]; pos += 1; mask = 0x80
        if flags & mask:
            b = src[pos]; pos += 1
            q = len(out) - ((b >> 4) + 1)
            for k in range((b & 0xF) + 2):
                out.append(out[q + k])
        else:
            out.append(src[pos]); pos += 1
        mask >>= 1
    return out  # may overrun out_len by up to 16 bytes, like the original


def argb1555_to_rgba(c):
    """func_00411C10 conversion; returns (r, g, b, a_ps2) with a_ps2 in {0, 0x80}."""
    return (((c >> 10) & 0x1F) << 3, ((c >> 5) & 0x1F) << 3, (c & 0x1F) << 3,
            0x80 if c & 0x8000 else 0)


class SpriteBank:
    def __init__(self, data, base=0):
        self.d = data
        self.b = base
        u32 = lambda o: struct.unpack_from('<I', data, base + o)[0]
        self.tile_tab = base + u32(0x04)
        self.frame_tab = base + u32(0x0C)
        self.pal_off = base + u32(0x14)
        self.n_tiles = struct.unpack_from('<I', data, self.tile_tab)[0] // 4
        self.n_frames = struct.unpack_from('<I', data, self.frame_tab)[0] // 4

    def palette(self, n):
        """Palette n (0..15 used by the slot) as 16 RGBA8 tuples (PS2 0x80 -> 255)."""
        out = []
        for k in range(16):
            c = struct.unpack_from('<H', self.d, self.pal_off + 32 * n + 2 * k)[0]
            r, g, b, a = argb1555_to_rgba(c)
            out.append((r, g, b, 255 if a else 0))
        return out

    def tile(self, idx):
        """-> (b0, b1, w, h, indices[w*h]) with indices 0..15 in tile pixel order."""
        o = self.tile_tab + struct.unpack_from('<I', self.d, self.tile_tab + 4 * idx)[0]
        b0, b1, w8, h8 = self.d[o:o + 4]
        w, h = w8 * 8, h8 * 8
        raw = lz_decode(self.d, o + 4, w * h // 2)
        s = min(w, h)              # square sub-block side
        nsub = max(w, h) // s
        pix = bytearray(w * h)
        p = 0
        for k in range(nsub):      # sub-blocks stored one after another, s x s 4bpp
            ox, oy = (k * s, 0) if w >= h else (0, k * s)
            for y in range(s):
                row = (oy + y) * w + ox
                for x in range(0, s, 2):
                    v = raw[p]; p += 1
                    pix[row + x] = v & 0xF          # PSMT4: low nibble = left pixel
                    pix[row + x + 1] = v >> 4
        return b0, b1, w, h, pix

    def frame_parts(self, f):
        o = self.frame_tab + struct.unpack_from('<I', self.d, self.frame_tab + 4 * f)[0]
        n = struct.unpack_from('<h', self.d, o)[0]
        return [struct.unpack_from('<4h', self.d, o + 2 + 8 * k) for k in range(n)]

    def frame_quads(self, f):
        """Replicates func_00412260's placement. Yields
        (x, y, side, flags, tile, subindex) for each square sub-block (pixel space,
        origin = actor position, y down)."""
        px = py = 0.0
        for dx, dy, flags, ti in self.frame_parts(f):
            px -= dx; py -= dy                    # positions are cumulative deltas
            b0, b1, w, h, _ = self.tile_info(ti)
            s = min(w, h); nsub = max(w, h) // s
            stx, sty = (1, 0) if w >= h else (0, 1)
            if flags & 0x8000:
                x0 = px + b0 * 8 - s; stx = -stx
            else:
                x0 = px
            if flags & 0x4000:
                y0 = py + b1 * 8 - s; sty = -sty
            else:
                y0 = py
            for k in range(nsub):
                yield (x0 + k * stx * s, y0 + k * sty * s, s, flags, ti, k)

    def tile_info(self, idx):
        o = self.tile_tab + struct.unpack_from('<I', self.d, self.tile_tab + 4 * idx)[0]
        b0, b1, w8, h8 = self.d[o:o + 4]
        return b0, b1, w8 * 8, h8 * 8, None

    def render_frame(self, f, pal=0):
        """-> (w, h, origin_x, origin_y, rgba bytes)."""
        quads = list(self.frame_quads(f))
        if not quads:
            return 0, 0, 0, 0, b''
        x0 = int(min(q[0] for q in quads)); y0 = int(min(q[1] for q in quads))
        x1 = int(max(q[0] + q[2] for q in quads)); y1 = int(max(q[1] + q[2] for q in quads))
        W, H = x1 - x0, y1 - y0
        img = bytearray(W * H * 4)
        cache = {}
        # parts later in the list are drawn later (on top), as in the original loop
        for qx, qy, s, flags, ti, k in quads:
            if ti not in cache:
                cache[ti] = self.tile(ti)
            _, _, w, h, pix = cache[ti]
            pl = self.palette(((flags >> 4) + pal) & 0xF)
            ox, oy = (k * s, 0) if w >= h else (0, k * s)
            hf, vf = flags & 0x8000, flags & 0x4000
            for y in range(s):
                sy = (s - 1 - y) if vf else y
                dy = int(qy) - y0 + y
                for x in range(s):
                    sx = (s - 1 - x) if hf else x
                    i = pix[(oy + sy) * w + ox + sx]
                    if i == 0:          # CLUT index 0 is transparent (A = 0)
                        continue
                    r, g, b, a = pl[i]
                    o = (dy * W + int(qx) - x0 + x) * 4
                    img[o:o + 4] = bytes((r, g, b, a))
        return W, H, -x0, -y0, bytes(img)


def load_bank(iso, char_id):
    a = Afs(iso, 2)
    d = a.read(PAK_BASE_ID + char_id)
    sec0 = struct.unpack_from('<I', d, 0)[0]
    return SpriteBank(d, sec0)


def _parse_frames(s, n):
    out = []
    for part in s.split(','):
        if '-' in part:
            a, b = part.split('-'); out += range(int(a), int(b) + 1)
        else:
            out.append(int(part))
    return [f for f in out if f < n]


if __name__ == '__main__':
    iso, cid, outdir = sys.argv[1], int(sys.argv[2], 0), sys.argv[3]
    args = sys.argv[4:]
    pal = int(args[args.index('--pal') + 1]) if '--pal' in args else 0
    bank = load_bank(iso, cid)
    frames = _parse_frames(args[args.index('--frames') + 1], bank.n_frames) \
        if '--frames' in args else range(bank.n_frames)
    os.makedirs(outdir, exist_ok=True)
    print('PL%02XPAK: %d tiles, %d frames' % (cid, bank.n_tiles, bank.n_frames))
    for f in frames:
        W, H, ox, oy, img = bank.render_frame(f, pal)
        if not W:
            continue
        p = os.path.join(outdir, 'pl%02x_f%03d_p%d.png' % (cid, f, pal))
        png.write_rgba(p, W, H, img)
        print('%s %dx%d origin=(%d,%d) parts=%d' % (p, W, H, ox, oy, len(bank.frame_parts(f))))
    if '--palettes' in args:
        img = bytearray()
        for n in range(16):
            for c in bank.palette(n):
                img += bytes((c[0], c[1], c[2], 255))
        png.write_rgba(os.path.join(outdir, 'pl%02x_palettes.png' % cid), 16, 16, img)
