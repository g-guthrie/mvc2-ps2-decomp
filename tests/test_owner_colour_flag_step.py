"""Check identity/flag gating and current-owner palette or termination callbacks."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class OwnerColourFlagStepTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/owner_colour_flag_step_001cf0b0.c').read_text().replace('__attribute__((section(".sdata")))','')
        if mutation=='owner':body=body.replace('func_00175C00(*(u8**)(p+0x18),0)','func_00175C00((u8*)owner,0)',1)
        if mutation=='frame':body=body.replace('(s8)func_00175670(p)','func_00175670(p)')
        if mutation=='flag':body=body.replace('if(value){','if(value==1){')
        root=states.function('src/composite_dispatch_heads.c','func_001CF090')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
struct Object;extern void func_003DAA40(struct Object*);extern void func_001CF6C0(u8*);
extern void func_00176160(u8*,int,int,int);extern u8 *D_004C2840;
void func_001CF0B0(u8*);
void (*const jtbl_0044DE60[15])(u8*)={[0]=func_001CF0B0,[1]=func_001CF0B0,[2]=func_001CF0B0,[3]=func_001CF0B0,[4]=func_001CF0B0,[5]=func_001CF0B0,[12]=func_001CF0B0};
'''+root+body+states.function('src/leaf_batch_b.c','func_001CF6F0')+states.function('src/h5b.c','func_001CF720')+states.function('src/tail_leaves.c','func_001CF6A0')+states.function('src/tail_leaves.c','func_001CF6C0')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u16 stored;u16 *D_004C2718=&stored;static _Alignas(16) u8 global0[64],global1[64];u8 *D_004C2840=global0;
static u8 *actor,*oldOwner,*alternate,*current,beforeFrame[0x600],beforeEnd[0x600],final[0x600],wantedOld[0x600],wantedAlt[0x600];
static int wrong,frames,sets,frees,colours,result,swap,expectedIndex,oldParity;
int func_00175670(u8*p){frames++;if(p!=actor||sets||frees||colours||oldOwner[0x161]||memcmp(p,beforeFrame,sizeof beforeFrame))wrong++;if(swap)*(u8**)(p+0x18)=alternate;D_004C2840=global1;return result;}
void func_00175C00(u8*p,int n){sets++;if(p!=current||n||frees||colours||memcmp(actor,beforeEnd,sizeof beforeEnd))wrong++;}
void func_003DAA40(struct Object*p){frees++;if((u8*)p!=actor||sets!=1||colours||memcmp(actor,final,sizeof final))wrong++;}
void func_00176160(u8*p,int a,int b,int c){colours++;if(p!=current||a!=1||b!=expectedIndex||c!=1||sets||frees||memcmp(actor,final,sizeof final))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600],r[0x600];int flags[]={-128,-1,0,1,127},returns[]={-1,0,127,128,255,256},palettes[]={0,1,127,255},selectors[]={0,5,12};
 for(int same=0;same<2;same++)for(int flag=0;flag<5;flag++)for(int ret=0;ret<6;ret++)for(int changed=0;changed<2;changed++)for(int parity=0;parity<2;parity++)for(int pal=0;pal<4;pal++)for(int wrap=0;wrap<2;wrap++)for(int sel=0;sel<3;sel++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);memset(r,0x34,sizeof r);actor=p;oldOwner=q;alternate=r;wrong=frames=sets=frees=colours=0;result=returns[ret];swap=changed;oldParity=parity;
  p[4]=wrap?255:0;p[0x20]=selectors[sel];*(u8**)(p+0x18)=q;q[0x24]=0xFD;q[0x25]=palettes[pal];r[0x25]=(palettes[pal]+7)&255;q[0x161]=(u8)flags[flag];r[0x161]=0x5A;
  *(u16*)(q+0x168)=0x1234;*(u16*)(r+0x168)=0x5678;stored=same?0x1234:0x1235;F(q,0x34)=10;F(q,0x38)=-20;F(r,0x34)=100;F(r,0x38)=200;
  *(u32*)(global0+0x1C)=parity;*(u32*)(global1+0x1C)=parity^1;D_004C2840=global0;
  memcpy(beforeFrame,p,sizeof p);F(beforeFrame,0x34)=10;F(beforeFrame,0x38)=-20;beforeFrame[0x13C]=1;beforeFrame[0x24]=q[0x24];beforeFrame[0x31]=254;
  int stepped=same&&flags[flag]!=0,ended=!same||(stepped&&(signed char)result<0);current=stepped&&changed?r:q;
  memcpy(beforeEnd,beforeFrame,sizeof beforeEnd);if(stepped&&changed)*(u8**)(beforeEnd+0x18)=r;
  memcpy(final,beforeEnd,sizeof final);if(ended){final[4]=(u8)(final[4]+1);final[0x13C]=0;}
  memcpy(wantedOld,q,sizeof q);memcpy(wantedAlt,r,sizeof r);if(stepped)wantedOld[0x161]=0;
  int frameParity=stepped?(parity^1):parity;expectedIndex=current[0x25]*2+(frameParity?0:1);
  func_001CF090(p);
  if(wrong||frames!=stepped||sets!=ended||frees!=ended||colours!=!ended||memcmp(p,final,sizeof p)||memcmp(q,wantedOld,sizeof q)||memcmp(r,wantedAlt,sizeof r))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_identity_flags_and_real_palette_cleanup_paths(self):self.assertEqual(self.run_case(),0)
    def test_stale_owner_reset_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
    def test_unsigned_frame_status_rejected(self):self.assertNotEqual(self.run_case('frame'),0)
    def test_event_one_only_rejected(self):self.assertNotEqual(self.run_case('flag'),0)
