"""Exercise the contextual tail and its real downstream dispatcher."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerContextCopyTail0035dfc0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_context_copy_tail_0035dfc0.c').read_text()
        if mutation == 'owner':
            body = body.replace('func_0035E090(p,owner)', 'func_0035E090(p,p)')
        if mutation == 'copy':
            body = body.replace('p[1]=owner[1]', 'p[1]=owner[2]')
        if mutation == 'timer':
            body = body.replace('*(s16*)(p+0x1E)=48', '*(s16*)(p+0x1E)=47')
        helper = states.function('src/wave3b.c','func_0035E090')
        root = states.function('src/composite_dispatch_heads.c','func_0035DFA0')
        code = r'''
#include <string.h>
''' + body + r'''
static u8 *actor,*owner;static int calls,wrong,mode;
static void callback(u8*p,void*q,int selected) {
 calls++;if(p!=actor || q!=owner || selected!=mode || p[0x13C] || *(s16*)(p+0x1C)!=1 || *(s16*)(p+0x1E)!=48 ||
  p[1]!=owner[1] || p[2]!=owner[2] || p[0x1B7]!=owner[0x1B7] || p[0x1B8]!=owner[0x1B8] ||
  p[0x30]!=owner[0x30] || p[0x24]!=owner[0x24] || memcmp(p+0x50,owner+0x50,12) || memcmp(p+0x34,owner+0x34,12))wrong++;
 for(int i=0;i<196;i++)if(p[0xEC+i]!=(i==0x50?0:owner[0xEC+i]))wrong++;
}
static void cb0(u8*p,void*q){callback(p,q,0);}
static void cb1(u8*p,void*q){callback(p,q,1);}
static void cb2(u8*p,void*q){callback(p,q,2);}
void (*const D_004C1B90[3])(u8*,void*)={cb0,cb1,cb2};
void (*const jtbl_00463370[])(u8*,void*)={func_0035DFC0};
''' + helper + root + r'''
int main(void) {
 _Alignas(16) u8 p[0x400],q[0x400];
 for(mode=0;mode<3;mode++)for(int active=0;active<2;active++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(q,0,sizeof q);actor=p;owner=q;calls=wrong=0;
  for(int i=0;i<196;i++)q[0xEC+i]=(u8)(i*3+7);
  p[4]=wrap?254:0;p[5]=mode;q[1]=44;q[2]=1;q[0x169]=active?22:23;
  q[0x1B7]=17;q[0x1B8]=18;q[0x30]=250;q[0x24]=252;
  *(float*)(q+0x50)=3;*(float*)(q+0x54)=6;*(float*)(q+0x58)=7;
  *(float*)(q+0x34)=100;*(float*)(q+0x38)=200;*(float*)(q+0x3C)=300;
  if(wrap)func_0035DFC0(p,q);else func_0035DFA0(p,q);
  if(wrong || calls!=active || p[4]!=(u8)((wrap?254:0)+1+!active) || p[0x13C] || *(s16*)(p+0x1C)!=1 || *(s16*)(p+0x1E)!=48)return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_copy_and_real_dispatch(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_owner_is_rejected(self):
        self.assertNotEqual(self.run_case('owner'), 0)

    def test_wrong_owner_field_is_rejected(self):
        self.assertNotEqual(self.run_case('copy'), 0)

    def test_wrong_timer_is_rejected(self):
        self.assertNotEqual(self.run_case('timer'), 0)
