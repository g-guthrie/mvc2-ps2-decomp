#!/usr/bin/env python3
"""CRI AFS archive reader on top of iso.py (stdlib only, no asset bytes).

AFS layout: "AFS\\0", u32 count, count x {u32 offset, u32 size} (offsets from
archive start, 2048-aligned), then {u32 nameTableOffset, u32 nameTableSize}.
Name table (only AFS02): 48-byte entries {char name[32]; u16 y,m,d,h,mi,s; u32 size}.

Partitions as mounted by func_004189A0: ptid 0..3 = /PS2/AFS00..AFS03.AFS.

    from afs import Afs
    a = Afs(iso, 2); a.entries -> [(offset, size, name)]; a.read(209)
CLI: afs.py ISO list PTID | extract PTID INDEX OUT | extract-all PTID OUTDIR
"""
import os, struct, sys
from iso import Iso


class Afs:
    def __init__(self, iso, ptid):
        self.iso = iso if isinstance(iso, Iso) else Iso(iso)
        self.ptid = ptid
        self.path = '/PS2/AFS%02d.AFS' % ptid
        self.base, self.size = self.iso.open_range(self.path)
        hdr = self.iso.read(self.path, 0, 8)
        if hdr[:4] != b'AFS\0':
            raise ValueError('bad AFS magic')
        n = struct.unpack_from('<I', hdr, 4)[0]
        tab = self.iso.read(self.path, 8, 8 * (n + 1))
        ents = [struct.unpack_from('<II', tab, 8 * i) for i in range(n)]
        nt_off, nt_size = struct.unpack_from('<II', tab, 8 * n)
        names = [''] * n
        if nt_off and nt_size >= 48 * n:
            nt = self.iso.read(self.path, nt_off, nt_size)
            names = [nt[48 * i:48 * i + 32].split(b'\0')[0].decode('latin1')
                     for i in range(n)]
        self.entries = [(o, s, names[i]) for i, (o, s) in enumerate(ents)]

    def __len__(self):
        return len(self.entries)

    def read(self, index):
        o, s, _ = self.entries[index]
        return self.iso.read(self.path, o, s)

    def name(self, index):
        return self.entries[index][2] or ('%03d.bin' % index)

    def find(self, name):
        for i, (_, _, n) in enumerate(self.entries):
            if n.upper() == name.upper():
                return i
        raise KeyError(name)


if __name__ == '__main__':
    iso = Iso(sys.argv[1])
    cmd, pt = sys.argv[2], int(sys.argv[3])
    a = Afs(iso, pt)
    if cmd == 'list':
        for i, (o, s, n) in enumerate(a.entries):
            print('%4d 0x%08x %9d %s' % (i, o, s, n))
    elif cmd == 'extract':
        open(sys.argv[5], 'wb').write(a.read(int(sys.argv[4])))
    elif cmd == 'extract-all':
        os.makedirs(sys.argv[4], exist_ok=True)
        for i in range(len(a)):
            open(os.path.join(sys.argv[4], '%03d_%s' % (i, a.name(i))), 'wb').write(a.read(i))
