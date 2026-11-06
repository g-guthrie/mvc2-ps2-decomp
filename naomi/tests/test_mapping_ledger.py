"""Every reviewed mapping range must hash to the verified ROM slice."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT, load, number, sha, verify_rom
from mapping import review


class MappingLedgerTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        target = load(ROOT / 'config/target.json')
        main = target['main']
        cls.base = number(main['address'])
        cls.size = number(main['size'])
        rom = verify_rom(target)
        cls.img = rom[number(main['rom_offset']):number(main['rom_offset']) + cls.size]
        cls.ranges = load(ROOT / 'config/mapping.json')['ranges']

    def test_ranges_are_sorted_non_overlapping_hashed_and_evidenced(self):
        cursor = self.base
        for part in self.ranges:
            addr, size = number(part['address']), part['size']
            self.assertGreater(size, 0)
            self.assertIn(part['kind'], {'code', 'data'})
            self.assertTrue(part.get('evidence'))
            self.assertGreaterEqual(addr, cursor)
            self.assertLessEqual(addr + size, self.base + self.size)
            sl = self.img[addr - self.base:addr - self.base + size]
            self.assertEqual(part['sha256'], sha(sl), f'hash mismatch at {part["address"]}')
            cursor = addr + size

    def test_review_accepts_ledger(self):
        result = review(self.img, self.base)
        self.assertEqual(result['reviewed_code_bytes'] + result['reviewed_data_bytes'] + result['unknown_bytes'], self.size)
        self.assertEqual(result['main_sha256'], sha(self.img))

    def test_verified_source_classifies_unknown_literal_pool_as_data(self):
        image, base = bytes(range(16)), 0x1000
        entries = [
            dict(address=base, size=4, kind='code', sha256=sha(image[:4]), evidence='code'),
            dict(address=base + 8, size=2, kind='data', sha256=sha(image[8:10]), evidence='pool'),
        ]
        unit = dict(id='source', credited=True, sections=[dict(
            section='P', address=base, size=16, kind='code',
            interior=[dict(address=base + 8, size=8, kind='data')])])
        result = review(image, base, entries=entries, verified=[unit])
        self.assertEqual(result['reviewed_code_bytes'], 8)
        self.assertEqual(result['reviewed_data_bytes'], 8)
        self.assertEqual(result['unknown_bytes'], 0)

    def test_sampled_delay_slots_and_pool_kinds(self):
        by = {number(p['address']): p for p in self.ranges}

        def kind_at(pc):
            for p in self.ranges:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None

        # RTS delay at 0c0215aa; JMP delay at 0c02aba6; BRA delay at 0c02842a
        self.assertEqual(kind_at(0x0c0215aa), 'code')
        self.assertEqual(kind_at(0x0c02aba6), 'code')
        self.assertEqual(kind_at(0x0c02842a), 'code')
        self.assertEqual(by[0x0c02842c]['kind'], 'data')
        self.assertEqual(kind_at(0x0c02ac7c), 'data')
        self.assertEqual(kind_at(0x0c0477ce), 'code')
        self.assertEqual(by[0x0c0477d0]['kind'], 'data')
        self.assertEqual(by[0x0c0477d0]['size'], 12)
        self.assertEqual(number(by[0x0c047796]['address']) + by[0x0c047796]['size'], 0x0c0477d0)


if __name__ == '__main__':
    unittest.main()
