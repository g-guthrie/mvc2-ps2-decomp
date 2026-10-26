"""Exercise palette selection and actor setup through the real dispatch entry."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorPaletteStart0030a6d0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_palette_start_0030a6d0.c').read_text().replace(' __attribute__((section(".sdata")))', '')
        changes = {'palette': ('func_00176160(p,1,32,1)', 'func_00176160(p,1,31,1)'),
                   'height': ('381.428558349609375f', '380.428558349609375f')}
        if mutation:
            old,new=changes[mutation]
            self.assertIn(old,body)
            body=body.replace(old,new,1)
        root=states.function('src/composite_dispatch_heads.c','func_0030A6B0')
        code=r"""
#include <string.h>
""" + body + r"""
u8 *D_004C28DC;
static u8 *actor;static int seq,fail,mode;
void func_00176160(u8*p,int bank,int index,int count){
 int expected=(mode?32:35)+seq;
 if(p!=actor || D_004C28DC!=p+0x2B8 || bank!=seq+1 || index!=expected || count!=1 || seq>=2)fail++;
 seq++;
}
void func_001DB320(u8*p){if(p!=actor || seq++!=2 || D_004C28DC[7]!=0 || p[6]!=1 || p[0x13C]!=1 ||
 *(float*)(p+0x38)!=500.0f-381.428558349609375f || *(float*)(p+0x5C)!=0 ||
 *(float*)(p+0x60)!=8.5714282989501953125f || *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0 ||
 *(s16*)(p+0x1C)!=0 || *(s16*)(p+0x1E)!=4)fail++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor || a!=18 || b!=0 || seq++!=3)fail++;return 0;}
void (*const jtbl_0045CE90[])(u8*)={func_0030A6D0};
""" + root + r"""
int main(void){
 _Alignas(16) u8 p[0x500];
 for(mode=0;mode<2;mode++){
  memset(p,0,sizeof p);actor=p;seq=fail=0;p[0x25]=mode;p[0x2BF]=9;
  *(float*)(p+0x430)=500;*(float*)(p+0x5C)=2;*(float*)(p+0x60)=2;*(float*)(p+0x68)=2;*(float*)(p+0x6C)=2;
  func_0030A6B0(p);if(fail || seq!=4)return 1;
 }
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_setup_both_palette_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_bad_palette_is_rejected(self):
        self.assertNotEqual(self.run_case('palette'),0)

    def test_bad_height_is_rejected(self):
        self.assertNotEqual(self.run_case('height'),0)
