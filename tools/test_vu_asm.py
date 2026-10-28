#!/usr/bin/env python3
"""Round-trip tests for tools/vu_asm.py and the src/vu/*.vsm microcode sources."""

from __future__ import annotations

import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import vu_asm  # noqa: E402

REPO = Path(__file__).resolve().parent.parent


@unittest.skipUnless(vu_asm.DEFAULT_ROM.is_file(), "needs the private retail ROM")
class VsmRoundTrip(unittest.TestCase):
    def test_units_match_retail(self):
        for name, addr, size in vu_asm.UNITS:
            with self.subTest(unit=name):
                want = vu_asm.read_rom_unit(vu_asm.DEFAULT_ROM, addr, size)
                self.assertEqual(len(want), size)
                path = REPO / "src/vu" / f"{name}.vsm"
                got = vu_asm.assemble_text(path.read_text(encoding="utf-8"), str(path))
                self.assertEqual(got, want)

    def test_regenerated_text_is_stable(self):
        texts, _, _ = vu_asm.disassemble_units(vu_asm.DEFAULT_ROM)
        for name, text in texts.items():
            with self.subTest(unit=name):
                self.assertEqual(text, (REPO / "src/vu" / f"{name}.vsm").read_text(encoding="utf-8"))


class VsmSources(unittest.TestCase):
    def test_no_raw_fallbacks(self):
        for name, _addr, _size in vu_asm.UNITS:
            text = (REPO / "src/vu" / f"{name}.vsm").read_text(encoding="utf-8")
            self.assertNotIn(".vif raw", text)
            self.assertNotIn(".dmatag_raw", text)


class Encodings(unittest.TestCase):
    def pair(self, lo, up, pc=0x10):
        u, l = vu_asm.disasm_pair(lo, up, pc, lambda t: hex(t))
        self.assertEqual(vu_asm.assemble_pair(u, l, pc), (lo, up), (u, l))
        return u, l

    def test_nops(self):
        self.assertEqual(self.pair(0x8000033C, 0x000002FF), ("nop", "nop"))
        self.assertEqual(self.pair(0x8000033C, 0x400002FF)[0], "nop[e]")

    def test_loi(self):
        self.assertEqual(self.pair(0x3F800000, 0x800002FF), ("nop", "loi 1.0"))
        self.assertEqual(self.pair(0x7FC00001, 0x800002FF)[1], "loi 0x7fc00001")
        self.assertEqual(vu_asm.assemble_pair("nop", "loi 0x1.8p+0"), (0x3FC00000, 0x800002FF))

    def test_every_spec_round_trips(self):
        # Fill every operand field with a distinctive value and round-trip.
        for specs, slot in ((vu_asm.UPPER_SPECS, "u"), (vu_asm.LOWER_SPECS, "l")):
            for sp in specs:
                word = sp.fixed_val | (sp.used & ~sp.fixed_mask & 0x5A5A5A5A)
                if slot == "u":
                    self.pair(0x8000033C, word)
                else:
                    self.pair(word, 0x000002FF)


if __name__ == "__main__":
    unittest.main()
