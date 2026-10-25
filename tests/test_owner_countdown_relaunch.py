"""Check all nine constructed slots, countdown wrapping and real lifecycle bodies."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerCountdownRelaunchTests(unittest.TestCase):
    def run_relaunch(self,wrong_owner=False,signed_counter=False):
        source=(ROOT/'src/owner_countdown_relaunch_0019be90.c').read_text()
        if wrong_owner:
            changed=source.replace('#define OWNER (*(u8**)(p+0x18))','#define OWNER (p)')
            self.assertNotEqual(changed,source);source=changed
        if signed_counter:
            changed=source.replace('int remaining=--p[0x21]','int remaining=(s8)--p[0x21]')
            self.assertNotEqual(changed,source);source=changed
        # Native timer 0x1c overlaps a widened host owner pointer at 0x18.
        source=source.replace('(p+0x18))','(p+0x280))')
        code=r'''
#include <string.h>
typedef float f32;
struct Object;
void func_003DAA40(struct Object *);
'''+source+'\n'+(ROOT/'src/data/jtbl_0044A8D0.c').read_text()+'\n'
        code+=states.function('src/composite_dispatch_heads.c','func_0019BE70')
        code+=states.function('src/h9.c','func_0019C100')
        code+=states.function('src/tail_leaves.c','func_0019C190')
        code+=states.function('src/tail_leaves.c','func_0019C1B0')
        code+=r'''
/* The ninth native halfword is 0x5555, overlapping the first velocity. */
s16 D_0044A8A0[9]={-24,-8,8,24,-24,-10,-10,24,21845};
float D_0044A8B0[4][2]={{-5.0f/3,0},{-5.0f/6,0},{5.0f/3,0},{5.0f/6,0}};
float D_0044A8B4[4][2]={{5.0f/96,0},{5.0f/96,0},{-5.0f/96,0},{-5.0f/96,0}};
static int animations,sounds,updates,releases,wrong,frameResult;
static u8 *seen;
int func_001757E0(u8 *p,int a,int b){animations++;seen=p;if(a!=23||b!=((p[0x20]&4)?5:4))wrong++;return 0;}
int func_00175700(u8 *p){updates++;seen=p;return frameResult;}
void func_001E3210(u8 *p,int n){sounds++;seen=p;if(n!=10||animations!=1)wrong++;}
void func_003DAA40(struct Object *p){releases++;seen=(u8*)p;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 const int timers[6]={-32768,-1,0,1,2,32767},counts[5]={0,1,2,7,255};
 int slot,t,c,negative,i;
 for(slot=0;slot<9;slot++)for(t=0;t<6;t++)for(c=0;c<5;c++)for(negative=0;negative<2;negative++) {
  int timer=(short)(timers[t]-1),remaining=(u8)(counts[c]-1),run=timer<=0,terminal=run&&remaining==0;
  for(i=0;i<0x300;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[4]=0;p[0x20]=slot;p[0x21]=counts[c];H(p,0x1C)=timers[t];H(p,0x1E)=118;
  *(u8**)(p+0x280)=q;F(q,0x34)=12.5f;F(q,0x38)=-3.25f;
  F(q,0x50)=1.25f;F(q,0x54)=2.5f;F(q,0x58)=-4.5f;
  memcpy(want,p,sizeof(p));H(want,0x1C)=timer;
  if(run) {
   want[0x21]=remaining;
   if(terminal){want[4]=3;want[0x13C]=0;}
   else {
    float vx=0,vy=0,ax=0,ay=0,x,y;
    want[4]=1;memcpy(want+0xEC,q+0xEC,196);want[0x13C]=1;
    want[2]=q[2];want[1]=q[1];memcpy(want+0x50,q+0x50,12);
    want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];want[0x24]=0;
    if(slot&4){vx=D_0044A8B0[slot-4][0];ax=D_0044A8B4[slot-4][0];vy=90.0f/7;ay=-(15.0f/7)/8;}
    x=12.5f+(5.0f/3)*D_0044A8A0[slot];y=-3.25f+(15.0f/7)*118;
    F(want,0x34)=x+vx;F(want,0x38)=y+vy;F(want,0x5C)=vx+ax;F(want,0x60)=vy+ay;
    F(want,0x68)=ax;F(want,0x6C)=ay;
    if(negative){want[4]=0;want[0x13C]=0;H(want,0x1E)=99;}
   }
  }
  animations=sounds=updates=releases=wrong=0;seen=0;frameResult=negative?-1:0;
  func_0019BE70(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(animations!=(run&&!terminal)||updates!=(run&&!terminal)||releases!=terminal||sounds!=(run&&!terminal&&slot==0)||wrong)return 2;
  if(run&&seen!=p)return 3;
 }
 return 0;
}
'''
        # The extracted updater's callee declaration is a fixture boundary.
        code=code.replace('void func_0019C100(u8 *p) {','int func_00175700(u8*);\nvoid func_0019C100(u8 *p) {')
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_all_slots_timer_and_counter_wrap_real_update_and_release(self):
        self.assertEqual(self.run_relaunch(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_relaunch(wrong_owner=True),0)

    def test_signed_counter_is_detected(self):
        self.assertNotEqual(self.run_relaunch(signed_counter=True),0)
