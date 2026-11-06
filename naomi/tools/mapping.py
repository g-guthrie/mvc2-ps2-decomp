"""Verify reviewed ranges and preserve every unreviewed byte as an explicit gap."""
import bisect

from core import ROOT, load, number, sha


def review(image, base, entries=None, verified=()):
    entries = load(ROOT/'config/mapping.json')['ranges'] if entries is None else entries
    entries = list(entries)
    known = []
    for part in entries:
        lo, size = number(part['address']), number(part['size'])
        known.append((lo, lo + size, part['kind']))
    known.sort()
    starts = [item[0] for item in known]
    for unit in verified:
        if not unit['credited']:
            continue
        for part in unit['sections']:
            if part['kind'] == 'bss':
                continue
            start, end = number(part['address']), number(part['address']) + number(part['size'])
            # A compiled object holds bytes that are not instructions: SHC emits a
            # translation unit's literal pool inside the same linked section as its
            # code. The unit declares those interiors so the ledger can keep calling
            # them data while the unit still owns the whole section.
            interiors = []
            for spare in part.get('interior', ()):
                lo = number(spare['address'])
                interiors.append((lo, lo + number(spare['size']), spare['kind']))
            for lo, hi, _kind in interiors:
                if lo < start or hi > end:
                    raise ValueError('Interior range falls outside its unit section')
            pieces = [(start, end)]
            i = bisect.bisect_right(starts, start) - 1
            if i < 0:
                i = 0
            while i < len(known) and known[i][0] < end:
                lo, hi, kind = known[i]
                i += 1
                if hi <= start or lo >= end:
                    continue
                if kind != part['kind']:
                    covered = any(spare_lo <= max(lo, start) and min(hi, end) <= spare_hi
                                  and spare_kind == kind
                                  for spare_lo, spare_hi, spare_kind in interiors)
                    # A library unit links a prebuilt SDK object. It proves the
                    # bytes, not which of them are instructions, so the reviewed
                    # classification of its interior stands as it is.
                    covered = covered or 'library' in unit
                    if not covered:
                        raise ValueError('Verified source conflicts with reviewed code/data mapping')
                pieces = [(a, b) for x, y in pieces for a, b in [(x, min(y, lo)), (max(x, hi), y)] if a < b]
            for lo, hi in pieces:
                origin = (f"library unit {unit['id']} module {unit['module']}" if 'library' in unit
                          else f"C unit {unit['id']} section {part['section']}")
                cuts = {lo, hi}
                for spare_lo, spare_hi, _kind in interiors:
                    if spare_lo < hi and lo < spare_hi:
                        cuts.update((max(lo, spare_lo), min(hi, spare_hi)))
                ordered_cuts = sorted(cuts)
                for start, end in zip(ordered_cuts, ordered_cuts[1:]):
                    kind = next((spare_kind for spare_lo, spare_hi, spare_kind in interiors
                                 if spare_lo <= start and end <= spare_hi), part['kind'])
                    entries.append(dict(address=start, size=end-start, kind=kind,
                                        sha256=sha(image[start-base:end-base]),
                                        evidence=f"Current build verifies {origin}"))
    ordered = sorted(entries, key=lambda p: number(p['address']))
    cursor, ranges = base, []
    totals = {'code': 0, 'data': 0, 'unknown': 0}
    for part in ordered:
        address, size = number(part['address']), number(part['size'])
        if part['kind'] not in {'code', 'data'} or size <= 0 or address < cursor or address+size > base+len(image):
            raise ValueError('Invalid or overlapping reviewed mapping range')
        if not part.get('evidence') or sha(image[address-base:address-base+size]) != part['sha256']:
            raise ValueError(f'Mapping evidence/hash mismatch at 0x{address:08x}')
        if address > cursor:
            ranges.append(dict(address=cursor, size=address-cursor, kind='unknown'))
            totals['unknown'] += address-cursor
        ranges.append({**part, 'address': address, 'size': size})
        totals[part['kind']] += size
        cursor = address+size
    if cursor < base+len(image):
        ranges.append(dict(address=cursor, size=base+len(image)-cursor, kind='unknown'))
        totals['unknown'] += base+len(image)-cursor
    return {'status': 'complete' if not totals['unknown'] else 'incomplete',
            'reviewed_code_bytes': totals['code'], 'reviewed_data_bytes': totals['data'],
            'unknown_bytes': totals['unknown'], 'main_sha256': sha(image), 'ranges': ranges}
