"""Exercise the timer gate, actual facing/placement, and post-animation byte."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorActionTimerEntry002ef8d0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_action_timer_entry_002ef8d0.c').read_text().replace('__attribute__((section(".sdata")))', '')
        if mutation == 'timer':
            body = body.replace('!*(s8*)(p+0x539) || p[0x425]', '*(s8*)(p+0x539) && p[0x425]')
        if mutation == 'row':
            body = body.replace('row[p[0x1B7]]', 'row[1-p[0x1B7]]')
        if mutation == 'signed':
            body = body.replace('*(s8*)(p+0x152)', '*(u8*)(p+0x152)')
        code = r'''
#include <string.h>
typedef unsigned int u32;typedef int s32;typedef float f32;
''' + body + r'''
extern void func_0018C510(u8*,int),func_0015D8F0(float*,s16);
''' + states.function('src/h11d.c','func_00185490') + states.function('src/wave13.c','func_00183D10') + states.function('src/wave2.c','func_0018C4B0') + r'''
static Counters bank;Counters *D_004C2794=&bank;
u8 D_004C1250[8]={41,43,41,43,45,47,49,51};
static u8 *actor;static int stage,wrong,face,team,row,variant,mode,flag,frameByte;
void func_0015D8F0(float*v,s16 dir) {
 if(stage++!=0 || dir!=face || v[0]!=100 || v[1]!=50 || v[2]!=99 || actor[0x20D]!=9)wrong++;
}
void func_0018C510(u8*p,int n) {
 int expected=(!mode || flag)?30:120;
 if(p!=actor || stage++!=1 || n!=10 || p[0x20D] || p[0x20] || *(int*)(p+0x2E0)!=96 ||
    *(float*)(p+0x38)!=50 || *(s16*)(p+0x1C)!=expected || p[0x1B5]!=53 ||
    p[0x1B2] || *(u16*)(p+0x1C0) || *(int*)(p+0x1D8) || bank.count[team]!=6)wrong++;
}
int func_001757E0(u8*p,int a,int b) {
 if(p!=actor || stage++!=2 || a!=21 || b!=D_004C1250[row*2+variant])wrong++;
 p[0x152]=frameByte;return 0;
}
int main(void) {
 _Alignas(16) u8 p[0x600],opponent[0x500];int modes[]={-1,0,1},bytes[]={0,127,128,255};
 for(face=0;face<2;face++)for(team=0;team<2;team++)for(row=0;row<4;row++)for(variant=0;variant<2;variant++)
 for(int m=0;m<3;m++)for(flag=0;flag<2;flag++)for(int j=0;j<4;j++) {
  memset(p,0,sizeof p);memset(opponent,0,sizeof opponent);memset(&bank,0,sizeof bank);
  actor=p;stage=wrong=0;mode=modes[m];frameByte=bytes[j];*(u8**)(p+0x220)=opponent;
  *(float*)(p+0x34)=100;*(float*)(opponent+0x34)=100;*(float*)(p+0x430)=50;*(float*)(p+0x3C)=99;
  p[6]=255;p[2]=team;p[0x1B7]=variant;p[0x1E6]=face;p[0x20D]=9;p[0x20]=7;
  p[0x539]=(u8)mode;p[0x425]=flag;*(int*)(p+0x2D4)=row;p[0x1B2]=9;*(u16*)(p+0x1C0)=7;
  *(int*)(p+0x1D8)=8;bank.count[team]=5;
  func_002EF8D0(p);
  if(wrong || stage!=3 || p[6] || *(int*)(p+0x2EC)!=(int)(s8)frameByte || bank.count[1-team])return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_timer_facing_and_post_animation_byte(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_timer_condition_is_rejected(self):
        self.assertNotEqual(self.run_case('timer'), 0)

    def test_wrong_action_variant_is_rejected(self):
        self.assertNotEqual(self.run_case('row'), 0)

    def test_unsigned_animation_byte_is_rejected(self):
        self.assertNotEqual(self.run_case('signed'), 0)
