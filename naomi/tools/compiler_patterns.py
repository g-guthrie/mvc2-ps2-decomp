#!/usr/bin/env python3
"""Reproduce the switch discovery against retail; never register anything."""
import hashlib
import json
import re
from pathlib import Path
import shutil
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import core
import diff_unit
from build import compile_unit

SOURCE = ROOT / 'tests/fixtures/compiler_patterns/ud2_12_recovered.c'
TARGETS = {'_func_0c0d6afa', '_func_0c0d6b1e'}


CATALOG = SOURCE.with_name('verified_sources.json')


def source_family_hits(spec, units=None, root=ROOT):
    """Cheap source-backed propagation leads, usable by the work queue."""
    units = units if units is not None else core.load(root / 'config/units.json')
    query = re.compile(spec['family_query'])
    hits = []
    for unit in units:
        source = unit.get('source')
        if not source or source == spec['source'] or unit.get('mode') != 'candidate':
            continue
        for line, text in enumerate((root / source).read_text().splitlines(), 1):
            if query.search(text):
                hits.append({'unit': unit['id'], 'source': source, 'line': line,
                             'evidence': text.strip()})
    return hits


def verified_source_corpus():
    """Recompile authoritative whole sources and local spelling controls.

    No copied fixtures, modified verified files, source admission or credit.
    Controls test compiler shape, not semantic correctness of untested C.
    """
    result, positives = [], {}
    units = core.load(ROOT / 'config/units.json')
    for spec in core.load(CATALOG):
        source = ROOT / spec['source']
        text = source.read_text()
        if spec['source'] not in positives:
            proof, unit = diff_unit.evaluate(spec['source'])
            assert proof['exact'], (spec['source'], proof)
            positives[spec['source']] = (proof, unit)
        proof, unit = positives[spec['source']]
        assert text.count(spec['replace']) == 1, spec['id']
        with tempfile.TemporaryDirectory(prefix='pattern-control-', dir=ROOT / 'build') as directory:
            path = Path(directory) / source.name
            path.write_text(text.replace(spec['replace'], spec['with']))
            control, _ = diff_unit.evaluate(str(path.relative_to(ROOT)), imports=unit['imports'], options=unit['options'])
        rows = [f for f in control['functions'] if f['symbol'] == spec['symbol']]
        assert len(rows) == 1 and not rows[0]['exact'] and not control['exact'], (spec['id'], rows)
        result.append({
            'id': spec['id'], 'source': spec['source'], 'symbol': spec['symbol'],
            'source_sha256': hashlib.sha256(source.read_bytes()).hexdigest(),
            'observation': spec['observation'], 'whole_unit_exact': proof['exact'],
            'sections': proof['sections'], 'negative_control': rows[0],
            'family_scope': spec['family_scope'], 'candidate_source_leads': source_family_hits(spec, units),
        })
    return {'patterns': result, 'input_sha256': core.input_fingerprint(),
            'options': core.load(ROOT / 'config/compiler.json')['sets']['game'], 'credit': 0}


def main():
    proof, unit = diff_unit.evaluate(str(SOURCE.relative_to(ROOT)))
    rows = [f for f in proof['functions'] if f['symbol'] in TARGETS]
    assert len(rows) == 2 and all(f['exact'] and f['size'] == 36 for f in rows), rows
    section = proof['sections'][0]
    assert section['size'] == section['linked_size'] == 620, section
    assert section['equal_bytes'] == 616 and not proof['exact'], section

    # Equivalent grouped labels must not be mistaken for the recovered shape.
    old = 'switch((signed char)a->b4c9){case 0:a->b1e9=8;break;case 1:a->b1e9=8;break;case 2:a->b1e9=8;break;}'
    new = 'switch((signed char)a->b4c9){case 0:case 1:case 2:a->b1e9=8;break;}'
    text = SOURCE.read_text()
    assert text.count(old) == 2
    with tempfile.TemporaryDirectory(prefix='pattern-control-', dir=ROOT / 'build') as directory:
        path = Path(directory) / 'grouped.c'
        path.write_text(text.replace(old, new))
        control, _ = diff_unit.evaluate(str(path.relative_to(ROOT)))
    controls = [f for f in control['functions'] if f['symbol'] in TARGETS]
    assert len(controls) == 2 and not any(f['exact'] for f in controls), controls

    float_source = SOURCE.with_name('float_context.c')
    float_unit = {
        'id': 'float_context', 'source': str(float_source.relative_to(ROOT)),
        'sections': [{'section': 'P', 'kind': 'code', 'address': 0x1000, 'size': 76}],
        'imports': {'_use': 0x0c025900}, 'options': 'game',
    }
    with tempfile.TemporaryDirectory(prefix='pattern-float-', dir=ROOT / 'build') as directory:
        work = Path(directory)
        shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work, dirs_exist_ok=True)
        elf, link = compile_unit(float_unit, work, [])
        compiled = core.memory_bytes(core.elf_segments(elf), 0x1000, 76)
        assembly = (work / 'float_context.src').read_text()
    target = core.load(ROOT / 'config/target.json')
    rom = core.verify_rom(target)
    start = core.number(target['main']['rom_offset']) + 0x0c10f1e8 - core.number(target['main']['address'])
    retail_block = rom[start:start + 20]
    # Both functions have five prologue/call instructions before the block.
    assert compiled[10:30] == retail_block
    # 5.1r08 spells a plain 2.0f literal as FLDI1/FADD too (5.0r31 pooled it).
    assert compiled[46:66] == retail_block
    assert assembly.count('FLDI1') == 2 and assembly.count("H'40000000") == 0
    print(json.dumps({
        'source_sha256': hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
        'input_sha256': core.input_fingerprint(),
        'options': core.load(ROOT / 'config/compiler.json')['sets']['game'],
        'retail_proof': proof,
        'grouped_case_negative_control': controls,
        'float_context': {
            'source_sha256': hashlib.sha256(float_source.read_bytes()).hexdigest(),
            'retail_start': '0x0c10f1e8', 'retail_end_exclusive': '0x0c10f1fc',
            'matching_bytes': 20, 'bytes_hex': retail_block.hex(),
            'literal_spelling_matches': True,
            'scope': 'Ten-instruction block only; no complete retail function match or registration.',
        },
        'credit': 0,
    }, indent=2))


if __name__ == '__main__':
    if sys.argv[1:] == ['--verified-sources']:
        print(json.dumps(verified_source_corpus(), indent=2))
    else:
        main()
