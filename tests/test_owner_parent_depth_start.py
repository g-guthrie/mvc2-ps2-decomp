"""Check copied owner state, the separate parent depth and native mode rows."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerParentDepthStartTests(unittest.TestCase):
    def run_start(self,wrong_parent=False,wrong_owner=False):
        source=(ROOT/'src/owner_parent_depth_start_001dd520.c').read_text().replace('extern u8 D_0044ECE0[9];','')
        if wrong_parent:
            changed=source.replace('*(u8**)(p+0x18)','q')
            self.assertNotEqual(changed,source);source=changed
        if wrong_owner:
            changed=source.replace('func_001DD660(p,q)','func_001DD660(p,p)')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
struct Object;
void func_003DAA40(struct Object*);
'''+(ROOT/'src/data/data_u32_0044ECE0.c').read_text()+r'''
#define D_0044ECE0 (data_u32_0044ECE0.a)
'''+source+'\n'+(ROOT/'src/data/jtbl_0044ECD0.c').read_text()+'\n'+states.function('src/argument_dispatch_heads.c','func_001DD4F0')
        code+=states.function('src/simple_leaves.c','func_001DD880')+states.function('src/tail_leaves.c','func_001DD890')
        code+=r'''
static int animations,updates,releases,wrong,expectedAnimation;
static u8 *actor,*owner,*wanted;
int func_001754A0(u8 *p,int a,int b){animations++;if(p!=actor||a!=27||b!=expectedAnimation)wrong++;return 0;}
/* Check the actual complex updater's input and initialized-record boundary. */
void func_001DD660(u8 *p,u8 *q){updates++;if(animations!=1||p!=actor||q!=owner||memcmp(p,wanted,0x600))wrong++;}
void func_003DAA40(struct Object *p){releases++;if((u8*)p!=actor||((u8*)p)[0x13C])wrong++;}
#define F(p,n) (*(float*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],parent[0x600],want[0x600];
 const int depths[4]={-128,-1,0,127},ids[9]={14,13,16,17,18,19,20,21,22};
 int mode,depth,direct,i;
 for(mode=0;mode<9;mode++)for(depth=0;depth<4;depth++)for(direct=0;direct<2;direct++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);parent[i]=0;}
  p[4]=direct?255:0;p[0x20]=mode;*(u8**)(p+0x18)=direct?parent:q;
  q[0x24]=direct?42:(u8)depths[depth];parent[0x24]=(u8)depths[depth];
  F(q,0x34)=14.25f;F(q,0x38)=-36.5f;F(q,0x3C)=80.75f;
  F(q,0x50)=1.25f;F(q,0x54)=-2.5f;F(q,0x58)=4.75f;
  memcpy(want,p,sizeof(p));memcpy(want+0xEC,q+0xEC,196);want[0x13C]=1;
  want[2]=q[2];want[1]=q[1];memcpy(want+0x50,q+0x50,12);
  want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];
  want[4]=(u8)(p[4]+1);want[0x31]=255;want[0x24]=mode==1?(u8)depths[depth]:8;
  memcpy(want+0x34,q+0x34,12);
  actor=p;owner=q;wanted=want;expectedAnimation=ids[mode];animations=updates=releases=wrong=0;
  if(direct)func_001DD520(p,q);else func_001DD4F0(p);
  if(memcmp(p,want,sizeof(p))||animations!=1||updates!=1||releases||wrong)return 1;
 }
 /* The same typed root selects its real no-op and release callbacks. */
 p[4]=2;memcpy(want,p,sizeof(p));actor=p;wrong=releases=0;
 func_001DD4F0(p);if(memcmp(p,want,sizeof(p)))return 2;
 p[4]=3;p[0x13C]=1;func_001DD4F0(p);if(releases!=1||wrong||p[0x13C])return 3;
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_nine_modes_separate_parent_depth_copy_phase_wrap_and_lifecycle(self):
        self.assertEqual(self.run_start(),0)

    def test_replacing_parent_depth_with_owner_depth_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_parent=True),0)

    def test_wrong_updater_owner_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)
