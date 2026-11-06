#!/usr/bin/env python3
"""Search source spellings that move a candidate closer to retail.

    python3 tools/permute.py src/candidates/unit.c --hypothesis "native-supported change"

Compiles bounded isolated spelling trials. Persistent negative results avoid
repeating failed variants under unchanged compiler/fact inputs. Stalled sources
need a new evidence statement. Only an improvement is atomically written back;
matching and registration remain separate full-byte checks.
"""
import argparse
import fcntl
import json
import os
import tempfile
import time
from pathlib import Path
import re
import sys
import hashlib

from core import ROOT, load
from diff_unit import evaluate
from recovery import search_context, read_journal, experiment_state, record, source_key

FIELD = r'[A-Za-z_]\w*(?:->\w+|\.\w+|\[[^\]]*\])+'

REWRITES = [
    ('not-vs-eq0', rf'if \(({FIELD}) == 0\)', lambda m: f'if (!{m.group(1)})'),
    ('eq0-vs-not', rf'if \(!({FIELD})\)', lambda m: f'if ({m.group(1)} == 0)'),
    ('ne0-vs-plain', rf'if \(({FIELD}) != 0\)', lambda m: f'if ({m.group(1)})'),
    ('plain-vs-ne0', rf'if \(({FIELD})\)', lambda m: f'if ({m.group(1)} != 0)'),
    ('inc-vs-add', rf'({FIELD})\+\+;', lambda m: f'{m.group(1)} = {m.group(1)} + 1;'),
    ('add-vs-inc', rf'({FIELD}) = \1 \+ 1;', lambda m: f'{m.group(1)}++;'),
    ('dec-vs-sub', rf'({FIELD})--;', lambda m: f'{m.group(1)} = {m.group(1)} - 1;'),
    ('sub-vs-dec', rf'({FIELD}) = \1 - 1;', lambda m: f'{m.group(1)}--;'),
    ('pluseq-vs-long', rf'({FIELD}) \+= ({FIELD}|[-\w.]+);', lambda m: f'{m.group(1)} = {m.group(1)} + {m.group(2)};'),
    ('long-vs-pluseq', rf'({FIELD}) = \1 \+ ({FIELD}|[-\w.]+);', lambda m: f'{m.group(1)} += {m.group(2)};'),
    ('chain-const', rf'({FIELD}) = (-?\w+);\n(\s*)({FIELD}) = \2;', lambda m: f'{m.group(1)} = {m.group(4)} = {m.group(2)};'),
    ('assign-in-cond', rf'(\w+) = (\w+\([^;]*\));\n(\s*)if \(\1\)', lambda m: f'if (({m.group(1)} = {m.group(2)}) != 0)'),
    ('uchar-vs-char', r'\bunsigned char (\w+);', lambda m: f'char {m.group(1)};'),
    ('char-vs-uchar', r'(?<!unsigned )\bchar (\w+);', lambda m: f'unsigned char {m.group(1)};'),
    ('ushort-vs-short', r'\bunsigned short (\w+);', lambda m: f'short {m.group(1)};'),
    ('short-vs-ushort', r'(?<!unsigned )\bshort (\w+);', lambda m: f'unsigned short {m.group(1)};'),
    ('uint-vs-int', r'\bunsigned int (\w+);', lambda m: f'int {m.group(1)};'),
    ('int-vs-uint', r'(?<!unsigned )\bint (\w+);', lambda m: f'unsigned int {m.group(1)};'),
    ('swap-stmts', r'^(\s*)([^\n;{}]+;)\n\1([^\n;{}]+;)\n', lambda m: f'{m.group(1)}{m.group(3)}\n{m.group(1)}{m.group(2)}\n'),
]


def score(path):
    proof, _ = evaluate(path)
    equal = sum(p['equal_bytes'] for p in proof['sections'])
    return equal, proof['exact']


def variants(text):
    for name, pattern, repl in REWRITES:
        regex = re.compile(pattern, re.M)
        sites = list(regex.finditer(text))
        for i, m in enumerate(sites):
            new = text[:m.start()] + repl(m) + text[m.end():]
            if new != text:
                yield f'{name}@{i}', new


def bounded_search(path, unit, initial, *, budget=10, seconds=1200, rounds=6, failed=None,
                   evaluator=evaluate, root=ROOT):
    """Compile private copies. An exception or interruption never dirties source."""
    failed = set() if failed is None else set(failed)
    original = path.read_text();best_text=original
    best=sum(p['equal_bytes'] for p in initial['sections']);baseline_score=best;exact=initial['exact']
    compiled=errors=skipped=round_count=0;started=time.monotonic();seen=set()
    with tempfile.TemporaryDirectory(prefix='spelling-',dir=root/'build') as directory:
        trial=Path(directory)/path.name
        while not exact and compiled<budget and round_count<rounds and time.monotonic()-started<seconds:
            round_count+=1
            improved=False
            for name,text in variants(best_text):
                key=hashlib.sha256(text.encode()).hexdigest()
                if key in seen or key in failed:
                    skipped+=1;continue
                seen.add(key)
                if compiled>=budget or time.monotonic()-started>=seconds:break
                trial.write_text(text)
                compiled+=1
                try:
                    proof,_=evaluator(str(trial),descriptor=unit)
                except ValueError:
                    # Compiler/tool failures are not permanent negative evidence.
                    errors+=1;continue
                equal=sum(p['equal_bytes'] for p in proof['sections'])
                if not proof['exact'] and equal<=baseline_score:failed.add(key)
                if equal>best or proof['exact']:
                    best,exact,best_text=equal,proof['exact'],text;improved=True
                    print(f'  {name}: {best} equal bytes'+(' EXACT' if exact else ''),flush=True)
                    break
            if not improved:break
    if path.read_text()!=original:raise ValueError('Source changed during experiment; refusing to overwrite it')
    return dict(text=best_text,score=best,exact=exact,compiled=compiled,errors=errors,
                skipped=skipped,failed=sorted(failed),elapsed=time.monotonic()-started,
                original_sha256=hashlib.sha256(original.encode()).hexdigest())


def search_outcome(result, initial_score):
    if result['exact']:return 'matched'
    if result['score']>initial_score:return 'improved'
    if not result['compiled'] and not result.get('skipped',0):return 'inconclusive'
    if result['compiled'] and result['errors']==result['compiled']:return 'inconclusive'
    return 'stalled'


def main():
    parser=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('path')
    parser.add_argument('--rounds',type=int,default=6,help='maximum improving search rounds within the probe/time budgets')
    parser.add_argument('--budget',type=int,default=10,help='maximum compiled variants; default stops a speculative search early')
    parser.add_argument('--seconds',type=float,default=1200,help='wall-time search budget')
    parser.add_argument('--hypothesis',default='Bounded mechanical spelling search after native diagnosis')
    parser.add_argument('--new-evidence',help='concrete new fact permitting a previously stalled input to be reconsidered')
    args=parser.parse_args()
    if args.budget<=0 or args.seconds<=0 or args.rounds<=0:parser.error('budgets must be positive')
    path=ROOT/args.path
    from boundaries import BoundaryIndex
    from type_contracts import check_all
    known=next((u for u in load(ROOT/'config/units.json') if u.get('source')==args.path),None)
    original_hash=hashlib.sha256(path.read_bytes()).hexdigest()
    preliminary=known or {'id':'diff','source':args.path}
    before_context=search_context(preliminary)
    initial,unit=evaluate(args.path,descriptor=known)
    if search_context(preliminary)!=before_context:raise ValueError('Inputs changed during initial comparison; retry from a stable source')
    if initial['exact']:
        print('Already exact; register/verify the whole unit instead of searching.');return 0
    boundary=BoundaryIndex.current().unit(unit)
    if boundary['issues']:parser.error('Resolve native boundaries first: '+repr(boundary['issues'][:8]))
    check_all(args.path)
    state=experiment_state(unit,read_journal())
    if state['status']=='needs_new_evidence' and not args.new_evidence:
        parser.error('This input already stalled. Recover a new native fact or provide --new-evidence; repeated guesses are parked.')
    if initial.get('diagnosis',{}).get('category')=='layout_or_signature':args.budget=min(args.budget,12)
    context=search_context(unit)
    cache_dir=ROOT/'build/recovery';cache_dir.mkdir(parents=True,exist_ok=True)
    cache=cache_dir/(context+'.json')
    try:failed=set(load(cache)['failed'])
    except (OSError,ValueError,KeyError,TypeError):failed=set()
    lock=cache_dir/(hashlib.sha256(unit['id'].encode()).hexdigest()+'.lock')
    with lock.open('a') as handle:
        try:fcntl.flock(handle,fcntl.LOCK_EX|fcntl.LOCK_NB)
        except BlockingIOError:parser.error('Another search owns this unit; use a disjoint unit')
        if hashlib.sha256(path.read_bytes()).hexdigest()!=original_hash:raise ValueError('Source changed since initial comparison; refusing stale baseline')
        if search_context(preliminary)!=before_context:raise ValueError('Facts changed since initial comparison; retry')
        print('DIAGNOSIS '+repr(initial.get('diagnosis')),flush=True)
        result=bounded_search(path,unit,initial,budget=args.budget,seconds=args.seconds,rounds=args.rounds,failed=failed)
        if search_context(unit)!=context:raise ValueError('Compiler, facts, or extent changed during search; source left untouched')
        if hashlib.sha256(path.read_text().encode()).hexdigest()!=result['original_sha256']:raise ValueError('Source changed before publication; refusing to overwrite it')
        if result['text']!=path.read_text():
            with tempfile.NamedTemporaryFile(mode='w',dir=path.parent,delete=False,prefix=path.name+'.') as f:
                f.write(result['text']);staged=f.name
            os.replace(staged,path)
        cache.write_text(json.dumps({'context':context,'failed':result['failed']})+'\n')
        initial_score=sum(p['equal_bytes'] for p in initial['sections'])
        outcome=search_outcome(result,initial_score)
        record({'kind':'experiment','id':unit['id'],'source_sha256':source_key(unit),
                'context':context,'hypothesis':args.hypothesis,'evidence':args.new_evidence,
                'outcome':outcome,'minutes':result['elapsed']/60,'attempts':result['compiled'],
                'compile_errors':result['errors'],'duplicates_skipped':result['skipped'],
                'equal_bytes_before':initial_score,'equal_bytes_after':result['score'],
                'next_action':'Whole-unit registration/check' if result['exact'] else 'Review first native divergence; change hypothesis before another broad search'})
        print(f"end {result['score']} equal bytes; {result['compiled']} compiled, {result['skipped']} repeated variants skipped; {outcome}")
    return 0 if result['exact'] else 1


if __name__=='__main__':
    sys.exit(main())
