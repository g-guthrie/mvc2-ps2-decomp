"""Check offset setup, allocation and parent/actor animation ordering."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class ParentFrameStartTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/parent_frame_start_0025b560.c').read_text()
        if mutation=='parent':body=body.replace('*(u8**)(p+0x1DC)','p')
        if mutation=='flag':body=body.replace('&0x400','&0x200')
        if mutation=='order':body=body.replace('func_001757E0(*(u8**)(p+0x1DC),13,5);func_001757E0(p,15,0);','func_001757E0(p,15,0);func_001757E0(*(u8**)(p+0x1DC),13,5);')
        root=states.function('src/argument_dispatch_heads.c','func_0025B530')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef short s16;
typedef struct Event { u8 pad00[16]; void *callback; u8 pad14[4]; void *arg; u8 pad1c[4]; u8 mode; } Event;
extern Event *func_003DA750(int,int,int);extern void func_001AFD10(void),func_0015D090(u8*),func_001E3C40(u8*);
void func_0025B560(u8*);
void (*const jtbl_004538E0[3])(u8*)={func_0025B560,0,0};
'''+root+body+states.function('src/create_offset_effect_0015D010.c','func_0015D010')+states.function('src/event_callbacks84.c','func_001AFCB0')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,*replacement,expected[0x600];static Event event;static int wrong,step,failAlloc;static float xyz[3];
void func_0015D090(u8*p){float*v=(float*)p;if(step++!=0||v[0]!=xyz[0]||v[1]!=xyz[1]||v[2]!=xyz[2])wrong++;}
void func_001E3C40(u8*p){if(p!=actor||step++!=1||memcmp(p,expected,sizeof expected))wrong++;*(u8**)(p+0x1DC)=replacement;*(u8**)(expected+0x1DC)=replacement;}
void func_001266A0(u8*p,int a,int b){if(p!=actor||a!=5||b!=5||step++!=2||memcmp(p,expected,sizeof expected))wrong++;}
void func_0018C6E0(u8*p){if(p!=actor||step++!=3)wrong++;}
Event *func_003DA750(int a,int b,int c){if(a||b!=3||c||step++!=4)wrong++;return failAlloc?0:&event;}
void func_001AFD10(void){}
int func_001757E0(u8*p,int a,int b){if(step==5){if(p!=replacement||a!=13||b!=5)wrong++;if(!failAlloc&&(event.callback!=(void*)func_001AFD10||event.arg!=actor||event.mode))wrong++;}else if(step==6){if(p!=actor||a!=15||b)wrong++;}else wrong++;step++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600],r[0x600];int flags[]={0,0x200,0x400,0xFFFF},faces[]={0,1,-32768,32767},bytes[]={0,1,128,255};
 for(int f=0;f<4;f++)for(int h=0;h<4;h++)for(int d=0;d<4;d++)for(int failed=0;failed<2;failed++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);memset(r,0x34,sizeof r);memset(&event,0x5A,sizeof event);actor=p;replacement=r;wrong=step=0;failAlloc=failed;
  p[0x20B]=0xC0;*(u8**)(p+0x1DC)=q;*(unsigned short*)(p+0x20E)=flags[f];*(short*)(p+0x140)=faces[h];p[0x1E6]=bytes[d];F(p,0x34)=100;F(p,0x38)=200;F(p,0x3C)=300;
  memcpy(expected,p,sizeof p);if(flags[f]&0x400){expected[0x1E6]^=1;*(short*)(expected+0x140)^=1;}
  xyz[0]=*(short*)(expected+0x140)?100-(-83.33332824707031f):100+(-83.33332824707031f);xyz[1]=200+158.57142639160156f;xyz[2]=300;
  /* The offset callback observes state before the later 0x1b4 write. */
  func_0025B530(p);
  if(wrong||step!=7||memcmp(p,expected,sizeof p)||*(u8**)(p+0x1DC)!=r)return 1;
 }
 return 0;
}
'''
        # Adjust expected state at the later setup boundary only.
        code=code.replace('if(p!=actor||a!=5||b!=5||step++!=2||memcmp(p,expected,sizeof expected))wrong++;','expected[0x1B4]=10;if(p!=actor||a!=5||b!=5||step++!=2||memcmp(p,expected,sizeof expected))wrong++;')
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_real_offset_and_event_allocation(self):self.assertEqual(self.run_case(),0)
    def test_actor_as_parent_rejected(self):self.assertNotEqual(self.run_case('parent'),0)
    def test_wrong_turn_flag_rejected(self):self.assertNotEqual(self.run_case('flag'),0)
    def test_animation_order_rejected(self):self.assertNotEqual(self.run_case('order'),0)
