import struct
import unittest
from types import SimpleNamespace

from tools.verify_object import (
    R_MIPS_26, R_MIPS_32, R_MIPS_HI16, R_MIPS_LO16,
    R_MIPS_GPREL16, relocate_bytes, relocation_target, whole_function_anchors,
)


class RelocationTest(unittest.TestCase):
    class Symbol(dict):
        def __init__(self, name, section, value, size=8):
            super().__init__(st_shndx=section, st_value=value, st_size=size,
                             st_info={'type': 'STT_FUNC' if name else 'STT_SECTION'})
            self.name = name

    class Section(dict):
        def __init__(self, size):
            super().__init__(sh_flags=6)
            self.data_size = size

    def test_section_anchor_requires_complete_selected_function_ownership(self):
        symbol = self.Symbol('callee', 10, 0)
        matches = [{'name': 'callee', 'size': '0x8'}]
        elf = SimpleNamespace(get_section=lambda _: self.Section(8))
        self.assertEqual(whole_function_anchors(elf, {'callee': symbol}, matches), [symbol])
        self.assertEqual(whole_function_anchors(elf, {'callee': symbol}, []), [])
        # Extra bytes could be an unverified pool or padding, so cannot anchor it.
        elf = SimpleNamespace(get_section=lambda _: self.Section(12))
        self.assertEqual(whole_function_anchors(elf, {'callee': symbol}, matches), [])
        with self.assertRaisesRegex(SystemExit, 'no target address'):
            relocation_target(self.Symbol('', 10, 0), [], {'callee': 0x0010EB90})

    def test_unnamed_section_reference_uses_known_function_address(self):
        anchor = self.Symbol('callee', 10, 8)
        section = self.Symbol('', 10, 0)
        value, key = relocation_target(section, [anchor], {'callee': 0x0010EB98})
        self.assertEqual(value, 0x0010EB90)
        self.assertEqual(self.relocate([0x0C000001],
                         [(0, R_MIPS_26, value, key, None)]), (0x0C043AE5,))
        # Distinct local sections must not share a pending HI16/LO16 key.
        self.assertNotEqual(key, relocation_target(self.Symbol('', 11, 0),
                            [self.Symbol('other', 11, 0)], {'other': 0x0010EB50})[1])

    def test_unanchored_or_undefined_reference_is_rejected(self):
        for symbol in [self.Symbol('', 10, 0), self.Symbol('unknown', 'SHN_UNDEF', 0)]:
            with self.assertRaisesRegex(SystemExit, 'no target address'):
                relocation_target(symbol, [], {})

    def test_conflicting_section_anchors_are_rejected(self):
        anchors = [self.Symbol('a', 10, 0), self.Symbol('b', 10, 8)]
        with self.assertRaisesRegex(SystemExit, 'inconsistent retail base'):
            relocation_target(self.Symbol('', 10, 0), anchors,
                              {'a': 0x00100000, 'b': 0x00100010})

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
