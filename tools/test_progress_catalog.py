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
    def test_empty_codegen_barriers_are_rejected_per_function(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "mixed.c").write_text(
                'int good(void) { return 1; } void bad(void) {\n'
                ' __asm__ volatile("");\n}\n'
            )
            validate_source_credit({"good": {"source": "mixed.c"}}, root)
            with self.assertRaisesRegex(SystemExit, "empty asm codegen barrier"):
                validate_source_credit({"bad": {"source": "mixed.c"}}, root)

    def test_manual_metrowerks_nop_cannot_receive_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "mixed.c").write_text(
                'void good(void) { /* asm { nop } */ }\n'
                'void bad(void) { asm { div.s r, d, nf; nop; nop } }\n'
            )
            validate_source_credit({"good": {"source": "mixed.c"}}, root)
            with self.assertRaisesRegex(SystemExit, "manual asm nop"):
                validate_source_credit({"bad": {"source": "mixed.c"}}, root)

    def test_unused_fixed_register_destination_cannot_receive_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "bad.c").write_text(
                'extern volatile int flag; void bad(void) {\n'
                'register int j __asm__("$3"); j = flag;\n'
                'const char *note = "j is an example";\n}\n'
            )
            with self.assertRaisesRegex(SystemExit, "unused fixed-register local"):
                validate_source_credit({"bad": {"source": "bad.c"}}, root)

    def test_actual_fixed_register_reads_and_cpu_operations_remain_eligible(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "real.c").write_text(
                'extern int flag; int comparison(void) {\n'
                'register int j __asm__("$3"); j = flag; return j == 0; }\n'
                'void operation(void) { register int j __asm__("$3");\n'
                'j = flag; __asm__ volatile("syscall 0" : : "r"(j)); }\n'
                'void fence(void) { __asm__ volatile("" : : : "memory"); }\n'
            )
            validate_source_credit({name: {"source": "real.c"}
                                    for name in ("comparison", "operation", "fence")}, root)

    def test_forcing_mentions_and_calls_are_not_function_bodies(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "real.c").write_text(
                'int real(void) {\n'
                '/* __asm__ volatile(""); */\n'
                'const char *note = "__asm__ volatile(\\"\\");"; return 1; }\n'
                'void caller(void) { if (real()) { __asm__ volatile(""); } }\n'
            )
            validate_source_credit({"real": {"source": "real.c"}}, root)

    def test_whitespace_only_asm_and_unread_fixed_register_are_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "bad.c").write_text(
                'void empty(void) { __asm__ volatile("\\n" "\\t"); }\n'
                'void unread(void) { register int j __asm__("$3"); }\n'
            )
            for name, reason in (("empty", "empty asm codegen barrier"),
                                 ("unread", "unused fixed-register local")):
                with self.subTest(name=name), self.assertRaisesRegex(SystemExit, reason):
                    validate_source_credit({name: {"source": "bad.c"}}, root)

    def test_metrowerks_assembly_bodies_cannot_receive_c_credit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "mixed.c").write_text(
                'asm void func_002301C0(void) { .word 0x03E00008 }\n'
                'asm void *func_003DC120(void *p, int x) { jr ra }\n'
                'int func_00100010(void) { return 1; }\n'
            )
            validate_source_credit({"func_00100010": {"source": "mixed.c"}}, root)
            for name in ("func_002301C0", "func_003DC120"):
                with self.subTest(name=name), self.assertRaisesRegex(
                    SystemExit, "assembly instruction stream credited as C"
                ):
                    validate_source_credit({name: {"source": "mixed.c"}}, root)
            catalog = root / "matches.csv"
            catalog.write_text(
                'name,address,size,source,status\n'
                'func_002301C0,0x002301C0,0x9C,mixed.c,placeholder\n'
                'func_003DC120,0x003DC120,0x64,mixed.c,placeholder\n'
                'func_00100010,0x00100010,0x4,mixed.c,complete\n'
            )
            validate_source_credit(load_matches(catalog), root)

    def test_assembly_mentions_do_not_disqualify_real_c(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "real.c").write_text(
                '/* Example:\nasm void func_00100000(void) { jr ra }\n*/\n'
                'const char *note = "asm void func_00100000(void) { jr ra }";\n'
                'int func_00100000(void) { return 1; }\n'
            )
            validate_source_credit({"func_00100000": {"source": "real.c"}}, root)

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
