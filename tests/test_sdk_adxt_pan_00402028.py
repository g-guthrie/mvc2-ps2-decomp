"""Check pan writes through the real forwarding and clamping functions."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SdkAdxtPan00402028Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/sdk_adxt_pan_00402028.c').read_text()
        changes={'forward':('index,value);','index,0);'), 'order':('*(s16*)(p+0x42+index*2)=value;','*(s16*)(p+0x42+index*2)=0;')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new,1)
        wrapper=states.function('src/k0.c','func_003FF270')
        clamp=states.function('src/w9e1.c','func_0040EE00')
        data='\n'.join((ROOT/('src/data/gAdxtDiagnostic_'+address+'.c')).read_text() for address in ('004BC188','004BC1B8'))
        code=body+'\n'+data+r"""
static int logs;static void *message;
void func_003FB128(void*p){logs++;message=p;}
void func_0040EE00(s32*,s32,s32);
"""+wrapper+clamp+r"""
int main(void){
 _Alignas(16) u8 storage[0x110]={0};u8*p=storage+4;s32 output[32]={0};
 logs=0;func_00402028(0,0,0);if(logs!=1||message!=gAdxtDiagnostic_004BC188)return 1;
 *(s32**)(p+0x0C)=output;p[3]=2;logs=0;
 func_00402028(p,0,-31);if(logs||*(s16*)(p+0x42)!=-31||output[14]!=-15)return 2;
 func_00402028(p,1,65541);if(logs||*(s16*)(p+0x44)!=5||output[15]!=15)return 3;
 func_00402028(p,-1,9);if(logs||*(s16*)(p+0x40)!=9||output[13]!=9)return 4;
 p[3]=1;logs=0;output[15]=77;func_00402028(p,1,12);
 if(logs!=1||message!=gAdxtDiagnostic_004BC1B8||*(s16*)(p+0x44)!=12||output[15]!=77)return 5;
 p[3]=255;logs=0;func_00402028(p,0,7);if(logs!=1||message!=gAdxtDiagnostic_004BC1B8||*(s16*)(p+0x42)!=7)return 6;
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_native_paths_and_forwarding(self):
        self.assertEqual(self.run_case(),0)

    def test_lost_value_is_rejected(self):
        self.assertNotEqual(self.run_case('forward'),0)

    def test_wrong_store_is_rejected(self):
        self.assertNotEqual(self.run_case('order'),0)
