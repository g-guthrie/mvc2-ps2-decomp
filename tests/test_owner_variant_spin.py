"""Exercise owner replacement across animation calls and signed spin expiry."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerVariantSpinTests(unittest.TestCase):
    def owner_case(self, mutation=None):
        source=(ROOT/'src/owner_variant_offset_start_001b82b0.c').read_text().replace('__attribute__((section(".sdata")))','')
        if mutation == 'omit_follow':
            source=source.replace('func_001B8610(p);','')
        if mutation == 'early_id':
            source=source.replace('func_001754A0(p,27,9);*D_004C26DC=*(u16*)(OWNER+0x168);','*D_004C26DC=*(u16*)(OWNER+0x168);func_001754A0(p,27,9);')
        code=r'''
#include <string.h>
typedef float f32;typedef short s16;
'''+source+states.function('src/z13_f.c','func_001B8610')+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(short*)((p)+(n)))
static u16 id,*unused;u16 *D_004C26DC=&id;
static u8 *actor,*replacement;static u8 initial[0x400],final[0x400];
static int wrong,anim,frame;
int func_001754A0(u8*p,int group,int index){
 anim++;if(p!=actor||group!=27||index!=9||frame||memcmp(p,initial,sizeof initial))wrong++;
 *(u8**)(p+0x18)=replacement;return -1;
}
int func_00175670(u8*p){frame++;if(p!=actor||anim!=1||id!=0x5678||memcmp(p,final,sizeof final))wrong++;return -1;}
void func_001B87B0(u8*p){(void)p;wrong++;}
int main(void){
 _Alignas(16) u8 p[0x400],q[0x400],r[0x400];
 int faces[]={0,1,-32768,256},variants[]={0,1,255},counts[]={0,255};
 for(int v=0;v<3;v++)for(int f=0;f<4;f++)for(int c=0;c<2;c++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);memset(r,0x34,sizeof r);
  actor=p;replacement=r;wrong=anim=frame=0;id=0x9999;
  p[4]=counts[c];*(u8**)(p+0x18)=q;
  q[0x1B7]=variants[v];S(q,0x140)=faces[f];S(q,0x168)=0x1234;S(r,0x168)=0x5678;
  F(q,0x34)=10;F(q,0x38)=-20;F(q,0x50)=2;F(q,0x54)=3;F(q,0x58)=4;
  F(r,0x34)=-100;F(r,0x38)=200;
  memcpy(initial,p,sizeof p);initial[4]=(unsigned char)(counts[c]+1);
  memcpy(initial+0xEC,q+0xEC,196);initial[0x13C]=1;
  initial[2]=q[2];initial[1]=q[1];memcpy(initial+0x50,q+0x50,12);
  initial[0x1B7]=q[0x1B7];initial[0x1B8]=q[0x1B8];initial[0x30]=q[0x30];initial[0x24]=0;
  float dx=variants[v]?35:60,dy=variants[v]?62.1428566f:49.2857132f;
  F(initial,0x34)=10+(faces[f]?dx:-dx);F(initial,0x38)=-20+dy;
  *(u32*)(initial+0x48)=variants[v]?0x1C00:0x2400;
  memcpy(final,initial,sizeof final);*(u8**)(final+0x18)=r;F(final,0x118)=.5f;
  dx=variants[v]?41.666664123535156f:60;
  F(final,0x34)=-100+(faces[f]?dx:-dx);F(final,0x38)=200+dy;
  func_001B82B0(p);
  if(wrong||anim!=1||frame!=1||memcmp(p,final,sizeof p)||id!=0x5678)return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def spin_case(self, mutation=None):
        source=(ROOT/'src/timed_spin_scale_001b9930.c').read_text()
        if mutation=='new_timer':
            source=source.replace('0.16f * *(s16*)(p+0x1C)','0.16f * (*(s16*)(p+0x1C)+1)')
        if mutation=='early_flags':
            source=source.replace('func_001E3210(p,45);D_004F1F45=3;D_004F1F46=1;','D_004F1F45=3;D_004F1F46=1;func_001E3210(p,45);')
        code='#include <string.h>\n'+source+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(s16*)((p)+(n)))
float D_004F1F4C=-27.5f,D_004F1FE8=12.25f;u8 D_004F1F45,D_004F1F46;
static u8 expected[0x400],*actor;static int wrong,anim,sound;
int func_001754A0(u8*p,int a,int b){anim++;if(p!=actor||a!=27||b!=17||sound||D_004F1F45!=9||D_004F1F46!=8||memcmp(p,expected,sizeof expected))wrong++;return 0;}
void func_001E3210(u8*p,int n){sound++;if(p!=actor||n!=45||anim!=1||D_004F1F45!=9||D_004F1F46!=8)wrong++;}
int main(void){
 _Alignas(16) u8 p[0x400];int times[]={-32768,-1,0,15,16,17,32767},faces[]={0,1,-32768,256};
 for(int t=0;t<7;t++)for(int f=0;f<4;f++)for(int counter=0;counter<2;counter++){
  memset(p,0xA5,sizeof p);actor=p;wrong=anim=sound=0;D_004F1F45=9;D_004F1F46=8;
  S(p,0x1C)=times[t];S(p,0x140)=faces[f];p[5]=counter?255:0;
  F(p,0x34)=10;F(p,0x38)=-2;F(p,0x5C)=-4;F(p,0x68)=.25f;
  F(p,0x50)=.5f;F(p,0x54)=2;*(u32*)(p+0x48)=0xFFFFFF80u;
  memcpy(expected,p,sizeof p);
  F(expected,0x34)=6;F(expected,0x5C)=-3.75f;*(u32*)(expected+0x48)=64;
  F(expected,0x50)=.532f;float scaled=(float)times[t]*.16f;F(expected,0x54)=2+scaled*scaled;
  s16 next=(s16)(times[t]+1);S(expected,0x1C)=next;int expired=next>16;
  if(expired){expected[5]=(u8)(expected[5]+1);F(expected,0x50)=F(expected,0x54)=1.5f;
   *(u32*)(expected+0x48)=0;F(expected,0x34)=faces[f]?572.5f:-627.5f;F(expected,0x38)=372.25f;}
  func_001B9930(p);
  if(wrong||anim!=expired||sound!=expired||memcmp(p,expected,sizeof p)||D_004F1F45!=(expired?3:9)||D_004F1F46!=(expired?1:8))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_owner_replacement_and_variants(self):self.assertEqual(self.owner_case(),0)
    def test_missing_follow_rejected(self):self.assertNotEqual(self.owner_case('omit_follow'),0)
    def test_stale_owner_id_rejected(self):self.assertNotEqual(self.owner_case('early_id'),0)
    def test_signed_timer_expiry(self):self.assertEqual(self.spin_case(),0)
    def test_incremented_timer_growth_rejected(self):self.assertNotEqual(self.spin_case('new_timer'),0)
    def test_early_camera_flags_rejected(self):self.assertNotEqual(self.spin_case('early_flags'),0)
