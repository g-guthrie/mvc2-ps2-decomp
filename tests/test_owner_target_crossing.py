"""Exercise the real owner gate, launch timer, crossing test and both roots."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerTargetCrossingTests(unittest.TestCase):
    def run_crossing(self,wrong_owner=False,wrong_crossing=False):
        source=(ROOT/'src/owner_target_crossing_001e1930.c').read_text()
        nested=states.function('src/composite_dispatch_heads.c','func_001E1910')
        if wrong_owner:
            changed=nested.replace('(p,owner)','(p,p)')
            self.assertNotEqual(changed,nested);nested=changed
        if wrong_crossing:
            changed=source.replace('offset * *(float*)(p+0x5C)<0','offset * *(float*)(p+0x5C)>0')
            self.assertNotEqual(changed,source);source=changed
        root=states.function('src/grok_r2_001c.c','func_001E16A0').replace('*(u8 **)(p + 24)','*(u8 **)(p + 0x580)')
        code=r'''
#include <string.h>
typedef int s32;
typedef unsigned int u32;
typedef float f32;
struct Object;
void func_003DAA40(struct Object*);
'''+source+'\n'+(ROOT/'src/data/jtbl_0044F028.c').read_text()+'\n'+(ROOT/'src/data/jtbl_0044F040.c').read_text()+'\n'
        code+=r'''
extern ControllerEffectCallback const jtbl_0044EFF0[4];
'''+nested+states.function('src/composite_dispatch_heads.c','func_001E16E0')+states.function('src/composite_dispatch_heads.c','func_001E1C40')+root
        code+=(ROOT/'src/random_state_step.c').read_text()+'\n'+states.function('src/y5_e.c','func_001E1B70')
        code+=states.function('src/three_byte_state.c','func_001E1FC0')+states.function('src/tail_leaves.c','func_001E1FE0')
        code+=r'''
u8 D_004C26AC,D_004C26B0;
static int frames,randomAnimations,endAnimations,releases,wrong;
static u8 *expected;
int func_00175670(u8 *p){frames++;if(p!=expected)wrong++;p[0x159]=77;return -1;}
void func_001757E0(u8 *p,int a,int b){randomAnimations++;if(p!=expected||a!=23||b!=43)wrong++;}
int func_001754A0(u8 *p,int a,int b){endAnimations++;if(p!=expected||a!=27||b!=16)wrong++;return 0;}
void func_003DAA40(struct Object *p){releases++;if((u8*)p!=expected)wrong++;}
void func_001E1700(u8 *p,u8 *q){(void)p;(void)q;}
void func_001E1A60(u8 *p,u8 *q){(void)p;(void)q;}
void func_001E1B00(u8 *p,u8 *q){(void)p;(void)q;}
void func_001E1C60(u8 *p,u8 *q){(void)p;(void)q;}
void func_001E1F30(u8 *p,u8 *q){(void)p;(void)q;}
ControllerEffectCallback const jtbl_0044EFF0[4]={func_001E1700,func_001E1910,func_001E1FC0,func_001E1FE0};
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600];
 const int delays[5]={-32768,-1,0,1,2},timers[5]={-32768,0,1,2,32767},faces[3]={0,1,-1};
 const float xs[4]={-14,14,-9,9},vs[4]={-4,-4,4,4},as[4]={0.5f,-0.5f,0.5f,-0.5f};
 int d,t,block,motion,face,wrap,seed;
 for(d=0;d<5;d++)for(t=0;t<5;t++)for(block=0;block<3;block++)for(motion=0;motion<4;motion++)for(face=0;face<3;face++)for(wrap=0;wrap<2;wrap++)for(seed=0;seed<4;seed++) {
  unsigned state=(seed*7919+17)&65535,step=(state*3)>>8;
  unsigned next=(((state&255)+step)&255)|((step&255)<<8);
  int delay=(short)(delays[d]-1),active=delay<=0,gate=active&&block,finish=0,timer=timers[t];
  memset(p,0x5A,sizeof(p));memset(q,0,sizeof(q));
  p[4]=1;p[5]=wrap?255:0;p[0x20]=0;*(u8**)(p+0x580)=q;
  H(p,0x1E)=delays[d];H(p,0x1C)=timer;H(p,0x13E)=wrap?-32768:90;H(p,0x140)=wrap;
  F(p,0x34)=xs[motion];F(p,0x5C)=vs[motion];F(p,0x68)=as[motion];F(p,0x64)=10;
  F(q,0x34)=0;H(q,0x140)=faces[face];q[5]=block==1;q[0x1E4]=block==2?28:29;
  memcpy(want,p,sizeof(p));H(want,0x1E)=delay;
  if(!active)want[0x13C]=0;
  else {
   want[0x13C]=1;
   if(gate) {
    int facing=wrap^1,r=(next&7)+4;
    want[5]=2;H(want,0x140)=facing;F(want,0x5C)=(5.0f/3.0f)*r;if(!facing)F(want,0x5C)=-F(want,0x5C);F(want,0x68)=0;
   } else {
    float x=xs[motion]+vs[motion],velocity=vs[motion]+as[motion];
    float delta=(faces[face]?-10.0f:10.0f)-x;
    want[0x159]=0;F(want,0x34)=x;F(want,0x5C)=velocity;
    if(timer>0&&delta*velocity<0){timer=0;finish=1;}
    else{timer=(short)(timer-1);finish=timer==0;}
    H(want,0x1C)=timer;
    if(finish){want[5]=(u8)(p[5]+1);H(want,0x13E)=(short)(H(p,0x13E)-6);F(want,0x5C)=F(want,0x68)=0;}
   }
  }
  expected=p;frames=randomAnimations=endAnimations=releases=wrong=0;D_004C26AC=state&255;D_004C26B0=state>>8;
  if(wrap)func_001E1930(p,q);else func_001E16A0(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(frames!=(active&&!gate)||randomAnimations!=gate||endAnimations!=finish||releases||wrong)return 2;
  if((D_004C26AC|(D_004C26B0<<8))!=(gate?next:state))return 3;
 }
 /* The alternate owner root shares the actual cleanup and release callbacks. */
 p[0x20]=1;p[4]=2;p[0]=1;p[0x13C]=1;expected=p;wrong=releases=0;
 func_001E16A0(p);
 if(p[4]!=3||p[0]||p[0x13C])return 4;
 func_001E16A0(p);if(releases!=1||wrong)return 5;
 return 0;
}
'''
        # Modernize only the legacy boundary declaration for the host compiler.
        code=code.replace("extern void func_001757E0();","extern void func_001757E0(u8*,int,int);")
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_delays_real_owner_gate_crossing_timer_and_shared_lifecycle(self):
        self.assertEqual(self.run_crossing(),0)

    def test_wrong_owner_forwarding_is_detected(self):
        self.assertNotEqual(self.run_crossing(wrong_owner=True),0)

    def test_wrong_crossing_sign_is_detected(self):
        self.assertNotEqual(self.run_crossing(wrong_crossing=True),0)
