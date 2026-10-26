"""Exercise known spawn offsets, owner direction and initializer ordering."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerOffsetStart00380300Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_offset_start_00380300.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p+0x18', 'p+0x500')
        if mutation == 'facing':
            body = body.replace('if(*(s16*)(owner+0x140))offset=-offset;', 'if(!*(s16*)(owner+0x140))offset=-offset;')
        if mutation == 'index':
            body = body.replace('D_004C1D48[p[0x23]]', 'D_004C1D48[2-p[0x23]]')
        if mutation == 'flag':
            body = body.replace('*(u16*)(p+0x1C0)|=0x200;', '*(u16*)(p+0x1C0)|=0x100;')
        code = r'''
#include <string.h>
''' + body + r'''
static Counters bank;Counters *D_004C2794=&bank;
s16 D_004C1D48[3]={0,-112,112};float D_004F1F4C=400.0f;
static u8 *actor;static int stage,wrong,face,row,team;
int func_001757E0(u8*p,int a,int b) {
 float offset=1.6666666269302368f*(float)D_004C1D48[row];if(face)offset=-offset;
 if(p!=actor || stage++!=0 || a!=23 || b!=3 || p[0x13C]!=1 || p[1]!=44 || p[2]!=team ||
    p[0xEC]!=99 || p[0x1B7]!=17 || p[0x1B8]!=18 || p[0x30]!=250 || p[0x24]!=10 ||
    p[0x31] || p[0x21] || p[0x20] || *(s16*)(p+0x140) || *(u16*)(p+0x26)!=0x1900 ||
    *(float*)(p+0x64)!=3 || *(float*)(p+0x70)!=6 || *(float*)(p+0x34)!=400.0f+offset ||
    *(float*)(p+0x38)!=77 || p[0x1B0]!=68 || p[0x1B1]!=68 || p[0x1B5]!=48 ||
    p[0x1B2] || *(u16*)(p+0x1C0)!=0x200 || *(int*)(p+0x1D8) || bank.count[team]!=6)wrong++;
 return 0;
}
void func_003804B0(u8*p) {if(p!=actor || stage++!=1)wrong++;}
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x500];
 for(row=0;row<3;row++)for(face=0;face<2;face++)for(team=0;team<2;team++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);memset(&bank,0,sizeof bank);actor=p;stage=wrong=0;
  *(u8**)(p+0x500)=owner;p[4]=255;p[0x23]=row;owner[1]=44;owner[2]=team;owner[0xEC]=99;
  owner[0x1B7]=17;owner[0x1B8]=18;owner[0x30]=250;owner[0x24]=252;
  *(s16*)(owner+0x140)=face;*(float*)(owner+0x430)=77;
  *(float*)(owner+0x50)=3;*(float*)(owner+0x54)=6;*(float*)(owner+0x58)=7;bank.count[team]=5;
  func_00380300(p);
  if(wrong || stage!=2 || p[4] || bank.count[1-team])return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_known_offsets_and_callback_order(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_offset_index_is_rejected(self):
        self.assertNotEqual(self.run_case('index'), 0)

    def test_wrong_action_flag_is_rejected(self):
        self.assertNotEqual(self.run_case('flag'), 0)
