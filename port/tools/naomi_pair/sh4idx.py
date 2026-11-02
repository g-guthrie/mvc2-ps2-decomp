#!/usr/bin/env python3
"""SH-4 index of the NAOMI MvC2 program (mvsc2 Rev A, epr-23085a.ic11).

Reads the program ROM from the NAOMI decomp checkout (its orig/mvsc2.zip,
checked against config/target.json) at run time and writes a pickle of
derived facts only: function entries and extents, and per function the
calls, literal-pool references, constants, field offsets and branch counts.
No ROM bytes are written.

    python3 -I sh4idx.py NAOMI_DECOMP_ROOT OUT.pkl

Function entries: call targets (BSR, JSR/JMP through a PC-relative
literal), code addresses found in literal pools and in data ranges,
exported symbols of units.json, and mapping.json code ranges whose evidence
names them as a CFG walk start or a prologue.  A function runs from its
entry to the next entry (decoded only inside mapping.json code ranges).
"""
import bisect
import json
import pickle
import re
import struct
import sys
import zipfile
from pathlib import Path

BASE = 0x0C021000


def load_image(root):
    root = Path(root)
    t = json.loads((root / 'config/target.json').read_text())
    with zipfile.ZipFile(root / t['archive']) as z:
        prog = z.read(t['program_rom'])
    m = t['main']
    img = prog[m['rom_offset']:m['rom_offset'] + m['size']]
    return img


def s8(v):
    return v - 256 if v & 0x80 else v


def s12(v):
    return v - 4096 if v & 0x800 else v


def is_floaty(v):
    """Literal word that reads as an ordinary float constant (|x| in 2^-31..2^32)."""
    return 0x60 <= (v >> 23) & 0xFF <= 0x9F


def looks_like_entry(im, a):
    """First instruction of a function in unmapped bytes: a push, PR save,
    PC-relative load, register move, small immediate, displacement load,
    stack adjust, RTS or an FPU push -- and not the first of a run of
    pointer words (0x0C0xxxxx / 0x0C2xxxxx little-endian)."""
    w = im.u16(a)
    if a % 4 == 0 and (im.u16(a + 2) & 0xFFF0) in (0x0C00, 0x0C10, 0x0C20):
        return False
    return ((w & 0xFF0F) == 0x2F06 or w == 0x4F22 or w >> 12 in (0x9, 0xD, 0xE) or (w & 0xF00F) == 0x6003
            or (w & 0xFF00) in (0x8400, 0x8500, 0x7F00) or w == 0x000B or (w & 0xFF0F) == 0xFF0B
            or (w & 0xF000) == 0x5000 or (w & 0xF00F) in (0x600C, 0x6002, 0x0002))


class Img:
    def __init__(self, img):
        self.img = img
        self.end = BASE + len(img)

    def u16(self, a):
        return struct.unpack_from('<H', self.img, a - BASE)[0]

    def u32(self, a):
        return struct.unpack_from('<I', self.img, a - BASE)[0]

    def inimg(self, a):
        return BASE <= a < self.end


def build(root):
    root = Path(root)
    im = Img(load_image(root))
    mp = json.loads((root / 'config/mapping.json').read_text())['ranges']
    code = sorted((int(r['address'], 16), int(r['address'], 16) + r['size'], r.get('evidence', ''))
                  for r in mp if r['kind'] == 'code')
    data = sorted((int(r['address'], 16), int(r['address'], 16) + r['size'])
                  for r in mp if r['kind'] == 'data')
    truecode = [(s, e) for s, e, _ in code]
    tstarts = [c[0] for c in truecode]

    def intrue(a):
        i = bisect.bisect_right(tstarts, a) - 1
        return i >= 0 and truecode[i][0] <= a < truecode[i][1]
    # bytes the mapping has not classified (about 66 KB) are decoded as code
    # when an entry falls in them (several vtable targets do)
    allr = sorted([(s, e) for s, e, _ in code] + data)
    pos = BASE
    for s, e in allr + [(im.end, im.end)]:
        if s > pos:
            code.append((pos, s, 'unmapped'))
        pos = max(pos, e)
    code.sort()
    cstarts = [c[0] for c in code]

    def incode(a):
        i = bisect.bisect_right(cstarts, a) - 1
        return i >= 0 and code[i][0] <= a < code[i][1]

    entries = set()
    for s, e, ev in code:
        if ev == 'unmapped':
            continue
        m = re.search(r'(?:CFG walk from|prologue starts at) (0x[0-9a-f]+)', ev)
        if m and int(m.group(1), 16) == s:
            entries.add(s)
    for u in json.loads((root / 'config/units.json').read_text()):
        for k, v in u.get('exports', {}).items():
            a = int(v, 16)
            if intrue(a):
                entries.add(a)
    # pointers in data ranges and in unmapped bytes (everything outside code)
    for a in range(BASE, im.end - 3, 4):
        if not intrue(a):
            v = im.u32(a)
            if v & 1 == 0 and intrue(v):
                entries.add(v)
            elif v & 1 == 0 and incode(v):
                # a target in unmapped bytes counts when a word within 8 of
                # it (the same table) points into mapped code
                nb = [im.u32(x) for x in range(a - 32, a + 36, 4) if x != a and BASE <= x < im.end - 3]
                if any(intrue(x) for x in nb) and looks_like_entry(im, v):
                    entries.add(v)
    # decode code: calls and literal code pointers.  Mapped code is scanned
    # whole; an unmapped range only from an entry inside it, to its end.
    def scan(s, e):
        regs = {}
        for pc in range(s, e, 2):
            w = im.u16(pc)
            hi = w >> 12
            n = (w >> 8) & 15
            if hi == 0xD:
                la = ((pc + 4) & ~3) + (w & 255) * 4
                if im.inimg(la):
                    v = im.u32(la)
                    regs[n] = v
                    if v & 1 == 0 and intrue(v):
                        found.add(v)
                continue
            if hi == 0xB:
                found.add(pc + 4 + s12(w & 0xFFF) * 2)
            if w & 0xF0FF in (0x400B, 0x402B) and n in regs:
                v = regs[n]
                if incode(v):
                    found.add(v)
            if hi in (0x6, 0x7, 0xE, 0x9, 0x5, 0x3) or (hi == 0 and (w & 15) in (0xC, 0xD, 0xE, 0xA, 0x9)):
                regs.pop(n, None)

    found = set()
    for s, e, ev in code:
        if ev != 'unmapped':
            scan(s, e)
    done = set()
    while True:
        entries |= {x for x in found if intrue(x) or (incode(x) and looks_like_entry(im, x))}
        todo = [x for x in entries if x not in done and not intrue(x)]
        if not todo:
            break
        found = set()
        for x in todo:
            done.add(x)
            i = bisect.bisect_right(cstarts, x) - 1
            scan(x, code[i][1])
    ent = sorted(entries)
    funcs = {}
    for i, a in enumerate(ent):
        nxt = ent[i + 1] if i + 1 < len(ent) else im.end
        funcs[a] = analyse(im, a, nxt, code, cstarts, lambda v: v in entries)
        funcs[a]['unmapped'] = not intrue(a)
    return {'base': BASE, 'end': im.end, 'funcs': funcs, 'code': [(s, e) for s, e, _ in code],
            'data': data}


def analyse(im, a, nxt, code, cstarts, incode):
    """Features of the function at a (instructions in code ranges up to nxt)."""
    f = {'start': a, 'end': nxt, 'n': 0, 'calls': [], 'tails': [], 'refs': [], 'fnptrs': [], 'floats': [],
         'ints': [], 'imm': [], 'cmpimm': [], 'offs': [], 'adds': [], 'branches': 0, 'w16': [], 'size': 0}
    i = bisect.bisect_right(cstarts, a) - 1
    pcs = []
    while i < len(code) and code[i][0] < nxt:
        s, e = max(code[i][0], a), min(code[i][1], nxt)
        if s < e:
            pcs.extend(range(s, e, 2))
        i += 1
    regs = {}
    for pc in pcs:
        w = im.u16(pc)
        f['n'] += 1
        hi, n, m, lo = w >> 12, (w >> 8) & 15, (w >> 4) & 15, w & 15
        if hi == 0xD:
            la = ((pc + 4) & ~3) + (w & 255) * 4
            if not im.inimg(la):
                continue
            v = im.u32(la)
            regs[n] = v
            if 0x0C000000 <= v < 0x0D000000 or 0x8C000000 <= v < 0x8D000000 or 0xAC000000 <= v < 0xAD000000:
                if incode(v):
                    f['fnptrs'].append(v)
                else:
                    f['refs'].append(v)
            elif is_floaty(v):
                f['floats'].append(v)
            else:
                f['ints'].append(v)
            continue
        if w >> 8 == 0xC7:  # mova @(disp,PC),R0: a float or table in the pool
            la = ((pc + 4) & ~3) + (w & 255) * 4
            regs[0] = la
            if im.inimg(la) and is_floaty(im.u32(la)):
                f['floats'].append(im.u32(la))
            continue
        if hi == 0x9:
            la = pc + 4 + (w & 255) * 2
            v = im.u16(la)
            v = v - 0x10000 if v & 0x8000 else v
            regs[n] = v
            f['w16'].append(v)
            continue
        if hi == 0xE:
            regs[n] = s8(w & 255)
            f['imm'].append(s8(w & 255))
            continue
        if w & 0xFF00 == 0x8800:
            f['cmpimm'].append(s8(w & 255))
            continue
        if hi == 0xB:
            f['calls'].append(pc + 4 + s12(w & 0xFFF) * 2)
            for r in range(8):
                regs.pop(r, None)
            continue
        if w & 0xF0FF == 0x400B:
            f['calls'].append(regs.get(n))
            for r in range(8):
                regs.pop(r, None)
            continue
        if w & 0xF0FF == 0x402B:
            v = regs.get(n)
            f['tails'].append(v)
            if v is not None and incode(v):
                f['calls'].append(v)
            continue
        if hi == 0xA:
            t = pc + 4 + s12(w & 0xFFF) * 2
            if not a <= t < nxt:     # BRA out of the function: a tail call
                f['calls'].append(t)
                f['tails'].append(t)
                continue
        if w & 0xFF00 in (0x8900, 0x8B00, 0x8D00, 0x8F00) or hi == 0xA:
            f['branches'] += 1
            continue
        # field accesses
        if w & 0xFF00 in (0x8400, 0x8000):
            f['offs'].append(('b', w & 15))
        elif w & 0xFF00 in (0x8500, 0x8100):
            f['offs'].append(('w', (w & 15) * 2))
        elif hi in (0x5, 0x1):
            f['offs'].append(('l', lo * 4))
        elif hi == 0 and lo in (0xC, 0xD, 0xE, 0x4, 0x5, 0x6) and 0 in regs and isinstance(regs[0], int) and 0 <= regs[0] < 0x2000:
            f['offs'].append(('bwl'[(lo - 4) % 4 if lo < 8 else (lo - 0xC)], regs[0]))
        elif hi == 0xF and lo in (6, 7) and 0 in regs and 0 <= regs[0] < 0x2000:
            f['offs'].append(('f', regs[0]))
        elif hi == 0x7:
            f['adds'].append(s8(w & 255))
        if w & 0xF00F == 0x6003:   # mov Rm,Rn copies a known value
            if m in regs:
                regs[n] = regs[m]
            else:
                regs.pop(n, None)
            continue
        # register writes (approximate)
        if hi in (0x6, 0x7, 0x5, 0x3) or (hi == 0 and lo in (0xC, 0xD, 0xE, 0xA, 0x9, 0x2)) or (hi == 0x4 and lo in (0x0, 0x1, 0x4, 0x5, 0x8, 0x9, 0xA)):
            regs.pop(n, None)
        if w & 0xFF00 in (0x8400, 0x8500, 0xC400, 0xC500, 0xC600, 0xC700, 0xC900, 0xCA00, 0xCB00, 0xCD00, 0xCE00, 0xCF00):
            regs.pop(0, None)
        if hi == 0xF and lo == 0xD and (w & 0xFF) == 0x0D:  # fsts FPUL,FRn: no general reg
            pass
        if w & 0xF0FF == 0x005A:  # sts fpul,Rn
            regs.pop(n, None)
    f['size'] = len(pcs) * 2
    return f


def main():
    root, out = sys.argv[1], sys.argv[2]
    idx = build(root)
    with open(out, 'wb') as fh:
        pickle.dump(idx, fh)
    print(len(idx['funcs']), 'functions')


if __name__ == '__main__':
    main()
