"""Run the actual six-effect wrapper and allocator body with host pointers."""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

class EffectPositionForwardingTests(unittest.TestCase):
    def test_full_position_and_owner_survive_six_spawns(self):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        wrapper=(ROOT/'src/h4e.c').read_text().split('extern void func_003AE900')[0]
        allocation=(ROOT/'src/m4.c').read_text()
        allocation=allocation[allocation.index('void func_00380160('):allocation.index('void func_001AD0B0(')]
        code=wrapper+r'''
#include <string.h>
static _Alignas(16) u8 objects[6][0x100];
static int calls,failed;
u8 *func_003DA750(s32 a,s32 b,s32 c) {
    int slot=calls++;
    if(a || b!=1 || c || slot>=6)return 0;
    return slot==failed?0:objects[slot];
}
void func_0037FCA0(void) {}
'''+allocation+r'''
int main(void) {
    _Alignas(16) u8 owner[0x40]={0};
    V3 position={123.5f,-27.25f,91.75f};
    int sample,i;
    for(sample=-1;sample<6;sample++) {
        calls=0;failed=sample;
        memset(objects,0xCC,sizeof(objects));
        func_003801F0(owner,&position,3);
        if(calls!=6)return 1;
        for(i=0;i<6;i++) {
            if(i==sample) {
                int j;
                for(j=0;j<0x100;j++)if(objects[i][j]!=0xCC)return 2;
            } else {
                V3 *actual=(V3*)(objects[i]+0x34);
                if(*(void**)(objects[i]+0x18)!=owner)return 3;
                if(*(void**)(objects[i]+0x10)!=(void*)func_0037FCA0)return 4;
                if(actual->x!=position.x || actual->y!=position.y || actual->z!=position.z)return 5;
                if(objects[i][0x20]!=3 || objects[i][0x21]!=i)return 6;
                if(objects[i][0x33]!=0xCC || objects[i][0x40]!=0xCC)return 7;
            }
        }
        if(position.x!=123.5f || position.y!=-27.25f || position.z!=91.75f)return 8;
    }
    return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            source=Path(temporary)/'effect.c'
            binary=Path(temporary)/'effect'
            source.write_text(code)
            result=subprocess.run([cc,'-std=c11','-Werror',str(source),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(result.returncode,0,result.stderr)
            self.assertEqual(subprocess.run([str(binary)],timeout=10).returncode,0)
