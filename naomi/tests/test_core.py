"""Regression checks for false matching credit and misleading image coverage."""
import copy
from pathlib import Path
import struct
import sys
import unittest
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT, compare, elf_segments, load, validate_units
from report import layout, metrics, work_queue


def executable(address=0x1000, data=b'\x0b\0\x09\0', kind=2):
    header = struct.pack('<16sHHIIIIIHHHHHH', b'\x7fELF\x01\x01\x01'+b'\0'*9,
                         kind, 42, 1, address, 52, 0, 0, 52, 32, 1, 0, 0, 0)
    return header + struct.pack('<8I', 1, 84, address, address, len(data), len(data), 5, 4) + data


def link(address=0x1000, size=4):
    return f"ATTRIBUTE : CODE\nP H'{address:08X} - H'{address+size-1:08X} H'{size:X}\n_func H'{address:08X} ENT\n"


class ProofTests(unittest.TestCase):
    def test_every_source_unit_is_registered(self):
        registered = {unit['source'] for unit in load(ROOT / 'config/units.json') if 'source' in unit}
        sources = {str(path.relative_to(ROOT)) for folder in ('verified', 'candidates')
                   for path in (ROOT / 'src' / folder).glob('*.c')}
        self.assertEqual(sources, registered)

    def setUp(self):
        self.unit = dict(id='func', source='src/func.c', mode='verified',
                         exports={'_func':0x1000}, sections=[dict(section='P',kind='code',address=0x1000,size=4)])
        self.original = b'\x0b\0\x09\0'

    def check_match(self, elf=None, map_text=None):
        return compare(self.unit, elf or executable(), map_text or link(), self.original, 0x1000)[0]

    def test_exact_linked_code(self):
        self.assertTrue(self.check_match()['exact'])

    def test_identical_bytes_at_wrong_address_fail(self):
        self.assertFalse(self.check_match(executable(0x2000), link(0x2000))['exact'])

    def test_matching_prefix_with_extra_bytes_fails(self):
        self.assertFalse(self.check_match(executable(data=self.original+b'\0\0'),link(size=6))['exact'])

    def test_changed_byte_fails(self):
        self.assertFalse(self.check_match(executable(data=b'\x0b\0\x08\0'))['exact'])

    def test_relocatable_object_is_not_proof(self):
        with self.assertRaises(ValueError):
            elf_segments(executable(kind=1))

    def test_map_and_elf_cannot_hide_extra_bytes(self):
        self.assertFalse(self.check_match(executable(data=self.original+b'\0\0'))['exact'])

    def test_missing_export_fails(self):
        self.assertFalse(self.check_match(map_text=link().replace('_func','_other'))['exact'])

    def test_overlapping_references_fail(self):
        other = copy.deepcopy(self.unit)
        other['id'] = 'other'
        with self.assertRaisesRegex(ValueError,'Overlapping'):
            validate_units([self.unit,other], {'main':{'address':0x1000,'size':100}})

    def test_candidate_without_matching_functions_has_no_progress_credit(self):
        proof = {'main_size':100, 'units':[dict(credited=False, function_bytes=0, sections=[dict(kind='code',size=4)])]}
        self.assertEqual(metrics(proof)['code']['matched_bytes'],0)

    def test_verified_literal_pool_counts_as_data(self):
        unit = dict(credited=True, sections=[dict(kind='code', size=10,
                    interior=[dict(kind='data', size=4)])])
        result = metrics({'main_size': 100, 'units': [unit]})
        self.assertEqual(result['code']['matched_bytes'], 6)
        self.assertEqual(result['data']['matched_bytes'], 4)

    def test_progress_provenance_sums_to_credited_bytes(self):
        units = [dict(credited=True, sections=[dict(kind='code', size=4)]),
                 dict(credited=True, library='sdk.lib', sections=[dict(kind='code', size=6)]),
                 dict(credited=False, function_bytes=2, pool_bytes=1,
                      sections=[dict(kind='code', size=4)])]
        result = metrics({'main_size': 100, 'units': units, 'mapping':
                          {'reviewed_code_bytes': 20, 'reviewed_data_bytes': 5, 'unknown_bytes': 75}})
        self.assertEqual(result['provenance'], {
            'c_source': {'code': 4, 'data': 0},
            'sdk_modules': {'code': 6, 'data': 0},
            'candidate_fragments': {'code': 2, 'data': 1}})
        self.assertEqual(sum(sum(row.values()) for row in result['provenance'].values()),
                         result['decomp']['matched_bytes'])

    def test_work_queue_separates_near_match_from_wrong_extent(self):
        def candidate(name, equal, linked):
            return dict(id=name, source=f'src/candidates/{name}.c', credited=False,
                        sections=[dict(address=0x1000, size=100, linked_address=0x1000,
                                       linked_size=linked, kind='code', equal_bytes=equal)],
                        functions=[], function_bytes=0, pool_bytes=0, problems=[])
        queue = work_queue(dict(input_sha256='test', units=[candidate('extent', 100, 120),
                                                         candidate('near', 98, 100)]))
        self.assertEqual([(row['id'], row['kind']) for row in queue['candidates']],
                         [('near', 'near_match'), ('extent', 'review_extent')])

    def test_unknown_bytes_stay_in_lower_bound(self):
        proof = {'main_size':100, 'units':[dict(credited=True, sections=[dict(kind='code',size=4)])]}
        self.assertEqual(metrics(proof)['code']['lower_bound_percent'],4)
        self.assertEqual(metrics(proof)['data']['possible_total_bytes'],96)

    def test_treemap_area_and_bounds(self):
        items = [dict(size=s) for s in [4,34,72,1000,2800]]
        boxes = layout(items, 800,400)
        for item,x,y,w,h in boxes:
            self.assertGreater(w,0)
            self.assertGreater(h,0)
            self.assertGreaterEqual(x,0)
            self.assertGreaterEqual(y,0)
            self.assertLessEqual(x+w,800.000001)
            self.assertLessEqual(y+h,400.000001)
            self.assertAlmostEqual(w*h/(800*400),item['size']/3910)
        self.assertAlmostEqual(sum(w*h for _,x,y,w,h in boxes),800*400)


class InspectionTests(unittest.TestCase):
    def test_literal_address_includes_pc_alignment(self):
        from inspect_rom import literal
        self.assertEqual(literal(0x901d,0x0c047b0c),(0x0c047b4a,2))
        self.assertEqual(literal(0xd12e,0x0c021002),(0x0c0210bc,4))

    def test_decoder_distinguishes_return_from_literal(self):
        from vendor.sh4dis.sh4 import disasm
        self.assertEqual(disasm(0x000b,0),'rts')
        self.assertEqual(disasm(0x0029,0),'movt r0')

    def test_mapping_preserves_unknown_and_rejects_overlap(self):
        from mapping import review
        from core import sha
        data=b'\x0b\0\x09\0'+bytes(6)
        part=dict(address=0x1000,size=4,kind='code',sha256=sha(data[:4]),evidence='RTS/NOP')
        result=review(data,0x1000,[part])
        self.assertEqual(result['unknown_bytes'],6)
        self.assertEqual(result['status'],'incomplete')
        with self.assertRaises(ValueError):
            review(data,0x1000,[part,part])

    def test_unsupported_host_has_actionable_fallback(self):
        from unittest.mock import patch
        from core import runner
        with patch('core.platform.system',return_value='Linux'), patch('core.platform.machine',return_value='aarch64'):
            with self.assertRaisesRegex(ValueError,'Run workflow'):
                runner()


class CurrentMappingTests(unittest.TestCase):
    def test_new_verified_source_is_added_to_mapping(self):
        from mapping import review
        unit=dict(id='new',credited=True,sections=[dict(section='P',kind='code',address=0x1000,size=4)])
        result=review(bytes(8),0x1000,entries=[],verified=[unit])
        self.assertEqual(result['reviewed_code_bytes'],4)
        self.assertEqual(result['unknown_bytes'],4)


class RepositoryStateTests(unittest.TestCase):
    def test_readme_has_generated_progress_without_task_queue(self):
        readme = (ROOT / 'README.md').read_text()
        self.assertNotIn('build/NEXT.md', readme)
        self.assertNotIn('Next candidate', readme)
        self.assertIn('| Matched reviewed code |', readme)
        self.assertIn('| Verified C executable code (lower bound) |', readme)
        self.assertIn('| Data |', readme)
        self.assertIn('| Map |', readme)

    def test_ci_only_writes_generated_readme_progress(self):
        workflow = (ROOT.parent / '.github/workflows/naomi-build.yml').read_text()
        self.assertIn('contents: write', workflow)
        self.assertIn('git add README.md', workflow)
        self.assertIn('git push origin HEAD:main', workflow)
        self.assertNotIn('git add README.md assets/', workflow)
        self.assertNotIn('build/NEXT.md', workflow)

    def test_progress_bar_is_deterministic(self):
        from report import progress_bar
        self.assertEqual(progress_bar(0, 100, 4), '░░░░')
        self.assertEqual(progress_bar(50, 100, 4), '██░░')
        self.assertEqual(progress_bar(100, 100, 4), '████')


if __name__=='__main__':
    unittest.main()
