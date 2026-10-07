import struct
import unittest

from tools.verify_object import (
    R_MIPS_26, R_MIPS_32, R_MIPS_HI16, R_MIPS_LO16,
    R_MIPS_GPREL16, relocate_bytes,
)


class RelocationTest(unittest.TestCase):
    def relocate(self, words, relocations, gp=0x004C7270):
        body = struct.pack('<' + 'I' * len(words), *words)
        result = relocate_bytes(body, relocations, gp)
        return struct.unpack('<' + 'I' * len(words), result)

    def pair(self, high, low, symbol):
        return self.relocate(
            [high, low],
            [(0, R_MIPS_HI16, symbol, 'table', None),
             (4, R_MIPS_LO16, symbol, 'table', None)],
        )

    def test_array_member_offset_is_preserved(self):
        self.assertEqual(self.pair(0x3C020000, 0x24420008, 0x00444D30),
                         (0x3C020044, 0x24424D38))

    def test_low_half_carry_adjusts_the_high_half(self):
        self.assertEqual(self.pair(0x3C020000, 0x24420008, 0x00417FF8),
                         (0x3C020042, 0x24428000))

    def test_negative_offset_crosses_back_over_the_carry_boundary(self):
        self.assertEqual(self.pair(0x3C020000, 0x2442FFF8, 0x00428004),
                         (0x3C020042, 0x24427FFC))

    def test_high_and_signed_low_form_the_full_implicit_addend(self):
        self.assertEqual(self.pair(0x3C020002, 0x24428000, 0x00430020),
                         (0x3C020045, 0x24428020))

    def test_one_low_relocation_resolves_multiple_pending_highs(self):
        result = self.relocate(
            [0x3C020000, 0x3C030001, 0x24420008],
            [(0, R_MIPS_HI16, 0x00417FF8, 'table', None),
             (4, R_MIPS_HI16, 0x00417FF8, 'table', None),
             (8, R_MIPS_LO16, 0x00417FF8, 'table', None)],
        )
        self.assertEqual(result, (0x3C020042, 0x3C030043, 0x24428000))

    def test_explicit_addends_replace_instruction_addends(self):
        result = self.relocate(
            [0x3C02FFFF, 0x2442FFFF],
            [(0, R_MIPS_HI16, 0x00417FF8, 'table', 8),
             (4, R_MIPS_LO16, 0x00417FF8, 'table', 8)],
        )
        self.assertEqual(result, (0x3C020042, 0x24428000))

    def test_jump_word_and_gp_offsets_are_preserved(self):
        result = self.relocate(
            [0x0C000003, 8, 0x8F820004],
            [(0, R_MIPS_26, 0x00101000, 'callee', None),
             (4, R_MIPS_32, 0x00445000, 'pointer', None),
             (8, R_MIPS_GPREL16, 0x004C7278, 'small', None)],
        )
        self.assertEqual(result, (0x0C040403, 0x00445008, 0x8F82000C))

    def test_missing_low_relocation_and_out_of_bounds_are_rejected(self):
        with self.assertRaisesRegex(SystemExit, 'HI16 relocation without LO16'):
            self.relocate([0x3C020000], [(0, R_MIPS_HI16, 0x00440000, 'table', None)])
        with self.assertRaisesRegex(SystemExit, 'relocation outside function'):
            self.relocate([0], [(2, R_MIPS_32, 0x00440000, 'table', None)])


if __name__ == '__main__':
    unittest.main()
