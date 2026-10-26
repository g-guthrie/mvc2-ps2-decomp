"""Check the size and handle path through the real pool allocator."""
import unittest
import test_owned_actor_states as states

class PoolAllocationChain003db9b0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        retry=states.function('src/grok_w3_003c.c','func_003DCFE0')
        wrapper=states.function('src/grok_tail_r2.c','func_003DB9B0')
        if mutation:
            old='return func_003F0C50((u8 *)D_005BF280, size);'
            new={'result':'return 0;', 'size':'return func_003F0C50((u8 *)D_005BF280, size+1);'}[mutation]
            self.assertIn(old,wrapper);wrapper=wrapper.replace(old,new,1)
        bridge=states.function('src/tail_leaves.c','func_003F0C50')
        allocator=states.function('src/w20b1_f.c','func_003F0C60')
        code=r"""
#include <string.h>
typedef unsigned char u8;typedef unsigned int u32;typedef int s32;
typedef struct {u32 addr,size;s32 owner,z;} PoolEntryNative;
typedef struct {s32 n,f4;PoolEntryNative *tab;s32 dir;u32 cur;s32 f14,f18;u32 total;} PoolArenaNative;
typedef PoolEntryNative E16;typedef PoolArenaNative Arena;
static union {PoolArenaNative pool;u8 bytes[128];} backing;
#define D_005BF280 (backing.bytes)
static u32 available,after_reset;static int resets;
u32 func_003F0B20(Arena*p){(void)p;return available;}
void func_003DD040(void){resets++;available=after_reset;}
u32 func_003F0C60(PoolArenaNative*,u32,u32);
s32 func_003F0C50(u8*,s32);
s32 func_003DB9B0(s32);
"""+allocator+bridge+wrapper+retry+r"""
int main(void){
 PoolEntryNative entries[2]={{0}};PoolArenaNative *p=&backing.pool;memset(&backing,0,sizeof backing);
 p->n=2;p->tab=entries;p->dir=1;p->cur=0x1000;p->f18=16;
 /* On a 64-bit host the native +24 byte field is not at the host struct's f18. */
 *(s32*)(backing.bytes+24)=16;
 available=1000;after_reset=1000;resets=0;
 if(func_003DCFE0(16,0)!=1||resets||entries[0].addr!=0x1000||entries[0].size!=16||p->cur!=0x1010||p->total!=16)return 1;
 available=0;after_reset=1000;resets=0;
 if(func_003DCFE0(16,3)!=2||resets!=1||entries[1].addr!=0x1010||entries[1].size!=16)return 2;
 available=0;after_reset=0;resets=0;if(func_003DCFE0(16,0)!=0||resets!=1)return 3;
 memset(entries,0,sizeof entries);p->dir=0;p->cur=0x200f;p->total=0;available=1000;resets=0;
 if(func_003DCFE0(16,0)!=1||entries[0].addr!=0x1ff0||p->cur!=0x1ff0||resets)return 4;
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_handle_and_retry_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_lost_handle_is_rejected(self):
        self.assertNotEqual(self.run_case('result'),0)

    def test_wrong_size_is_rejected(self):
        self.assertNotEqual(self.run_case('size'),0)
