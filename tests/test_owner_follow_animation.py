"""Check owner position, signed animation selection and frame calls."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerFollowAnimationTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_follow_animation_00198fc0.c').read_text()
        # Keep the host's 64-bit owner pointer clear of the native 16-bit timer.
        body = body.replace('p+0x18', 'p+0x500')
        if mutation == 'sign':
            body = body.replace('if(state<0)', 'if(state>0)')
        if mutation == 'frame':
            body = body.replace('(u8)(p[0x22]+1)', '(u8)(p[0x22]+2)')
        if mutation == 'ground':
            body = body.replace('owner+0x430', 'owner+0x38')
        code = r'''
#include <string.h>
''' + body + r'''
static int calls,wrong,expected_state,expected_frame;static u8 *actor;
int func_00175580(u8*p,int anim,int frame,int state) {
 calls++;if(p!=actor || anim!=27 || frame!=expected_frame || state!=expected_state)wrong++;
 *(s16*)(p+0x1C)=222;return 0;
}
int main(void) {
 _Alignas(16) u8 p[0x600], owner[0x500];
 int signals[]={0,1,127,128,129,255};
 for(int k=0;k<6;k++)for(int same=0;same<2;same++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);actor=p;calls=wrong=0;
  *(u8**)(p+0x500)=owner;owner[0x161]=signals[k];p[0x22]=wrap?255:7;
  *(float*)(owner+0x34)=4;*(float*)(owner+0x38)=5;*(float*)(owner+0x3C)=6;
  *(float*)(owner+0x430)=17;*(float*)(owner+0x118)=0.5f;*(float*)(owner+0x50)=2;*(float*)(owner+0x54)=3;
  *(s16*)(owner+0x140)=-1;*(float*)(p+0x34)=-8;*(float*)(p+0x38)=-9;
  int state=signals[k]>=128?(signals[k]&127):signals[k];
  *(s16*)(p+0x1C)=same?state:234;expected_state=state;expected_frame=wrap?0:8;
  func_00198FC0(p);
  if(signals[k]==0) {
   if(p[0x13C] || *(s16*)(p+0x1C) || calls || *(float*)(p+0x34)!=-8 || *(float*)(p+0x38)!=-9) return 1;
  } else {
   if(p[0x13C]!=1 || *(s16*)(p+0x1C)!=state || calls!=(!same) || wrong ||
      *(float*)(p+0x34)!=4 || *(float*)(p+0x38)!=(signals[k]>=128?17:5) ||
      *(float*)(p+0x3C)!=6 || *(s16*)(p+0x140)!=-1 || *(float*)(p+0x118)!=0.5f ||
      *(float*)(p+0x50)!=2 || *(float*)(p+0x54)!=3) return 2;
  }
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_owner_follow_and_animation(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_sign_is_rejected(self):
        self.assertNotEqual(self.run_case('sign'), 0)

    def test_wrong_frame_is_rejected(self):
        self.assertNotEqual(self.run_case('frame'), 0)

    def test_wrong_ground_is_rejected(self):
        self.assertNotEqual(self.run_case('ground'), 0)
