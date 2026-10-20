import unittest

from tools.effect_transform_tables import (
    ROW_SIZE,
    TABLE1_BASE,
    TABLE2_BASE,
    TABLE_SIZE,
    accessed_rows,
    body_table1_selectors,
    contiguous_row_runs,
    signed_quad,
)
from tools.report_effect_transform_tables import NATIVE_ONLY_ROOT_BOUNDS, parser_root_inventory


class EffectTransformTableTests(unittest.TestCase):
    def test_only_native_table_selector_opcodes_count(self):
        selectors = body_table1_selectors([0, 1, 4, 5, 10, 13, 0x10, 0x9B, 0x110])
        self.assertEqual(selectors, {0x10, 0x9B})

    def test_renderer_and_stream_rows_form_disjoint_runs(self):
        rows = accessed_rows([0x10, 0x9B])
        self.assertTrue(set(range(16, 78)).issubset(rows))
        self.assertTrue({80, 81, 145, 146, 149, 0x9B}.issubset(rows))
        runs = contiguous_row_runs(rows)
        self.assertEqual(runs[0], (16, 78))
        self.assertEqual(runs[-1], (155, 156))
        self.assertEqual(sum(end - start for start, end in runs), len(rows))

    def test_native_table_extents_are_exactly_one_byte_selector_times_stride(self):
        self.assertEqual(TABLE1_BASE + TABLE_SIZE, TABLE2_BASE)
        self.assertEqual(TABLE2_BASE + TABLE_SIZE, 0x004A8F80)
        self.assertEqual(TABLE_SIZE, 256 * ROW_SIZE)

    def test_quad_fields_are_signed_words(self):
        image = bytearray(0x100000 + 16)
        address = 0x00100000
        for i, value in enumerate((-1, 0, 121, -144)):
            image[i * 4:i * 4 + 4] = value.to_bytes(4, "little", signed=True)
        self.assertEqual(signed_quad(bytes(image), address), (-1, 0, 121, -144))

    def test_native_only_stream_roots_have_explicit_next_root_bounds(self):
        roots = parser_root_inventory()
        self.assertEqual(len(roots), 52)
        self.assertEqual(
            NATIVE_ONLY_ROOT_BOUNDS,
            {
                0x004A9360: (0x004A93D0, "native func_004220B0 callsite 0x00421540"),
                0x004A96B0: (0x004A9720, "native func_004220B0 callsite 0x00421750"),
                0x004AA160: (0x004AA240, "func_00421C00 conditional callback at 0x00421C44"),
                0x004AA240: (0x004AA320, "func_00421C00 conditional callback at 0x00421C7C"),
                0x004AA7B0: (0x004AA800, "native func_004220B0 callsite 0x00421E90"),
            },
        )


if __name__ == "__main__":
    unittest.main()
