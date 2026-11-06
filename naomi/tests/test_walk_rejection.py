"""A walk must reject undecodable bytes and must not propose overlapping ranges."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import flow_map
from core import number


class WalkRejectionTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image, _ = flow_map.load_image()

    def test_filler_is_not_accepted_as_code(self):
        # 0x0c22e58c is a run of 0xffff ROM filler reached by a raw BSR hint.
        self.assertEqual(self.image.word(0x0c22e58c), 0xFFFF)
        fn = flow_map.walk_function(self.image, 0x0c22e58c)
        self.assertTrue(fn['issues'], 'a walk over undecodable filler must report issues')
        self.assertIn('undecodable', {kind for kind, *_rest in fn['issues']})

    def test_accepted_walk_has_no_undecodable_word(self):
        fn = flow_map.walk_function(self.image, 0x0c148312)
        self.assertEqual(fn['issues'], [])
        for start, size in fn['code']:
            for pc in range(start, start + size, 2):
                self.assertNotEqual(flow_map.sh4.disasm(self.image.word(pc), pc), 'error')

    def test_proposals_do_not_overlap_each_other(self):
        existing = flow_map.existing_ranges(self.image)
        roots = [0x0c148312, 0x0c148350, 0x0c14838c]
        functions = flow_map.map_from_roots(self.image, roots, existing)
        props = flow_map.proposals_from_functions(self.image, functions, existing)
        spans = sorted((number(p['address']), number(p['address']) + p['size']) for p in props)
        for (_a, b), (c, _d) in zip(spans, spans[1:]):
            self.assertLessEqual(b, c, 'proposals must not overlap each other')


if __name__ == '__main__':
    unittest.main()


class PointerTableTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.image, _ = flow_map.load_image()

    def test_in_image_pointer_runs_are_not_code(self):
        # 0x0c2413ac holds twelve 0x0c07-page pointers; its low halfwords
        # decode as mov.b/swap.b rather than branches.
        self.assertTrue(flow_map.looks_like_pointer_table(self.image, 0x0c2413ac, 48))
        # 0x0c23b7fc repeats one pointer, so branch-shaped lows do not save it.
        self.assertTrue(flow_map.looks_like_pointer_table(self.image, 0x0c23b7fc, 30))

    def test_branch_pairs_with_stc_delay_slots_stay_code(self):
        # `stc sr,r12` encodes as 0x0c02, which is also an image page, so a
        # bsr/bra run looks page-constant without being a table.
        self.assertFalse(flow_map.looks_like_pointer_table(self.image, 0x0c026e50, 552))
        self.assertFalse(flow_map.looks_like_pointer_table(self.image, 0x0c159070, 296))


class LedgerCodeIsDecodableTests(unittest.TestCase):
    def test_no_reviewed_code_range_holds_an_undecodable_word(self):
        """Every even address in a code range is an instruction boundary.

        SH-4 instructions are two bytes and two-byte aligned, so a word that
        encodes no instruction cannot sit inside executed code.
        """
        image, _ = flow_map.load_image()
        undecodable = bytes(flow_map.sh4.disasm(word, 0) == 'error' for word in range(1 << 16))
        blob, base = image.blob, image.base
        offenders = []
        for part in flow_map.load(flow_map.ROOT / 'config/mapping.json')['ranges']:
            if part['kind'] != 'code':
                continue
            start = number(part['address']) - base
            chunk = blob[start:start + part['size']]
            for index in range(0, len(chunk) - 1, 2):
                if undecodable[chunk[index] | (chunk[index + 1] << 8)]:
                    offenders.append(f"{part['address']} at +{index}")
                    break
        self.assertEqual(offenders[:5], [], f"{len(offenders)} code ranges hold undecodable words")
