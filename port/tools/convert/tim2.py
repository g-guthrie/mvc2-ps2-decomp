#!/usr/bin/env python3
"""Sony TIM2 -> RGBA (stdlib only, no asset bytes).

File header (16 bytes; 128 when format byte == 1):
  'TIM2', u8 version, u8 format(0 = 16-byte align, 1 = 128), u16 nPictures, pad
Picture header (headerSize bytes, 0x30 without mipmaps):
  u32 totalSize, u32 clutSize, u32 imageSize, u16 headerSize, u16 clutColors,
  u8 pictFormat, u8 mipMaps, u8 clutType, u8 imageType, u16 width, u16 height,
  u64 GsTex0, u64 GsTex1, u32 GsRegs, u32 GsTexClut
  then image data (imageSize), then CLUT (clutSize).
imageType: 1 = 16-bit (A1B5G5R5), 2 = 24-bit, 3 = 32-bit, 4 = 4-bit, 5 = 8-bit.
clutType: low 6 bits = entry format (1 = 16, 2 = 24, 3 = 32 bit); bit 7 set =
  CSM2 / linear order, clear = CSM1 (256-colour CLUTs then have index bits 3/4
  swapped). PS2 alpha 0x80 = opaque; scaled with min(255, a*2).
The game parser is func_003F4C10 (header) / func_003F4E70 (CLUT) feeding
func_00418200 (src/s9a_c.c).

usage: tim2.py IN.TM2 OUT_PREFIX     (writes OUT_PREFIX[_N].png)
"""
import struct, sys
import png


def _a(a):
    return min(255, a * 2)


def _color(fmt, b, o):
    if fmt == 1 or fmt == 16:
        c = b[o] | b[o + 1] << 8
        return ((c & 0x1F) << 3, ((c >> 5) & 0x1F) << 3, ((c >> 10) & 0x1F) << 3,
                255 if c & 0x8000 else 0)
    if fmt == 2 or fmt == 24:
        return (b[o], b[o + 1], b[o + 2], 255)
    return (b[o], b[o + 1], b[o + 2], _a(b[o + 3]))


_ENT = {1: 2, 2: 3, 3: 4}


def unswizzle_csm1(i):
    """CSM1 256-colour index -> CLUT storage position (swap bits 3 and 4)."""
    return (i & 0xE7) | ((i & 0x08) << 1) | ((i & 0x10) >> 1)


def parse(data, base=0):
    """-> list of dicts {w, h, imageType, clutType, clutColors, rgba, index, clut}."""
    if data[base:base + 4] != b'TIM2':
        raise ValueError('not TIM2')
    fmt = data[base + 5]
    n = struct.unpack_from('<H', data, base + 6)[0]
    p = base + (128 if fmt == 1 else 16)
    out = []
    for _ in range(n):
        (total, clut_size, img_size, hdr_size, clut_colors, pict_fmt, mips,
         clut_type, img_type, w, h) = struct.unpack_from('<IIIHHBBBBHH', data, p)
        img_off = p + hdr_size
        clut_off = img_off + img_size
        clut = []
        ef = clut_type & 0x3F
        if clut_colors:
            es = _ENT.get(ef, 4)
            raw = [_color(ef, data, clut_off + es * k) for k in range(clut_colors)]
            if clut_colors == 256 and not (clut_type & 0x80):
                clut = [raw[unswizzle_csm1(k)] for k in range(256)]
            else:
                clut = raw
        index = None
        rgba = bytearray(w * h * 4)
        if img_type in (4, 5):
            index = bytearray(w * h)
            if img_type == 5:
                index[:] = data[img_off:img_off + w * h]
            else:
                for k in range((w * h) // 2):
                    v = data[img_off + k]
                    index[2 * k] = v & 0xF          # low nibble = left pixel
                    index[2 * k + 1] = v >> 4
            for k, i in enumerate(index):
                c = clut[i] if i < len(clut) else (255, 0, 255, 255)
                rgba[4 * k:4 * k + 4] = bytes(c)
        else:
            es = {1: 2, 2: 3, 3: 4}[img_type]
            for k in range(w * h):
                rgba[4 * k:4 * k + 4] = bytes(_color(img_type, data, img_off + es * k))
        out.append(dict(w=w, h=h, imageType=img_type, clutType=clut_type,
                        clutColors=clut_colors, mips=mips, pictFormat=pict_fmt,
                        rgba=bytes(rgba), index=index, clut=clut, size=total))
        p += total
    return out


def write_pngs(pics, prefix):
    names = []
    for i, pic in enumerate(pics):
        name = prefix + ('' if len(pics) == 1 else '_%d' % i) + '.png'
        png.write_rgba(name, pic['w'], pic['h'], pic['rgba'])
        names.append(name)
    return names


if __name__ == '__main__':
    pics = parse(open(sys.argv[1], 'rb').read())
    for n, p in zip(write_pngs(pics, sys.argv[2]), pics):
        print(n, p['w'], p['h'], 'type', p['imageType'], 'clut', hex(p['clutType']), p['clutColors'])
