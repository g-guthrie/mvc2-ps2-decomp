"""Check the native 4/8/8/3 callback ranges and their owner-dependent chain."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerVariantEventChainTests(unittest.TestCase):
    def run_chain(self,wrong_owner=False,missing_group=False,stale_event=False,reload_owner=False):
        init=(ROOT/'src/owner_variant_start_00395a30.c').read_text()
        init=init.replace('extern void (*const jtbl_00472420[8])(u8*,void*);','')
        depth=(ROOT/'src/owner_depth_phase_00396200.c').read_text().replace('extern void (*const jtbl_00472460[3])(u8*,void*);','')
        event=(ROOT/'src/owner_event_offset_00396230.c').read_text()
        main=states.function('src/composite_dispatch_heads.c','func_003961E0')
        if wrong_owner:
            changed=main.replace('(p,owner_context)','(p,p)')
            self.assertNotEqual(changed,main);main=changed
        if missing_group:
            changed=depth.replace('+*(s8*)(p+0x31)','')
            self.assertNotEqual(changed,depth);depth=changed
        if stale_event:
            changed=event.replace('func_00175700(p);','{s8 saved=*(s8*)(p+0x151);func_00175700(p);').replace('if(*(s8*)(p+0x151)!=0)','if(saved!=0)').replace(' func_001E7F60(p);',' }\n func_001E7F60(p);')
            self.assertNotEqual(changed,event);event=changed
        if reload_owner:
            changed=init.replace('func_003961E0(p,q)','func_003961E0(p,*(void**)(p+0x18))')
            self.assertNotEqual(changed,init);init=changed
        code=r'''
#include <string.h>
struct Object;
void func_003DAA40(struct Object*);
'''+(ROOT/'src/data/jtbl_00472410.c').read_text()+r'''
#define jtbl_00472420 (jtbl_00472410+4)
#define jtbl_00472440 (jtbl_00472410+12)
#define jtbl_00472460 (jtbl_00472410+20)
'''+init+'\n'+depth+'\n'+event+'\n'+main+states.function('src/argument_dispatch_heads.c','func_00395A00')
        code+=states.function('src/straight_leaves.c','func_00396C50')+states.function('src/tail_leaves.c','func_00396C70')
        code+=r'''
static int variants,mains,frames,footers,releases,wrong,eventFlag,mode,phase;
static u8 *actor,*owner,*baseWanted,*finalWanted,*alternate;
#define F(p,n) (*(float*)((p)+(n)))
static void variant(u8 *p,void *q,int key) {
 int keys[8]={0,0,2,3,4,5,0,0};variants++;
 if(p!=actor||q!=owner||key!=keys[mode]||memcmp(p,baseWanted,0x600))wrong++;
 *(s8*)(p+0x31)=(mode&1)?3:-2;F(p,0x34)=5.5f;F(p,0x38)=6.5f;
 if(mode==7){*(u8**)(p+0x18)=alternate;p[4]=2;}
}
#define INIT(name,key) void name(u8*p,void*q){variant(p,q,key);}
INIT(func_00395B30,0)
INIT(func_00395E10,2)
INIT(func_00395ED0,3)
INIT(func_00395FF0,4)
INIT(func_00396030,5)
static void main_other(u8 *p,void *q,int key) {
 int keys[8]={0,0,2,3,4,5,6,6};mains++;
 if(p!=actor||q!=owner||variants!=1||key!=keys[mode]||memcmp(p,finalWanted,0x600))wrong++;
}
#define MAIN(name,key) void name(u8*p,void*q){main_other(p,q,key);}
MAIN(func_003964B0,2)
MAIN(func_003966A0,3)
MAIN(func_003967D0,4)
MAIN(func_00396940,5)
MAIN(func_00396A40,6)
static void nested(u8 *p,void *q,int selected) {
 mains++;
 if(p!=actor||q!=owner||variants!=1||selected!=phase||memcmp(p,finalWanted,0x600))wrong++;
}
void func_003962E0(u8*p,void*q){nested(p,q,1);}
void func_00396430(u8*p,void*q){nested(p,q,2);}
int func_00175700(u8 *p) {
 mains++;frames++;
 if(p!=actor||variants!=1||F(p,0x34)!=F(owner,0x34)||F(p,0x38)!=F(owner,0x38)||p[0x24]!=finalWanted[0x24])wrong++;
 p[0x151]=(u8)eventFlag;return -1;
}
void func_001E7F60(u8 *p){footers++;if(p!=actor||frames!=1||memcmp(p,finalWanted,0x600))wrong++;}
void func_003DAA40(struct Object *p){releases++;if((u8*)p!=actor||((u8*)p)[0x13C])wrong++;}
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],aux[0x600],base[0x600],want[0x600];
 int events[3]={0,1,-128},faces[3]={0,1,-1},depths[4]={-128,-1,0,127};
 int e,f,d,direct,i,group;
 for(mode=0;mode<8;mode++)for(phase=0;phase<3;phase++)for(e=0;e<3;e++)for(f=0;f<3;f++)for(d=0;d<4;d++)for(direct=0;direct<2;direct++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);aux[i]=0;}
  p[4]=direct?255:0;p[5]=phase;p[0x20]=mode;*(u8**)(p+0x18)=q;
  F(q,0x34)=7.5f;F(q,0x38)=-3.25f;F(q,0x50)=1.25f;F(q,0x54)=2.5f;F(q,0x58)=-4.75f;
  *(short*)(q+0x140)=faces[f];q[0x24]=(u8)depths[d];q[0x151]=9;
  memcpy(base,p,sizeof(p));base[4]=(u8)(p[4]+1);memcpy(base+0xEC,q+0xEC,196);base[0x13C]=1;
  base[2]=q[2];base[1]=q[1];memcpy(base+0x50,q+0x50,12);
  base[0x1B7]=q[0x1B7];base[0x1B8]=q[0x1B8];base[0x30]=q[0x30];base[0x24]=q[0x24];
  memcpy(want,base,sizeof(p));group=(mode&1)?3:-2;want[0x31]=(u8)group;F(want,0x34)=5.5f;F(want,0x38)=6.5f;
  if(mode==7){*(u8**)(want+0x18)=aux;want[4]=2;}
  eventFlag=events[e];
  if(mode<2) {
   want[0x24]=(u8)(depths[d]+group);
   if(phase==0){
    F(want,0x34)=7.5f;F(want,0x38)=-3.25f;want[0x151]=(u8)eventFlag;
    if(eventFlag){want[0x151]=0;want[5]=1;if(mode==0){F(want,0x38)+=265.714264f;F(want,0x34)-=faces[f]?-133.333328f:133.333328f;}}
   }
  }
  actor=p;owner=q;baseWanted=base;finalWanted=want;alternate=aux;
  variants=mains=frames=footers=releases=wrong=0;
  if(direct)func_00395A30(p,q);else func_00395A00(p);
  if(memcmp(p,want,sizeof(p))||variants!=1||mains!=1||releases||wrong)return 1;
  if(frames!=(mode<2&&phase==0)||footers!=(mode<2&&phase==0))return 2;
 }
 p[4]=2;p[0x13C]=1;actor=p;releases=wrong=0;func_00395A00(p);
 if(p[4]!=3||p[0x13C])return 3;
 func_00395A00(p);if(releases!=1||wrong)return 4;
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_full_variant_depth_event_chain_and_shared_lifecycle(self):
        self.assertEqual(self.run_chain(),0)

    def test_wrong_main_owner_is_detected(self):
        self.assertNotEqual(self.run_chain(wrong_owner=True),0)

    def test_missing_signed_depth_group_is_detected(self):
        self.assertNotEqual(self.run_chain(missing_group=True),0)

    def test_stale_frame_event_is_detected(self):
        self.assertNotEqual(self.run_chain(stale_event=True),0)

    def test_reloading_changed_parent_instead_of_supplied_owner_is_detected(self):
        self.assertNotEqual(self.run_chain(reload_owner=True),0)
