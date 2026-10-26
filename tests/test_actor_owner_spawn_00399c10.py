"""Check the inherited actor setup through its three native dispatchers."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class ActorOwnerSpawn00399c10Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/actor_owner_spawn_00399c10.c').read_text().replace(' __attribute__((section(".sdata")))','')
        changes={'height':('231.428558349609375f','230.428558349609375f'),
                 'signal':('D_004C29FC[1]=6','D_004C29FC[1]=5')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new,1)
        root=states.function('src/grok_kk_399790.c','func_00399790')
        middle=states.function('src/composite_dispatch_heads.c','func_00399BD0')
        inner=states.function('src/grok_w5_disp.c','residual_00399BF0')
        code=r"""
#include <string.h>
"""+body+r"""
u8 *D_004C29F8,*D_004C29FC;
static u8 *actor,*owner;static int calls,fail,face,air;
int func_001757E0(u8*p,int a,int b){
 float dx=air?113.3333282470703125f:120.0f,dy=air?231.428558349609375f:180.0f;
 float vx=3.3333332538604736328125f;
 calls++;
 if(p!=actor || a!=23 || b!=2 || p[4]!=1 || p[0x13C]!=1 || D_004C29F8!=owner+0x2B8 ||
 D_004C29FC!=actor+0xD0 || D_004C29F8[1]!=1 || D_004C29FC[1]!=6 ||
 *(float*)(p+0x34)!=100.0f+(face?dx:-dx) || *(float*)(p+0x38)!=200.0f+dy ||
 *(float*)(p+0x5C)!=(face?vx:-vx) || *(float*)(p+0x60)!=0 || *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0 ||
 p[0x1B0]!=66 || p[0x1B1]!=66 || *(s16*)(p+0x1C)!=20 || p[0x24]!=0 || p[1]!=owner[1] || p[2]!=owner[2])fail++;
 for(int i=0;i<196;i++)if(p[0xEC+i]!=(i==0x50?1:owner[0xEC+i]))fail++;
 return 0;
}
void residual_00399BF0(u8*);void func_00399BD0(u8*);
void (*const jtbl_00472640[])(u8*)={func_00399C10};
void (*const jtbl_00472630[])(u8*)={residual_00399BF0};
void (*const jtbl_004725F0[])(u8*)={0,func_00399BD0};
"""+inner+middle+root+r"""
int main(void){
 _Alignas(16) u8 p[0x500],q[0x500];
 for(face=0;face<2;face++)for(air=0;air<2;air++){
  memset(p,0,sizeof p);memset(q,0,sizeof q);actor=p;owner=q;calls=fail=0;
  for(int i=0;i<196;i++)q[0xEC+i]=(u8)(i*3+7);
  *(u8**)(p+0x18)=q;p[0x20]=1;p[0x21]=0;q[1]=4;q[2]=1;q[0x20D]=air?2:0;q[0x1E6]=face;
  *(float*)(q+0x34)=100;*(float*)(q+0x38)=200;*(float*)(q+0x50)=1;*(float*)(q+0x54)=2;*(float*)(q+0x58)=3;
  func_00399790(p);if(calls!=1||fail)return 1;
 }
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_inherited_spawn_all_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_bad_height_is_rejected(self):
        self.assertNotEqual(self.run_case('height'),0)

    def test_bad_signal_is_rejected(self):
        self.assertNotEqual(self.run_case('signal'),0)
