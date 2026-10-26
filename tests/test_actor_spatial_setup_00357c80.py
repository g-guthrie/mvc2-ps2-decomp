"""Exercise the owner-relative setup and its full position helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorSpatialSetup00357c80Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_spatial_setup_00357c80.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p + 0x18', 'p + 0x500').replace('p+0x18', 'p+0x500')
        if mutation == 'facing':
            body = body.replace('if (*(s16 *)(p + 0x140) != 0)', 'if (*(s16 *)(p + 0x140) == 0)')
        if mutation == 'row':
            body = body.replace('D_004C1AA8[p[0x21]]', 'D_004C1AA8[3-p[0x21]]')
        if mutation == 'order':
            body = body.replace('func_003577C0(p,2);func_003577C0(p,3);', 'func_003577C0(p,3);func_003577C0(p,2);')
        code = r'''
#include <string.h>
''' + body + r'''
u8 D_004C1AA8[4]={17,22,27,17};
s16 D_00462D80[8]={-73,0,-43,0,-66,0,-91,0};
s16 D_00462D82[8]={64,0,104,0,44,0,88,0};
static u8 *actor;static int stage,wrong,row,face;
int func_001757E0(u8*p,int a,int b) {
 float x=1.666666627f*(float)D_00462D80[row*2];if(face)x=-x;
 float y=2.142857075f*(float)D_00462D82[row*2];
 if(p!=actor || stage++!=0 || a!=21 || b!=D_004C1AA8[row] ||
    *(float*)(p+0x34)!=100.0f+x || *(float*)(p+0x38)!=200.0f+y || p[0x13C]!=1 ||
    p[0x23]!=6 || p[0x24]!=11 || p[0x1B0] || p[0x1B1] || *(s16*)(p+0x1C)!=1 ||
    *(s16*)(p+0x1E)!=1 || p[6]!=1 || p[7] || *(int*)(p+0xD0))wrong++;
 return 0;
}
void func_003577C0(u8*p,u8 n) {if(p!=actor || (stage==1?n!=2:n!=3) || stage<1 || stage>2)wrong++;stage++;}
void func_00357700(u8*p) {if(p!=actor || stage++!=3)wrong++;}
void func_00357830(u8*p) {if(p!=actor || stage++!=4)wrong++;}
void func_001E3210(u8*p,int n) {if(p!=actor || n!=30 || stage++!=5)wrong++;}
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x500];
 for(row=0;row<4;row++)for(face=0;face<2;face++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);actor=p;stage=wrong=0;
  *(u8**)(p+0x500)=owner;p[4]=wrap?255:8;p[0x21]=row;owner[1]=44;owner[2]=1;owner[0xEC]=99;
  owner[0x1B7]=17;owner[0x1B8]=18;owner[0x30]=250;owner[0x24]=252;
  *(s16*)(owner+0x140)=face;*(float*)(owner+0x34)=100;*(float*)(owner+0x38)=200;
  *(float*)(owner+0x50)=3;*(float*)(owner+0x54)=6;*(float*)(owner+0x58)=7;
  func_00357C80(p);
  if(wrong || stage!=6 || p[4]!=(wrap?0:9) || p[1]!=44 || p[2]!=1 || p[0xEC]!=99 ||
     p[0x1B7]!=17 || p[0x1B8]!=18 || p[0x30]!=250 || *(float*)(p+0x50)!=3 ||
     *(float*)(p+0x54)!=6 || *(float*)(p+0x58)!=7)return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_position_and_callbacks(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_row_is_rejected(self):
        self.assertNotEqual(self.run_case('row'), 0)

    def test_wrong_callback_order_is_rejected(self):
        self.assertNotEqual(self.run_case('order'), 0)
