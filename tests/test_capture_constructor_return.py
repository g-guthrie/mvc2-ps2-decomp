"""Validate the real capture constructor's nullable pointer result and fields.

Typed host fields exercise the contract; whole-object comparison separately
checks the PS2 offsets and pointer width.
"""
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

class CaptureConstructorReturnTests(unittest.TestCase):
    def test_allocated_pointer_or_null_is_returned(self):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        source=(ROOT/'src/q7_a.c').read_text()
        source=source[source.index('typedef struct {\n    u8 pad0[0x10]'):source.index('\nextern void func_001CCD40')]
        code=r'''
#include <string.h>
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
'''+source+r'''
static Obj allocated;
static int failAllocation,calls,badArguments;
void *func_003DA750(void *pool,s32 kind,s32 flags) {
 calls++;
 if(pool || kind!=3 || flags)badArguments++;
 return failAllocation?0:&allocated;
}
void func_001D7D70(void) {}
void func_001D8160(void) {}
int main(void) {
 const int modes[4]={0,1,256,-1};
 Src owner,originalOwner;
 Obj originalObject;
 int sample,fail;
 memset(&owner,0x5A,sizeof(owner));
 owner.h168=0xFEDC;owner.b1B5=0xF3;owner.w1C4=0xDEADBEEFu;
 memcpy(&originalOwner,&owner,sizeof(owner));
 for(sample=0;sample<4;sample++)for(fail=0;fail<2;fail++) {
  Obj *result;
  int mode=modes[sample];
  memset(&allocated,0xCC,sizeof(allocated));memcpy(&originalObject,&allocated,sizeof(allocated));
  failAllocation=fail;calls=badArguments=0;
  result=func_001D7CE0(&owner,mode);
  if(calls!=1 || badArguments)return 1;
  if(memcmp(&owner,&originalOwner,sizeof(owner)))return 2;
  if(fail) {
   if(result || memcmp(&allocated,&originalObject,sizeof(allocated)))return 3;
  } else {
   if(result!=&allocated || result->f18!=&owner)return 4;
   if(result->f10!=(mode?(void*)func_001D8160:(void*)func_001D7D70))return 5;
   if(result->h26!=0x2F05 || result->fD0!=0xFEDCu || result->fD4!=0xF3u)return 6;
   if(result->fD8!=0xDEADBEEFu || result->b20!=(u8)mode || result->b21!=(u8)(mode-1))return 7;
   if(result->pad0[0]!=0xCC || result->pad14[0]!=0xCC)return 8;
  }
 }
 failAllocation=1;
 if(func_001D7CE0(0,1))return 9;
 return 0;
}
'''
        with tempfile.TemporaryDirectory() as temporary:
            path=Path(temporary);c=path/'capture.c';binary=path/'capture'
            c.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror',str(c),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            self.assertEqual(subprocess.run([str(binary)],timeout=10).returncode,0)
