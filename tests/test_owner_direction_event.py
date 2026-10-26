"""Check frame byte signs, current owner selection and the helper's parent input."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class OwnerDirectionEventTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/actor_owner_direction_event_0023eb90.c').read_text().replace('p+0x1DC','p+0x580')
        helper=states.function('src/wave2.c','func_001E3A40').replace('p + 0x1DC','p + 0x580')
        root=states.function('src/preaction_dispatch_heads.c','func_0023ED90')
        if mutation=='actor':body=body.replace('func_001E3A40(owner)','func_001E3A40(p)')
        if mutation=='event':body=body.replace('if(*(s8*)(p+0x151))','if(*(s8*)(p+0x151)==1)')
        if mutation=='flip':body=body.replace('*(short*)(p+0x140)^=1;','')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef int s32;
void func_0023EB90(u8*);extern void func_001E3710(u8*,u8);
void (*const jtbl_00452850[3])(u8*)={func_0023EB90,0,0};
'''+root+body+helper+r'''
static u8 *actor,*current,*grandparent,expected[0x600],wantedOwner[0x600];static int wrong,frames,releases,sounds,result,event,tag;
int func_00175700(u8*p){frames++;if(p!=actor||p[0x1FE]!=1)wrong++;*(u8**)(p+0x580)=current;p[0x151]=(u8)event;return result;}
void func_001843A0(u8*p){releases++;if(p!=actor||frames!=1||sounds||memcmp(p,expected,sizeof expected))wrong++;}
void func_001E3710(u8*p,u8 n){sounds++;if(p!=grandparent||n!=tag||frames!=1||releases||memcmp(actor,expected,sizeof expected)||memcmp(current,wantedOwner,sizeof wantedOwner))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],old[0x600],owner[0x600],grand[0x600],untouched[0x600];
 int results[]={-1,127,128,255,256},events[]={0,1,2,-1},faces[]={0,1,-32768,32767},bytes[]={0,1,128,255},xs[]={0,127,128,255},ys[]={0,4,5,255};
 for(int a=0;a<5;a++)for(int b=0;b<4;b++)for(int f=0;f<4;f++)for(int d=0;d<4;d++)for(int x=0;x<4;x++)for(int y=0;y<4;y++){
  memset(p,0xA5,sizeof p);memset(old,0x12,sizeof old);memset(owner,0x34,sizeof owner);memset(grand,0x56,sizeof grand);
  actor=p;current=owner;grandparent=grand;wrong=frames=releases=sounds=0;result=results[a];event=events[b];tag=(xs[x]&128)||ys[y]>=5?49:48;
  *(u8**)(p+0x580)=old;*(u8**)(owner+0x580)=grand;grand[0x216]=xs[x];grand[0x21B]=ys[y];p[0x20B]=0xC0;p[0x1E6]=bytes[d];*(short*)(p+0x140)=faces[f];
  memcpy(expected,p,sizeof p);memcpy(wantedOwner,owner,sizeof owner);memcpy(untouched,old,sizeof old);expected[0x1FE]=1;*(u8**)(expected+0x580)=owner;expected[0x151]=(u8)event;
  int ended=(signed char)result<0,active=!ended&&event!=0;
  if(ended)*(short*)(expected+0x140)^=1;
  if(active){expected[0x151]=0;wantedOwner[0x20A]=11;wantedOwner[0x20D]=2;wantedOwner[0x1B5]=expected[0x1B5]=32;wantedOwner[0x1E6]=bytes[d];expected[0x1E6]^=1;}
  func_0023ED90(p);
  if(wrong||frames!=1||releases!=ended||sounds!=active||memcmp(p,expected,sizeof p)||memcmp(owner,wantedOwner,sizeof owner)||memcmp(old,untouched,sizeof old))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_owner_parent_and_signed_events(self):self.assertEqual(self.run_case(),0)
    def test_actor_instead_of_owner_rejected(self):self.assertNotEqual(self.run_case('actor'),0)
    def test_event_one_only_rejected(self):self.assertNotEqual(self.run_case('event'),0)
    def test_missing_terminal_flip_rejected(self):self.assertNotEqual(self.run_case('flip'),0)
