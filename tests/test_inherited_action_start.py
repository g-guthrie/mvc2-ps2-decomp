"""Check the inlined action reset and both actual owner-update branches."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class InheritedActionStartTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/inherited_action_start_003a50e0.c').read_text().replace('__attribute__((section(".sdata")))','')
        if mutation=='depth':body=body.replace('= -2;','= -1;')
        if mutation=='z':body=body.replace('    a[0x1B5] = 53;','    *(f32*)(a+0x3C)=*(f32*)(b+0x3C);\n    a[0x1B5] = 53;')
        if mutation=='owner':body=body.replace('func_003A5220(a, b)','func_003A5220(a, a)')
        root=states.function('src/composite_dispatch_heads.c','func_003A50C0')
        code=r'''
#include <string.h>
#include <stdlib.h>
typedef unsigned char u8;
void func_003A50E0(u8*,u8*),func_003A5220(u8*,u8*);
void (*const jtbl_00472D60[7])(u8*,u8*)={func_003A50E0,func_003A5220,0,0,0,0,0};
'''+root+body+r'''
typedef void (*hx6b_fp)(u8*,u8*);
extern s16 D_00472D40[],D_00472D42[];extern hx6b_fp D_00472D70[];
'''+states.function('src/hx6_b.c','func_003A5220')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,*owner,atFrame[0x600],final[0x600],wantedBank[0x100];static int wrong,frames,cleanup,phases,phase;
G3c *D_004C2794;
s16 D_00472D40[4]={-23,0,-37,0},D_00472D42[4]={89,0,98,0};
int func_001757E0(u8*p,int a,int b){frames++;if(p!=actor||a!=23||b!=5||memcmp(p,atFrame,sizeof atFrame)||memcmp(D_004C2794,wantedBank,sizeof wantedBank))wrong++;return -1;}
void func_003A58E0(u8*p,u8*q){cleanup++;if(p!=actor||q!=owner||frames!=1||phases||memcmp(p,final,sizeof final))wrong++;}
static void phase_call(u8*p,u8*q,int n){phases++;if(p!=actor||q!=owner||frames!=1||cleanup||n!=phase||memcmp(p,final,sizeof final))wrong++;}
static void phase0(u8*p,u8*q){phase_call(p,q,0);}static void phase1(u8*p,u8*q){phase_call(p,q,1);}static void phase2(u8*p,u8*q){phase_call(p,q,2);}
hx6b_fp D_00472D70[3]={phase0,phase1,phase2};
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600];int depths[]={-128,-1,0,1,2,7,9,127},counts[]={-32768,-1,0,32767};D_004C2794=malloc(0x100);if(!D_004C2794)return 2;
 for(int state=0;state<2;state++)for(int team=0;team<2;team++)for(int d=0;d<8;d++)for(int f=0;f<2;f++)for(int row=0;row<2;row++)for(int sub=0;sub<3;sub++)for(int c=0;c<4;c++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);memset(D_004C2794,0x3C,0x100);actor=p;owner=q;wrong=frames=cleanup=phases=0;phase=sub;
  p[4]=wrap?255:0;p[5]=sub;p[0x21]=row;*(u16*)(p+0x1C)=17;F(p,0x34)=-5;F(p,0x38)=-9;F(p,0x3C)=-99;
  q[2]=team;q[0x24]=(u8)depths[d];q[0x169]=state?9:0;*(s16*)(q+0x140)=f;F(q,0x34)=10;F(q,0x38)=20;F(q,0x3C)=30;F(q,0x50)=2;F(q,0x54)=3;F(q,0x58)=4;
  D_004C2794->f7c[0]=counts[c];D_004C2794->f7c[1]=counts[3-c];memcpy(wantedBank,D_004C2794,sizeof wantedBank);++*(s16*)(wantedBank+0x7C+team*2);
  memcpy(atFrame,p,sizeof p);atFrame[4]=(u8)(atFrame[4]+1);memcpy(atFrame+0xEC,q+0xEC,196);atFrame[0x13C]=1;atFrame[2]=q[2];atFrame[1]=q[1];
  memcpy(atFrame+0x50,q+0x50,12);atFrame[0x1B7]=q[0x1B7];atFrame[0x1B8]=q[0x1B8];atFrame[0x30]=q[0x30];atFrame[0x24]=q[0x24];atFrame[0x31]=254;
  atFrame[0x1B5]=53;atFrame[0x1B2]=0;*(u16*)(atFrame+0x1C0)=0;*(u32*)(atFrame+0x1D8)=0;atFrame[0x1B0]=atFrame[0x1B1]=66;
  memcpy(final,atFrame,sizeof final);*(u16*)(final+0x1C)=1;int depth=(signed char)(depths[d]-2);if(depth>7)depth=7;if(depth<0)depth=0;final[0x24]=depth;
  if(!state)final[4]=(u8)(final[4]+1);
  else{float dx=row?-37:-23,dy=row?98:89;F(final,0x34)=f?10-1.6666666f*dx:10+1.6666666f*dx;F(final,0x38)=20+2.142857f*dy;F(final,0x3C)=30;}
  if(wrap)func_003A50E0(p,q);else func_003A50C0(p,q);
  if(wrong||frames!=1||cleanup!=!state||phases!=state||memcmp(p,final,sizeof p)||memcmp(D_004C2794,wantedBank,sizeof wantedBank))return 1;
 }
 free(D_004C2794);return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_full_reset_and_owner_update(self):self.assertEqual(self.run_case(),0)
    def test_sibling_depth_rejected(self):self.assertNotEqual(self.run_case('depth'),0)
    def test_unconditional_z_copy_rejected(self):self.assertNotEqual(self.run_case('z'),0)
    def test_actor_as_owner_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
