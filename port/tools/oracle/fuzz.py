#!/usr/bin/env python3
"""Randomised differential test of the port against the retail PS2 (the oracle:
the retail executable in Play!, mvc2_oracle).  See port/docs/ORACLE_FUZZ.md.

  fuzz.py run  --out DIR [--seed S] [--count N] [--jobs J] [--hours H] [opts]
  fuzz.py one  --out DIR --seed S [opts]        one scenario, outputs kept
  fuzz.py show SEED [--seed-only]               print a scenario (script + options)
  fuzz.py minimise DIR/SEED [opts]              snapshots around a divergence + snapdiff
  fuzz.py report --out DIR                      summary of DIR/results.jsonl
  fuzz.py sanity --out DIR [--seed S --count N] the oracle against itself (noise check)

Sound commands (dump_format.h): every frame's ordered list of calls into the
TSD client and CRI ADXT entry points must match too (--no-sound: not compared).

A scenario (from its seed alone): ARCADE, a random P1 team (any of the 56
selectable characters, a random assist type each, picked through the
character select with --p1-team: the cursor resolves to the forced
character, the assist type is chosen in the menu), a random CPU team
(--cpu-team ID:T), optional --cpu-hp (to win stages quickly: new stages,
eventually Abyss) and --p1-hp (to stay alive), then random but game-plausible
input: walks, dashes, jumps, super jumps, blocking, crouching, normals,
chains, special and super motions, assists, tags, snap-backs, throws, mashes,
idle.  Port (native i386 build, MVC2_PS2_FLOAT on) and oracle run in
parallel with --resync 1/1/0; their per-frame dumps (dump_format.h) go
through FIFOs to the comparer here (nothing large on disk), which stops both
at the first difference in the header (pads, game state, rand seed, game
RNG) or the player/game region.  BSS hash blocks that newly differ are
recorded (first frame per block) without stopping the run (host-pointer
words make some differ by design; see the doc).

Results: DIR/results.jsonl (one line per seed; `run` skips seeds already
there, so it resumes), DIR/SEED/ for divergences (script, options, the
diverging records of both sides, repro command).  `minimise` re-runs a
diverging scenario only up to the divergence with snapshots (sync frame,
divergence - 1, divergence) on both sides and writes snapdiff.py output
(words that differ at the divergence and did not at the sync frame, with
symbols) to DIR/SEED/snapdiff.txt.
"""
import argparse
import json
import os
import random
import shutil
import signal
import struct
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '../../..'))
sys.path.insert(0, HERE)
import compare as C  # noqa: E402

SYNC = '1/1/0'

DUMP_FROM = 400

CHARS = {
    0x00: 'Ryu', 0x01: 'Zangief', 0x02: 'Guile', 0x03: 'Morrigan', 0x04: 'Anakaris',
    0x05: 'Strider', 0x06: 'Cyclops', 0x07: 'Wolverine', 0x08: 'Psylocke', 0x09: 'Iceman',
    0x0A: 'Rogue', 0x0B: 'Captain America', 0x0C: 'Spider-Man', 0x0D: 'Hulk', 0x0E: 'Venom',
    0x0F: 'Dr. Doom', 0x10: 'Tron', 0x11: 'Jill', 0x12: 'Hayato', 0x13: 'Ruby Heart',
    0x14: 'SonSon', 0x15: 'Amingo', 0x16: 'Marrow', 0x17: 'Cable', 0x1B: 'Chun-Li',
    0x1C: 'Mega Man', 0x1D: 'Roll', 0x1E: 'Akuma', 0x1F: 'BB Hood', 0x20: 'Felicia',
    0x21: 'Charlie', 0x22: 'Sakura', 0x23: 'Dan', 0x24: 'Cammy', 0x25: 'Dhalsim',
    0x26: 'M. Bison', 0x27: 'Ken', 0x28: 'Gambit', 0x29: 'Juggernaut', 0x2A: 'Storm',
    0x2B: 'Sabretooth', 0x2C: 'Magneto', 0x2D: 'Shuma-Gorath', 0x2E: 'War Machine',
    0x2F: 'Silver Samurai', 0x30: 'Omega Red', 0x31: 'Spiral', 0x32: 'Colossus',
    0x33: 'Iron Man', 0x34: 'Sentinel', 0x35: 'Blackheart', 0x36: 'Thanos', 0x37: 'Jin',
    0x38: 'Captain Commando', 0x39: 'Wolverine (bone)', 0x3A: 'Servbot',
}
assert len(CHARS) == 56
IDS = sorted(CHARS)
ASSIST = 'abg'  # alpha, beta, gamma


# ---- scenario generation ---------------------------------------------------

def motion(r, f, b):
    """a special-move motion as (buttons, frames) steps without the button"""
    k = r.choice(['qcf', 'qcb', 'dp', 'rdp', 'hcf', 'hcb', 'charge_b', 'charge_d', 'dd'])
    if k == 'qcf':
        return [('down', 2), ('down+' + f, 2), (f, 0)]
    if k == 'qcb':
        return [('down', 2), ('down+' + b, 2), (b, 0)]
    if k == 'dp':
        return [(f, 2), ('down', 2), ('down+' + f, 0)]
    if k == 'rdp':
        return [(b, 2), ('down', 2), ('down+' + b, 0)]
    if k == 'hcf':
        return [(b, 2), ('down+' + b, 2), ('down', 2), ('down+' + f, 2), (f, 0)]
    if k == 'hcb':
        return [(f, 2), ('down+' + f, 2), ('down', 2), ('down+' + b, 2), (b, 0)]
    if k == 'charge_b':
        return [(b, r.randint(30, 60)), (f, 0)]
    if k == 'charge_d':
        return [('down+' + b, r.randint(30, 60)), ('up', 0)]
    return [('down', 2), ('', 2), ('down', 0)]


def action(r):
    """one game-plausible input chunk: list of script lines"""
    f = r.choice(['right', 'left'])
    b = 'left' if f == 'right' else 'right'
    P, K = ['square', 'triangle'], ['cross', 'circle']
    BTN = P + K
    kinds = [('idle', 10), ('walk', 10), ('crouch', 5), ('block', 8), ('jump', 10),
             ('superjump', 3), ('dash', 6), ('normal', 15), ('chain', 8), ('special', 12),
             ('super', 6), ('assist', 6), ('tag', 3), ('variable', 2), ('throw', 4),
             ('mash', 4), ('shoulder', 2)]
    k = r.choices([x for x, _ in kinds], [w for _, w in kinds])[0]
    L = []

    def j(*parts):
        return '+'.join(p for p in parts if p)
    if k == 'idle':
        L.append(f'wait {r.randint(1, 40)}')
    elif k == 'walk':
        L.append(f'hold {r.choice([f, b])} {r.randint(5, 40)}')
    elif k == 'crouch':
        L.append(f'hold down {r.randint(5, 30)}')
    elif k == 'block':
        L.append(f'hold {r.choice([b, "down+" + b])} {r.randint(10, 50)}')
    elif k == 'jump':
        L.append(f'hold {j("up", r.choice([f, b, ""]))} 3')
        L.append(f'wait {r.randint(2, 18)}')
        for _ in range(r.randint(0, 2)):
            L.append(f'hold {j(r.choice(["", "down", f]), r.choice(BTN))} 3')
            L.append(f'wait {r.randint(2, 10)}')
    elif k == 'superjump':
        L.append('hold down 2')
        L.append(f'hold {j("up", r.choice([f, b, ""]))} 3')
        L.append(f'wait {r.randint(5, 25)}')
        if r.random() < 0.7:
            L.append(f'hold {r.choice(BTN)} 3')
    elif k == 'dash':
        if r.random() < 0.5:
            d = r.choice([f, b])
            L += [f'hold {d} 2', 'wait 3', f'hold {d} {r.randint(2, 10)}']
        else:
            L.append(f'hold {j(r.choice(["", f, b]), "square+triangle")} 3')
        L.append(f'wait {r.randint(0, 10)}')
    elif k == 'normal':
        L.append(f'press {j(r.choice(["", "", "down", f, b]), r.choice(BTN))} {r.randint(2, 5)}')
    elif k == 'chain':
        for x in r.sample(BTN, r.randint(2, 4)):
            L.append(f'hold {j(r.choice(["", "", "down"]), x)} 2')
            L.append(f'wait {r.randint(4, 12)}')
    elif k in ('special', 'super'):
        steps = motion(r, f, b)
        btn = r.choice(BTN) if k == 'special' else r.choice(['square+triangle', 'cross+circle', 'square+cross',
                                                              'triangle+circle'])
        for d, n in steps[:-1]:
            L.append(f'hold {d} {n}' if d else f'wait {n}')
        L.append(f'hold {j(steps[-1][0], btn)} {r.randint(2, 4)}')
        L.append(f'wait {r.randint(5, 40)}')
    elif k == 'assist':
        L.append(f'press {j(r.choice(["", "", "down", b]), r.choice(["l1", "r1"]))} {r.randint(2, 5)}')
    elif k == 'tag':
        L.append(f'hold {r.choice(["l1", "r1", "triangle+circle"])} {r.randint(10, 40)}')
    elif k == 'variable':
        if r.random() < 0.5:
            L.append(f'press l1+r1 {r.randint(2, 5)}')
        else:  # snap-back: qcf + assist
            L += ['hold down 2', f'hold down+{f} 2', f'hold {f}+{r.choice(["l1", "r1"])} 3']
    elif k == 'throw':
        L += [f'hold {f} {r.randint(3, 15)}', f'hold {r.choice([f, b])}+{r.choice(["triangle", "circle"])} 3']
    elif k == 'mash':
        for _ in range(r.randint(5, 20)):
            bs = r.sample(BTN + ['l1', 'r1', f, b, 'down', 'up'], r.randint(1, 3))
            L.append(f'hold {"+".join(bs)} {r.randint(1, 2)}')
    elif k == 'shoulder':
        L.append(f'press {r.choice(["l2", "r2"])} {r.randint(2, 4)}')
    return L


def lines_frames(L):
    n = 0
    for ln in L:
        c = ln.split()
        if c[0] in ('wait', 'hold'):
            n += int(c[-1]) if c[0] == 'wait' else (int(c[2]) if len(c) > 2 else 1)
        elif c[0] == 'press':
            n += (int(c[2]) if len(c) > 2 else 6) + 6
    return n


ARCADE_SEED = 1000000   # seeds from here on are whole arcade runs (scenario_arcade)
STAGE_BYTE = 0x004F4385  # arcade stage counter in the game block (0 = first fight)


def scenario_arcade(seed):
    """a whole ARCADE run: the fight scenario's team pick, then per stage a
    burst of random input and a ~1200-frame attack mash (with start/cross
    presses that also get through the win screens).  The CPU has 1 HP and
    P1 144, so the run goes stage to stage; the game stays in 2/1/2 across
    stages, `stages` in the result is the arcade stage counter (STAGE_BYTE,
    0 for the first fight)."""
    r = random.Random(seed)
    p1 = [(r.choice(IDS), r.randint(0, 2)) for _ in range(3)]
    cpu = [(r.choice(IDS), r.randint(0, 2)) for _ in range(3)]
    S = ['# fuzz.py arcade scenario %d' % seed,
         'state 1/1/1', 'wait 30', 'until 1/7 start 40', 'wait 30', 'until 3/1/1 start 30', 'wait 40',
         'press cross', 'state 2/1/1', 'wait 240']
    for cid, a in p1:
        S += ['press right 4', 'wait 10', 'press left 4', 'wait 10', 'press cross', 'wait 100']
        S += ['press down 4', 'wait 10'] * a
        S += ['press cross', 'wait 100']
    S += ['until 2/1/2 cross 50']
    n = 0
    # 12 stage blocks below seed 1000100 (they reach the 7th-8th fight), 22 from there on (to Abyss)
    for _ in range(12 if seed < ARCADE_SEED + 100 else 22):
        F = []
        while lines_frames(F) < r.randint(150, 600):
            F += action(r)
        mash = r.choice(['right+square', 'left+triangle', 'down+square+triangle', 'right+cross+circle',
                         'square+triangle'])
        for k in range(150):
            F += [f'hold {mash} 4', 'wait 4']
            if k % 25 == 24:
                F += [f'press {r.choice(["cross", "start"])} 3']
        S += F
        n += lines_frames(F)
    return {
        'seed': seed,
        'p1': p1, 'cpu': cpu, 'cpu_hp': 1, 'p1_hp': 144, 'frames': 2200 + n,
        'script': '\n'.join(S) + '\n',
    }


def scenario(seed):
    if seed >= ARCADE_SEED:
        return scenario_arcade(seed)
    r = random.Random(seed)
    p1 = [(r.choice(IDS), r.randint(0, 2)) for _ in range(3)]
    cpu = [(r.choice(IDS), r.randint(0, 2)) for _ in range(3)]
    cpu_hp = r.choices([None, 40, 1], [6, 2, 2])[0]
    p1_hp = r.choices([None, 60, 144], [2, 3, 5])[0]
    fight = r.randint(2000, 4000)
    S = ['# fuzz.py scenario %d' % seed,
         'state 1/1/1', 'wait 30', 'until 1/7 start 40', 'wait 30', 'until 3/1/1 start 30', 'wait 40',
         'press cross', 'state 2/1/1', 'wait 240']
    # each pick: move the cursor (the forced character is under it, see
    # func_00137F90 in port/host/arcade.c), pick, choose the assist type
    for cid, a in p1:
        S += ['press right 4', 'wait 10', 'press left 4', 'wait 10', 'press cross', 'wait 100']
        S += ['press down 4', 'wait 10'] * a
        S += ['press cross', 'wait 100']
    S += ['until 2/1/2 cross 50']
    F = []
    while lines_frames(F) < fight:
        F += action(r)
    S += F
    frames = 2200 + fight
    return {
        'seed': seed,
        'p1': p1, 'cpu': cpu, 'cpu_hp': cpu_hp, 'p1_hp': p1_hp, 'frames': frames,
        'script': '\n'.join(S) + '\n',
    }


def team_arg(team, with_assist):
    return ','.join(('0x%02X:%d' % (c, a)) if with_assist else ('0x%02X' % c) for c, a in team)


def options(scn):
    o = ['--p1-team', team_arg(scn['p1'], False), '--cpu-team', team_arg(scn['cpu'], True)]
    if scn['cpu_hp'] is not None:
        o += ['--cpu-hp', str(scn['cpu_hp'])]
    if scn['p1_hp'] is not None:
        o += ['--p1-hp', str(scn['p1_hp'])]
    return o


def describe(scn):
    t = lambda team: '/'.join('%s(%s)' % (CHARS[c], ASSIST[a]) for c, a in team)
    return 'P1 %s vs CPU %s%s%s' % (t(scn['p1']), t(scn['cpu']),
                                   '' if scn['cpu_hp'] is None else ' cpu-hp %d' % scn['cpu_hp'],
                                   '' if scn['p1_hp'] is None else ' p1-hp %d' % scn['p1_hp'])


# ---- running a pair ----------------------------------------------------------

class Stream:
    """records of a dump FIFO, as compare.load() tuples"""

    def __init__(self, path, proc, size=None):
        self.size = size or C.REC
        fd = os.open(path, os.O_RDONLY | os.O_NONBLOCK)
        import fcntl
        fl = fcntl.fcntl(fd, fcntl.F_GETFL)
        fcntl.fcntl(fd, fcntl.F_SETFL, fl & ~os.O_NONBLOCK)
        self.fd, self.proc, self.buf, self.got = fd, proc, b'', False

    def raw(self):
        need = self.size
        while len(self.buf) < need:
            d = os.read(self.fd, max(need - len(self.buf), 1 << 16))
            if not d:
                if self.proc.poll() is not None and (self.got or self.proc.poll() is not None):
                    # writer gone (or never came): drain once more, then EOF
                    d = os.read(self.fd, 1 << 16)
                    if not d:
                        return None
                else:
                    time.sleep(0.02)
                    continue
            self.got = True
            self.buf += d
        r, self.buf = self.buf[:need], self.buf[need:]
        return r

    def close(self):
        os.close(self.fd)


def parse(rec):
    magic, frame, pads, st = struct.unpack_from('<4I', rec, 0)
    if magic != C.MAGIC:
        raise ValueError('bad record')
    seed, grng = struct.unpack_from('<QI', rec, 16)
    reg = rec[28:28 + C.RL]
    raw = rec[28 + C.RL:28 + 2 * C.RL]
    hashes = rec[28 + 2 * C.RL:C.SND_OFF]
    return frame, pads, st, seed, reg, hashes, grng, raw, rec[C.REC:], C.parse_snd(rec, C.SND_OFF)


def frame_diffs(p, o, ign=(), sound=True, races=None):
    """races: a list that collects the status-gated stops excused this frame
    (compare.snd_match)"""
    msgs = []
    if sound:
        sd, r = C.snd_match(p[9], o[9])
        if sd:
            msgs.append(sd)
        if races is not None:
            races += r
    if p[1] != o[1]:
        msgs.append(f'pads port {p[1]:08X} oracle {o[1]:08X}')
    if p[2] != o[2]:
        msgs.append(f'state port {C.st_str(p[2])} oracle {C.st_str(o[2])}')
    if p[3] != o[3]:
        msgs.append(f'rand seed port {p[3]:016X} oracle {o[3]:016X}')
    if p[6] != o[6]:
        msgs.append(f'game RNG port {p[6]:04X} oracle {o[6]:04X}')
    fields = []
    if p[4] != o[4]:
        d = C.diff_region(p[4], o[4], ign, p[7])
        for off in d:
            pv, = struct.unpack_from('<I', p[4], off)
            ov, = struct.unpack_from('<I', o[4], off)
            fields.append((C.where(C.REGION_LO + off), pv, ov))
        for w, pv, ov in fields[:24]:
            msgs.append(f'{w}: port {pv:08X} oracle {ov:08X}')
        if len(fields) > 24:
            msgs.append(f'... {len(fields)} words differ')
    return msgs, fields


def blocks_differ(p, o):
    if p[5] == o[5]:
        return []
    a = struct.unpack(f'<{C.NBLOCKS}I', p[5])
    b = struct.unpack(f'<{C.NBLOCKS}I', o[5])
    return [k for k in range(C.NBLOCKS) if a[k] != b[k]]


def is_fight(st):
    return (st >> 16) == 2 and ((st >> 8) & 0xFF) == 1 and (st & 0xFF) >= 2


def _die_with_parent():
    """children (and pool workers) get SIGKILL when their parent dies, so a
    killed `fuzz.py run` leaves no emulator behind"""
    try:
        import ctypes
        ctypes.CDLL('libc.so.6').prctl(1, signal.SIGKILL)  # PR_SET_PDEATHSIG
    except OSError:
        pass


def _child_init():
    os.setsid()
    _die_with_parent()


def run_pair(scn, work, port, oracle, iso, snaps=None, frames=None, keep_div=None, extra=None, visit=None,
             sound=True, oracle_only=False):
    """run port and oracle on a scenario, compare as they go.
    snaps: {'port': [(frame, file)], 'oracle': [(frame, file)]}"""
    os.makedirs(work, exist_ok=True)
    script = os.path.join(work, 'script.txt')
    open(script, 'w').write(scn['script'])
    pf, of = os.path.join(work, 'port.fifo'), os.path.join(work, 'oracle.fifo')
    for f in (pf, of):
        if os.path.exists(f):
            os.unlink(f)
        os.mkfifo(f)
    mc, oh = os.path.join(work, 'mc'), os.path.join(work, 'oracle_home')
    shutil.rmtree(mc, ignore_errors=True)
    shutil.rmtree(oh, ignore_errors=True)
    os.makedirs(mc)
    nfr = frames or scn['frames']
    opts = options(scn)
    oargs = [oracle, '--iso', iso, '--frames', str(nfr), '--resync', SYNC, '--dump', of,
             '--dump-from', str(DUMP_FROM), '--script', script] + opts
    pargs = [port, '--hidden', '--frames', str(nfr), '--draw-every', '1000000', '--script', script] + opts + \
        ['--iso', iso]
    env_o = dict(os.environ, MVC2_ORACLE_HOME=oh)
    env_p = dict(os.environ, MVC2_PAD_DELAY='0', MVC2_RESYNC=SYNC, MVC2_STATE_DUMP=pf,
                 MVC2_STATE_DUMP_FROM=str(DUMP_FROM), MVC2_MEMCARD=mc, SDL_VIDEODRIVER='offscreen',
                 SDL_AUDIODRIVER='dummy')
    if oracle_only:
        # the sanity pair: the oracle twice on the scenario ("port" = a second oracle)
        oh2 = oh + '2'
        shutil.rmtree(oh2, ignore_errors=True)
        pargs = [oracle if a == port else (pf if a == of else a) for a in oargs]
        env_p = dict(env_o, MVC2_ORACLE_HOME=oh2)
    rsize = C.REC
    if extra:
        env_o['MVC2_DUMP_EXTRA'] = env_p['MVC2_DUMP_EXTRA'] = '0x%08X:0x%08X' % extra
        rsize += extra[1] - extra[0]
    if snaps:
        for fr, path in snaps.get('oracle', []):
            oargs += ['--snap', f'{fr}:{path}']
        if snaps.get('port'):
            env_p['MVC2_STATE_SNAP'] = ','.join(f'{fr}:{path}' for fr, path in snaps['port'])
    olog = open(os.path.join(work, 'oracle.log'), 'w')
    plog = open(os.path.join(work, 'port.log'), 'w')
    t0 = time.time()
    po = subprocess.Popen(oargs, env=env_o, stdout=olog, stderr=subprocess.STDOUT, cwd=ROOT,
                          preexec_fn=_child_init)
    pp = subprocess.Popen(pargs, env=env_p, stdout=plog, stderr=subprocess.STDOUT, cwd=ROOT,
                          preexec_fn=_child_init)
    res = {'seed': scn['seed'], 'desc': describe(scn), 'frames_run': nfr}
    P = Stream(pf, pp, rsize)
    O = Stream(of, po, rsize)
    deadline = t0 + 240 + nfr / 12.0

    def kill():
        for pr in (pp, po):
            if pr.poll() is None:
                try:
                    os.killpg(pr.pid, signal.SIGKILL)
                except OSError:
                    pass

    import threading
    timer = threading.Timer(max(1, deadline - time.time()), kill)
    timer.start()
    try:
        # align at the first frame of SYNC on each side
        def to_sync(st):
            while True:
                r = st.raw()
                if r is None:
                    return None
                f = parse(r)
                if C.match(f[2], SYNC):
                    return f, r
        ps = to_sync(P)
        os_ = to_sync(O)
        if ps is None or os_ is None:
            res['status'] = 'no_sync'
            res['detail'] = 'port' if ps is None else 'oracle'
            return finish(res, pp, po, P, O, kill, timer, t0, work)
        (p, praw), (o, oraw) = ps, os_
        res['port_sync'], res['oracle_sync'] = p[0], o[0]
        base = set(blocks_differ(p, o))
        res['base_blocks'] = len(base)
        newly = {}
        n = fight = 0
        nsnd = sframes = 0
        races = []
        prev = None
        stages, seen = 0, set()
        while True:
            fr = []
            msgs, fields = frame_diffs(p, o, sound=sound, races=fr)
            races += [(n, p[0], side, '%#x' % x) for side, x in fr]
            if visit is not None:
                if visit(n, p, o, msgs):
                    res['status'] = 'visited'
                    break
                msgs = []
            for blk in blocks_differ(p, o):
                if blk not in base and blk not in newly:
                    newly[blk] = (n, p[0], C.st_str(o[2]))
            if msgs:
                res['status'] = 'diverge'
                res['div'] = {'k': n, 'port_frame': p[0], 'oracle_frame': o[0], 'state': C.st_str(o[2]),
                              'msgs': msgs, 'fields': [w for w, _, _ in fields[:64]]}
                if keep_div:
                    os.makedirs(keep_div, exist_ok=True)
                    with open(os.path.join(keep_div, 'div_port.bin'), 'wb') as fp:
                        fp.write((prev[0] if prev else b'') + praw)
                    with open(os.path.join(keep_div, 'div_oracle.bin'), 'wb') as fo:
                        fo.write((prev[1] if prev else b'') + oraw)
                break
            n += 1
            nsnd += o[9][0]
            sframes += o[9][0] > 0
            if is_fight(o[2]):
                fight += 1
            seen.add(o[2])
            stages = max(stages, o[4][STAGE_BYTE - C.REGION_LO])
            prev = (praw, oraw)
            a, b = P.raw(), O.raw()
            if a is None or b is None:
                res['status'] = 'match'
                if a is None and pp.poll() not in (0, None):
                    res['status'] = 'port_exit'
                    res['detail'] = 'port exit code %s at port frame %d' % (pp.poll(), p[0])
                elif b is None and po.poll() not in (0, None):
                    res['status'] = 'oracle_exit'
                    res['detail'] = 'oracle exit code %s' % po.poll()
                break
            praw, oraw = a, b
            p, o = parse(a), parse(b)
        res['compared'] = n
        res['last_port_frame'] = p[0]
        res['fight_frames'] = fight
        res['sound'] = sound
        res['sound_cmds'] = nsnd
        res['sound_frames'] = sframes
        res['sound_races'] = races[:200]
        res['n_sound_races'] = len(races)
        res['stages'] = stages
        res['states'] = sorted(C.st_str(x) for x in seen)
        res['last_state'] = C.st_str(o[2])
        # earliest first (a cap by address dropped the blocks above ~0x004EA000)
        res['new_blocks'] = sorted((('0x%08X' % (C.HASH_LO + k * C.BLOCK), v[0], v[1], v[2])
                                    for k, v in newly.items()), key=lambda t: (t[1], t[0]))[:80]
        return finish(res, pp, po, P, O, kill, timer, t0, work)
    except Exception as e:  # noqa: BLE001
        res['status'] = 'error'
        res['detail'] = repr(e)
        return finish(res, pp, po, P, O, kill, timer, t0, work)


def finish(res, pp, po, P, O, kill, timer, t0, work):
    # a pair that matched to the end exits by itself (--frames); otherwise stop it
    for _ in range(50):
        if pp.poll() is not None and po.poll() is not None:
            break
        if res.get('status') != 'match':
            break
        time.sleep(0.1)
    kill()
    timer.cancel()
    pp.wait()
    po.wait()
    P.close()
    O.close()
    res['wall'] = round(time.time() - t0, 1)
    if pp.returncode not in (0, None, -9) and res.get('status') in ('match', 'diverge'):
        res['port_rc'] = pp.returncode
    # port crash signature from its log
    try:
        tail = open(os.path.join(work, 'port.log'), errors='replace').read()[-3000:]
        res['port_log_tail'] = [ln for ln in tail.splitlines() if not ln.startswith('[asm]')][-4:]
    except OSError:
        pass
    for f in ('port.fifo', 'oracle.fifo'):
        try:
            os.unlink(os.path.join(work, f))
        except OSError:
            pass
    shutil.rmtree(os.path.join(work, 'oracle_home'), ignore_errors=True)
    shutil.rmtree(os.path.join(work, 'oracle_home2'), ignore_errors=True)
    shutil.rmtree(os.path.join(work, 'mc'), ignore_errors=True)
    return res


def job(seed, out, port, oracle, iso, fight_override=None, sound=True):
    scn = scenario(seed)
    if fight_override:
        scn['frames'] = fight_override
    work = tempfile.mkdtemp(prefix=f'fz{seed}_', dir=out)
    keep = os.path.join(out, str(seed))
    port = os.path.realpath(port)  # a symlink can be repointed between seeds
    res = run_pair(scn, work, port, oracle, iso, keep_div=keep, sound=sound)
    res['port'] = port
    if res.get('status') != 'match':
        os.makedirs(keep, exist_ok=True)
        open(os.path.join(keep, 'script.txt'), 'w').write(scn['script'])
        for f in ('port.log', 'oracle.log'):
            try:
                lines = open(os.path.join(work, f), errors='replace').read().splitlines()
                open(os.path.join(keep, f), 'w').write('\n'.join(
                    ln for ln in lines if not ln.startswith('[asm]') and not ln.startswith('[trace]'))[-200000:])
            except OSError:
                pass
        open(os.path.join(keep, 'repro.txt'), 'w').write(
            'port:   %s\noracle: %s\n' % (' '.join(options(scn)), ' '.join(options(scn))) +
            'fuzz.py one --seed %d --out DIR   (or minimise DIR/%d)\n' % (seed, seed))
        json.dump(res, open(os.path.join(keep, 'result.json'), 'w'), indent=1)
    shutil.rmtree(work, ignore_errors=True)
    return res


# ---- commands ----------------------------------------------------------------

def done_seeds(out):
    p = os.path.join(out, 'results.jsonl')
    s = set()
    if os.path.exists(p):
        for ln in open(p):
            try:
                s.add(json.loads(ln)['seed'])
            except (ValueError, KeyError):
                pass
    return s


def summary_line(res):
    st = res.get('status')
    s = f"seed {res['seed']:6d} {st:11s} {res.get('compared', 0):6d} fr ({res.get('fight_frames', 0):5d} fight) " \
        f"{res.get('sound_cmds', 0):5d} snd {res.get('n_sound_races', 0):3d} races " \
        f"{res.get('wall', 0):6.0f}s  {res['desc']}"
    if st == 'diverge':
        d = res['div']
        s += f"\n      +{d['k']} port {d['port_frame']} oracle {d['oracle_frame']} state {d['state']}: " + \
            '; '.join(d['msgs'][:3])
    elif st not in ('match',):
        s += '\n      ' + str(res.get('detail', '')) + ' ' + ' | '.join(res.get('port_log_tail', [])[-2:])
    return s


def cmd_run(a):
    os.makedirs(a.out, exist_ok=True)
    have = done_seeds(a.out)
    seeds = [s for s in range(a.seed, a.seed + a.count) if s not in have]
    stop = time.time() + a.hours * 3600 if a.hours else None
    print(f'{len(seeds)} scenarios to run ({len(have)} already in {a.out}), {a.jobs} pairs at a time', flush=True)
    resf = open(os.path.join(a.out, 'results.jsonl'), 'a')
    it = iter(seeds)
    with ProcessPoolExecutor(max_workers=a.jobs, initializer=_die_with_parent) as ex:
        fut = {}
        for _ in range(a.jobs):
            s = next(it, None)
            if s is not None:
                fut[ex.submit(job, s, a.out, a.port, a.oracle, a.iso, a.frames, not a.no_sound)] = s
        while fut:
            for f in as_completed(list(fut)):
                s = fut.pop(f)
                try:
                    res = f.result()
                except Exception as e:  # noqa: BLE001
                    res = {'seed': s, 'status': 'error', 'detail': repr(e), 'desc': describe(scenario(s))}
                resf.write(json.dumps(res) + '\n')
                resf.flush()
                print(summary_line(res), flush=True)
                if stop is None or time.time() < stop:
                    n = next(it, None)
                    if n is not None:
                        fut[ex.submit(job, n, a.out, a.port, a.oracle, a.iso, a.frames, not a.no_sound)] = n
                break


def cmd_one(a):
    os.makedirs(a.out, exist_ok=True)
    res = job(a.seed, a.out, a.port, a.oracle, a.iso, a.frames, not a.no_sound)
    print(summary_line(res))
    print(json.dumps(res, indent=1))


def cmd_sanity(a):
    """the oracle against itself on each seed's scenario: the per-frame
    records (sound commands included) must be identical; anything that is
    not is emulator noise the port comparison has to allow for"""
    os.makedirs(a.out, exist_ok=True)
    resf = open(os.path.join(a.out, 'sanity.jsonl'), 'a')
    for seed in range(a.seed, a.seed + a.count):
        scn = scenario(seed)
        if a.frames:
            scn['frames'] = a.frames
        work = tempfile.mkdtemp(prefix=f'san{seed}_', dir=a.out)
        res = run_pair(scn, work, a.oracle, a.oracle, a.iso, keep_div=os.path.join(a.out, 'sanity_%d' % seed),
                       sound=not a.no_sound, oracle_only=True)
        shutil.rmtree(work, ignore_errors=True)
        resf.write(json.dumps(res) + '\n')
        resf.flush()
        print(summary_line(res), flush=True)


def cmd_show(a):
    scn = scenario(a.seed)
    print(describe(scn))
    print('options:', ' '.join(options(scn)), '--frames', scn['frames'])
    if not a.brief:
        print(scn['script'])


def cmd_minimise(a):
    d = a.dir.rstrip('/')
    res = json.load(open(os.path.join(d, 'result.json')))
    if res.get('status') != 'diverge' and not a.at:
        raise SystemExit('not a divergence: %s (use --at FRAME)' % res.get('status'))
    scn = scenario(res['seed'])
    psync, osync = res['port_sync'], res['oracle_sync']
    if a.at:
        # a BSS block's first difference (result.json new_blocks), by port frame
        pfr = a.at
        ofr = a.at + osync - psync
    else:
        dv = res['div']
        pfr, ofr = dv['port_frame'], dv['oracle_frame']
    tmp = os.path.join(d, 'snaps')
    os.makedirs(tmp, exist_ok=True)
    snaps = {'port': [(psync + 1, f'{tmp}/p_base'), (pfr - 1, f'{tmp}/p_prev'), (pfr, f'{tmp}/p_div')],
             'oracle': [(osync + 1, f'{tmp}/o_base'), (ofr - 1, f'{tmp}/o_prev'), (ofr, f'{tmp}/o_div')]}
    work = tempfile.mkdtemp(prefix='min_', dir=d)
    r2 = run_pair(scn, work, a.port, a.oracle, a.iso, snaps=snaps, frames=max(pfr, ofr) + 2)
    shutil.rmtree(work, ignore_errors=True)
    out = [f"minimise seed {res['seed']}: {res['desc']}",
           f"rerun: {r2.get('status')} at {r2.get('div', {}).get('port_frame')} (first run {pfr})"]
    sd = os.path.join(HERE, 'snapdiff.py')
    for tag in ('prev', 'div'):
        if os.path.exists(f'{tmp}/p_{tag}') and os.path.exists(f'{tmp}/o_{tag}'):
            r = subprocess.run([sys.executable, sd, f'{tmp}/p_{tag}', f'{tmp}/o_{tag}', '--base', f'{tmp}/p_base',
                                f'{tmp}/o_base', '--max', str(a.max), '--from', a.lo, '--to', a.hi],
                               capture_output=True, text=True)
            out.append(f'--- snapdiff at the divergence{" - 1" if tag == "prev" else ""} '
                       f'(port {pfr - (tag == "prev")}, oracle {ofr - (tag == "prev")}), '
                       'words already different at the sync frame left out:')
            out.append(r.stdout + r.stderr)
    txt = '\n'.join(out)
    open(os.path.join(d, 'snapdiff%s.txt' % ('_%d' % a.at if a.at else '')), 'w').write(txt)
    print(txt)
    if not a.keep_snaps:
        shutil.rmtree(tmp, ignore_errors=True)


def cmd_scan(a):
    """re-run a scenario with the words of an EE range in every record and
    print, per word, the first frame it differs (floats within --ulp units in
    the last place counted separately): finds where a difference the BSS
    hashes flag starts and whether it is 1-2 ulp render noise"""
    d = a.dir.rstrip('/')
    res = json.load(open(os.path.join(d, 'result.json')))
    scn = scenario(res['seed'])
    lo, hi = (int(x, 0) for x in a.range.split(':'))
    keys, syms = snap_symbols()
    first = {}
    big = {}
    base = set()  # words already different at the sync frame
    n_lines = [0]

    def small(x, y):
        """two words that are floats within a relative --tol (an integer
        word, exponent field 0 or 0xFF, is never small)"""
        ex, ey = (x >> 23) & 0xFF, (y >> 23) & 0xFF
        if ex in (0, 0xFF) or ey in (0, 0xFF):
            return False
        fx, fy = struct.unpack('<f', struct.pack('<I', x))[0], struct.unpack('<f', struct.pack('<I', y))[0]
        return abs(fx - fy) <= a.tol * max(1.0, abs(fx), abs(fy))

    def visit(k, p, o, msgs):
        pe, oe = p[8], o[8]
        if msgs and a.region:
            print(f'+{k} port {p[0]}: region/header: ' + '; '.join(msgs[:4]))
        if pe != oe:
            for off in range(0, len(pe), 4):
                if pe[off:off + 4] != oe[off:off + 4]:
                    addr = lo + off
                    if k == 0:
                        base.add(addr)
                    if addr in base:
                        continue
                    x, = struct.unpack_from('<I', pe, off)
                    y, = struct.unpack_from('<I', oe, off)
                    if addr not in first:
                        first[addr] = (k, p[0], x, y)
                    if not small(x, y) and addr not in big:
                        big[addr] = (k, p[0], x, y)
                        if n_lines[0] < a.max:
                            n_lines[0] += 1
                            print(f'+{k} port {p[0]} oracle {o[0]} state {C.st_str(o[2])}: '
                                  f'0x{addr:08X} {sym(keys, syms, addr):28s} port {x:08X} oracle {y:08X}', flush=True)
        return a.until is not None and p[0] >= a.until
    work = tempfile.mkdtemp(prefix='scan_', dir=d)
    r = run_pair(scn, work, a.port, a.oracle, a.iso, frames=(a.until + 2) if a.until else None, extra=(lo, hi),
                 visit=visit)
    shutil.rmtree(work, ignore_errors=True)
    print(f"run: {r.get('status')}, {r.get('compared')} frames; {len(first)} words differed at some frame, "
          f"{len(big)} by more than a relative {a.tol} (floats)")
    small = sorted((v[0], addr) for addr, v in first.items() if addr not in big)
    for kk, addr in small[:a.max]:
        v = first[addr]
        print(f'  small only: +{v[0]} port {v[1]} 0x{addr:08X} {sym(keys, syms, addr):28s} port {v[2]:08X} oracle {v[3]:08X}')


def cmd_watch(a):
    """the port alone under gdb: a hardware watchpoint on EE words from port
    frame --at - 1, backtraces of every write until --at + --span (which
    game functions write the word that diverges)"""
    d = a.dir.rstrip('/')
    res = json.load(open(os.path.join(d, 'result.json')))
    scn = scenario(res['seed'])
    work = tempfile.mkdtemp(prefix='watch_', dir=d)
    script = os.path.join(work, 'script.txt')
    open(script, 'w').write(scn['script'])
    mc = os.path.join(work, 'mc')
    os.makedirs(mc)
    g = [f'set pagination off', 'set confirm off',
         f'break host_state_dump_frame if frame == {a.at - 1}', 'run', 'delete 1']
    for w in a.addr:
        addr = int(w, 0)
        g.append(f'watch *(unsigned int *)((char *)&mvc2_ee_bss + {addr - 0x004C2580})')
        g.append('commands\nsilent\nprintf "=== write 0x%08X: %08X frame %ld\\n", ' +
                 f'{addr}, *(unsigned int *)((char *)&mvc2_ee_bss + {addr - 0x004C2580}), *(long *)&mvc2_host_frame\nbt {a.depth}\ncont\nend')
    g.append(f'break host_state_dump_frame if frame >= {a.at + a.span}')
    g.append('cont')
    g.append('kill')
    gf = os.path.join(work, 'gdb.txt')
    open(gf, 'w').write('\n'.join(g) + '\n')
    env = dict(os.environ, MVC2_PAD_DELAY='0', MVC2_RESYNC=SYNC, MVC2_STATE_DUMP='/dev/null',
               MVC2_MEMCARD=mc, SDL_VIDEODRIVER='offscreen', SDL_AUDIODRIVER='dummy')
    cmd = ['gdb', '-batch', '-x', gf, '--args', a.port, '--hidden', '--frames', str(a.at + a.span + 5),
           '--draw-every', '1000000', '--script', script] + options(scn) + ['--iso', a.iso]
    r = subprocess.run(cmd, env=env, cwd=ROOT, capture_output=True, text=True)
    out = [ln for ln in r.stdout.splitlines() if ln.startswith('===') or ln.startswith('#')]
    print('\n'.join(out) if out else (r.stdout[-3000:] + r.stderr[-3000:]))
    shutil.rmtree(work, ignore_errors=True)


def snap_symbols():
    import snapdiff
    return snapdiff.symbols()


def sym(keys, syms, addr):
    import bisect
    i = bisect.bisect_right(keys, addr) - 1
    return f'{syms[keys[i]]}+0x{addr - keys[i]:X}' if i >= 0 else '?'


def cmd_report(a):
    rs = []
    for ln in open(os.path.join(a.out, 'results.jsonl')):
        try:
            rs.append(json.loads(ln))
        except ValueError:
            pass
    by = {}
    for r in rs:
        by.setdefault(r.get('status'), []).append(r)
    tot = sum(r.get('compared', 0) for r in rs)
    snd = sum(r.get('sound_cmds', 0) for r in rs if r.get('sound') is True)
    nrace = sum(r.get('n_sound_races', 0) for r in rs if r.get('sound'))
    fight = sum(r.get('fight_frames', 0) for r in rs)
    chars = set()
    pairs = set()
    for r in rs:
        scn = scenario(r['seed'])
        for c, _ in scn['p1'] + scn['cpu']:
            chars.add(c)
        for c, _ in scn['p1']:
            for e, _ in scn['cpu']:
                pairs.add((c, e))
    print(f'{len(rs)} scenarios, {tot} frames compared ({fight} fight frames), '
          f'{len(chars)} characters, {len(pairs)} P1/CPU character pairs, '
          f'{snd} sound commands compared ({nrace} status-gated stop races excused)')
    for k, v in sorted(by.items(), key=lambda t: str(t[0])):
        print(f'  {k}: {len(v)}')
    sig = {}
    for r in by.get('diverge', []):
        d = r['div']
        key = d['msgs'][0].split(':')[0] if d['msgs'] else '?'
        sig.setdefault(key, []).append(r['seed'])
    if sig:
        print('first diverging field -> seeds:')
        for k, v in sorted(sig.items(), key=lambda t: -len(t[1])):
            print(f'  {k}: {v[:12]}{" ..." if len(v) > 12 else ""}')
    blk = {}
    for r in rs:
        for b in r.get('new_blocks', []):
            blk.setdefault(b[0], []).append(r['seed'])
    if blk:
        print('BSS blocks newly differing (block: runs):')
        for k, v in sorted(blk.items(), key=lambda t: -len(t[1]))[:30]:
            print(f'  {k}: {len(v)}')
    for r in rs:
        if r.get('status') not in ('match',) and a.verbose:
            print(summary_line(r))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest='cmd', required=True)

    def common(p):
        p.add_argument('--port', default=os.environ.get('PORT', os.path.join(ROOT, 'build/port-i386/mvc2')))
        p.add_argument('--oracle', default=os.environ.get('ORACLE', '/tmp/oracle_src/build/mvc2_oracle'))
        p.add_argument('--iso', default=os.environ.get('ISO', os.path.join(ROOT, 'private/disc/mvc2.iso')))
        p.add_argument('--frames', type=int, help='override the scenario length (frames from boot)')
        p.add_argument('--no-sound', action='store_true', help='do not compare the sound commands')
    p = sub.add_parser('run')
    common(p)
    p.add_argument('--out', required=True)
    p.add_argument('--seed', type=int, default=1)
    p.add_argument('--count', type=int, default=100)
    p.add_argument('--jobs', type=int, default=2)
    p.add_argument('--hours', type=float, default=0)
    p.set_defaults(fn=cmd_run)
    p = sub.add_parser('one')
    common(p)
    p.add_argument('--out', required=True)
    p.add_argument('--seed', type=int, required=True)
    p.set_defaults(fn=cmd_one)
    p = sub.add_parser('sanity')
    common(p)
    p.add_argument('--out', required=True)
    p.add_argument('--seed', type=int, default=1)
    p.add_argument('--count', type=int, default=1)
    p.set_defaults(fn=cmd_sanity)
    p = sub.add_parser('show')
    p.add_argument('seed', type=int)
    p.add_argument('--brief', action='store_true')
    p.set_defaults(fn=cmd_show)
    p = sub.add_parser('minimise')
    common(p)
    p.add_argument('dir')
    p.add_argument('--max', type=int, default=60)
    p.add_argument('--at', type=int, help='port frame to look at instead of the divergence (a block\'s first difference)')
    p.add_argument('--from', dest='lo', default='0x004C2580', help='snapdiff range (default: the EE BSS)')
    p.add_argument('--to', dest='hi', default='0x00634380')
    p.add_argument('--keep-snaps', action='store_true')
    p.set_defaults(fn=cmd_minimise)
    p = sub.add_parser('scan')
    common(p)
    p.add_argument('dir')
    p.add_argument('--range', default='0x004C2580:0x004F20B0', help='LO:HI inside the EE BSS')
    p.add_argument('--until', type=int, help='stop at this port frame')
    p.add_argument('--tol', type=float, default=1e-5, help='relative float difference counted as noise')
    p.add_argument('--max', type=int, default=80)
    p.add_argument('--region', action='store_true', help='also print region/header differences (does not stop)')
    p.set_defaults(fn=cmd_scan)
    p = sub.add_parser('watch')
    common(p)
    p.add_argument('dir')
    p.add_argument('--at', type=int, required=True, help='port frame of the difference')
    p.add_argument('--addr', action='append', required=True, help='EE address of a word (several allowed)')
    p.add_argument('--span', type=int, default=1)
    p.add_argument('--depth', type=int, default=8)
    p.set_defaults(fn=cmd_watch)
    p = sub.add_parser('report')
    p.add_argument('--out', required=True)
    p.add_argument('-v', '--verbose', action='store_true')
    p.set_defaults(fn=cmd_report)
    a = ap.parse_args()
    a.fn(a)


if __name__ == '__main__':
    main()
