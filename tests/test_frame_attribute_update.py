"""Check native frame selection, three attribute words and byte rollover."""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class FrameAttributeUpdateTests(unittest.TestCase):
    def run_update(self, wrong_keep_mask=False):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("A host C compiler is required")
        code = (ROOT / "src/frame_attribute_update_001b5a40.c").read_text()
        if wrong_keep_mask:
            changed = code.replace("keep=0x9FFF", "keep=0xFFFF")
            self.assertNotEqual(code, changed)
            code = changed
        code += "\nFrame D_004F54D0[6];\n"
        code += """
int main(void) {
    const short frames[4]={-2,-1,0,2};
    const u8 counters[3]={0,254,255};
    const u16 initial[3]={0x0123,0x6A5A,0xFFFF};
    _Alignas(16) u8 actor[0x600]={0},owner[0x600]={0};
    int sample,counter,i,j,selected;
    *(u8 **)(actor+0x18)=owner;
    for(sample=0;sample<4;sample++)for(counter=0;counter<3;counter++) {
        for(i=0;i<6;i++) {
            D_004F54D0[i].dirty=0x12340000u+i;
            for(j=0;j<3;j++)D_004F54D0[i].flags[j]=initial[j];
            D_004F54D0[i].pre8[0]=0xAB;
            D_004F54D0[i].pre12[0]=0xCD;
            D_004F54D0[i].tail[0]=0xEF;
        }
        *(short *)(owner+0x13E)=frames[sample];selected=frames[sample]+2;
        actor[6]=counters[counter];actor[0x13C]=1;actor[4]=9;
        func_001B5A40(actor);
        if(actor[6]!=(u8)(counters[counter]+1) || actor[0x13C] || actor[4]!=9)return 1;
        for(i=0;i<6;i++) {
            if(D_004F54D0[i].dirty!=(i==selected?1u:0x12340000u+i))return 2;
            for(j=0;j<3;j++) {
                u16 expected=i==selected?(initial[j]&0x0FFFu)|0x9000u:initial[j];
                if(D_004F54D0[i].flags[j]!=expected)return 3;
            }
            if(D_004F54D0[i].pre8[0]!=0xAB || D_004F54D0[i].pre12[0]!=0xCD
               || D_004F54D0[i].tail[0]!=0xEF)return 4;
        }
    }
    return 0;
}
"""
        with tempfile.TemporaryDirectory() as temporary:
            path = Path(temporary)
            source, binary = path / "frame.c", path / "frame"
            source.write_text(code)
            built = subprocess.run([cc, "-std=c11", "-Werror", str(source), "-o", str(binary)],
                                   capture_output=True, text=True, timeout=30)
            self.assertEqual(built.returncode, 0, built.stderr)
            return subprocess.run([str(binary)], timeout=10).returncode

    def test_only_the_selected_native_frame_is_updated(self):
        self.assertEqual(self.run_update(), 0)

    def test_wrong_attribute_keep_mask_is_detected(self):
        self.assertNotEqual(self.run_update(wrong_keep_mask=True), 0)


if __name__ == "__main__":
    unittest.main()
