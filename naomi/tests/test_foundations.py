"""Behavioral checks for safe incremental builds and candidate admission."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
import contextlib
import importlib.util
import io

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from build_cache import ArtifactCache, unit_key, shared_inputs
from boundaries import BoundaryIndex
from diagnose import word_class
from core import ROOT


class CacheTests(unittest.TestCase):
    def test_headers_options_and_compiler_are_in_shared_key(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for relative in ('config/compiler.json', 'tools/build.py', 'tools/core.py', 'tools/build_cache.py',
                             'src/include/shared.h', 'toolchain/compiler.exe'):
                path = root / relative
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(relative)
            previous = shared_inputs(root)
            for relative in ('src/include/shared.h', 'config/compiler.json', 'toolchain/compiler.exe'):
                path = root / relative
                path.write_text(path.read_text() + 'changed')
                current = shared_inputs(root)
                self.assertNotEqual(previous, current)
                previous = current
    def test_content_and_placement_invalidate_and_corruption_recompiles(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'toolchain/hitachi-shc-5.1r08').mkdir(parents=True)
            (root / 'unit.c').write_text('void f(void) {}')
            unit = {'id': 'u', 'source': 'unit.c', 'sections': [{'address': 4096}]}
            calls = []
            def compiler(unit, work, flags):
                calls.append(unit)
                (work / 'u.elf').write_bytes(b'compiled')
                (work / 'u.map').write_text('link map')
                return b'compiled', 'link map'
            cache = ArtifactCache(root, 'compiler-and-headers')
            self.assertFalse(cache.compile(unit, root / 'build/a', compiler)[2])
            self.assertTrue(cache.compile(unit, root / 'build/b', compiler)[2])
            self.assertEqual(len(calls), 1)
            key = unit_key(root, unit, cache.shared)
            (cache.directory / key / 'u.elf').write_bytes(b'corrupted')
            self.assertFalse(cache.compile(unit, root / 'build/c', compiler)[2])
            (cache.directory / key / 'manifest.json').write_text(json.dumps({'key': key, 'files': []}))
            self.assertFalse(cache.compile(unit, root / 'build/c2', compiler)[2])
            (root / 'unit.c').write_text('void f(void) { int x; }')
            self.assertNotEqual(key, unit_key(root, unit, cache.shared))
            changed = {**unit, 'sections': [{'address': 8192}]}
            self.assertNotEqual(unit_key(root, unit, cache.shared), unit_key(root, changed, cache.shared))
            self.assertNotEqual(unit_key(root, unit, cache.shared), unit_key(root, unit, 'changed-header'))
            cache.clean = True
            self.assertFalse(cache.compile(unit, root / 'build/d', compiler)[2])
            self.assertEqual(len(calls), 4)


class BoundaryTests(unittest.TestCase):
    def audit(self, blob, sections, entries=(), ranges=None):
        return BoundaryIndex(blob, 0x1000, ranges or [(0x1000, len(blob), 'code')]).audit(sections, entries)

    def test_backward_incoming_branch_is_not_missed(self):
        blob = bytearray(16)
        blob[12:14] = bytes.fromhex('f8af')  # BRA from 100c to 1000.
        result = self.audit(blob, [{'address': 0x1000, 'size': 4, 'kind': 'code'}], [0x1000])
        self.assertTrue(any(i['kind'] == 'incoming_branch' for i in result['issues']))

    def test_literal_width_must_be_contained(self):
        blob = bytes.fromhex('00d1090000000000')  # MOV.L at 1000 reads all four bytes at 1004.
        result = self.audit(blob, [{'address': 0x1000, 'size': 6, 'kind': 'code'}], [0x1000])
        self.assertTrue(any(i['kind'] == 'outgoing_literal' for i in result['issues']))

    def test_continuation_and_delay_slot_are_not_new_entries(self):
        blob = bytes.fromhex('008900000b000900')  # BT ->1004; RTS with delay at1006.
        result = self.audit(blob, [{'address': 0x1000, 'size': 8, 'kind': 'code'}], [0x1000, 0x1004, 0x1006])
        kinds = {i['kind'] for i in result['issues']}
        self.assertIn('conditional_entry', kinds)
        self.assertIn('entry_in_delay_slot', kinds)

    def test_frameless_conditional_tail_to_saved_register_entry(self):
        # MOV #1,R0; BT ->1008; MOV #0,R0; NOP; callee prologue.
        blob = bytes.fromhex('01e0018900e00900e62f')
        result = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}], [0x1000, 0x1008])
        self.assertEqual(result['issues'], [])

    def test_conditional_tail_rejects_modified_abi_state_and_unknown_code(self):
        for prefix in ('e62f', '227f', '22e8', '224f', '0b43', '0000'):
            with self.subTest(prefix=prefix):
                blob = bytes.fromhex(prefix + '018900e00900e62f')
                result = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}], [0x1000, 0x1008])
                self.assertIn('conditional_entry', {i['kind'] for i in result['issues']})

    def test_conditional_tail_checks_delay_slot_for_stack_changes(self):
        blob = bytes.fromhex('01e0018dfc7f0900e62f')
        result = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}], [0x1000, 0x1008])
        self.assertIn('conditional_entry', {i['kind'] for i in result['issues']})

    def floating_tail_fixture(self):
        # Retail 0c1c4236's position update and countdown, then a distinct
        # callee with two constant loads before its own saved-register frame.
        words = [0xe164, 0x314c, 0xe03c, 0xf318, 0xf246, 0xf230, 0xf427,
                 0x854e, 0x70ff, 0x814e, 0x600f, 0x4015, 0x8b01,
                 0x000b, 0x0009, 0x9007, 0xe300, 0x2fe6, 0x6e43,
                 0x4f22, 0x4f26, 0x6ef6, 0x000b, 0x0009, 0x012c]
        return bytearray(b''.join(w.to_bytes(2, 'little') for w in words))

    def test_floating_tail_and_scratch_constants_before_saved_frame(self):
        blob = self.floating_tail_fixture()
        result = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}],
                            [0x1000, 0x101e], [(0x1000, 48, 'code'), (0x1030, 2, 'data')])
        self.assertEqual(result['issues'], [])

    def test_floating_tail_rejects_saved_register_stack_and_fpscr_changes(self):
        for index, word in [(1, 0x3e4c), (1, 0x31fc), (4, 0xfc46), (5, 0xfc30), (6, 0xff27),
                            (4, 0xf2f6), (5, 0x416a), (15, 0x9e07),
                            (16, 0xee00), (16, 0xe400), (17, 0xe201)]:
            with self.subTest(index=index, word=hex(word)):
                blob = self.floating_tail_fixture()
                blob[index * 2:index * 2 + 2] = word.to_bytes(2, 'little')
                result = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}],
                                    [0x1000, 0x101e], [(0x1000, 48, 'code'), (0x1030, 2, 'data')])
                self.assertIn('conditional_entry', {i['kind'] for i in result['issues']})

    def test_prefixed_callee_still_requires_its_literal_bytes(self):
        blob = self.floating_tail_fixture()
        result = self.audit(blob, [{'address': 0x1000, 'size': 48, 'kind': 'code'}],
                            [0x1000, 0x101e], [(0x1000, 48, 'code'), (0x1030, 2, 'data')])
        self.assertIn('outgoing_literal', {i['kind'] for i in result['issues']})

    def test_conditional_entry_admitted_only_for_exact_units(self):
        from diff_unit import admission_issues
        blob = bytes.fromhex('e62f018900e00900e62f')  # Saved frame, BT ->1008, next entry.
        issues = self.audit(blob, [{'address': 0x1000, 'size': len(blob), 'kind': 'code'}],
                            [0x1000, 0x1008])['issues']
        self.assertIn('conditional_entry', {i['kind'] for i in issues})
        self.assertEqual(admission_issues(issues, True), [])
        self.assertEqual(admission_issues(issues, False), issues)
        gap = [{'kind': 'unreviewed_gap', 'address': '0x1000', 'end': '0x1004'}]
        self.assertEqual(admission_issues(gap, True), gap)

    def test_legitimate_direct_call_to_entry_is_allowed(self):
        blob = bytes.fromhex('00b009000b000900')
        result = self.audit(blob, [{'address': 0x1004, 'size': 4, 'kind': 'code'}], [0x1004])
        self.assertEqual(result['issues'], [])

    def test_gap_and_split_delay_are_reported(self):
        blob = bytes.fromhex('0b00090000000000')
        result = self.audit(blob, [{'address': 0x1000, 'size': 2, 'kind': 'code'}], [0x1000])
        self.assertIn('split_delay_slot', {i['kind'] for i in result['issues']})
        result = self.audit(blob, [{'address': 0x1000, 'size': 8, 'kind': 'code'}], [], [(0x1000, 4, 'code')])
        self.assertIn('unreviewed_gap', {i['kind'] for i in result['issues']})

    def test_loop_back_to_own_entry_is_not_a_second_function(self):
        blob = bytes.fromhex('0900fd8b0b000900')  # BF at1002 back to1000.
        result = self.audit(blob, [{'address': 0x1000, 'size': 8, 'kind': 'code'}], [0x1000])
        self.assertEqual(result['issues'], [])


class DiagnosisTests(unittest.TestCase):
    def test_register_difference_is_distinct_from_constant_difference(self):
        self.assertEqual(word_class(0xe203, 0xe303, 0x1000), 'register_choice')
        self.assertEqual(word_class(0xe203, 0xe204, 0x1000), 'operand_or_control_flow')
        self.assertEqual(word_class(0xd301, 0xd302, 0x1000), 'literal_displacement_or_field_offset')

    def test_completion_inventory_separates_provenance_and_review_signals(self):
        from feasibility import inventory
        blob = bytes.fromhex('0b0009000b000900fdf32b0009000900')
        units = [
            {'credited': True, 'sections': [{'kind': 'code', 'address': 0x1000, 'size': 4}]},
            {'credited': True, 'library': 'sdk.lib', 'sections': [{'kind': 'code', 'address': 0x1004, 'size': 4}]},
        ]
        result = inventory(blob, 0x1000, [(0x1000, 16, 'code')], units)
        self.assertEqual(result['reviewed_instruction_bytes'], {
            'exact_c': 4, 'sdk_object': 4, 'intrinsic_or_abi_review': 2,
            'cpu_state_review': 2, 'c_feasibility_unassessed': 4})
        self.assertFalse(result['c_only_completion_established'])


class TargetCompilerTests(unittest.TestCase):
    def test_layout_drift_and_wrong_return_type_fail(self):
        from type_contracts import check
        with tempfile.TemporaryDirectory(prefix='contract-test-', dir=ROOT / 'build') as directory:
            source = Path(directory) / 'types.c'
            source.write_text('struct Evidence { char pad[4]; int field; };\nextern unsigned char answer(void);\n')
            contract = {'source': str(source.relative_to(ROOT)), 'members': [
                {'type': 'struct Evidence', 'member': 'field', 'offset': 4, 'evidence': 'test fixture target layout'}],
                'prototypes': [{'declaration': 'extern unsigned char answer(void);', 'evidence': 'test fixture declaration'}]}
            self.assertEqual(check(contract)['status'], 'PASS')
            source.write_text(source.read_text().replace('pad[4]', 'pad[8]'))
            with self.assertRaisesRegex(ValueError, 'target type contract failed'):
                check(contract)
            source.write_text('struct Evidence { char pad[4]; int field; };\nextern int answer(void);\n')
            with self.assertRaisesRegex(ValueError, 'target type contract failed'):
                check(contract)

    def test_retail_compiler_patterns_and_negative_controls(self):
        import compiler_patterns as module
        with contextlib.redirect_stdout(io.StringIO()) as output:
            module.main()
        proof = json.loads(output.getvalue())
        self.assertEqual(proof['float_context']['matching_bytes'], 20)
        self.assertEqual(proof['credit'], 0)


if __name__ == '__main__':
    unittest.main()
