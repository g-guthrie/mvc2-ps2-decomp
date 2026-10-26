"""Check actor callbacks, signed counters and explicit actor forwarding."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class PlayerIdleCounterStartTests(unittest.TestCase):
    def run_idle(self,wrong_counter=False):
        source=(ROOT/'src/player_idle_counter_start_0030aaa0.c').read_text().replace(' __attribute__((section(".sdata")))','')
        # Keep the native pointer slot four bytes wide on the 64-bit host.
        source=source.replace('*(u8**)(p+0x1D8)=0','*(unsigned int*)(p+0x1D8)=0')
        if wrong_counter:
            changed=source.replace('count[p[2]]','count[0]')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
typedef unsigned int u32;
typedef float f32;
'''+source+'\n'+(ROOT/'src/data/jtbl_0045CEF0.c').read_text()+'\n'
        code+=states.function('src/grok_u3_30a_dispatches.c','func_0030AA80')
        code+=states.function('src/h11d.c','func_00185490')
        code+=states.function('src/wave13.c','func_00183D10')
        code+=r'''
CounterBank *D_004C2794;
static int effects,animations,wrong,expectedFace;
static u8 *expected;
static float expectedX,expectedY;
void func_0015D8F0(float *v,int face) {
 effects++;
 if(v[0]!=expectedX||v[1]!=expectedY||v[2]!=7.25f||face!=expectedFace)wrong++;
}
int func_001757E0(u8 *p,int a,int b){animations++;if(p!=expected||a!=22||b||effects!=1)wrong++;return 0;}
void func_0030AB60(u8 *p){(void)p;}
void func_0030AC10(u8 *p){(void)p;}
void func_0030AC70(u8 *p){(void)p;}
void func_00309310(u8 *p){(void)p;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600];
 CounterBank bank,wantBank;
 int players[2]={0,1},kinds[3]={0,6,255},dirs[3]={0,1,255},values[3]={13,32767,-32768};
 float positions[3]={-100,0,100};
 int player,kind,direction,count,position,wrap;
 D_004C2794=&bank;
 for(player=0;player<2;player++)for(kind=0;kind<3;kind++)for(direction=0;direction<3;direction++)for(count=0;count<3;count++)for(position=0;position<3;position++)for(wrap=0;wrap<2;wrap++) {
  float k=-23.333332f,target;int a=dirs[direction],facing;
  memset(p,0x5A,sizeof(p));memset(q,0,sizeof(q));memset(&bank,0x23,sizeof(bank));
  bank.count[0]=values[count];bank.count[1]=(short)(values[count]-1);
  p[2]=players[player];p[6]=wrap?255:0;p[0x269]=kinds[kind];p[0x1E6]=a;
  *(u8**)(p+0x220)=q;F(q,0x34)=20.5f;
  F(p,0x34)=positions[position];F(p,0x430)=-50.5f;F(p,0x3C)=7.25f;
  if(a)k=-k;target=20.5f+k;
  facing=((target<positions[position]&&a)||(!(target<positions[position])&&!a))?(a^1):a;
  memcpy(want,p,sizeof(p));memcpy(&wantBank,&bank,sizeof(bank));
  if(kinds[kind]==6){want[0x404]=255;want[0x405]=16;}
  want[6]=(u8)(p[6]+1);want[0x1E6]=facing;H(want,0x140)=facing;
  F(want,0x5C)=F(want,0x60)=F(want,0x68)=F(want,0x6C)=0;
  want[0x1B5]=want[0x1B2]=0;*(unsigned short*)(want+0x1C0)=0;*(u32*)(want+0x1D8)=0;
  wantBank.count[player]=(short)(bank.count[player]+1);F(want,0x38)=-50.5f;want[0x20D]=0;
  effects=animations=wrong=0;expected=p;expectedFace=facing;expectedX=positions[position];expectedY=-50.5f;
  if(wrap)func_0030AAA0(p);else func_0030AA80(p);
  if(memcmp(p,want,sizeof(p))||memcmp(&bank,&wantBank,sizeof(bank)))return 1;
  if(effects!=1||animations!=1||wrong)return 2;
 }
 return 0;
}
'''
        code=code.replace('void func_00183D10(u8 *p) {','void func_0015D8F0(float*,int);\nvoid func_00183D10(u8 *p) {')
        return states.OwnedActorStateTests.compile_run(self,code)

    def run_forwarding(self,wrong_actor=False):
        caller=states.function('src/grok_r1_0030.c','func_0030A680')
        if wrong_actor:
            changed=caller.replace('func_00309310(p)','func_00309310((u8*)0)')
            self.assertNotEqual(changed,caller);caller=changed
        code=r'''
#include <string.h>
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x151];s8 frame;} FrameFlag;
'''+(ROOT/'src/data/data_u32_0045CE50.c').read_text()+r'''
#define D_0045CE50 data_u32_0045CE50
int func_00175700(u8*);
void func_001843A0(u8*);
'''+states.function('src/grok_r1_0030.c','func_0030A450')+states.function('src/signed_result_handlers.c','func_00309310')+caller+r'''
static int advances,transitions,wrong,result;
static u8 *expected;
static float expectedX;
int func_00175700(u8 *p) {advances++;if(p!=expected){wrong++;return 0;}if(*(float*)(p+0x34)!=expectedX)wrong++;return result;}
void func_001843A0(u8 *p) {transitions++;if(p!=expected)wrong++;}
int main(void) {
 _Alignas(16) u8 p[0x300],want[0x300];int frame,direction,r;
 int results[4]={0,-1,128,256};
 for(frame=0;frame<15;frame++)for(direction=0;direction<2;direction++)for(r=0;r<4;r++) {
  memset(p,0x5A,sizeof(p));p[0x151]=frame<12?(u8)(-128+frame):(frame==12?0:frame==13?1:127);
  p[0x1E6]=direction;*(float*)(p+0x34)=12.5f;
  memcpy(want,p,sizeof(p));
  if(frame<12){want[0x209]=1;if(frame){float x=data_u32_0045CE50[frame];if(!direction)x=-x;want[0x151]=128;*(float*)(want+0x34)+=x;}}
  expected=p;expectedX=*(float*)(want+0x34);result=results[r];advances=transitions=wrong=0;
  func_0030A680(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(advances!=1||transitions!=((s8)result<0)||wrong)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_idle_fields_real_orientation_ground_helper_and_both_counters(self):
        self.assertEqual(self.run_idle(),0)

    def test_wrong_player_counter_is_detected(self):
        self.assertNotEqual(self.run_idle(wrong_counter=True),0)

    def test_repaired_caller_real_helper_and_real_frame_child(self):
        self.assertEqual(self.run_forwarding(),0)

    def test_missing_actor_forwarding_is_detected(self):
        self.assertNotEqual(self.run_forwarding(wrong_actor=True),0)
