"""Generate private-repository progress views from a successful fresh build."""
import html
import json
import math
import re
from collections import deque
from core import ROOT, load, number


def credited_bytes(unit):
    """Bytes a unit earns: every code and data byte of a verified unit, or the
    bytes of the functions and pools that match inside a candidate unit."""
    kinds = dict(code=0, data=0)
    if unit.get('credited'):
        for part in unit['sections']:
            if part['kind'] in kinds:
                kinds[part['kind']] += number(part['size'])
                for interior in part.get('interior', ()):
                    if interior['kind'] != part['kind'] and interior['kind'] in kinds:
                        size = number(interior['size'])
                        kinds[part['kind']] -= size
                        kinds[interior['kind']] += size
    else:
        kinds['code'] = unit.get('function_bytes', 0)
        kinds['data'] = unit.get('pool_bytes', 0)
    return kinds


def metrics(proof):
    known = dict(code=0, data=0)
    matched = dict(code=0, data=0)
    provenance = {key: dict(code=0, data=0) for key in ('c_source', 'sdk_modules', 'candidate_fragments')}
    for unit in proof['units']:
        for part in unit['sections']:
            if part['kind'] in known:
                known[part['kind']] += number(part['size'])
        origin = ('candidate_fragments' if not unit.get('credited') else
                  'sdk_modules' if 'library' in unit else 'c_source')
        for kind, count in credited_bytes(unit).items():
            matched[kind] += count
            provenance[origin][kind] += count
    if 'mapping' in proof:
        known = {kind: proof['mapping']['reviewed_' + kind + '_bytes'] for kind in known}
    total = proof['main_size']
    result = {kind: {'matched_bytes': matched[kind], 'known_bytes': known[kind],
                     'possible_total_bytes': total - known['data' if kind == 'code' else 'code'],
                     'lower_bound_percent': 100 * matched[kind] / max(1, total - known['data' if kind == 'code' else 'code'])}
              for kind in known}
    if 'mapping' in proof:
        result['map'] = {'matched_bytes': total - proof['mapping']['unknown_bytes'], 'known_bytes': total}
        result['decomp'] = {'matched_bytes': matched['code'] + matched['data'], 'known_bytes': total}
    result['provenance'] = provenance
    return result


def work_queue(proof):
    """Rank current candidates from linker evidence; never store a hand-edited task list."""
    rows = []
    for unit in proof['units']:
        if unit['credited']:
            continue
        sections = [part for part in unit['sections'] if part['kind'] != 'bss']
        expected = sum(part['size'] for part in sections)
        equal = sum(part['equal_bytes'] for part in sections)
        placed = all(part['linked_address'] == part['address'] and
                     part['linked_size'] == part['size'] for part in sections)
        if placed and equal * 100 >= expected * 95:
            kind = 'near_match'
        elif not placed and equal == expected:
            kind = 'review_extent'
        elif placed and unit['function_bytes']:
            kind = 'partial_functions'
        else:
            kind = 'investigate'
        if unit.get('boundaries', {}).get('issues'):
            kind = 'review_boundaries'
        rows.append({'id': unit['id'], 'source': unit.get('source'), 'kind': kind,
                     'address': min(part['address'] for part in sections),
                     'equal_bytes': equal, 'expected_bytes': expected,
                     'new_code_bytes': max(0, sum(p['size'] - sum(i['size'] for i in p.get('interior',[]) if i['kind'] != 'code') for p in sections if p['kind']=='code') - unit.get('function_bytes',0)),
                     'c_completion_bytes': sum(p['size'] - sum(i['size'] for i in p.get('interior',[]) if i['kind'] != 'code') for p in sections if p['kind']=='code'),
                     'linked_sizes': [part['linked_size'] for part in sections],
                     'exact_functions': sum(bool(f['exact']) for f in unit['functions']),
                     'total_functions': len(unit['functions']),
                     'credited_bytes': unit['function_bytes'] + unit['pool_bytes'],
                     'problems': unit['problems'],
                     'diagnosis': unit.get('diagnosis'), 'boundaries': unit.get('boundaries'),
                     'next_action': 'Repair boundaries before source search' if kind == 'review_boundaries'
                                    else (unit.get('diagnosis') or {}).get('action', 'Inspect native semantics')})
    from recovery import prioritize
    prioritize(rows)
    return {'input_sha256': proof['input_sha256'], 'candidates': rows}


def progress_bar(current, total, width=32):
    filled = min(width, math.floor(width * current / total)) if total else 0
    return '█' * filled + '░' * (width - filled)


def tiles(proof):
    active = []
    for unit in proof['units']:
        for part in unit['sections']:
            if part['kind'] == 'bss':
                continue
            active.append({'name': unit['id'] + ':' + part['section'], 'address': part['address'],
                           'size': part['size'], 'state': 'candidate' if not unit['credited'] else
                           'sdk' if 'library' in unit else 'matched',
                           'source': unit.get('source') or f"{unit['library']}:{unit['module']}", 'kind': part['kind']})
    active.sort(key=lambda p: p['address'])
    bins = load(ROOT / 'config/regions.json')
    cursor = proof['main_address']
    unknown = []
    ai = 0
    for start, size in bins:
        if start != cursor or size <= 0:
            raise ValueError('Display regions must partition the main image')
        end = start + size
        while ai < len(active) and active[ai]['address'] + active[ai]['size'] <= start:
            ai += 1
        pieces = [(start, end)]
        i = ai
        while i < len(active) and active[i]['address'] < end:
            lo, hi = active[i]['address'], active[i]['address'] + active[i]['size']
            i += 1
            if hi <= start:
                continue
            pieces = [(a, b) for x, y in pieces for a, b in [(x, min(y, lo)), (max(x, hi), y)] if a < b]
        unknown.extend({'name': f'No C source 0x{a:08x}', 'address': a, 'size': b-a, 'state': 'unknown',
                        'kind': 'unclassified'} for a, b in pieces)
        cursor = end
    if cursor != proof['main_address'] + proof['main_size']:
        raise ValueError('Display regions do not cover the image')
    if sum(t['size'] for t in active + unknown) != proof['main_size']:
        raise ValueError('Treemap does not conserve image bytes')
    return active + unknown, active


def layout(items, width=1152, height=560):
    """Squarified treemap: rectangle area is proportional to reference bytes."""
    total = sum(p['size'] for p in items)
    if not total:
        return []
    pending = deque(sorted([(p['size'] * width * height / total, p) for p in items], key=lambda p: -p[0]))
    x = y = 0.0
    w, h = float(width), float(height)
    output = []
    while pending:
        side = min(w, h)
        row = []
        def score(cells):
            vals = [a for a, _ in cells]
            s = sum(vals)
            return max(side * side * max(vals) / (s*s), s*s / (side*side*min(vals)))
        while pending and (not row or score(row + [pending[0]]) <= score(row)):
            row.append(pending.popleft())
        area = sum(a for a, _ in row)
        if w >= h:
            strip, cursor = area/h, y
            for a, p in row:
                output.append((p, x, cursor, strip, a/strip))
                cursor += a/strip
            x, w = x+strip, max(0, w-strip)
        else:
            strip, cursor = area/w, x
            for a, p in row:
                output.append((p, cursor, y, a/strip, strip))
                cursor += a/strip
            y, h = y+strip, max(0, h-strip)
    return output


def svg(items, proof, active=False):
    m = metrics(proof)
    esc = html.escape
    prefix = 'active-' if active else 'main-'
    out = ['<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 1200 800" role="group" aria-label="Hitachi decompilation progress treemap">',
           '<defs>']
    for name, center, edge in [('matched','#00e500','#008600'),('sdk','#e4ad36','#80591c'),
                               ('candidate','#0086bb','#104253'),('unknown','#343737','#272a2b')]:
        out.append(f'<radialGradient id="{prefix}{name}"><stop stop-color="{center}"/><stop offset="1" stop-color="{edge}"/></radialGradient>')
    out += ['</defs><rect width="1200" height="800" fill="#171c24"/>',
            '<g font-family="system-ui,sans-serif" fill="#e9f1f5">',
            '<text x="24" y="36" font-size="23" font-weight="650">MARVEL vs. CAPCOM 2 · NAOMI</text>',
            f'<text x="24" y="62" font-size="13" fill="#a8b4c1">Hitachi SHC 5.1R08 · {"Active source units (zoom)" if active else "Main executable image"} · area = reference bytes</text>']
    for i, kind in enumerate(['code','data']):
        x = 24+i*588
        value = m[kind]
        pct = math.floor(value['lower_bound_percent']*1e6)/1e6
        out += [f'<text x="{x}" y="96" font-size="15">{kind.title()} ≥ {pct:.6f}% · {value["matched_bytes"]:,} matched bytes</text>',
                f'<rect x="{x}" y="107" width="564" height="8" rx="4" fill="#343b43"/>',
                f'<rect x="{x}" y="107" width="{564*pct/100:.9f}" height="8" fill="#00cf23"/>']
    out += ['<text x="24" y="142" font-size="12" fill="#a8b4c1">Percentages are against the whole image and are lower bounds; the README bars are against reviewed bytes.</text>']
    for p,x,y,w,h in layout(items):
        detail = f"{p['name']} · 0x{p['address']:08x} · {p['size']:,} bytes · {p['state']} · {p['kind']}"
        out.append(f'<g class="tile" role="button" aria-label="{esc(detail, quote=True)}" tabindex="0" data-detail="{esc(detail, quote=True)}"><title>{esc(detail)}</title><rect x="{24+x:.5f}" y="{160+y:.5f}" width="{w:.5f}" height="{h:.5f}" fill="url(#{prefix}{p["state"]})" stroke="#14191c" stroke-width="0.8"/>')
        if active and w > 160 and h > 48:
            out += [f'<text x="{36+x:.3f}" y="{190+y:.3f}" font-size="17">{esc(p["name"])}</text>',
                    f'<text x="{36+x:.3f}" y="{214+y:.3f}" font-size="13">{p["size"]} bytes · {p["state"]}</text>']
        out.append('</g>')
    out += ['<text x="24" y="749" font-size="13"><tspan fill="#00d823">■ Exact C</tspan><tspan dx="24" fill="#e4ad36">■ Prebuilt SDK</tspan><tspan dx="24" fill="#00a6df">■ Candidate C</tspan><tspan dx="24" fill="#a8b4c1">■ Original bytes</tspan></text>',
            f'<text x="24" y="776" font-size="12" fill="#a8b4c1">{"This zoom excludes unmapped bytes. " if active else "Gray tiles are display regions, not inferred functions. "}Build input: {proof["input_sha256"][:16]}</text>', '</g></svg>']
    return ''.join(out)


def publish(proof):
    all_tiles, active = tiles(proof)
    main_svg, active_svg = svg(all_tiles, proof), svg(active, proof, True)
    output = ROOT / 'build'
    output.mkdir(exist_ok=True)
    (output/'progress.svg').write_text(main_svg+'\n')
    (output/'active.svg').write_text(active_svg+'\n')
    data = {**proof, 'metrics': metrics(proof)}
    (output/'progress.json').write_text(json.dumps(data, indent=2)+'\n')
    page = '''<!doctype html><html lang="en"><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><title>MVC2 · Hitachi progress</title>
<style>body{margin:0;background:#171c24;color:#e9f1f5;font:15px system-ui}main{max-width:1400px;margin:auto;padding:20px}nav{display:flex;gap:12px;align-items:center;flex-wrap:wrap}button,a{color:inherit}button{background:#303b48;border:1px solid #657180;padding:10px 18px;border-radius:5px;cursor:pointer}button[aria-pressed=true]{background:#096d95}svg{width:100%;display:block}.tile:hover rect,.tile:focus rect{stroke:#fff;stroke-width:2}#detail{min-height:40px;color:#bccbd9}a{margin-left:auto}p{color:#acb9c6;line-height:1.6}</style>
<main><nav><button id="mainButton" aria-pressed="true">Main image</button><button id="activeButton" aria-pressed="false">Active source units</button><a href="https://github.com/g-guthrie/mvc2-naomi-decomp">Repository ↗</a></nav>
<div id="mainMap">MAIN_SVG</div><div id="activeMap" hidden>ACTIVE_SVG</div><div id="detail" aria-live="polite">Hover, focus, or tap a tile to inspect its address and size.</div>
<p>Green is C compiled by the bundled Hitachi compiler. Gold is a prebuilt Sega SDK module linked at its retail address. Blue is candidate C with matching functions or pools, without a verified whole unit. The full image comparison retains original bytes for untranslated regions. Progress covers the 2,424,832-byte main executable; the test program and graphics/audio ROMs remain outside this source metric.</p></main>
<script>const buttons=[document.getElementById('mainButton'),document.getElementById('activeButton')],maps=[document.getElementById('mainMap'),document.getElementById('activeMap')];buttons.forEach((b,i)=>b.onclick=()=>{maps.forEach((m,j)=>m.hidden=i!==j);buttons.forEach((b,j)=>b.setAttribute('aria-pressed',i===j));});document.querySelectorAll('.tile').forEach(t=>['mouseenter','focus','click'].forEach(e=>t.addEventListener(e,()=>document.getElementById('detail').textContent=t.dataset.detail)));</script></html>'''
    (output/'index.html').write_text(page.replace('MAIN_SVG',main_svg).replace('ACTIVE_SVG',active_svg))
    (output/'work_queue.json').write_text(json.dumps(work_queue(proof), indent=2)+'\n')
    m = metrics(proof)
    def row(label, kind):
        value = m[kind]
        return (f"| {label} | `{progress_bar(value['matched_bytes'], value['known_bytes'])}` "
                f"**{100 * value['matched_bytes'] / max(1, value['known_bytes']):.3f}%** | "
                f"{value['matched_bytes']:,} / {value['known_bytes']:,} |\n")
    def origin_row(label, kind):
        amount = sum(m['provenance'][kind].values())
        total = proof['main_size']
        return (f"| {label} | `{progress_bar(amount, total)}` "
                f"**{100 * amount / total:.3f}%** | {amount:,} / {total:,} |\n")
    block = ('<!-- progress:start -->\n'
             '| Track | Progress | Bytes |\n'
             '| --- | --- | ---: |\n'
             + row('Map', 'map') + row('Matched reviewed code', 'code') + row('Data', 'data')
             + row('[Decomp](config/units.json)', 'decomp')
             + (f"| Verified C executable code (lower bound) | `{progress_bar(m['provenance']['c_source']['code'], m['code']['possible_total_bytes'])}` **{100 * m['provenance']['c_source']['code'] / max(1, m['code']['possible_total_bytes']):.3f}%** | {m['provenance']['c_source']['code']:,} / {m['code']['possible_total_bytes']:,} |\n")
             + origin_row('Verified C code + data', 'c_source')
             + origin_row('Prebuilt SDK modules', 'sdk_modules')
             + origin_row('Candidate fragments', 'candidate_fragments')
             + '<!-- progress:end -->')
    readme = ROOT / 'README.md'
    readme.write_text(re.sub(
        r'<!-- progress:start -->.*?<!-- progress:end -->',
        block,
        readme.read_text(),
        flags=re.S))
