"""Exercise owner copying and state after animation callbacks."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerScaleStartTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_scale_start_00383580.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p+0x18', 'p+0x500')
        if mutation == 'team':
            body = body.replace('count[*team]', 'count[1-*team]')
        if mutation == 'scale':
            body = body.replace('*=1.5f', '*=1.0f')
        if mutation == 'owner':
            body = body.replace('p[1]=OWNER[1]', 'p[1]=OWNER[2]')
        code = r'''
#include <string.h>
''' + body + r'''
static Counters bank;Counters *D_004C2794=&bank;
static u8 *actor;static int stage,wrong,initial_team;
int func_001757E0(u8*p,int a,int b) {
 if(p!=actor || stage++!=0 || a!=23 || b!=16 || p[0x13C]!=1 || p[2]!=initial_team ||
    p[1]!=44 || p[0x1B7]!=17 || p[0x1B8]!=18 || p[0x30]!=250 || p[0x24]!=252 ||
    *(float*)(p+0x50)!=3 || *(float*)(p+0x54)!=6 || *(float*)(p+0x58)!=7 || p[0xEC]!=99)wrong++;
 p[2]=1-initial_team;*(float*)(p+0x50)=8;*(float*)(p+0x54)=12;return 0;
}
void func_00383710(u8*p) {
 if(p!=actor || stage++!=1 || p[0x1B0]!=66 || p[0x1B1]!=66 || p[0x24]!=0 ||
    *(int*)(p+0x48)!=410 || *(float*)(p+0x50)!=12 || *(float*)(p+0x54)!=8 ||
    *(s16*)(p+0x1C)!=8 || p[0x1B5]!=59 || p[0x1B2] || *(u16*)(p+0x1C0) ||
    *(int*)(p+0x1D8) || p[7]!=1)wrong++;
}
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x500];
 for(int t=0;t<2;t++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);memset(&bank,0,sizeof bank);
  actor=p;stage=wrong=0;initial_team=t;*(u8**)(p+0x500)=owner;
  owner[2]=t;owner[1]=44;owner[0x1B7]=17;owner[0x1B8]=18;owner[0x30]=250;owner[0x24]=252;owner[0xEC]=99;
  *(float*)(owner+0x50)=3;*(float*)(owner+0x54)=6;*(float*)(owner+0x58)=7;
  bank.count[1-t]=wrap?32767:5;bank.count[t]=11;p[4]=255;
  func_00383580(p);
  if(wrong || stage!=2 || p[4] || bank.count[t]!=11 || bank.count[1-t]!=(wrap?-32768:6))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_copy_and_post_animation_state(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_team_is_rejected(self):
        self.assertNotEqual(self.run_case('team'), 0)

    def test_wrong_scale_is_rejected(self):
        self.assertNotEqual(self.run_case('scale'), 0)

    def test_wrong_owner_field_is_rejected(self):
        self.assertNotEqual(self.run_case('owner'), 0)
