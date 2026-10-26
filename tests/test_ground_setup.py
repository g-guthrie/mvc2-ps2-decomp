"""Check the real nonvolatile action reset and ground setup sequence."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class GroundSetupTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/ground_setup_00250580.c').read_text()
        reset=states.function('src/q7_c.c','reset_action')
        setup=states.function('src/q7_c.c','func_00250940')
        if mutation=='tag':setup=setup.replace('(u8)(a + (u8)idx)','(u8)(a + (u8)idx + 1)')
        if mutation=='frame':body=body.replace('p[0x1B7]+7','p[0x1B7]+8')
        if mutation=='counter':reset=reset.replace('h7C[p[2]]++','h7C[p[2]]+=2')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;typedef int s32;typedef float f32;
typedef struct {u8 prefix[0x1B5];u8 action;} ActionActor;
typedef struct {u8 pad[0x7C];s16 h7C[];} S794;
extern S794 *D_004C2794;extern u8 D_004C04A0[];extern void func_0018C510(u8*,int),func_0015D8F0(float*,s16);
void func_00250580(u8*);static void entry(u8*p,void*w){if(w!=p+0x2B8)return;func_00250580(p);}
void (*const jtbl_00453350[4])(u8*,void*)={entry,0,0,0};
'''+states.function('src/argument_dispatch_heads.c','func_00250550')+reset+setup+body+states.function('src/wave2.c','func_0018C4B0')+states.function('src/h11d.c','func_00185490')+states.function('src/wave13.c','func_00183D10')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static _Alignas(16) u8 bank[0x100],wantedBank[0x100];S794 *D_004C2794=(S794*)bank;
u8 D_004C04A0[6]={56,57,76,80,81,82};
static u8 *actor,expected[0x600];static int wrong,stage,variant,facing;
void func_0018C510(u8*p,int n){if(p!=actor||n!=5||stage++!=0||memcmp(bank,wantedBank,sizeof bank)||p[0x1B5]!=expected[0x1B5])wrong++;p[0x1B7]=variant;}
void func_0015D8F0(float*v,s16 face){if(stage++!=1||face!=facing||v[0]!=0||v[1]!=60.5f||v[2]!=99||memcmp(actor,expected,sizeof expected))wrong++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||stage++!=2||a!=21||b!=(u8)(variant+7)||memcmp(p,expected,sizeof expected)||memcmp(bank,wantedBank,sizeof bank))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600],opponent[0x600],want[0x600];int subtypes[]={0,3,255},counts[]={-32768,-1,0,32767},variants[]={0,1,127,128,255};
 for(int k=0;k<3;k++)for(int mode=0;mode<3;mode++)for(int team=0;team<2;team++)for(int c=0;c<4;c++){
  memset(p,0xA5,sizeof p);memset(bank,0x3C,sizeof bank);p[2]=team;p[0x269]=subtypes[k];D_004C2794->h7C[0]=counts[c];D_004C2794->h7C[1]=counts[3-c];
  memcpy(want,p,sizeof p);memcpy(wantedBank,bank,sizeof bank);want[0x1B5]=D_004C04A0[mode+(subtypes[k]==3?3:0)];want[0x1B2]=0;*(u16*)(want+0x1C0)=0;*(u32*)(want+0x1D8)=0;++*(s16*)(wantedBank+0x7C+team*2);
  func_00250940(p,mode);if(memcmp(p,want,sizeof p)||memcmp(bank,wantedBank,sizeof bank))return 1;
 }
 for(int k=0;k<3;k++)for(int team=0;team<2;team++)for(int v=0;v<5;v++)for(int face=0;face<2;face++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(opponent,0,sizeof opponent);memset(bank,0x3C,sizeof bank);actor=p;wrong=stage=0;variant=variants[v];facing=face;
  p[7]=wrap?255:0;p[2]=team;p[0x269]=subtypes[k];p[0x214]=0;p[0x1E6]=face;*(u8**)(p+0x220)=opponent;F(p,0x34)=0;F(p,0x38)=-12;F(p,0x3C)=99;F(p,0x430)=60.5f;
  D_004C2794->h7C[0]=32767;D_004C2794->h7C[1]=-1;memcpy(wantedBank,bank,sizeof bank);++*(s16*)(wantedBank+0x7C+team*2);
  memcpy(expected,p,sizeof p);expected[7]=(u8)(expected[7]+1);expected[0x1B5]=D_004C04A0[subtypes[k]==3?3:0];expected[0x1B2]=0;*(u16*)(expected+0x1C0)=0;*(u32*)(expected+0x1D8)=0;
  expected[0x1B7]=variant;*(s16*)(expected+0x140)=face;F(expected,0x38)=60.5f;expected[0x20D]=0;F(expected,0x5C)=F(expected,0x60)=F(expected,0x68)=F(expected,0x6C)=0;
  if(wrap)func_00250580(p);else func_00250550(p);
  if(wrong||stage!=3||memcmp(p,expected,sizeof p)||memcmp(bank,wantedBank,sizeof bank))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_native_setup_and_six_table_entries(self):self.assertEqual(self.run_case(),0)
    def test_wrong_table_index_rejected(self):self.assertNotEqual(self.run_case('tag'),0)
    def test_wrong_frame_rejected(self):self.assertNotEqual(self.run_case('frame'),0)
    def test_double_counter_rejected(self):self.assertNotEqual(self.run_case('counter'),0)
