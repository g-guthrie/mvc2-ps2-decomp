"""2-aligned Hitachi placement must come from compiled C, not a padded fake."""
import shutil
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from build import compile_unit
from core import ROOT, elf_segments, load, number, verify_rom


class Align2Tests(unittest.TestCase):
    def test_two_aligned_noop_links_at_retail_address(self):
        flags = load(ROOT / 'config/compiler.json')['sets']['game']
        work = ROOT / 'build' / 'work-align2'
        if work.exists():
            shutil.rmtree(work)
        shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work)
        unit = {
            'id': 'align2_noop',
            'source': 'tests/fixtures/align2_noop.c',
            'mode': 'verified',
            'sections': [{'section': 'P', 'kind': 'code', 'address': '0x0c0239e2', 'size': 4}],
            'exports': {'_func_0c0239e2': '0x0c0239e2'},
        }
        elf, link = compile_unit(unit, work, flags)
        segs = elf_segments(elf)
        self.assertEqual(segs[0]['address'], 0x0c0239e2)
        self.assertEqual(len(segs[0]['data']), 4)
        target = load(ROOT / 'config/target.json')
        main = verify_rom(target)[number(target['main']['rom_offset']):]
        base = number(target['main']['address'])
        retail = main[0x0c0239e2 - base:0x0c0239e2 - base + 4]
        self.assertEqual(segs[0]['data'], retail)
        self.assertIn("H'0C0239E2", link)
        shutil.rmtree(work)
