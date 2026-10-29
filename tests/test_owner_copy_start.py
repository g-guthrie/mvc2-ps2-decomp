"""Exercise the copied owner state through its actual phase dispatcher."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerCopyStartTests(unittest.TestCase):
    def run_copy(self, wrong_owner=False, short_copy=False):
        source=(ROOT/'src/actor_owner_copy_start_0019d860.c').read_text()
        dispatch=states.function('src/argument_dispatch_heads.c','func_0019D830')
        if wrong_owner:
            changed=dispatch.replace('*(u8 **)(p + 212)','p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if short_copy:
            changed=source.replace('typedef ActorState Fields;','typedef struct { unsigned char b[0xC0]; } Fields;')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
#include "actor_effect_work_callbacks.h"
'''+source+r'''
static int calls,animation,frame;
static u8 *seen;
int func_001754A0(u8 *p,int a,int b) {calls++;seen=p;animation=a;frame=b;return -1;}
void func_0019D970(u8 *p,u8 *q) {(void)p;(void)q;}
const ActorEffectWorkCallback jtbl_0044ABF0[2]={func_0019D860,func_0019D970};
'''+dispatch+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 const int kinds[6]={-128,-1,31,32,47,127};
 int active,k,i;
 for(active=0;active<2;active++)for(k=0;k<6;k++) {
  for(i=0;i<0x300;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[4]=0;p[0x20]=active;p[0x13C]=99;H(p,0x1C)=400;
  *(u8**)(p+212)=q;
  F(q,0x34)=-17.5f;F(q,0x38)=23.25f;F(q,0x3C)=64.0f;
  F(q,0x50)=3.5f;F(q,0x54)=4.5f;F(q,0x58)=-5.5f;
  H(q,0x13E)=120;q[0x161]=(u8)kinds[k];
  memcpy(want,p,sizeof(p));want[4]=1;
  if(!active) {want[0x13C]=0;H(want,0x1C)=0;}
  else {
   memcpy(want+0xEC,q+0xEC,196);
   want[0x13C]=1;
   want[2]=q[2];want[1]=q[1];
   memcpy(want+0x50,q+0x50,12);
   want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];
   want[0x24]=q[0x24];want[0x31]=1;H(want,0x13E)=124;
   memcpy(want+0x34,q+0x34,12);H(want,0x1E)=23;
  }
  calls=0;seen=0;func_0019D830(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(calls!=(active&&kinds[k]>=32))return 2;
  if(calls&&(seen!=p||animation!=28||frame!=(kinds[k]&15)))return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_full_copy_inactive_path_and_signed_animation_selector(self):
        self.assertEqual(self.run_copy(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_copy(wrong_owner=True),0)

    def test_incomplete_copy_is_detected(self):
        self.assertNotEqual(self.run_copy(short_copy=True),0)
