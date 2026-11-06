#!/usr/bin/env python3
"""Compile one unit or C file, show every word that differs from retail, and
optionally register the result.

    python3 tools/diff_unit.py mask_tu                      # a registered unit
    python3 tools/diff_unit.py src/candidates/new.c         # a bare file
    python3 tools/diff_unit.py src/verified/new.c --register new_id

A bare file is described by its own text. Functions are named func_0cXXXXXX,
so their addresses are known. A file whose functions each follow a
`#pragma section NAME` line is a set of pool-free leaves: each becomes section
PNAME at its function's address with the size of the reviewed code range there.
Any other file is one translation unit: section P starts at the first function
and runs through every reviewed code and data range up to the pool that follows
the last function in the file. Each data range inside is a literal pool,
declared as interior data, so a unit may hold several pools. Imports are read off the compiler's
.IMPORT lines; a symbol named func_0cXXXXXX or dat_0cXXXXXX resolves to that
address, compiler runtime routines come from config/runtime.json, and anything
else needs --import SYMBOL=ADDRESS.

--register writes the unit into config/units.json as verified when exact and
as candidate otherwise. A file under src/verified/ must be exact.
"""
import argparse
import copy
import fcntl
import json
import os
import re
import shutil
import struct
import sys

from build import compile_unit
from core import ROOT, compare, link_map, load, memory_bytes, number, verify_rom
from vendor.sh4dis import sh4

FUNCTION = re.compile(r'^\s*(?:[\w\s\*]+?)\b(func_0c[0-9a-f]{6})\s*\(', re.M)
PRAGMA = re.compile(r'^\s*#pragma\s+section\s+(\w+)\s*$', re.M)
SYMBOL = re.compile(r'^_?(?:func|dat|ptr|table)_(0c[0-9a-f]{6})$')
RUNTIME = load(ROOT / 'config/runtime.json')


def mapping_ranges():
    return [(number(r['address']), number(r['size']), r['kind']) for r in load(ROOT / 'config/mapping.json')['ranges']]


def describe(path, ranges, imports):
    """Derive the unit entry for a bare C file from its text and the mapping."""
    text = (ROOT / path).read_text()
    definitions = [(m.start(), m.group(1)) for m in FUNCTION.finditer(text)
                   if not text[m.end():].lstrip().startswith(';') and ';' not in text[m.start():text.find('{', m.end())]]
    if not definitions:
        raise ValueError('No func_0cXXXXXX definition in ' + path)
    pragmas = [(m.start(), m.group(1)) for m in PRAGMA.finditer(text)]
    by_start = {lo: (size, kind) for lo, size, kind in ranges}
    unit = {'id': 'diff', 'source': path, 'mode': 'candidate', 'sections': [], 'exports': {}, 'imports': dict(imports)}
    for _, name in definitions:
        unit['exports']['_' + name] = number('0x' + name[5:])
    if pragmas and len(pragmas) == len(definitions):
        for (_, section), (_, name) in zip(pragmas, definitions):
            address = number('0x' + name[5:])
            if address not in by_start or by_start[address][1] != 'code':
                raise ValueError(f'No reviewed code range starts at {name}; map it first')
            unit['sections'].append({'section': 'P' + section, 'kind': 'code', 'address': address, 'size': by_start[address][0]})
        return unit
    start, last = min(unit['exports'].values()), max(unit['exports'].values())
    holder = [lo for lo, size, kind in ranges if lo <= start < lo + size and kind == 'code']
    if not holder:
        raise ValueError('A translation unit must start on reviewed code')
    cursor, interior = holder[0], []
    while cursor in by_start:
        size, kind = by_start[cursor]
        if kind == 'code':
            if (cursor > last and interior and interior[-1]['address'] + interior[-1]['size'] == cursor
                    and cursor not in branch_targets(holder[0], cursor, ranges)):
                break
        else:
            interior.append({'address': cursor, 'size': size, 'kind': 'data'})
        cursor += size
    if not interior:
        raise ValueError('No reviewed pool follows the code; use #pragma section for pool-free leaves')
    interior = coalesce(interior)
    unit['sections'].append({'section': 'P', 'kind': 'code', 'address': start, 'size': cursor - start, 'interior': interior})
    return unit


_IMAGE = None


def main_image():
    """The retail main image and its base address, read once."""
    global _IMAGE
    if _IMAGE is None:
        target = load(ROOT / 'config/target.json')
        program = verify_rom(target)
        offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
        _IMAGE = (base, program[offset:offset + size])
    return _IMAGE


def branch_targets(lo, hi, ranges):
    """Targets of BT/BF/BT.S/BF.S/BRA in reviewed code within [lo, hi).

    A function may continue after its own literal pool; the code there is part
    of the unit when a branch inside the unit reaches it."""
    base, image = main_image()
    targets = set()
    for address, size, kind in ranges:
        if kind != 'code' or address + size <= lo or address >= hi:
            continue
        for pc in range(max(address, lo), min(address + size, hi), 2):
            word = struct.unpack_from('<H', image, pc - base)[0]
            if word & 0xf900 == 0x8900:
                disp = word & 0xff
                targets.add(pc + 4 + (disp - 256 if disp & 0x80 else disp) * 2)
            elif word & 0xf000 == 0xa000:
                disp = word & 0xfff
                targets.add(pc + 4 + (disp - 4096 if disp & 0x800 else disp) * 2)
    return targets


def coalesce(ranges):
    """Adjacent ranges of one kind are one range."""
    merged = []
    for item in sorted(ranges, key=lambda r: number(r['address'])):
        if merged and number(merged[-1]['address']) + number(merged[-1]['size']) == number(item['address']) and merged[-1]['kind'] == item['kind']:
            merged[-1]['size'] = number(merged[-1]['size']) + number(item['size'])
        else:
            merged.append({'address': number(item['address']), 'size': number(item['size']), 'kind': item['kind']})
    return merged


def resolve_imports(unit, work, stem):
    assembly = (work / (stem + '.src')).read_text(errors='replace')
    for symbol in re.findall(r'^\s*\.IMPORT\s+(\w+)', assembly, re.M):
        if symbol in unit['imports']:
            continue
        match = SYMBOL.match(symbol)
        if match:
            unit['imports'][symbol] = number('0x' + match.group(1))
        elif symbol in RUNTIME:
            unit['imports'][symbol] = number(RUNTIME[symbol])
        else:
            raise ValueError(f'Unknown import {symbol}: pass --import {symbol}=ADDRESS')


def hexed(unit):
    out = json.loads(json.dumps(unit))
    if out.get('options', 'game') == 'game':
        out.pop('options', None)
    for part in out['sections']:
        part['address'] = f"0x{number(part['address']):08x}"
        for spare in part.get('interior', ()):
            spare['address'] = f"0x{number(spare['address']):08x}"
    for key in ('exports', 'imports'):
        out[key] = {k: f"0x{number(v):08x}" for k, v in out[key].items()}
        if not out[key]:
            del out[key]
    return out


def release_pools(unit, units):
    """A unit owns everything inside its sections. Sections of other units that
    lie inside them, pools and pool-free leaves alike, are removed from the
    registry and from their source."""
    spans = [(number(part['address']), number(part['address']) + number(part['size'])) for part in unit['sections']]
    # Every source edit is computed before any is written, so a section that
    # cannot be released leaves all sources and the registry untouched.
    writes = []
    for other in units:
        if other['id'] == unit['id'] or (unit.get('source') and other.get('source') == unit['source']):
            continue
        keep, drop = [], []
        for part in other['sections']:
            lo, hi = number(part['address']), number(part['address']) + number(part['size'])
            (drop if any(a <= lo and hi <= b for a, b in spans) else keep).append(part)
        if not drop:
            continue
        if 'source' not in other:
            raise ValueError(f"Cannot release sections of library unit {other['id']}")
        source = ROOT / other['source']
        text = source.read_text()
        for part in drop:
            pattern = re.compile(r'#pragma section ' + re.escape(part['section'][1:]) + r'\n.*?\n(?=#pragma section |\Z)', re.S)
            text, count = pattern.subn('', text, count=1)
            if count != 1:
                raise ValueError(f"Cannot find section {part['section']} in {other['source']} to release it")
            symbol = next((k for k, v in other.get('exports', {}).items() if number(v) == number(part['address'])), None)
            if symbol:
                del other['exports'][symbol]
            print(f"RELEASED {other['id']} {part['section']} to {unit['id']}")
        writes.append((source, text))
        other['sections'] = keep
    for source, text in writes:
        source.write_text(text)
    return [u for u in units if u['sections']]


def admission_issues(issues, exact):
    """Boundary issues that block registration.

    A conditional branch onto another exported entry of the same unit
    (conditional_entry) is admitted only for an exact unit: every byte,
    including that branch, then came from the compiler with both functions
    defined separately in the source, not from a label standing in for an
    entry.
    """
    return [i for i in issues if not (exact and i['kind'] == 'conditional_entry')]


def register(unit, exact):
    # Existing byte equality remains mandatory for verified units. Boundary
    # admission also prevents a newly registered fragment from posing as C.
    if any(s['kind'] == 'code' for s in unit['sections']):
        from boundaries import BoundaryIndex
        issues = admission_issues(BoundaryIndex.current().unit(unit)['issues'], exact)
        if issues:
            raise ValueError('Candidate boundary review failed: ' + json.dumps(issues))
    unit = hexed(unit)
    unit['mode'] = 'verified' if exact else 'candidate'
    if unit['source'].startswith('src/verified/') and not exact:
        raise ValueError('A file under src/verified/ must match exactly; put it under src/candidates/')
    path = ROOT / 'config/units.json'
    # Lock a file that is never replaced: os.replace below swaps the registry's
    # inode, so a lock held on the registry itself would not exclude a writer
    # that opened it before the swap.
    (ROOT / 'build').mkdir(exist_ok=True)
    with open(ROOT / 'build/units.lock', 'w') as guard, open(path, 'r+') as handle:
        fcntl.flock(guard, fcntl.LOCK_EX)
        fcntl.flock(handle, fcntl.LOCK_EX)
        units = release_pools(unit, json.load(handle))
        slots = [i for i, u in enumerate(units) if u['id'] == unit['id'] or u.get('source') == unit['source']]
        units = [u for i, u in enumerate(units) if i not in slots]
        units.insert(slots[0] if slots else len(units), unit)
        temp = path.with_suffix('.json.tmp')
        temp.write_text(json.dumps(units, indent=2) + '\n')
        os.replace(temp, path)
    print(f"REGISTERED {unit['id']} as {unit['mode']} ({len(units)} units)")


def evaluate(path, imports=None, options=None, descriptor=None):
    """Compile a C file below src/ and compare it: (proof, unit). No output."""
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    main_image = program[offset:offset + size]
    sets = load(ROOT / 'config/compiler.json')['sets']
    units = {u['id']: u for u in load(ROOT / 'config/units.json')}
    known = next((u for u in units.values() if u.get('source') == path), {})
    if descriptor is None:
        unit = describe(path, mapping_ranges(), {**{k: number(v) for k, v in known.get('imports', {}).items()}, **(imports or {})})
        unit['id'] = known.get('id', 'diff')
        unit['options'] = options or known.get('options', 'game')
    else:
        # Isolated spelling trials retain the admitted extent and exports.
        # Full byte comparison remains mandatory; no result is registered here.
        unit = copy.deepcopy(descriptor)
        unit['source'] = path
        unit['imports'] = {**unit.get('imports', {}), **(imports or {})}
        unit['options'] = options or unit.get('options', 'game')
    flags = sets[unit['options']]
    work = ROOT / 'build' / f'work-diff-{os.getpid()}'
    if work.exists():
        shutil.rmtree(work)
    shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work)
    try:
        elf, link = compile_unit(unit, work, flags)
        before = len(unit['imports'])
        resolve_imports(unit, work, unit['id'])
        if len(unit['imports']) != before:
            elf, link = compile_unit(unit, work, flags)
        proof, _ = compare(unit, elf, link, main_image, base)
        from diagnose import diagnose
        proof['diagnosis'] = diagnose(unit, proof, elf, main_image, base)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    return proof, unit


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('target', help='unit id from config/units.json, or a C file below src/')
    parser.add_argument('--import', dest='imports', action='append', default=[], metavar='SYMBOL=ADDRESS')
    parser.add_argument('--register', metavar='ID', help='write the unit into config/units.json under this id')
    parser.add_argument('--options', choices=['game', 'library'], help='option set for a bare file; the default is game')
    parser.add_argument('--context', type=int, default=2, help='matching instructions shown around each difference')
    args = parser.parse_args()
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    offset, base, size = (number(target['main'][k]) for k in ('rom_offset', 'address', 'size'))
    main = program[offset:offset + size]
    sets = load(ROOT / 'config/compiler.json')['sets']
    units = {u['id']: u for u in load(ROOT / 'config/units.json')}
    imports = {k: number(v) for k, v in (item.split('=', 1) for item in args.imports)}
    if args.target in units:
        unit = units[args.target]
        unit['imports'] = {**unit.get('imports', {}), **imports}
    else:
        known = next((u for u in units.values() if u.get('source') == args.target), {})
        unit = describe(args.target, mapping_ranges(), {**{k: number(v) for k, v in known.get('imports', {}).items()}, **imports})
        if known:
            unit['id'] = known['id']
            if 'options' in known:
                unit['options'] = known['options']
    if args.register:
        unit['id'] = args.register
    if args.options:
        unit['options'] = args.options
    flags = sets[unit.get('options', 'game')]
    work = ROOT / 'build' / f'work-diff-{os.getpid()}'
    if work.exists():
        shutil.rmtree(work)
    shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work)
    try:
        elf, link = compile_unit(unit, work, flags)
        before = len(unit['imports'])
        resolve_imports(unit, work, unit['id'])
        if len(unit['imports']) != before:
            elf, link = compile_unit(unit, work, flags)
        proof, segments = compare(unit, elf, link, main, base)
    finally:
        shutil.rmtree(work, ignore_errors=True)
    for part in proof['sections']:
        placed = f"0x{part['linked_address']:08x}" if part['linked_address'] is not None else 'nowhere'
        print(f"{part['section']} 0x{part['address']:08x} {part['size']} bytes: {part['equal_bytes']}/{part['size']} equal, "
              f"linked {part['linked_size']} at {placed}")
    for row in proof['functions']:
        print(f"  {row['symbol']} 0x{row['address']:08x} {row['size']} bytes: {row['equal_bytes']}/{row['size']} equal")
    for row in proof['pools']:
        print(f"  pool 0x{row['address']:08x} {row['size']} bytes: {row['equal_bytes']}/{row['size']} equal")
    for part in proof['sections']:
        if part['kind'] != 'code' or part['exact']:
            continue
        try:
            ours = memory_bytes(segments, part['address'], part['size'])
        except ValueError:
            print(f"  ({part['section']} did not link at its address with its size; nothing to compare)")
            continue
        retail = main[part['address'] - base:part['address'] - base + part['size']]
        words = list(range(0, part['size'] - 1, 2))
        differing = {i for i in words if ours[i:i + 2] != retail[i:i + 2]}
        show = {j for i in differing for j in words if abs(j - i) <= 2 * args.context}
        last = None
        for i in sorted(show):
            if last is not None and i != last + 2:
                print('    ...')
            pc = part['address'] + i
            r, o = struct.unpack_from('<H', retail, i)[0], struct.unpack_from('<H', ours, i)[0]
            mark = '!' if i in differing else ' '
            print(f"  {mark} {pc:08x}  retail {r:04x}  {sh4.disasm(r, pc):32s} ours {o:04x}  {sh4.disasm(o, pc)}")
            last = i
    for problem in proof['problems']:
        print('PROBLEM ' + problem)
    print('EXACT' if proof['exact'] else 'DIFFERS')
    if args.register:
        register(unit, proof['exact'])
    return 0 if proof['exact'] else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except ValueError as error:
        sys.exit(str(error))
