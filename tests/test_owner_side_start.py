"""Check the bounded side selector and real nested owner/frame callbacks."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerSideStartTests(unittest.TestCase):
    def run_side(self,wrong_owner=False,wrong_side=False):
        source=(ROOT/'src/owner_side_start_001a7160.c').read_text().replace(' __attribute__((section(".sdata")))','')
        inner=states.function('src/composite_dispatch_heads.c','func_001A7320')
        if wrong_owner:
            changed=inner.replace('(p,owner_context)','(p,p)')
            self.assertNotEqual(changed,inner);inner=changed
        if wrong_side:
            changed=source.replace('D_004BF768[p[0x21]]','D_004BF768[0]')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
typedef float f32;
struct Object;
void func_003DAA40(struct Object*);
int func_00175670(unsigned char*);
int func_00175700(unsigned char*);
'''+source+'\n'+(ROOT/'src/data/jtbl_0044B420.c').read_text()+'\n'+(ROOT/'src/data/jtbl_0044B430.c').read_text()+'\n'
        code+=r'''
extern Mvc2OwnerStateCallback const D_004BF790[14];
'''+states.function('src/argument_dispatch_heads.c','func_001A7130')+inner+states.function('src/wave11b.c','func_001A72C0')
        code+=states.function('src/tail_leaves.c','func_001A72B0')+states.function('src/negative_incrementers.c','func_001A74B0')
        code+=states.function('src/duplicate_family.c','func_001A78A0')+states.function('src/tail_leaves.c','func_001A78C0')
        code+=r'''
s16 D_004BF768[2]={64,-64};
static int setups,shortFrames,fullFrames,releases,wrong,result;
static u8 *expected;
int func_001754A0(u8 *p,int a,int b){setups++;if(p!=expected||a!=27||b)wrong++;return 0;}
int func_00175670(u8 *p){shortFrames++;if(p!=expected||setups!=1)wrong++;return result;}
int func_00175700(u8 *p){fullFrames++;if(p!=expected||setups!=1)wrong++;return result;}
void func_003DAA40(struct Object *p){releases++;if((u8*)p!=expected)wrong++;}
static void unused(u8 *p,void*q){(void)p;(void)q;}
const Mvc2OwnerStateCallback D_004BF790[14]={func_001A72B0,func_001A74B0,unused,unused,unused,unused,unused,unused,unused,unused,unused,unused,unused,unused};
void func_001A7540(u8*p,void*q){(void)p;(void)q;}
void func_001A7880(u8*p,void*q){(void)p;(void)q;}
void func_001A7340(u8*p,void*q){(void)p;(void)q;}
void func_001A7500(u8*p,void*q){(void)p;(void)q;}
void func_001A7720(u8*p,void*q){(void)p;(void)q;}
void func_001A7750(u8*p,void*q){(void)p;(void)q;}
void func_001A7810(u8*p,void*q){(void)p;(void)q;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600];
 int statuses[4]={0,-1,128,256};int side,kind,phase,status,wrap,i;
 for(side=0;side<2;side++)for(kind=0;kind<2;kind++)for(phase=0;phase<2;phase++)for(status=0;status<4;status++)for(wrap=0;wrap<2;wrap++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[4]=wrap?255:0;p[5]=phase;p[0x20]=0;p[0x21]=side;*(u8**)(p+0x18)=q;
  q[0x169]=kind?19:18;H(q,0x140)=1-side;q[0x24]=0x80;
  F(q,0x34)=12.5f;F(q,0x38)=-23.75f;F(q,0x3C)=80.5f;
  F(q,0x50)=1.25f;F(q,0x54)=2.5f;F(q,0x58)=-4.75f;
  memcpy(want,p,sizeof(p));memcpy(want+0xEC,q+0xEC,196);want[4]=(u8)(p[4]+1);want[0x13C]=1;
  want[2]=q[2];want[1]=q[1];memcpy(want+0x50,q+0x50,12);want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];want[0x24]=q[0x24];want[0x31]=255;
  memcpy(want+0x34,q+0x34,12);H(want,0x140)=side;F(want,0x34)+=(5.0f/3)*D_004BF768[side];
  if(!kind)want[4]++;
  else if(phase==1&&(s8)statuses[status]<0){want[4]++;want[0x13C]=0;}
  expected=p;result=statuses[status];setups=shortFrames=fullFrames=releases=wrong=0;
  if(wrap)func_001A7160(p,q);else func_001A7130(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(setups!=1||shortFrames!=(kind&&phase==0)||fullFrames!=(kind&&phase==1)||releases||wrong)return 2;
 }
 p[4]=2;p[0x13C]=1;expected=p;releases=wrong=0;func_001A7320(p,q);
 if(p[4]!=3||p[0x13C])return 3;func_001A7320(p,q);if(releases!=1||wrong)return 4;
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_both_sides_owner_gate_real_frame_children_and_lifecycle(self):
        self.assertEqual(self.run_side(),0)

    def test_dropped_owner_is_detected(self):
        self.assertNotEqual(self.run_side(wrong_owner=True),0)

    def test_wrong_side_lookup_is_detected(self):
        self.assertNotEqual(self.run_side(wrong_side=True),0)
