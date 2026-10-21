import unittest
import json
from pathlib import Path
import subprocess
import sys
import tempfile

from tools.effect_timeline import TimelineParseError, parse_program

from tools.report_effect_timeline_004a9280 import BASE, END, NATIVE_ONLY_ROOTS, callback_roots, load_original_bytes


class MiddleEffectFamilyRootTests(unittest.TestCase):
    def test_includes_independently_loaded_native_roots(self):
        roots = callback_roots()
        self.assertEqual(len(roots), 25)
        self.assertIn(0x004A9360, roots)
        self.assertIn(0x004A96B0, roots)
        self.assertEqual(NATIVE_ONLY_ROOTS[0x004A9360], "native callsite 0x00421540")
        self.assertEqual(NATIVE_ONLY_ROOTS[0x004A96B0], "native callsite 0x00421750")

    def test_last_record_crosses_old_import_cutoff_and_ends_before_next_root(self):
        image = load_original_bytes(Path("src/data/data_u32_004A9280.c"))
        start = 0x004A9ED0 - BASE
        with self.assertRaises(TimelineParseError):
            parse_program(image, start, 0x004A9F60 - BASE)
        program = parse_program(image, start, END - BASE)
        self.assertEqual(program.count, 1)
        self.assertEqual(program.end + BASE, 0x004A9F61)
        self.assertEqual(END - BASE - program.end, 15)

    def test_source_backed_report_accounts_for_every_record_once(self):
        with tempfile.TemporaryDirectory() as directory:
            output = Path(directory) / "report.json"
            subprocess.run([sys.executable, "-m", "tools.report_effect_timeline_004a9280",
                            "--output", str(output)], check=True)
            report = json.loads(output.read_text())
        self.assertEqual(len(report["roots"]), 25)
        self.assertEqual(report["held_bytes"], 0)
        self.assertEqual((report["native_read_bytes"], report["opaque_payload_bytes"],
                          report["inter_root_gap_bytes"]), (2845, 254, 213))
        self.assertEqual(report["total_covered_bytes"], END - BASE)
        self.assertEqual(report["roots"][-1]["boundary_address"], "0x004A9F70")
        self.assertTrue(all(row["boundary_kind"] == "next_callback_root"
                            for row in report["roots"]))


if __name__ == "__main__":
    unittest.main()
