#!/usr/bin/env python3
"""MIPS (R5900) index of the PS2 MvC2 executable from the decomp's asm/main.s.

Writes a pickle of derived facts: function extents (glabel/endlabel), and
per function the jal targets, address references (lui/addiu pairs), float
constants (lui+mtc1), integer immediates, compare immediates, field offsets
of loads/stores, and the branch count.  Also the data words of the image
(the labelled .word lines) as {address: word} for the pointer tables, the
same facts the comments of main.s already carry; nothing is copied from
the disc.

    python3 -I mipsidx.py asm/main.s OUT.pkl
"""
import pickle
import re
import sys

LINE = re.compile(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ([0-9A-F]{8}) \*/\s+(\S+)')
GPREL = re.compile(r'%gp_rel\(D_([0-9A-F]{8})\)')
GP = [None]


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def parse(path):
    funcs = {}
    words = {}
    dl = {}
    dcur = None
    cur = None
    insns = []
    with open(path, errors='replace') as fh:
        for line in fh:
            if line.startswith('glabel '):
                name = line.split()[1]
                if name.startswith('func_') or not cur:
                    cur = name
                    insns = []
                continue
            if line.startswith('dlabel '):
                dcur = [None, None]
                dl[line.split()[1]] = dcur
                continue
            if line.startswith('enddlabel '):
                dcur = None
                continue
            if line.startswith('endlabel ') and cur and line.split()[1] == cur:
                if insns:
                    funcs[insns[0][0]] = (cur, insns)
                cur = None
                continue
            m = LINE.search(line)
            if not m:
                continue
            if GP[0] is None and '%gp_rel(D_' in line:
                g = GPREL.search(line)
                w = int.from_bytes(bytes.fromhex(m.group(2)), 'little')
                GP[0] = (int(g.group(1), 16) - s16(w & 0xFFFF)) & 0xFFFFFFFF
            a = int(m.group(1), 16)
            b = bytes.fromhex(m.group(2))
            w = int.from_bytes(b, 'little')
            if dcur is not None:
                if dcur[0] is None:
                    dcur[0] = a
                dcur[1] = a + 4
            if m.group(3) == '.word':
                words[a] = w
            elif cur:
                insns.append((a, w))
            else:
                words[a] = w
    return funcs, words, {v[0]: v[1] for v in dl.values() if v[0] is not None}


def split(funcs, words):
    """Split a glabel function where a data word points into it just after
    an unconditional jump and its delay slot (the per-state handlers that
    the asm files run together after a dispatch `jr`)."""
    targets = set(words.values())
    out = {}
    for a, (name, insns) in funcs.items():
        cut = [0]
        for i in range(2, len(insns)):
            w = insns[i - 2][1]
            uncond = (w & 0xFC1FFFFF) == 0x00000008 or (w >> 26) == 2 or (w & 0xFFFF0000) == 0x10000000
            if insns[i][0] in targets and uncond:
                cut.append(i)
        cut.append(len(insns))
        for k in range(len(cut) - 1):
            part = insns[cut[k]:cut[k + 1]]
            if part:
                out[part[0][0]] = (name if k == 0 else '%s_%08X' % (name, part[0][0]), part)
    return out


def analyse(name, insns):
    f = {'name': name, 'start': insns[0][0], 'end': insns[-1][0] + 4, 'n': len(insns), 'calls': [], 'tails': [],
         'refs': [], 'fnptrs': [], 'floats': [], 'ints': [], 'imm': [], 'cmpimm': [], 'offs': [], 'adds': [],
         'branches': 0, 'frefs': [], 'luis': []}
    lui = {}
    for a, w in insns:
        op = w >> 26
        rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
        imm = w & 0xFFFF
        if op == 3:
            f['calls'].append((a & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
            continue
        if op == 2:
            f['tails'].append((a & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
            f['calls'].append(f['tails'][-1])
            continue
        if op == 0xF:
            lui[rt] = imm << 16
            f['luis'].append(imm << 16)
            continue
        if op == 0x11 and rs == 4:  # mtc1 rt, fs
            f['floats'].append(lui.get(rt, 0) if rt else 0)
            continue
        if op in (9, 0x19, 0xD):  # addiu/daddiu/ori
            if rs == 0:
                f['imm'].append(s16(imm) if op != 0xD else imm)
                lui.pop(rt, None)
            elif rs in lui:
                v = (lui[rs] + (s16(imm) if op != 0xD else imm)) & 0xFFFFFFFF
                if 0x00100000 <= v < 0x02000000:
                    f['refs'].append(v)
                else:
                    lui[rt] = v
                    if op == 0xD:
                        f['ints'].append(v)
                    continue
                lui.pop(rt, None)
            elif rs not in (29,):
                f['adds'].append(s16(imm))
                lui.pop(rt, None)
            continue
        if op in (0xA, 0xB):  # slti/sltiu
            f['cmpimm'].append(s16(imm))
            continue
        if op in (4, 5, 6, 7, 0x14, 0x15, 0x16, 0x17, 1) or (op == 0x11 and rs == 8):
            f['branches'] += 1
            continue
        if op in (0x20, 0x24, 0x28):
            kind = 'b'
        elif op in (0x21, 0x25, 0x29):
            kind = 'w'
        elif op in (0x23, 0x27, 0x2B, 0x37, 0x3F, 0x1E, 0x1F):
            kind = 'l'
        elif op in (0x31, 0x39):
            kind = 'f'
        else:
            kind = None
        if kind:
            if rs == 28 and GP[0]:
                f['refs'].append((GP[0] + s16(imm)) & 0xFFFFFFFF)
                if op == 0x31:
                    f['frefs'].append(f['refs'][-1])
            elif rs in lui and lui[rs] >= 0x00100000:
                f['refs'].append((lui[rs] + s16(imm)) & 0xFFFFFFFF)
                if op == 0x31:
                    f['frefs'].append(f['refs'][-1])
            elif rs not in (29,):
                f['offs'].append((kind, s16(imm)))
            if op < 0x28 and op not in (0x31, 0x39, 0x1F):
                lui.pop(rt, None)
            continue
        if op == 0 and rd:
            lui.pop(rd, None)
    return f


def main():
    src, out = sys.argv[1], sys.argv[2]
    funcs, words, tables = parse(src)
    funcs = split(funcs, words)
    idx = {'funcs': {}, 'names': {}, 'words': words, 'tables': tables}
    for a, (name, insns) in funcs.items():
        idx['funcs'][a] = analyse(name, insns)
        idx['names'][name] = a
    with open(out, 'wb') as fh:
        pickle.dump(idx, fh)
    print(len(idx['funcs']), 'functions', len(words), 'data words')


if __name__ == '__main__':
    main()
