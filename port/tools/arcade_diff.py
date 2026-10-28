#!/usr/bin/env python3
"""Compare MvC2 per-character gameplay data: PS2 disc vs the user's NAOMI ROM set.

No asset bytes are embedded here; both data sets are read from the user's own
files at run time and only derived numbers are printed.

usage:
  arcade_diff.py ISO FILELIST NAOMI_ZIP [--chars 00,17,2c,2a,34,06] [--detail]
                 [--summary] [--json OUT]

  ISO        private/disc/mvc2.iso       (2048-byte sectors)
  FILELIST   private/disc/filelist.txt   ("path lba size" lines)
  NAOMI_ZIP  mvsc2.zip (MAME set: epr-23085a.ic11 + mpr-230xx mask ROMs)

Data model (see port/docs/ARCADE_DIFF.md for the evidence):
  PS2   AFS02 id 209+c = PLccPAK.BIN; header u32[15] section offsets; sections
        5..13 = TBL, HIT, HIT_FM, HIT_DT, TAIKI, ATCK, WARI, YOK, LIB (identical
        to the loose AFS02 files 268+c, 327+c, ...). Bound by func_0016F1B0.
  NAOMI cart image = epr-23085a at 0, mask ROMs at 0x800000*(n+1). File table
        {u32 cart_offset, u32 size}[787] at main-RAM 0x0C2285D4 (cart
        0x2085D4). NAOMI file index = PS2 AFS02 index - 12 for ids 209..798.
  TBL    animation scripts: u32 top table (at 0x100 normally) -> per-animation
         u32 group -> per-strength u32 script; 20-byte frame records
         {u8 b0,b1; s8 duration; u8 attr(0x80 = goto: next u32 is target);
          u32 sprite; u8 b8..b17; u16 box_selection}. func_00175700 (PS2),
         func_0c02a026 (NAOMI).
  HIT    box selections, 16 bytes: s16 slot[8]; slot0 = attack rect,
         slot1 low byte = body/throw rect (+flags), slot2..5 = hurt rects,
         byte 14 = height. Indexed by box_selection (<<4).
  HIT_FM rect table, 8 bytes {s16 x, half_w, y, half_h} (func_0c15dc08).
  HIT_DT attack records, 28 bytes, indexed by attack id & 0x7F; byte0 = base
         damage (func_0018B500 -> func_0018B890 PS2; 0x0c0482b0 -> 0x0c048520 NAOMI).
"""
import argparse, io, json, struct, sys, zipfile

NAOMI_ROMS = ["epr-23085a.ic11", "mpr-23048.ic17s", "mpr-23049.ic18", "mpr-23050.ic19s",
              "mpr-23051.ic20", "mpr-23052.ic21s", "mpr-23053.ic22", "mpr-23054.ic23s",
              "mpr-23055.ic24", "mpr-23056.ic25s", "mpr-23057.ic26", "mpr-23058.ic27s",
              "mpr-23059.ic28", "mpr-23060.ic29", "mpr-23061.ic30s", "mpr-23083.ic31",
              "mpr-23084.ic32s"]
NAOMI_FTAB = 0x2085D4          # cart offset of the file table (RAM 0x0C2285D4)
NAOMI_FTAB_N = 787
GROUPS = {'PAK': 209, 'TBL': 268, 'HIT': 327, 'HIT_FM': 386, 'HIT_DT': 445,
          'TAIKI': 504, 'ATCK': 563, 'WARI': 622, 'YOK': 681, 'LIB': 740}
PAK_SECTION = {'TBL': 5, 'HIT': 6, 'HIT_FM': 7, 'HIT_DT': 8, 'TAIKI': 9, 'ATCK': 10,
               'WARI': 11, 'YOK': 12, 'LIB': 13}
CHAR_NAMES = {0x00: 'Ryu', 0x06: 'Cyclops', 0x17: 'Cable', 0x2A: 'Storm',
              0x2C: 'Magneto', 0x34: 'Sentinel'}


def u32(b, o): return struct.unpack_from('<I', b, o)[0]


# ---------------------------------------------------------------- loaders
class PS2Data:
    def __init__(self, iso, filelist):
        self.f = open(iso, 'rb')
        for line in open(filelist):
            p, lba, _ = line.split()
            if p.upper().endswith('AFS02.AFS'):
                self.base = int(lba) * 2048
        self.f.seek(self.base)
        hdr = self.f.read(8)
        assert hdr[:4] == b'AFS\0'
        n = u32(hdr, 4)
        tab = self.f.read(8 * n)
        self.ents = [struct.unpack_from('<II', tab, 8 * i) for i in range(n)]

    def file(self, idx):
        o, s = self.ents[idx]
        self.f.seek(self.base + o)
        return self.f.read(s)

    def get(self, group, ch):
        return self.file(GROUPS[group] + ch)


class NaomiData:
    def __init__(self, zpath):
        z = zipfile.ZipFile(zpath)
        self.cart = bytearray(0x800000 * (len(NAOMI_ROMS)))
        for i, n in enumerate(NAOMI_ROMS):
            d = z.read(n)
            off = 0 if i == 0 else 0x800000 * i
            self.cart[off:off + len(d)] = d
        self.ents = [struct.unpack_from('<II', self.cart, NAOMI_FTAB + 8 * i)
                     for i in range(NAOMI_FTAB_N)]

    def file(self, idx):
        o, s = self.ents[idx]
        return bytes(self.cart[o:o + s])

    def get(self, group, ch):
        return self.file(GROUPS[group] + ch - 12)


# ---------------------------------------------------------------- TBL
def find_top(b):
    for t in range(0x100, len(b) - 64, 4):
        w = [u32(b, t + 4 * i) for i in range(48)]
        nz = [x for x in w if x]
        if not nz or w[0] == 0:
            continue
        f = min(nz)
        if f <= t or (f - t) % 4 or (f - t) // 4 > 48:
            continue
        k = (f - t) // 4
        if k >= 20 and all(x == 0 or f <= x < len(b) for x in w[:k]):
            return t
    raise ValueError('no animation top table')


def scripts(b):
    top = find_top(b)
    first = min(u32(b, top + 4 * i) for i in range(64) if u32(b, top + 4 * i) > top)
    groups = [u32(b, top + 4 * i) for i in range((first - top) // 4)]
    starts = set(g for g in groups if g)
    out = {}
    for ai, g in enumerate(groups):
        if not g:
            continue
        n = 0
        while n <= 64:
            o = g + 4 * n
            if n and o in starts:
                break
            if o + 4 > len(b):
                break
            v = u32(b, o)
            if v and not first <= v < len(b):
                break
            if n and o in out.values():
                break
            n += 1
        for si in range(n):
            r = u32(b, g + 4 * si)
            if r:
                out[(ai, si)] = r
    return top, out


def chain(b, off, limit=400):
    recs, seen, o = [], {}, off
    while len(recs) < limit and o + 20 <= len(b):
        if o in seen:
            return recs, ('loop', seen[o])
        seen[o] = len(recs)
        r = b[o:o + 20]
        recs.append(dict(b0=r[0], b1=r[1], dur=struct.unpack_from('<b', r, 2)[0],
                         attr=r[3] & 0x7F, spr=u32(r, 4), ext=r[8:18].hex(),
                         sel=struct.unpack_from('<H', r, 18)[0]))
        if r[3] & 0x80:
            if o + 24 > len(b):
                return recs, ('end', None)
            t = u32(b, o + 20)
            if t in seen:
                return recs, ('loop', seen[t])
            return recs, ('goto', t)
        o += 20
    return recs, ('end', None)


# ---------------------------------------------------------------- boxes
def sel(h, i):
    return struct.unpack_from('<8h', h, 16 * i) if 16 * i + 16 <= len(h) else None


def rect(f, i):
    i &= 0xFFFF
    return struct.unpack_from('<4h', f, 8 * i) if 8 * i + 8 <= len(f) else None


def live(r):
    return r is not None and r[1] != 0 and r[3] != 0


def boxes(h, f, s_idx):
    s = sel(h, s_idx)
    if s is None:
        return None
    hurt = [rect(f, s[k]) for k in (2, 3, 4)] + ([rect(f, s[5])] if s[5] else [])
    atk = rect(f, s[0]) if s[0] else None
    return dict(atk=atk if live(atk) else None, body=rect(f, s[1] & 0xFF),
                hurt=tuple(x for x in hurt if live(x)))


# ---------------------------------------------------------------- compare
def compare_char(P, N, ch):
    rep = dict(char='%02x' % ch, name=CHAR_NAMES.get(ch, ''))
    tp, tn = P.get('TBL', ch), N.get('TBL', ch)
    hp, hn = P.get('HIT', ch), N.get('HIT', ch)
    fp, fn = P.get('HIT_FM', ch), N.get('HIT_FM', ch)
    top_p, sp = scripts(tp)
    top_n, sn = scripts(tn)
    rep['tbl_top'] = (hex(top_n), hex(top_p))
    common = sorted(set(sp) & set(sn))
    rep['scripts'] = dict(naomi=len(sn), ps2=len(sp), common=len(common),
                          only_ps2=['%02x/%02x' % k for k in sorted(set(sp) - set(sn))],
                          only_naomi=['%02x/%02x' % k for k in sorted(set(sn) - set(sp))])
    timing, fields, inv, hurt_d, atk_d, body_d, nframes = [], {}, [], 0, 0, 0, 0
    for k in common:
        rp, ep = chain(tp, sp[k])
        rn, en = chain(tn, sn[k])
        dn = [r['dur'] for r in rn]
        dp = [r['dur'] for r in rp]
        if dn != dp or ep[0] != en[0]:
            timing.append(dict(script='%02x/%02x' % k, naomi_frames=len(rn), ps2_frames=len(rp),
                               naomi_total=sum(max(d, 0) for d in dn),
                               ps2_total=sum(max(d, 0) for d in dp),
                               naomi_dur=dn, ps2_dur=dp, naomi_end=en[0], ps2_end=ep[0]))
        for a, c in zip(rn, rp):
            for fld in ('b0', 'b1', 'attr', 'spr', 'ext', 'sel'):
                if a[fld] != c[fld]:
                    fields[fld] = fields.get(fld, 0) + 1
        # box comparison on frame-aligned scripts only
        if dn == dp:
            t = 0
            for i, (a, c) in enumerate(zip(rn, rp)):
                bn, bp = boxes(hn, fn, a['sel']), boxes(hp, fp, c['sel'])
                if bn is None or bp is None:
                    continue
                nframes += 1
                hurt_d += bn['hurt'] != bp['hurt']
                atk_d += bn['atk'] != bp['atk']
                body_d += bn['body'] != bp['body']
                if bool(bn['hurt']) != bool(bp['hurt']) and a['dur'] > 0:
                    inv.append(dict(script='%02x/%02x' % k, frame=i, start_tick=t, dur=a['dur'],
                                    invulnerable_on='naomi' if not bn['hurt'] else 'ps2'))
                t += max(a['dur'], 0)
    rep['timing_diffs'] = timing
    rep['record_field_diffs'] = fields
    rep['boxes'] = dict(frames_compared=nframes, hurt_diff=hurt_d, attack_diff=atk_d,
                        body_diff=body_d)
    rep['invuln_diffs'] = inv
    rep['rect_diffs'] = [dict(i=i, naomi=rect(fn, i), ps2=rect(fp, i))
                         for i in range(256) if rect(fn, i) != rect(fp, i)]
    rep['selection_diffs'] = [dict(i=i, naomi=sel(hn, i), ps2=sel(hp, i))
                              for i in range(min(len(hn), len(hp)) // 16) if sel(hn, i) != sel(hp, i)]
    # attack data
    dp_, dn_ = P.get('HIT_DT', ch), N.get('HIT_DT', ch)
    atk = []
    for i in range(len(dn_) // 28):
        a, c = dn_[28 * i:28 * i + 28], dp_[28 * i:28 * i + 28]
        if a != c and a.strip(b'\0'):
            atk.append(dict(id=i, bytes=[j for j in range(28) if a[j] != c[j]],
                            dmg_naomi=a[0], dmg_ps2=c[0]))
    rep['attack_records'] = dict(naomi=len(dn_) // 28,
                                 nonempty=sum(1 for i in range(len(dn_) // 28) if dn_[28 * i:28 * i + 28].strip(b'\0')),
                                 differing=len(atk),
                                 damage_lower_on_ps2=sum(1 for x in atk if x['dmg_ps2'] < x['dmg_naomi']),
                                 damage_higher_on_ps2=sum(1 for x in atk if x['dmg_ps2'] > x['dmg_naomi']),
                                 list=atk)
    # CPU AI tables (byte compare after stripping NAOMI 32-byte padding)
    ai = {}
    for g in ('TAIKI', 'ATCK', 'WARI', 'YOK', 'LIB'):
        a, c = N.get(g, ch).rstrip(b'\0'), P.get(g, ch).rstrip(b'\0')
        ai[g] = 'same' if a == c else 'differs (%d vs %d bytes)' % (len(a), len(c))
    rep['cpu_ai_tables'] = ai
    return rep


def check_pak_sections(P):
    bad = 0
    for ch in range(59):
        pak = P.get('PAK', ch)
        offs = struct.unpack_from('<15I', pak, 0)
        for g, s in PAK_SECTION.items():
            f = P.get(g, ch)
            if pak[offs[s]:offs[s] + len(f)] != f:
                bad += 1
    return bad


def print_rep(r, detail):
    print('== %s %s  (TBL top NAOMI/PS2 %s/%s)' % (r['char'], r['name'], *r['tbl_top']))
    s = r['scripts']
    print('  scripts: NAOMI %d, PS2 %d, common %d; only PS2 %s; only NAOMI %s' %
          (s['naomi'], s['ps2'], s['common'], s['only_ps2'] or '-', s['only_naomi'] or '-'))
    t = r['timing_diffs']
    print('  scripts with different frame timing: %d (total length shorter on PS2: %d, longer: %d)' %
          (len(t), sum(1 for x in t if x['ps2_total'] < x['naomi_total']),
           sum(1 for x in t if x['ps2_total'] > x['naomi_total'])))
    for x in t[:None if detail else 6]:
        print('    %s frames %d->%d ticks %d->%d end %s->%s  N%s P%s' %
              (x['script'], x['naomi_frames'], x['ps2_frames'], x['naomi_total'], x['ps2_total'],
               x['naomi_end'], x['ps2_end'], x['naomi_dur'][:24], x['ps2_dur'][:24]))
    print('  frame-record field diffs (aligned frames):', r['record_field_diffs'])
    b = r['boxes']
    print('  boxes over %d aligned frames: hurt %d, attack %d, body %d; rects changed %d; selections changed %d' %
          (b['frames_compared'], b['hurt_diff'], b['attack_diff'], b['body_diff'],
           len(r['rect_diffs']), len(r['selection_diffs'])))
    for x in r['rect_diffs'][:None if detail else 8]:
        print('    rect %3d NAOMI %s PS2 %s' % (x['i'], x['naomi'], x['ps2']))
    inv = r['invuln_diffs']
    print('  frames whose invulnerability (no live hurtbox) differs: %d' % len(inv))
    for x in inv[:None if detail else 10]:
        print('    %s frame %d tick %d dur %d: invulnerable only on %s' %
              (x['script'], x['frame'], x['start_tick'], x['dur'], x['invulnerable_on']))
    a = r['attack_records']
    print('  attack records: %d non-empty, %d differ; base damage lower on PS2 %d, higher %d' %
          (a['nonempty'], a['differing'], a['damage_lower_on_ps2'], a['damage_higher_on_ps2']))
    for x in a['list'][:None if detail else 6]:
        print('    atk %02x dmg %d->%d bytes %s' % (x['id'], x['dmg_naomi'], x['dmg_ps2'], x['bytes']))
    print('  CPU AI tables:', r['cpu_ai_tables'])


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('iso'); ap.add_argument('filelist'); ap.add_argument('naomi_zip')
    ap.add_argument('--chars', default='00,17,2c,2a,34,06')
    ap.add_argument('--detail', action='store_true')
    ap.add_argument('--summary', action='store_true', help='one line per character, all 59')
    ap.add_argument('--json')
    a = ap.parse_args()
    P, N = PS2Data(a.iso, a.filelist), NaomiData(a.naomi_zip)
    print('PS2 PAK sections that differ from loose AFS02 files: %d' % check_pak_sections(P))
    chars = range(59) if a.summary else [int(c, 16) for c in a.chars.split(',')]
    reps = [compare_char(P, N, c) for c in chars]
    if a.summary:
        print('ch timing(shorter/longer) inv_diff hurt atk rects atk_recs(lower/higher)')
        for r in reps:
            t = r['timing_diffs']; at = r['attack_records']
            print('%s %3d(%d/%d) %3d %4d %4d %3d %3d(%d/%d)' % (
                r['char'], len(t), sum(1 for x in t if x['ps2_total'] < x['naomi_total']),
                sum(1 for x in t if x['ps2_total'] > x['naomi_total']), len(r['invuln_diffs']),
                r['boxes']['hurt_diff'], r['boxes']['attack_diff'], len(r['rect_diffs']),
                at['differing'], at['damage_lower_on_ps2'], at['damage_higher_on_ps2']))
    else:
        for r in reps:
            print_rep(r, a.detail)
    if a.json:
        json.dump(reps, open(a.json, 'w'), indent=1)


if __name__ == '__main__':
    main()
