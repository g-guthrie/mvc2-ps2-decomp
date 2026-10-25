"""Exercise the real work-pointer producer and inherited phase dispatcher."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class ActorEffectWorkContextTests(unittest.TestCase):
    def run_dispatch(self, substitute_owner=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        game = (ROOT / "src/actor_work_inherit_dispatch_0019e670.c").read_text()
        if substitute_owner:
            changed = game.replace("(p,work)", "(p,OWNER)")
            self.assertNotEqual(game, changed)
            game = changed
        parent = (ROOT / "src/data/jtbl_0044ABA0.c").read_text()
        initializer = re.search(r"jtbl_0044ABA0[^=]*=\s*\{(.*)\};", parent, re.S).group(1)
        entries = re.findall(r"func_[0-9A-F]+", initializer)
        first = entries.index("func_0019E670")
        self.assertEqual(first, (0x44AC10 - 0x44ABA0) // 4)
        work_entries = entries[first:first + 4]
        self.assertEqual(len(work_entries), 4)
        phase_table = (ROOT / "src/data/jtbl_0044ACC0.c").read_text()
        phase_initializer = re.search(r"jtbl_0044ACC0[^=]*=\s*\{(.*)\};", phase_table, re.S).group(1)
        phases = re.findall(r"(?:func|residual)_[0-9A-F]+", phase_initializer)
        self.assertEqual(len(phases), 11)
        code = game + '\n#include "jtbl_0044ACC0.c"\n'
        code += "static u8 *seen_actor,*seen_work;static int seen_phase;\n"
        for index, name in enumerate(phases):
            code += (f"void {name}(u8 *p,u8 *work) {{seen_actor=p;"
                     f"seen_work=work;seen_phase={index};}}\n")
        for name in work_entries[1:]:
            code += f"void {name}(u8 *p,u8 *work) {{}}\n"
        code += "ActorEffectWorkCallback const jtbl_0044AC10[4]={" + ",".join(work_entries) + "};\n"
        code += (ROOT / "src/grok_jr_19dfd0.c").read_text()
        code += """
int main(void) {
    _Alignas(16) u8 actor[0x600],owner[0x600]={0};
    int mode,i;
    for(i=0xEC;i<0x1B0;i++)owner[i]=0x6D;
    owner[1]=4;owner[2]=1;owner[0x24]=249;owner[0x30]=250;
    owner[0x1B7]=2;owner[0x1B8]=3;
    *(float *)(owner+0x50)=2;*(float *)(owner+0x54)=3;*(float *)(owner+0x58)=4;
    for(mode=0;mode<11;mode++) {
        for(i=0;i<0x600;i++)actor[i]=0;
        *(u8 **)(actor+0x18)=owner;
        actor[0x20]=mode;seen_actor=seen_work=0;seen_phase=-1;
        func_0019DFD0(actor);
        if(seen_actor!=actor || seen_work!=actor+0x88 || seen_phase!=mode)return 1;
        if(actor[4]!=1 || actor[0x13C]!=1 || actor[0xEC]!=0x6D)return 2;
        if(actor[1]!=4 || actor[2]!=1 || actor[0x24]!=249 || actor[0x30]!=250)return 3;
        if(actor[0x1B7]!=2 || actor[0x1B8]!=3)return 4;
        if(*(float *)(actor+0x50)!=2 || *(float *)(actor+0x54)!=3 || *(float *)(actor+0x58)!=4)return 5;
    }
    return 0;
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            fixture, binary = path / "work.c", path / "work"
            fixture.write_text(code)
            built = subprocess.run(
                [cc, "-std=c11", "-Werror", "-I", str(ROOT / "src"),
                 "-I", str(ROOT / "src/data"), str(fixture), "-o", str(binary)],
                capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_work_pointer_survives_inheritance_for_all_modes(self):
        self.assertEqual(self.run_dispatch(), 0)

    def test_replacing_work_with_owner_is_detected(self):
        self.assertNotEqual(self.run_dispatch(substitute_owner=True), 0)


if __name__ == "__main__":
    unittest.main()
