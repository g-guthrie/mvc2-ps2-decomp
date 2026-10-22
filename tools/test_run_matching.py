import tempfile
import unittest
from pathlib import Path

from tools import build_runner, run_matching

PRELUDE = 'set -eu\nBUILD=build/matching\nmkdir -p "$BUILD"\n'
DATA = 'PYTHON="$PYTHON" tools/compile_matching_data.sh\n'


class ParseScriptTest(unittest.TestCase):
    def test_expands_loops_and_joins_continuations(self):
        body = (
            "for unit in a b; do\n"
            '    "$WIBO" "$MWCCPS2" \\\n'
            '        "src/$unit.c" -o "$BUILD/$unit.o"\n'
            '    "$PYTHON" tools/verify_object.py "$BUILD/$unit.o" rom --source "src/$unit.c"\n'
            "done\n"
            "# comment\n"
        )
        prelude, commands = run_matching.parse_script(PRELUDE + body + DATA)
        self.assertTrue(prelude.endswith('mkdir -p "$BUILD"'))
        self.assertEqual(commands, [
            '"$WIBO" "$MWCCPS2" "src/a.c" -o "$BUILD/a.o"',
            '"$PYTHON" tools/verify_object.py "$BUILD/a.o" rom --source "src/a.c"',
            '"$WIBO" "$MWCCPS2" "src/b.c" -o "$BUILD/b.o"',
            '"$PYTHON" tools/verify_object.py "$BUILD/b.o" rom --source "src/b.c"',
        ])

    def test_rejects_unschedulable_control_flow(self):
        with self.assertRaisesRegex(SystemExit, "unsupported shell control flow"):
            run_matching.parse_script(PRELUDE + 'if true; then\n  echo\nfi\n' + DATA)

    def test_rejects_commands_after_data_step(self):
        with self.assertRaisesRegex(SystemExit, "after the data step"):
            run_matching.parse_script(PRELUDE + DATA + "echo late\n")


class GroupJobsTest(unittest.TestCase):
    def test_commands_sharing_a_build_file_stay_together_in_order(self):
        commands = [
            'cpp src/a.c "$BUILD/a.i"',
            'cc "$BUILD/b.c" -o "$BUILD/b.o"',
            'cc1 "$BUILD/a.i" -o "$BUILD/a.s"',
            'as "$BUILD/a.s" -o "$BUILD/a.o"',
            'verify "$BUILD/b.o"',
        ]
        self.assertEqual(run_matching.group_jobs(commands), [
            [commands[0], commands[2], commands[3]],
            [commands[1], commands[4]],
        ])

    def test_repository_script_parses(self):
        _, commands = run_matching.parse_script(run_matching.SCRIPT.read_text(encoding="utf-8"))
        jobs = run_matching.group_jobs(commands)
        self.assertGreater(len(jobs), 1)


class FileDigestTest(unittest.TestCase):
    def test_header_change_changes_digest(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "unit.c").write_text('#include "unit.h"\nint f(void) { return X; }\n')
            header = root / "unit.h"
            header.write_text("#define X 1\n")
            before = build_runner.file_digest(root / "unit.c")
            header.write_text("#define X 22\n")
            self.assertNotEqual(before, build_runner.file_digest(root / "unit.c"))


class CompileCacheTest(unittest.TestCase):
    def test_restore_returns_stored_outputs_and_log(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            output = root / "out" / "unit.o"
            output.parent.mkdir()
            output.write_bytes(b"object")
            cache = build_runner.CompileCache(root / "cache")
            self.assertIsNone(cache.restore("ab" * 32, [output]))
            cache.store("ab" * 32, [output], "compiled\n")
            output.write_bytes(b"stale")
            self.assertEqual(cache.restore("ab" * 32, [output]), "compiled\n")
            self.assertEqual(output.read_bytes(), b"object")


if __name__ == "__main__":
    unittest.main()
