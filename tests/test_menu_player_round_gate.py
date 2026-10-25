"""Check bounded player slots, round guards and post-helper state reload."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class MenuPlayerRoundGateTests(unittest.TestCase):
    def run_gate(self, wrong_owner=False, stale_flags=False):
        source=(ROOT/'src/menu_player_round_gate_00133970.c').read_text()
        source=source.replace(' __attribute__((section(".sdata")))','')
        dispatch=states.function('src/composite_dispatch_heads.c','func_00133950')
        if wrong_owner:
            changed=dispatch.replace('(p,owner)','(p,p)')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if stale_flags:
            changed=source.replace('u32 selection=', 'u8 flags=D_004C2840[0x18];\n  u32 selection=').replace('*(s8*)(D_004C2840+0x18)','(s8)flags')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
'''+source+r'''
u8 D_004D18A0[3];
u8 *D_004C2840;
static u8 *seenActor,*seenOwner;
static int setup,sound,wrongThird;
void func_001345C0(u8 *p,u8 *q,u32 n) {
 setup++;seenActor=p;seenOwner=q;if(n)wrongThird++;
 /* The callee boundary may change scene state before the sound guard. */
 D_004C2840[0x18]^=3;
}
void func_001E3CE0(int n) {if(n!=10)wrongThird++;sound++;}
static void other(u8 *p,u8 *q) {(void)p;(void)q;}
void (*const jtbl_0043E918[3])(u8*,u8*)={func_00133970,other,other};
'''+dispatch+r'''
int main(void) {
 _Alignas(16) u8 p[0x200],q[0x200],scene[0x40],want[0x200];
 int modes[4]={-128,-1,2,3};
 int mode,round,selection,player,ownerSlot,flags;
 D_004C2840=scene;
 for(mode=0;mode<4;mode++)for(round=0;round<7;round++)
 for(selection=0;selection<256;selection++)for(player=0;player<2;player++)
 for(ownerSlot=0;ownerSlot<3;ownerSlot++)for(flags=0;flags<4;flags++) {
  int eligible=modes[mode]==2&&round==4&&selection!=0;
  int same=ownerSlot==(selection&127);
  memset(p,0x5A,sizeof(p));memset(q,0xA5,sizeof(q));memset(scene,0,sizeof(scene));
  p[2]=player;p[5]=0;q[2]=ownerSlot;
  scene[2]=(u8)modes[mode];scene[0x18]=flags;
  D_004D18A0[0]=round;D_004D18A0[2]=selection;
  memcpy(want,p,sizeof(p));
  if(eligible){if(!same){want[5]=0;want[0x20]=1;}
   else{want[5]=1;want[0x14C]=0;*(short*)(want+0x1C)=0;}}
  setup=sound=wrongThird=0;seenActor=seenOwner=0;
  func_00133950(p,q);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(setup!=(eligible&&same))return 2;
  if(setup&&(seenActor!=p||seenOwner!=q))return 3;
  if(sound!=(eligible&&same&&((flags^3)&(1U<<player))!=0))return 4;
  if(wrongThird)return 5;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_round_guards_identifiers_and_reloaded_sound_flags(self):
        self.assertEqual(self.run_gate(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_gate(wrong_owner=True),0)

    def test_stale_scene_flags_are_detected(self):
        self.assertNotEqual(self.run_gate(stale_flags=True),0)
