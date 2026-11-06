import copy
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
import zipfile
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from behavioral_evidence import REVISION, fingerprint, status

class BehavioralEvidenceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.unit = {'id': 'test', 'source': 'src/test.c', 'sections': [{'address': 123, 'size': 2}]}
        self.cases = [{'name': 'boundary', 'entry': '_func_test', 'arguments': [1]}]
        files = ['src/test.c', 'src/include/types.h', 'tools/build.py', 'tools/core.py',
                 'tools/behavioral_evidence.py', 'tools/diff_unit.py', 'tools/simulator_pilot/pilot.py',
                 'tools/simulator_pilot/run.php', 'toolchain/hitachi-shc-5.1r08/shc.exe',
                 'toolchain/hitachi-shc-5.1r08.json', 'toolchain/runner', 'config/compiler.json']
        for name in files:
            p = self.root / name
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text('original')
        (self.root / 'toolchain/wibo.json').write_text(json.dumps({'assets': {'host': {'path': 'toolchain/runner'}}}))
        (self.root / 'config/target.json').write_text(json.dumps({'archive': 'native.zip', 'program_rom': 'main.bin'}))
        with zipfile.ZipFile(self.root / 'native.zip', 'w') as archive:
            archive.writestr('main.bin', b'native')
        self.record = {'inputs': fingerprint(self.unit, self.cases, self.root), 'case_names': ['boundary'],
                       'simulator_path': '/simulator', 'simulator_revision': REVISION,
                       'variants': {'retail': [{'case': 'boundary', 'passed': True}],
                                    'candidate': [{'case': 'boundary', 'passed': True}],
                                    'mutant': [{'case': 'boundary', 'passed': False, 'error': 'ExpectationException: wrong return'}]}}
        self.report = self.root / 'report.json'
    def read_status(self):
        self.report.write_text(json.dumps({'units': {'test': self.record}}))
        with patch('behavioral_evidence.current_cases', return_value=self.cases), patch('behavioral_evidence.subprocess.check_output', side_effect=[REVISION, '']):
            return status(self.unit, self.report, self.root)
    def test_current_scope(self):
        result = self.read_status()
        self.assertEqual(result['status'], 'current_pass')
        self.assertEqual(result['tested_functions'], ['_func_test'])
        self.assertIn('untested paths remain unknown', result['action'])
    def test_stale_inputs(self):
        for name in ['src/test.c', 'src/include/types.h', 'config/compiler.json', 'toolchain/hitachi-shc-5.1r08/shc.exe', 'tools/simulator_pilot/run.php']:
            with self.subTest(name=name):
                path = self.root / name
                original = path.read_bytes()
                path.write_bytes(original + b'changed')
                self.assertEqual(self.read_status()['status'], 'unknown')
                path.write_bytes(original)
        self.unit['sections'][0]['size'] = 4
        self.assertEqual(self.read_status()['status'], 'unknown')
    def test_equivalent_registered_and_evaluated_descriptors(self):
        registered = copy.deepcopy(self.unit)
        registered['sections'][0]['address'] = '0x0000007b'
        registered['sections'][0]['interior'] = [{'address': '0x0000007c', 'size': 1}]
        registered['exports'] = {'_func_test': '0x0000007b'}
        evaluated = copy.deepcopy(registered)
        evaluated['sections'][0]['address'] = 123
        evaluated['sections'][0]['interior'][0]['address'] = 124
        evaluated['exports']['_func_test'] = 123
        evaluated['imports'] = {}
        evaluated['options'] = 'game'
        expected = fingerprint(registered, self.cases, self.root)
        self.assertEqual(expected, fingerprint(evaluated, self.cases, self.root))
        evaluated['sections'][0]['size'] = 4
        self.assertNotEqual(expected, fingerprint(evaluated, self.cases, self.root))

    def test_stale_cases(self):
        self.cases[0]['arguments'] = [2]
        self.assertEqual(self.read_status()['status'], 'unknown')
    def test_native_changed(self):
        with zipfile.ZipFile(self.root / 'native.zip', 'w') as archive:
            archive.writestr('main.bin', b'changed')
        self.assertEqual(self.read_status()['status'], 'unknown')
    def test_failed_mutation_control(self):
        self.record['variants']['mutant'][0] = {'case': 'boundary', 'passed': True}
        self.assertEqual(self.read_status()['status'], 'unknown')
    def test_unsupported_is_not_mutation_detection(self):
        self.record['variants']['mutant'][0]['error'] = 'RuntimeException: Unsupported opcode'
        self.assertEqual(self.read_status()['status'], 'unknown')
    def test_candidate_failure(self):
        self.record['variants']['candidate'][0] = {'case': 'boundary', 'passed': False, 'error': 'ExpectationException: wrong return'}
        self.assertEqual(self.read_status()['status'], 'current_failure')
    def test_missing_cases_unknown(self):
        self.record['variants']['candidate'] = []
        self.assertEqual(self.read_status()['status'], 'unknown')

if __name__ == '__main__':
    unittest.main()
