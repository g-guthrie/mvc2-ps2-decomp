"""Exercise the verified ground comparison, including unordered floats."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorGroundBounce00374210Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_ground_bounce_00374210.c').read_text()
        if mutation == 'unordered':
            body = body.replace('!(*(float*)(p+0xD4)<*(float*)(p+0x38))', '(*(float*)(p+0x38)<=*(float*)(p+0xD4))')
        if mutation == 'boundary':
            body = body.replace('*(float*)(p+0xD4)<*(float*)(p+0x38)', '*(float*)(p+0xD4)<=*(float*)(p+0x38)')
        if mutation == 'phase':
            body = body.replace('++p[6]', 'p[6]+=2')
        dispatch = states.function('src/grok_kk_3741e0.c','func_003741E0').replace('p + 24', 'p + 0x500')
        code = r'''
#include <string.h>
''' + body + r'''
void (*const jtbl_00463EE0[])(u8*)={func_00374210};
''' + dispatch + r'''
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x300];union {unsigned int bits;float value;} nan={0x7FC00000u};
 float heights[]={49,50,51,0};heights[3]=nan.value;
 for(int h=0;h<4;h++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);*(u8**)(p+0x500)=owner;p[6]=wrap?255:0;
  *(float*)(p+0x34)=10;*(float*)(p+0x38)=heights[h];*(float*)(p+0xD4)=50;
  *(float*)(p+0x5C)=2;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0.5f;*(float*)(p+0x6C)=1;
  *(s16*)(p+0x1C)=9;
  if(wrap)func_00374210(p);else func_003741E0(p);
  int landing=!(50.0f<heights[h]);
  if(*(float*)(p+0x34)!=12 || p[6]!=(u8)((wrap?255:0)+landing) || owner[510]!=(wrap?0:1))return 1;
  if(landing) {
   if(*(float*)(p+0x38)!=50 || *(s16*)(p+0x1C)!=5 || *(float*)(p+0x5C)!=0 ||
      *(float*)(p+0x68)!=0 || *(float*)(p+0x60)!=3.2142856121063232f || *(float*)(p+0x6C)!=-0.234375f)return 2;
  } else if(*(float*)(p+0x38)!=heights[h] || *(s16*)(p+0x1C)!=9 || *(float*)(p+0x5C)!=2.5f ||
            *(float*)(p+0x68)!=0.5f || *(float*)(p+0x60)!=1 || *(float*)(p+0x6C)!=1)return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_dispatch_landing_and_unordered_comparison(self):
        self.assertEqual(self.run_case(), 0)

    def test_unordered_comparison_is_distinct(self):
        self.assertNotEqual(self.run_case('unordered'), 0)

    def test_ground_boundary_is_checked(self):
        self.assertNotEqual(self.run_case('boundary'), 0)

    def test_phase_increment_is_checked(self):
        self.assertNotEqual(self.run_case('phase'), 0)
