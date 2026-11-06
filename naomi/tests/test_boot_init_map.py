"""Boot-init mapping must keep the literal pool out of code and include delay slots."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from core import ROOT, load, number, sha, verify_rom
from mapping import review


def image():
    target = load(ROOT / 'config/target.json')
    main = target['main']
    base = number(main['address'])
    rom = verify_rom(target)
    return rom[number(main['rom_offset']):number(main['rom_offset']) + number(main['size'])], base


class BootInitMappingTests(unittest.TestCase):
    def setUp(self):
        self.img, self.base = image()
        self.reviewed = {number(p['address']): p for p in load(ROOT / 'config/mapping.json')['ranges']}

    def test_boot_init_code_excludes_pool_and_includes_loop_delay_slot(self):
        part = self.reviewed[0x0c028394]
        self.assertEqual(part['kind'], 'code')
        self.assertEqual(part['size'], 152)
        end = 0x0c028394 + 152
        self.assertEqual(end, 0x0c02842c)
        self.assertEqual(part['sha256'], sha(self.img[0x0c028394 - self.base:end - self.base]))
        pool = self.reviewed[0x0c02842c]
        self.assertEqual(pool['kind'], 'data')
        self.assertEqual(pool['size'], 96)

    def test_leaf_rts_delay_slot_is_inside_reviewed_code(self):
        part = self.reviewed[0x0c02156c]
        self.assertGreaterEqual(0x0c0215aa, number(part['address']))
        self.assertLess(0x0c0215aa, number(part['address']) + part['size'])
        word = int.from_bytes(self.img[0x0c0215aa - self.base:0x0c0215ac - self.base], 'little')
        self.assertEqual(word, 0x0009)

    def test_copy_loop_word_literal_and_its_pad_are_separate_ranges(self):
        self.assertEqual(self.reviewed[0x0c02239c]['size'], 2)
        self.assertEqual(self.reviewed[0x0c02239e]['size'], 2)  # the alignment pad before the mov.l literals
        self.assertIn(0x0c0223c0, self.reviewed)
        code = self.reviewed[0x0c022354]
        self.assertEqual(number(code['address']) + code['size'], 0x0c02239a)

    def test_ab50_jmp_delay_slot_is_code_and_pool_starts_after_existing_word(self):
        code = self.reviewed[0x0c02ab50]
        self.assertEqual(code['kind'], 'code')
        self.assertEqual(number(code['address']) + code['size'], 0x0c02aba8)
        slot = 0x0c02aba6
        self.assertGreaterEqual(slot, number(code['address']))
        self.assertLess(slot, number(code['address']) + code['size'])
        self.assertEqual(self.reviewed[0x0c02ac7c]['kind'], 'data')
        self.assertEqual(self.reviewed[0x0c02ac74]['size'], 8)

    def test_mask_apply_pool_is_data_and_bra_delay_is_code(self):
        code = self.reviewed[0x0c047796]
        self.assertEqual(code['kind'], 'code')
        self.assertEqual(code['size'], 58)
        self.assertEqual(number(code['address']) + code['size'], 0x0c0477d0)
        self.assertGreaterEqual(0x0c0477c6, number(code['address']))
        self.assertLess(0x0c0477c6, number(code['address']) + code['size'])
        pool = self.reviewed[0x0c0477d0]
        self.assertEqual(pool['kind'], 'data')
        self.assertEqual(pool['size'], 12)
        callee = self.reviewed[0x0c0477dc]
        self.assertEqual(callee['kind'], 'code')
        self.assertEqual(callee['size'], 156)
        self.assertLess(0x0c047876, number(callee['address']) + callee['size'])
        self.assertEqual(self.reviewed[0x0c047878]['kind'], 'data')

    def test_wait_loop_pool_does_not_absorb_unreferenced_words(self):
        part = self.reviewed[0x0c0272e8]
        self.assertEqual(part['kind'], 'data')
        self.assertEqual(part['size'], 4)
        self.assertEqual(number(part['address']) + part['size'], 0x0c0272ec)
        result = review(self.img, self.base)
        self.assertEqual(result['main_sha256'], sha(self.img))


if __name__ == '__main__':
    unittest.main()
