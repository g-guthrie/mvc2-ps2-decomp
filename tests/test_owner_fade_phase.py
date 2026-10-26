"""Exercise the owner-state gate, fade clamp and signed animation flag."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerFadePhaseTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_fade_phase_003718b0.c').read_text()
        if mutation == 'owner':
            body = body.replace('owner[6]!=2', 'owner[6]==2')
        if mutation == 'signed':
            body = body.replace('*(s8*)(p+0x153)<0', '*(u8*)(p+0x153)<0')
        if mutation == 'clamp':
            body = body.replace('if(*(float*)(p+0x118)<0.0f)', 'if(*(float*)(p+0x118)>0.0f)')
        code = r'''
#include <string.h>
''' + body + r'''
static int calls; static u8 *actor;
int func_00175700(u8*p) { if(p!=actor)return -1; calls++;return 0; }
int main(void) {
 _Alignas(16) u8 p[0x300], owner[32];
 float values[]={0.0f,0.01f,0.06f,0.2f,-0.1f};
 int flags[]={0,127,128,255};
 for(int state=0;state<4;state++)for(int i=0;i<5;i++)for(int j=0;j<4;j++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);actor=p;calls=0;
  *(u8**)(p+0x18)=owner;owner[6]=state;p[4]=wrap?255:7;p[5]=wrap?255:9;p[0x13C]=8;p[0x153]=flags[j];
  *(float*)(p+0x118)=values[i];
  float expected=values[i];if(state==2 && expected!=0.0f) {expected-=0.05999999865889549f;if(expected<0.0f)expected=0.0f;}
  func_003718B0(p);
  int ended=flags[j]>=128;
  if(p[4]!=(u8)((wrap?255:7)+(state!=2)) || p[5]!=(u8)((wrap?255:9)+(state==2 && ended)) ||
     p[0x13C]!=(state==2 && ended?0:8) || calls!=(state==2 && !ended) || *(float*)(p+0x118)!=expected) return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_fade_and_transition(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_owner_state_is_rejected(self):
        self.assertNotEqual(self.run_case('owner'), 0)

    def test_unsigned_animation_flag_is_rejected(self):
        self.assertNotEqual(self.run_case('signed'), 0)

    def test_wrong_clamp_is_rejected(self):
        self.assertNotEqual(self.run_case('clamp'), 0)
