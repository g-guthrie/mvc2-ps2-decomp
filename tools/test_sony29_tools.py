import tempfile
import unittest
from pathlib import Path

from tools.probe_sony29 import defined_functions
from tools.setup_sony29 import install


class SonyCompilerToolsTests(unittest.TestCase):
    def test_call_and_extern_do_not_become_candidate_definitions(self):
        source = """extern int func_001089F0(int);
int func_004087B8(void) {
    if (func_001089F0(1)) { return 1; }
    return 0;
}
"""
        self.assertEqual(defined_functions(source), ["func_004087B8"])
        self.assertEqual(defined_functions("static unsigned int *func_00100000(void) { return 0; }"), ["func_00100000"])

    def test_wrong_archive_cannot_write_any_tools(self):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            archive = root / "invalid.tar.gz"
            archive.write_bytes(b"not the pinned compiler")
            with self.assertRaisesRegex(ValueError, "SHA-256 mismatch"):
                install(archive, root / "destination")
            self.assertFalse((root / "destination").exists())
