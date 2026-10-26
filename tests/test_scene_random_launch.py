"""Check scene gating, real RNG consumption and the character-specific override."""
import re
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SceneRandomLaunchTests(unittest.TestCase):
    def run_launch(self,missing_override=False,missing_random=False):
        source=(ROOT/'src/scene_random_launch_00323250.c').read_text()
        if missing_override:
            changed=source.replace('if(parent[1]==58)choice=p[2];','')
            self.assertNotEqual(changed,source);source=changed
        if missing_random:
            changed=source.replace('choice=func_00174170()&1','choice=0')
            self.assertNotEqual(changed,source);source=changed
        table=(ROOT/'src/data/jtbl_0045DEB0.c').read_text()
        unused=sorted(set(re.findall(r'extern void (func_\w+)\(u8 \*\);',table))-{'func_00323250'})
        code=r'''
#include <string.h>
'''+source+'\n'+table+'\n'+(ROOT/'src/random_state_step.c').read_text()+r'''
#define jtbl_0045DED0 (jtbl_0045DEB0+8)
'''+states.function('src/composite_dispatch_heads.c','func_00323230')
        code+='\n'.join(f'void {name}(u8 *p){{(void)p;}}' for name in unused)
        code+=r'''
u8 D_004D18A0,D_004C26AC,D_004C26B0;
static int events,animations,wrong,expectedChoice;
static u8 *expected;
void func_001E0760(void *p,u8 mode){events++;if(p!=expected||mode||((u8*)p)[6]!=2||((u8*)p)[0x20D])wrong++;}
int func_001757E0(u8 *p,int a,int b){animations++;if(p!=expected||a!=18||b!=expectedChoice||events!=(expectedChoice==0))wrong++;return 0;}
#define F(p,n) (*(float*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600];
 const int scenes[4]={0,1,2,255};int scene,kind,player;
 unsigned state,next,step;
 for(scene=0;scene<4;scene++)for(kind=0;kind<2;kind++)for(player=0;player<2;player++)for(state=0;state<65536;state++) {
  int active=scenes[scene]>=2,choice;
  step=(state*3)>>8;next=(((state&255)+step)&255)|((step&255)<<8);
  choice=kind?player:(next&1);
  memset(p,0x5A,sizeof(p));memset(q,0,sizeof(q));
  p[6]=0;p[2]=player;*(u8**)(p+0x220)=q;q[1]=kind?58:0;F(p,0x38)=-27.5f;
  memcpy(want,p,sizeof(p));want[0x13C]=active;
  if(active){
   if(!choice){want[6]=2;want[0x20D]=0;}
   else{want[6]=1;want[0x20D]=2;F(want,0x38)=-27.5f+(15.0f/7.0f)*256;F(want,0x60)=0;F(want,0x6C)=-(15.0f/7.0f)*3/16;}
  }
  D_004D18A0=scenes[scene];D_004C26AC=state&255;D_004C26B0=state>>8;
  expected=p;expectedChoice=choice;events=animations=wrong=0;
  func_00323230(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(events!=(active&&!choice)||animations!=active||wrong)return 2;
  if((D_004C26AC|(D_004C26B0<<8))!=(active?next:state))return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_real_rng_scene_gates_parent_override_and_launch_fields(self):
        self.assertEqual(self.run_launch(),0)

    def test_missing_character_override_is_detected(self):
        self.assertNotEqual(self.run_launch(missing_override=True),0)

    def test_missing_random_consumption_is_detected(self):
        self.assertNotEqual(self.run_launch(missing_random=True),0)
