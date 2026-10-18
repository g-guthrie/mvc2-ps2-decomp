import unittest
import tempfile
from pathlib import Path

from tools.objdiff_report import load_matches
from tools.verify_object import load_matches as load_compiler_matches
from tools.validate_progress_catalog import validate_source_credit

from tools.progress_catalog import (
    DATA_BEGIN,
    DATA_SIZE,
    TEXT_SIZE,
    code_progress,
    data_progress,
    first_overlap,
    unique_covered_bytes,
    validate_code_catalog,
    validate_data_catalog,
)


class ProgressCatalogTest(unittest.TestCase):
    def test_instruction_stream_cannot_receive_c_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "mixed.c").write_text(
                '#define FN(name, body) __asm__(body)\n'
                'FN(func_00100000, "jr $31\\n");\n'
                'int func_00100010(void) { return 1; }\n'
            )
            # Genuine C in the same translation unit remains eligible.
            validate_source_credit({"func_00100010": {"source": "mixed.c"}}, root)
            with self.assertRaisesRegex(SystemExit, "assembly instruction stream credited as C"):
                validate_source_credit({"func_00100000": {"source": "mixed.c"}}, root)
            # Correctly classified placeholders are filtered by the report loader.
            catalog = root / "matches.csv"
            catalog.write_text(
                'name,address,size,source,status\n'
                'func_00100000,0x00100000,0x4,mixed.c,placeholder\n'
                'func_00100010,0x00100010,0x4,mixed.c,complete\n'
            )
            validate_source_credit(load_matches(catalog), root)

    def test_required_cpu_operation_retains_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "src").mkdir()
            (root / "src/k2s.c").write_text(
                '#define FN(name, body) __asm__(body)\n'
                'FN(func_001048B0, "mfc0 $2,$12\\n");\n'
            )
            validate_source_credit(
                {"func_001048B0": {"source": "src/k2s.c"}}, root
            )

    def test_assembly_placeholder_gets_no_code_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            catalog = Path(directory) / "matches.csv"
            catalog.write_text(
                "name,address,size,source,status\n"
                "c,0x00100000,0x10,src/c.c,complete\n"
                "assembly,0x00100010,0x20,src/assembly.c,placeholder\n"
            )
            matches = load_matches(catalog)
            self.assertEqual(set(matches), {"c"})
            self.assertEqual(code_progress(matches), (16, 16))

    def test_malformed_code_rows_are_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            catalog = Path(directory) / "matches.csv"
            for row in (
                "<<<<<<< HEAD\n", "=======\n", ">>>>>>> branch\n",
                "f,0x00100000,0x10,src/f.c\n",
                "f,0x00100000,0x10,src/f.c,complete,extra\n",
            ):
                catalog.write_text("name,address,size,source,status\n" + row)
                for loader in (load_matches, load_compiler_matches):
                    with self.subTest(row=row, loader=loader.__module__):
                        with self.assertRaisesRegex(SystemExit, "malformed code match row"):
                            loader(catalog)

    def test_unique_coverage_dedups_overlap(self):
        lo = DATA_BEGIN
        covered = unique_covered_bytes(
            [(lo, 32), (lo + 16, 32)],
            lo,
            lo + DATA_SIZE,
        )
        self.assertEqual(covered, 48)

    def test_first_overlap_names(self):
        self.assertEqual(
            first_overlap([(0, 16, "a"), (8, 16, "b")]),
            ("a", "b"),
        )
        self.assertIsNone(first_overlap([(0, 16, "a"), (16, 16, "b")]))

    def test_code_overlap_is_rejected(self):
        functions = [
            {"name": "a", "address": 0x00100000, "size": 16},
            {"name": "b", "address": 0x00100008, "size": 16},
        ]
        matches = {
            "a": {"address": 0x00100000, "size": 16, "complete": True, "progress": "reconstructed"},
            "b": {"address": 0x00100008, "size": 16, "complete": True, "progress": "reconstructed"},
        }
        with self.assertRaises(SystemExit):
            validate_code_catalog(functions, matches)

    def test_data_overlap_is_rejected(self):
        units = {"a": (DATA_BEGIN, 32), "b": (DATA_BEGIN + 16, 32)}
        matches = {
            "a": {"address": DATA_BEGIN, "size": 32, "complete": True, "progress": "reconstructed"},
            "b": {"address": DATA_BEGIN + 16, "size": 32, "complete": True, "progress": "reconstructed"},
        }
        with self.assertRaises(SystemExit):
            validate_data_catalog(units, matches)

    def test_complete_cannot_exceed_matched(self):
        matches = {
            "a": {"address": DATA_BEGIN, "size": 16, "complete": True, "progress": "reconstructed"},
        }
        matched, complete = data_progress(matches)
        self.assertEqual(matched, complete)
        with self.assertRaises(SystemExit):
            data_progress(
                {"a": {"address": DATA_BEGIN, "size": DATA_SIZE + 4, "complete": True, "progress": "reconstructed"}}
            )

    def test_linked_code_is_at_most_text_span(self):
        matches = {
            "a": {"address": 0x00100000, "size": 8, "complete": True, "progress": "reconstructed"},
        }
        matched, complete = code_progress(matches)
        self.assertEqual(matched, 8)
        self.assertEqual(complete, 8)
        self.assertLessEqual(complete, TEXT_SIZE)


if __name__ == "__main__":
    unittest.main()
