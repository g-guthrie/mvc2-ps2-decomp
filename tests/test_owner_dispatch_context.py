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


    def run_edge_dispatch(self, drop_owner=False):
        table = (ROOT / "src/data/jtbl_0044CD60.c").read_text()
        source = (ROOT / "src/composite_dispatch_heads.c").read_text()
        heads = [function(source, name) for name in ("func_001C67F0", "func_001C6AC0")]
        if drop_owner:
            changed = heads[1].replace("(p,owner)", "(p,wrong_owner)")
            self.assertNotEqual(heads[1], changed)
            heads[1] = changed
        code = '#include "edge_owner_phase_tables.h"\n#include "jtbl_0044CD60.c"\n'
        code += "static u8 *seen_actor,*seen_owner; u8 wrong_owner[0x600];\n"
        code += "float D_004F1FC8=800,D_004F1FCC=0,D_004F1FD0=0;\n"
        code += "int func_001757E0(u8 *p,int a,int b){return 0;}\n"
        code += "void func_0015E630(u8 *p){}\n"
        for name in re.findall(r"extern void (func_[0-9A-F]+)\(", table):
            if name != "func_001C6AE0":
                code += (f"void {name}(u8 *p,u8 *owner) {{"
                         "seen_actor=p;seen_owner=owner;}\n")
        code += "\n".join(heads)
        code += """
int main(void) {
    _Alignas(16) u8 actor[0x600]={0},owner[0x600]={0};
    *(float *)(owner+0x430)=100;
    func_001C67F0(actor,owner);
    if(seen_actor!=actor || seen_owner!=owner)return 1;
    seen_actor=seen_owner=0;
    func_001C6AC0(actor,owner);
    return !(seen_actor==actor && seen_owner==owner && actor[7]==1
             && *(short *)(actor+0x140)==1 && actor[0x24]==0
             && *(float *)(actor+0x34)==720.0f
             && *(float *)(actor+0x38)>104.28f
             && *(float *)(actor+0x38)<104.29f);
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            fixture, binary = path / "edge.c", path / "edge"
            fixture.write_text(code)
            built = subprocess.run(
                [self.cc, "-std=c11", "-Werror", "-I", str(ROOT / "src"),
                 "-I", str(ROOT / "src/data"), str(fixture),
                 str(ROOT / "src/owner_height_edge_entry_001c6ae0.c"),
                 "-o", str(binary)], capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_edge_owner_reaches_both_native_phase_groups(self):
        self.assertEqual(self.run_edge_dispatch(), 0)

    def test_edge_substituted_owner_is_detected(self):
        self.assertNotEqual(self.run_edge_dispatch(drop_owner=True), 0)


    def run_interaction_dispatch(self, drop_owner=False):
        table = (ROOT / "src/data/jtbl_00461F00.c").read_text()
        controller = (ROOT / "src/grok_ke_348f20.c").read_text()
        if drop_owner:
            changed = controller.replace("(p,q)", "(p,wrong_owner)")
            self.assertNotEqual(controller, changed)
            controller = "extern unsigned char wrong_owner[];\n" + changed
        code = '#include "interaction_state_callbacks.h"\n#include "jtbl_00461F00.c"\n'
        code += "u8 wrong_owner[0x600]; static u8 *seen_actor,*seen_owner;\n"
        code += "static u8 counters[0x100]; u8 *D_004C2794=counters;\n"
        code += "int func_001757E0(u8 *p,int a,int b){return 0;}\n"
        for name in re.findall(r"extern void (func_[0-9A-F]+)\(", table):
            if name != "func_00348F50":
                code += (f"void {name}(u8 *p,u8 *owner) {{"
                         "seen_actor=p;seen_owner=owner;}\n")
        code += "void func_00348F20(u8 *);\n"
        code += """
int main(void) {
    _Alignas(16) u8 actor[0x600]={0},owner[0x600]={0};
    *(u8 **)(actor+0x18)=owner;
    *(unsigned short *)(owner+0x168)=0x1234;
    actor[4]=4;
    func_00348F20(actor);
    return !(seen_actor==actor && seen_owner==owner
             && *(unsigned short *)(actor+0x88)==0x1234
             && actor[0x1B5]==0x45 && actor[0x168]==0x1D
             && actor[0x31]==252 && *(short *)(counters+0x7C)==1
             && *(float *)(actor+0x5C)<-146.66f
             && *(float *)(actor+0x60)>100.71f);
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            fixture, head, binary = path / "interaction.c", path / "head.c", path / "interaction"
            fixture.write_text(code)
            head.write_text(controller)
            built = subprocess.run(
                [self.cc, "-std=c11", "-Werror", "-I", str(ROOT / "src"),
                 "-I", str(ROOT / "src/data"), str(fixture), str(head),
                 str(ROOT / "src/interaction_high_launch_00348f50.c"),
                 "-o", str(binary)], capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_interaction_owner_reaches_the_real_launch(self):
        self.assertEqual(self.run_interaction_dispatch(), 0)

    def test_interaction_substituted_owner_is_detected(self):
        self.assertNotEqual(self.run_interaction_dispatch(drop_owner=True), 0)


    def run_inherited_effect(self, drop_owner=False):
        table = (ROOT / "src/data/jtbl_004634F0.c").read_text()
        phases = (ROOT / "src/grok_ic_361310.c").read_text()
        bodies = [function(phases, name) for name in ("func_00361310", "func_00361340")]
        if drop_owner:
            changed = bodies[1].replace("func_00361880(p,owner)",
                                       "func_00361880(p,wrong_owner)")
            self.assertNotEqual(bodies[1], changed)
            bodies[1] = changed
        code = '#include "inherited_effect_phase_tables.h"\n#include "jtbl_004634F0.c"\n'
        code += '#include "inherited_effect_entry_003611d0.c"\n'
        code += "static _Alignas(16) u8 stats[0x100]; G3c *D_004C2794=(G3c *)stats;\n"
        code += "u8 wrong_owner[0x600]; static u8 *seen_actor;\n"
        code += "int func_001757E0(u8 *p,int a,int b){return 0;}\n"
        code += "void func_003610F0(u8 *p,int a,int b){seen_actor=p;}\n"
        code += "void func_00361880(u8 *,u8 *);\n"
        actual = {"func_003611D0", "func_00361310", "func_00361340"}
        for name in re.findall(r"extern void (func_[0-9A-F]+)\(", table):
            if name not in actual:
                code += f"void {name}(u8 *p,u8 *owner) {{}}\n"
        code += "\n".join(bodies)
        code += function((ROOT / "src/pw24_a.c").read_text(), "func_00361880")
        code += function((ROOT / "src/composite_dispatch_heads.c").read_text(), "func_003611B0")
        code += """
int main(void) {
    _Alignas(16) u8 actor[0x600]={0},owner[0x600]={0};
    *(float *)(owner+0x34)=100;
    *(float *)(owner+0x38)=50;
    *(float *)(owner+0x3C)=123;
    *(float *)(owner+0x50)=2;
    *(float *)(owner+0x54)=3;
    *(float *)(owner+0x58)=4;
    *(short *)(owner+0x140)=1;
    owner[0x24]=7;
    func_003611B0(actor,owner);
    return !(seen_actor==actor && actor[4]==1 && actor[5]==1
             && actor[0x24]==7 && actor[0x31]==255 && actor[0x1B5]==14
             && *(short *)(stats+0x7C)==1 && *(float *)(actor+0x3C)==123
             && *(float *)(actor+0x34)>311.66f && *(float *)(actor+0x34)<311.67f
             && *(float *)(actor+0x38)>255.71f && *(float *)(actor+0x38)<255.72f
             && *(float *)(actor+0x54)==3 && *(float *)(actor+0x58)==4);
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            fixture, binary = path / "inherited.c", path / "inherited"
            fixture.write_text(code)
            built = subprocess.run(
                [self.cc, "-std=c11", "-Werror", "-I", str(ROOT / "src"),
                 "-I", str(ROOT / "src/data"), str(fixture), "-o", str(binary)],
                capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_inherited_effect_owner_reaches_position_helper(self):
        self.assertEqual(self.run_inherited_effect(), 0)

    def test_inherited_effect_substituted_owner_is_detected(self):
        self.assertNotEqual(self.run_inherited_effect(drop_owner=True), 0)


if __name__ == "__main__":
    unittest.main()
