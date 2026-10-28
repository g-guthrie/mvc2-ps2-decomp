#!/usr/bin/env python3
"""Minimal ISO9660 reader (stdlib only). Contains no asset bytes.

    from iso import Iso
    iso = Iso('private/disc/mvc2.iso')
    iso.files()            -> {'/PS2/AFS00.AFS': (lba, size), ...}
    iso.read('/FONT8_8.TM2')
    iso.open_range(path)   -> (byte_offset_in_image, size) for random access

CLI: iso.py ISO [ls | cat PATH OUT]
"""
import struct, sys

SECTOR = 2048


class Iso:
    def __init__(self, path):
        self.path = path
        self.f = open(path, 'rb')
        pvd = self._sector(16)
        if pvd[1:6] != b'CD001':
            raise ValueError('not an ISO9660 image')
        root = pvd[156:156 + 34]
        self._files = {}
        self._walk(struct.unpack_from('<I', root, 2)[0],
                   struct.unpack_from('<I', root, 10)[0], '')

    def _sector(self, lba, n=1):
        self.f.seek(lba * SECTOR)
        return self.f.read(n * SECTOR)

    def _walk(self, lba, size, prefix):
        data = self._sector(lba, (size + SECTOR - 1) // SECTOR)
        p = 0
        while p < len(data):
            ln = data[p]
            if ln == 0:  # records never straddle sectors; skip to next sector
                p = (p // SECTOR + 1) * SECTOR
                continue
            ext = struct.unpack_from('<I', data, p + 2)[0]
            sz = struct.unpack_from('<I', data, p + 10)[0]
            flags = data[p + 25]
            nl = data[p + 32]
            name = data[p + 33:p + 33 + nl]
            p += ln
            if name in (b'\0', b'\1'):
                continue
            name = name.decode('latin1').split(';')[0]
            full = prefix + '/' + name
            if flags & 2:
                self._walk(ext, sz, full)
            else:
                self._files[full.upper()] = (ext, sz)

    def files(self):
        return dict(self._files)

    def open_range(self, path):
        lba, sz = self._files[path.upper()]
        return lba * SECTOR, sz

    def read(self, path, off=0, size=None):
        base, sz = self.open_range(path)
        if size is None:
            size = sz - off
        self.f.seek(base + off)
        return self.f.read(size)


if __name__ == '__main__':
    iso = Iso(sys.argv[1])
    cmd = sys.argv[2] if len(sys.argv) > 2 else 'ls'
    if cmd == 'ls':
        for k, (lba, sz) in sorted(iso.files().items(), key=lambda kv: kv[1][0]):
            print('%-32s %7d %10d' % (k, lba, sz))
    elif cmd == 'cat':
        open(sys.argv[4], 'wb').write(iso.read(sys.argv[3]))
