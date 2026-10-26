"""Exercise motion integration and the real event velocity helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorMotionEventTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_motion_event_00319d90.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '')
        body = body.replace('extern u8 D_0045D8F0[];', 'extern float testTable[2][4];\n#define D_0045D8F0 ((u8*)testTable)')
        if mutation == 'event':
            body = body.replace('if(*(s8*)(p+0x151))', 'if(!*(s8*)(p+0x151))')
        if mutation == 'table':
            body = body.replace('((unsigned)p[0x1B7]<<4)', '((unsigned)(1-p[0x1B7])<<4)')
        if mutation == 'facing':
            body = body.replace('if (*(s16 *)(p + 320) != 0)', 'if (*(s16 *)(p + 320) == 0)')
        code = r'''
#include <string.h>
''' + body + r'''
static Counters counters;Counters *D_004C2794=&counters;
float testTable[2][4]={{4.0f,0.5f,6.0f,1.0f},{8.0f,1.0f,10.0f,2.0f}};
static u8 *actor;static int calls,event,variant;
int func_00175700(u8*p) { if(p!=actor)return -1;calls++;p[0x151]=event;p[0x1B7]=variant;return 0; }
int main(void) {
 _Alignas(16) u8 p[0x400];int events[]={0,1,255};
 for(int team=0;team<2;team++)for(variant=0;variant<2;variant++)for(int face=0;face<2;face++)for(int e=0;e<3;e++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(&counters,0,sizeof counters);actor=p;calls=0;event=events[e];
  p[2]=team;p[6]=wrap?255:3;p[0x1B2]=9;*(u16*)(p+0x1C0)=7;*(int*)(p+0x1D8)=8;p[0x20D]=7;
  *(s16*)(p+0x140)=face;*(float*)(p+0x34)=10;*(float*)(p+0x38)=20;
  *(float*)(p+0x5C)=2;*(float*)(p+0x60)=3;*(float*)(p+0x68)=0.5f;*(float*)(p+0x6C)=1;
  counters.count[team]=wrap?32767:5;
  func_00319D90(p);
  if(calls!=1 || *(float*)(p+0x34)!=12 || *(float*)(p+0x38)!=23 || p[6]!=(u8)((wrap?255:3)+(event!=0)))return 1;
  if(event) {
   if(p[0x151] || p[0x1B5]!=(variant?86:84) || p[0x1B2] || *(u16*)(p+0x1C0) || *(int*)(p+0x1D8) ||
      counters.count[team]!=(wrap?-32768:6) || p[0x20D]!=2 ||
      *(float*)(p+0x5C)!=(face?-testTable[variant][0]:testTable[variant][0]) ||
      *(float*)(p+0x68)!=(face?-testTable[variant][1]:testTable[variant][1]) ||
      *(float*)(p+0x60)!=testTable[variant][2] || *(float*)(p+0x6C)!=testTable[variant][3])return 2;
  } else if(p[0x1B2]!=9 || *(u16*)(p+0x1C0)!=7 || *(int*)(p+0x1D8)!=8 || p[0x20D]!=7 ||
            *(float*)(p+0x5C)!=2.5f || *(float*)(p+0x60)!=4 || counters.count[team]!=(wrap?32767:5))return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_motion_and_real_helper(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_event_gate_is_rejected(self):
        self.assertNotEqual(self.run_case('event'), 0)

    def test_wrong_table_row_is_rejected(self):
        self.assertNotEqual(self.run_case('table'), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)
