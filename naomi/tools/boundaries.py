"""Candidate boundary evidence from reviewed instructions, not decompiler labels."""
import bisect
import struct

from core import ROOT, load, number, verify_rom
from flow_map import decode


class BoundaryIndex:
    def __init__(self, image, base, ranges):
        self.image, self.base = image, base
        self.ranges = sorted(ranges)
        self.edges, self.delays, self.indirect = [], set(), []
        self.code = {}
        for lo, size, kind in self.ranges:
            if kind != 'code':
                continue
            for pc in range(lo, lo + size - 1, 2):
                word = struct.unpack_from('<H', image, pc - base)[0]
                info = decode(pc, word)
                self.code[pc] = info
                if info['delay']:
                    self.delays.add(pc + 2)
                if info['call'] is not None:
                    self.edges.append((pc, info['call'], 2, 'call'))
                for target in info['targets']:
                    self.edges.append((pc, target, 2, 'branch'))
                if info['lit']:
                    target, width = info['lit']
                    self.edges.append((pc, target, width, 'literal'))
                if info['kind'] in ('braf', 'bsrf', 'jmp'):
                    self.indirect.append(pc)

    @classmethod
    def current(cls):
        target = load(ROOT / 'config/target.json')
        program = verify_rom(target)
        base, offset, size = (number(target['main'][k]) for k in ('address', 'rom_offset', 'size'))
        ranges = [(number(r['address']), number(r['size']), r['kind'])
                  for r in load(ROOT / 'config/mapping.json')['ranges']]
        return cls(program[offset:offset + size], base, ranges)

    def frameless_conditional_tail(self, entry, source, target):
        """Recognize a small caller prefix that preserves callee-saved ABI state.

        A separate saved-register prologue distinguishes this from a label in
        a frameless continuation. Unknown instructions fail closed. Whole-unit
        compiler proof and independent export review remain admission gates.
        """
        if target not in self.code or target in self.delays:
            return False
        # Retail 0c1c4254 loads a field offset and zero into R0/R3 before
        # saving R14. Permit at most two scratch-register constant loads;
        # never hide an argument, stack, PR or callee-saved register change.
        for prefix in range(3):
            pc = target + prefix * 2
            if pc not in self.code or pc in self.delays:
                return False
            word = struct.unpack_from('<H', self.image, pc - self.base)[0]
            if word == 0x4f22 or word in range(0x2f86, 0x2fe7, 0x10):
                break
            if prefix == 2 or not (word >> 12 in (9, 13, 14) and ((word >> 8) & 15) < 4):
                return False
        end = source + (4 if self.code[source]['delay'] else 2)
        for pc in range(entry, end, 2):
            if pc not in self.code:
                return False
            word = struct.unpack_from('<H', self.image, pc - self.base)[0]
            n, m = (word >> 8) & 15, (word >> 4) & 15
            info = self.code[pc]
            if info['kind'] in ('bt', 'bf', 'bts', 'bfs'):
                if any(t != target and not entry <= t <= source for t in info['targets']):
                    return False
                continue
            # Single-precision scratch arithmetic used by 0c1c4236. FPSCR
            # changes, FR12-FR15 writes and stack-based stores remain excluded.
            floating = (word >> 12 == 15 and (
                (word & 15 == 0 and n < 12 and m < 12)
                or (word & 15 in (6, 8) and n < 12 and m < 8)
                or (word & 15 == 7 and n < 8 and m < 12)))
            safe = (floating or word == 0x0009
                    or (word >> 12 in (7, 9, 14) and n < 8)
                    or (word & 0xff00 in (0x8000, 0x8100, 0x8400, 0x8500) and m < 8)
                    or (word >> 12 == 6 and n < 8 and m < 8 and word & 15 in (3, 12, 13, 14, 15))
                    or (word >> 12 == 3 and n < 8 and m < 8 and word & 15 in (0, 2, 3, 6, 7, 12))
                    or (word >> 12 == 2 and n < 8 and m < 8 and word & 15 == 8)
                    or (word & 0xf0ff in (0x4011, 0x4015) and n < 8))
            if not safe:
                return False
        return True

    def audit(self, sections, entries=()):
        spans = sorted((number(s['address']), number(s['address']) + number(s['size']))
                       for s in sections if s['kind'] != 'bss')
        entries = set(entries)
        ordered_entries = sorted(entries)
        issues = []
        def inside(address, width=1):
            # Contiguous independently declared sections can own one literal.
            cursor = address
            for lo, hi in spans:
                if lo <= cursor < hi:
                    cursor = min(address + width, hi)
                    if cursor == address + width:
                        return True
            return False
        for lo, hi in spans:
            cursor = lo
            for start, count, kind in self.ranges:
                end = start + count
                if end <= cursor or start >= hi:
                    continue
                if start > cursor or kind not in ('code', 'data'):
                    break
                cursor = min(hi, end)
                if cursor == hi:
                    break
            if cursor != hi:
                issues.append({'kind': 'unreviewed_gap', 'address': hex(cursor), 'end': hex(hi)})
        dependencies = []
        for source, target, width, kind in self.edges:
            owner, destination = inside(source, 2), inside(target, width)
            overlap = any(target < hi and target + width > lo for lo, hi in spans)
            reason = None
            if owner and not destination:
                reason = 'outgoing_' + kind
            elif not owner and overlap and not (kind == 'call' and target in entries):
                reason = 'incoming_' + kind
            elif (owner and kind == 'branch' and target in entries
                  and self.code[source]['kind'] in ('bt', 'bf', 'bts', 'bfs')
                  and ordered_entries[max(0, bisect.bisect_right(ordered_entries, source)-1)] != target):
                entry = ordered_entries[max(0, bisect.bisect_right(ordered_entries, source)-1)]
                if not self.frameless_conditional_tail(entry, source, target):
                    reason = 'conditional_entry'
            if reason:
                row = {'kind': reason, 'source': hex(source), 'target': hex(target), 'width': width}
                issues.append(row)
            if (owner or overlap) and (owner != destination or reason):
                dependencies.append({'kind': kind, 'source': hex(source), 'target': hex(target), 'width': width})
        for entry in sorted(entries):
            if entry not in self.code:
                issues.append({'kind': 'entry_not_reviewed_code', 'address': hex(entry)})
            if entry in self.delays:
                issues.append({'kind': 'entry_in_delay_slot', 'address': hex(entry)})
        for pc in self.delays:
            if inside(pc - 2, 2) and not inside(pc, 2):
                issues.append({'kind': 'split_delay_slot', 'address': hex(pc)})
        unresolved = [hex(pc) for pc in self.indirect if inside(pc, 2)]
        return {'status': 'blocked' if issues else 'direct_edges_closed',
                'issues': issues, 'dependencies': dependencies,
                'indirect_transfers_requiring_review': unresolved,
                'scope': 'Reviewed direct edges and literal extents only; indirect targets and source provenance still require review.'}

    def unit(self, unit):
        entries = [number(address) for symbol, address in unit.get('exports', {}).items()
                   if symbol.startswith('_func_')]
        return self.audit(unit['sections'], entries)
