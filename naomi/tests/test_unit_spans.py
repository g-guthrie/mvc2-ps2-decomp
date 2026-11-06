"""A proposed unit must contain the literal pools its code reads."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from unit_spans import owned_code_sections, span_evidence, spans


class UnitSpanTests(unittest.TestCase):
    def test_literal_load_crosses_earlier_pool_boundary(self):
        base = 0x1000
        image = bytearray(0x30)
        image[:4] = bytes.fromhex('0ad10900')  # MOV.L at 0x1000 reads 0x102c.
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data'),
                  (base + 8, 0x24, 'code'), (base + 0x2c, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, []), [(base, 0x30)])

    def test_long_branch_crosses_pool_boundary(self):
        base = 0x1000
        image = bytearray(0x908)
        image[:4] = bytes.fromhex('7ea40900')  # BRA from 0x1000 to 0x1900; NOP delay.
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data'),
                  (base + 8, 0x8fc, 'code'), (base + 0x904, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, []), [(base, 0x908)])

    def test_unreviewed_gap_does_not_hide_later_unit(self):
        base = 0x1000
        image = bytearray(0x20)
        ranges = [(base, 4, 'code'), (base + 8, 4, 'data'),
                  (base + 12, 4, 'code'), (base + 16, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, []), [(base + 12, 8)])

    def test_earlier_code_reading_later_pool_invalidates_start_after_gap(self):
        base = 0x1000
        image = bytearray(0x30)
        image[:2] = bytes.fromhex('0ad1')  # MOV.L at 0x1000 reads 0x102c.
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data'),
                  (base + 12, 0x20, 'code'), (base + 0x2c, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, []), [])

    def test_branch_into_later_code_invalidates_start_after_gap(self):
        base = 0x1000
        image = bytearray(0x14)
        image[:2] = bytes.fromhex('04a0')  # BRA from 0x1000 to 0x100c.
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data'),
                  (base + 12, 4, 'code'), (base + 16, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, []), [])
        image[:2] = bytes.fromhex('04b0')  # BSR may enter a new function.
        self.assertEqual(spans(image, base, ranges, []), [(base + 12, 8)])
        image[:2] = bytes.fromhex('05b0')  # A call into its interior cannot.
        self.assertEqual(spans(image, base, ranges, []), [])

    def test_owned_pool_excludes_proposal(self):
        base = 0x1000
        image = bytearray(8)
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data')]
        self.assertEqual(spans(image, base, ranges, [(base + 4, base + 8)]), [])

    def test_previously_registered_data_pool_can_be_released(self):
        base = 0x1000
        image = bytearray(8)
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data')]
        units = [{'sections': [{'kind': 'data', 'address': base + 4, 'size': 4}]}]
        self.assertEqual(spans(image, base, ranges, owned_code_sections(units)), [(base, 8)])

    def test_evidence_identifies_literal_pool_owner_and_crossing(self):
        base = 0x1000
        image = bytearray(0x30)
        image[:4] = bytes.fromhex('0ad17ea4')  # MOV.L to 0x102c; BRA to 0x1100.
        ranges = [(base, 4, 'code'), (base + 4, 4, 'data'),
                  (base + 8, 0x24, 'code'), (base + 0x2c, 4, 'data')]
        units = [{'id': 'old_pool', 'sections': [
            {'kind': 'data', 'address': base + 4, 'size': 4}]}]
        evidence = span_evidence(image, base, ranges, units, base, 0x30)
        self.assertEqual(evidence['pools'][0]['owners'], ['old_pool'])
        self.assertTrue(any(d['kind'] == 'literal' and d['target'] == '0x0000102c'
                            for d in evidence['dependencies']))
        self.assertTrue(any(d['kind'] == 'branch' and d['external']
                            for d in evidence['dependencies']))


if __name__ == '__main__':
    unittest.main()
