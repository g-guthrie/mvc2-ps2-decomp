"""Check dash setup, counter ordering and the direction chosen after orientation."""
import re
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class PlayerDashCounterStartTests(unittest.TestCase):
    def run_dash(self,wrong_work=False,stale_direction=False):
        source=(ROOT/'src/player_dash_counter_start_001fa920.c').read_text().replace(' __attribute__((section(".sdata")))','')
        source=source.replace('*(u8**)(p+0x1D8)=0','*(u32*)(p+0x1D8)=0')
        dispatch=states.function('src/argument_dispatch_heads.c','func_001FA8F0')
        if wrong_work:
            changed=dispatch.replace('p + 696','p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if stale_direction:
            changed=source.replace('u8 *work=work_context;','u8 *work=work_context;u8 oldDirection=p[0x1E6];').replace('p[0x1E6]?20.0f:-20.0f','oldDirection?20.0f:-20.0f')
            self.assertNotEqual(changed,source);source=changed
        table=(ROOT/'src/data/jtbl_0044FD60.c').read_text()
        unused=sorted(set(re.findall(r'extern void (func_\w+)\(u8 \*, void \*\);',table))-{'func_001FA920'})
        orient=states.function('src/h11d.c','func_00185490').replace('void func_00185490(','static void orient_body(',1)
        code=r'''
#include <string.h>
typedef unsigned int u32;
typedef float f32;
'''+source+'\n'+table+'\n'+dispatch+orient+'\n'
        code+='\n'.join(f'void {name}(u8 *p,void *w){{(void)p;(void)w;}}' for name in unused)
        code+=r'''
CounterBank *D_004C2794;
static int orientations,animations,wrong;
static u8 *expected,*wanted;
static CounterBank *wantedBank;
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
void func_00185490(u8 *p) {
 orientations++;
 if(p!=expected||p[6]!=wanted[6]||p[0x1B5]!=72||*(u16*)(p+0x1C0)||p[0x1B2]||*(u32*)(p+0x1D8)||memcmp(D_004C2794,wantedBank,sizeof(CounterBank)))wrong++;
 if(F(p,0x5C)!=51.25f||F(p,0x60)!=1.5f||F(p,0x68)!=-2.5f||F(p,0x6C)!=0.25f)wrong++;
 orient_body(p);
}
int func_001757E0(u8 *p,int a,int b){animations++;if(p!=expected||a!=22||b!=6||orientations!=1||memcmp(p,wanted,0x600))wrong++;return 0;}
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600];CounterBank bank,wantBank;
 int kinds[3]={0,6,255},dirs[3]={0,1,255},values[3]={-32768,32767,13},parentKinds[3]={0,58,255};
 float xs[3]={-100,0,100};int player,kind,direction,count,position,parent,wrap;
 D_004C2794=&bank;
 for(player=0;player<2;player++)for(kind=0;kind<3;kind++)for(direction=0;direction<3;direction++)for(count=0;count<3;count++)for(position=0;position<3;position++)for(parent=0;parent<3;parent++)for(wrap=0;wrap<2;wrap++) {
  float k=-23.333332f,target;int a=dirs[direction],facing;
  memset(p,0x5A,sizeof(p));memset(q,0,sizeof(q));memset(&bank,0x23,sizeof(bank));
  p[2]=player;p[6]=wrap?255:0;p[0x269]=kinds[kind];p[0x1E6]=a;
  bank.count[0]=values[count];bank.count[1]=(short)(values[count]-1);
  *(u8**)(p+0x220)=q;q[1]=parentKinds[parent];F(q,0x34)=20.5f;F(p,0x34)=xs[position];
  F(p,0x5C)=51.25f;F(p,0x60)=1.5f;F(p,0x68)=-2.5f;F(p,0x6C)=0.25f;
  if(a)k=-k;target=20.5f+k;
  facing=((target<xs[position]&&a)||(!(target<xs[position])&&!a))?(a^1):a;
  memcpy(want,p,sizeof(p));memcpy(&wantBank,&bank,sizeof(bank));
  if(kinds[kind]==6){want[0x404]=255;want[0x405]=16;}
  want[6]=(u8)(p[6]+1);want[0x1B5]=72;*(u16*)(want+0x1C0)=0;want[0x1B2]=0;*(u32*)(want+0x1D8)=0;
  wantBank.count[player]=(short)(bank.count[player]+1);want[0x1E6]=facing;H(want,0x140)=facing;
  F(want,0x5C)=facing?20.0f:-20.0f;F(want,0x60)=F(want,0x68)=F(want,0x6C)=0;
  want[0x20D]=2;want[0x2B9]=parentKinds[parent];H(want,0x1C)=16;want[0x21]=0;
  expected=p;wanted=want;wantedBank=&wantBank;orientations=animations=wrong=0;
  if(wrap)func_001FA920(p,p+0x2B8);else func_001FA8F0(p);
  if(memcmp(p,want,sizeof(p))||memcmp(&bank,&wantBank,sizeof(bank)))return 1;
  if(orientations!=1||animations!=1||wrong)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_dash_fields_real_orientation_counters_work_and_call_order(self):
        self.assertEqual(self.run_dash(),0)

    def test_wrong_work_pointer_is_detected(self):
        self.assertNotEqual(self.run_dash(wrong_work=True),0)

    def test_stale_direction_is_detected(self):
        self.assertNotEqual(self.run_dash(stale_direction=True),0)
