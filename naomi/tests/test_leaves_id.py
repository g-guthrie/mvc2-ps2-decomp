"""Unmapped four-byte identity leaves must compile to retail RTS; MOV R4,R0."""
import shutil
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from build import compile_unit
from core import ROOT, compare, load, number, verify_rom


class LeavesIdTests(unittest.TestCase):
    def test_identity_leaves_match_retail(self):
        flags = load(ROOT / 'config/compiler.json')['sets']['game']
        target = load(ROOT / 'config/target.json')
        main = verify_rom(target)[number(target['main']['rom_offset']):]
        base = number(target['main']['address'])
        units = {u['id']: u for u in load(ROOT / 'config/units.json')}
        # Library modules may absorb leaves (leaves_id_29 is now part of sySq_).
        present = [uid for uid in ('leaves_id_28', 'leaves_id_29') if uid in units]
        self.assertTrue(present)
        for uid in present:
            work = ROOT / 'build' / f'work-{uid}'
            if work.exists():
                shutil.rmtree(work)
            shutil.copytree(ROOT / 'toolchain/hitachi-shc-5.1r08', work)
            unit = units[uid]
            self.assertEqual(unit['mode'], 'verified')
            elf, link = compile_unit(unit, work, flags)
            proof, _ = compare(unit, elf, link, main, base)
            self.assertTrue(proof['exact'], (uid, proof['problems']))
            self.assertEqual(
                sum(part['equal_bytes'] for part in proof['sections']),
                4 * len(unit['sections']))
            shutil.rmtree(work)
