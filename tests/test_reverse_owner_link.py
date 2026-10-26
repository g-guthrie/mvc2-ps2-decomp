"""Check signed frame/events, owner replacement and the real zero-input helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class ReverseOwnerLinkTests(unittest.TestCase):
    def run_case(self,mutation=None):
        source=(ROOT/'src/actor_reverse_owner_link_0024d1e0.c').read_text().replace('p+0x1DC','p+0x580')
        if mutation=='event':source=source.replace('*(s8*)(p+0x151)==1','*(s8*)(p+0x151)!=0')
        if mutation=='owner':source=source.replace('owner=*(u8**)(p+0x580)','owner=original')
        if mutation=='helper':source=source.replace('func_00126400();','')
        root=states.function('src/composite_dispatch_heads.c','func_0024CEF0')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef short s16;
static u8 *original;
void func_0024D1E0(u8*);
void (*const jtbl_00453110[12])(u8*)={[8]=func_0024D1E0,[11]=func_0024D1E0};
extern void func_0015D090(u8*),func_001E3C40(u8*);
u8 *D_004C25D0,*D_004C25D4,D_004F1F41[1],D_004F1F42[1];
'''+root+source+states.function('src/create_offset_effect_0015D010.c','func_0015D010')+states.function('src/m2c.c','func_00126400')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,*alternate;static int wrong,frameResult,event1,event2,frames,releases,effects,updates;static float expectedXYZ[3];
int func_00175700(u8*p){frames++;if(p!=actor||releases||effects||updates)wrong++;p[0x150]=(u8)event1;p[0x151]=(u8)event2;return frameResult;}
void func_001843A0(u8*p){releases++;if(p!=actor||frames!=1||effects||updates)wrong++;}
void func_0015D090(u8*p){float*v=(float*)p;effects++;if(frames!=1||releases||v[0]!=expectedXYZ[0]||v[1]!=expectedXYZ[1]||v[2]!=expectedXYZ[2])wrong++;}
void func_001E3C40(u8*p){updates++;if(p!=actor||effects!=1||frames!=1)wrong++;*(u8**)(p+0x580)=alternate;p[0x1E6]^=0x80;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600],r[0x600],expected[0x600],eq[0x600],er[0x600],state0[2],state4[2];
 int results[]={-1,127,128,255,256},events[]={0,1,2,-1},faces[]={0,1,-32768},directions[]={0,1,128,255};
 for(int ret=0;ret<5;ret++)for(int e=0;e<4;e++)for(int h=0;h<4;h++)for(int f=0;f<3;f++)for(int d=0;d<4;d++)for(int mode=0;mode<3;mode++){
  memset(p,0xA5,sizeof p);memset(q,0x23,sizeof q);memset(r,0x45,sizeof r);actor=p;original=q;alternate=r;wrong=frames=releases=effects=updates=0;
  frameResult=results[ret];event1=events[e];event2=events[h];p[0x20D]=e&1?8:11;*(u8**)(p+0x580)=q;p[0x1E6]=directions[d];*(short*)(p+0x140)=faces[f];
  F(p,0x34)=10;F(p,0x38)=20;F(p,0x3C)=30;
  D_004C25D0=state0;D_004C25D4=state4;state4[1]=mode==0?26:0;state0[1]=mode==1?26:0;D_004F1F41[0]=9;D_004F1F42[0]=8;
  memcpy(expected,p,sizeof p);memcpy(eq,q,sizeof q);memcpy(er,r,sizeof r);expected[0x150]=(u8)event1;expected[0x151]=(u8)event2;
  int ended=(signed char)frameResult<0;int moved=!ended&&event1==1,linked=!ended&&event2==1;
  if(moved){expected[0x150]=0;expected[0x1B4]=10;*(u8**)(expected+0x580)=r;expected[0x1E6]^=0x80;}
  if(linked){u8*target=moved?er:eq;expected[0x151]=0;*(u8**)(target+0x1C8)=p;target[0x1E6]=expected[0x1E6]^1;target[0x20D]=2;target[0x1B5]=32;target[0x20A]=1;}
  expectedXYZ[0]=faces[f]?10-(-126.66666412353516f):10+(-126.66666412353516f);expectedXYZ[1]=110;expectedXYZ[2]=30;
  func_0024CEF0(p);
  int output=mode==0?4:mode==1?3:0;
  if(wrong||frames!=1||releases!=ended||effects!=moved||updates!=moved||memcmp(p,expected,sizeof p)||memcmp(q,eq,sizeof q)||memcmp(r,er,sizeof r)||D_004F1F41[0]!=(linked?output:9)||D_004F1F42[0]!=(linked?output:8))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_signed_events_and_actual_helpers(self):self.assertEqual(self.run_case(),0)
    def test_any_nonzero_event_rejected(self):self.assertNotEqual(self.run_case('event'),0)
    def test_stale_owner_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
    def test_missing_global_helper_rejected(self):self.assertNotEqual(self.run_case('helper'),0)
