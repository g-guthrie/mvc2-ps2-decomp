"""Check turn placement using the real offset helper and counter callback order."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class TurnCounterInitializerTests(unittest.TestCase):
    def turn_case(self,wrong_flag=False):
        body=(ROOT/'src/actor_turn_offset_start_00202400.c').read_text()
        if wrong_flag:body=body.replace('&0x400','&0x200')
        root=states.function('src/argument_dispatch_heads.c','func_002023D0')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef short s16;
void func_00202400(u8*);
void (*const jtbl_00450210[6])(u8*)={func_00202400,0,0,0,0,0};
extern void func_0015D090(u8*),func_001E3C40(u8*);
'''+root+body+states.function('src/create_offset_effect_0015D010.c','func_0015D010')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,expected[0x600];static int wrong,step;static float xyz[3];
void func_001266A0(u8*p,int a,int b){if(p!=actor||step++!=0||a!=5||b!=5||memcmp(p,expected,sizeof expected))wrong++;F(p,0x34)=100;F(p,0x38)=200;F(p,0x3C)=300;F(expected,0x34)=100;F(expected,0x38)=200;F(expected,0x3C)=300;}
void func_0015D090(u8*p){float*v=(float*)p;if(step++!=1||v[0]!=xyz[0]||v[1]!=xyz[1]||v[2]!=xyz[2])wrong++;}
void func_001E3C40(u8*p){if(p!=actor||step++!=2)wrong++;}
void func_0018C6E0(u8*p){if(p!=actor||step++!=3)wrong++;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||step++!=4||a!=15||b||memcmp(p,expected,sizeof expected))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600];int flags[]={0,0x200,0x400,0xFFFF},faces[]={0,1,-32768,32767},bytes[]={0,1,128,255};
 for(int f=0;f<4;f++)for(int h=0;h<4;h++)for(int b=0;b<4;b++){
  memset(p,0xA5,sizeof p);actor=p;wrong=step=0;p[0x20B]=0xC0;*(unsigned short*)(p+0x20E)=flags[f];*(short*)(p+0x140)=faces[h];p[0x1E6]=bytes[b];
  memcpy(expected,p,sizeof p);if(flags[f]&0x400){expected[0x1E6]^=1;*(short*)(expected+0x140)^=1;}
  expected[0x1B4]=10;expected[6]=0;xyz[0]=*(short*)(expected+0x140)?100-(-53.33333206176758f):100+(-53.33333206176758f);xyz[1]=200+137.14285278320312f;xyz[2]=300;
  func_002023D0(p);
  if(wrong||step!=5||memcmp(p,expected,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def counter_case(self,wrong_team=False):
        body=(ROOT/'src/player_action_counter_start_00213cd0.c').read_text().replace('__attribute__((section(".sdata")))','')
        if wrong_team:body=body.replace('count[p[2]]','count[p[2]^1]')
        root=states.function('src/argument_dispatch_heads.c','func_00213CA0')
        code=r'''
#include <string.h>
typedef unsigned char u8;
void func_00213CD0(u8*,void*);
void (*const jtbl_00450CD0[5])(u8*,void*)={func_00213CD0,0,0,0,0};
'''+root+body+r'''
static Counters counters;Counters *D_004C2794=&counters;
static u8 *actor,expected[0x600];static int wrong,step,target;static short oldCount[2];
void func_00175C00(u8*p,int n){if(p!=actor||step++!=0||n||p[6]!=expected[6])wrong++;}
void func_00185490(u8*p){if(p!=actor||step++!=1)wrong++;}
void func_0018C4B0(u8*p,int n){if(p!=actor||step++!=2||n!=5)wrong++;}
void func_00183D10(u8*p){if(p!=actor||step++!=3)wrong++;p[2]=target;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||step++!=4||a!=22||b!=5||memcmp(p,expected,sizeof expected)||counters.count[target]!=(short)(oldCount[target]+1)||counters.count[target^1]!=oldCount[target^1])wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600];int counts[]={-32768,-1,0,32767};
 for(int initial=0;initial<2;initial++)for(int team=0;team<2;team++)for(int c=0;c<4;c++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(&counters,0x3C,sizeof counters);actor=p;wrong=step=0;target=team;
  p[2]=initial;p[6]=wrap?255:0;oldCount[0]=counters.count[0]=counts[c];oldCount[1]=counters.count[1]=counts[3-c];
  memcpy(expected,p,sizeof p);expected[6]=(u8)(expected[6]+1);expected[2]=team;expected[0x20D]=1;expected[0x1B5]=53;expected[0x1B2]=0;*(unsigned short*)(expected+0x1C0)=0;*(int*)(expected+0x1D8)=0;
  if(wrap)func_00213CD0(p,p+0x2B8);else func_00213CA0(p);
  if(wrong||step!=5||memcmp(p,expected,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_turn_flags_and_offset_helper(self):self.assertEqual(self.turn_case(),0)
    def test_wrong_turn_flag_rejected(self):self.assertNotEqual(self.turn_case(True),0)
    def test_current_team_counter_and_wrap(self):self.assertEqual(self.counter_case(),0)
    def test_wrong_team_rejected(self):self.assertNotEqual(self.counter_case(True),0)
