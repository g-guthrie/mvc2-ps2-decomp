import unittest

from tools.report_effect_timeline_late_family import END, START, late_roots


class LateEffectFamilyTests(unittest.TestCase):
    def test_includes_native_only_conditional_stream_roots(self):
        roots = dict(late_roots())
        self.assertEqual(len(roots), 22)
        self.assertIn(0x004AA160, roots)
        self.assertIn(0x004AA240, roots)
        self.assertIn("func_00421C00", roots[0x004AA160])
        self.assertIn("func_00421C00", roots[0x004AA240])
        self.assertIn("0x00421E90", roots[0x004AA7B0])
        self.assertEqual(min(roots), START)
        self.assertEqual(max(roots), 0x004AA8A0)
        self.assertEqual(END, 0x004AA980)


if __name__ == "__main__":
    unittest.main()
