"""Check all four native six-byte rows and owner-relative velocity setup."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerVelocityStartTests(unittest.TestCase):
    def run_start(self,wrong_owner=False,wide_random=False):
        source=(ROOT/'src/owner_velocity_start_00195d30.c').read_text()
        dispatch=states.function('src/composite_gp_dispatch_heads.c','func_00195F40')
        if wrong_owner:
            changed=dispatch.replace('(p,owner)','(p,p)')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if wide_random:
            changed=source.replace('func_00417A40()&3','func_00417A40()&7')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
'''+source+r'''
/* Column views of the native rows, with six-byte stride. */
s16 D_00449FC0[4][3]={{-25,23,2},{-8,28,2},{-12,22,2},{-33,22,2}};
s16 D_00449FC2[4][3]={{23,2,0},{28,2,0},{22,2,0},{22,2,0}};
s8 D_00449FC4[4][6]={{2},{2},{2},{2}};
static int noop,rng,animation,wrong;
static unsigned seed;
static u8 *seen;
void func_00197600(void) {noop++;}
unsigned func_00417A40(void) {if(noop!=1)wrong++;rng++;return seed;}
int func_00175580(u8 *p,int a,int b,int c) {
 if(noop!=1||rng!=1||a!=27||b!=8||c!=(int)(seed&3))wrong++;
 animation++;seen=p;return 0;
}
static void update(u8 *p,u8 *q) {(void)p;(void)q;}
void (*const jtbl_004BF578[2])(u8*,u8*)={func_00195D30,update};
'''+dispatch+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 int style,face,k;
 int facing[3]={0,1,-1};
 for(style=0;style<256;style++)for(face=0;face<3;face++)for(k=0;k<8;k++) {
  memset(p,0x5A,sizeof(p));memset(q,0xA5,sizeof(q));
  p[5]=0;p[0x21]=style;H(q,0x140)=facing[face];
  F(q,0x34)=81.5f;F(q,0x38)=-23.25f;
  memcpy(want,p,sizeof(p));want[5]=1;
  if(style<4) {
   H(want,0x140)=facing[face];F(want,0x34)=81.5f;F(want,0x38)=-23.25f;
   F(want,0x5C)=(5.0f/3.0f)*D_00449FC0[style][0];
   F(want,0x60)=(15.0f/7.0f)*D_00449FC2[style][0];
   want[0x31]=2;if(!facing[face])F(want,0x5C)=-F(want,0x5C);
  }
  noop=rng=animation=wrong=0;seen=0;seed=k;
  func_00195F40(p,q);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(noop!=(style<4)||rng!=(style<4)||animation!=(style<4)||wrong)return 2;
  if(animation&&seen!=p)return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_rows_facing_bounds_and_random_animation_frame(self):
        self.assertEqual(self.run_start(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)

    def test_wide_random_mask_is_detected(self):
        self.assertNotEqual(self.run_start(wide_random=True),0)
