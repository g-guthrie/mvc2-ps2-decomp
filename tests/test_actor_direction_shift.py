"""Check the real five-phase table's actor-local work pointer and direction shift."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class ActorDirectionShiftTests(unittest.TestCase):
    def run_shift(self,wrong_work=False,wrong_toggle=False):
        source=(ROOT/'src/actor_direction_shift_0020a6f0.c').read_text()
        dispatch=states.function('src/argument_dispatch_heads.c','func_0020A6C0')
        if wrong_work:
            changed=dispatch.replace('p + 696','p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if wrong_toggle:
            changed=source.replace('p[0x1E6]^=1','p[0x1E6]^=0')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
'''+source+'\n'+(ROOT/'src/data/jtbl_00450720.c').read_text()+'\n'+dispatch+r'''
static int callbacks,animations,wrong;
static u8 *expected;
void func_0034E160(void *p,u8 mode){callbacks++;if(p!=expected||mode!=5||*(short*)((u8*)p+0x1C)!=123)wrong++;}
int func_001757E0(u8 *p,int a,int b){animations++;if(p!=expected||a!=10||b!=1||callbacks!=1||*(short*)(p+0x1C)!=48)wrong++;return 0;}
void func_0020A7A0(u8 *p,void *w){(void)p;(void)w;}
void func_0020A7F0(u8 *p,void *w){(void)p;(void)w;}
void func_0020A880(u8 *p,void *w){(void)p;(void)w;}
void func_0020A8D0(u8 *p,void *w){(void)p;(void)w;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],want[0x300];
 const float xs[3]={-1000.5f,0,33.25f};int direction,position,wrap;
 for(direction=0;direction<256;direction++)for(position=0;position<3;position++)for(wrap=0;wrap<2;wrap++) {
  memset(p,0x5A,sizeof(p));p[7]=wrap?255:0;p[0x1E6]=direction;
  F(p,0x34)=xs[position];F(p,0x38)=-23.75f;H(p,0x1C)=123;
  memcpy(want,p,sizeof(p));want[7]=(u8)(p[7]+1);
  F(want,0x2C8)=xs[position];F(want,0x2CC)=-23.75f;
  F(want,0x34)=xs[position]+(direction?640.0f:-640.0f);
  want[0x1E6]=direction^1;H(want,0x140)=direction^1;want[0x2BC]=1;H(want,0x1C)=48;
  callbacks=animations=wrong=0;expected=p;
  if(wrap)func_0020A6F0(p,p+0x2B8);else func_0020A6C0(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(callbacks!=1||animations!=1||wrong)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_every_direction_byte_work_coordinates_and_helper_order(self):
        self.assertEqual(self.run_shift(),0)

    def test_wrong_work_pointer_is_detected(self):
        self.assertNotEqual(self.run_shift(wrong_work=True),0)

    def test_missing_toggle_is_detected(self):
        self.assertNotEqual(self.run_shift(wrong_toggle=True),0)
