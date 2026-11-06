"""Separate proven source, SDK provenance, and unproven C-only feasibility."""
from collections import Counter
import struct

from core import ROOT, load, number
from vendor.sh4dis import sh4


def inventory(image, base, ranges, units):
    owned = sorted((number(s['address']), number(s['address']) + number(s['size']),
                    'sdk_object' if 'library' in u else 'exact_c')
                   for u in units if u.get('credited') for s in u['sections'] if s['kind'] == 'code')
    totals = Counter()
    examples = []
    pointer = 0
    for start, size, kind in sorted(ranges):
        if kind != 'code':
            continue
        for pc in range(start, start + size - 1, 2):
            while pointer < len(owned) and owned[pointer][1] <= pc:
                pointer += 1
            if pointer < len(owned) and owned[pointer][0] <= pc < owned[pointer][1]:
                category = owned[pointer][2]
            else:
                word = struct.unpack_from('<H', image, pc - base)[0]
                instruction = sh4.disasm(word, pc).lower()
                if any(token in instruction for token in ('ftrv', 'fipr', 'fschg', 'frchg', 'pref ')):
                    category = 'intrinsic_or_abi_review'
                elif any(token in instruction for token in (' sr', ',sr', ' fpscr', ',fpscr', 'rte', 'sleep', 'trapa')):
                    category = 'cpu_state_review'
                else:
                    category = 'c_feasibility_unassessed'
                if category != 'c_feasibility_unassessed' and len(examples) < 100:
                    examples.append({'address': hex(pc), 'instruction': instruction, 'category': category})
            totals[category] += 2
    return {'reviewed_instruction_bytes': dict(totals), 'signals': examples,
            'scope': 'Instruction-level triage, not function boundaries or proof of handwritten assembly. All unowned code remains unproven for C-only completion.',
            'c_only_completion_established': False}
