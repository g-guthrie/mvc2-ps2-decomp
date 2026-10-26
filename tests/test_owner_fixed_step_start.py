"""Check all fixed-point rows and the state-gated three-phase owner interface."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerFixedStepStartTests(unittest.TestCase):
    def run_fixed(self,missing_reset=False,wrong_column=False,wrong_owner=False):
        source=(ROOT/'src/owner_fixed_step_start_00195f60.c').read_text()
        source='\n'.join(x for x in source.splitlines() if not x.startswith('extern s32 D_'))+'\n'
        gate=(ROOT/'src/owner_state_phase_00196460.c').read_text()
        if missing_reset:
            changed=gate.replace('work[12]=0;','')
            self.assertNotEqual(changed,gate);gate=changed
        if wrong_column:
            changed=source.replace('extraAx=(float)D_00449F0C','extraAx=(float)D_00449F08')
            self.assertNotEqual(changed,source);source=changed
        if wrong_owner:
            changed=gate.replace('jtbl_0044A2B0[p[5]](p,q)','jtbl_0044A2B0[p[5]](p,p)')
            self.assertNotEqual(changed,gate);gate=changed
        code=r'''
#include <string.h>
typedef int s32;
static s32 rows[8][6]={
 {61166,52428,44418,1456,-71070,-2330},
 {58015,-15291,44418,1456,-71070,-2330},
 {110318,26214,44418,1456,-71070,-2330},
 {91750,8738,44418,1456,-71070,-2330},
 {-42598,69905,44418,1456,-71070,-2330},
 {-93934,34952,-71070,-2330,44418,1456},
 {-67720,-7645,-71070,-2330,44418,1456},
 {-70821,52428,-71070,-2330,44418,1456}};
#define D_00449F00 ((s32(*)[6])&rows[0][0])
#define D_00449F04 ((s32(*)[6])&rows[0][1])
#define D_00449F08 ((s32(*)[6])&rows[0][2])
#define D_00449F0C ((s32(*)[6])&rows[0][3])
#define D_00449F10 ((s32(*)[6])&rows[0][4])
#define D_00449F14 ((s32(*)[6])&rows[0][5])
'''+source+'\n'+gate+states.function('src/simple_leaves.c','func_00197600')+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
static int randomCalls,setups,routed,wrong,seed,phase;
static u8 *actor,*owner,*wanted,*ownerWanted;
int func_00417A40(void){randomCalls++;if(H(actor,0x1C)!=60)wrong++;return seed;}
int func_00175580(u8 *p,int a,int b,int c){setups++;if(p!=actor||a!=27||b!=8||c!=(seed&3)||randomCalls!=1||memcmp(p,wanted,0x600)||memcmp(owner,ownerWanted,0x600))wrong++;return 0;}
static void boundary(u8 *p,u8 *q,int selected){routed++;if(p!=actor||q!=owner||selected!=phase||memcmp(p,wanted,0x600)||memcmp(q,ownerWanted,0x600))wrong++;}
static void second(u8*p,u8*q){boundary(p,q,1);}
static void third(u8*p,u8*q){boundary(p,q,2);}
void (*const jtbl_0044A2B0[3])(u8*,u8*)={func_00195F60,second,third};
static float scaled(int value,float gain,int mirror){float fixed=value/65536.0f;float v=fixed*gain;return mirror?-v:v;}
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600],wantQ[0x600];
 int kinds[4]={22,0,21,255},faces[4]={0,1,-32768,256};int mode,kind,face,i;
 for(mode=0;mode<8;mode++)for(kind=0;kind<4;kind++)for(face=0;face<4;face++)for(phase=0;phase<3;phase++)for(seed=0;seed<8;seed++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[5]=phase;p[0x21]=mode;q[0x1E4]=kinds[kind];H(q,0x140)=faces[face];F(q,0x34)=23.5f;F(q,0x38)=-14.25f;
  memcpy(want,p,sizeof(p));memcpy(wantQ,q,sizeof(q));
  if(kinds[kind]!=22){want[0x88]=0;wantQ[0x2C4]=0;}
  if(phase==0) {
   want[5]=1;H(want,0x140)=faces[face];F(want,0x34)=23.5f;F(want,0x38)=105.75f;
   F(want,0x5C)=scaled(rows[mode][0],5.0f/3,faces[face]==0);
   F(want,0x60)=scaled(rows[mode][1],15.0f/7,0);
   F(want,0x68)=scaled(rows[mode][2],5.0f/3,faces[face]==0);
   F(want,0x98)=scaled(rows[mode][3],5.0f/3,faces[face]==0);
   F(want,0x6C)=scaled(rows[mode][4],15.0f/7,0);
   F(want,0x9C)=scaled(rows[mode][5],15.0f/7,0);H(want,0x1C)=60;
  }
  actor=p;owner=q;wanted=want;ownerWanted=wantQ;randomCalls=setups=routed=wrong=0;
  func_00196460(p,q);
  if(memcmp(p,want,sizeof(p))||memcmp(q,wantQ,sizeof(q)))return 1;
  if(randomCalls!=(phase==0)||setups!=(phase==0)||routed!=(phase!=0)||wrong)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_eight_rows_all_phases_owner_state_reset_facing_and_rng_mask(self):
        self.assertEqual(self.run_fixed(),0)

    def test_missing_owner_work_reset_is_detected(self):
        self.assertNotEqual(self.run_fixed(missing_reset=True),0)

    def test_wrong_extra_acceleration_column_is_detected(self):
        self.assertNotEqual(self.run_fixed(wrong_column=True),0)

    def test_wrong_phase_owner_is_detected(self):
        self.assertNotEqual(self.run_fixed(wrong_owner=True),0)
