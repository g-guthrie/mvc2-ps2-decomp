import copy
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT
from flow_map import Image
from shared_facts import callback_review
from type_contracts import check


class CallbackReviewTests(unittest.TestCase):
    def setUp(self):
        self.blob = bytearray(0x100)
        # MOV.L literal->R3; indexed MOV.L ->R0; JMP @R0; delay NOP.
        struct.pack_into('<4H', self.blob, 0, 0xd307, 0x003e, 0x402b, 0x0009)
        struct.pack_into('<I', self.blob, 0x20, 0x1040)
        struct.pack_into('<2I', self.blob, 0x40, 0x1080, 0x1084)
        struct.pack_into('<4H', self.blob, 0x80, 0xb, 9, 0xb, 9)
        self.ranges = [{'kind': 'code', 'address': 0x1000, 'size': 8}]
        self.units = [{'id': 'candidate', 'mode': 'candidate', 'exports': {'first': 0x1080},
                       'sections': [{'kind': 'code', 'address': 0x1080, 'size': 8}]}]

    def review(self):
        return callback_review(Image(bytes(self.blob), 0x1000), self.ranges, self.units)

    def test_real_indexed_dispatch_yields_inspectable_hint_only(self):
        rows = self.review()
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]['address'], '0x00001084')
        self.assertEqual(rows[0]['witnesses'], ['0x00001044'])
        self.assertTrue(rows[0]['needs_review'])
        self.assertIn('rts', rows[0]['native_disassembly'])
        self.assertEqual(rows[0]['confidence'], 'table-derived hint')

    def test_bad_cell_export_and_pool_are_not_new_entries(self):
        original = copy.deepcopy(self.units)
        self.units[0]['exports']['second'] = 0x1084
        self.assertEqual(self.review(), [])
        self.units = original
        self.units[0]['sections'][0]['interior'] = [{'address': 0x1084, 'size': 4}]
        self.assertEqual(self.review(), [])
        self.units[0]['sections'][0].pop('interior')
        struct.pack_into('<I', self.blob, 0x44, 0x1085)
        self.assertEqual(self.review(), [])


class TypeSizeTests(unittest.TestCase):
    def test_target_member_width_and_stride_drift_fail(self):
        with tempfile.TemporaryDirectory(prefix='facts-test-', dir=ROOT / 'build') as directory:
            source = Path(directory) / 'types.c'
            source.write_text('struct Record { short field; char tail[6]; };\n')
            contract = {'source': str(source.relative_to(ROOT)), 'members': [
                {'type': 'struct Record', 'member': 'field', 'offset': 0, 'size': 2,
                 'evidence': 'synthetic halfword access'}], 'sizes': [
                {'type': 'struct Record', 'size': 8, 'evidence': 'synthetic indexed stride'}]}
            self.assertEqual(check(contract)['status'], 'PASS')
            source.write_text('struct Record { int field; char tail[4]; };\n')
            with self.assertRaisesRegex(ValueError, r'sizeof\(struct Record.field\)'):
                check(contract)
            source.write_text('struct Record { short field; char tail[10]; };\n')
            with self.assertRaisesRegex(ValueError, r'sizeof\(struct Record\)'):
                check(contract)


if __name__ == '__main__':
    unittest.main()
