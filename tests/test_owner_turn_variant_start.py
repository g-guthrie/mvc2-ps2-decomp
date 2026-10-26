"""Check saved turn state, RNG selection and variant initialization boundaries."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class OwnerTurnVariantStartTests(unittest.TestCase):
    def turn_case(self,mutation=None):
        body=(ROOT/'src/owner_turn_start_001a9ef0.c').read_text()
        root=states.function('src/composite_gp_dispatch_heads.c','func_001A9ED0')
        outer=states.function('src/composite_dispatch_heads.c','func_001A9700')
        if mutation=='owner':root=root.replace('(p,owner)','(p,p)')
        if mutation=='saved_phase':body=body.replace('*(int*)(p+0xD4)=p[7]','*(int*)(p+0xD4)=p[7]-1')
        if mutation=='signed_rng':body=body.replace('(unsigned int)func_00174170()','func_00174170()')
        code=r'''
#include <string.h>
#include <math.h>
typedef unsigned char u8;typedef short s16;typedef int s32;typedef float f32;
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(s16*)((p)+(n)))
#define I(p,n) (*(int*)((p)+(n)))
extern void func_001A9EF0(u8*,u8*),func_001A9ED0(u8*,u8*);
extern int func_00175700(u8*);extern void func_001AC3F0(u8*,u8*);
void (*const jtbl_004BF7E8[2])(u8*,u8*)={func_001A9EF0,0};
void (*const jtbl_0044B690[23])(u8*,u8*)={[6]=func_001A9ED0};
'''+outer+root+body+states.function('src/round3_1.c','func_001A9FE0')+r'''
static u8 *actor,*owner,atCall[0x600],after[0x600];
static int wrong,turn,anim,rng,frame,expire,wantAnim;static unsigned int randomValue;
int func_00174170(void){rng++;if(frame||anim||turn)wrong++;return (int)randomValue;}
int func_001757E0(u8*p,int a,int b){anim++;if(p!=actor||a!=23||b!=(int)(randomValue%3)||rng!=1||memcmp(p,atCall,sizeof atCall))wrong++;return -1;}
int func_00175700(u8*p){frame++;if(p!=actor||turn||anim!=wantAnim||rng!=wantAnim||memcmp(p,atCall,sizeof atCall))wrong++;return 0;}
void func_001AC3F0(u8*p,u8*q){expire++;if(p!=actor||q!=owner||memcmp(p,after,sizeof after))wrong++;}
void func_001AA040(u8*p,u8*q){turn++;if(p!=actor||q!=owner||anim||rng||frame||memcmp(p,after,sizeof after))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600];int faces[]={0,1,2,-1};float xs[]={-1,0,1,NAN};unsigned int values[]={0,1,2,0xFFFFFFFFu};
 for(int f=0;f<4;f++)for(int x=0;x<4;x++)for(int same=0;same<2;same++)for(int duration=1;duration<=2;duration++)for(int r=0;r<4;r++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(q,0x32,sizeof q);actor=p;owner=q;wrong=turn=anim=rng=frame=expire=0;
  p[4]=6;p[6]=3;p[7]=wrap?255:0;S(p,0x140)=faces[f];F(p,0x34)=xs[x];F(q,0x34)=0;S(p,0x1E)=duration;I(p,0xD0)=same?3:8;randomValue=values[r];
  memcpy(atCall,p,sizeof p);atCall[7]=(u8)(atCall[7]+1);
  F(atCall,0x5C)=F(atCall,0x68)=F(atCall,0x60)=F(atCall,0x6C)=0;
  int side=x==0;int turning=side!=faces[f];wantAnim=!turning&&!same;
  memcpy(after,atCall,sizeof after);
  if(turning){I(after,0xD0)=3;I(after,0xD4)=atCall[7];after[6]=11;after[7]=0;}
  else S(after,0x1E)=duration-1;
  if(wrap)func_001A9EF0(p,q);else func_001A9700(p,q);
  if(wrong||turn!=turning||anim!=wantAnim||rng!=wantAnim||frame!=!turning||expire!=(!turning&&duration==1)||memcmp(p,after,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def variant_case(self,mutation=None):
        body=(ROOT/'src/owner_variant_animation_start_001bbe60.c').read_text()
        root=states.function('src/argument_dispatch_heads.c','func_001BBE30').replace('p + 24','p + 0x580')
        if mutation=='owner':root=root.replace('*(void **)(p + 0x580)','p')
        if mutation=='group':body=body.replace('case 7:','case 6:')
        if mutation=='copy_extent':body=body.replace('count=49','count=48')
        code=r'''
#include <string.h>
typedef unsigned char u8;
void func_001BBE60(u8*,u8*);
void (*const jtbl_0044C0C0[2])(u8*,u8*)={func_001BBE60,0};
'''+root+body+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,expected[0x600];static int wrong,frames,wantFrame,wantIndex;
int func_001754A0(u8*p,int a,int b){frames++;if(p!=actor||a!=27||b!=wantIndex||memcmp(p,expected,sizeof expected))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600];
 for(int mode=0;mode<256;mode++)for(int depth=0;depth<2;depth++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);actor=p;wrong=frames=0;
  p[4]=0;p[0x23]=mode;*(u8**)(p+0x580)=q;q[0x24]=depth?0x80:0x7F;q[0x30]=depth?0xFF:0;
  F(q,0x34)=-10;F(q,0x38)=20;F(q,0x3C)=30;F(q,0x50)=2;F(q,0x54)=3;F(q,0x58)=4;
  q[0x1AE]=0x76;q[0x1AF]=0x54;
  memcpy(expected,p,sizeof p);expected[4]=1;memcpy(expected+0xEC,q+0xEC,196);expected[0x13C]=1;
  expected[2]=q[2];expected[1]=q[1];memcpy(expected+0x50,q+0x50,12);
  expected[0x1B7]=q[0x1B7];expected[0x1B8]=q[0x1B8];expected[0x30]=q[0x30];expected[0x24]=q[0x24];expected[0x31]=255;
  memcpy(expected+0x34,q+0x34,12);F(expected,0x118)=1;*(short*)(expected+0x1C)=0;
  wantFrame=mode==0||mode==1||mode==2||mode==7;wantIndex=mode==1?12:mode==2?13:11;
  func_001BBE30(p);
  if(wrong||frames!=wantFrame||memcmp(p,expected,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_owner_turn_and_nested_frame(self):self.assertEqual(self.turn_case(),0)
    def test_wrong_turn_owner_rejected(self):self.assertNotEqual(self.turn_case('owner'),0)
    def test_old_subphase_rejected(self):self.assertNotEqual(self.turn_case('saved_phase'),0)
    def test_signed_rng_rejected(self):self.assertNotEqual(self.turn_case('signed_rng'),0)
    def test_all_variant_selectors(self):self.assertEqual(self.variant_case(),0)
    def test_wrong_variant_owner_rejected(self):self.assertNotEqual(self.variant_case('owner'),0)
    def test_wrong_variant_case_rejected(self):self.assertNotEqual(self.variant_case('group'),0)
    def test_short_owner_copy_rejected(self):self.assertNotEqual(self.variant_case('copy_extent'),0)
