#!/usr/bin/python3
"""Compare what the player sees and hears: the port against the retail game
running in Play! (mvc2_av).  Run with /usr/bin/python3 (numpy + Pillow).

  compare_av.py snd PORT.snd ORACLE.snd [--sync 1/1/0] [--tol 2] [--from F --to F]
      the sound command streams (TSD packets decoded into commands, TSD
      status queries, ADXT calls), aligned at the first frame of the resync
      state; prints the commands only one side sent and the ones sent on a
      different frame
  compare_av.py audio PORT.wav PORT.snd ORACLE.wav ORACLE.snd [--sync S]
      per-frame RMS envelopes of the mixed output (the W lines map game
      frames to samples); correlation, level offset, frames where one side
      is sounding and the other is silent
  compare_av.py img PORT_DIR ORACLE_DIR PORT.snd ORACLE.snd [--sync S]
      [--lat L] [--out DIR] [--worst N] [--scenes FILE]
      the port's canvas shots (fNNNNNN.png, 640x480, rows 0..447 shown)
      against the oracle's displayed GS buffer (640x224): the port's row
      pairs are averaged to 224 lines; per frame the mean absolute error,
      the share of pixels off by more than 32 (any channel), the worst 80x28
      cells; --lat is the oracle's display latency in frames (default: the
      best of 0..3 over the first frames); the worst N frames are written
      as port | oracle | diff x4 strips into --out.
"""
import argparse
import os
import re
import sys
from collections import defaultdict


# ---- logs -------------------------------------------------------------------
def read_log(path):
    ev = defaultdict(list)  # frame -> [(kind, text)]
    states = []  # (frame, state)
    samples = {}  # frame -> sample frames so far
    with open(path) as f:
        for ln in f:
            p = ln.split(None, 2)
            if len(p) < 2:
                continue
            fr, k = int(p[0]), p[1]
            rest = p[2].strip() if len(p) > 2 else ""
            if k == "G":
                states.append((fr, int(rest, 16)))
            elif k == "W":
                samples[fr] = int(rest)
            else:
                ev[fr].append((k, rest))
    return ev, states, samples


def sync_frame(states, sync):
    want = [int(x) for x in sync.split("/") if x != ""]
    for fr, st in states:
        cur = [st >> 16, (st >> 8) & 0xFF, st & 0xFF]
        if cur[: len(want)] == want:
            return fr
    raise SystemExit("resync state %s not in the log" % sync)


def state_at(states, fr):
    s = 0
    for f, st in states:
        if f > fr:
            break
        s = st
    return "%d/%d/%d" % (s >> 16, (s >> 8) & 0xFF, s & 0xFF)


# ---- the TSD byte stream (port/audio/tsd_client.c serializer, AUDIO.md 4.2) --
def decode_tsd(hexs):
    b = bytes.fromhex(hexs)
    out, i = [], 0
    while i < len(b):
        c = b[i]
        if c == 0xFF:
            break
        if c < 0x10:
            n = 4 + (c & 1) + ((c >> 1) & 1) + (2 if c & 4 else 0)
            bank, snd, h = b[i + 1], b[i + 2], b[i + 3]
            j = i + 4
            vol = pan = pitch = None
            if c & 1:
                vol = b[j]; j += 1
            if c & 2:
                pan = b[j]; j += 1
            if c & 4:
                pitch = b[j] << 8 | b[j + 1]; j += 2
            kind = "stop" if c == 8 else ("chg" if c & 8 else "play")
            args = "%02X:%02X:%02X" % (bank, snd, h)
            if kind != "stop":
                args += " v=%s p=%s b=%s" % (vol, pan, pitch)
            out.append("%s %s" % (kind, args))
            i += n
            continue
        n = {0x28: 1, 0x29: 3, 0x40: 1, 0x41: 2, 0x42: 2, 0x48: 2, 0x4D: 21, 0x77: 5}.get(c)
        if n is None:
            out.append("raw " + b[i:].hex().upper())
            break
        if c == 0x4D:  # bank load: the addresses are host/EE specific
            out.append("bank %d" % (b[i + 1] << 8 | b[i + 2]))
        else:
            out.append("cmd " + b[i:i + n].hex().upper())
        i += n
    return out


def commands(ev, base, lo, hi, with_status):
    """[(rel_frame, text)] in order"""
    res = []
    for fr in sorted(ev):
        r = fr - base
        if r < lo or r > hi:
            continue
        for k, t in ev[fr]:
            if k == "T":
                res.extend((r, "tsd " + c) for c in decode_tsd(t))
            elif k == "A":
                if t == "stop" and res and res[-1] == (r, "adxt start " + res[-1][1][11:]) and res[-1][1].startswith("adxt start"):
                    continue  # ADXT_StartAfs's own ADXT_Stop (older mvc2_av logs)
                res.append((r, "adxt " + t))
            elif k == "S" and with_status and t.startswith("4 "):
                res.append((r, "status " + t))
    return res


def match(pc, oc, tol):
    """greedy in-order matching per command text, within tol frames"""
    by = defaultdict(list)
    for i, (fr, t) in enumerate(oc):
        by[t].append([fr, i, False])
    only_p, late = [], []
    used = set()
    for fr, t in pc:
        best = None
        for cand in by.get(t, ()):
            if cand[2]:
                continue
            d = cand[0] - fr
            if abs(d) <= tol and (best is None or abs(d) < abs(best[0] - fr)):
                best = cand
            if cand[0] - fr > tol:
                break
        if best is None:
            only_p.append((fr, t))
        else:
            best[2] = True
            used.add(best[1])
            if best[0] != fr:
                late.append((fr, best[0], t))
    only_o = [oc[i] for i in range(len(oc)) if i not in used]
    return only_p, only_o, late


def cmd_snd(a):
    pev, pst, _ = read_log(a.port)
    oev, ost, _ = read_log(a.oracle)
    pb, ob = sync_frame(pst, a.sync), sync_frame(ost, a.sync)
    pc = commands(pev, pb, a.frm, a.to, a.status)
    oc = commands(oev, ob, a.frm, a.to, a.status)
    only_p, only_o, late = match(pc, oc, a.tol)
    print("sync %s: port frame %d = oracle frame %d" % (a.sync, pb, ob))
    print("commands: port %d, oracle %d; matched %d (%d on another frame, within %d); only port %d; only oracle %d"
          % (len(pc), len(oc), len(pc) - len(only_p), len(late), a.tol, len(only_p), len(only_o)))
    kinds = defaultdict(lambda: [0, 0])
    for fr, t in only_p:
        kinds[t.split()[0] + " " + t.split()[1]][0] += 1
    for fr, t in only_o:
        kinds[t.split()[0] + " " + t.split()[1]][1] += 1
    for k in sorted(kinds):
        print("  unmatched %-12s port %5d  oracle %5d" % (k, kinds[k][0], kinds[k][1]))
    allx = [(fr, "port  ", t) for fr, t in only_p] + [(fr, "oracle", t) for fr, t in only_o]
    allx.sort()
    for fr, who, t in allx[: a.show]:
        print("  +%-6d %s only: %-40s (%s)" % (fr, who, t, state_at(pst, fr + pb)))
    if late:
        print("timing (port frame -> oracle frame):")
        for fp, fo, t in late[: a.show]:
            print("  +%-6d -> +%-6d %s" % (fp, fo, t))


# ---- mixed audio --------------------------------------------------------------
def read_wav(path):
    import numpy as np
    import wave
    import struct
    with open(path, "rb") as f:
        d = f.read()
    # minimal RIFF walk (the port writes float32, the oracle s16)
    pos, fmt, data = 12, None, None
    while pos + 8 <= len(d):
        cid, sz = d[pos:pos + 4], struct.unpack("<I", d[pos + 4:pos + 8])[0]
        body = d[pos + 8:pos + 8 + sz]
        if cid == b"fmt ":
            fmt = struct.unpack("<HHIIHH", body[:16])
        elif cid == b"data":
            data = body
        pos += 8 + sz + (sz & 1)
    tag, ch, rate, _, _, bits = fmt
    if tag == 3 or bits == 32:
        x = np.frombuffer(data, dtype="<f4").astype(np.float64)
    else:
        x = np.frombuffer(data[: len(data) // 2 * 2], dtype="<i2").astype(np.float64) / 32768.0
    return x.reshape(-1, ch), rate


def env(x, samples, base, lo, hi):
    import numpy as np
    out = {}
    for fr in range(lo, hi + 1):
        a, b = samples.get(fr + base), samples.get(fr + base + 1)
        if a is None or b is None or b <= a or b > len(x):
            continue
        seg = x[a:b]
        out[fr] = 10 * np.log10(np.mean(seg * seg) + 1e-12)
    return out


def cmd_audio(a):
    import numpy as np
    px, prate = read_wav(a.port_wav)
    ox, orate = read_wav(a.oracle_wav)
    _, pst, psm = read_log(a.port)
    _, ost, osm = read_log(a.oracle)
    pb, ob = sync_frame(pst, a.sync), sync_frame(ost, a.sync)
    lo = a.frm
    hi = min(max(psm) - pb, max(osm) - ob, a.to) - 1
    pe, oe = env(px, psm, pb, lo, hi), env(ox, osm, ob, lo, hi)
    fr = sorted(set(pe) & set(oe))
    P = np.array([pe[f] for f in fr])
    O = np.array([oe[f] for f in fr])
    print("audio: port %d Hz, oracle %d Hz; %d frames compared (+%d..+%d)" % (prate, orate, len(fr), fr[0], fr[-1]))
    loud = (P > -50) & (O > -50)
    print("  mean level: port %.1f dB, oracle %.1f dB (where both sound: port-oracle %.1f dB)"
          % (P.mean(), O.mean(), (P[loud] - O[loud]).mean() if loud.any() else float("nan")))
    for lag in range(-6, 7):
        if lag >= 0:
            c = np.corrcoef(P[lag:], O[: len(O) - lag])[0, 1]
        else:
            c = np.corrcoef(P[:lag], O[-lag:])[0, 1]
        print("  envelope correlation, oracle %+d frames: %.3f" % (-lag, c))
    # sections: per 300 frames
    print("  per 300 frames: [rel frame] state, port dB, oracle dB, corr")
    for s in range(0, len(fr), 300):
        p, o = P[s:s + 300], O[s:s + 300]
        c = np.corrcoef(p, o)[0, 1] if len(p) > 2 and p.std() > 0 and o.std() > 0 else float("nan")
        print("   +%-6d %-8s %6.1f %6.1f %6.2f" % (fr[s], state_at(pst, fr[s] + pb), p.mean(), o.mean(), c))
    sil_p = [f for f, p, o in zip(fr, P, O) if p < -60 and o > -35]
    sil_o = [f for f, p, o in zip(fr, P, O) if o < -60 and p > -35]
    print("  frames where only the oracle sounds: %d %s" % (len(sil_p), runs(sil_p)[:10]))
    print("  frames where only the port sounds:   %d %s" % (len(sil_o), runs(sil_o)[:10]))


def runs(fr):
    out = []
    for f in fr:
        if out and f == out[-1][1] + 1:
            out[-1][1] = f
        else:
            out.append([f, f])
    return ["%d-%d" % (a, b) if a != b else str(a) for a, b in out]


# ---- images -----------------------------------------------------------------
def load_port(path, dy=0, dx=0):
    """the port's rows 0..447 as 224 lines (row pairs averaged), optionally
    shifted by dy rows (448-line units) and dx columns first"""
    import numpy as np
    from PIL import Image
    im = np.asarray(Image.open(path).convert("RGB"), dtype=np.float32)[:448]
    if dy or dx:
        im = np.roll(np.roll(im, dy, axis=0), dx, axis=1)
    return (im[0::2] + im[1::2]) * 0.5


SHIFTS = [(0, 0)] + [(dy, dx) for dy in (-2, -1, 1, 2) for dx in (-1, 0, 1)] + [(0, -1), (0, 1)]


def best_shift(path, q):
    """design difference: the port rasterizes 448 progressive lines, the GS
    224 (and Play!'s GL samples pixel centres at +0.5, the GS at the integer
    corner): allow a global shift of up to 2 port rows / 1 column"""
    import numpy as np
    best = None
    for dy, dx in SHIFTS:
        p = load_port(path, dy, dx)
        e = float(np.abs(p - q)[4:-4, 4:-4].mean())
        if best is None or e < best[0]:
            best = (e, dy, dx, p)
    return best


def load_oracle(path):
    import numpy as np
    from PIL import Image
    return np.asarray(Image.open(path).convert("RGB"), dtype=np.float32)[:224]


def metrics(p, o):
    import numpy as np
    d = np.abs(p - o)
    mx = d.max(axis=2)
    cells = mx.reshape(8, 28, 8, 80).mean(axis=(1, 3))
    return float(d.mean()), float((mx > 32).mean() * 100), cells


def cmd_img(a):
    import numpy as np
    from PIL import Image
    _, pst, _ = read_log(a.port)
    _, ost, _ = read_log(a.oracle)
    pb, ob = sync_frame(pst, a.sync), sync_frame(ost, a.sync)
    pf = {int(m.group(1)): os.path.join(a.port_dir, n) for n in os.listdir(a.port_dir)
          for m in [re.match(r"f(\d+)\.png$", n)] if m}
    of = {int(m.group(1)): os.path.join(a.oracle_dir, n) for n in os.listdir(a.oracle_dir)
          for m in [re.match(r"f(\d+)\.png$", n)] if m}
    rel = sorted(f - pb for f in pf if a.frm <= f - pb <= a.to)
    lat = a.lat
    if lat is None:
        best = None
        for L in range(0, 4):
            errs = [metrics(load_port(pf[r + pb]), load_oracle(of[r + ob + L]))[0]
                    for r in rel[:: max(1, len(rel) // 12)] if r + ob + L in of]
            if errs and (best is None or np.mean(errs) < best[1]):
                best = (L, float(np.mean(errs)))
        lat = best[0] if best else 0
        print("display latency (oracle frames after the port's): %d" % lat)
    rows = []
    for r in rel:
        o = of.get(r + ob + lat)
        if not o:
            continue
        q = load_oracle(o)
        raw = metrics(load_port(pf[r + pb]), q)[0]
        _, dy, dx, p = best_shift(pf[r + pb], q) if a.shift else (0, 0, 0, load_port(pf[r + pb]))
        mae, bad, cells = metrics(p, q)
        rows.append((r, mae, bad, cells, raw, dy, dx))
    scenes = []
    if a.scenes:
        for ln in open(a.scenes):
            ln = ln.split("#")[0].split()
            if len(ln) >= 3:
                scenes.append((int(ln[0]), int(ln[1]), " ".join(ln[2:])))
    print("sync %s: port %d = oracle %d, latency %d; %d frame pairs" % (a.sync, pb, ob, lat, len(rows)))
    print("%-8s %-8s %7s %7s %7s %5s  worst cells (col,row: mean max-channel diff)" % ("frame", "state", "MAE", "%>32", "MAE0", "dy,dx"))
    for r, mae, bad, cells, raw, dy, dx in rows:
        idx = np.argsort(cells, axis=None)[::-1][:3]
        cs = " ".join("%d,%d:%.0f" % (i % 8, i // 8, cells.flat[i]) for i in idx)
        print("+%-7d %-8s %7.2f %7.2f %7.2f %2d,%-2d  %s" % (r, state_at(pst, r + pb), mae, bad, raw, dy, dx, cs))
    if scenes:
        print("\nper scene (rel frames): frames, mean MAE, mean %>32, worst frame")
        for lo, hi, name in scenes:
            sel = [x for x in rows if lo <= x[0] <= hi]
            if not sel:
                continue
            w = max(sel, key=lambda x: x[1])
            print("  %-28s %5d %7.2f %7.2f  +%d (%.2f)" % (name, len(sel), np.mean([x[1] for x in sel]),
                                                        np.mean([x[2] for x in sel]), w[0], w[1]))
    if a.out:
        os.makedirs(a.out, exist_ok=True)
        for r, mae, bad, cells, raw, dy, dx in sorted(rows, key=lambda x: -x[1])[: a.worst]:
            p = load_port(pf[r + pb], dy, dx)
            q = load_oracle(of[r + ob + lat])
            d = np.clip(np.abs(p - q) * 4, 0, 255)
            strip = np.concatenate([p, q, d], axis=0).astype(np.uint8)
            Image.fromarray(strip).save(os.path.join(a.out, "w%06d_mae%03d.png" % (r, int(mae))))


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest="cmd", required=True)
    s = sp.add_parser("snd")
    s.add_argument("port"); s.add_argument("oracle")
    s.add_argument("--status", action="store_true", help="also TSD status fno 4 queries")
    s = [s, sp.add_parser("audio"), sp.add_parser("img")]
    s[1].add_argument("port_wav"); s[1].add_argument("port"); s[1].add_argument("oracle_wav"); s[1].add_argument("oracle")
    s[2].add_argument("port_dir"); s[2].add_argument("oracle_dir"); s[2].add_argument("port"); s[2].add_argument("oracle")
    s[2].add_argument("--lat", type=int); s[2].add_argument("--out"); s[2].add_argument("--worst", type=int, default=8)
    s[2].add_argument("--scenes")
    s[2].add_argument("--no-shift", dest="shift", action="store_false", help="no shift tolerance")
    for x in s:
        x.add_argument("--sync", default="1/1/0")
        x.add_argument("--tol", type=int, default=2)
        x.add_argument("--from", dest="frm", type=int, default=0)
        x.add_argument("--to", type=int, default=10 ** 9)
        x.add_argument("--show", type=int, default=60)
    a = ap.parse_args()
    {"snd": cmd_snd, "audio": cmd_audio, "img": cmd_img}[a.cmd](a)


if __name__ == "__main__":
    main()
