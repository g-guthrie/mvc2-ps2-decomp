"""CFG mapper must match reviewed boot-init boundaries and not swallow tail-call targets."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT, load, number, verify_rom
from flow_map import Image, recover_callback_cells, recover_indexed_tables, walk_function
from ghidra_draft import function_starts


def image():
    target = load(ROOT / 'config/target.json')
    main = target['main']
    base = number(main['address'])
    blob = verify_rom(target)[number(main['rom_offset']):number(main['rom_offset']) + number(main['size'])]
    return Image(blob, base)


class FlowMapTests(unittest.TestCase):
    def test_code_after_tail_jump_is_a_function_start(self):
        base = 0x1000
        image = bytes.fromhex('2b4209000b000900')  # JMP @R2; NOP; RTS; NOP
        self.assertEqual(function_starts(image, base, [(base, 4, 'code'),
                                                        (base + 4, 4, 'code')]),
                         [base, base + 4])

    @classmethod
    def setUpClass(cls):
        cls.img = image()

    def test_pcrel_loaded_prologs_are_reviewed_code(self):
        fn = walk_function(self.img, 0x0c2103a0)
        self.assertFalse(fn['issues'], fn['issues'])
        def kind_at(pc):
            for p in load(ROOT / 'config/mapping.json')['ranges']:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None
        self.assertEqual(kind_at(0x0c2103a0), 'code')
        self.assertEqual(kind_at(0x0c224d82), 'code')
        self.assertEqual(kind_at(0x0c225e0e), 'code')

    def test_boot_init_jsr_r11_survives_intervening_other_jsrs(self):
        from flow_map import literal_reg_target
        target = literal_reg_target(self.img, 0x0c028424, 11)
        self.assertEqual(target, 0x0c023060)
        fn = walk_function(self.img, 0x0c028394)
        dests = [c[2] for c in fn['calls'] if c[0] == 'jsr']
        self.assertIn(0x0c023060, dests)
        def kind_at(pc):
            for p in load(ROOT / 'config/mapping.json')['ranges']:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None
        self.assertEqual(kind_at(0x0c023060), 'code')

    def test_jsr_lookback_recovers_pointer_across_straight_line_stores(self):
        from flow_map import literal_reg_target
        target = literal_reg_target(self.img, 0x0c20b7b0, 3)
        self.assertEqual(target, 0x0c21b7f0)
        fn = walk_function(self.img, 0x0c20b6f8)
        dests = [c[2] for c in fn['calls'] if c[0] == 'jsr']
        self.assertIn(0x0c21b7f0, dests)
        def kind_at(pc):
            for p in load(ROOT / 'config/mapping.json')['ranges']:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None
        self.assertEqual(kind_at(0x0c21b7f0), 'code')

    def test_boot_init_splits_pool_and_keeps_loop_delay_slot(self):
        fn = walk_function(self.img, 0x0c028394)
        self.assertFalse(fn['issues'], fn['issues'])
        self.assertEqual(fn['code'], [(0x0c028394, 152)])
        self.assertEqual(fn['data'], [(0x0c02842c, 96)])
        self.assertIn(0x0c02842a, set(range(0x0c028394, 0x0c028394 + 152, 2)))

    def test_leaf_includes_rts_delay_and_stops(self):
        fn = walk_function(self.img, 0x0c02156c)
        self.assertFalse(fn['issues'], fn['issues'])
        self.assertEqual(fn['code'], [(0x0c02156c, 64)])
        self.assertEqual(fn['data'], [])

    def test_backward_bra_past_entry_is_tail_not_same_function(self):
        fn = walk_function(self.img, 0x0c034288)
        self.assertFalse(fn['issues'], fn['issues'])
        self.assertEqual(fn['code'], [(0x0c034288, 26)])
        tails = [c for c in fn['calls'] if c[0] == 'bra_tail']
        self.assertEqual(tails[0][2], 0x0c033f28)

    def test_indexed_jmp_table_is_data_and_seeds_in_image_pointers(self):
        fn = walk_function(self.img, 0x0c1fb794)
        self.assertFalse(fn['issues'], fn['issues'])
        self.assertIn((0x0c1fb7f4, 68), fn['tables'])
        self.assertIn(0x0c1fb7f0, fn['table_seeds'])
        self.assertTrue(all(self.img.contains(p) and p % 2 == 0 for p in fn['table_seeds']))

    def test_callback_cell_from_mov_l_then_jsr_is_data(self):
        fn = walk_function(self.img, 0x0c1e9b20)
        self.assertIsNotNone(fn)
        cells = [run for run in fn.get('tables') or [] if run[1] == 4 and run[0] in {
            0x0c266bf8, 0x0c266bfc, 0x0c266c00, 0x0c266bdc,
        }]
        self.assertTrue(cells, fn.get('tables'))
        pcs = list(range(0x0c1e9b20, 0x0c1e9b20 + 80, 2))
        runs, _seeds = recover_callback_cells(self.img, pcs)
        addrs = {a for a, s in runs}
        self.assertIn(0x0c266bf8, addrs)

    def test_braf_and_shll2_follows_case_slots(self):
        fn = walk_function(self.img, 0x0c1fc80a)
        self.assertFalse(fn['issues'], fn['issues'])
        covered = []
        for start, size in fn['code']:
            covered.extend(range(start, start + size, 2))
        self.assertIn(0x0c1fc832, covered)

    def test_ledger_records_braf_word_table_as_data(self):
        def kind_at(pc):
            for p in load(ROOT / 'config/mapping.json')['ranges']:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None
        self.assertEqual(kind_at(0x0c212368), 'data')
        self.assertEqual(kind_at(0x0c21237a), 'data')
        self.assertEqual(kind_at(0x0c21237c), 'code')

    def test_braf_mova_word_table_is_data_and_cases_are_code(self):
        fn = walk_function(self.img, 0x0c212348)
        self.assertFalse(fn['issues'], fn['issues'])
        self.assertIn((0x0c212368, 20), fn.get('tables') or fn.get('data'))
        covered = []
        for start, size in fn['code']:
            covered.extend(range(start, start + size, 2))
        self.assertIn(0x0c21237c, covered)
        self.assertNotIn(0x0c212368, covered)

    def test_ledger_records_callback_cell(self):
        def kind_at(pc):
            for p in load(ROOT / 'config/mapping.json')['ranges']:
                lo = number(p['address'])
                if lo <= pc < lo + p['size']:
                    return p['kind']
            return None
        self.assertEqual(kind_at(0x0c266bf8), 'data')

    def test_ledger_records_indexed_jump_table_as_data(self):
        by = {number(p['address']): p for p in load(ROOT / 'config/mapping.json')['ranges']}
        part = by[0x0c1fb7f4]
        self.assertEqual(part['kind'], 'data')
        self.assertEqual(part['size'], 68)

    def test_jump_table_words_are_not_kept_as_code(self):
        pcs = list(range(0x0c1fb794, 0x0c1fb794 + 24, 2))
        tables, seeds = recover_indexed_tables(self.img, pcs)
        self.assertEqual(tables, [(0x0c1fb7f4, 68)])
        self.assertGreaterEqual(len(seeds), 2)


if __name__ == '__main__':
    unittest.main()
