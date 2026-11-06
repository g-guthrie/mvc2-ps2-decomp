#!/usr/bin/env python3
"""Inspect original SH-4 bytes without installing an external disassembler."""
import argparse
import struct
from core import ROOT, load, number, verify_rom
from vendor.sh4dis import sh4


def literal(word, address):
    if word & 0xf000 == 0xd000:
        return ((address + 4) & ~3) + (word & 255) * 4, 4
    if word & 0xf000 == 0x9000:
        return address + 4 + (word & 255) * 2, 2
    return None


def inspect(main, base, address, size):
    if address % 2 or size <= 0 or size % 2 or address < base or address+size > base+len(main):
        raise ValueError('Use an even address and positive even size within the main image')
    lines = []
    for pc in range(address,address+size,2):
        word = struct.unpack_from('<H',main,pc-base)[0]
        note = ''
        ref = literal(word,pc)
        if ref:
            pool,width = ref
            if base <= pool and pool+width <= base+len(main):
                value = int.from_bytes(main[pool-base:pool-base+width],'little')
                note = f' ; literal at 0x{pool:08x} = 0x{value:0{width*2}x}'
        lines.append(f'{pc:08x}  {word:04x}  {sh4.disasm(word,pc)}{note}')
    return '\n'.join(lines)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    group=parser.add_mutually_exclusive_group(required=True)
    group.add_argument('--address',type=number)
    group.add_argument('--unit',help='id from config/units.json')
    parser.add_argument('--size',type=number,default=64)
    args=parser.parse_args()
    target=load(ROOT/'config/target.json')
    program=verify_rom(target)
    offset,base,size=(number(target['main'][k]) for k in ('rom_offset','address','size'))
    image=program[offset:offset+size]
    ranges=[(args.address,args.size)]
    if args.unit:
        units=[u for u in load(ROOT/'config/units.json') if u['id']==args.unit]
        if not units:
            parser.error('Unknown unit id')
        ranges=[(number(p['address']),number(p['size'])) for p in units[0]['sections'] if p['kind']=='code']
    print('Original ROM bytes. Decoding alone does not establish code boundaries.')
    for address,size in ranges:
        print(inspect(image,base,address,size))


if __name__=='__main__':
    main()
