"""Canonical defaults must agree with whole-module SDK export proof."""
import json
import sys
import unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))
from core import ROOT, number

class RuntimeSymbols(unittest.TestCase):
    def test_defaults_agree_with_verified_sdk_exports(self):
        runtime=json.loads((ROOT/'config/runtime.json').read_text())
        units=json.loads((ROOT/'config/units.json').read_text())
        for module,symbol in [('lib_sh4nlfzn___q_mvn','__quick_mvn'),('lib_sh4nlfzn___s_mvn','__slow_mvn'),('lib_sh4nlfzn___q_fmvn','__quick_odd_mvn'),('lib_sh4nlfzn___q_fmvn','__quick_evn_mvn'),('lib_sh4nlfzn___divlu','__divlu')]:
            unit=next(u for u in units if u['id']==module)
            self.assertEqual(unit['mode'],'verified')
            self.assertIn('library',unit)
            self.assertEqual(number(runtime[symbol]),number(unit['exports'][symbol]),symbol)
    def test_aligned_and_byte_copiers_are_distinct(self):
        runtime=json.loads((ROOT/'config/runtime.json').read_text())
        self.assertNotEqual(number(runtime['__quick_mvn']),number(runtime['__slow_mvn']))
        self.assertNotEqual(number(runtime['__quick_mvn']),number(runtime['__quick_odd_mvn']))

if __name__=='__main__':unittest.main()
