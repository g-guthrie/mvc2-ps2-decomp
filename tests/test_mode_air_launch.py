"""Check native launch constants, setup-time inputs and two-byte work output."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class ModeAirLaunchTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/actor_mode_air_launch_002cdb90.c').read_text().replace('__attribute__((section(".sdata")))','')
        # The production target has 32-bit pointers; widen only the host fixture's address arithmetic.
        old='{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}'
        new='{uintptr_t a=p[2]*2;a+=(uintptr_t)D_004C2794;a+=0x7C;++*(s16*)a;}'
        self.assertIn(old,body);body=body.replace(old,new)
        if mutation=='drag':body=body.replace('0.7291666269302368f','0.8333333134651184f')
        if mutation=='column':body=body.replace('counts[1]=D_004C0F21','counts[1]=D_004C0F20')
        if mutation=='extent':body=body.replace('counts[1]=','counts[2]=')
        if mutation=='facing':body=body.replace('if(p[0x1E6])','if(*(s16*)(p+0x140))')
        root=states.function('src/argument_dispatch_heads.c','func_002CDB60')
        code=r'''
#include <stdint.h>
#include <string.h>
typedef unsigned char u8;typedef float f32;typedef int s32;
extern void func_0018C510(u8*,int);
void func_002CDB90(u8*,void*);
void (*const jtbl_0045A170[5])(u8*,void*)={func_002CDB90,0,0,0,0};
'''+root+body+states.function('src/h11d.c','func_00185490')+states.function('src/wave2.c','func_0018C4B0')+r'''
#define F(p,n) (*(float*)((p)+(n)))
u8 D_004C0F20[2][2],D_004C0F21[2][2];static u8 bank[0x100],wantedBank[0x100];u8 *D_004C2794=bank;
static u8 *actor,beforeSetup[0x600],final[0x600];static int wrong,step,team,mode,facing;
void func_0018C510(u8*p,int n){if(p!=actor||n!=10||step++!=0||memcmp(p,beforeSetup,sizeof beforeSetup))wrong++;p[2]=team;p[0x1B7]=mode;p[0x1E6]=facing;F(p,0x430)=95;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||step++!=1||a!=21||b!=mode+2||memcmp(p,final,sizeof final)||memcmp(bank,wantedBank,sizeof bank))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600],opponent[0x600];int faces[]={0,1,255},counts[]={-32768,-1,0,32767};
 for(int oldFace=0;oldFace<2;oldFace++)for(int m=0;m<2;m++)for(int f=0;f<3;f++)for(int t=0;t<2;t++)for(int c=0;c<4;c++)for(int wrap=0;wrap<2;wrap++)for(int perturb=0;perturb<2;perturb++){
  memset(p,0xA5,sizeof p);memset(opponent,0,sizeof opponent);memset(bank,0x3C,sizeof bank);actor=p;wrong=step=0;team=t;mode=m;facing=faces[f];
  p[6]=wrap?255:0;p[0x214]=0;p[0x1E6]=oldFace;*(u8**)(p+0x220)=opponent;F(p,0x34)=0;F(p,0x38)=-12;F(p,0x3C)=77;F(p,0x430)=41;
  *(s16*)(bank+0x7C)=counts[c];*(s16*)(bank+0x7E)=counts[3-c];memcpy(wantedBank,bank,sizeof bank);++*(s16*)(wantedBank+0x7C+2*team);
  // Resident rows are (1,1) and (3,3). Perturbed columns also test data dependence.
  D_004C0F20[0][0]=perturb?2:1;D_004C0F20[1][0]=perturb?5:3;
  D_004C0F21[0][0]=perturb?7:1;D_004C0F21[1][0]=perturb?11:3;
  memcpy(beforeSetup,p,sizeof p);*(s16*)(beforeSetup+0x140)=oldFace;F(beforeSetup,0x38)=41;beforeSetup[6]=(u8)(beforeSetup[6]+1);beforeSetup[0x210]=beforeSetup[0x20D]=0;
  memcpy(final,beforeSetup,sizeof final);final[2]=team;final[0x1B7]=mode;final[0x1E6]=facing;F(final,0x430)=95;
  float speed=mode?20.0f:13.333333015441895f;F(final,0x5C)=facing?speed:-speed;F(final,0x60)=mode?34.285713195800781f:17.142856597900391f;
  F(final,0x68)=facing?-0.7291666269302368f:0.7291666269302368f;F(final,0x6C)=-1.0714285373687744f;
  final[0x1B5]=mode+51;final[0x1B2]=0;*(u16*)(final+0x1C0)=0;*(u32*)(final+0x1D8)=0;final[0x2B8]=D_004C0F20[mode][0];final[0x2B9]=D_004C0F21[mode][0];
  if(wrap)func_002CDB90(p,p+0x2B8);else func_002CDB60(p);
  if(wrong||step!=2||memcmp(p,final,sizeof p)||memcmp(bank,wantedBank,sizeof bank))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_native_launch_and_post_setup_inputs(self):self.assertEqual(self.run_case(),0)
    def test_old_sibling_drag_rejected(self):self.assertNotEqual(self.run_case('drag'),0)
    def test_wrong_byte_column_rejected(self):self.assertNotEqual(self.run_case('column'),0)
    def test_neighbor_work_byte_rejected(self):self.assertNotEqual(self.run_case('extent'),0)
    def test_stale_facing_field_rejected(self):self.assertNotEqual(self.run_case('facing'),0)
