import unittest

from tools.report_effect_timeline_004a9280 import NATIVE_ONLY_ROOTS, callback_roots


class MiddleEffectFamilyRootTests(unittest.TestCase):
    def test_includes_independently_loaded_native_roots(self):
        roots = callback_roots()
        self.assertEqual(len(roots), 25)
        self.assertIn(0x004A9360, roots)
        self.assertIn(0x004A96B0, roots)
        self.assertEqual(NATIVE_ONLY_ROOTS[0x004A9360], "native callsite 0x00421540")
        self.assertEqual(NATIVE_ONLY_ROOTS[0x004A96B0], "native callsite 0x00421750")


if __name__ == "__main__":
    unittest.main()
