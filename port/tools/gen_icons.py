#!/usr/bin/env python3
"""Generate the web app icons (port/web/icon-*.png): an arcade stick and six
buttons, drawn with signed-distance shapes (no image libraries, no game art).

    python3 port/tools/gen_icons.py port/web
"""
import math, os, struct, sys, zlib

def png(path, w, h, rgba):
    raw = b''.join(b'\0' + bytes(rgba[y * w * 4:(y + 1) * w * 4]) for y in range(h))
    def chunk(t, d):
        c = struct.pack('>I', len(d)) + t + d
        return c + struct.pack('>I', zlib.crc32(t + d) & 0xffffffff)
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 6, 0, 0, 0))
                + chunk(b'IDAT', zlib.compress(raw, 9)) + chunk(b'IEND', b''))

def hexc(s):
    return tuple(int(s[i:i + 2], 16) / 255 for i in (1, 3, 5))

def sd_circle(x, y, cx, cy, r):
    return math.hypot(x - cx, y - cy) - r

def sd_rrect(x, y, x0, y0, x1, y1, r):
    cx, cy, hx, hy = (x0 + x1) / 2, (y0 + y1) / 2, (x1 - x0) / 2 - r, (y1 - y0) / 2 - r
    qx, qy = abs(x - cx) - hx, abs(y - cy) - hy
    return math.hypot(max(qx, 0), max(qy, 0)) + min(max(qx, qy), 0) - r

def sd_capsule(x, y, ax, ay, bx, by, r):
    px, py, vx, vy = x - ax, y - ay, bx - ax, by - ay
    t = max(0, min(1, (px * vx + py * vy) / (vx * vx + vy * vy)))
    return math.hypot(px - vx * t, py - vy * t) - r

def render(n, maskable):
    out = bytearray(n * n * 4)
    k = 0.80 if maskable else 1.0          # maskable: keep the art in the safe zone
    btn = [(0.565, 0.455, '#4fa3ff'), (0.695, 0.435, '#2f6fe0'), (0.825, 0.455, '#50d070'),
           (0.565, 0.615, '#ff6a6a'), (0.695, 0.595, '#d03a3a'), (0.825, 0.615, '#e0c040')]
    px = 1.0 / n
    for j in range(n):
        for i in range(n):
            u, v = (i + 0.5) / n, (j + 0.5) / n
            # background
            if maskable:
                a_bg = 1.0
            else:
                a_bg = max(0.0, min(1.0, 0.5 - sd_rrect(u, v, 0.02, 0.02, 0.98, 0.98, 0.2) / px))
            g = v
            col = [hexc('#1c2350')[c] * (1 - g) + hexc('#090b16')[c] * g for c in range(3)]
            # glow behind the stick
            glow = max(0.0, 1 - math.hypot(u - 0.5, v - 0.45) / 0.55)
            col = [c + 0.10 * glow * glow for c in col]
            x, y = 0.5 + (u - 0.5) / k, 0.5 + (v - 0.5) / k
            def over(cov, c, a=1.0):
                nonlocal col
                cov = max(0.0, min(1.0, cov)) * a
                col = [col[t] * (1 - cov) + c[t] * cov for t in range(3)]
            s = lambda d: 0.5 - d / (px / k)
            # panel
            over(s(sd_rrect(x, y, 0.10, 0.30, 0.90, 0.78, 0.07)), hexc('#2b3266'))
            over(s(sd_rrect(x, y, 0.10, 0.30, 0.90, 0.33, 0.03)), hexc('#5b6bd8'), 0.6)
            # stick: base, shaft, ball
            over(s(sd_circle(x, y, 0.30, 0.62, 0.085)), hexc('#11152e'))
            over(s(sd_capsule(x, y, 0.30, 0.62, 0.30, 0.38, 0.025)), hexc('#c8ccdc'))
            over(s(sd_circle(x, y, 0.30, 0.34, 0.105)), hexc('#e8403a'))
            over(s(sd_circle(x, y, 0.27, 0.305, 0.035)), (1, 1, 1), 0.55)
            for (bx, by, c) in btn:
                over(s(sd_circle(x, y, bx, by + 0.012, 0.055)), hexc('#11152e'))
                over(s(sd_circle(x, y, bx, by, 0.052)), hexc(c))
                over(s(sd_circle(x, y, bx - 0.015, by - 0.017, 0.016)), (1, 1, 1), 0.45)
            o = (j * n + i) * 4
            out[o:o + 4] = bytes([int(max(0, min(1, c)) * 255 + 0.5) for c in col] + [int(a_bg * 255 + 0.5)])
    return out

def main():
    d = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(__file__), '..', 'web')
    for n, name, m in [(32, 'icon-32.png', False), (180, 'icon-180.png', True), (192, 'icon-192.png', False),
                       (512, 'icon-512.png', False), (512, 'icon-maskable-512.png', True)]:
        png(os.path.join(d, name), n, n, render(n, m))
        print('wrote', name)

if __name__ == '__main__':
    main()
