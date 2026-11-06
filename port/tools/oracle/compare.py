#!/usr/bin/env python3
"""Compare per-frame state dumps of the port and the oracle (retail game in Play!).

  compare.py PORT.bin ORACLE.bin [--sync STATE] [--port-sync N --oracle-sync M]
             [--frames N] [--ignore FILE] [--show K]

Alignment: --sync STATE pairs the first frame at which each side's game state
(g[0..2], "a/b/c" or a prefix) matches STATE, then frame by frame from there.
Without it, frame numbers are paired as they are.

Reported per frame: the header (pads, game state, rand seed), the sound
commands issued since the previous frame (in order, --no-sound to skip), the bytes of the
six player records (stride 0x5B8 from 0x004F20B0) and of the game block
(0x004F4300..0x004F4500), and the 1 KB hash blocks of the EE BSS that newly
differ (blocks already different at the first compared frame are listed once
and then ignored: IOP / GS / sound areas the port does not keep).
The first diverging frame and field are printed; --show K prints K frames.
"""
import argparse
import struct
import sys

MAGIC = 0x3546564D
REGION_LO, REGION_HI = 0x004F20B0, 0x004F4500
HASH_LO, HASH_HI, BLOCK = 0x004C2580, 0x00634380, 0x400
NBLOCKS = (HASH_HI - HASH_LO + BLOCK - 1) // BLOCK
RL = REGION_HI - REGION_LO
SND_OFF = 12 + 4 + 8 + 4 + 2 * RL + 4 * NBLOCKS
SND_MAX, SND_WORDS = 96, 8
REC = SND_OFF + 4 + 4 * SND_MAX * SND_WORDS
PL, STRIDE = 0x004F20B0, 0x5B8

# dump_format.h oracle_snd_defs: EE entry -> (name, argument count)
SND_DEFS = {
    0x00422EA0: ('tsd_play', 4), 0x00422FB0: ('tsd_stop', 1), 0x004230B0: ('tsd_change', 4),
    0x004231D0: ('tsd_stop_all_tq', 0), 0x00423240: ('tsd_master_volume', 1), 0x004232C0: ('tsd_cmd77', 3),
    0x00423480: ('tsd_load_bank', 7), 0x004235D0: ('tsd_unload_bank', 1), 0x00423650: ('tsd_stop_all', 0),
    0x004236C0: ('tsd_stereo', 1), 0x00423990: ('tsd_status', 2),
    0x00402C20: ('ADXT_StartAfs', 3), 0x00401868: ('ADXT_Stop', 1), 0x004020D8: ('ADXT_SetOutVol', 2),
    0x004026B0: ('ADXT_Pause', 2), 0x00402BC0: ('ADXT_SetOutputMono', 1),
}


def parse_snd(d, o):
    """the record's sound commands: (count, ((fn, a0..a6), ...)); count can
    exceed the entries kept (SND_MAX)"""
    n, = struct.unpack_from('<I', d, o)
    w = struct.unpack_from(f'<{SND_MAX * SND_WORDS}I', d, o + 4)
    return n, tuple(w[i * SND_WORDS:(i + 1) * SND_WORDS] for i in range(min(n, SND_MAX)))


def snd_str(e):
    name, na = SND_DEFS.get(e[0], ('0x%08X' % e[0], 7))
    args = e[1:1 + na]
    # the ADXT handle (first argument) is not recorded
    if name.startswith('ADXT_') and name != 'ADXT_SetOutputMono':
        args = args[1:]
    return name + '(' + ', '.join(_arg(x) for x in args) + ')'


def _arg(x):
    if x >= 0xFFFF0000:
        return str(x - (1 << 32))
    return str(x) if x < 0x10000 else '0x%X' % x


def snd_list(s):
    n, es = s
    return '[' + ', '.join(snd_str(e) for e in es) + (f', ... {n} in all' if n > len(es) else '') + ']'


TSD_STATUS, TSD_STOP = 0x00423990, 0x00422FB0


def _gated_stop(es, i):
    """es[i] is a tsd_stop(X) right after a tsd_status(4, X) query: the game
    stops X only if the driver says X is still active (func_001E59E0)"""
    e = es[i]
    if e[0] != TSD_STOP or i == 0:
        return False
    q = es[i - 1]
    return q[0] == TSD_STATUS and (q[1] & 0xFF) == 4 and q[2] == e[1]


def snd_match(p, o):
    """compare two frames' lists (count, entries): (message or None, races).
    A status-gated stop present on one side only is a race (the end of a TSD
    slot against the frame, ORACLE_FUZZ.md "Sound commands"), not a
    difference; races is the list of ('port'|'oracle', id) excused."""
    if p == o:
        return None, []
    (pn, pe), (on, oe) = p, o
    i = j = 0
    races = []
    while i < len(pe) or j < len(oe):
        if i < len(pe) and j < len(oe) and pe[i] == oe[j]:
            i += 1
            j += 1
        elif i < len(pe) and _gated_stop(pe, i) and not (j < len(oe) and oe[j] == pe[i]):
            races.append(('port', pe[i][1]))
            i += 1
        elif j < len(oe) and _gated_stop(oe, j):
            races.append(('oracle', oe[j][1]))
            j += 1
        else:
            return f'sound commands port {snd_list(p)} oracle {snd_list(o)}', races
    if pn - len(pe) != on - len(oe):  # entries past SND_MAX: only the counts are known
        return f'sound commands port {snd_list(p)} oracle {snd_list(o)}', races
    return None, races


def snd_diff(p, o):
    """None, or a message with both frames' lists"""
    return snd_match(p, o)[0]


def load(path):
    d = open(path, 'rb').read()
    n = len(d) // REC
    frames = []
    for i in range(n):
        o = i * REC
        magic, frame, pads, st = struct.unpack_from('<4I', d, o)
        if magic != MAGIC:
            raise SystemExit(f'{path}: bad record {i}')
        seed, grng = struct.unpack_from('<QI', d, o + 16)
        reg = d[o + 28:o + 28 + RL]
        raw = d[o + 28 + RL:o + 28 + 2 * RL]
        hashes = struct.unpack_from(f'<{NBLOCKS}I', d, o + 28 + 2 * RL)
        frames.append((frame, pads, st, seed, reg, hashes, grng, raw, parse_snd(d, o + SND_OFF)))
    return frames


def st_str(st):
    return f'{st >> 16}/{(st >> 8) & 0xFF}/{st & 0xFF}'


def match(st, want):
    cur = st_str(st)
    return cur == want or cur.startswith(want + '/') or (want.endswith('/') and cur.startswith(want))


def where(addr):
    if PL <= addr < PL + 6 * STRIDE:
        i = (addr - PL) // STRIDE
        return f'player[{i}]+0x{(addr - PL) % STRIDE:03X}'
    return f'0x{addr:08X}'


def load_ignore(path):
    """lines: 'player +0xOFF [len]' (all six records) or '0xADDR [len]'"""
    ign = set()
    if not path:
        return ign
    for ln in open(path):
        ln = ln.split('#')[0].split()
        if not ln:
            continue
        if ln[0] == 'player':
            off = int(ln[1], 0)
            n = int(ln[2], 0) if len(ln) > 2 else 4
            for i in range(6):
                ign.update(range(PL + i * STRIDE + off, PL + i * STRIDE + off + n))
        else:
            a = int(ln[0], 0)
            n = int(ln[1], 0) if len(ln) > 1 else 4
            ign.update(range(a, a + n))
    return ign


# player-record words the render path writes (func_00152D20: the projected
# screen x, y and depth through the VU0 macro matrix code, vu0_macro_math.S):
# Play!'s VU0 and the port's differ by an ulp or two there (BOOT_NOTES "known
# false differences"), so up to RENDER_ULP is not a difference
RENDER_WORDS = (0xF0, 0xF4, 0xF8)
RENDER_ULP = 2


def _ulps(x, y):
    """distance in units in the last place of two float words of one sign"""
    if (x ^ y) & 0x80000000:
        return 1 << 31
    return abs((x & 0x7FFFFFFF) - (y & 0x7FFFFFFF))


def render_noise(off, a, b):
    if off >= 6 * STRIDE or (off % STRIDE) not in RENDER_WORDS:
        return False
    x, = struct.unpack_from('<I', a, off)
    y, = struct.unpack_from('<I', b, off)
    return _ulps(x, y) <= RENDER_ULP


def diff_region(a, b, ign, araw=None):
    """word offsets where a (port, EE terms) and b (oracle) differ; a word
    whose untranslated port value equals the oracle's is not a difference,
    nor render noise (render_noise)"""
    out = []
    i = 0
    n = len(a)
    while i < n:
        if a[i] != b[i] and (REGION_LO + i) not in ign:
            j = i & ~3
            if (araw is None or araw[j:j + 4] != b[j:j + 4]) and not render_noise(j, a, b):
                out.append(j)
            i = j + 4
        else:
            i += 1
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('port')
    ap.add_argument('oracle')
    ap.add_argument('--sync')
    ap.add_argument('--port-sync', type=int)
    ap.add_argument('--oracle-sync', type=int)
    ap.add_argument('--frames', type=int, default=10 ** 9)
    ap.add_argument('--ignore')
    ap.add_argument('--show', type=int, default=1)
    ap.add_argument('--max-fields', type=int, default=24)
    ap.add_argument('--no-pads', action='store_true', help='do not require equal pad bits')
    ap.add_argument('--quiet-blocks', action='store_true', help='blocks only in the summary, not as divergences')
    ap.add_argument('--no-blocks', action='store_true', help='compare the header and the player/game region only')
    ap.add_argument('--no-sound', action='store_true', help='do not compare the sound commands')
    a = ap.parse_args()
    P = load(a.port)
    O = load(a.oracle)
    ign = load_ignore(a.ignore)
    ps, os_ = 0, 0
    if a.sync:
        ps = next((i for i, f in enumerate(P) if match(f[2], a.sync)), None)
        os_ = next((i for i, f in enumerate(O) if match(f[2], a.sync)), None)
        if ps is None or os_ is None:
            raise SystemExit(f'sync state {a.sync} not reached: port {ps}, oracle {os_}')
    if a.port_sync is not None:
        ps = next(i for i, f in enumerate(P) if f[0] == a.port_sync)
    if a.oracle_sync is not None:
        os_ = next(i for i, f in enumerate(O) if f[0] == a.oracle_sync)
    n = min(len(P) - ps, len(O) - os_, a.frames)
    print(f'port frame {P[ps][0]} <-> oracle frame {O[os_][0]} (state {st_str(P[ps][2])} / {st_str(O[os_][2])}), {n} frames')
    base_bad = {k for k in range(NBLOCKS) if P[ps][5][k] != O[os_][5][k]}
    print(f'{len(base_bad)} of {NBLOCKS} BSS blocks differ at the first frame (ignored after)')
    shown = 0
    first = None
    newly = {}
    nsnd = nrace = 0
    for k in range(n):
        p, o = P[ps + k], O[os_ + k]
        msgs = []
        if p[1] != o[1] and not a.no_pads:
            msgs.append(f'pads port {p[1]:08X} oracle {o[1]:08X}')
        if p[2] != o[2]:
            msgs.append(f'state port {st_str(p[2])} oracle {st_str(o[2])}')
        if p[3] != o[3]:
            msgs.append(f'rand seed port {p[3]:016X} oracle {o[3]:016X}')
        if p[6] != o[6]:
            msgs.append(f'game RNG (D_004C26AC/B0) port {p[6]:04X} oracle {o[6]:04X}')
        sd, r = (None, []) if a.no_sound else snd_match(p[8], o[8])
        if sd:
            msgs.append(sd)
        nrace += len(r)
        nsnd += o[8][0]
        d = diff_region(p[4], o[4], ign, p[7])
        for off in d[:a.max_fields]:
            pv, = struct.unpack_from('<I', p[4], off)
            ov, = struct.unpack_from('<I', o[4], off)
            msgs.append(f'{where(REGION_LO + off)}: port {pv:08X} oracle {ov:08X}')
        if len(d) > a.max_fields:
            msgs.append(f'... {len(d)} words differ')
        nb = [] if a.no_blocks else [blk for blk in range(NBLOCKS) if blk not in base_bad and p[5][blk] != o[5][blk]]
        for blk in nb:
            newly.setdefault(blk, k)
        if nb and not a.quiet_blocks:
            msgs.append('BSS blocks newly differing: ' + ' '.join(f'0x{HASH_LO + blk * BLOCK:08X}' for blk in nb[:16]) +
                        (f' (+{len(nb) - 16})' if len(nb) > 16 else ''))
        if msgs:
            if first is None:
                first = k
            if shown < a.show:
                print(f'--- +{k}: port frame {p[0]} / oracle frame {o[0]} (state {st_str(o[2])})')
                for m in msgs:
                    print('   ', m)
                shown += 1
    if newly:
        print('BSS blocks by first divergence (+frame):')
        for blk, k in sorted(newly.items(), key=lambda t: t[1])[:a.max_fields]:
            print(f'    0x{HASH_LO + blk * BLOCK:08X}: +{k} (port frame {P[ps + k][0]})')
    if first is None:
        print(f'MATCH: {n} frames identical, {nsnd} sound commands ({nrace} status-gated stop races)')
    else:
        print(f'FIRST DIVERGENCE at +{first} (port frame {P[ps + first][0]}, oracle frame {O[os_ + first][0]}); matched {first} frames')
    return 0 if first is None else 1


if __name__ == '__main__':
    sys.exit(main())
