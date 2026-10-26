"""Exercise owner-phase callback selection and post-callback flag handling."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerPhaseUpdateTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_phase_update_0036d7d0.c').read_text()
        if mutation == 'flag':
            body = body.replace('if(work[1])', 'if(work[0])')
        if mutation == 'owner':
            body = body.replace('u8 *work=owner+0x2B8;', 'u8 *work=*(u8 **)(p+0x18)+0x2B8;')
        code = r'''
#include <string.h>
''' + body + r'''
static u8 *actor, *old_owner, *new_owner;
static int selected, called, flag;
static void callback(u8 *p,int id) {
 if(p!=actor || id!=selected) called=-100; else called++;
 old_owner[0x2B9]=flag;
 *(u8 **)(p+0x18)=new_owner;
}
static void cb0(u8 *p){callback(p,0);}
static void cb1(u8 *p){callback(p,1);}
static void cb2(u8 *p){callback(p,2);}
StateFn const jtbl_00463D68[3]={cb0,cb1,cb2};
int main(void) {
 _Alignas(16) u8 a[0x200], old[0x300], replacement[0x300];
 for(selected=0;selected<3;selected++)for(flag=0;flag<2;flag++)for(int phase=0;phase<2;phase++) {
  memset(a,0,sizeof a);memset(old,0,sizeof old);memset(replacement,0,sizeof replacement);
  actor=a;old_owner=old;new_owner=replacement;called=0;
  *(u8 **)(a+0x18)=old;a[5]=selected;a[4]=phase?255:4;a[0x13C]=9;
  old[0x2B8]=3;old[0x2B9]=!flag;replacement[0x2B8]=7;replacement[0x2B9]=!flag;
  func_0036D7D0(a);
  if(called!=1 || a[4]!=(unsigned char)((phase?255:4)+flag) ||
    a[0x13C]!=(flag?0:9) || old[0x2B8]!=(flag?0:3) || replacement[0x2B8]!=7) return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_callback_and_snapshotted_owner(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_flag_is_rejected(self):
        self.assertNotEqual(self.run_case('flag'), 0)

    def test_reloading_owner_is_rejected(self):
        self.assertNotEqual(self.run_case('owner'), 0)
