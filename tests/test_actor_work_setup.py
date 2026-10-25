"""Run the real four-selector producer, dispatcher and initializer together."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

from test_owner_dispatch_context import function

ROOT = Path(__file__).resolve().parents[1]


class ActorWorkSetupTests(unittest.TestCase):
    def run_setup(self, wrong_work_pointer=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        game = (ROOT / "src/actor_work_dispatch_setup_00351060.c").read_text()
        if wrong_work_pointer:
            changed = game.replace("D_004C295C=owner+0x2b8;", "D_004C295C=owner+0x2bc;")
            self.assertNotEqual(game, changed)
            game = changed
        table = (ROOT / "src/data/jtbl_004624C0.c").read_text()
        code = game + '\n#include "jtbl_004624C0.c"\n#include "data_u32_004624E0.c"\n'
        code += "u8 *D_004C2960,*D_004C295C; float D_004624E0[4][2],D_004624E4[4][2];\n"
        code += "static _Alignas(16) u8 records[4][0x600];\n"
        code += "static int attempts,fail_at,bad,seen_group,seen_animation; static u8 *seen;\n"
        code += """
void *func_003DA750(void *list,int pool,int flags) {
    int slot=attempts++;
    if(list || pool!=1 || flags!=0 || slot>=4){bad=1;return 0;}
    return slot==fail_at ? 0 : records[slot];
}
int func_001757E0(u8 *p,int group,int animation) {
    seen=p;seen_group=group;seen_animation=animation;return 0;
}
"""
        for name in re.findall(r"extern void (func_[0-9A-F]+)\(", table):
            if name != "func_003510A0":
                code += f"void {name}(u8 *p) {{}}\n"
        code += function((ROOT / "src/wave32.c").read_text(), "func_00350FF0")
        code += """
int main(void) {
    _Alignas(16) u8 owner[0x600]={0};
    int pass,i,j;
    for(i=0xEC;i<0x1B0;i++)owner[i]=0x51;
    owner[1]=1;owner[2]=0;owner[0x30]=254;
    owner[0x1B7]=2;owner[0x1B8]=3;
    *(float *)(owner+0x34)=100;*(float *)(owner+0x38)=50;
    *(float *)(owner+0x50)=2;*(float *)(owner+0x54)=3;*(float *)(owner+0x58)=4;
    /* Host component aliases are populated from the canonical interleaved table. */
    for(i=0;i<4;i++) {
        D_004624E0[i][0]=data_u32_004624E0[2*i];
        D_004624E4[i][0]=data_u32_004624E0[2*i+1];
    }
    for(pass=0;pass<2;pass++) {
        for(i=0;i<4;i++)for(j=0;j<0x600;j++)records[i][j]=0;
        attempts=bad=0;fail_at=pass?1:-1;
        func_00350FF0(owner);
        if(attempts!=4 || bad)return 1;
        for(i=0;i<4;i++) {
            u8 *p=records[i];
            if(i==fail_at){if(*(void **)(p+0x10))return 2;continue;}
            if(p[0x20]!=i || *(u8 **)(p+0x18)!=owner)return 3;
            seen=0;
            (*(void (**)(u8 *))(p+0x10))(p);
            if(seen!=p || seen_group!=21 || seen_animation!=29+i)return 4;
            if(D_004C2960!=p+0xD0 || D_004C295C!=owner+0x2B8)return 5;
            if(p[4]!=1 || p[1]!=1 || p[2]!=0 || p[0x30]!=254)return 6;
            if(p[0xEC]!=0x51 || p[0x13C]!=1 || *(short *)(p+0x140)!=0)return 7;
            if(*(float *)(p+0x34)!=100 || *(float *)(p+0x38)!=50)return 8;
            if(*(float *)(p+0x50)!=2 || *(float *)(p+0x54)!=3 || *(float *)(p+0x58)!=4)return 9;
            if(p[0x24]!=0 || p[0x14C]!=56 || p[0x14F]!=80)return 10;
            if(*(short *)(p+0x1C)!=16 || *(short *)(p+0x1E)!=3)return 11;
            if(*(float *)(p+0x5C)!=data_u32_004624E0[2*i]
                || *(float *)(p+0x60)!=data_u32_004624E0[2*i+1])return 12;
        }
    }
    return 0;
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            source, binary = path / "work.c", path / "work"
            source.write_text(code)
            built = subprocess.run(
                [cc, "-std=c11", "-Werror", "-Wno-unknown-pragmas",
                 "-I", str(ROOT / "src/data"), str(source), "-o", str(binary)],
                capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_all_native_selectors_and_allocation_failure(self):
        self.assertEqual(self.run_setup(), 0)

    def test_wrong_owner_work_offset_is_detected(self):
        self.assertNotEqual(self.run_setup(wrong_work_pointer=True), 0)


if __name__ == "__main__":
    unittest.main()
