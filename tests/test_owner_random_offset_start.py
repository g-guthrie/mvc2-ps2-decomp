"""Exercise native owner copying and the real two-byte RNG through dispatch."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerRandomOffsetStartTests(unittest.TestCase):
    def run_start(self,wrong_owner=False,wide_mask=False):
        source=(ROOT/'src/owner_random_offset_start_0019d300.c').read_text()
        dispatch=states.function('src/argument_dispatch_heads.c','func_0019D2D0')
        if wrong_owner:
            changed=dispatch.replace('*(u8 **)(p + 24)','p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if wide_mask:
            changed=source.replace('func_00174170()&7','func_00174170()&15')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
typedef int s32;
'''+source+'\n'+(ROOT/'src/random_state_step.c').read_text()+r'''
u8 D_004C26AC,D_004C26B0;
static int setups,animation,frame,ended,frameResult;
static u8 *seen,*seenOwner;
int func_001754A0(u8 *p,int a,int b){setups++;seen=p;animation=a;frame=b;return 0;}
int func_00175670(u8 *p){seen=p;return frameResult;}
void func_0019D520(u8 *p,u8 *q){ended++;seen=p;seenOwner=q;}
'''+states.function('src/m99.c','func_0019D4A0')+r'''
const ActorEffectWorkCallback jtbl_0044ABD0[2]={func_0019D300,func_0019D4A0};
'''+dispatch+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
static unsigned next(unsigned value) {
 unsigned quotient=(3*value)>>8;
 return (((value&255)+quotient)&255)|((quotient&255)<<8);
}
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 int modes[3]={0,1,255},faces[3]={0,1,-1};
 unsigned seed,first,second;int mode,face,i;
 for(mode=0;mode<3;mode++)for(face=0;face<3;face++)for(seed=0;seed<65536;seed++) {
  int x=0,y=0;
  for(i=0;i<0x300;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[4]=0;p[0x20]=modes[mode];*(u8**)(p+24)=q;
  H(q,0x140)=faces[face];H(q,0x13E)=100;*(u16*)(q+0x168)=0xF102;
  F(q,0x34)=20.25f;F(q,0x38)=-13.5f;
  F(q,0x50)=1.25f;F(q,0x54)=-2.5f;F(q,0x58)=4.5f;
  memcpy(want,p,sizeof(p));want[4]=1;memcpy(want+0xEC,q+0xEC,196);
  want[0x13C]=1;want[2]=q[2];want[1]=q[1];
  memcpy(want+0x50,q+0x50,12);want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];
  want[0x30]=q[0x30];want[0x24]=q[0x24];want[0x31]=255;
  first=next(seed);second=next(first);
  if(modes[mode]) {x=(faces[face]?-15:15)+(first&7);y=37+(second&7);H(want,0x13E)=97;}
  F(want,0x34)=20.25f+(5.0f/3.0f)*x;F(want,0x38)=-13.5f+(15.0f/7.0f)*y;
  *(u32*)(want+0xD0)=0xF102;
  D_004C26AC=seed&255;D_004C26B0=seed>>8;setups=0;seen=0;
  func_0019D2D0(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(setups!=1||seen!=p||animation!=27||frame!=(u8)(modes[mode]+26))return 2;
  if((D_004C26AC|(D_004C26B0<<8))!=(modes[mode]?second:seed))return 3;
 }
 /* Run the actual second phase after the copied owner's frame identity. */
 ended=0;frameResult=0;seen=seenOwner=0;func_0019D2D0(p);
 if(ended||seen!=p)return 4;
 frameResult=-1;func_0019D2D0(p);
 if(ended!=1||seen!=p||seenOwner!=q)return 5;
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_full_state_copy_every_rng_state_and_real_second_phase(self):
        self.assertEqual(self.run_start(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)

    def test_widened_random_offsets_are_detected(self):
        self.assertNotEqual(self.run_start(wide_mask=True),0)
