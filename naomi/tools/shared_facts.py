#!/usr/bin/env python3
"""Inspect contract consumers and native callback-entry leads; never promote hints."""
import argparse
from collections import defaultdict
import json
import re

from core import ROOT, load, number, verify_rom
from flow_map import Image, recover_indexed_tables
from inspect_rom import inspect


def callback_review(image, ranges, units):
    """Return candidate interior entry hints backed by recovered table cells.

    Table recovery is heuristic (including its table extent). A cell containing
    an address is evidence to review, not proof that the address starts a function.
    This deliberately neither edits the mapping nor grants matching-code credit.
    """
    pcs = [pc for r in ranges if r['kind'] == 'code'
           for pc in range(number(r['address']), number(r['address']) + number(r['size']), 2)]
    tables, _ = recover_indexed_tables(image, pcs)
    witnesses = defaultdict(set)
    for start, size in tables:
        for cell in range(start, start + size, 4):
            witnesses[image.u32(cell)].add(cell)
    rows = []
    for unit in units:
        if unit['mode'] != 'candidate':
            continue
        exports = {number(value) for value in unit.get('exports', {}).values()}
        for target, cells in sorted(witnesses.items()):
            if target in exports:
                continue
            for section in unit['sections']:
                start = number(section['address'])
                if section['kind'] != 'code' or not start < target < start + number(section['size']):
                    continue
                if any(number(p['address']) <= target < number(p['address']) + number(p['size'])
                       for p in section.get('interior', [])):
                    continue
                size = min(24, image.end - target)
                rows.append({'id': unit['id'], 'address': f'0x{target:08x}',
                             'witnesses': [f'0x{cell:08x}' for cell in sorted(cells)],
                             'confidence': 'table-derived hint', 'needs_review': True,
                             'section': {'address': f'0x{start:08x}', 'size': section['size']},
                             'native_disassembly': inspect(image.blob, image.base, target, size),
                             'next_action': 'Review dispatch/table extent, entry predecessors, delay slots and literal ownership before splitting.'})
                break
    return rows


def contract_consumers(root=ROOT):
    """Expose established claims and all source files naming each contracted type.

    A textual consumer is a review target, not an automatically validated caller.
    Native/source evidence text is retained beside each fact for inspection.
    """
    contracts = load(root / 'config/type_contracts.json')['contracts']
    sources = {str(p.relative_to(root)): p.read_text() for p in (root / 'src').rglob('*.c')}
    rows = []
    for contract in contracts:
        types = sorted({item['type'] for group in ('members', 'sizes') for item in contract.get(group, [])})
        consumers = {name: [path for path, text in sorted(sources.items())
                            if re.search(r'\b' + re.escape(name) + r'\b', text)] for name in types}
        symbols = sorted({symbol for item in contract.get('prototypes', [])
                          for symbol in re.findall(r'\b(?:func|dat)_[0-9a-fA-F]+\b', item['declaration'])})
        symbol_consumers = {name: [path for path, text in sorted(sources.items())
                                   if re.search(r'\b' + re.escape(name) + r'\b', text)] for name in symbols}
        rows.append({'source': contract['source'], 'members': contract.get('members', []),
                     'sizes': contract.get('sizes', []), 'prototypes': contract.get('prototypes', []),
                     'textual_consumers': consumers, 'textual_symbol_consumers': symbol_consumers})
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--callbacks', action='store_true', help='also scan reviewed code for callback-table entry leads')
    args = parser.parse_args()
    result = {'scope': 'Contracts assert listed facts only. Textual consumers are not validated prototypes; callback entries remain hints.',
              'contracts': contract_consumers()}
    if args.callbacks:
        target = load(ROOT / 'config/target.json')
        rom = verify_rom(target)
        main = target['main']
        offset, size = number(main['rom_offset']), number(main['size'])
        image = Image(rom[offset:offset + size], number(main['address']))
        result['callback_entries'] = callback_review(image, load(ROOT / 'config/mapping.json')['ranges'],
                                                     load(ROOT / 'config/units.json'))
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
