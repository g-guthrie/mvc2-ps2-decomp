"""Pool clustering must recover the registered mask translation unit."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pool_clusters
from core import ROOT, load, number, verify_rom


class PoolClusterTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        target = load(ROOT / 'config/target.json')
        main = target['main']
        cls.base, offset, size = (number(main[k]) for k in ('address', 'rom_offset', 'size'))
        cls.image = verify_rom(target)[offset:offset + size]
        cls.found = pool_clusters.clusters(cls.image, cls.base)

    def test_recovers_the_mask_tu_span(self):
        """src/candidates/mask_tu.c is four functions sharing the 0x0c047b2e pool."""
        rows = [r for r in self.found if r['pool'] == '0x0c047b2e']
        self.assertEqual(len(rows), 1)
        row = rows[0]
        self.assertEqual(row['readers'], 4)
        self.assertEqual(number(row['start']), 0x0c047a3c)
        self.assertEqual(number(row['start']) + row['total'], 0x0c047b60)

    def test_pc_relative_targets(self):
        # mov.l @(disp,PC) rounds PC down to four; mov.w does not.
        self.assertEqual(pool_clusters.pc_relative_target(0xD305, 0x0c047b0e), (0x0c047b24, 4))
        self.assertEqual(pool_clusters.pc_relative_target(0x9002, 0x0c047b0c), (0x0c047b14, 2))
        self.assertIsNone(pool_clusters.pc_relative_target(0x000B, 0x0c047b0c))

    def test_every_cluster_is_code_then_its_own_pool(self):
        ranges = sorted(
            (number(p['address']), number(p['address']) + p['size'], p['kind'])
            for p in load(ROOT / 'config/mapping.json')['ranges'])
        kinds = {}
        for lo, hi, kind in ranges:
            kinds[lo] = (hi, kind)
        for row in self.found[:200]:
            start, pool = number(row['start']), number(row['pool'])
            self.assertLess(start, pool)
            self.assertEqual(kinds[start][1], 'code', f'{row["start"]} does not start on code')
            self.assertEqual(kinds[pool][1], 'data', f'{row["pool"]} is not data')


if __name__ == '__main__':
    unittest.main()
