"""Check typed lifecycle/owner dispatch, recovered handlers and native bounds."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]

def function(source,name):
    text=(ROOT/source).read_text()
    match=re.search(r'(?:^|\n)([^\n;{}]*\b'+name+r'\s*\([^;{}]*?\))\s*\{',text)
    if match is None:
        raise AssertionError(name)
    start=match.start(1);depth=1;end=match.end()
    while depth:
        depth+=(text[end]=='{')-(text[end]=='}');end+=1
    return text[start:end]+'\n'

class OwnedActorStateTests(unittest.TestCase):
    def compile_run(self,code):
        cc=shutil.which('cc')
        if cc is None:
            self.skipTest('A host C compiler is required')
        with tempfile.TemporaryDirectory() as temporary:
            path=Path(temporary);c=path/'states.c';binary=path/'states'
            # Native pointer-size assertions remain enforced by the PS2 build.
            header=(ROOT/'src/owner_effect_callbacks.h').read_text()
            header=re.sub(r'^typedef char \w+\[.*sizeof.*\];\n','',header,flags=re.MULTILINE)
            (path/'owner_effect_callbacks.h').write_text(header)
            c.write_text(code)
            built=subprocess.run([cc,'-std=c11','-Werror','-I',str(ROOT/'src'),'-I',str(ROOT/'src/data'),str(c),'-o',str(binary)],capture_output=True,text=True,timeout=30)
            self.assertEqual(built.returncode,0,built.stderr)
            return subprocess.run([str(binary)],timeout=10).returncode

    def run_owner(self,wrong_owner=False):
        dispatch=function('src/argument_dispatch_heads.c','func_001C0C30')
        if wrong_owner:
            changed=dispatch.replace('*(void **)(p + 24)','p')
            self.assertNotEqual(changed,dispatch);dispatch=changed
        # Keep host 64-bit owner pointers away from the native timer at 0x1c.
        dispatch=dispatch.replace('*(void **)(p + 24)','*(void **)(p + 0x580)')
        code=r'''
#include <string.h>
#include "owned_actor_states_0044c770.h"
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct {float x,y,z;} V3;
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(short*)((p)+(n)))
struct Object;
extern void func_003DAA40(struct Object*);
extern int func_00174470(const void*);
extern int func_00175670(u8*);
'''
        code+=(ROOT/'src/data/jtbl_0044C770.c').read_text()+'\n'+(ROOT/'src/data/jtbl_0044C868.c').read_text()+'\n'
        gpdata=(ROOT/'src/data/jtbl_004BF960.c').read_text()
        code+=gpdata+'\n#define jtbl_004BF9D0 (jtbl_004BF960.follow)\n'
        code+=(ROOT/'src/actor_depth_animation_001c0c60.c').read_text()+'\n'
        code+=(ROOT/'src/actor_follow_start_001c0e40.c').read_text()+'\n'
        for source,name in [('src/grok_w7_001c.c','func_001C1330'),('src/grok_w7_001c.c','func_001C1390'),('src/wave31.c','func_001C0E60'),('src/grok_w5_001c.c','func_001C0CC0'),('src/grok_w7_001c.c','func_001C1100'),('src/straight_leaves.c','func_001C1300'),('src/tail_leaves.c','func_001C1320'),('src/composite_dispatch_heads.c','func_001C0A70'),('src/composite_dispatch_heads.c','func_001C0FF0'),('src/composite_gp_dispatch_heads.c','func_001C0E20')]:
            code+=function(source,name)
        # The native alias is four pointer words into the physical owner.
        code+='#define jtbl_0044C780 (jtbl_0044C770.mode)\n'+dispatch
        for name,args in re.findall(r'extern void (func_\w+)\(([^;]*)\);',gpdata):
            if name in {'func_001C0E40','func_001C0E60'}:
                continue
            types=[v.strip() for v in args.split(',')]
            params=', '.join(t+' a'+str(i) for i,t in enumerate(types))
            ignores=''.join('(void)a'+str(i)+';' for i in range(len(types)))
            code+='void '+name+'('+params+') {'+ignores+'}\n'
        code+=r'''
static int frameResult,frameCalls,queryResult,tag,releaseCalls;
static u8 *seenActor,*seenOwner;
int func_00175670(u8 *p) {frameCalls++;seenActor=p;return frameResult;}
int func_00174470(const void *p) {(void)p;return queryResult;}
void func_003DAA40(struct Object *p) {releaseCalls++;seenActor=(u8*)p;}
void func_001C0A90(u8 *p) {tag=1;seenActor=p;}
#define OWNER_STUB(name,id) void name(u8 *p,u8 *owner) {tag=id;seenActor=p;seenOwner=owner;}
OWNER_STUB(func_001C0D20,2)
OWNER_STUB(func_001C0D90,3)
OWNER_STUB(func_001C0EF0,4)
OWNER_STUB(func_001C0F70,5)
OWNER_STUB(func_001C1160,6)
OWNER_STUB(func_001C1250,7)
OWNER_STUB(func_001C12B0,8)
OWNER_STUB(func_001C1010,1010)
OWNER_STUB(func_001C1080,1080)
int main(void) {
 _Alignas(16) u8 actor[0x600],owner[0x600];
 const int modes[3]={0,26,29},depths[2]={-128,127};
 int m,face,d,ended,i,marker,subMode=-1,gpMode=-1;
 if(jtbl_0044C770.mode[26]!=func_001C0C60 || jtbl_0044C770.mode[29]!=func_001C0C60)return 1;
 for(m=0;m<3;m++)for(face=0;face<2;face++)for(d=0;d<2;d++)for(ended=0;ended<2;ended++) {
  memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
  *(void**)(actor+0x18)=owner;actor[4]=1;actor[0x20]=modes[m];actor[0x13c]=9;
  F(actor,0x5c)=3;F(actor,0x60)=-4;
  F(owner,0x34)=10;F(owner,0x38)=20;F(owner,0x3c)=30;
  S(owner,0x140)=face;*(s8*)(owner+0x24)=depths[d];
  frameResult=ended?-128:0;frameCalls=0;
  func_001C0A70(actor);
  if(F(actor,0x34)!=(face?7.0f:13.0f) || F(actor,0x38)!=16 || F(actor,0x3c)!=30)return 2;
  if(S(actor,0x140)!=face || *(s8*)(actor+0x24)!=(m?depths[d]:8))return 3;
  if(actor[4]!=(ended?2:1) || actor[0x13c]!=(ended?0:9) || frameCalls!=1 || seenActor!=actor)return 4;
 }
 actor[4]=255;frameResult=-128;func_001C0C60(actor,owner);
 if(actor[4] || actor[0x13c])return 5;
 for(i=0;i<57;i++) {
  if(jtbl_0044C770.mode[i]==func_001C0FF0)subMode=i;
  if(jtbl_0044C770.mode[i]==func_001C0E20)gpMode=i;
 }
 if(subMode<0 || gpMode<0)return 6;
 for(i=0;i<2;i++) {
  memset(actor,0,sizeof(actor));*(void**)(actor+0x18)=owner;
  actor[4]=1;actor[5]=i;actor[0x20]=subMode;tag=0;
  func_001C0A70(actor);
  if(tag!=(i?1080:1010) || seenActor!=actor || seenOwner!=owner)return 7;
 }
 for(i=0;i<2;i++)for(marker=0;marker<2;marker++) {
  memset(actor,0,sizeof(actor));*(void**)(actor+0x18)=owner;
  actor[4]=1;actor[5]=i;actor[0x20]=gpMode;
  *(s8*)(actor+0x24)=-7;S(actor,0x140)=777;S(actor,0x1c)=3;
  F(actor,0x5c)=3;F(actor,0x60)=-4;
  F(owner,0x34)=10;F(owner,0x38)=20;F(owner,0x3c)=30;
  S(owner,0x140)=1;owner[0x151]=marker?255:0;
  frameResult=-128;frameCalls=0;
  func_001C0A70(actor);
  if(F(actor,0x34)!=7 || F(actor,0x38)!=16 || F(actor,0x3c)!=30)return 8;
  if(actor[4]!=(marker?1:2) || actor[5]!=1 || S(actor,0x1c)!=(i?4:1))return 12;
  if(actor[0x13c]!=(i?0:1) || *(s8*)(actor+0x24)!=(i?-7:15))return 13;
  if(S(actor,0x140)!=777 || frameCalls!=1 || seenActor!=actor)return 14;
 }
 actor[0x20]=subMode;actor[5]=2;actor[4]=1;
 F(actor,0x34)=1;F(actor,0x5c)=2;F(actor,0x68)=3;queryResult=0;
 func_001C0A70(actor);
 if(F(actor,0x34)!=3 || F(actor,0x5c)!=5 || actor[4]!=2)return 9;
 actor[4]=2;actor[0x13c]=9;releaseCalls=0;
 func_001C0A70(actor);
 if(actor[4]!=3 || actor[0x13c] || releaseCalls)return 10;
 func_001C0A70(actor);
 if(releaseCalls!=1 || seenActor!=actor)return 11;
 return 0;
}
'''
        code=code.replace('*(void**)(actor+0x18)','*(void**)(actor+0x580)')
        return self.compile_run(code)

    def run_random(self,wide_mask=False):
        code='#include <string.h>\n'+(ROOT/'src/actor_random_start_001ca5c0.c').read_text()
        if wide_mask:
            changed=code.replace('func_00174170()&15','func_00174170()&31')
            self.assertNotEqual(changed,code);code=changed
        code+=(ROOT/'src/data/jtbl_0044D8C0.c').read_text()+'\n'
        code+=function('src/composite_dispatch_heads.c','func_001CA560')
        code+=r'''
static int randomValue,randomCalls,sequence[4],length,bad;
static u8 *expectedActor;
int func_00174170(void) {randomCalls++;if(expectedActor[5]!=1)bad++;sequence[length++]=1;return randomValue;}
void func_001CADB0(u8 *p) {if(p!=expectedActor || *(s16*)(p+0x1c)!=(randomValue&15))bad++;sequence[length++]=2;}
void func_001CAC90(u8 *p) {if(p!=expectedActor || *(s16*)(p+0x1e)!=2)bad++;sequence[length++]=3;}
void func_001CA9F0(u8 *p) {if(p!=expectedActor)bad++;sequence[length++]=4;}
void func_001CA620(u8 *p) {(void)p;bad++;}
void func_001CA710(u8 *p) {(void)p;bad++;}
int main(void) {
 _Alignas(16) u8 actor[0x600];
 const int modes[6]={0,8,17,18,20,23},started[3]={0,1,255},values[6]={0,1,15,16,127,255};
 int m,s,r,i;
 for(m=0;m<6;m++)for(s=0;s<3;s++)for(r=0;r<6;r++) {
  memset(actor,0,sizeof(actor));actor[0x21]=modes[m];actor[5]=started[s];
  *(s16*)(actor+0x1c)=77;*(s16*)(actor+0x1e)=88;
  expectedActor=actor;randomValue=values[r];randomCalls=length=bad=0;
  func_001CA560(actor);
  if(bad || actor[5]!=(s?started[s]:1))return 1;
  if(s) {
   if(randomCalls || length!=1 || sequence[0]!=4 || *(s16*)(actor+0x1c)!=77 || *(s16*)(actor+0x1e)!=88)return 2;
  } else {
   if(randomCalls!=1 || length!=4 || *(s16*)(actor+0x1c)!=(values[r]&15) || *(s16*)(actor+0x1e)!=2)return 3;
   for(i=0;i<4;i++)if(sequence[i]!=i+1)return 4;
  }
 }
 return 0;
}
'''
        return self.compile_run(code)

    def test_owner_context_and_real_dispatch_paths(self):
        self.assertEqual(self.run_owner(),0)

    def test_wrong_owner_forwarding_is_detected(self):
        self.assertNotEqual(self.run_owner(wrong_owner=True),0)

    def test_random_initialization_and_always_run_update(self):
        self.assertEqual(self.run_random(),0)

    def test_wrong_random_mask_is_detected(self):
        self.assertNotEqual(self.run_random(wide_mask=True),0)
