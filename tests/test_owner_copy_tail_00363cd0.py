"""Exercise the owner-copy tail call through both real dispatch heads."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerCopyTail00363cd0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_copy_tail_00363cd0.c').read_text().replace('p+0x18', 'p+0x500')
        root = states.function('src/composite_dispatch_heads.c','func_00363CB0')
        dispatch = states.function('src/argument_dispatch_heads.c','func_00363D80').replace('p + 24', 'p + 0x500')
        if mutation == 'owner':
            dispatch = dispatch.replace('(p, *(void **)(p + 0x500))', '(p, p)')
        if mutation == 'copy':
            body = body.replace('owner+0xEC', 'owner+0xE8')
        if mutation == 'active':
            body = body.replace('p[0x13C]=1', 'p[0x13C]=0')
        code = r'''
#include <string.h>
''' + body + r'''
static u8 *actor,*owner;static int calls,wrong,mode;
static void callback(u8*p,void*q,int selected) {
 calls++;if(p!=actor || q!=owner || selected!=mode || *(u16*)(p+0x26)!=0x1004 || p[0x13C]!=1 ||
  p[1]!=owner[1] || p[2]!=owner[2] || p[0x1B7]!=owner[0x1B7] || p[0x1B8]!=owner[0x1B8] ||
  p[0x30]!=owner[0x30] || p[0x24]!=owner[0x24] || memcmp(p+0x50,owner+0x50,12))wrong++;
 for(int i=0;i<196;i++)if(p[0xEC+i]!=(i==0x50?1:owner[0xEC+i]))wrong++;
}
static void cb0(u8*p,void*q){callback(p,q,0);}
static void cb1(u8*p,void*q){callback(p,q,1);}
void (*const jtbl_00463700[])(u8*)={func_00363CD0};
void (*const jtbl_00463710[])(u8*,void*)={cb0,cb1};
''' + root + dispatch + r'''
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x500];
 for(mode=0;mode<2;mode++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(q,0,sizeof q);actor=p;owner=q;calls=wrong=0;
  for(int i=0;i<196;i++)q[0xEC+i]=(u8)(i*3+7);
  *(u8**)(p+0x500)=q;p[4]=wrap?255:0;p[0x20]=mode;
  q[1]=44;q[2]=1;q[0x1B7]=17;q[0x1B8]=18;q[0x30]=250;q[0x24]=252;
  *(float*)(q+0x50)=3;*(float*)(q+0x54)=6;*(float*)(q+0x58)=7;
  if(wrap)func_00363CD0(p);else func_00363CB0(p);
  if(wrong || calls!=1 || p[4]!=(wrap?0:1))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_copy_and_owner_dispatch(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_owner_is_rejected(self):
        self.assertNotEqual(self.run_case('owner'), 0)

    def test_wrong_copy_is_rejected(self):
        self.assertNotEqual(self.run_case('copy'), 0)

    def test_wrong_active_flag_is_rejected(self):
        self.assertNotEqual(self.run_case('active'), 0)
