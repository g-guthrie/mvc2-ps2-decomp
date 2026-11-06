#!/usr/bin/env python3
"""One Hitachi build path, from checked-in C to address-verified ROM bytes."""
import argparse
import fcntl
import time
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

from core import (ROOT, compare, input_fingerprint, load, memory_bytes, number,
                  preflight, runner, sha, validate_units, verify_rom, verify_tools)


def link_lines(unit, stem):
    """The linker subcommands every unit shares: section placement and imports."""
    start, chunk = [], []
    for part in unit['sections']:
        item = f"{part['section']}({number(part['address']):08X})"
        if chunk and sum(len(x) + 1 for x in chunk) + len(item) > 180:
            start.append('START ' + ','.join(chunk))
            chunk = []
        chunk.append(item)
    if chunk:
        start.append('START ' + ','.join(chunk))
    lines = [f'OUTPUT {stem}.elf', 'ELF', *start]
    lines += [f'DEFINE {symbol}({number(address):08X})' for symbol, address in unit.get('imports', {}).items()]
    return lines + [f'PRINT {stem}.map', 'EXIT']


def compile_unit(unit, work, flags):
    stem = unit['id']
    env = {**os.environ, 'SHC_LIB': '.', 'SHC_TMP': '.'}
    log = []

    def run(exe, args):
        command = runner() + [str(work / exe)] + args
        # The Win32 runner occasionally hangs under load on an input that
        # compiles in a second; a hung run is retried, never accepted.
        for attempt in range(3):
            try:
                result = subprocess.run(command, cwd=work, env=env, stdout=subprocess.PIPE,
                                        stderr=subprocess.STDOUT, timeout=120)
                break
            except subprocess.TimeoutExpired:
                if attempt == 2:
                    raise
                log.append(' '.join([exe] + args) + f'\ntimed out; retry {attempt + 1}')
        output = result.stdout.decode('utf-8', errors='replace')
        log.append(' '.join([exe] + args) + '\n' + output)
        (work / (stem + '.log')).write_text('\n'.join(log))
        if result.returncode:
            raise ValueError(f'{stem}: {exe} failed; see build/work/{stem}.log\n{output}')

    if 'library' in unit:
        # A library unit links one prebuilt SDK module at its retail address. The
        # pull object lives in a DUMMY section, so it contributes no bytes; it only
        # references the module's exports, which makes the linker pull that module.
        symbols = list(unit['exports'])
        pull = ['        .SECTION PULL,DUMMY'] + [f'        .IMPORT {s}' for s in symbols]
        pull += [f'        .DATA.L {s}' for s in symbols] + ['        .END']
        (work / (stem + '.src')).write_text('\n'.join(pull) + '\n')
        run('asmsh.exe', [stem + '.src', '-cpu=sh4', '-endian=little', '-object=' + stem + '.obj'])
        # The linker prefers a library module over a DEFINE, so it links against
        # a library holding only this module; every other symbol is an import.
        (work / (stem + '.lib')).unlink(missing_ok=True)
        (work / (stem + '.sub')).write_text(f'LIBRARY {Path(unit["library"]).name}\nOUTPUT {stem}.lib\nEXTRACT {unit["module"]}\nEXIT\n')
        run('lbr.exe', ['-subcommand=' + stem + '.sub'])
        if not (work / (stem + '.lib')).exists():
            raise ValueError(f'{stem}: lbr did not extract module {unit["module"]}; see build/work/{stem}.log')
        lines = [f'INPUT {stem}.obj', f'LIBRARY {stem}.lib'] + link_lines(unit, stem)
        (work / (stem + '.lnk')).write_text('\n'.join(lines) + '\n')
        run('lnk.exe', ['-subcommand=' + stem + '.lnk'])
        return (work / (stem + '.elf')).read_bytes(), (work / (stem + '.map')).read_text(errors='replace')

    shutil.copyfile(ROOT / unit['source'], work / (stem + '.c'))
    for header in sorted((ROOT / 'src/include').glob('*.h')):
        # Units compile in parallel in one work directory. Never expose a
        # truncated header to another compiler while refreshing its copy.
        staged = work / (stem + '.' + header.name + '.tmp')
        shutil.copyfile(header, staged)
        os.replace(staged, work / header.name)

    options = load(ROOT / 'config/compiler.json')['sets'][unit.get('options', 'game')]
    run('shc.exe', [stem + '.c', *options, '-code=asmcode', '-object=' + stem + '.src'])
    assembly = (work / (stem + '.src')).read_text(errors='replace')
    placed = (assembly.replace('ALIGN=16', 'ALIGN=2').replace('ALIGN=8', 'ALIGN=2')
              .replace('ALIGN=4', 'ALIGN=2'))
    (work / (stem + '.src')).write_text(placed)
    run('asmsh.exe', [stem + '.src', '-cpu=sh4', '-endian=little', '-object=' + stem + '.obj'])
    lines = [f'INPUT {stem}.obj'] + link_lines(unit, stem)
    (work / (stem + '.lnk')).write_text('\n'.join(lines) + '\n')
    run('lnk.exe', ['-subcommand=' + stem + '.lnk'])
    (work / (stem + '.src')).write_text(assembly)
    return (work / (stem + '.elf')).read_bytes(), (work / (stem + '.map')).read_text(errors='replace')


def smoke(work, flags):
    unit = {'id': 'link_smoke', 'source': 'tests/fixtures/link_smoke.c',
            'sections': [dict(section=name, kind=kind, address=address, size=size) for name, kind, address, size in
                         [('P', 'code', 0x1000, 4), ('C', 'data', 0x2000, 8), ('D', 'data', 0x4000, 4), ('B', 'bss', 0x5000, 4)]],
            'imports': {'_imported': 0x3000},
            'exports': {'_smoke': 0x1000, '_hook': 0x2000, '_imported_hook': 0x2004, '_value': 0x4000, '_scratch': 0x5000}}
    reference = bytearray(0x5004)
    reference[0x1000:0x1004] = bytes.fromhex('0b000900')
    reference[0x2000:0x2008] = bytes.fromhex('0010000000300000')
    reference[0x4000:0x4004] = bytes.fromhex('78563412')
    elf, link = compile_unit(unit, work, flags)
    proof, _ = compare(unit, elf, link, reference, 0)
    if not proof['exact']:
        raise ValueError('Compiler/linker smoke test failed: ' + repr(proof))
    print('PASS Hitachi code, data, BSS, imported and local pointer relocation', flush=True)


def build(selected=None, *, clean=False, jobs=None):
    started = time.monotonic()
    initial_inputs = input_fingerprint()
    metadata = verify_tools()
    target, units = load(ROOT / 'config/target.json'), load(ROOT / 'config/units.json')
    validate_units(units, target)
    program = verify_rom(target)
    base, offset, size = (number(target['main'][k]) for k in ('address', 'rom_offset', 'size'))
    main = program[offset:offset + size]
    from mapping import review
    sets = load(ROOT / 'config/compiler.json')['sets']
    flags = sets['game']
    output = ROOT / 'build'
    work = output / 'work'
    if work.exists():
        shutil.rmtree(work)
    from build_cache import ArtifactCache, prepare_work, shared_inputs
    prepare_work(ROOT, work / 'smoke')
    smoke(work / 'smoke', flags)
    cache = ArtifactCache(ROOT, shared_inputs(ROOT), clean=clean)
    if selected:
        units = [u for u in units if u['id'] == selected]
        if not units:
            raise ValueError('Unknown unit: ' + selected)
    rows, rebuilt = [], bytearray(main)
    failed = []
    matched_units = matched_sections = matched_bytes = 0
    from concurrent.futures import ThreadPoolExecutor
    jobs = jobs or min(4, os.cpu_count() or 1)
    with ThreadPoolExecutor(max_workers=jobs) as pool:
        compiled = list(pool.map(lambda unit: cache.compile(unit, work / unit['id'], compile_unit), units))
    cache_hits = sum(hit for _, _, hit in compiled)
    print(f'BUILD compiled={len(compiled)-cache_hits} cache_hits={cache_hits} jobs={jobs}', flush=True)
    from boundaries import BoundaryIndex
    from diagnose import diagnose
    boundary_index = BoundaryIndex.current()
    for unit, (elf, link, hit) in zip(units, compiled):
        try:
            proof, segments = compare(unit, elf, link, main, base)
        except ValueError as error:
            raise ValueError(f"{unit['id']}: {error}") from error
        credited = unit['mode'] == 'verified' and proof['exact']
        row = {**unit, **proof, 'credited': credited, 'elf_sha256': sha(elf)}
        if not credited and any(s['kind'] == 'code' for s in unit['sections']):
            row['boundaries'] = boundary_index.unit(unit)
            row['diagnosis'] = diagnose(unit, proof, elf, main, base)
        rows.append(row)
        if unit['mode'] == 'verified' and not proof['exact']:
            failed.append(unit['id'])
        if credited:
            matched_units += 1
            matched_sections += len(unit['sections'])
            matched_bytes += sum(number(part['size']) for part in unit['sections'] if part['kind'] != 'bss')
            for part in unit['sections']:
                if part['kind'] != 'bss':
                    start, count = number(part['address']), number(part['size'])
                    rebuilt[start-base:start-base+count] = memory_bytes(segments, start, count)
        details = ', '.join(f"{p['section']}: {p['equal_bytes']}/{p['size']} equal bytes, linked size {p['linked_size']}" for p in proof['sections'])
        if proof['functions'] and not credited:
            exact = sum(f['exact'] for f in proof['functions'])
            details += f"; {exact}/{len(proof['functions'])} functions match, {proof['function_bytes']} bytes; pools {proof['pool_bytes']} bytes"
        if selected or not credited:
            print(f"{'MATCH' if credited else 'CANDIDATE' if unit['mode'] == 'candidate' else 'FAIL'} {unit['id']} — {details}", flush=True)
    if input_fingerprint() != initial_inputs:
        raise ValueError('Build inputs changed while compiling; no proof published')
    if selected:
        (output / 'unit-proof.json').write_text(json.dumps(rows[0], indent=2) + '\n')
        if failed:
            raise ValueError('Verified unit mismatch: ' + ', '.join(failed))
        return
    function_bytes = sum(row['function_bytes'] + row['pool_bytes'] for row in rows if not row['credited'])
    print(f'MATCH {matched_units} verified config units, {matched_sections} source ranges, {matched_bytes:,} bytes; '
          f'{function_bytes:,} more bytes of matched functions and pools in candidate units', flush=True)
    merged = bytearray(program)
    merged[offset:offset+size] = rebuilt
    if rebuilt != main or merged != program:
        raise ValueError('Reconstructed image does not match the reference')
    if failed:
        raise ValueError('Verified unit mismatch: ' + ', '.join(failed))
    mapping = review(main, base, verified=rows)
    proof = {'schema_version': 1, 'input_sha256': initial_inputs, 'toolchain': metadata,
             'performance': {'compiled_units': len(compiled)-cache_hits, 'cached_units': cache_hits, 'jobs': jobs, 'elapsed_seconds': round(time.monotonic()-started, 3)},
             'main_size': size, 'main_address': base, 'main_sha256': sha(rebuilt),
             'program_sha256': sha(merged), 'rom_members_verified': len(target['roms']),
             'units': rows,
             'mapping': {k:v for k,v in mapping.items() if k != 'ranges'},
             'scope': 'Main image source progress only. Untranslated reference bytes preserve the remainder of the image.'}
    from feasibility import inventory
    proof['feasibility'] = inventory(main, base, [(r['address'], r['size'], r['kind']) for r in mapping['ranges']], rows)
    (output / 'main.bin').write_bytes(rebuilt)
    (output / target['program_rom']).write_bytes(merged)
    (output / 'mapping.json').write_text(json.dumps(mapping, indent=2) + '\n')
    (output / 'proof.json').write_text(json.dumps(proof, indent=2) + '\n')
    from report import publish
    publish(proof)
    print(f'PASS full main ({size:,} bytes) and program ROM ({len(program):,} bytes) match; original remainder is not decompilation credit.')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', nargs='?', default='check', choices=['check', 'unit'])
    parser.add_argument('unit', nargs='?')
    parser.add_argument('--clean', action='store_true', help='recompile all selected units without reading the cache')
    parser.add_argument('--jobs', type=int, default=None, help='bounded vendor-tool concurrency (default: up to 4)')
    args = parser.parse_args()
    if args.jobs is not None and args.jobs < 1:
        parser.error('--jobs must be positive')
    if args.command == 'unit' and not args.unit:
        parser.error('unit requires an id from config/units.json')
    (ROOT / 'build').mkdir(exist_ok=True)
    # Only one command may own build outputs/proofs, including selected checks.
    with (ROOT / 'build/check.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        check_inputs = input_fingerprint()
        if args.command == 'check':
            (ROOT / 'build/proof.json').unlink(missing_ok=True)
        preflight()
        if args.command == 'check':
            subprocess.run([sys.executable, '-m', 'unittest', 'discover', '-s', 'tests', '-v'], cwd=ROOT, check=True)
            from type_contracts import check_all
            print('TYPE CONTRACTS ' + json.dumps(check_all()), flush=True)
        if input_fingerprint() != check_inputs:
            raise ValueError('Inputs changed during preflight/tests; rerun on a stable tree')
        build(args.unit if args.command == 'unit' else None, clean=args.clean, jobs=args.jobs)


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, subprocess.SubprocessError) as error:
        sys.exit(str(error))
