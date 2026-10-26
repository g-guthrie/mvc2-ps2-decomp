"""Check five descriptor rows, distinct manager/owner inputs and allocation returns."""
import re
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class DescriptorChainStartTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/descriptor_chain_start_0034a1e0.c').read_text().replace('__attribute__((section(".sdata")))','').replace('(p+0x14)','(p+0x588)')
        # Replace only the pointer field; packed sprite fields at 0x14c remain native offsets.
        if mutation=='manager':body=body.replace('manager+0x140','owner+0x140')
        if mutation=='column':body=body.replace('D_00461F62[p[0x20]].value','D_00461F60[p[0x20]].value')
        root=states.function('src/argument_dispatch_heads.c','func_0034A1B0').replace('p + 24','p + 0x580')
        initial=states.function('src/grok_w7_0034.c','func_0034A0D0')
        initial=re.sub(r'p \+ (16|20|24)\b',lambda m:'p + '+{16:'0x500',20:'0x588',24:'0x580'}[int(m[1])],initial)
        factory=states.function('src/grok_w7_evt3.c','func_0034A140').replace('(s32)src','(intptr_t)src')
        if mutation=='return':factory=factory.replace('return p;','return 0;')
        code=r'''
#include <stdint.h>
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef int s32;typedef float f32;
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(s16*)((p)+(n)))
static unsigned pointer_offset(unsigned n){return n==16?0x500:n==20?0x588:n==24?0x580:n;}
#define P(p,n) (*(void**)((p)+pointer_offset(n)))
extern u8 *func_003DA750(intptr_t,int,int);
void func_0034A1B0(u8*),func_0034A1E0(u8*,void*),func_0034A590(u8*,u8*);
extern void func_001E7F60(u8*);
static void update_entry(u8*p,void*q){func_0034A590(p,(u8*)q);}
void (*const jtbl_00461F50[4])(u8*,void*)={func_0034A1E0,update_entry,0,0};
extern void (*D_00461F88[])(u8*,u8*);
'''+root+body+initial+factory+states.function('src/grok_ac_34a590.c','func_0034A590')+r'''
static Counters bank,wantedBank;Counters *D_004C2794=&bank;
Column D_00461F60[5]={{11,{0}},{13,{0}},{15,{0}},{17,{0}},{19,{0}}};
Column D_00461F62[5]={{8,{0}},{9,{0}},{10,{0}},{11,{0}},{12,{0}}};
Column D_00461F64[5]={{4096,{0}},{4608,{0}},{5120,{0}},{5632,{0}},{6144,{0}}};
Column D_00461F66[5]={{-512,{0}},{-480,{0}},{-448,{0}},{-416,{0}},{-384,{0}}};
static u8 *actor,expected[0x600],final[0x600],pool[6][0x600],*last,*wantedParent,*activeOwner;
static int wrong,stage,allocs,next,failAlloc,wantedMode,phases,footers;
int func_001757E0(u8*p,int a,int b){if(p!=actor||a!=22||b!=44||stage++!=0||memcmp(p,expected,sizeof expected)||memcmp(&bank,&wantedBank,sizeof bank))wrong++;return -1;}
void func_0015E630(u8*p){if(p!=actor||stage++!=1||memcmp(p,expected,sizeof expected))wrong++;p[0]=0x7F;}
static void phase_callback(u8*p,u8*q){phases++;if(p!=wantedParent||q!=activeOwner)wrong++;}
void (*D_00461F88[1])(u8*,u8*)={phase_callback};
void func_001E7F60(u8*p){footers++;if(p!=wantedParent)wrong++;}
u8 *func_003DA750(intptr_t key,int group,int mode){
 allocs++;last=0;if(group!=1||mode!=wantedMode||key!=(mode?(intptr_t)wantedParent:0))wrong++;
 if(failAlloc)return 0;if(next>=6){wrong++;return 0;}last=pool[next++];memset(last,0,0x600);return last;
}
static int constructor_cases(void){
 _Alignas(16) u8 p[0x600],owner[0x600],manager[0x600],savedOwner[0x600];int faces[]={0,1,-32768},counts[]={-32768,-1,0,32767};float carries[]={-7.5f,0,101};
 for(int row=0;row<5;row++)for(int f=0;f<3;f++)for(int team=0;team<2;team++)for(int c=0;c<4;c++)for(int carry=0;carry<3;carry++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(owner,0x12,sizeof owner);memset(manager,0,sizeof manager);memset(&bank,0x3C,sizeof bank);actor=p;wrong=stage=0;
  p[4]=wrap?255:0;p[0x20]=row;P(p,24)=owner;P(p,20)=manager;F(p,0x5C)=carries[carry];F(p,0x3C)=-99;S(manager,0x140)=faces[f];
  owner[2]=team;owner[0x24]=0xFE;S(owner,0x140)=faces[f]?0:1;F(owner,0x50)=2;F(owner,0x54)=3;F(owner,0x58)=4;F(owner,0x430)=67.5f;
  bank.count[0]=counts[c];bank.count[1]=counts[3-c];wantedBank=bank;wantedBank.count[team]=(s16)(wantedBank.count[team]+1);memcpy(savedOwner,owner,sizeof owner);
  memcpy(expected,p,sizeof p);expected[4]=(u8)(expected[4]+1);expected[5]=0;memcpy(expected+0xEC,owner+0xEC,196);expected[0x13C]=1;expected[2]=owner[2];expected[1]=owner[1];
  memcpy(expected+0x50,owner+0x50,12);expected[0x1B7]=owner[0x1B7];expected[0x1B8]=owner[0x1B8];expected[0x30]=owner[0x30];expected[0x24]=owner[0x24];expected[0x89]=3;expected[0x88]=0;
  *(u32*)(expected+0x14C)=0x60003030;expected[0x1B0]=expected[0x1B1]=66;expected[0x1B5]=row+72;expected[0x1B2]=0;*(u16*)(expected+0x1C0)=0;*(u32*)(expected+0x1D8)=0;
  F(expected,0x34)=(faces[f]?80.0f:-80.0f)+carries[carry];F(expected,0x38)=67.5f;F(expected,0x5C)=F(expected,0x68)=0;
  S(expected,0x1C)=11+row*2;S(expected,0x1E)=8+row;F(expected,0x60)=(2.142857074737549f*(4096+row*512))/256.0f;F(expected,0x6C)=(2.142857074737549f*(-512+row*32))/256.0f;
  expected[0x169]=22;expected[0x168]=44;memcpy(final,expected,sizeof final);final[0]=1;
  if(wrap)func_0034A1E0(p,owner);else func_0034A1B0(p);
  if(wrong||stage!=2||memcmp(p,final,sizeof p)||memcmp(owner,savedOwner,sizeof owner)||memcmp(&bank,&wantedBank,sizeof bank))return 1;
 }
 return 0;
}
static int factory_cases(void){
 _Alignas(16) u8 owner[0x600],saved[0x600];
 memset(owner,0,sizeof owner);memcpy(saved,owner,sizeof owner);allocs=next=wrong=0;wantedMode=0;wantedParent=0;failAlloc=1;func_0034A0D0(owner);
 if(wrong||allocs!=1||last||memcmp(owner,saved,sizeof owner))return 1;
 for(int failedRow=-1;failedRow<4;failedRow++){
  memset(owner,0,sizeof owner);owner[1]=7;owner[0x1E4]=29;owner[0x2CD]=127;F(owner,0x34)=123;activeOwner=owner;allocs=next=wrong=0;wantedMode=0;failAlloc=0;wantedParent=0;func_0034A0D0(owner);
  u8 *parent=last;if(!parent||parent[0x20]||P(parent,16)!=(void*)func_0034A1B0||P(parent,24)!=owner||P(parent,20)!=owner||F(parent,0x5C)!=123||S(parent,0x26)!=0x302)return 1;
  for(int row=0;row<5;row++){
   if(parent[0x20]!=row)return 1;parent[4]=1;parent[5]=0;S(parent,0x1E)=1;F(parent,0x34)=100+row;wantedParent=parent;wantedMode=2;failAlloc=row==failedRow;phases=footers=0;
   int before=allocs;u8 oldCount=owner[0x2CD];func_0034A590(parent,owner);
   if(wrong||phases!=1||footers!=1||parent[0x31]!=254||S(parent,0x1E)!=(row<4?0:1))return 1;
   if(row==4){if(allocs!=before||owner[0x2CD]!=oldCount)return 1;break;}
   if(allocs!=before+1)return 1;
   if(failAlloc){if(last||owner[0x2CD]!=oldCount) return 1;break;}
   if(!last||owner[0x2CD]!=(u8)(oldCount+1)||last[0x20]!=row+1||last[0x21]||last[1]!=parent[1]||P(last,16)!=(void*)func_0034A1B0||P(last,20)!=parent||P(last,24)!=owner||S(last,0x26)!=0x302||F(last,0x5C)!=100+row)return 1;
   parent=last;
  }
 }
 return 0;
}
int main(void){return constructor_cases()||factory_cases();}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_five_rows_and_actual_producer_bounds(self):self.assertEqual(self.run_case(),0)
    def test_wrong_facing_owner_rejected(self):self.assertNotEqual(self.run_case('manager'),0)
    def test_wrong_descriptor_column_rejected(self):self.assertNotEqual(self.run_case('column'),0)
    def test_missing_allocation_pointer_return_rejected(self):self.assertNotEqual(self.run_case('return'),0)
