"""Whole-source compiler experiments stay separate from admission and credit."""
import sys
import tempfile
import unittest
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import compiler_patterns


class CompilerCorpusTests(unittest.TestCase):
    def test_verified_sources_and_each_negative_control(self):
        result = compiler_patterns.verified_source_corpus()
        self.assertEqual(len(result['patterns']), 4)
        self.assertEqual(result['credit'], 0)
        for row in result['patterns']:
            self.assertTrue(row['whole_unit_exact'], row['id'])
            self.assertFalse(row['negative_control']['exact'], row['id'])
            self.assertEqual(row['negative_control']['symbol'], row['symbol'])
            self.assertTrue(row['source_sha256'])

    def test_family_leads_require_registered_candidate_and_report_line(self):
        with tempfile.TemporaryDirectory(dir=compiler_patterns.ROOT / 'build') as directory:
            source = Path(directory) / 'family.c'
            source.write_text('/* example */\na->angles.scalar.l48 += 256;\n')
            relative = str(source.relative_to(compiler_patterns.ROOT))
            spec = {'source': 'different.c', 'family_query': r'angles\.scalar\.l48'}
            units = [{'id': 'candidate', 'mode': 'candidate', 'source': relative},
                     {'id': 'verified', 'mode': 'verified', 'source': relative}]
            self.assertEqual(compiler_patterns.source_family_hits(spec, units), [{
                'unit': 'candidate', 'source': relative, 'line': 2,
                'evidence': 'a->angles.scalar.l48 += 256;'}])
            spec['source'] = relative
            self.assertEqual(compiler_patterns.source_family_hits(spec, units), [])


if __name__ == '__main__':
    unittest.main()
