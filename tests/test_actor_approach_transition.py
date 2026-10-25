"""Check strict approach bounds with the actual contact and queue helpers."""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

class ActorApproachTransitionTests(unittest.TestCase):
    def run_transition(self,inclusive=False):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        source=(ROOT/'src/actor_approach_transition_00377390.c').read_text()
        if inclusive:
            changed=source.replace('center - halfWidth < actorX','center - halfWidth <= actorX')
            self.assertNotEqual(source,changed)
            source=changed
        queue=(ROOT/'src/enqueue_actor_001e7f60.c').read_text()
        contact=(ROOT/'src/t5_a.c').read_text()
        contact=contact[contact.index('s32 func_003777B0('):contact.index('\nvoid func_003CC760(')]
        code='#include <string.h>\n'+source+'\n'+queue+r'''
typedef float f32;
void func_001548D0(u8*,f32*,int);
void func_001E3210(u8*,int);
'''+contact+r'''
static _Alignas(16) u8 game[0x100];
u8 *D_004C2794=game;
s8 D_004C279C[2];
ActorList D_004D3170[2];
static int advanceResult,advanceCalls,animationCalls,group,event,hitCalls,hitEventCalls,hitEvent;
static float hitVector[3];
int func_00175700(u8 *p) {(void)p;advanceCalls++;return advanceResult;}
int func_001757E0(u8 *p,int a,int b) {(void)p;animationCalls++;group=a;event=b;return 0;}
void func_001548D0(u8 *p,f32 *v,int kind) {
 (void)p;if(kind!=0)hitCalls+=100;
 hitCalls++;memcpy(hitVector,v,sizeof(hitVector));
}
void func_001E3210(u8 *p,int value) {(void)p;hitEventCalls++;hitEvent=value;}
static void reset(void) {
 memset(game,0,sizeof(game));memset(D_004C279C,0,sizeof(D_004C279C));
 memset(D_004D3170,0,sizeof(D_004D3170));
 advanceResult=advanceCalls=animationCalls=hitCalls=hitEventCalls=0;
 group=event=hitEvent=-1;
}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 actor[0x600],owner[0x600],target[0x600];
 const float positions[7]={19,20,20.25f,100,179.75f,180,181};
 int x,air,variant,timer,ended;
 for(x=0;x<7;x++)for(air=0;air<2;air++)for(variant=0;variant<2;variant++)
 for(timer=0;timer<=2;timer++)for(ended=0;ended<2;ended++) {
  int finalTimer=timer-ended;
  int attack=finalTimer==1 || (positions[x]>20 && positions[x]<180 && !air);
  reset();memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));memset(target,0,sizeof(target));
  actor[2]=1;actor[5]=255;H(actor,0x1c)=timer;F(actor,0x34)=positions[x];
  F(actor,0x60)=9;F(actor,0x6c)=3;owner[0x1b7]=variant;
  *(u8**)(owner+0x220)=target;F(target,0x34)=100;target[0x20d]=air?2:0;
  advanceResult=ended?-128:0;
  func_00377390(actor,owner);
  if(H(actor,0x1c)!=finalTimer || advanceCalls!=1)return 1;
  if(actor[5]!=(attack?0:255) || animationCalls!=attack)return 2;
  if(attack && (group!=23 || event!=(variant?9:8)))return 3;
  if(!attack && (F(actor,0x60)!=4.821428298950195f || F(actor,0x6c)!=-0.8035714030265808f))return 4;
  if(attack && (F(actor,0x60)!=9 || F(actor,0x6c)!=3))return 5;
  if(F(actor,0x34)!=positions[x] || D_004C279C[1]!=1 || D_004D3170[1].list[0]!=actor)return 6;
  if(hitCalls || hitEventCalls)return 7;
 }
 reset();memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
 actor[2]=1;actor[5]=255;actor[0x151]=255;
 F(actor,0x34)=1;F(actor,0x38)=10;F(actor,0x5c)=2;F(actor,0x68)=3;
 F(actor,0x60)=4;F(actor,0x6c)=5;
 func_00377390(actor,owner);
 if(F(actor,0x34)!=3 || F(actor,0x38)!=14 || F(actor,0x5c)!=5 || F(actor,0x60)!=9)return 10;
 if(actor[5]!=255 || animationCalls || D_004C279C[1]!=1)return 11;
 reset();memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
 actor[2]=1;actor[5]=255;actor[0x151]=1;actor[0x1b3]=1;H(actor,0x1c)=2;
 F(actor,0x34)=1;F(actor,0x38)=10;F(actor,0x5c)=8;F(actor,0x60)=4;
 advanceResult=-128;
 func_00377390(actor,owner);
 if(actor[4]!=2 || actor[5] || H(actor,0x1c)!=1 || F(actor,0x5c)!=-4)return 20;
 if(F(actor,0x34)!=1 || F(actor,0x38)!=10 || F(actor,0x60)!=4)return 21;
 if(animationCalls!=1 || group!=23 || event!=11 || hitCalls!=1 || hitEventCalls!=1 || hitEvent!=37)return 22;
 if(hitVector[0]!=26.666666f || hitVector[1]!=34.285713f || hitVector[2]!=0)return 23;
 if(D_004C279C[1] || actor[0x1b3]!=1)return 24;
 for(timer=0;timer<2;timer++) {
  reset();memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
  actor[2]=1;actor[0x151]=1;
  if(timer)D_004C279C[1]=94;else game[6]=1;
  func_00377390(actor,owner);
  if(D_004C279C[1]!=(timer?94:0))return 30;
 }
 return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            path=Path(temporary);c=path/'approach.c';binary=path/'approach'
            c.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror',str(c),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            return subprocess.run([str(binary)],timeout=10).returncode

    def test_boundaries_timer_fallback_contact_and_queue(self):
        self.assertEqual(self.run_transition(),0)

    def test_inclusive_lower_bound_is_detected(self):
        self.assertNotEqual(self.run_transition(inclusive=True),0)
