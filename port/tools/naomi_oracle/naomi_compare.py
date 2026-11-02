#!/usr/bin/env python3
"""Compare the port's per-frame state dump (MVC2_STATE_DUMP, PS2 layout,
port/tools/oracle/dump_format.h) with the NAOMI arcade oracle's
(naomi_oracle --dump, naomi_dump.h), frame by frame.

  naomi_compare.py PORT.bin NAOMI.bin [--sync STATE] [--port-sync N --naomi-sync M]
                   [--frames N] [--show K] [--max-fields N] [--no-pads]
                   [--players-only] [--strict-y]
  naomi_compare.py PORT.bin NAOMI.bin --align [--sync STATE] [--frames N]

Alignment: --sync STATE pairs the first frame at which each side's game
state g[0..4] ("2/1/2/3", or a prefix) matches, then frame by frame.

What is compared (the NAOMI side translated to the PS2 layout):
  header: game state g[0..4], the game RNG (PS2 D_004C26AC/B0 = NAOMI
    0x0C283049/48), the script's pad bits;
  the six player records (PS2 0x004F20B0 stride 0x5B8, NAOMI 0x0C2D7088
    stride 0x5A4) through PLAYER_MAP: NAOMI offset + shift = PS2 offset;
  the game block g (PS2 0x004F4300, NAOMI 0x0C2D6F88) through GAME_MAP.
Fields that differ by design are mapped or skipped (BY_DESIGN below):
  - pointers (a word that is an EE address on the PS2 side or a NAOMI
    main-RAM address on the NAOMI side) are not compared;
  - vertical world coordinates: the PS2 build scales the CPS2 y by 2
    (448/224) where the NAOMI scales by 15/7 (480/224); y positions and
    y velocities are compared as PS2 = NAOMI * 14/15 within 1e-4
    (--strict-y: bit-exact after the scale is not expected);
  - fields in the PS2-only gaps of the record are not compared.
--align prints, for each NAOMI player-record word that changes, the shift
(0, 4, ... 0x24) under which it equals a PS2 word most often: the evidence
for PLAYER_MAP.
"""
import argparse
import struct
import sys

# ---- port dump (dump_format.h) -------------------------------------------
P_MAGIC = 0x3446564D
P_REGION_LO, P_REGION_HI = 0x004F20B0, 0x004F4500
P_HASH_LO, P_HASH_HI, P_BLOCK = 0x004C2580, 0x00634380, 0x400
P_NBLOCKS = (P_HASH_HI - P_HASH_LO + P_BLOCK - 1) // P_BLOCK
P_RL = P_REGION_HI - P_REGION_LO
P_REC = 12 + 4 + 8 + 4 + 2 * P_RL + 4 * P_NBLOCKS
P_PL, P_STRIDE, P_G = 0x004F20B0, 0x5B8, 0x004F4300

# ---- NAOMI dump (naomi_dump.h) -------------------------------------------
N_MAGIC = 0x314E564D
N_REGION_LO, N_REGION_HI = 0x0C2D6F00, 0x0C2D9700
N_RL = N_REGION_HI - N_REGION_LO
N_REC = 32 + N_RL
N_PL, N_STRIDE, N_G = 0x0C2D7088, 0x5A4, 0x0C2D6F88

YSCALE = 14.0 / 15.0


def load_port(path):
    d = open(path, 'rb').read()
    out = []
    for i in range(len(d) // P_REC):
        o = i * P_REC
        magic, frame, pads, st = struct.unpack_from('<4I', d, o)
        if magic != P_MAGIC:
            raise SystemExit(f'{path}: bad record {i}')
        grng, = struct.unpack_from('<I', d, o + 24)
        reg = d[o + 28:o + 28 + P_RL]
        raw = d[o + 28 + P_RL:o + 28 + 2 * P_RL]
        out.append(dict(frame=frame, pads=pads, rng=grng, reg=reg, raw=raw))
    return out


def load_naomi(path):
    d = open(path, 'rb').read()
    out = []
    for i in range(len(d) // N_REC):
        o = i * N_REC
        magic, frame, pads, st, rng = struct.unpack_from('<5I', d, o)
        if magic != N_MAGIC:
            raise SystemExit(f'{path}: bad record {i}')
        out.append(dict(frame=frame, pads=pads, rng=rng, reg=d[o + 32:o + 32 + N_RL]))
    return out


def pplayer(f, i):
    o = P_PL - P_REGION_LO + i * P_STRIDE
    return f['reg'][o:o + P_STRIDE], f['raw'][o:o + P_STRIDE]


def nplayer(f, i):
    o = N_PL - N_REGION_LO + i * N_STRIDE
    return f['reg'][o:o + N_STRIDE]


def pgame(f):
    o = P_G - P_REGION_LO
    return f['reg'][o:o + 0x100]


def ngame(f):
    o = N_G - N_REGION_LO
    return f['reg'][o:o + 0x100]


def pstate(f):
    g = pgame(f)
    return tuple(g[:5])


def nstate(f):
    g = ngame(f)
    return tuple(g[:5])


def st_str(t):
    return '/'.join(str(x) for x in t)


def match(t, want):
    cur = st_str(t)
    return cur == want or cur.startswith(want + '/') or (want.endswith('/') and cur.startswith(want))


# ---- the player-record map: (NAOMI lo, NAOMI hi, shift) --------------------
# Shift = PS2 offset - NAOMI offset.  From the twin routines (ARCADE_DIFF
# 7, 10) and --align over the attract cycle and fights (BOOT_NOTES "Arcade
# oracle").  Ranges not listed are not compared.
PLAYER_MAP = [
    (0x000, 0x0C0, 0x00),
    (0x0C0, 0x108, 0x00),
    (0x108, 0x17C, 0x10),
    (0x17C, 0x19C, 0x10),
    (0x19C, 0x5A4, 0x14),
]
# NAOMI offsets of float fields in world y units (compared after the scale)
Y_FIELDS = {0x38, 0x60, 0x68, 0x6C}
# NAOMI offsets (4-byte words) not compared, with the reason
BY_DESIGN = {
}

GAME_MAP = [(0x00, 0x100, 0x00)]


def is_naomi_ptr(v):
    return 0x0C000000 <= v < 0x0D000000 or 0x8C000000 <= v < 0x8D000000 or 0xAC000000 <= v < 0xAD000000


def is_ps2_ptr(v):
    return 0x00100000 <= v < 0x02000000 and (v & 3) == 0


def f32(b):
    return struct.unpack('<f', b)[0]


def cmp_words(pb, praw, nb, segs, yfields, strict_y, label, msgs, maxf, skip):
    for lo, hi, sh in segs:
        for n in range(lo & ~3, hi, 4):
            p = n + sh
            if p + 4 > len(pb) or n + 4 > len(nb):
                continue
            if n in skip:
                continue
            nw = nb[n:n + 4]
            pw = pb[p:p + 4]
            if nw == pw or (praw is not None and praw[p:p + 4] == nw):
                continue
            nv, = struct.unpack('<I', nw)
            pv, = struct.unpack('<I', pw)
            if is_naomi_ptr(nv) or is_ps2_ptr(pv) and nv != 0:
                continue
            if n in yfields:
                a, b = f32(pw), f32(nw) * YSCALE
                if not strict_y and abs(a - b) <= 1e-4 * max(1.0, abs(a)):
                    continue
                msgs.append(f'{label}+0x{p:03X} (NAOMI +0x{n:03X}, y): port {f32(pw):.6g} naomi {f32(nw):.6g} (x14/15 = {b:.6g})')
                continue
            # name the differing bytes
            for k in range(4):
                if pw[k] != nw[k]:
                    break
            msgs.append(f'{label}+0x{p:03X} (NAOMI +0x{n:03X}): port {pv:08X} naomi {nv:08X}'
                        + (f' ({f32(pw):.6g} / {f32(nw):.6g})' if 0x30 <= n < 0x80 else ''))
            if len(msgs) > maxf:
                return


def align(P, N, ps, ns, n):
    """for every NAOMI player word that is non-zero, the shift (0..0x24)
    under which the PS2 record holds the same value in the same frame, over
    the six players and the paired frames (sampled)"""
    shifts = list(range(0, 0x28, 4))
    step = max(1, n // 400)
    print('NAOMI off: best shift, hits / non-zero samples (second best)')
    for off in range(0, N_STRIDE, 4):
        cnt = {sh: 0 for sh in shifts}
        tot = 0
        for k in range(0, n, step):
            for i in range(6):
                w = nplayer(N[ns + k], i)[off:off + 4]
                if w in (b'\0\0\0\0', b'\xff\xff\xff\xff'):
                    continue
                tot += 1
                pb, _ = pplayer(P[ps + k], i)
                for sh in shifts:
                    if pb[off + sh:off + sh + 4] == w:
                        cnt[sh] += 1
        if not tot:
            continue
        r = sorted(cnt.items(), key=lambda t: -t[1])
        print(f'  +0x{off:03X}: 0x{r[0][0]:02X} {r[0][1]}/{tot}   (0x{r[1][0]:02X} {r[1][1]})')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('port')
    ap.add_argument('naomi')
    ap.add_argument('--sync')
    ap.add_argument('--port-sync', type=int)
    ap.add_argument('--naomi-sync', type=int)
    ap.add_argument('--frames', type=int, default=10 ** 9)
    ap.add_argument('--show', type=int, default=1)
    ap.add_argument('--max-fields', type=int, default=24)
    ap.add_argument('--no-pads', action='store_true')
    ap.add_argument('--players-only', action='store_true')
    ap.add_argument('--players', default='0,1,2,3,4,5')
    ap.add_argument('--strict-y', action='store_true')
    ap.add_argument('--align', action='store_true')
    ap.add_argument('--skip', action='append', default=[], help='NAOMI player offset (hex) not compared')
    a = ap.parse_args()
    P = load_port(a.port)
    N = load_naomi(a.naomi)
    ps = ns = 0
    if a.sync:
        ps = next((i for i, f in enumerate(P) if match(pstate(f), a.sync)), None)
        ns = next((i for i, f in enumerate(N) if match(nstate(f), a.sync)), None)
        if ps is None or ns is None:
            raise SystemExit(f'sync state {a.sync} not reached: port {ps}, naomi {ns}')
    if a.port_sync is not None:
        ps = next(i for i, f in enumerate(P) if f['frame'] == a.port_sync)
    if a.naomi_sync is not None:
        ns = next(i for i, f in enumerate(N) if f['frame'] == a.naomi_sync)
    n = min(len(P) - ps, len(N) - ns, a.frames)
    print(f'port frame {P[ps]["frame"]} <-> naomi frame {N[ns]["frame"]} '
          f'(state {st_str(pstate(P[ps]))} / {st_str(nstate(N[ns]))}), {n} frames')
    if a.align:
        align(P, N, ps, ns, n)
        return 0
    skip = {int(x, 16) for x in a.skip} | set(BY_DESIGN)
    players = [int(x) for x in a.players.split(',')]
    first = None
    shown = 0
    for k in range(n):
        p, q = P[ps + k], N[ns + k]
        msgs = []
        if pstate(p) != nstate(q):
            msgs.append(f'state port {st_str(pstate(p))} naomi {st_str(nstate(q))}')
        if not a.no_pads and (p['pads'] & 0xFFFF0000FFFF) != (q['pads'] & 0xFFFF0000FFFF):
            msgs.append(f'pads port {p["pads"]:08X} naomi {q["pads"]:08X}')
        if p['rng'] != q['rng']:
            msgs.append(f'game RNG port {p["rng"]:04X} naomi {q["rng"]:04X}')
        for i in players:
            pb, praw = pplayer(p, i)
            cmp_words(pb, praw, nplayer(q, i), PLAYER_MAP, Y_FIELDS, a.strict_y, f'player[{i}]', msgs,
                      a.max_fields, skip)
        if not a.players_only:
            cmp_words(pgame(p), None, ngame(q), GAME_MAP, set(), a.strict_y, 'g', msgs, a.max_fields, set())
        if msgs:
            if first is None:
                first = k
            if shown < a.show:
                print(f'--- +{k}: port frame {p["frame"]} / naomi frame {q["frame"]} (state {st_str(nstate(q))})')
                for m in msgs[:a.max_fields]:
                    print('   ', m)
                if len(msgs) > a.max_fields:
                    print(f'    ... {len(msgs)} differences')
                shown += 1
    if first is None:
        print(f'MATCH: {n} frames identical (mapped fields)')
    else:
        print(f'FIRST DIVERGENCE at +{first} (port frame {P[ps + first]["frame"]}, '
              f'naomi frame {N[ns + first]["frame"]}); matched {first} frames')
    return 0 if first is None else 1


if __name__ == '__main__':
    sys.exit(main())
