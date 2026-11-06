"""Classify evidence before spending a source-permutation budget."""
import argparse
from collections import Counter
import json
import re

from core import ROOT, elf_segments, link_map, load, memory_bytes, number
from vendor.sh4dis import sh4


def word_class(retail, actual, address):
    left, right = sh4.disasm(retail, address), sh4.disasm(actual, address)
    normalize = lambda s: re.sub(r'\b(?:fr|r)\d+\b', 'REG', s.lower())
    if normalize(left) == normalize(right):
        return 'register_choice'
    if retail >> 12 in (0x9, 0xd) and actual >> 12 == retail >> 12:
        return 'literal_displacement_or_field_offset'
    if retail >> 8 == actual >> 8 == 0xc7:
        return 'literal_displacement'
    if left.split(' ')[0] == right.split(' ')[0]:
        return 'operand_or_control_flow'
    return 'instruction_or_sequence'


def diagnose(unit, proof, elf, main, base):
    structural = [p for p in proof['sections'] if p['linked_size'] != p['size']
                  or p['linked_address'] != p['address']]
    if structural or any('exported symbol' in p for p in proof['problems']):
        return {'category': 'layout_or_signature', 'action': 'Check extent, function entries, return types and pools before register permutations.',
                'structural_sections': [p['section'] for p in structural]}
    segments = elf_segments(elf)
    examples, counts = [], Counter()
    for section in unit['sections']:
        if section['kind'] != 'code':
            continue
        address, size = number(section['address']), number(section['size'])
        interiors = [(number(p['address']), number(p['address']) + number(p['size']))
                     for p in section.get('interior', ())]
        try:
            actual = memory_bytes(segments, address, size)
        except ValueError:
            continue
        retail = main[address-base:address-base+size]
        for offset in range(0, min(len(actual), len(retail)) - 1, 2):
            pc = address + offset
            if actual[offset:offset+2] == retail[offset:offset+2]:
                continue
            if any(lo <= pc < hi for lo, hi in interiors):
                category = 'literal_value_or_layout'
            else:
                category = word_class(int.from_bytes(retail[offset:offset+2], 'little'),
                                      int.from_bytes(actual[offset:offset+2], 'little'), pc)
            counts[category] += 1
            if len(examples) < 8:
                examples.append({'address': hex(pc), 'category': category,
                                 'retail': retail[offset:offset+2].hex(), 'actual': actual[offset:offset+2].hex()})
    category = 'exact' if proof['exact'] else 'register_choice' if counts and set(counts) == {'register_choice'} else 'source_semantics_or_types'
    return {'category': category, 'word_counts': dict(counts), 'first_differences': examples,
            'action': 'Check real predecessors, switch structure and live ranges.' if category == 'register_choice'
                      else 'Review the first divergence against native types and control flow; these labels are diagnostic, not acceptance rules.'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source')
    parser.add_argument('--options', choices=['game', 'library'], help='Override the registered option set; unregistered sources default to game')
    args = parser.parse_args()
    from diff_unit import evaluate
    from boundaries import BoundaryIndex
    from type_contracts import check_all
    from behavioral_evidence import status as behavioral_status
    registered = next((unit for unit in load(ROOT / 'config/units.json')
                       if unit.get('source') == args.source), None)
    proof, unit = evaluate(args.source, options=args.options, descriptor=registered)
    print(json.dumps({'exact': proof['exact'], 'diagnosis': proof.get('diagnosis'),
                      'boundaries': BoundaryIndex.current().unit(unit),
                      'type_contracts': check_all(args.source),
                      'behavioral_evidence': behavioral_status(unit)}, indent=2))


if __name__ == '__main__':
    main()
