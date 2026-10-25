"""Exercise the bounded sixteen-byte descriptor rows through native dispatch."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerDescriptorOffsetStartTests(unittest.TestCase):
    def run_start(self,wrong_owner=False,wrong_y=False):
        source=(ROOT/'src/owner_descriptor_offset_start_00194e40.c').read_text()
        source='\n'.join(x for x in source.splitlines() if not x.startswith('extern s16 D_') and not x.startswith('extern s32 D_') and not x.startswith('extern E8 *D_'))+'\n'
        # Keep the native four-byte pointer slot when running on a 64-bit host.
        source=source.replace('*(E8**)(work+8)=','*(unsigned int*)(work+8)=(unsigned int)')
        dispatch=states.function('src/gp_dispatch.c','func_00195230')
        if wrong_owner:
            changed=dispatch.replace('(p,owner)','(p,p)')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        if wrong_y:
            changed=source.replace('D_0044A222[p[0x21]][0]','D_0044A220[p[0x21]][0]')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
static struct Row {short x,y,extent,pad;int address;short limit,mask;} rows[4]={
 {-22,77,0,0,4494688,1,127},{18,74,64,0,4495712,1,127},
 {0,64,0,0,4494432,1,31},{0,24,12,0,4494432,-1,31}};
#define D_0044A220 ((short(*)[8])&rows[0].x)
#define D_0044A222 ((short(*)[8])&rows[0].y)
#define D_0044A224 ((short(*)[8])&rows[0].extent)
#define D_0044A228 ((int(*)[4])&rows[0].address)
#define D_0044A22C ((short(*)[8])&rows[0].limit)
#define D_0044A22E ((short(*)[8])&rows[0].mask)
'''+source+r'''
static int noop,set,wrong;
static u8 *seen;
void func_00197600(void) {noop++;}
int func_001754A0(u8 *p,int a,int b) {set++;seen=p;if(noop!=1||a!=27||b!=8)wrong++;return 0;}
static void update(u8 *p,u8 *q) {(void)p;(void)q;}
void (*const jtbl_004BF550[2])(u8*,u8*)={func_00194E40,update};
'''+dispatch+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x300],q[0x300],want[0x300];
 int faces[3]={0,1,-1};int slot,face,initial;
 if(sizeof(struct Row)!=16)return 9;
 for(slot=0;slot<256;slot++)for(face=0;face<3;face++)for(initial=0;initial<2;initial++) {
  memset(p,0x5A,sizeof(p));memset(q,0xA5,sizeof(q));
  p[5]=initial?255:0;p[0x21]=slot;H(q,0x140)=faces[face];
  F(q,0x34)=45.5f;F(q,0x38)=-67.25f;
  memcpy(want,p,sizeof(p));want[5]=(u8)(p[5]+1);
  if(slot<4) {
   float x=(5.0f/3.0f)*rows[slot].x,y=(15.0f/7.0f)*rows[slot].y;
   if(!faces[face])x=-x;
   H(want,0x140)=faces[face];F(want,0xA0)=x;F(want,0xA4)=y;
   H(want,0x8C)=rows[slot].extent;*(int*)(want+0x90)=rows[slot].address;
   H(want,0x94)=rows[slot].limit;H(want,0x96)=rows[slot].mask;
   F(want,0x34)=45.5f+x;F(want,0x38)=-67.25f+y;
  }
  noop=set=wrong=0;seen=0;
  if(initial)func_00194E40(p,q);else func_00195230(p,q);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(noop!=(slot<4)||set!=(slot<4)||wrong)return 2;
  if(set&&seen!=p)return 3;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_rows_invalid_selectors_facing_phase_wrap_and_all_fields(self):
        self.assertEqual(self.run_start(),0)

    def test_wrong_owner_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)

    def test_wrong_descriptor_column_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_y=True),0)
