"""Discovery must preserve dependencies, ABI roles and exact-shape behavior."""
import struct
import sys
import unittest
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from twins import register_shape, renamed_twins, shape


def signature(*words):
    image = struct.pack('<' + 'H' * len(words), *words)
    result = register_shape(image, 0, 0, len(image))
    return None if result is None else result[0]


class RegisterTwinTests(unittest.TestCase):
    def test_consistent_scratch_and_preserved_register_renaming(self):
        # mov r4,r8; mov #3,r1; add r1,r8; mov r8,r0; rts; nop
        self.assertEqual(signature(0x6843, 0xe103, 0x381c, 0x6083, 0x000b, 0x0009),
                         signature(0x6943, 0xe207, 0x392c, 0x6093, 0x000b, 0x0009))

    def test_dependency_alias_and_later_inconsistent_use_fail(self):
        self.assertNotEqual(signature(0x6143, 0x6213, 0x312c),
                            signature(0x6243, 0x6323, 0x322c))
        self.assertNotEqual(signature(0x6143, 0x6213, 0x312c),
                            signature(0x6243, 0x6323, 0x313c))

    def test_fixed_abi_and_preserved_vs_scratch_roles(self):
        for a, b in [(0x6143, 0x6153), (0x6013, 0x6313),
                     (0x68f3, 0x68e3), (0x6143, 0x6843),
                     (0xf14c, 0xf15c), (0xf10c, 0xf12c),
                     (0xf14c, 0xfc4c)]:
            self.assertNotEqual(signature(a), signature(b))

    def test_delayed_branch_offsets_and_saves_keep_relationships(self):
        self.assertNotEqual(signature(0xa001, 0x6143), signature(0xa002, 0x6243))
        self.assertEqual(signature(0x2f86, 0x6843, 0x68f6),
                         signature(0x2f96, 0x6943, 0x69f6))
        self.assertNotEqual(signature(0x2f86, 0x6843, 0x68f6),
                            signature(0x2f96, 0x6943, 0x68f6))

    def test_unsupported_state_or_opcode_rejects_whole_function(self):
        for word in (0xffff, 0xf3fd, 0xf7fd, 0x406a, 0xc301, 0x0000):
            self.assertIsNone(signature(0x0009, word))

    def test_renamed_hints_have_source_mapping_and_exclude_exact_shape(self):
        words = (0x6143, 0x000b, 0x0009, 0x6243, 0x000b, 0x0009,
                 0x6143, 0x000b, 0x0009)
        image = struct.pack('<9H', *words)
        hints = renamed_twins(image, 0, 0, 6, [0, 6, 12], lambda a: a + 6,
                              {6: 'src/verified/example.c', 12: 'src/verified/same.c'})
        self.assertEqual(hints, [{'address': 6, 'source': 'src/verified/example.c',
                                'twin_to_target_registers': {'r2': 'r1'}}])
        self.assertEqual(renamed_twins(image, 0, 0, 6, [0, 6], lambda a: a + 6, {}), [])

    def test_exact_shape_remains_register_sensitive(self):
        a, b = struct.pack('<H', 0x6143), struct.pack('<H', 0x6243)
        self.assertNotEqual(shape(a, 0, 0, 2), shape(b, 0, 0, 2))
        self.assertEqual(signature(0x6143), signature(0x6243))


if __name__ == '__main__':
    unittest.main()
