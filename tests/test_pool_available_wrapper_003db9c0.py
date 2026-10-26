"""Check the wrapper against the real pool-availability implementation."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class PoolAvailableWrapper003db9c0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        wrapper=states.function('src/grok_r1_0038.c','func_003DB9C0')
        if mutation:
            old='return func_003F0A60((S3F *)D_005BF280, size);'
            new={'result':'return 0;', 'size':'return func_003F0A60((S3F *)D_005BF280, size+1);'}[mutation]
            self.assertIn(old,wrapper);wrapper=wrapper.replace(old,new,1)
        callee=states.function('src/sa40_b.c','func_003F0A60')
        code=r"""
#include <string.h>
typedef unsigned char u8;typedef unsigned int u32;typedef signed int s32;
typedef struct {s32 f0;u32 f4;s32 f8,fC,f10;u32 f14,f18;} S3F;
static union {S3F pool;u8 bytes[128];} backing;
#define D_005BF280 (backing.bytes)
static u32 available,after_reset;static int resets;
u32 func_003F0B20(S3F*p){(void)p;return available;}
void func_003F0E60(S3F*p){(void)p;resets++;available=after_reset;}
u32 func_003F0A60(S3F*,u32);
"""+callee+wrapper+r"""
int main(void){
 S3F *p=&backing.pool;memset(p,0,sizeof *p);p->f18=16;p->f14=0x1000;p->f4=0x400;p->fC=1;
 available=64;resets=0;if(func_003DB9C0(16)!=0x13f0||resets)return 1;
 if(func_003DB9C0(17)!=0x13e0||resets)return 2;
 p->fC=0;if(func_003DB9C0(17)!=0xc00||resets)return 3;
 p->fC=1;available=8;after_reset=16;resets=0;if(func_003DB9C0(17)!=0||resets!=1)return 4;
 available=8;after_reset=64;resets=0;if(func_003DB9C0(17)!=0x13e0||resets!=1)return 5;
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_size_and_return_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_discarded_result_is_rejected(self):
        self.assertNotEqual(self.run_case('result'),0)

    def test_wrong_size_is_rejected(self):
        self.assertNotEqual(self.run_case('size'),0)
