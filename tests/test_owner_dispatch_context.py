import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TABLES = ("004761D0", "004761F0", "00476220")


def function(source, name):
    match = re.search(r"void\s+" + name + r"\s*\([^)]*\)\s*\{", source)
    if not match:
        raise AssertionError(f"Missing dispatcher {name}")
    depth = 1
    end = match.end()
    while depth:
        depth += (source[end] == "{") - (source[end] == "}")
        end += 1
    return source[match.start():end]


class OwnerDispatchContextTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.cc = shutil.which("cc")
        if cls.cc is None:
            raise unittest.SkipTest("A host C compiler is required for the dispatch fixture")

    def run_dispatch(self, drop_owner=False):
        callbacks = set()
        for table in TABLES:
            source = (ROOT / f"src/data/jtbl_{table}.c").read_text()
            callbacks.update(re.findall(r"extern void (func_[0-9A-F]+)\(", source))
        wrappers = []
        for file, name in (
            ("sc2_a.c", "func_003C81C0"),
            ("composite_dispatch_heads.c", "func_003C8310"),
            ("composite_dispatch_heads.c", "func_003C8A50"),
        ):
            body = function((ROOT / "src" / file).read_text(), name)
            if drop_owner and name == "func_003C8A50":
                changed = body.replace("(p,owner)", "(p,0)")
                self.assertNotEqual(body, changed)
                body = changed
            wrappers.append(body)
            callbacks.discard(name)
        code = '#include "mvc2_state_callbacks.h"\n'
        code += "static u8 *seen_actor; static void *seen_owner; static int seen_state;\n"
        for table in TABLES:
            code += f'#include "jtbl_{table}.c"\n'
        for name in sorted(callbacks):
            address = int(name[5:], 16)
            code += (f"void {name}(u8 *p,void *owner) {{ seen_actor=p;"
                     f"seen_owner=owner;seen_state={address}; }}\n")
        code += "\n".join(wrappers)
        code += """
int main(void) {
    _Alignas(void *) u8 actor[0x600]={0};
    _Alignas(void *) u8 owner[0x600]={0};
    *(u8 **)(actor+0x18)=owner;
    actor[4]=1; actor[5]=3; actor[6]=4;
    func_003C81C0(actor);
    return !(seen_actor==actor && seen_owner==owner && seen_state==0x3C8DD0
             && owner[0x2BF]==2 && owner[0x205]==2);
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / "dispatch.c"
            binary = Path(temporary) / "dispatch"
            source.write_text(code)
            built = subprocess.run(
                [self.cc, "-std=c11", "-Werror", "-I", str(ROOT / "src/data"),
                 str(source), "-o", str(binary)], capture_output=True, text=True,
                timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_owner_reaches_nested_state(self):
        self.assertEqual(self.run_dispatch(), 0)

    def test_dropped_owner_is_detected(self):
        self.assertNotEqual(self.run_dispatch(drop_owner=True), 0)


    def run_character_dispatch(self, drop_owner=False):
        files = ("jtbl_004492D0.c", "jtbl_00449400.c", "jtbl_004BF520.c")
        unary, owner = set(), set()
        for file in files:
            text = (ROOT / "src/data" / file).read_text()
            unary.update(re.findall(r"extern void (func_[0-9A-F]+)\(u8 \*\);", text))
            owner.update(re.findall(r"extern void (func_[0-9A-F]+)\(u8 \*, u8 \*\);", text))
        self.assertEqual(len(unary), 18)
        self.assertEqual(len(owner), 11)
        wrappers = []
        for file, name in (
            ("indirect_dispatch.c", "func_00192580"),
            ("composite_dispatch_heads.c", "func_00192BD0"),
            ("small_state_controls.c", "func_00192E00"),
            ("indirect_dispatch.c", "func_00193160"),
            ("composite_dispatch_heads.c", "func_001934E0"),
            ("composite_dispatch_heads.c", "func_00193B80"),
            ("gp_dispatch.c", "func_00190B30"),
        ):
            text = function((ROOT / "src" / file).read_text(), name)
            if drop_owner and name == "func_001934E0":
                changed = text.replace("(p,owner)", "(p,0)")
                self.assertNotEqual(text, changed)
                text = changed
            wrappers.append(text)
            unary.discard(name)
            owner.discard(name)
        code = '#include "character_owner_callbacks.h"\n'
        code += "static u8 *seen_actor,*seen_owner; static int token; u8 *D_004C26D0;\n"
        for file in files:
            code += f'#include "{file}"\n'
        for name in sorted(unary):
            code += (f"void {name}(u8 *p) {{ seen_actor=p;"
                     "seen_owner=0;token=0; }\n")
        for name in sorted(owner):
            code += (f"void {name}(u8 *p,u8 *parent) {{ seen_actor=p;"
                     "seen_owner=parent;token=parent?parent[0]:-1; }\n")
        code += "\n".join(wrappers)
        code += """
int main(void) {
    u8 actor[0x600]={0};
    u8 parent[8]={137};
    int group,index;
    void (*unary_heads[4])(u8 *)={func_00192580,func_00192BD0,
                                 func_00192E00,func_00193160};
    for(group=0;group<4;group++)for(index=0;index<4;index++) {
        actor[4]=index;actor[6]=index;seen_actor=0;token=-1;
        unary_heads[group](actor);
        if(seen_actor!=actor || token!=0)return 1;
    }
    for(index=0;index<2;index++) {
        actor[0x295]=index;seen_actor=0;token=-1;func_00190B30(actor);
        if(seen_actor!=actor || token!=0)return 2;
    }
    for(group=0;group<2;group++)for(index=0;index<(group?7:4);index++) {
        actor[4]=index;seen_actor=0;seen_owner=0;token=-1;
        jtbl_004BF520.owner[group](actor,parent);
        if(seen_actor!=actor || seen_owner!=parent || token!=137)return 3;
    }
    return 0;
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            source = Path(temporary) / "character_dispatch.c"
            binary = Path(temporary) / "character_dispatch"
            source.write_text(code)
            built = subprocess.run(
                [self.cc, "-std=c11", "-Werror", "-I", str(ROOT / "src/data"),
                 "-I", str(ROOT / "src"), str(source), "-o", str(binary)],
                capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_character_dispatch_ranges_preserve_their_inputs(self):
        self.assertEqual(self.run_character_dispatch(), 0)

    def test_character_dropped_owner_is_detected(self):
        self.assertNotEqual(self.run_character_dispatch(drop_owner=True), 0)


if __name__ == "__main__":
    unittest.main()
