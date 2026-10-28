#!/usr/bin/env python3
"""List AFS archive entries inside the user's MvC2 PS2 ISO (no asset bytes embedded).

usage: afs_inventory.py ISO FILELIST [--names ROM]
  ISO       2048-byte-sector ISO image (private/disc/mvc2.iso)
  FILELIST  "path lba size" lines (private/disc/filelist.txt)
  --names   loaded image (private/SLUS_204.86.rom): labels AFS02 entries with
            the 983-entry filename table at 0x0043CDA0 (index == AFS02 file id)
Output: one line per entry: archive idx offset size magic(hex8) guess [name]
"""
import struct, sys

def guess(b, size):
    if b[:2] == b'\x80\x00': return 'ADX'
    if b[:4] == b'TIM2': return 'TIM2'
    if b[:4] == b'AFS\0': return 'AFS'
    if b[:4] == b'\x7fELF': return 'ELF'
    if b[:4] == b'IECS': return 'IOP-SQ'
    return '?'

def table_names(rom):
    d = open(rom, 'rb').read()
    out = []
    for i in range(983):
        p = struct.unpack_from('<I', d, 0x0043CDA0 - 0x100000 + 4 * i)[0] - 0x100000
        out.append(d[p:d.index(b'\0', p)].decode('latin1'))
    return out

def main():
    iso, fl = sys.argv[1], sys.argv[2]
    names = table_names(sys.argv[4]) if len(sys.argv) > 4 and sys.argv[3] == '--names' else None
    f = open(iso, 'rb')
    for line in open(fl):
        path, lba, size = line.split()
        if not path.upper().endswith('.AFS'): continue
        base = int(lba) * 2048
        f.seek(base); hdr = f.read(8)
        assert hdr[:4] == b'AFS\0', path
        n = struct.unpack_from('<I', hdr, 4)[0]
        f.seek(base + 8); tab = f.read(8 * (n + 1))
        ents = [struct.unpack_from('<II', tab, 8 * i) for i in range(n)]
        nt_off, nt_size = struct.unpack_from('<II', tab, 8 * n)
        print('# %s files=%d nametable=%s' % (path, n, 'yes' if nt_off else 'no'))
        tnames = []
        if nt_off:
            f.seek(base + nt_off); nt = f.read(nt_size)
            tnames = [nt[48 * i:48 * i + 32].split(b'\0')[0].decode('latin1') for i in range(n)]
        for i, (off, sz) in enumerate(ents):
            f.seek(base + off); b = f.read(16)
            nm = tnames[i] if i < len(tnames) else ''
            if names and 'AFS02' in path.upper() and i < len(names): nm = nm or names[i]
            print('%s %4d 0x%08x %9d %s %-6s %s' % (path.split('/')[-1], i, off, sz, b[:8].hex(), guess(b, sz), nm))

if __name__ == '__main__':
    main()
