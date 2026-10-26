"""Exercise both tail handlers through their dispatchers and real update bodies."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorTailUpdatesTests(unittest.TestCase):
    def run_case(self, mutation=None):
        motion = (ROOT / 'src/actor_motion_tail_002e07b0.c').read_text()
        launch = (ROOT / 'src/actor_launch_tail_00214d60.c').read_text()
        if mutation == 'zero':
            motion = motion.replace('*(float*)(p+0x68)=0;', '*(float*)(p+0x68)=1;')
        if mutation == 'facing':
            launch = launch.replace('if(!p[0x1E6])', 'if(p[0x1E6])')
        if mutation == 'speed':
            launch = launch.replace('16.66666603088379f', '15.0f')
        helper1 = states.function('src/grok_w5_002e.c','func_002E07E0')
        helper2 = states.function('src/w187_u.c','func_00214DD0').replace('func_00175700(p);', 'func_00175700((u8*)p);')
        dispatch1 = states.function('src/composite_dispatch_heads.c','func_002E0790')
        dispatch2 = states.function('src/composite_dispatch_heads.c','func_00214D40')
        code = r'''
#include <string.h>
typedef int s32;typedef unsigned int u32;
''' + motion + launch + r'''
extern int func_00175700(u8*),func_001757E0(u8*,int,int);
extern void func_001D2A10(u8*,u8);
extern s16 D_00450D80[],D_00450D82[];
''' + helper1 + helper2 + r'''
void (*const jtbl_0045ADE0[])(u8*)={func_002E07B0};
void (*const jtbl_00450D70[])(u8*)={func_00214D60};
''' + dispatch1 + dispatch2 + r'''
s16 D_00450D80[4]={0,3,0,0},D_00450D82[4]={0,-4,0,0};
static u8 *actor;static int which,stage,wrong,status,event,face;
int func_00175700(u8*p) {
 if(p!=actor || stage++!=0 || *(s16*)(p+0x1C))wrong++;
 if(!which) {
  if(*(float*)(p+0x5C)!=0 || *(float*)(p+0x60)!=0 || *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0)wrong++;
  return status;
 }
 float vx=face?16.66666603088379f:-16.66666603088379f;
 float ax=face?-0.4166666567325592f:0.4166666567325592f;
 if(*(float*)(p+0x5C)!=vx || *(float*)(p+0x68)!=ax || *(float*)(p+0x60)!=12.857142448425293f ||
    *(float*)(p+0x6C)!=-1.0714285373687744f)wrong++;
 p[0x151]=event;return 0;
}
void func_001D2A10(u8*p,u8 n) {if(p!=actor || n || stage++!=1)wrong++;}
int func_001757E0(u8*p,int a,int b) {if(p!=actor || a!=15 || b!=1 || stage++!=2)wrong++;return 0;}
int main(void) {
 _Alignas(16) u8 p[0x500];int statuses[]={0,127,128,255,256},events[]={0,24,2};
 for(which=0;which<2;which++)for(face=0;face<2;face++)for(int r=0;r<5;r++)for(int e=0;e<3;e++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);actor=p;stage=wrong=0;status=statuses[r];event=events[e];
  p[6]=wrap?254:0;p[0x1E6]=face;*(s16*)(p+0x1C)=9;
  *(float*)(p+0x34)=100;*(float*)(p+0x38)=200;*(float*)(p+0x430)=50;
  *(float*)(p+0x5C)=9;*(float*)(p+0x60)=9;*(float*)(p+0x68)=9;*(float*)(p+0x6C)=9;
  if(which) {if(wrap)func_00214D60(p);else func_00214D40(p);} else {if(wrap)func_002E07B0(p);else func_002E0790(p);}
  int ended=!which && (s8)status<0;int jumped=which && event==24;
  if(wrong || stage!=(ended?3:1) || p[6]!=(u8)((wrap?254:0)+1+ended+jumped))return 1;
  if(which) {
   float expectedX=100,expectedY=event==24?50:200;
   if(event==2) {float d=1.6666666269302368f*3.0f;if(!face)d=-d;expectedX+=d;expectedY-=2.142857074737549f*(-4.0f);}
   if(*(float*)(p+0x34)!=expectedX || *(float*)(p+0x38)!=expectedY || *(s16*)(p+0x1C)!=(event==2?2:0))return 2;
  }
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_real_downstream_handlers(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_reset_is_rejected(self):
        self.assertNotEqual(self.run_case('zero'), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_speed_is_rejected(self):
        self.assertNotEqual(self.run_case('speed'), 0)
