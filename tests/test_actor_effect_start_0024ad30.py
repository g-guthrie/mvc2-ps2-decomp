"""Exercise the effect-start callback through its native dispatch entry."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorEffectStart0024ad30Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_effect_start_0024ad30.c').read_text()
        changes = {'position': ('85.7142791748046875f', '84.7142791748046875f'),
                   'animation': ('func_001757E0(p,19,2)', 'func_001757E0(p,19,3)')}
        if mutation:
            old, new = changes[mutation]
            self.assertIn(old, body)
            body = body.replace(old, new, 1)
        root = states.function('src/composite_dispatch_heads.c', 'func_0024AD10')
        code = r"""
#include <string.h>
""" + body + r"""
static u8 *actor; static int seq,fail;
void func_00175C00(u8*p,int n){if(p!=actor || n!=0 || ++seq!=1 || p[7]!=1)fail++;}
void func_00176160(u8*p,int a,int b,int c){if(p!=actor || a!=5 || b!=1 || c!=1 || ++seq!=2)fail++;}
void func_0015B200(O*o,V3*v,u8 n,unsigned short flags){
 u8*p=(u8*)o; if(p!=actor || ++seq!=3 || n!=1 || flags!=8 || v->x!=123.0f || v->y!=200.0f+85.7142791748046875f ||
 *(float*)(p+0x38)!=200.0f || *(float*)(p+0x5C)!=0 || *(float*)(p+0x60)!=0 ||
 *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0 || p[0x210] || p[0x20D])fail++;
}
void func_001E3710(u8*p,u8 n){if(p!=actor || n!=74 || ++seq!=4)fail++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor || a!=19 || b!=2 || ++seq!=5)fail++;return 0;}
void func_0024AE10(u8*p){if(p!=actor || ++seq!=6)fail++;}
void (*const jtbl_00452F90[])(u8*)={func_0024AD30};
""" + root + r"""
int main(void) {
 _Alignas(16) u8 p[0x500];
 for(int face=0;face<2;face++) {
  memset(p,0,sizeof p);actor=p;seq=fail=0;
  *(short*)(p+0x140)=face;*(float*)(p+0x34)=123;*(float*)(p+0x38)=20;*(float*)(p+0x430)=200;
  *(float*)(p+0x5C)=1;*(float*)(p+0x60)=2;*(float*)(p+0x68)=3;*(float*)(p+0x6C)=4;p[0x210]=1;p[0x20D]=1;
  func_0024AD10(p);if(fail||seq!=6)return 1;
 }
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_effect_start(self):
        self.assertEqual(self.run_case(), 0)

    def test_bad_position_is_rejected(self):
        self.assertNotEqual(self.run_case('position'), 0)

    def test_bad_animation_is_rejected(self):
        self.assertNotEqual(self.run_case('animation'), 0)
