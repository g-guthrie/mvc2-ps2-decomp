"""A unit section may hold interior bytes of the other kind, declared explicitly."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import sha
from mapping import review

BASE = 0x0c021000


IMAGE = bytes(64)


def ledger(*rows):
    return [dict(address=a, size=s, kind=k, evidence='e',
                 sha256=sha(IMAGE[a - BASE:a - BASE + s])) for a, s, k in rows]


class UnitInteriorTests(unittest.TestCase):
    def setUp(self):
        self.image = IMAGE

    def unit(self, sections):
        return [dict(id='u', credited=True, sections=sections)]

    def test_pool_inside_a_code_section_conflicts_without_a_declaration(self):
        entries = ledger((BASE + 16, 8, 'data'))
        section = [dict(section='P', kind='code', address=BASE, size=32)]
        with self.assertRaises(ValueError):
            review(self.image, BASE, entries, self.unit(section))

    def test_declared_pool_lets_the_section_own_the_whole_range(self):
        entries = ledger((BASE + 16, 8, 'data'))
        section = [dict(section='P', kind='code', address=BASE, size=32,
                        interior=[dict(address=BASE + 16, size=8, kind='data')])]
        result = review(self.image, BASE, entries, self.unit(section))
        kinds = {(r['address'], r['size']): r['kind'] for r in result['ranges']}
        self.assertEqual(kinds[(BASE + 16, 8)], 'data')
        self.assertEqual(result['reviewed_data_bytes'], 8)
        self.assertEqual(result['reviewed_code_bytes'], 24)

    def test_a_declaration_does_not_excuse_an_undeclared_conflict(self):
        entries = ledger((BASE + 8, 4, 'data'), (BASE + 16, 8, 'data'))
        section = [dict(section='P', kind='code', address=BASE, size=32,
                        interior=[dict(address=BASE + 16, size=8, kind='data')])]
        with self.assertRaises(ValueError):
            review(self.image, BASE, entries, self.unit(section))

    def test_interior_must_lie_inside_its_section(self):
        entries = ledger()
        section = [dict(section='P', kind='code', address=BASE, size=16,
                        interior=[dict(address=BASE + 12, size=8, kind='data')])]
        with self.assertRaises(ValueError):
            review(self.image, BASE, entries, self.unit(section))


if __name__ == '__main__':
    unittest.main()
