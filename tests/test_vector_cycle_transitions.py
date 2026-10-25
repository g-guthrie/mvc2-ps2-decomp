"""Exercise the real cycle callbacks, their tables and their update helpers."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

from test_owner_dispatch_context import function

ROOT = Path(__file__).resolve().parents[1]


class VectorCycleTests(unittest.TestCase):
    def build_run(self, code, data=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            source, binary = path / "fixture.c", path / "fixture"
            source.write_text(code)
            args = [cc, "-std=c11", "-Werror", "-I", str(ROOT / "src"),
                    "-I", str(ROOT / "src/data"), str(source)]
            if data:
                for name, address in (("data_v3_basis_004B3ED0", "004B3ED0"),
                                      ("data_v3_motion_targets_004B3F80", "004B3F80"),
                                      ("data_v3_motion_targets_004B3FB0", "004B3FB0")):
                    args += [f"-D{name}=D_{address}", str(ROOT / "src/data" / f"{name}.c")]
            built = subprocess.run(args + ["-o", str(binary)], capture_output=True,
                                   text=True, timeout=30)
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def run_cycles(self, lose_byte_wrap=False):
        code = (ROOT / "src/vector_cycle_transitions.c").read_text()
        if lose_byte_wrap:
            code, count = re.subn(r"p->key\+\+;\s*p->key=\(u32\)p->key%3;",
                                  "p->key=(u32)(p->key+1)%3;", code)
            self.assertEqual(count, 3)
        table = (ROOT / "src/data/jtbl_004BF450.c").read_text()
        code += '\n#include "jtbl_004BF450.c"\ntypedef float f32;\n'
        helpers = (ROOT / "src/grok_size54.c").read_text()
        code += re.search(r"^#define F.*", helpers, re.MULTILINE).group(0) + "\n"
        for name, file in (("func_001615D0", "grok_size54.c"),
                           ("func_00161820", "grok_size54.c"),
                           ("func_00161A70", "grok_w4_sz54.c")):
            code += function((ROOT / "src" / file).read_text(), name) + "\n"
        actual = {"func_00161530", "func_00161780", "func_001619D0",
                  "func_001615D0", "func_00161820", "func_00161A70"}
        for name, params in re.findall(r"extern void (func_[0-9A-F]+)\(([^)]*)\);", table):
            if name not in actual:
                named = ", ".join(f"{p.strip()}arg{i}" for i, p in enumerate(params.split(",")))
                code += f"void {name}({named}) {{}}\n"
        code += """
static int near(float a,float b){float d=a-b;return d>-0.00001f && d<0.00001f;}
int main(void) {
    const u8 seeds[4]={0,1,2,255},expected[4]={1,2,0,0};
    V3 *tables[3]={D_004B3ED0,D_004B3F80,D_004B3FB0};
    int group,seed,tick;
    for(group=0;group<3;group++)for(seed=0;seed<4;seed++) {
        Transition state={0};
        V3 target=tables[group][expected[seed]],step;
        float dx,dy,dz;
        state.key=seeds[seed];state.current=(V3){0.2f,0.3f,0.4f};
        state.reserved64[0]=0xA5;
        step=(V3){(target.x-0.2f)/20.0f,(target.y-0.3f)/20.0f,(target.z-0.4f)/20.0f};
        jtbl_004BF450.meter[group][0]((u8 *)&state);
        if(state.key!=expected[seed] || state.phase!=1 || state.timer!=19)return 1;
        dx=group==2?state.movementX:state.delta.x;
        dy=group==2?state.movementY:state.delta.y;
        dz=group==2?state.movementZ:state.delta.z;
        if(!near(dx,step.x) || !near(dy,step.y) || !near(dz,step.z))return 2;
        if(!near(state.current.x,0.2f+step.x) || state.reserved64[0]!=0xA5)return 3;
        for(tick=0;tick<19;tick++)jtbl_004BF450.meter[group][1]((u8 *)&state);
        if(state.timer!=0 || state.phase!=1)return 4;
        if(!near(state.current.x,target.x) || !near(state.current.y,target.y)
           || !near(state.current.z,target.z))return 5;
        jtbl_004BF450.meter[group][1]((u8 *)&state);
        if(state.phase!=0 || state.timer!=0)return 6;
    }
    return 0;
}
"""
        return self.build_run(code, data=True)

    def test_all_three_cycles_and_native_byte_wrap(self):
        self.assertEqual(self.run_cycles(), 0)

    def test_moving_remainder_before_byte_wrap_is_detected(self):
        self.assertNotEqual(self.run_cycles(lose_byte_wrap=True), 0)

    def run_height_caller(self, wrong_actor=False):
        body = function((ROOT / "src/q8_b.c").read_text(), "func_001C1590")
        if wrong_actor:
            changed = body.replace("func_001C1630(p);", "func_001C1630(q);")
            self.assertNotEqual(body, changed)
            body = changed
        code = "typedef unsigned char u8;typedef signed char s8;typedef float f32;\n"
        code += "static u8 *seen;void func_001C1630(u8 *p){seen=p;}\n" + body
        code += """
int main(void) {
    _Alignas(16) u8 actor[0x600]={0},owner[0x600]={0};
    *(u8 **)(actor+0x18)=owner;
    owner[6]=2;owner[0x24]=7;actor[0x20]=1;
    func_001C1590(actor);
    if(seen!=actor || actor[0x24]!=7)return 1;
    seen=0;owner[6]=3;actor[0x13C]=1;
    func_001C1590(actor);
    if(seen || actor[4]!=2 || actor[0x13C])return 2;
    owner[6]=2;actor[0x20]=0;*(float *)(owner+0x38)=12;
    func_001C1590(actor);
    return seen || *(float *)(actor+0x38)<316.28f || *(float *)(actor+0x38)>316.29f;
}
"""
        return self.build_run(code)

    def test_height_caller_passes_the_actor(self):
        self.assertEqual(self.run_height_caller(), 0)

    def test_height_caller_owner_substitution_is_detected(self):
        self.assertNotEqual(self.run_height_caller(wrong_actor=True), 0)


if __name__ == "__main__":
    unittest.main()
