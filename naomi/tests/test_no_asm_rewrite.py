"""compile_unit must assemble SHC output, not rewrite instructions to match ROM."""
import inspect
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import build
from core import ROOT, load


class NoAsmRewriteTests(unittest.TestCase):
    def test_compile_unit_has_no_instruction_rewriters(self):
        source = inspect.getsource(build)
        self.assertNotIn('retarget_pc_word', source)
        self.assertNotIn('rewrite_bsr_imports', source)
        self.assertNotIn('pc_word_pool', source)
        self.assertNotIn('bsr_imports', source)
        self.assertNotIn("BSR         $+H'", source)

    def test_units_do_not_request_instruction_rewrites(self):
        for unit in load(ROOT / 'config/units.json'):
            self.assertNotIn('pc_word_pool', unit, unit['id'])
            self.assertNotIn('pc_rel_imm', unit, unit['id'])
            self.assertNotIn('bsr_imports', unit, unit['id'])
            self.assertNotIn('emit_section', unit, unit['id'])
