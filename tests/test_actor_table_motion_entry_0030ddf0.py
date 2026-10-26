"""Exercise table selection and real facing, placement and frame-copy helpers."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorTableMotionEntry0030ddf0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_table_motion_entry_0030ddf0.c').read_text().replace('__attribute__((section(".sdata")))', '')
        if mutation == 'facing':
            body = body.replace('if(p[0x1E6])', 'if(!p[0x1E6])')
        if mutation == 'position':
            body = body.replace('p[0x20D]!=2', 'p[0x20D]==2')
        if mutation == 'action':
            body = body.replace('D_004C1658[p[0x1B7]*2]', 'D_004C1658[(2-p[0x1B7])*2]')
        frame = states.function('src/y11_d.c','func_00176160').replace('o + 0x174', 'o + 0x580')
        code = r'''
#include <string.h>
typedef signed char s8;typedef int s32;typedef unsigned int u32;typedef float f32;
''' + body + r'''
extern u8 D_004F54D0[];
extern void func_0018C510(u8*,int),func_0015D8F0(float*,s16);
''' + states.function('src/h11d.c','func_00185490') + states.function('src/wave2.c','func_0018C4B0') + states.function('src/wave13.c','func_00183D10') + frame + r'''
static Counters bank;Counters *D_004C2794=&bank;
u8 D_004C1658[6]={48,0,49,0,50,0};
float D_0045D1E0[6]={-10,0.5f,-20,1,-30,1.5f};
_Alignas(16) u8 D_004F54D0[0x100];
static u8 *actor,*texture;static int stage,wrong,variant,face,skip,team;
void func_0018C510(u8*p,int n) {if(p!=actor || n!=5 || stage++!=0)wrong++;}
void func_0015D8F0(float*v,s16 dir) {if(stage++!=1 || skip || dir!=face || v[0]!=100 || v[1]!=50 || v[2]!=99)wrong++;}
int func_001757E0(u8*p,int a,int b) {
 float vx=D_0045D1E0[variant*2],ax=D_0045D1E0[variant*2+1];if(face){vx=-vx;ax=-ax;}
 if(p!=actor || stage++!=(skip?1:2) || a!=21 || b!=variant || p[0x1B5]!=48+variant ||
    p[0x1B2] || *(u16*)(p+0x1C0) || *(int*)(p+0x1D8) || bank.count[team]!=6 ||
    *(float*)(p+0x5C)!=vx || *(float*)(p+0x68)!=ax || *(float*)(p+0x60)!=0 ||
    *(float*)(p+0x6C)!=0 || *(s32*)(D_004F54D0+0x38)!=1 ||
    memcmp(D_004F54D0+0x40,texture+0x880,32))wrong++;
 return 0;
}
int main(void) {
 _Alignas(16) u8 p[0x600],opponent[0x500],source[0x1000];
 for(variant=0;variant<3;variant++)for(face=0;face<2;face++)for(skip=0;skip<2;skip++)for(team=0;team<2;team++) {
  memset(p,0,sizeof p);memset(opponent,0,sizeof opponent);memset(source,0,sizeof source);
  memset(D_004F54D0,0,sizeof D_004F54D0);memset(&bank,0,sizeof bank);actor=p;texture=source;stage=wrong=0;
  for(int j=0;j<32;j++)source[0x880+j]=(u8)(j+1);
  *(u8**)(p+0x580)=source;*(u8**)(p+0x220)=opponent;
  *(float*)(p+0x34)=100;*(float*)(opponent+0x34)=100;*(float*)(p+0x430)=50;*(float*)(p+0x3C)=99;
  p[6]=255;p[2]=team;p[0x1B7]=variant;p[0x1E6]=face;p[0x20D]=skip?2:0;
  p[0x1B2]=9;*(u16*)(p+0x1C0)=7;*(int*)(p+0x1D8)=8;bank.count[team]=5;
  func_0030DDF0(p);
  if(wrong || stage!=(skip?2:3) || p[6] || p[0x20D]!=(skip?2:0) || bank.count[1-team])return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_facing_tables_and_real_helpers(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_position_gate_is_rejected(self):
        self.assertNotEqual(self.run_case('position'), 0)

    def test_wrong_action_row_is_rejected(self):
        self.assertNotEqual(self.run_case('action'), 0)
