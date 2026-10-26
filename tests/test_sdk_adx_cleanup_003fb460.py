"""Check ADX reference-count cleanup and exact native memory ranges."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SdkAdxCleanup003fb460Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/sdk_adx_cleanup_003fb460.c').read_text()
        changes={'fill':('D_0047B588,255,0x1000','D_0047B588,0,0x1000'),
                 'reset':('D_0047C5B4=-1','D_0047C5B4=0')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new,1)
        code=r"""
#include <string.h>
"""+body+r"""
s32 D_00479DFC,D_0047C5B0,D_0047C5B4,D_0047C5AC,D_0047B580,D_0047C5A8;
u8 D_0047C588[0x20],D_0047B588[0x1000],D_0047B180[0x400],D_00479E00[0x1380];
static int seq,fail;
void func_003FCD80(void){if(seq++!=0||D_00479DFC!=0||D_0047C5B0!=7)fail++;}
void *func_0011D8F8(void *p,s32 value,u32 size){
 void *expected[]={D_0047C588,D_0047B588,D_0047B180,D_00479E00};
 u32 lengths[]={0x20,0x1000,0x400,0x1380};int fills[]={0,255,0,0};
 int i=seq-1;if(i<0||i>=4){fail++;return p;}
 if(p!=expected[i]||size!=lengths[i]||value!=fills[i]||D_0047C5B0||D_0047C5B4!=-1||
 D_0047C5AC||D_0047B580||D_0047C5A8)fail++;
 seq++;return memset(p,value,size);
}
int main(void){
 memset(D_0047C588,0x55,sizeof D_0047C588);memset(D_0047B588,0x55,sizeof D_0047B588);
 memset(D_0047B180,0x55,sizeof D_0047B180);memset(D_00479E00,0x55,sizeof D_00479E00);
 D_0047C5B0=D_0047C5B4=D_0047C5AC=D_0047B580=D_0047C5A8=7;seq=fail=0;D_00479DFC=2;
 func_003FB460();if(D_00479DFC!=1||seq||fail||D_0047C588[0]!=0x55)return 1;
 func_003FB460();if(D_00479DFC||seq!=5||fail)return 2;
 for(unsigned i=0;i<sizeof D_0047C588;i++)if(D_0047C588[i])return 3;
 for(unsigned i=0;i<sizeof D_0047B588;i++)if(D_0047B588[i]!=255)return 4;
 for(unsigned i=0;i<sizeof D_0047B180;i++)if(D_0047B180[i])return 5;
 for(unsigned i=0;i<sizeof D_00479E00;i++)if(D_00479E00[i])return 6;
 seq=fail=0;D_00479DFC=0;func_003FB460();if(D_00479DFC!=-1||seq||fail)return 7;
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_reference_and_cleanup_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_wrong_fill_is_rejected(self):
        self.assertNotEqual(self.run_case('fill'),0)

    def test_wrong_reset_is_rejected(self):
        self.assertNotEqual(self.run_case('reset'),0)
