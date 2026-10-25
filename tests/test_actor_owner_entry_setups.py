"""Run the real unary lifecycle entries and derived-owner dispatch paths."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

from test_owner_dispatch_context import function

ROOT = Path(__file__).resolve().parents[1]


def initializer_names(path, symbol):
    text = path.read_text()
    body = re.search(symbol + r"[^=]*=\s*\{(.*)\};", text, re.S).group(1)
    return re.findall(r"func_[0-9A-F]+", body)


class ActorOwnerEntryTests(unittest.TestCase):
    def run_entries(self, substitute_actor=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        pair = initializer_names(ROOT / "src/data/jtbl_004BF960.c", "jtbl_004BF960")
        first = pair.index("func_001BE690")
        self.assertEqual(first, (0x4BF9A8 - 0x4BF960) // 4)
        pair = pair[first:first + 2]
        files = ("jtbl_0044C3B0.c", "jtbl_0044CB90.c", "jtbl_0044CBB8.c",
                 "jtbl_0044CBC8.c", "jtbl_0044CBD8.c", "jtbl_004BFA28.c")
        code = '#include "actor_owner_entry_setups.c"\n#include "actor_owner_mode_callbacks.h"\n'
        for file in files:
            code += f'#include "{file}"\n'
        code += "typedef ActorOwnerPhase OwnerPhase;\n"
        code += "extern void func_001BE690(u8 *,u8 *),func_001BE700(u8 *,u8 *);\n"
        code += "OwnerPhase const jtbl_004BF9A8[2]={" + ",".join(pair) + "};\n"
        gp = initializer_names(ROOT / "src/data/jtbl_004BFA28.c", "jtbl_004BFA28")
        code += "ActorOwnerPhase const jtbl_004BFA30[2]={" + ",".join(gp[2:]) + "};\n"
        code += "static u8 *seen_actor,*seen_owner;\nvoid func_003DAA40(void *p){seen_actor=p;}\n"
        actual = {"func_001BE590", "func_001BE640", "func_001C3F40", "func_001C4010",
                  "func_001C40B0", "func_001C42D0", "func_001C4420", "func_001C4540", "func_001C4690", "func_001BE7D0", "func_001C47C0"}
        declarations = {}
        for file in files:
            text = (ROOT / "src/data" / file).read_text()
            declarations.update(re.findall(r"extern void (func_[0-9A-F]+)\(([^)]*)\);", text))
        declarations.update({name: "u8 *,u8 *" for name in pair})
        for name, params in declarations.items():
            if name not in actual:
                named = ",".join(f"{p.strip()}arg{i}" for i, p in enumerate(params.split(",")))
                body = "seen_actor=arg0;seen_owner=arg1;" if len(params.split(",")) == 2 else ""
                code += f"void {name}({named}){{{body}}}\n"
        for file, name in (("tail_leaves.c", "func_001BE7D0"),
                           ("tail_leaves.c", "func_001C47C0"),
                           ("grok_w7_001a.c", "func_001BE640"),
                           ("n10b.c", "func_001C4010"),
                           ("composite_dispatch_heads.c", "func_001BE570"),
                           ("composite_dispatch_heads.c", "func_001C3F20"),
                           ("composite_dispatch_heads.c", "func_001C40B0"),
                           ("composite_dispatch_heads.c", "func_001C42D0"),
                           ("composite_dispatch_heads.c", "func_001C4690"),
                           ("composite_gp_dispatch_heads.c", "func_001C4420"),
                           ("composite_gp_dispatch_heads.c", "func_001C4540")):
            body = function((ROOT / "src" / file).read_text(), name)
            if substitute_actor and name in ("func_001BE640", "func_001C4010"):
                changed = body.replace("(p,q)", "(p,p)")
                self.assertNotEqual(body, changed)
                body = changed
            code += body + "\n"
        code += """
static void clear(u8 *p){int i;for(i=0;i<0x600;i++)p[i]=0;}
int main(void) {
    _Alignas(16) u8 actor[0x600],owner[0x600]={0};
    int mode,phase,i;
    const int phases[5]={3,3,2,2,3};
    for(i=0xEC;i<0x1B0;i++)owner[i]=0x51;
    owner[1]=2;owner[2]=1;owner[0x13C]=1;owner[0x24]=7;
    *(float *)(owner+0x50)=2;*(float *)(owner+0x54)=3;*(float *)(owner+0x58)=4;
    for(phase=0;phase<2;phase++) {
        clear(actor);*(u8 **)(actor+0x18)=owner;actor[5]=phase;
        seen_actor=seen_owner=0;func_001BE570(actor);
        if(seen_actor!=actor || seen_owner!=owner || actor[4]!=1)return 1;
        if(*(unsigned short *)(actor+0x26)!=0x1802 || actor[0x13C]!=0)return 2;
        if(actor[0xEC]!=0x51 || *(float *)(actor+0x58)!=4)return 3;
    }
    owner[4]=2;clear(actor);*(u8 **)(actor+0x18)=owner;seen_actor=0;
    func_001BE570(actor);
    if(seen_actor || actor[4]!=2 || actor[0x13C])return 4;
    owner[4]=0;owner[0x1E4]=0;
    for(mode=0;mode<5;mode++)for(phase=0;phase<phases[mode];phase++) {
        clear(actor);*(u8 **)(actor+0x18)=owner;actor[6]=mode;actor[7]=phase;
        seen_actor=seen_owner=0;func_001C3F20(actor);
        if(seen_actor!=actor || seen_owner!=owner || actor[4]!=1)return 5;
        if(*(unsigned short *)(actor+0x26)!=0x1C04 || actor[0x13C]!=1 || actor[0x24])return 6;
        if(actor[0x14C]!=24 || actor[0x14D]!=24 || actor[0x14E]!=16 || actor[0x14F]!=16)return 7;
    }
    owner[0x1E4]=21;owner[0x1FD]=7;owner[0x2BB]=9;
    clear(actor);*(u8 **)(actor+0x18)=owner;seen_actor=0;
    func_001C3F20(actor);
    if(seen_actor || actor[4]!=2 || actor[5] || actor[6] || actor[7]
       || actor[0x13C] || owner[0x2BB])return 8;
    clear(actor);actor[4]=3;seen_actor=0;func_001BE570(actor);
    if(seen_actor!=actor)return 9;
    clear(actor);actor[4]=3;seen_actor=0;func_001C3F20(actor);
    return seen_actor!=actor;
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            fixture, binary = path / "owner.c", path / "owner"
            fixture.write_text(code)
            built = subprocess.run(
                [cc, "-std=c11", "-Werror", "-Wno-unknown-pragmas", "-I", str(ROOT / "src"),
                 "-I", str(ROOT / "src/data"), str(fixture), "-o", str(binary)],
                capture_output=True, text=True, timeout=30,
            )
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_initializers_derive_and_forward_owner(self):
        self.assertEqual(self.run_entries(), 0)

    def test_actor_substitution_at_owner_boundary_is_detected(self):
        self.assertNotEqual(self.run_entries(substitute_actor=True), 0)


if __name__ == "__main__":
    unittest.main()
