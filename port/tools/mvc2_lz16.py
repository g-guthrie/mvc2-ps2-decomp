#!/usr/bin/env python3
"""Decoder for the 16-bit-word LZ used by MvC2 PS2 *TEX.BIN packs (func_00176230).

Stream of u16 words. Flag word (MSB first); bit 0 => copy literal word.
bit 1 => token v: cnt = v>>11 (if 0, cnt = next word); off = v & 0x7FF (words back).
off == 0: cnt words of zero (cnt == 0 => end of stream).
usage: mvc2_lz16.py IN OUT   (operate on files you extracted to /tmp or private/)
"""
import struct, sys

def decode(src: bytes) -> bytes:
    w = struct.unpack('<%dH' % (len(src) // 2), src[:len(src) // 2 * 2])
    out = []; i = 0; mask = 0; bits = 0
    while True:
        if mask == 0:
            bits = w[i]; i += 1; mask = 0x8000
        if bits & mask:
            v = w[i]; i += 1
            cnt = v >> 11
            if cnt: v &= 0x7FF
            else: cnt = w[i]; i += 1
            if v == 0:
                if cnt == 0: break
                out.extend([0] * cnt)
            else:
                s = len(out) - v
                for k in range(cnt): out.append(out[s + k])
        else:
            out.append(w[i]); i += 1
        mask >>= 1
    return struct.pack('<%dH' % len(out), *out)

if __name__ == '__main__':
    open(sys.argv[2], 'wb').write(decode(open(sys.argv[1], 'rb').read()))
