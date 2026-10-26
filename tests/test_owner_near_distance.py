"""Check the native near/far threshold and owner flow through nested dispatch."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerNearDistanceTests(unittest.TestCase):
    def run_case(self,mutation=None):
        init=(ROOT/'src/owner_near_distance_start_001c2aa0.c').read_text()
        dispatch=states.function('src/composite_gp_dispatch_heads.c','func_001C2A80')
        main=states.function('src/composite_dispatch_heads.c','func_001C1DF0')
        if mutation=='owner':dispatch=dispatch.replace('(p,owner)','(p,p)')
        if mutation=='threshold':init=init.replace('93.33332824707031f','94.0f')
        if mutation=='unordered':init=init.replace('!(distance<93.33332824707031f)','distance>=93.33332824707031f')
        code=r'''
#include <string.h>
#include <math.h>
typedef unsigned char u8;typedef short s16;typedef int s32;typedef float f32;
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(s16*)((p)+(n)))
extern void func_001C2AA0(u8*,u8*);
extern int func_00175700(u8*);
extern void func_001C3A80(u8*,u8*);
void (*const jtbl_004BFA10[2])(u8*,u8*)={func_001C2AA0,0};
void func_001C2A80(u8*,u8*);
void (*const jtbl_0044CAA0[21])(u8*,u8*)={[7]=func_001C2A80};
'''+main+dispatch+init+states.function('src/wave2.c','func_001C3A20')+states.function('src/round3_0.c','func_001C2BD0')+r'''
static u8 *actor,*owner;static u8 atCall[0x600],after[0x600];
static int wrong,animation,advance,farCalls,expired,wantAnimation;
int func_001757E0(u8*p,int a,int b){animation++;if(p!=actor||a!=25||b!=4||memcmp(p,atCall,sizeof atCall))wrong++;return -1;}
int func_00175700(u8*p){advance++;if(p!=actor||animation!=wantAnimation||memcmp(p,atCall,sizeof atCall))wrong++;return -1;}
void func_001C3A80(u8*p,u8*q){expired++;if(p!=actor||q!=owner||memcmp(p,after,sizeof after))wrong++;}
void func_001C2C70(u8*p,u8*q){farCalls++;if(p!=actor||q!=owner||advance||animation||memcmp(p,after,sizeof after))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600];float deltas[]={-100,-93.33332824707031f,-93,0,93,93.33332824707031f,100,NAN};
 int faces[]={0,1,-32768,256};
 for(int d=0;d<8;d++)for(int f=0;f<4;f++)for(int duration=1;duration<=2;duration++)for(int same=0;same<2;same++){
  memset(p,0xA5,sizeof p);memset(q,0x32,sizeof q);actor=p;owner=q;
  wrong=animation=advance=farCalls=expired=0;p[4]=7;p[6]=2;p[7]=0;p[0xD6]=same?2:3;
  S(p,0x1E)=duration;S(q,0x140)=faces[f];F(q,0x34)=0;
  float target=faces[f]?-80.0f:80.0f;F(p,0x34)=target+deltas[d];
  float difference=F(p,0x34)-target;int facing=difference<0;float distance=facing?-difference:difference;
  int far=!(distance<93.33332824707031f);wantAnimation=far?0:!same;
  memcpy(atCall,p,sizeof p);atCall[7]=1;S(atCall,0x140)=facing;
  if(far){atCall[6]=4;atCall[7]=0;memcpy(after,atCall,sizeof after);}
  else{
   float velocity=faces[f]==facing?-5.833333015441895f:-5.0f;
   F(atCall,0x5C)=facing?-velocity:velocity;F(atCall,0x68)=0;
   memcpy(after,atCall,sizeof after);F(after,0x34)=F(p,0x34)+F(atCall,0x5C);S(after,0x1E)=duration-1;
  }
  func_001C1DF0(p,q);
  if(wrong||farCalls!=far||advance!=!far||animation!=wantAnimation||expired!=(!far&&duration==1)||memcmp(p,after,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_nested_owner_and_threshold(self):self.assertEqual(self.run_case(),0)
    def test_wrong_owner_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
    def test_wrong_threshold_rejected(self):self.assertNotEqual(self.run_case('threshold'),0)
    def test_unordered_comparison_rejected(self):self.assertNotEqual(self.run_case('unordered'),0)
