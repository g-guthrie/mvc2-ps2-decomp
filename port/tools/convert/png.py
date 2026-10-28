"""Tiny PNG writer (stdlib zlib). write_rgba(path, w, h, rows_bytes) and helpers."""
import struct, zlib


def _chunk(t, d):
    return struct.pack('>I', len(d)) + t + d + struct.pack('>I', zlib.crc32(t + d) & 0xFFFFFFFF)


def write_rgba(path, w, h, pix):
    """pix: bytes/bytearray of w*h*4 RGBA, row-major."""
    raw = bytearray()
    stride = w * 4
    for y in range(h):
        raw.append(0)
        raw += pix[y * stride:(y + 1) * stride]
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n')
        f.write(_chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0)))
        f.write(_chunk(b'IDAT', zlib.compress(bytes(raw), 6)))
        f.write(_chunk(b'IEND', b''))


def read_rgba(path):
    """Minimal reader for PNGs written by write_rgba (for self-tests)."""
    d = open(path, 'rb').read()
    p = 8; idat = b''; w = h = 0
    while p < len(d):
        n = struct.unpack_from('>I', d, p)[0]; t = d[p + 4:p + 8]; c = d[p + 8:p + 8 + n]
        if t == b'IHDR': w, h = struct.unpack_from('>II', c)
        if t == b'IDAT': idat += c
        p += 12 + n
    raw = zlib.decompress(idat)
    out = bytearray()
    for y in range(h):
        out += raw[y * (w * 4 + 1) + 1:(y + 1) * (w * 4 + 1)]
    return w, h, out
