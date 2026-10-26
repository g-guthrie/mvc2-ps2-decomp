"""Keep the native mixed selectors: vertical offset uses mode, others use style."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerMixedMotionStartTests(unittest.TestCase):
    def run_mixed(self,wrong_y=False,skip_second=False):
        source=(ROOT/'src/owner_mixed_motion_start_001964a0.c').read_text()
        source='\n'.join(x for x in source.splitlines() if not x.startswith('extern s16 D_') and not x.startswith('extern s32 D_') and not x.startswith('extern s8 D_'))+'\n'
        if wrong_y:
            changed=source.replace('D_00449FF2[p[0x20]]','D_00449FF2[p[0x21]]')
            self.assertNotEqual(changed,source);source=changed
        if skip_second:
            changed=source.replace('if(p[0x21]<2)','if(p[0x21]<1)')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
static struct Row {short x,y;int vx,vy;signed char depth;unsigned char pad[3];} rows[2]={{-9,82,-8192,6144,-2,{0}},{7,81,6144,8192,2,{0}}};
#define D_00449FF0 ((short(*)[8])&rows[0].x)
#define D_00449FF2 ((short(*)[8])&rows[0].y)
#define D_00449FF4 ((int(*)[4])&rows[0].vx)
#define D_00449FF8 ((int(*)[4])&rows[0].vy)
#define D_00449FFC ((signed char(*)[16])&rows[0].depth)
'''+source+'\n'+(ROOT/'src/grok_jp_1966c0.c').read_text().replace('extern DispatchFn2 const jtbl_004BF580[2] __attribute__((section(".sdata")));','')+states.function('src/simple_leaves.c','func_00197600')+r'''
static int calls,randomCalls,wrong,seed;
static u8 *actor,*owner,*wanted,*ownerWanted;
int func_00417A40(void){randomCalls++;if(memcmp(actor,wanted,0x600)||memcmp(owner,ownerWanted,0x600))wrong++;return seed;}
int func_00175580(u8*p,int a,int b,int c){calls++;if(p!=actor||a!=27||b!=8||c!=(seed&3)||randomCalls!=1||memcmp(p,wanted,0x600))wrong++;return 0;}
static void other(u8*p,u8*q){(void)p;(void)q;}
DispatchFn2 const jtbl_004BF580[2]={func_001964A0,other};
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600],wantQ[0x600];
 const int faces[4]={0,1,-32768,256},kinds[2]={22,21};int style,mode,face,kind,direct,i;
 if(sizeof(struct Row)!=16)return 9;
 for(style=0;style<256;style++)for(mode=0;mode<2;mode++)for(face=0;face<4;face++)for(kind=0;kind<2;kind++)for(direct=0;direct<2;direct++)for(seed=0;seed<8;seed++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[5]=direct?255:0;p[0x20]=mode;p[0x21]=style;q[0x1E4]=kinds[kind];H(q,0x140)=faces[face];F(q,0x34)=10;F(q,0x38)=20;
  memcpy(want,p,sizeof(p));memcpy(wantQ,q,sizeof(q));want[5]=(u8)(p[5]+1);
  if(!direct&&kinds[kind]!=22){want[0x88]=0;wantQ[0x2C4]=0;}
  if(style<2) {
   float dx=(5.0f/3)*rows[style].x,vx=(rows[style].vx/65536.0f)*(5.0f/3);
   if(!faces[face]){dx=-dx;vx=-vx;}
   H(want,0x140)=faces[face];F(want,0x34)=10+dx;F(want,0x38)=20+(15.0f/7)*rows[mode].y;
   F(want,0x5C)=vx;F(want,0x60)=(rows[style].vy/65536.0f)*(15.0f/7);F(want,0x68)=F(want,0x6C)=0;want[0x31]=(u8)rows[style].depth;
  }
  actor=p;owner=q;wanted=want;ownerWanted=wantQ;calls=randomCalls=wrong=0;
  if(direct)func_001964A0(p,q);else func_001966C0(p,q);
  if(memcmp(p,want,sizeof(p))||memcmp(q,wantQ,sizeof(q)))return 1;
  if(calls!=(style<2)||randomCalls!=(style<2)||wrong)return 2;
 }
 return 0;
}
'''
        code=code.replace('void func_001966C0(u8 *p, u8 *q)','extern DispatchFn2 const jtbl_004BF580[2];\nvoid func_001966C0(u8 *p, u8 *q)')
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_mixed_selector_rows_all_style_bytes_facing_guard_and_owner_gate(self):
        self.assertEqual(self.run_mixed(),0)

    def test_replacing_native_y_selector_with_style_is_detected(self):
        self.assertNotEqual(self.run_mixed(wrong_y=True),0)

    def test_skipping_second_valid_style_is_detected(self):
        self.assertNotEqual(self.run_mixed(skip_second=True),0)
