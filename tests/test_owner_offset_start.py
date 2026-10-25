"""Check the native owner offsets and address-derived depth byte."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerOffsetStartTests(unittest.TestCase):
    def run_start(self,wrong_owner=False,dereference_row=False):
        source=(ROOT/'src/owner_offset_start_00195490.c').read_text()
        source=source.replace('extern s16 D_0044A270[8][3],D_0044A272[8][3];','')
        # Host pointers are wider; the low-byte operation itself is unchanged.
        source=source.replace('(s8)(unsigned)&D_0044A270','(s8)(uintptr_t)&D_0044A270')
        dispatch=states.function('src/composite_gp_dispatch_heads.c','func_00195990')
        if wrong_owner:
            changed=dispatch.replace('(p,owner)','(p,p)')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if dereference_row:
            changed=source.replace('(s8)(uintptr_t)&D_0044A270[p[0x21]][0]','D_0044A270[p[0x21]][2]')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
#include <stdint.h>
/* Match retail's low address byte without requiring its absolute address. */
_Alignas(256) static struct {unsigned char pad[112];short rows[8][3];} fixture;
#define D_0044A270 (fixture.rows)
#define D_0044A272 ((short(*)[3])((unsigned char*)fixture.rows+2))
'''+source+r'''
static int noop,rng,set,wrong;
static unsigned randomValue;
static u8 *seen;
void func_00197600(void) {noop++;}
unsigned func_00417A40(void) {if(noop!=1)wrong++;rng++;return randomValue;}
int func_00175580(u8 *p,int a,int b,int c) {
 if(noop!=1||rng!=1||a!=27||b!=8||c!=(int)(randomValue&3))wrong++;
 set++;seen=p;return 0;
}
static void update(u8 *p,u8 *q){(void)p;(void)q;}
void (*const jtbl_004BF560[2])(u8*,u8*)={func_00195490,update};
'''+dispatch+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 const short rows[8][3]={{1024,-2048,-2},{2560,-1024,-2},{4608,-1280,-2},{4864,256,-2},{0,0,2},{4096,-2560,2},{1024,-2304,2},{-2304,-3072,2}};
 const int facing[3]={0,1,-1};
 int slot,face,k,initial;
 memcpy(fixture.rows,rows,sizeof(rows));
 if(((uintptr_t)fixture.rows&255)!=0x70)return 9;
 for(slot=0;slot<8;slot++)for(face=0;face<3;face++)for(k=0;k<8;k++)for(initial=0;initial<2;initial++) {
  float x=(5.0f/3.0f)*(rows[slot][0]/256.0f);
  float y=(15.0f/7.0f)*(rows[slot][1]/256.0f);
  memset(p,0x5A,sizeof(p));memset(q,0xA5,sizeof(q));
  p[5]=initial?255:0;p[0x21]=slot;
  H(q,0x140)=facing[face];F(q,0x34)=100.5f;F(q,0x38)=-70.25f;
  memcpy(want,p,sizeof(p));want[5]=(u8)(p[5]+1);
  H(want,0x140)=facing[face];
  F(want,0x34)=facing[face]?100.5f+x:100.5f-x;
  F(want,0x38)=-70.25f+y;want[0x31]=(u8)(0x70+6*slot);
  noop=rng=set=wrong=0;seen=0;randomValue=k;
  if(initial)func_00195490(p,q);else func_00195990(p,q);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(noop!=1||rng!=1||set!=1||wrong||seen!=p)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_native_rows_facing_phase_wrap_and_address_byte(self):
        self.assertEqual(self.run_start(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)

    def test_replacing_address_byte_with_row_contents_is_detected(self):
        self.assertNotEqual(self.run_start(dereference_row=True),0)
