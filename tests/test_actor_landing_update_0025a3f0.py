"""Test landing, animation order and the real sound-position helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorLandingUpdate0025a3f0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_landing_update_0025a3f0.c').read_text()
        if mutation == 'boundary':
            body = body.replace('*(float*)(p+0x38)<*(float*)(p+0x430)', '*(float*)(p+0x38)<=*(float*)(p+0x430)')
        if mutation == 'velocity':
            body = body.replace('*(float*)(p+0x5C)+=*(float*)(p+0x68);', '*(float*)(p+0x5C)-=*(float*)(p+0x68);')
        if mutation == 'sound':
            body = body.replace('func_00183D50(p);func_001757E0(p,22,5);', 'func_001757E0(p,22,5);func_00183D50(p);')
        code = r'''
#include <string.h>
typedef float f32;typedef int s32;
extern void func_001E3A70(unsigned char*),func_00154390(float*,int);
''' + body + states.function('src/grok_w5_0018.c','func_00183D50') + r'''
static u8 *actor;static int stage,wrong,land;
void func_001E3A70(u8*p) {
 if(p!=actor || stage++!=0 || !land || *(float*)(p+0x38)!=50 || *(float*)(p+0x5C)!=0 ||
    *(float*)(p+0x60)!=0 || *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0)wrong++;
 *(float*)(p+0x34)=20;
}
void func_00154390(float*v,int mode) {if(stage++!=1 || mode || v[0]!=10 || v[1]!=50 || v[2]!=99)wrong++;}
int func_001757E0(u8*p,int a,int b) {
 if(p!=actor || stage++!=2 || a!=22 || b!=5)wrong++;
 *(float*)(p+0x5C)=4;*(float*)(p+0x60)=5;*(float*)(p+0x68)=1;*(float*)(p+0x6C)=2;return 0;
}
int func_00175700(u8*p) {if(p!=actor || stage++!=(land?3:0))wrong++;*(float*)(p+0x5C)+=1;return 0;}
int main(void) {
 _Alignas(16) u8 p[0x500];int counts[]={-1,0,1};float heights[]={49,50,55};
 for(int count=0;count<3;count++)for(int h=0;h<3;h++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);actor=p;stage=wrong=0;land=(h==0);p[6]=wrap?255:7;
  p[0x40C]=9;p[0x40D]=9;p[0x33B]=7;p[0x33C]=8;p[0x20D]=6;*(s16*)(p+0x2B8)=counts[count];
  *(float*)(p+0x34)=10;*(float*)(p+0x38)=heights[h];*(float*)(p+0x3C)=99;*(float*)(p+0x430)=50;
  *(float*)(p+0x5C)=2;*(float*)(p+0x60)=3;*(float*)(p+0x68)=0.5f;*(float*)(p+0x6C)=1;
  func_0025A3F0(p);
  if(wrong || stage!=(land?4:1) || p[6]!=(u8)((wrap?255:7)+land) || p[0x40C] || p[0x40D] ||
     p[0x33B]!=(counts[count]>0?7:0) || p[0x33C]!=(counts[count]>0?5:0) ||
     p[0x20D]!=(land?0:6) || *(float*)(p+0x34)!=(land?25:13) ||
     *(float*)(p+0x38)!=(land?55:heights[h]+3) || *(float*)(p+0x5C)!=(land?6:3.5f) ||
     *(float*)(p+0x60)!=(land?7:4))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_landing_and_airborne_paths(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_landing_boundary_is_rejected(self):
        self.assertNotEqual(self.run_case('boundary'), 0)

    def test_wrong_velocity_update_is_rejected(self):
        self.assertNotEqual(self.run_case('velocity'), 0)

    def test_wrong_callback_order_is_rejected(self):
        self.assertNotEqual(self.run_case('sound'), 0)
