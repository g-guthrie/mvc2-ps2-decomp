"""Check complete setup/reset/tick chains and explicit workspace forwarding."""
import re
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class ActionCounterChainTests(unittest.TestCase):
    def run_case(self,mutation=None):
        # Native layout assertions and 32-bit address arithmetic are checked by the PS2 build.
        header=(ROOT/'src/actor_action_event.h').read_text()
        header=re.sub(r'typedef char ActorActionOffsetCheck\[[\s\S]*?\];','',header)
        header=header.replace('__attribute__((section(".sdata")))','').replace('u32 counterOffset;','uintptr_t counterOffset;').replace('(u32)D_004C2794','(uintptr_t)D_004C2794')
        bodies=[]
        for n,path in [(208,'src/player_action_chain_start_00246180.c'),(216,'src/player_work_chain_start_00246510.c')]:
            body=(ROOT/path).read_text().replace('#include "actor_action_event.h"',header)
            body=body.replace('reset_action','reset_action'+str(n)).replace('u32 counterOffset;','uintptr_t counterOffset;').replace('(u32)D_004C2794','(uintptr_t)D_004C2794')
            if mutation=='context':body=body.replace('(p,work);','(p,p);')
            if mutation=='work':body=body.replace('((u8*)work)[9]=0','((u8*)work)[8]=0')
            if mutation=='counter':body=body.replace('++*(s16*)counterOffset','*(s16*)counterOffset+=2')
            bodies.append(body)
        tick208=states.function('src/m13c.c','func_00246250').replace('func_00246250','real_tick208')
        tick216=states.function('src/grok_w5_0024.c','func_002465F0').replace('func_002465F0','real_tick216')
        if mutation=='frame':tick208=tick208.replace('(s8)func_00175700(p)','func_00175700(p)')
        code=r'''
#include <stdint.h>
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;typedef unsigned int u32;typedef int s32;typedef float f32;
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(s16*)((p)+(n)))
#define I(p,n) (*(s32*)((p)+(n)))
extern void func_0018C510(u8*,int),func_0015D8F0(float*,s16);
extern int func_00175700(u8*);
extern void func_001843A0(u8*),func_00248320(u8*),func_00360530(u8*,int,int),func_001E3210(u8*,int);
void func_00246180(u8*,void*),func_00246510(u8*,void*);
void (*const jtbl_004C0378[2])(u8*,void*)={func_00246180,0};
void (*const jtbl_00452D10[5])(u8*,void*)={func_00246510,0,0,0,0};
'''+states.function('src/composite_gp_dispatch_heads.c','func_002462E0')+states.function('src/composite_dispatch_heads.c','func_00246790')+'\n'.join(bodies)+states.function('src/wave2.c','func_0018C4B0')+states.function('src/h11d.c','func_00185490')+states.function('src/wave13.c','func_00183D10')+tick208+tick216+r'''
static _Alignas(16) u8 bank[0x100],wantedBank[0x100];u8 *D_004C2794=bank;
static u8 *actor,*workspace,ctor[0x600],final[0x600],wantedWork[64];
static int wrong,stage,kind,team,variant,facing,result,event,clips,releases,sounds,children;
void func_0018C510(u8*p,int n){if(p!=actor||n!=5||stage++!=0)wrong++;p[2]=team;p[0x1B7]=variant;p[0x1E6]=facing;F(p,0x430)=41;}
void func_00175C00(u8*p,int n){if(p!=actor||n||stage++!=1||S(p,0x140)!=facing||F(p,0x38)!=-12)wrong++;F(p,0x430)=60.5f;}
void func_0015D8F0(float*v,s16 face){if(stage++!=2||face!=facing||v[0]!=0||v[1]!=60.5f||v[2]!=99||F(actor,0x38)!=-12)wrong++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||stage++!=3||a!=21||b!=(kind?5:3)||memcmp(p,ctor,sizeof ctor)||memcmp(bank,wantedBank,sizeof bank))wrong++;for(int i=0;i<64;i++)if(workspace[i]!=0x5A)wrong++;return -1;}
void func_00246250(u8*p,void*w){if(kind||p!=actor||w!=workspace||stage!=4)wrong++;real_tick208(p,w);}
void func_002465F0(u8*p,void*w){if(!kind||p!=actor||w!=workspace||stage!=4)wrong++;real_tick216(p,w);}
int func_00175700(u8*p){if(p!=actor||stage++!=4||memcmp(p,ctor,sizeof ctor)||memcmp(workspace,wantedWork,sizeof wantedWork))wrong++;p[0x151]=(u8)event;return result;}
void func_001843A0(u8*p){releases++;if(p!=actor||kind||stage!=5||memcmp(p,final,sizeof final))wrong++;}
void func_00248320(u8*p){clips++;if(p!=actor||kind||stage!=5)wrong++;}
void func_00360530(u8*p,int mode,int slot){if(p!=actor||kind||mode||slot!=children++||stage!=5||memcmp(p,final,sizeof final))wrong++;}
void func_001E3210(u8*p,int n){sounds++;if(p!=actor||!kind||n!=32||stage!=5||memcmp(p,final,sizeof final))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],opponent[0x600],work[64];int variants[]={0,1,127,128,255},faces[]={0,1,255},results[]={-1,127,128,255,256},events[]={0,1,2,-1},counts[]={-32768,-1,0,32767},phases[]={0,254,255};
 for(int k=0;k<2;k++)for(int t=0;t<2;t++)for(int v=0;v<5;v++)for(int f=0;f<3;f++)for(int r=0;r<5;r++)for(int e=0;e<4;e++)for(int c=0;c<4;c++)for(int phase=0;phase<3;phase++){
  memset(p,0xA5,sizeof p);memset(opponent,0,sizeof opponent);memset(bank,0x3C,sizeof bank);memset(work,0x5A,sizeof work);actor=p;workspace=work;wrong=stage=clips=releases=sounds=children=0;
  kind=k;team=t;variant=variants[v];facing=faces[f];result=results[r];event=events[e];p[k?6:7]=phases[phase];p[0x214]=0;*(u8**)(p+0x220)=opponent;F(p,0x34)=0;F(p,0x38)=-12;F(p,0x3C)=99;
  S(bank,0x7C)=counts[c];S(bank,0x7E)=counts[3-c];memcpy(wantedBank,bank,sizeof bank);++S(wantedBank,0x7C+2*team);
  memcpy(ctor,p,sizeof p);ctor[k?6:7]=(u8)(ctor[k?6:7]+1);ctor[2]=team;ctor[0x1B7]=variant;ctor[0x1E6]=facing;S(ctor,0x140)=facing;F(ctor,0x430)=F(ctor,0x38)=60.5f;
  F(ctor,0x5C)=F(ctor,0x60)=F(ctor,0x68)=F(ctor,0x6C)=0;ctor[0x20D]=0;ctor[0x1B5]=k?(u8)((signed char)variant+54):63;ctor[0x1B2]=0;*(u16*)(ctor+0x1C0)=0;I(ctor,0x1D8)=0;
  memcpy(final,ctor,sizeof final);final[0x151]=(u8)event;memcpy(wantedWork,work,sizeof work);if(k)wantedWork[9]=0;
  int ended=!k&&(signed char)result<0;
  if(!k&&!ended&&event)final[0x151]=0;
  if(k&&!event){final[6]=(u8)(final[6]+1);S(final,0x1C)=36;S(final,0x1E)=0;}
  if(phase){if(k)func_00246510(p,work);else func_00246180(p,work);}else{if(k)func_00246790(p,work);else func_002462E0(p,work);}
  if(wrong||stage!=5||clips!=(!k&&!ended)||releases!=ended||sounds!=(k&&!event)||children!=(!k&&!ended&&event?10:0)||memcmp(p,final,sizeof p)||memcmp(bank,wantedBank,sizeof bank)||memcmp(work,wantedWork,sizeof work))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_complete_setup_reset_and_actual_ticks(self):self.assertEqual(self.run_case(),0)
    def test_wrong_context_forwarding_rejected(self):self.assertNotEqual(self.run_case('context'),0)
    def test_neighbor_work_byte_rejected(self):self.assertNotEqual(self.run_case('work'),0)
    def test_double_counter_increment_rejected(self):self.assertNotEqual(self.run_case('counter'),0)
    def test_unsigned_frame_result_rejected(self):self.assertNotEqual(self.run_case('frame'),0)
