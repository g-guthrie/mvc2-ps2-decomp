#!/usr/bin/env python3
"""Plan recovery work and remember bounded experiments; never grant matching credit."""
import argparse
from datetime import datetime, timezone
import fcntl
import hashlib
import json
import platform
from pathlib import Path
import subprocess
import time

from core import ROOT, input_fingerprint, load, number, verify_rom

JOURNAL = 'config/recovery.jsonl'


def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def source_key(unit, root=ROOT):
    path = root / unit.get('source', '')
    return hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else 'no-source'


def canonical_descriptor(unit, root=ROOT):
    value=json.loads(json.dumps(unit))
    value.setdefault('options','game')
    if value.get('source'):
        try:value['source']=str((root/value['source']).resolve().relative_to(root.resolve()))
        except ValueError:pass
    for part in value.get('sections',[]):
        part['address']=number(part['address'])
        for item in part.get('interior',[]):item['address']=number(item['address'])
    for name in ('imports','exports'):
        value[name]={k:number(v) for k,v in value.get(name,{}).items()}
    return value


def search_context(unit, root=ROOT):
    from build_cache import shared_inputs
    files = ['config/target.json', 'config/mapping.json', 'config/runtime.json',
             'config/type_contracts.json', 'config/units.json', 'tools/diff_unit.py', 'tools/permute.py']
    return digest({'shared': shared_inputs(root), 'unit': canonical_descriptor(unit,root), 'source':source_key(unit,root), 'host':(platform.system(),platform.machine()),
                   'files': {p: hashlib.sha256((root/p).read_bytes()).hexdigest() for p in files}})


def read_journal(root=ROOT):
    path = root / JOURNAL
    if not path.exists(): return []
    rows = []
    with path.open() as handle:
        fcntl.flock(handle,fcntl.LOCK_SH)
        for line in handle.read().splitlines():
            if line.strip(): rows.append(json.loads(line))
    return rows


def record(row, root=ROOT):
    path = root / JOURNAL
    path.parent.mkdir(parents=True, exist_ok=True)
    row = {'schema': 1, 'time': datetime.now(timezone.utc).isoformat(), **row}
    with path.open('a') as f:
        fcntl.flock(f, fcntl.LOCK_EX)
        f.write(json.dumps(row, sort_keys=True) + '\n')
    return row


def experiment_state(unit, journal, root=ROOT):
    key = source_key(unit, root)
    rows = [r for r in journal if r.get('id') == unit['id'] and r.get('source_sha256') == key]
    if not rows: return {'status': 'untried', 'attempts': 0, 'minutes': 0}
    if any(r.get('context') for r in rows):
        context=search_context(unit,root)
        rows=[r for r in rows if not r.get('context') or r['context']==context]
    if not rows:return {'status':'untried','attempts':0,'minutes':0,'reason':'compiler, facts, or unit changed'}
    last = rows[-1]
    attempts = sum(max(0,r.get('attempts',0)-r.get('compile_errors',0)) for r in rows if r.get('outcome')!='inconclusive')
    minutes = sum(r.get('minutes', 0) for r in rows if r.get('outcome')!='inconclusive')
    stalled = last.get('outcome') == 'stalled' or (last.get('outcome') not in ('evidence', 'improved', 'matched', 'inconclusive') and (attempts >= 10 or minutes >= 20))
    return {'status': 'needs_new_evidence' if stalled else 'active',
            'attempts': attempts, 'minutes': minutes, 'last_hypothesis': last.get('hypothesis'),
            'next_action': last.get('next_action'), 'effort_minutes': last.get('effort_minutes')}


def prioritize(rows):
    """Transparent estimates, not measured productivity or acceptance decisions."""
    for row in rows:
        diagnosis = (row.get('diagnosis') or {}).get('category')
        defaults = {'register_choice': 90, 'source_semantics_or_types': 60, 'layout_or_signature': 80}
        effort = defaults.get(diagnosis, 45 if row.get('kind') == 'near_match' else 60)
        if row.get('kind') == 'untouched': effort = 20 + row['new_code_bytes']/12
        if row.get('callback_entries'): effort = min(effort, 35)
        effort = (row.get('experiment') or {}).get('effort_minutes') or effort
        row['estimated_effort_minutes'] = round(max(1, effort), 1)
        row['estimated_c_completion_bytes_per_hour'] = round(row.get('c_completion_bytes',row.get('new_code_bytes',0))*60/max(1,effort),1)
        row['estimated_new_code_bytes_per_hour'] = round(row.get('new_code_bytes', 0)*60/max(1, effort), 1)
        row['estimate_scope'] = 'Planning heuristic; replace with measured effort, not a completion forecast.'
    rows.sort(key=lambda r: ((r.get('experiment') or {}).get('status') == 'needs_new_evidence',
                            -r['estimated_new_code_bytes_per_hour'], -r['estimated_c_completion_bytes_per_hour'], -r.get('family_reach', 0),
                            r['address'], r['id']))
    return rows


def disjoint_batch(rows, owners):
    """One integrator owns registry/shared headers; proposed workers own whole spans."""
    selected, spans = [], []
    anchor = None
    for row in rows:
        if len(selected) == len(owners): break
        if (row.get('experiment') or {}).get('status') == 'needs_new_evidence': continue
        if row.get('boundaries', {}).get('issues'): continue
        if anchor is not None:
            shared_family=set(anchor.get('pattern_families',[])) & set(row.get('pattern_families',[]))
            if not shared_family and (anchor['address'] >> 16) != (row['address'] >> 16):continue
        ranges = row.get('ranges', [(row['address'], row['address'] + row['expected_bytes'])])
        if any(a < y and b > x for a,b in ranges for x,y in spans): continue
        if anchor is None:anchor=row
        selected.append({'batch_basis':'shared source-pattern family or native address region; semantics still require review','id': row['id'], 'owner': owners[len(selected)], 'ranges': ranges,
                         'source': row.get('source'), 'next_action': row.get('next_action'),
                         'shared_writes': 'integration owner only'})
        spans.extend(ranges)
    return selected


def require_proof(root=ROOT):
    proof = load(root / 'build/proof.json')
    if proof['input_sha256'] != input_fingerprint(root):
        raise ValueError('Build proof is stale; run python3 tools/build.py check before planning or measuring.')
    return proof


def plan(root=ROOT, owners=None, max_span=4096):
    from report import work_queue
    from unit_spans import spans, owned_code_sections
    from shared_facts import callback_review
    from flow_map import Image
    from behavioral_evidence import status as behavior_status
    from compiler_patterns import CATALOG, source_family_hits
    started=time.monotonic()
    proof = require_proof(root)
    units = load(root/'config/units.json'); by_id = {u['id']: u for u in units}
    mapped = load(root/'config/mapping.json')['ranges']
    ranges = [(number(r['address']), number(r['size']), r['kind']) for r in mapped]
    target = load(root/'config/target.json'); rom = verify_rom(target, root)
    base=number(target['main']['address']); off=number(target['main']['rom_offset'])
    image=rom[off:off+number(target['main']['size'])]
    rows = work_queue(proof)['candidates']
    callbacks = callback_review(Image(image, base), mapped, units)
    journal = read_journal(root)
    behavioral_path = root/'build/simulator-pilot/results.json'
    try:behavioral = load(behavioral_path)
    except (OSError,ValueError):behavioral={}
    catalog = load(root / CATALOG.relative_to(ROOT))
    families = {}
    for spec in catalog:
        for hit in source_family_hits(spec, units, root=root):
            uid = hit['unit'] if isinstance(hit, dict) else hit

            if spec['id'] not in families.setdefault(uid, []): families[uid].append(spec['id'])
    for row in rows:
        unit=by_id[row['id']]
        row['ranges']=[(number(s['address']),number(s['address'])+number(s['size'])) for s in unit['sections'] if s['kind']=='code']
        row['experiment']=experiment_state(unit,journal,root)
        row['callback_entries']=[c for c in callbacks if c['id']==row['id']]
        row['pattern_families']=families.get(row['id'],[])
        row['related_units']=sorted(uid for uid,fs in families.items() if uid!=row['id'] and set(fs)&set(row['pattern_families']))
        row['family_reach']=len(row['related_units'])
        row['behavioral']=behavior_status(unit,root=root,report=behavioral)
        if row.get('boundaries',{}).get('issues'):row['next_action']='Repair native boundaries before source search.'
        elif row['callback_entries']: row['next_action']='Review native callback witnesses and recover missing entries before source search.'
        elif row['behavioral']['status']=='current_failure':row['next_action']='Review failing tested expectations before code-generation permutations.'
        elif row['behavioral']['status']=='current_pass': row['next_action']=row['behavioral']['action']
        if row['experiment']['status']=='needs_new_evidence': row['next_action']='Park this input until a recorded new fact changes the hypothesis.'
    proposals=spans(image,base,ranges,owned_code_sections(units))
    skipped=0
    for start,size in proposals:
        if size<64 or size>max_span: skipped+=1;continue
        code=sum(max(0,min(start+size,lo+n)-max(start,lo)) for lo,n,k in ranges if k=='code')
        rows.append({'id':f'untouched_{start:08x}','kind':'untouched','address':start,'expected_bytes':size,
                     'new_code_bytes':code,'c_completion_bytes':code,'ranges':[(start,start+size)],
                     'next_action':('Try existing SDK-module placement first; preserve SDK provenance before C feasibility review.' if start>=0x0c1e9000 else 'Review indirect targets/types, then clone a complete source unit.'),
                     'domain':'sdk' if start>=0x0c1e9000 else 'game',
                     'experiment':{'status':'untried'},'boundaries':{'issues':[]},'family_reach':0})
    prioritize(rows)
    result={'input_sha256':proof['input_sha256'],'items':rows,'untouched_spans_total':len(proposals),
            'untouched_spans_outside_size_window':skipped,'max_span':max_span,
            'batch':disjoint_batch(rows,owners or ['worker-1','worker-2','worker-3']),
            'integration':'One owner integrates source, facts and registry; full build at the batch checkpoint. No worker edits shared headers independently.'}
    if input_fingerprint(root)!=proof['input_sha256']:
        raise ValueError('Inputs changed during planning; no plan published')
    result['generation_seconds']=round(time.monotonic()-started,3)
    (root/'build/recovery_plan.json').write_text(json.dumps(result,indent=2)+'\n')
    return result


def main():
    ap=argparse.ArgumentParser(description=__doc__);sub=ap.add_subparsers(dest='command',required=True)
    p=sub.add_parser('plan');p.add_argument('--owners',default='worker-1,worker-2,worker-3');p.add_argument('--max-span',type=int,default=4096)
    p=sub.add_parser('record');p.add_argument('id');p.add_argument('--hypothesis',required=True);p.add_argument('--outcome',choices=['stalled','evidence','improved','matched'],required=True);p.add_argument('--minutes',type=float,required=True);p.add_argument('--attempts',type=int,default=0);p.add_argument('--evidence',required=True);p.add_argument('--next-action',required=True);p.add_argument('--effort-minutes',type=float)
    p=sub.add_parser('snapshot');p.add_argument('path',type=Path)
    p=sub.add_parser('measure');p.add_argument('baseline',type=Path)
    args=ap.parse_args()
    if args.command=='plan':
        result=plan(owners=args.owners.split(','),max_span=args.max_span)
        print(json.dumps({'items':len(result['items']),'batch':result['batch'],'report':'build/recovery_plan.json'},indent=2));return
    if args.command=='record':
        unit=next(u for u in load(ROOT/'config/units.json') if u['id']==args.id)
        if args.minutes<0 or args.attempts<0 or (args.effort_minutes is not None and args.effort_minutes<=0):ap.error('Effort must be nonnegative; estimates positive')
        print(json.dumps(record({'kind':'experiment','id':args.id,'source_sha256':source_key(unit),
            'context':search_context(unit),'hypothesis':args.hypothesis,'outcome':args.outcome,'minutes':args.minutes,'attempts':args.attempts,
            'evidence':args.evidence,'next_action':args.next_action,'effort_minutes':args.effort_minutes}),indent=2));return
    from report import metrics
    proof=require_proof();current={'time':time.time(),'input_sha256':proof['input_sha256'],'metrics':metrics(proof)}
    if args.command=='snapshot':
        args.path.parent.mkdir(parents=True,exist_ok=True);args.path.write_text(json.dumps(current,indent=2)+'\n');return
    before=load(args.baseline);hours=max((current['time']-before['time'])/3600,1/3600)
    origins=current['metrics']['provenance'];old=before['metrics']['provenance']
    delta={k:{b:origins[k][b]-old[k][b] for b in ['code','data']} for k in origins}
    result=record({'kind':'batch_result','baseline':before['input_sha256'],'current':current['input_sha256'],
                   'elapsed_hours':hours,'provenance_delta':delta,
                   'new_verified_c_code_bytes_per_hour':delta['c_source']['code']/hours,
                   'net_new_matched_code_bytes':current['metrics']['code']['matched_bytes']-before['metrics']['code']['matched_bytes']})
    print(json.dumps(result,indent=2))


if __name__=='__main__': main()
