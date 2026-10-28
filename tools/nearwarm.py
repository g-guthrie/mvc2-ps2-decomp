#!/usr/bin/env python3
"""nearwarm2.py ADDR [COMPILER]: nearest preceding double-arithmetic functions with
their credited source and that source's compiler; with COMPILER (MWCCPS2,
MWCCPS2_30, MWCCPS2_30B22) print the nearest one built by that compiler."""
import csv, re, struct, sys
rom = open('private/SLUS_204.86.rom', 'rb').read()
H = {0x119510, 0x119568, 0x1195D0, 0x119858}
fn = sorted((int(r['address'], 0), int(r['size'], 0), r['name']) for r in csv.DictReader(open('config/functions.csv')))
cred = {r[0]: r[3] for r in csv.reader(open('config/matches.csv')) if r and r[0] != 'name'}
comp = {}
sh = open('tools/compile_matching.sh').read()
for m in re.finditer(r'"\$(MWCCPS2\w*)"\s*\\?\s*\n?\s*(?:-i src\s+)?((?:src/\S+\.c\s+)+)-c', sh):
    srcs = m.group(2).split()
    comp.setdefault(srcs[-1], m.group(1))
def dbl(a, n):
    for i in range(a - 0x100000, a - 0x100000 + n, 4):
        w = struct.unpack_from('<I', rom, i)[0]
        if w >> 26 == 3 and ((w & 0x3FFFFFF) << 2) in H: return True
    return False
t = int(sys.argv[1], 16); want = sys.argv[2] if len(sys.argv) > 2 else None
k = 0
for a, n, name in reversed([f for f in fn if f[0] < t]):
    if not dbl(a, n): continue
    src = cred.get(name, 'UNCREDITED'); c = comp.get(src, '?')
    if want is None:
        print(hex(t), '->', name, src, c); k += 1
        if k >= 5: break
    elif c == want:
        print(hex(t), '->', name, src, c); break
