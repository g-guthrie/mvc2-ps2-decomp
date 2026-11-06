"""Read-only, case-scoped simulator evidence. Never grants exact-code credit."""
import hashlib
import importlib.util
import json
import subprocess
import zipfile
from pathlib import Path
from core import ROOT, load, number

REVISION = '291be8e458ddc2ecad9c3fd27b4e48a8b17e73aa'

def digest(value):
    return hashlib.sha256(json.dumps(value, sort_keys=True, separators=(',', ':')).encode()).hexdigest()

def fingerprint(unit, cases, root=ROOT):
    from diff_unit import hexed
    descriptor = hexed({'exports': {}, 'imports': {}, **unit})
    root = Path(root)
    paths = [root / unit['source'], root / 'config/compiler.json', root / 'config/target.json',
             root / 'tools/build.py', root / 'tools/core.py', root / 'tools/diff_unit.py', root / 'tools/behavioral_evidence.py',
             root / 'tools/simulator_pilot/pilot.py', root / 'tools/simulator_pilot/run.php']
    paths += sorted((root / 'src/include').glob('*.h'))
    paths += sorted(p for p in (root / 'toolchain/hitachi-shc-5.1r08').iterdir() if p.is_file())
    paths += [root / 'toolchain/hitachi-shc-5.1r08.json', root / 'toolchain/wibo.json']
    paths += [root / item['path'] for item in load(root / 'toolchain/wibo.json')['assets'].values()]
    files = {str(p.relative_to(root)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}
    target = load(root / 'config/target.json')
    with zipfile.ZipFile(root / target['archive']) as archive:
        image = archive.read(target['program_rom'])
    return {'files': files, 'unit': digest(descriptor), 'cases': digest(cases),
            'native_program': hashlib.sha256(image).hexdigest()}

def current_cases(unit_id, names, root=ROOT):
    spec = importlib.util.spec_from_file_location('behavioral_pilot', Path(root) / 'tools/simulator_pilot/pilot.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    if unit_id not in module.UNITS:
        raise ValueError('unit is not supported by the pilot')
    cases = module.cases_for(unit_id)
    chosen = [case for case in cases if case['name'] in names]
    if len(chosen) != len(names) or not chosen:
        raise ValueError('selected cases changed or are empty')
    return chosen

def classify(record):
    """Malformed, unsupported and ineffective mutation runs provide no positive evidence."""
    names = record['case_names']
    variants = record['variants']
    if not names or len(set(names)) != len(names):
        return 'unknown', 'empty or duplicate cases'
    for rows in variants.values():
        if [row['case'] for row in rows] != names:
            return 'unknown', 'incomplete case results'
    if set(variants) != {'retail', 'candidate', 'mutant'}:
        return 'unknown', 'missing execution variant'
    failures = [r for rows in variants.values() for r in rows if not r['passed']]
    if any('ExpectationException' not in row.get('error', '') for row in failures):
        return 'unknown', 'unsupported execution or runtime failure'
    if not all(row['passed'] for row in variants['retail']):
        return 'unknown', 'reference expectations failed'
    mutation = any(not row['passed'] for row in variants['mutant'])
    if not mutation:
        return 'unknown', 'mutation control did not detect its deliberate bug'
    if not all(row['passed'] for row in variants['candidate']):
        return 'current_failure', 'candidate disagrees with tested expectations'
    return 'current_pass', 'paired cases pass and mutation control detects the deliberate bug'

def status(unit, report_path=None, root=ROOT, report=None):
    root = Path(root)
    unknown = {'status': 'unknown', 'reason': 'no current behavioral evidence',
               'action': 'Use native types and control flow; add cases only for a concrete unresolved behavior.'}
    try:
        report = report if report is not None else load(report_path or root / 'build/simulator-pilot/results.json')
        record = report['units'][unit['id']]
        cases = current_cases(unit['id'], record['case_names'], root)
        if record['inputs'] != fingerprint(unit, cases, root):
            return {**unknown, 'reason': 'stale source, headers, descriptor, cases, compiler, adapter or native image'}
        simulator = record['simulator_path']
        revision = subprocess.check_output(['git', '-C', simulator, 'rev-parse', 'HEAD'], text=True).strip()
        dirty = subprocess.check_output(['git', '-C', simulator, 'status', '--porcelain'], text=True).strip()
        if revision != REVISION or dirty or record['simulator_revision'] != REVISION:
            return {**unknown, 'reason': 'simulator identity is stale or unavailable'}
        state, reason = classify(record)
        return {**unknown, 'status': state, 'reason': reason, 'case_names': record['case_names'],
                'tested_functions': sorted({case['entry'] for case in cases}),
                'mutation_control': state != 'unknown',
                'action': ('Investigate code generation for the tested paths; untested paths remain unknown.'
                           if state == 'current_pass' else unknown['action'])}
    except (OSError, ValueError, KeyError, TypeError, subprocess.SubprocessError, zipfile.BadZipFile):
        return unknown
