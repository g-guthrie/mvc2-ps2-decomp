"""Exercise the recovered transitions and their complete native helper bodies.

Host adaptation widens address arithmetic and moves the 32-bit owner slot so
64-bit host pointers cannot overlap the native timer fields. Animation and
setup calls are recorded as controlled inputs; game code is compiled unchanged
by the separate whole-object and retail-image checks.
"""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
SOURCES=['actor_owner_timer_001bf860.c','actor_landing_command_00299a20.c',
         'actor_rise_cancel_002b09b0.c','actor_ground_launch_002cfa90.c']

class ActorMotionTransitionTests(unittest.TestCase):
    def run_transitions(self,wrong_clamp=False):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        pieces=[]
        for name in SOURCES:
            code=(ROOT/'src'/name).read_text()
            if wrong_clamp and 'rise_cancel' in name:
                changed=code.replace('if(func_002ADC20(p)<0.0f)', 'if(func_002ADC20(p)>0.0f)')
                self.assertNotEqual(changed,code)
                code=changed
            code=re.sub(r' __attribute__\(\(section\("\.sdata"\)\)\)', '',code)
            code=code.replace('(u32)D_004C2794','(uintptr_t)D_004C2794')
            code=code.replace('u32 offset;', 'uintptr_t offset;').replace('u32 offset=', 'uintptr_t offset=')
            code=code.replace('*(u8**)(p+0x18)', '*(u8**)(p+0x580)')
            pieces.append(code)
        code='#include <stdint.h>\n#include <string.h>\n'+ '\n'.join(pieces)+r'''
static _Alignas(16) u8 counters[0x100];
static u8 clockValue;
u8 *D_004C2794=counters,*D_004C2704=&clockValue;
static int animationCalls,group,event,advanceCalls,landingCalls,setupCalls,prepareCalls;
int func_00175700(u8 *p) {(void)p;advanceCalls++;return 0;}
int func_001757E0(u8 *p,int a,int b) {(void)p;animationCalls++;group=a;event=b;return 0;}
void func_00183d50(u8 *p) {(void)p;landingCalls++;}
void func_00185490(u8 *p) {(void)p;setupCalls++;}
void func_00183D10(u8 *p) {(void)p;prepareCalls++;}
static void reset(void) {
 memset(counters,0,sizeof(counters));
 animationCalls=advanceCalls=landingCalls=setupCalls=prepareCalls=0;
 group=event=-1;
}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 actor[0x600],owner[0x600];
 int t,c,pause,land,command,reverse,fall;
 for(t=-1;t<=1;t++)for(c=10;c<=11;c++) {
  reset();memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
  *(u8**)(actor+0x580)=owner;H(owner,0x1c)=t;
  H(actor,0x1c)=999;H(actor,0x1e)=1;actor[5]=255;F(actor,0x54)=2;
  clockValue=c;func_001BF860(actor);
  if(actor[5]!=(t<=0?0:255) || H(actor,0x1c)!=(t<=0?10:999))return 1;
  if(F(actor,0x54)!=(t<=0?1.0f:2.0f) || H(owner,0x1c)!=t)return 2;
  if(clockValue!=11 || H(actor,0x1e)!=1)return 3;
  if(F(actor,0x34)!=(c==10?53.333332f:0.0f))return 4;
 }
 for(pause=0;pause<2;pause++)for(land=0;land<2;land++)for(command=0;command<2;command++) {
  reset();memset(actor,0,sizeof(actor));actor[2]=1;actor[6]=255;
  actor[0x151]=pause?255:0;actor[0x1b7]=255;actor[0x20d]=2;
  actor[0x15b]=command?77:0;
  F(actor,0x34)=10;F(actor,0x38)=200;F(actor,0x5c)=2;F(actor,0x68)=-1;
  F(actor,0x60)=-5;F(actor,0x6c)=2;F(actor,0x430)=land?201:100;
  func_00299A20(actor);
  if(F(actor,0x34)!=(pause?10.0f:12.0f))return 10;
  if(F(actor,0x38)!=(land?201.0f:pause?200.0f:195.0f))return 11;
  if(actor[6]!=(land?0:255) || actor[0x20d]!=(land?0:2))return 12;
  if(advanceCalls!=1 || landingCalls!=land || animationCalls!=land)return 13;
  if(land && (group!=21 || event!=26))return 14;
  if(actor[0x15b] || H(counters,0x7e)!=command)return 15;
  if(command && actor[0x1b5]!=77)return 16;
 }
 for(reverse=0;reverse<2;reverse++)for(fall=0;fall<2;fall++) {
  reset();memset(actor,0,sizeof(actor));actor[2]=1;actor[6]=255;actor[0x15b]=42;
  F(actor,0x34)=10;F(actor,0x38)=100;F(actor,0x5c)=2;
  F(actor,0x68)=reverse?-3:3;F(actor,0x60)=fall?-2:2;
  func_002B09B0(actor);
  if(F(actor,0x34)!=12 || F(actor,0x38)!=(fall?98.0f:102.0f))return 20;
  if(F(actor,0x5c)!=((reverse||fall)?0.0f:5.0f))return 21;
  if(F(actor,0x68)!=((reverse||fall)?0.0f:3.0f))return 22;
  if(actor[6]!=(fall?0:255) || animationCalls!=fall || advanceCalls!=1)return 23;
  if(fall && (group!=22 || event!=7))return 24;
  if(actor[0x15b] || actor[0x1b5]!=42 || H(counters,0x7e)!=1)return 25;
 }
 for(t=0;t<2;t++)for(command=0;command<2;command++) {
  reset();memset(actor,0,sizeof(actor));actor[2]=1;actor[6]=255;
  actor[0x269]=6;actor[0x1e6]=t;actor[0x15b]=command?77:0;
  H(actor,0x1c)=99;F(actor,0x430)=123;F(actor,0x60)=8;
  func_002CFA90(actor);
  if(actor[6]!=0 || actor[0x404]!=255 || actor[0x405]!=16 || H(actor,0x1c))return 30;
  if(F(actor,0x38)!=123 || F(actor,0x5c)!=(t?7.5f:-7.5f))return 31;
  if(F(actor,0x60) || F(actor,0x68) || F(actor,0x6c) || actor[0x20d])return 32;
  if(setupCalls!=1 || prepareCalls!=1 || animationCalls!=1 || group!=22 || event!=5)return 33;
  if(actor[0x15b] || actor[0x1b5]!=(command?77:88) || H(counters,0x7e)!=1+command)return 34;
 }
 return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            source=Path(temporary)/'transitions.c';binary=Path(temporary)/'transitions'
            source.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror',str(source),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            return subprocess.run([str(binary)],timeout=10).returncode

    def test_native_motion_timers_landing_and_command_consumption(self):
        self.assertEqual(self.run_transitions(),0)

    def test_reversed_horizontal_clamp_is_detected(self):
        self.assertNotEqual(self.run_transitions(wrong_clamp=True),0)
