#!/usr/bin/env python3
"""Match prebuilt NAOMI SDK library modules against the retail image.

The retail ROM links Sega's SDK libraries unchanged, so a library module is
matched by linking it at the address where its bytes sit, not by rewriting its
source. This tool finds each module of one library in the retail image, solves
the addresses its relocations point at, proves the link byte-exact through the
ordinary build path, and registers the exact ones as library units.

    python3 tools/libunit.py toolchain/naomi-sdk/lib/libkamui2.lib            # scan and prove
    python3 tools/libunit.py toolchain/naomi-sdk/lib/libkamui2.lib --register # also register exact units
"""
import argparse
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
from concurrent.futures import ThreadPoolExecutor
import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from build import compile_unit  # noqa: E402
from diff_unit import release_pools  # noqa: E402
from core import ROOT, compare, elf_segments, load, memory_bytes, number, runner, verify_rom  # noqa: E402

LIBRARY_START = 0x0c1e9000        # search from here: Sega libraries sit above the game code
SECTION_LIMIT = 64                # the compiler's section name table, per source file
IMPORT_BASE, IMPORT_STEP = 0x7C000000, 0x10000
BSS_BASE = 0x7B000000


def run(work, exe, args):
    env = {**os.environ, 'SHC_LIB': '.', 'SHC_TMP': '.'}
    result = subprocess.run(runner() + [str(work / exe)] + args, cwd=work, env=env,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=300)
    return result.stdout.decode('utf-8', errors='replace')


def hexed(value):
    return f'0x{value:08x}'


def ident(name):
    return re.sub(r'[^A-Za-z0-9_]', '_', name)


def library_modules(work, lib):
    """Every module of the library with the symbols it exports."""
    (work / 'slist.sub').write_text(f'LIBRARY {lib}\nSLIST\nEXIT\n')
    out = run(work, 'lbr.exe', ['-subcommand=slist.sub'])
    modules, current = {}, None
    for line in out.splitlines():
        head = re.fullmatch(r'([A-Za-z_$][A-Za-z0-9_$]*)\s*', line)
        if head:
            current = head.group(1)
            modules.setdefault(current, [])
            continue
        body = re.fullmatch(r'\s+([A-Za-z_$][A-Za-z0-9_$]*)\s+[A-Z]+\s*', line)
        if body and current:
            modules[current].append(body.group(1))
    return modules


def extract(work, lib, module, stem):
    """A library holding this module alone, so nothing else is ever pulled in."""
    target = work / (stem + '.lib')
    target.unlink(missing_ok=True)
    (work / (stem + '.sub')).write_text(f'LIBRARY {lib}\nOUTPUT {stem}.lib\nEXTRACT {module}\nEXIT\n')
    out = run(work, 'lbr.exe', [f'-subcommand={stem}.sub'])
    if not target.exists():
        raise ValueError(f'lbr could not extract {module}: ' + out.strip().splitlines()[-1])
    return stem + '.lib'


def pull_object(work, stem, symbols):
    lines = ['        .SECTION PULL,DUMMY'] + [f'        .IMPORT {s}' for s in symbols]
    lines += [f'        .DATA.L {s}' for s in symbols] + ['        .END']
    (work / (stem + '.src')).write_text('\n'.join(lines) + '\n')
    out = run(work, 'asmsh.exe', [stem + '.src', '-cpu=sh4', '-endian=little', '-object=' + stem + '.obj'])
    if 'TOTAL ERRORS       0' not in out:
        raise ValueError('pull object failed to assemble:\n' + out)


def start_lines(placements):
    items = [f'{name}({address:08X})' for name, address in placements]
    lines, chunk = [], []
    for item in items:
        if chunk and sum(len(x) + 1 for x in chunk) + len(item) > 160:
            lines.append('START ' + ','.join(chunk))
            chunk = []
        chunk.append(item)
    return lines + (['START ' + ','.join(chunk)] if chunk else [])


def link(work, stem, lib, placements, defines):
    lines = [f'INPUT {stem}.obj', f'LIBRARY {lib}', f'OUTPUT {stem}.elf', 'ELF', *start_lines(placements)]
    lines += [f'DEFINE {s}({v:08X})' for s, v in defines.items()] + [f'PRINT {stem}.map', 'EXIT']
    (work / (stem + '.lnk')).write_text('\n'.join(lines) + '\n')
    out = run(work, 'lnk.exe', [f'-subcommand={stem}.lnk'])
    undefined = sorted(set(re.findall(r'UNDEFINED EXTERNAL SYMBOL\([^.]+\.(\S+?)\)', out)))
    errors = [l for l in out.splitlines() if '**' in l and 'UNDEFINED' not in l and 'CANNOT FIND SECTION' not in l]
    return undefined, errors


def parse_map(text):
    """Section placement per module: [(section, module, start, size, attribute)], plus symbols."""
    modules, symbols, section, pending, attribute = [], {}, None, None, None
    for line in text.splitlines():
        m = re.match(r'^ATTRIBUTE\s*:\s*(\w+)', line)
        if m:
            attribute = m.group(1)
        m = re.match(r"^(\w+)?\s+H'([0-9A-F]{8})\s+-\s+H'([0-9A-F]{8})\s+H'([0-9A-F]{8})\s*$", line)
        if m:
            if m.group(1):
                section = m.group(1)
            pending = (section, int(m.group(2), 16), int(m.group(4), 16), attribute)
            continue
        # The unit and module names share a line, except when they are long:
        # the linker then prints the module name alone on the next line.
        m = re.match(r'^\s{10,}(\S+)(?:\s+(\S+))?\s*$', line)
        if m and pending:
            modules.append((pending[0], m.group(1), pending[1], pending[2], pending[3]))
            pending = None
        m = re.fullmatch(r"\s*(\S+)\s+H'([0-9A-Fa-f]+)\s+(ENT|DAT)\s*", line)
        if m:
            symbols[m.group(1)] = int(m.group(2), 16)
    return modules, symbols


def place(work, lib, module, symbols, stem, main, base, table=None):
    """Link this module alone at two bases; the words that move are its relocations.
    Everything else is fixed content, which is searched for in the retail image."""
    alone = extract(work, lib, module, stem)
    pull_object(work, stem, symbols)
    _, errors = link(work, stem, alone, [], {})
    names = []
    for m in re.finditer(r"^(\w+)\s+H'[0-9A-F]{8}", (work / (stem + '.map')).read_text(), re.M):
        if m.group(1) not in names:
            names.append(m.group(1))
    images = {}
    for tag, origin in (('a', 0x0c000000), ('b', 0x0d000000)):
        placements = [(name, origin + 0x100000 * i) for i, name in enumerate(names)]
        undefined, errors = link(work, stem, alone, placements, {})
        defines = {s: origin + 0x800000 + 16 * i for i, s in enumerate(undefined)}
        _, errors = link(work, stem, alone, placements, defines)
        if errors:
            raise ValueError('; '.join(errors[:2]))
        images[tag] = (elf_segments((work / (stem + '.elf')).read_bytes()),
                       parse_map((work / (stem + '.map')).read_text()), dict(placements))
    (segments_a, (rows, map_symbols), placed_a) = images['a']
    (segments_b, _, placed_b) = images['b']
    uninitialized = {s['address'] for s in segments_a if s['size'] == 0 and s['memory_size']}
    parts, bss_parts, unplaced = [], [], []
    for section, owner, start, size, attribute in rows:
        if owner != module or size == 0:
            continue
        if placed_a.get(section) in uninitialized:
            bss_parts.append({'section': section, 'size': size,
                              'symbols': {s: a - start for s, a in map_symbols.items() if start <= a < start + size}})
            continue
        ours = memory_bytes(segments_a, start, size)
        other = memory_bytes(segments_b, start + (placed_b[section] - placed_a[section]), size)
        mask = bytearray(b'\xff' * size)
        for i in range(0, size, 4):
            if ours[i:i + 4] != other[i:i + 4]:
                mask[i:i + 4] = b'\0\0\0\0'
        runs = [(m.end() - m.start(), m.start()) for m in re.finditer(rb'\xff+', bytes(mask))]
        fixed = size - mask.count(0)
        searchable = bool(runs) and max(runs)[0] >= 8 and fixed >= 16
        hits, position = [], -1
        if searchable:
            length, offset = max(runs)
            anchor = ours[offset:offset + min(length, 48)]
            position = main.find(anchor, LIBRARY_START - base)
        while position != -1:
            candidate = position - offset
            if 0 <= candidate and candidate + size <= len(main) and \
                    all(mask[i] == 0 or main[candidate + i] == ours[i] for i in range(size)):
                hits.append(base + candidate)
            position = main.find(anchor, position + 1)
        if len(hits) != 1:
            # A module that is almost all relocations has too little fixed content
            # to find by search. Another module's solved import names one of its
            # symbols, and that address says where the section starts.
            for symbol, address in map_symbols.items():
                if not (start <= address < start + size) or symbol not in (table or {}):
                    continue
                candidate = table[symbol] - (address - start)
                if candidate < LIBRARY_START or candidate - base + size > len(main):
                    continue
                if all(mask[i] == 0 or main[candidate - base + i] == ours[i] for i in range(size)):
                    hits = [candidate]
                    break
        if len(hits) != 1:
            reason = ('too little fixed content to place' if not searchable and not hits else
                      'not in the image' if not hits else f'{len(hits)} possible addresses')
            unplaced.append((section, size, reason))
            continue
        parts.append({'section': section, 'kind': 'code' if attribute == 'CODE' else 'data',
                      'address': hits[0], 'size': size, 'link_start': start,
                      'exports': {s: hits[0] + (a - start) for s, a in map_symbols.items() if start <= a < start + size},
                      'relocated': [i for i in range(0, size, 4) if mask[i] == 0]})
    parts, unplaced = infer_internal_sections(parts, unplaced, module, images, main, base)
    return parts, bss_parts, unplaced, alone


def infer_internal_sections(parts, unplaced, module, images, main, base):
    """Place low-entropy sections using relocations from already placed sections.

    This supplies candidates only. Fixed bytes must agree here, and solve plus
    the normal full linked-byte comparison still decide whether a module matches.
    """
    parts, unplaced = list(parts), list(unplaced)
    segments_a, (rows, symbols), placements_a = images['a']
    segments_b, _, placements_b = images['b']
    changed = True
    while changed:
        changed = False
        for item in list(unplaced):
            section, size, _reason = item
            row = next((r for r in rows if r[0] == section and r[1] == module), None)
            if row is None:
                continue
            _, _, start, size, attribute = row
            hints, evidence = set(), []
            for source in parts:
                content = memory_bytes(segments_a, source['link_start'], source['size'])
                for offset in source['relocated']:
                    pointer = int.from_bytes(content[offset:offset+4], 'little')
                    if start <= pointer < start + size:
                        location = source['address'] - base + offset
                        real = int.from_bytes(main[location:location+4], 'little')
                        hints.add(real - (pointer - start))
                        evidence.append({'source': hexed(source['address'] + offset),
                                         'section_offset': pointer - start, 'retail_pointer': hexed(real)})
            if len(hints) != 1:
                continue
            address = hints.pop()
            if not base <= address or address + size > base + len(main):
                continue
            ours = memory_bytes(segments_a, start, size)
            other = memory_bytes(segments_b, start + placements_b[section] - placements_a[section], size)
            relocated = [i for i in range(0, size, 4) if ours[i:i+4] != other[i:i+4]]
            moving = {i + j for i in relocated for j in range(min(4, size-i))}
            retail = main[address-base:address-base+size]
            if any(ours[i] != retail[i] for i in range(size) if i not in moving):
                continue
            parts.append({'section': section, 'kind': 'code' if attribute == 'CODE' else 'data',
                          'address': address, 'size': size, 'link_start': start,
                          'exports': {s: address + a - start for s, a in symbols.items() if start <= a < start+size},
                          'relocated': relocated, 'placement_evidence': evidence})
            unplaced.remove(item)
            changed = True
    return parts, unplaced


def solve(work, lib, module, parts, bss_parts, main, base):
    """Link the module alone at its retail addresses with every import at a unique
    dummy address, then read the real addresses off the retail bytes."""
    exports = {}
    for part in parts:
        exports.update(part['exports'])
    if not exports:
        return None, 'no exported symbol to pull the module with'
    stem = 'solve'
    pull_object(work, stem, sorted(exports))
    placements = [(p['section'], p['address']) for p in parts]
    undefined, errors = link(work, stem, lib, placements, {})
    bss_dummy = {p['section']: BSS_BASE + 0x100000 * i for i, p in enumerate(bss_parts)}
    placements += list(bss_dummy.items())
    dummies = {s: IMPORT_BASE + IMPORT_STEP * i for i, s in enumerate(undefined)}
    undefined2, errors = link(work, stem, lib, placements, dummies)
    if undefined2 or errors:
        return None, 'link: ' + '; '.join((undefined2 + errors)[:3])
    segments = elf_segments((work / (stem + '.elf')).read_bytes())
    imports, bss_addresses, conflicts = {}, {}, []
    for part in parts:
        ours = memory_bytes(segments, part['address'], part['size'])
        retail = main[part['address'] - base:part['address'] - base + part['size']]
        for i in part['relocated']:
            word = int.from_bytes(ours[i:i + 4], 'little')
            real = int.from_bytes(retail[i:i + 4], 'little')
            if word == real:
                continue
            if IMPORT_BASE <= word < IMPORT_BASE + IMPORT_STEP * len(undefined):
                index, offset = divmod(word - IMPORT_BASE, IMPORT_STEP)
                if offset >= IMPORT_STEP // 2:
                    continue
                symbol, value = undefined[index], (real - offset) & 0xFFFFFFFF
                if imports.setdefault(symbol, value) != value:
                    conflicts.append(f'{symbol} ({hexed(imports[symbol])} vs {hexed(value)} at {hexed(part["address"] + i)})')
            for section, dummy in bss_dummy.items():
                if dummy <= word < dummy + 0x100000:
                    value = (real - (word - dummy)) & 0xFFFFFFFF
                    if bss_addresses.setdefault(section, value) != value:
                        conflicts.append(f'{section} ({hexed(bss_addresses[section])} vs {hexed(value)} at {hexed(part["address"] + i)})')
    if conflicts:
        return None, 'inconsistent relocations for ' + ', '.join(sorted(set(conflicts)))
    unresolved = [s for s in undefined if s not in imports]
    return {'imports': imports, 'bss': bss_addresses, 'unresolved': unresolved}, None


def registry_intervals(units):
    spans = []
    for unit in units:
        for part in unit['sections']:
            if part['kind'] != 'bss':
                trimmable = 'source' in unit and part['kind'] == 'data' and not part.get('interior')
                spans.append((number(part['address']), number(part['address']) + number(part['size']),
                              unit['id'], trimmable, 'source' in unit))
    return spans


def remainders(lo, hi, cuts):
    """What is left of [lo, hi) once the module's ranges are cut out of it."""
    left, cursor = [], lo
    for a, b in sorted(cuts):
        if cursor < a:
            left.append((cursor, a))
        cursor = max(cursor, b)
    if cursor < hi:
        left.append((cursor, hi))
    return left


def partial_overlaps(spans, parts, sizes):
    """Registered ranges that cross a module boundary and cannot be trimmed.
    Ranges entirely inside a module (earlier data-only credit for its pools) are
    released on registration; crossing data-only ranges are trimmed then, unless
    a remainder would have to start at an odd address, which cannot be a section."""
    inside = lambda a, b: any(p['address'] <= a and b <= p['address'] + p['size'] for p in parts)
    names, growth = set(), {}
    for a, b, name, trimmable, compiled in spans:
        cuts = [(p['address'], p['address'] + p['size']) for p in parts if p['address'] < b and a < p['address'] + p['size']]
        if not cuts:
            continue
        if inside(a, b):
            # Only a compiled unit's range can be released to the module that
            # contains it. A library range inside the module is the same object
            # already registered from another library, and is never linked twice.
            if not compiled:
                names.add(name)
            continue
        left = remainders(a, b, cuts)
        growth[name] = growth.get(name, 0) + max(0, len(left) - 1)
        if not trimmable or any(start % 2 for start, _ in left) or sizes.get(name, 0) + growth[name] > SECTION_LIMIT:
            names.add(name)
    return sorted(names)


def trim_crossing(unit, units, main, base):
    """A registered data-only range that crosses the module boundary is cut back
    to the part outside the module; the remainder is re-emitted as bytes in the
    same source file, so no credit is claimed twice and none is invented."""
    spans = [(number(p['address']), number(p['address']) + number(p['size'])) for p in unit['sections'] if p['kind'] != 'bss']
    for other in units:
        if 'source' not in other:
            continue
        keep, changed = [], False
        for part in other['sections']:
            lo, hi = number(part['address']), number(part['address']) + number(part['size'])
            crossing = [(a, b) for a, b in spans if a < hi and lo < b and not (a <= lo and hi <= b)]
            if not crossing or part['kind'] != 'data' or part.get('interior'):
                keep.append(part)
                continue
            source = ROOT / other['source']
            text = source.read_text()
            pattern = re.compile(r'#pragma section ' + re.escape(part['section'][1:]) + r'\n.*?\n(?=#pragma section |\Z)', re.S)
            text, count = pattern.subn('', text, count=1)
            if count != 1:
                raise ValueError(f"Cannot find section {part['section']} in {other['source']} to trim it")
            symbol = next((k for k, v in other.get('exports', {}).items() if number(v) == lo), None)
            if symbol:
                del other['exports'][symbol]
            left = remainders(lo, hi, crossing)
            for index, (a, b) in enumerate(left):
                # The first remainder keeps the section's name, so trimming adds
                # no name to a file that may already hold the linker's maximum.
                name = part['section'][1:] if index == 0 else f'n{a - base + (base & 0xfff000):06x}'
                rows = [main[a - base:b - base][i:i + 12] for i in range(0, b - a, 12)]
                body = '\n'.join('    ' + ' '.join(f'0x{x:02x}u,' for x in row) for row in rows)
                text = text.rstrip('\n') + f'\n\n#pragma section {name}\nconst unsigned char dat_{a:08x}[] = {{\n{body}\n}};\n'
                keep.append({'section': 'C' + name, 'kind': 'data', 'address': hexed(a), 'size': b - a})
            if len(keep) + sum(1 for rest in other['sections'][other['sections'].index(part) + 1:]) > SECTION_LIMIT:
                raise ValueError(f"Trimming {other['id']} would exceed the compiler's {SECTION_LIMIT} sections per file")
            print(f"TRIMMED {other['id']} {part['section']} around {unit['id']}: kept {sum(b - a for a, b in left)} of {hi - lo} bytes")
            source.write_text(text)
            changed = True
        if changed:
            other['sections'] = keep
    return [u for u in units if u['sections']]


def register(new_units, main, base):
    path = ROOT / 'config/units.json'
    # Same stable lock as diff_unit.register: the registry file itself is replaced.
    (ROOT / 'build').mkdir(exist_ok=True)
    with open(ROOT / 'build/units.lock', 'w') as guard, open(path, 'r+') as handle:
        fcntl.flock(guard, fcntl.LOCK_EX)
        fcntl.flock(handle, fcntl.LOCK_EX)
        units = json.load(handle)
        ids = {u['id'] for u in units}
        added = [u for u in new_units if u['id'] not in ids]
        for unit in added:
            units = release_pools(unit, units)
            units = trim_crossing(unit, units, main, base)
        units += added
        temp = path.with_suffix('.json.tmp')
        temp.write_text(json.dumps(units, indent=2) + '\n')
        os.replace(temp, path)
    return added


def defer_bss(module, bss_parts, known, previous):
    """Retry only when the BSS symbol evidence changed; stop at a fixed point."""
    knowledge = tuple((symbol, known.get(symbol)) for part in bss_parts
                      for symbol in sorted(part['symbols']))
    if previous.get(module) == knowledge:
        return False
    previous[module] = knowledge
    return True


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('library', help='a .lib below toolchain/naomi-sdk/lib/')
    parser.add_argument('--register', action='store_true', help='append exact modules to config/units.json as verified library units')
    parser.add_argument('--module', help='only this module')
    parser.add_argument('--jobs', type=int, default=os.cpu_count() or 4, help='parallel placement jobs')
    parser.add_argument('--output', help='write exact unit descriptors and skipped reasons as JSON')
    args = parser.parse_args()
    library = Path(args.library)
    if library.is_absolute():
        library = library.relative_to(ROOT)
    target = load(ROOT / 'config/target.json')
    program = verify_rom(target)
    base, offset, size = (number(target['main'][k]) for k in ('address', 'rom_offset', 'size'))
    main_image = program[offset:offset + size]
    units = load(ROOT / 'config/units.json')
    # Every address the registry already knows a symbol by. A module too small to
    # find by content search is placed by one of these instead.
    table = {}
    for unit in units:
        for symbol, address in {**unit.get('exports', {}), **unit.get('imports', {})}.items():
            table.setdefault(symbol, number(address))
    spans = registry_intervals(units)
    sizes = {unit['id']: len(unit['sections']) for unit in units}
    (ROOT / 'build').mkdir(exist_ok=True)
    workspace = tempfile.TemporaryDirectory(prefix='libwork-', dir=ROOT / 'build')
    work = Path(workspace.name)
    shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work, dirs_exist_ok=True)
    shutil.copyfile(ROOT / library, work / library.name)
    modules = library_modules(work, library.name)
    if args.module:
        modules = {k: v for k, v in modules.items() if k == args.module}

    def placement(item):
        index, (module, symbols) = item
        if not symbols:
            return module, None, f'no exported symbol to pull the module with'
        try:
            return module, place(work, library.name, module, symbols, f'place{index:04d}', main_image, base, table), None
        except ValueError as error:
            return module, None, str(error).splitlines()[0]

    placements, skipped = [], []
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for module, result, why in pool.map(placement, enumerate(sorted(modules.items()))):
            if result is None:
                skipped.append((module, why))
                continue
            parts, bss_parts, unplaced, alone = result
            if not parts:
                skipped.append((module, '; '.join(f'{name} ({count} bytes): {why}' for name, count, why in unplaced) or 'nothing to place'))
                continue
            placements.append((module, parts, bss_parts, unplaced, alone))
    placements.sort(key=lambda item: item[1][0]['address'])
    print(f'{library.name}: {len(modules)} modules, {len(placements)} placed in the image', flush=True)

    stem = ident(library.stem[3:] if library.stem.startswith('lib') else library.stem)
    proven, known, queue, retry = [], dict(table), list(placements), []
    deferred_bss = {}
    while queue:
        module, parts, bss_parts, unplaced, alone = queue.pop(0)
        if unplaced:
            skipped.append((module, 'only part of the module is placed: '
                            + '; '.join(f'{name} ({count} bytes): {why}' for name, count, why in unplaced)))
            continue
        clash = partial_overlaps(spans, parts, sizes)
        if clash:
            detail = ', '.join(f'{name} {hexed(a)}+{b - a}' for a, b, name, _, _c in spans if name in clash
                               and any(a < p['address'] + p['size'] and p['address'] < b for p in parts))
            skipped.append((module, f"crosses registered range {detail} (module {hexed(parts[0]['address'])}+{sum(p['size'] for p in parts)})"))
            continue
        solved, why = solve(work, alone, module, parts, bss_parts, main_image, base)
        if solved is None:
            skipped.append((module, why))
            continue
        for part in bss_parts:
            if part['section'] not in solved['bss']:
                hints = {known[symbol] - shift for symbol, shift in part['symbols'].items() if symbol in known}
                if len(hints) == 1:
                    solved['bss'][part['section']] = hints.pop()
        waiting = [part['section'] for part in bss_parts if part['section'] not in solved['bss']]
        if waiting:
            # Another module may import this one's bss symbols and so reveal where
            # the section sits. Come back to it once the rest of the library is done.
            entry = (module, parts, bss_parts, unplaced, alone)
            if defer_bss(module, bss_parts, known, deferred_bss):
                retry.append(entry)
                if not queue:
                    queue, retry = retry, []
                continue
            skipped.append((module, 'bss section no other module places: ' + ', '.join(waiting)))
            continue
        if solved['unresolved']:
            skipped.append((module, 'imports never relocated: ' + ', '.join(solved['unresolved'][:3])))
            continue
        exports = {}
        for part in parts:
            exports.update(part['exports'])
        for part in bss_parts:
            exports.update({symbol: solved['bss'][part['section']] + shift for symbol, shift in part['symbols'].items()})
        unit = {'id': f'lib_{stem}_{ident(module)}', 'library': str(library), 'module': module, 'mode': 'verified',
                'sections': [{'section': p['section'], 'kind': p['kind'], 'address': hexed(p['address']), 'size': p['size']} for p in parts]
                + [{'section': p['section'], 'kind': 'bss', 'address': hexed(solved['bss'][p['section']]), 'size': p['size']} for p in bss_parts],
                'imports': {s: hexed(v) for s, v in sorted(solved['imports'].items())},
                'exports': {s: hexed(v) for s, v in sorted(exports.items(), key=lambda kv: kv[1])}}
        evidence = {p['section']: p['placement_evidence'] for p in parts if p.get('placement_evidence')}
        if evidence:
            unit['placement_evidence'] = evidence
        try:
            elf, map_text = compile_unit(unit, work, None)
            proof, _ = compare(unit, elf, map_text, main_image, base)
        except ValueError as error:
            skipped.append((module, str(error).splitlines()[0]))
            continue
        if proof['exact']:
            proven.append(unit)
            known.update(solved['imports'])
            known.update(exports)
            spans += [(p['address'], p['address'] + p['size'], unit['id'], False, False) for p in parts]
            print(f"EXACT {unit['id']} {sum(p['size'] for p in parts)} bytes at {hexed(parts[0]['address'])}", flush=True)
        else:
            skipped.append((module, 'links but differs: ' + '; '.join(proof['problems'][:2])))
        if not queue and retry:
            queue, retry = retry, []
    for module, why in sorted(skipped):
        print(f'SKIP {module}: {why}')
    total = sum(number(p['size']) for u in proven for p in u['sections'] if p['kind'] != 'bss')
    print(f'{len(proven)} modules exact, {total:,} bytes; {len(skipped)} skipped')
    if args.output:
        Path(args.output).write_text(json.dumps({'library': str(library), 'units': proven, 'skipped': skipped}, indent=2) + '\n')
    if args.register and proven:
        added = register(proven, main_image, base)
        print(f'REGISTERED {len(added)} library units')
    workspace.cleanup()


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, subprocess.SubprocessError) as error:
        sys.exit(str(error))
