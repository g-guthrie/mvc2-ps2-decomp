"""Exercise the dash setup's observable state and callback order."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorDashSetupTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_dash_setup_002f0110.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '')
        if mutation == 'facing':
            body = body.replace('if(p[0x1E6])', 'if(p[0x1E7])')
        if mutation == 'signed':
            body = body.replace('*(s8*)(p+0x152)', '*(u8*)(p+0x152)')
        code = r'''
#include <string.h>
''' + body + r'''
static Counters counters;
Counters *D_004C2794 = &counters;
static u8 *actor; static int stage, wrong, face;
void func_00183D10(u8 *p) { if(p!=actor || stage++!=0) wrong++; }
int func_001757E0(u8 *p,int a,int b) {
 if(p!=actor || stage++!=1 || a!=21 || b!=11) wrong++;
 if(*(float*)(p+0x5C)!=(face ? 6.666666507720947f : -6.666666507720947f)) wrong++;
 p[0x152]=0xFE; return 0;
}
void func_003A8B10(u8 *p) { if(p!=actor || stage++!=2 || *(int*)(p+0x2EC)!=-2) wrong++; }
void func_0018C4B0(u8 *p,int n) { if(p!=actor || n!=10 || stage++!=3) wrong++; }
void func_002F01E0(SS *p) { if((u8*)p!=actor || stage++!=4) wrong++; }
int main(void) {
 _Alignas(16) u8 p[0x500];
 for(int team=0;team<2;team++) for(face=0;face<2;face++) {
  memset(p,0,sizeof p); memset(&counters,0,sizeof counters); actor=p;stage=wrong=0;
  p[2]=team; p[6]=255; p[0x1E6]=face; p[0x1E7]=!face;
  p[0x1B2]=9; *(u16*)(p+0x1C0)=99; *(int*)(p+0x1D8)=7;
  *(float*)(p+0x430)=19.5f; *(float*)(p+0x68)=4;
  func_002F0110(p);
  if(wrong || stage!=5 || p[6]!=0 || p[0x1B5]!=53 || p[0x1B2] ||
     *(u16*)(p+0x1C0) || *(int*)(p+0x1D8) || counters.count[team]!=1 ||
     counters.count[1-team] || *(float*)(p+0x38)!=19.5f || *(float*)(p+0x68)!=0) return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_setup_and_callback_order(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_field_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_unsigned_frame_byte_is_rejected(self):
        self.assertNotEqual(self.run_case('signed'), 0)
