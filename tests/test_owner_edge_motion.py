"""Check the typed edge-motion pair and actor arguments in all update cases."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerEdgeMotionTests(unittest.TestCase):
    def run_edge(self,wrong_owner=False,missing_actor=False):
        dispatch=states.function('src/composite_gp_dispatch_heads.c','func_001D2F60')
        update=(ROOT/'src/w186_q.c').read_text()
        if wrong_owner:
            changed=dispatch.replace('(Q1D3*)owner_context','(Q1D3*)p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if missing_actor:
            changed=update.replace('func_00175700((u8*)p)','func_00175700((u8*)0)')
            self.assertNotEqual(changed,update);update=changed
        code=r'''
#include <string.h>
'''+(ROOT/'src/owner_edge_start_001d2f80.c').read_text()+'\n'+update+'\n'+(ROOT/'src/data/jtbl_004BFA80.c').read_text()+'\n'+dispatch+r'''
float D_004F1FC8=400,D_004F1FCC=-400;
static int scenario,spawns,animations,frames,wrong,flag;
static u8 *expected,*wanted;
void func_0015E630(u8 *p){spawns++;if(p!=expected||memcmp(p,wanted,0x600))wrong++;}
int func_001757E0(u8 *p,int a,int b){animations++;if(p!=expected||a!=23||b!=(scenario?29:28))wrong++;if(!scenario&&spawns!=1)wrong++;return 0;}
int func_00175700(u8 *p){frames++;if(p!=expected){wrong++;return -1;}p[0x151]=(u8)flag;return -1;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],want[0x600],wantQ[0x600];
 int dirs[3]={0,1,255};int direction,wrap,i,phase,ownerFrame,event,close;
 scenario=0;
 for(direction=0;direction<3;direction++)for(wrap=0;wrap<2;wrap++) {
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);}
  p[4]=wrap?255:0;q[0x1E6]=dirs[direction];F(q,0x430)=-75.5f;
  F(q,0x50)=1.25f;F(q,0x54)=2.5f;F(q,0x58)=-4.75f;
  memcpy(want,p,sizeof(p));memcpy(want+0xEC,q+0xEC,196);want[0x13C]=1;
  want[2]=q[2];want[1]=q[1];memcpy(want+0x50,q+0x50,12);
  want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];
  want[4]=(u8)(p[4]+1);want[0x24]=11;F(want,0x38)=-75.5f;
  F(want,0x34)=dirs[direction]?D_004F1FC8-(5.0f/3)*64:D_004F1FCC+(5.0f/3)*64;
  F(want,0x5C)=dirs[direction]?10.0f:-10.0f;
  expected=p;wanted=want;spawns=animations=frames=wrong=0;
  if(wrap)func_001D2F80((P1D3*)p,(Q1D3*)q);else func_001D2F60(p,q);
  if(memcmp(p,want,sizeof(p))||spawns!=1||animations!=1||frames||wrong)return 1;
 }
 scenario=1;
 for(phase=0;phase<3;phase++)for(ownerFrame=0;ownerFrame<2;ownerFrame++)for(event=0;event<2;event++)for(direction=0;direction<3;direction++)for(close=0;close<2;close++) {
  memset(p,0x5A,sizeof(p));memset(q,0,sizeof(q));p[4]=1;p[5]=phase;p[0x151]=9;
  q[0x151]=ownerFrame;q[0x1E6]=dirs[direction];q[0x21]=0x12;F(q,0x34)=0;
  F(p,0x34)=close?0:200;F(p,0x5C)=2;F(p,0x68)=0.25f;F(p,0x60)=3;F(p,0x6C)=-0.5f;
  memcpy(want,p,sizeof(p));memcpy(wantQ,q,sizeof(q));flag=event?-128:0;
  if(phase==0) {
   F(want,0x34)+=2;F(want,0x5C)+=0.25f;want[0x151]=(u8)flag;
   if(close){want[5]=1;F(want,0x34)=dirs[direction]?-(5.0f/3)*64:(5.0f/3)*64;F(want,0x5C)=F(want,0x60)=F(want,0x68)=F(want,0x6C)=0;}
  } else if(phase==1&&!ownerFrame) {
   want[0x151]=(u8)flag;if(flag){want[5]=2;want[0x151]=0;wantQ[0x21]|=128;}
  } else if(phase==2)want[0x151]=(u8)flag;
  expected=p;spawns=animations=frames=wrong=0;
  func_001D2F60(p,q);
  if(memcmp(p,want,sizeof(p))||memcmp(q,wantQ,sizeof(q)))return 2;
  if(frames!=(phase!=1||!ownerFrame)||animations!=(phase==0&&close)||spawns||wrong)return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_constructor_and_all_real_update_phases(self):
        self.assertEqual(self.run_edge(),0)

    def test_wrong_gp_owner_is_detected(self):
        self.assertNotEqual(self.run_edge(wrong_owner=True),0)

    def test_missing_actor_on_frame_calls_is_detected(self):
        self.assertNotEqual(self.run_edge(missing_actor=True),0)
