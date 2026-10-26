"""Check real setup helpers, current team counters and the exact work-byte reset."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class PlayerWorkCounterTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/player_work_counter_start_002c7c20.c').read_text().replace('__attribute__((section(".sdata")))','')
        if mutation=='work':body=body.replace('work[2]=0','work[1]=0')
        if mutation=='team':body=body.replace('count[p[2]]','count[p[2]^1]')
        root=states.function('src/argument_dispatch_heads.c','func_002C7BF0')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef unsigned int u32;typedef int s32;typedef short s16;typedef float f32;
extern void func_0018C510(u8*,int),func_0015D8F0(float*,s16);
void func_002C7C20(u8*,void*);
void (*const jtbl_00459E60[4])(u8*,void*)={func_002C7C20,0,0,0};
'''+root+body+states.function('src/wave2.c','func_0018C4B0')+states.function('src/h11d.c','func_00185490')+states.function('src/wave13.c','func_00183D10')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static Counters counters,wanted;Counters *D_004C2794=&counters;
static u8 *actor,atPosition[0x600],final[0x600];static int wrong,step,team,kind,variant,expectedFacing;
void func_0018C510(u8*p,int n){if(p!=actor||step++!=0||n!=10||p[7]!=atPosition[7])wrong++;p[2]=team;p[0x269]=kind;p[0x1B7]=variant;}
void func_0015D8F0(float*v,s16 facing){if(step++!=1||facing!=expectedFacing||v[0]!=F(final,0x34)||v[1]!=F(final,0x430)||v[2]!=F(final,0x3C)||memcmp(actor,atPosition,sizeof atPosition)||memcmp(&counters,&wanted,sizeof counters))wrong++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||step++!=2||a!=21||b!=1||memcmp(p,final,sizeof final)||memcmp(&counters,&wanted,sizeof counters))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600],opponent[0x600];int faces[]={0,1,255},kinds[]={0,3,255},variants[]={0,1,255},counts[]={-32768,-1,0,32767};float xs[]={-100,0,100};
 for(int t=0;t<2;t++)for(int k=0;k<3;k++)for(int v=0;v<3;v++)for(int f=0;f<3;f++)for(int x=0;x<3;x++)for(int c=0;c<4;c++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(opponent,0,sizeof opponent);memset(&counters,0x3C,sizeof counters);actor=p;wrong=step=0;team=t;kind=kinds[k];variant=variants[v];
  p[7]=wrap?255:0;p[0x214]=0;p[0x1E6]=faces[f];*(u8**)(p+0x220)=opponent;F(p,0x34)=xs[x];F(p,0x38)=-12;F(p,0x3C)=99;F(p,0x430)=60.5f;
  counters.count[0]=counts[c];counters.count[1]=counts[3-c];wanted=counters;wanted.count[t]=(short)(wanted.count[t]+1);
  memcpy(final,p,sizeof p);final[7]=(u8)(final[7]+1);final[2]=team;final[0x269]=kind;final[0x1B7]=variant;
  int face=faces[f];if((!face&&xs[x]<-23.333332f)||(face&&xs[x]>23.333332f))face^=1;
  final[0x1E6]=face;*(short*)(final+0x140)=face;expectedFacing=face;
  F(final,0x38)=60.5f;final[0x20D]=0;F(final,0x5C)=F(final,0x60)=F(final,0x68)=F(final,0x6C)=0;
  final[0x1B5]=kind==3?66:variant?52:48;*(unsigned short*)(final+0x1C0)=0;final[0x1B2]=0;*(int*)(final+0x1D8)=0;
  memcpy(atPosition,final,sizeof final);final[0x2BA]=0;
  if(wrap)func_002C7C20(p,p+0x2B8);else func_002C7BF0(p);
  if(wrong||step!=3||memcmp(p,final,sizeof p)||memcmp(&counters,&wanted,sizeof counters))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_nested_helpers_and_work_extent(self):self.assertEqual(self.run_case(),0)
    def test_neighbor_work_byte_rejected(self):self.assertNotEqual(self.run_case('work'),0)
    def test_wrong_team_counter_rejected(self):self.assertNotEqual(self.run_case('team'),0)
