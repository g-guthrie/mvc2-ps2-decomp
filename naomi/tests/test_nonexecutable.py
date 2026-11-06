"""Runs proposed by elimination must really encode no SH-4 instruction."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import nonexecutable
from core import ROOT, load, number, sha, verify_rom
from vendor.sh4dis import sh4


class NonExecutableTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        target = load(ROOT / 'config/target.json')
        main = target['main']
        cls.base, offset, size = (number(main[k]) for k in ('address', 'rom_offset', 'size'))
        cls.image = verify_rom(target)[offset:offset + size]
        cls.found = nonexecutable.proposals(cls.image, cls.base)

    def test_decoder_accepts_every_compiler_verified_word(self):
        """The elimination only holds if a valid instruction never reads as error."""
        checked = 0
        for unit in load(ROOT / 'config/units.json'):
            # Library units link an SDK object whose literal pools sit inside its
            # code section undeclared; only compiled C says which words are code.
            if unit.get('mode') != 'verified' or 'library' in unit:
                continue
            for part in unit['sections']:
                if part['kind'] != 'code':
                    continue
                start, size = number(part['address']), number(part['size'])
                # A code section holds the literal pool SHC emits with the code.
                # Those bytes are not instructions and the unit says so; only the
                # words the unit still claims are code are evidence about the decoder.
                spare = set()
                for interior in part.get('interior', ()):
                    if interior['kind'] == 'code':
                        continue
                    lo = number(interior['address'])
                    spare.update(range(lo, lo + number(interior['size'])))
                for pc in range(start, start + size, 2):
                    if pc in spare or pc + 1 in spare:
                        continue
                    word = self.image[pc - self.base] | (self.image[pc - self.base + 1] << 8)
                    self.assertNotEqual(sh4.disasm(word, pc), 'error', f'at 0x{pc:08x}')
                    checked += 1
        self.assertGreater(checked, 500)

    def test_every_proposed_word_is_undecodable(self):
        for start, size in self.found:
            self.assertGreaterEqual(size, nonexecutable.MINIMUM)
            self.assertEqual(start % 2, 0)
            for pc in range(start, start + size, 2):
                word = self.image[pc - self.base] | (self.image[pc - self.base + 1] << 8)
                self.assertEqual(sh4.disasm(word, pc), 'error', f'decodable word at 0x{pc:08x}')

    def test_proposals_do_not_touch_reviewed_bytes(self):
        reviewed = []
        for part in load(ROOT / 'config/mapping.json')['ranges']:
            lo = number(part['address'])
            reviewed.append((lo, lo + part['size']))
        reviewed.sort()
        for start, size in self.found:
            for lo, hi in reviewed:
                if lo >= start + size:
                    break
                self.assertFalse(start < hi and lo < start + size, f'0x{start:08x} overlaps reviewed')


if __name__ == '__main__':
    unittest.main()
