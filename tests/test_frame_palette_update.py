"""Exercise native frame selection, untouched attributes and the early exit."""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

class FramePaletteUpdateTests(unittest.TestCase):
    def run_update(self, broken=False):
        cc = shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        code = (ROOT / 'src/frame_palette_update_0021d280.c').read_text()
        if broken:
            changed = code.replace('attribute&=0xFFF', 'attribute&=0xFFFF')
            self.assertNotEqual(changed, code)
            code = changed
        code += r'''
Frame D_004F54D0[7];
int main(void) {
    _Alignas(16) u8 actor[0x300]={0};
    int frame, skip, i, j, selected;
    for(frame=-1;frame<=3;frame++)for(skip=0;skip<2;skip++) {
        selected=frame+1;
        for(i=0;i<7;i++) {
            D_004F54D0[i].dirty=100+i;
            for(j=0;j<16;j++)D_004F54D0[i].attributes[j]=0xA000+i*16+j;
            for(j=0;j<8;j++)D_004F54D0[i].pre8[j]=0x67;
            for(j=0;j<4;j++)D_004F54D0[i].pre10[j]=0x89;
        }
        if(skip)D_004F54D0[selected].attributes[1]=0xC000+selected*16+1;
        *(s16*)(actor+0x13e)=frame;
        actor[0x2c6]=7;
        func_0021D280(actor);
        if(actor[0x2c6]!=(skip?7:1))return 1;
        for(i=0;i<7;i++) {
            int updated=!skip && (i==selected || i==selected+1);
            if(D_004F54D0[i].dirty!=(updated?1u:100u+i))return 2;
            for(j=0;j<16;j++) {
                u16 expected=0xA000+i*16+j;
                if(updated && j)expected=0xC000+i*16+j;
                if(skip && i==selected && j==1)expected=0xC000+i*16+j;
                if(D_004F54D0[i].attributes[j]!=expected)return 3;
            }
            for(j=0;j<8;j++)if(D_004F54D0[i].pre8[j]!=0x67)return 4;
            for(j=0;j<4;j++)if(D_004F54D0[i].pre10[j]!=0x89)return 5;
        }
    }
    return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            source=Path(temporary)/'test.c'
            binary=Path(temporary)/'test'
            source.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror',str(source),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            return subprocess.run([str(binary)],timeout=10).returncode

    def test_two_adjacent_frames_and_early_exit(self):
        self.assertEqual(self.run_update(),0)

    def test_failure_to_clear_old_palette_is_detected(self):
        self.assertNotEqual(self.run_update(broken=True),0)
