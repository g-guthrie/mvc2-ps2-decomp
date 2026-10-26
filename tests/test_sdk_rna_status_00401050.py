"""Validate native diagnostic order and totals through the actual C body."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SdkRnaStatus00401050Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/sdk_rna_status_00401050.c').read_text()
        changes={'total':('a+b+c+d','a+b+c'), 'mode':('f24(o,0)','f24(o,1)')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new,1)
        # The PS2 handle is 32-bit; make the conversion explicit on a 64-bit host.
        body=body.replace('(s32)handle','(s32)(long)handle')
        names=('gAdxRnaTempCountsFormat_004BBF48','gAdxRnaIopTempCountsFormat_004BBF68','gAdxRnaStatusTotalsFormat_004BBF88')
        data='\n'.join((ROOT/('src/data/'+name+'.c')).read_text() for name in names)
        code=r"""
#include <stdarg.h>
"""+body+'\n'+data+r"""
static u8 base[16],handle[16];static Obj obj;static struct VT vt;
static int seq,fail;
u8 *func_0040EF88(u8*p,s32 i){if(p!=base||i||seq++!=0)fail++;return handle;}
u8 *func_0040EF70(u8*p,s32 i){if(p!=base||i||seq++!=1)fail++;return (u8*)&obj;}
static s32 virtual_call(Obj*p,s32 mode){if(p!=&obj||seq!=(mode?2:3))fail++;seq++;return mode?10:20;}
s32 func_00410AD0(s32 h,s32 mode){if(h!=(s32)(long)handle||seq!=(mode?4:5))fail++;seq++;return mode?3:4;}
void func_0011EB60(const char*fmt,...){
 va_list args;int a,b,c;va_start(args,fmt);a=va_arg(args,int);b=va_arg(args,int);
 if(seq==6){c=va_arg(args,int);if(fmt!=gAdxRnaTempCountsFormat_004BBF48||a!=10||b!=20||c!=30)fail++;}
 else if(seq==7){c=va_arg(args,int);if(fmt!=gAdxRnaIopTempCountsFormat_004BBF68||a!=3||b!=4||c!=7)fail++;}
 else if(seq==8){if(fmt!=gAdxRnaStatusTotalsFormat_004BBF88||a!=-7||b!=37)fail++;}
 else fail++;
 va_end(args);seq++;
}
int main(void){Context ctx={0};vt.f24=virtual_call;obj.vt=&vt;ctx.base=base;ctx.status=-7;seq=fail=0;
 func_00401050(&ctx);return fail||seq!=9;}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_status_output(self):
        self.assertEqual(self.run_case(),0)

    def test_missing_total_is_rejected(self):
        self.assertNotEqual(self.run_case('total'),0)

    def test_wrong_virtual_mode_is_rejected(self):
        self.assertNotEqual(self.run_case('mode'),0)
