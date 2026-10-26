"""Check owner copying, shared state and direction-dependent velocity."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerVelocityStartTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_velocity_start_00384670.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p+0x18', 'p+0x500')
        if mutation == 'facing':
            body = body.replace('*(s16*)(p+0x140)?1.6666666269302368f:-1.6666666269302368f', '*(s16*)(p+0x140)?-1.6666666269302368f:1.6666666269302368f')
        if mutation == 'handle':
            body = body.replace('OWNER+0x168', 'OWNER+0x16A')
        if mutation == 'zero':
            body = body.replace('D_004C29AC->f4=0', 'D_004C29AC->f4=1')
        code = r'''
#include <string.h>
''' + body + r'''
static S9AC bank;S9AC *D_004C29AC=&bank;
static u8 *actor;static int stage,wrong,face;
int func_001757E0(u8*p,int a,int b) {
 if(p!=actor || stage++!=0 || a!=23 || b!=3 || p[0x13C]!=1 || p[1]!=44 || p[2]!=1 ||
    p[0x1B7]!=17 || p[0x1B8]!=18 || p[0x30]!=250 || p[0x24]!=252 || p[0xEC]!=99 ||
    *(s16*)(p+0x140)!=face || bank.h0!=0xBEEF || bank.f4!=0 ||
    *(float*)(p+0x5C)!=(face?1.6666666269302368f:-1.6666666269302368f) ||
    *(float*)(p+0x60)!=0 || *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0)wrong++;
 *(float*)(p+0x5C)=9;return 0;
}
void func_003847D0(Ent3847*p) {if((u8*)p!=actor || stage++!=1 || *(float*)(actor+0x5C)!=9)wrong++;}
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x500];int faces[]={0,1,-1};
 for(int f=0;f<3;f++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);actor=p;stage=wrong=0;face=faces[f];
  *(u8**)(p+0x500)=owner;p[4]=wrap?255:5;owner[1]=44;owner[2]=1;
  owner[0x1B7]=17;owner[0x1B8]=18;owner[0x30]=250;owner[0x24]=252;owner[0xEC]=99;
  *(s16*)(owner+0x140)=face;*(u16*)(owner+0x168)=0xBEEF;*(u16*)(owner+0x16A)=0x1234;
  *(float*)(owner+0x50)=3;*(float*)(owner+0x54)=6;*(float*)(owner+0x58)=7;bank.h0=4;bank.f4=5;
  func_00384670(p);
  if(wrong || stage!=2 || p[4]!=(wrap?0:6) || *(float*)(p+0x50)!=3 || *(float*)(p+0x54)!=6 || *(float*)(p+0x58)!=7)return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_copy_velocity_and_callback_order(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_direction_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_handle_is_rejected(self):
        self.assertNotEqual(self.run_case('handle'), 0)

    def test_shared_offset_not_cleared_is_rejected(self):
        self.assertNotEqual(self.run_case('zero'), 0)
