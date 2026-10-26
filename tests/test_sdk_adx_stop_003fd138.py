"""Validate ADX stop returns, status transitions and native call sequence."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SdkAdxStop003fd138Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/sdk_adx_stop_003fd138.c').read_text()
        changes={'status':('p[1]=1;func_003F9660()', 'p[1]=2;func_003F9660()'),
                 'position':('return *(s32*)(p+0x14);', 'return 0;')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new)
        # PS2 addresses are 32-bit; make the same conversions explicit for a 64-bit host.
        body=body.replace('(s32)p', '(s32)(long)p').replace('(s8*)*(s32*)', '(s8*)(long)*(s32*)').replace('(s32*)*(s32*)', '(s32*)(long)*(s32*)')
        data='\n'.join((ROOT/('src/data/gAdxDiagnostic_'+address+'.c')).read_text() for address in ('004BB378','004BB3A0'))
        code=body+'\n'+data+r"""
static int seq,fail;static void *diag;static s32 actorbits;
void func_003FB510(s32 a,s32 b,s32 c,s32 d,s32 e){if(a!=5||c!=actorbits||d!=-1||e!=-1)fail++;if(b==0){if(seq!=0)fail++;seq=1;}else{if(b!=1||seq!=6)fail++;seq=7;}}
void func_003FB128(void*p){if(seq!=1)fail++;diag=p;seq=2;}
void func_00400740(s8*p){if((long)p!=0x1234||seq++!=1)fail++;}
void func_003F9630(void){if(seq++!=2)fail++;}
s32 func_00400B58(s32*p,s32*out){if((long)p!=0x1234||seq++!=3)fail++;*out=321;return 1;}
void func_003FCC80(S3FCC*p){if(!p||seq++!=4)fail++;}
void func_003F9660(void){if(seq++!=5)fail++;}
int main(void){
 _Alignas(16) u8 p[0x80]={0};s32 r;actorbits=0;seq=fail=0;diag=0;
 r=func_003FD138(0);if(r!=-3||seq!=2||fail||diag!=gAdxDiagnostic_004BB378)return 1;
 actorbits=(s32)(long)p;*(s32*)(p+0x14)=-17;
 for(int state=1;state<=3;state+=2){seq=fail=0;diag=0;p[1]=state;r=func_003FD138(p);if(r!=-17||p[1]!=1||seq!=1||fail||diag)return 2;}
 seq=fail=0;diag=0;p[1]=0;*(s32*)(p+4)=0;r=func_003FD138(p);if(r!=-1||seq!=2||fail||diag!=gAdxDiagnostic_004BB3A0)return 3;
 seq=fail=0;diag=0;p[1]=2;*(s32*)(p+4)=0x1234;*(s32*)(p+0x20)=0;
 r=func_003FD138(p);if(r!=-17||seq!=7||fail||diag||p[1]!=1||*(s32*)(p+0x20)!=321)return 4;
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_stop_paths(self):
        self.assertEqual(self.run_case(),0)

    def test_bad_state_is_rejected(self):
        self.assertNotEqual(self.run_case('status'),0)

    def test_bad_position_is_rejected(self):
        self.assertNotEqual(self.run_case('position'),0)
