"""Exercise the actual rotation table, caller and callee with distinct owners."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class RotationCallbackContextTests(unittest.TestCase):
    def run_rotation(self, drop_owner=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        table = (ROOT / "src/data/jtbl_004BF450.c").read_text()
        caller = (ROOT / "src/x11_e.c").read_text()
        if drop_owner:
            changed = caller.replace("func_0015BD40((u8 *)p,q)",
                                     "func_0015BD40((u8 *)p,wrong_owner)")
            self.assertNotEqual(caller, changed)
            caller = "extern unsigned char wrong_owner[];\n" + changed
        fixture = '#include "rotation_state_callbacks.h"\n'
        fixture += '#include "jtbl_004BF450.c"\n'
        fixture += "u8 wrong_owner[0x600];\nint fptosi(float v){return (int)v;}\n"
        actual = {"func_0015BC90", "func_0015BD40"}
        for name, params in re.findall(r"extern void (func_[0-9A-F]+)\(([^)]*)\);", table):
            if name not in actual:
                named = ", ".join(f"{param.strip()}arg{i}" for i, param in enumerate(params.split(",")))
                fixture += f"void {name}({named}) {{}}\n"
        fixture += """
int main(void) {
    _Alignas(16) u8 actor[0x600]={0};
    _Alignas(16) u8 owner[0x600]={0};
    *(short *)(actor+0x1C)=-90;
    *(short *)(owner+0x140)=1;
    jtbl_004BF450.rotation[1][0](actor,owner);
    return !(actor[4]==1 && actor[5]==1 && actor[7]==1
             && actor[0x13C]==1 && *(short *)(actor+0x1C)==-80);
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            directory = Path(temporary)
            source, caller_source = directory / "fixture.c", directory / "caller.c"
            binary = directory / "rotation"
            source.write_text(fixture)
            caller_source.write_text(caller)
            built = subprocess.run(
                [cc, "-std=c11", "-Werror", "-Wno-unknown-pragmas",
                 "-I", str(ROOT / "src"), "-I", str(ROOT / "src/data"),
                 str(source), str(caller_source),
                 str(ROOT / "src/actor_rotation_return_0015bd40.c"),
                 "-o", str(binary)], capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_rotation_owner_reaches_the_real_callee(self):
        self.assertEqual(self.run_rotation(), 0)

    def test_substituted_owner_is_detected(self):
        self.assertNotEqual(self.run_rotation(drop_owner=True), 0)


if __name__ == "__main__":
    unittest.main()
