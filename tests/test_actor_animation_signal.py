"""Exercise the signal handler with its real timer, allocation and queue helpers."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

class ActorAnimationSignalTests(unittest.TestCase):
    def run_signal(self,inverted=False):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        source=(ROOT/'src/actor_animation_signal_0035f270.c').read_text()
        if inverted:
            changed=source.replace('if(!(D_004D18DC & (1u << D_004D18DB)))',
                                   'if(D_004D18DC & (1u << D_004D18DB))')
            self.assertNotEqual(changed,source)
            source=changed
        source=re.sub(r' __attribute__\(\(section\("\.sdata"\)\)\)', '',source)
        # Widen address calculations only; native status stores remain 32-bit.
        source=source.replace('u32 offset;', 'uintptr_t offset;').replace('(u32)D_004C2794','(uintptr_t)D_004C2794')
        timer=(ROOT/'src/wave3.c').read_text()
        timer=timer[timer.index('void func_0035F430('):timer.index('\nvoid func_00359FD0(')]
        factory=(ROOT/'src/m6.c').read_text()
        factory=factory[factory.index('extern void func_0035F010(void);'):factory.index('\nextern void func_0039ACD0')]
        queue=(ROOT/'src/enqueue_actor_001e7f60.c').read_text()
        code='#include <stdint.h>\n#include <string.h>\n'+source+'\n'+timer+'\n'+queue+r'''
typedef struct {float x,y,z;} V3;
extern void *func_003DA750(void*,s32,s32);
'''+factory+r'''
static _Alignas(16) u8 game[0x100],allocated[0x100];
u8 *D_004C2794=game;
s8 D_004C279C[2];
ActorList D_004D3170[2];
u16 D_004D18DC;
u8 D_004D18DB;
static int frameCalls,allocCalls,badArguments,allocationFails,injectedCommand,injectedMarker;
static int timerAtFrame,workAtFrame;
static u8 *expectedActor,*expectedOwner;
int func_00175700(u8 *p) {
 frameCalls++;if(p!=expectedActor)badArguments++;
 timerAtFrame=*(s16*)(p+0x1c);workAtFrame=*(s8*)(expectedOwner+0x2bd);
 p[0x15b]=injectedCommand;p[0x151]=injectedMarker;return 0;
}
void *func_003DA750(void *context,s32 type,s32 initializer) {
 allocCalls++;if(context || type!=1 || initializer!=1)badArguments++;
 return allocationFails?0:allocated;
}
void func_0035F010(void) {}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(s16*)((p)+(n)))
#define U(p,n) (*(u16*)((p)+(n)))
#define W(p,n) (*(u32*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 actor[0x600],owner[0x600];
 s8 state[8];
 int phase,mask,command,marker,failed,hit;
 for(phase=0;phase<16;phase++)for(mask=0;mask<3;mask++)
 for(command=0;command<2;command++)for(marker=0;marker<2;marker++)
 for(failed=0;failed<2;failed++)for(hit=0;hit<2;hit++) {
  int blocked=mask==1;
  int triggered=!blocked && marker;
  int consumed=!blocked && command;
  int i;
  memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));memset(game,0,sizeof(game));
  memset(allocated,0xA5,sizeof(allocated));memset(state,0x6D,sizeof(state));state[4]=9;
  memset(D_004C279C,0,sizeof(D_004C279C));memset(D_004D3170,0,sizeof(D_004D3170));
  actor[2]=1;actor[5]=255;actor[0x20]=phase==15?255:phase;
  actor[0x15b]=90;actor[0x151]=127;actor[0x1b2]=hit;actor[0x1b3]=1;
  H(actor,0x1c)=5;U(actor,0x1c0)=0xA55A;W(actor,0x1d8)=33;
  actor[0x1c2]=0x72;actor[0x1dc]=0x71;
  F(actor,0x34)=1.25f;F(actor,0x38)=-2.5f;F(actor,0x3c)=3.75f;
  owner[0x2bd]=4;
  D_004D18DB=phase;
  D_004D18DC=mask==0?0:(u16)(1u<<(mask==1?phase:(phase+1)&15));
  frameCalls=allocCalls=badArguments=0;timerAtFrame=workAtFrame=-1;
  allocationFails=failed;injectedCommand=command?77:0;injectedMarker=marker?255:0;
  expectedActor=actor;expectedOwner=owner;
  func_0035F270(actor,owner,state);
  if(badArguments || frameCalls!=!blocked || allocCalls!=triggered)return 1;
  if(!blocked && (timerAtFrame!=(hit?1:5) || workAtFrame!=(hit?3:4)))return 2;
  if(*(s8*)(owner+0x2bd)!=(!blocked&&hit?3:4))return 3;
  if(H(actor,0x1c)!=(consumed?0:!blocked&&hit?1:5))return 4;
  if(actor[5]!=(triggered?0:255) || state[4]!=(triggered&&failed?-1:9))return 5;
  for(i=0;i<8;i++)if(i!=4 && state[i]!=0x6D)return 6;
  if(actor[0x15b]!=(blocked?90:0) || actor[0x151]!=(blocked?127:marker?255:0))return 7;
  if(*(s16*)(game+0x7e)!=consumed || actor[0x1b2]!=(consumed?0:hit))return 8;
  if(U(actor,0x1c0)!=(consumed?0:0xA55A) || W(actor,0x1d8)!=(consumed?0u:33u))return 9;
  if(actor[0x1c2]!=0x72 || actor[0x1dc]!=0x71)return 10;
  if(consumed && actor[0x1b5]!=77)return 11;
  if(triggered && !failed) {
   V3 *position=(V3*)(allocated+0x34);
   if(H(allocated,0x26)!=0xE02 || allocated[0x20]!=(u8)(actor[0x20]+1))return 12;
   if(*(void**)(allocated+0x18)!=owner || *(void**)(allocated+0x10)!=(void*)func_0035F010)return 13;
   if(position->x!=1.25f || position->y!=-2.5f || position->z!=3.75f)return 14;
  } else {
   for(i=0;i<0x100;i++)if(allocated[i]!=0xA5)return 15;
  }
  if(D_004C279C[1]!=1 || D_004D3170[1].list[0]!=actor || actor[0x1b3])return 16;
 }
 return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            path=Path(temporary);c=path/'signal.c';binary=path/'signal'
            c.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror',str(c),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            return subprocess.run([str(binary)],timeout=10).returncode

    def test_all_clock_phases_and_allocation_results(self):
        self.assertEqual(self.run_signal(),0)

    def test_inverted_clock_mask_is_detected(self):
        self.assertNotEqual(self.run_signal(inverted=True),0)
