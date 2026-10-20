import unittest

from tools.report_effect_timeline_early_family import END, START, early_roots


class EarlyEffectFamilyTests(unittest.TestCase):
    def test_five_source_roots_bound_the_family_before_a9280(self):
        roots = early_roots()
        self.assertEqual(roots, [0x004A8F80, 0x004A9000, 0x004A9060, 0x004A9120, 0x004A91E0])
        self.assertEqual(START, roots[0])
        self.assertEqual(END, 0x004A9280)


if __name__ == "__main__":
    unittest.main()
