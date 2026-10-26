"""Exercise the ADX read guard through its real forwarding wrapper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class SdkAdxRead003fcee0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body=(ROOT/'src/sdk_adx_read_003fcee0.c').read_text()
        changes={'result':('((u8*)p)[2]=1;return result;', '((u8*)p)[2]=1;return 0;'), 'error':('return -3;', 'return -2;')}
        if mutation:
            old,new=changes[mutation];self.assertIn(old,body);body=body.replace(old,new,1)
        wrapper=states.function('src/ee96_validation_thunk.c','func_003FCF70')
        data='\n'.join((ROOT/('src/data/gAdxDiagnostic_'+address+'.c')).read_text() for address in ('004BB218','004BB240','004BB270'))
        code=body+'\n'+data+r"""
static int calls,logs,seen_n,seen_x,returned;static void *message,*seen;
void func_003FB128(void *p){logs++;message=p;}
s32 func_003FCDE0(A *p,s32 n,s32 x){calls++;seen=p;seen_n=n;seen_x=x;return returned;}
"""+wrapper+r"""
int main(void){
 A object={0};u8 *p=(u8*)&object;int r;
 calls=logs=0;r=func_003FCF70(0,-1,0);if(r!=-3||logs!=1||message!=gAdxDiagnostic_004BB218||calls)return 1;
 calls=logs=0;r=func_003FCF70(&object,-1,0);if(r!=-3||logs!=1||message!=gAdxDiagnostic_004BB240||calls)return 2;
 calls=logs=0;r=func_003FCF70(&object,0,0);if(r!=-3||logs!=1||message!=gAdxDiagnostic_004BB270||calls)return 3;
 calls=logs=0;p[1]=2;p[2]=9;r=func_003FCF70(&object,5,7);if(r||logs||calls||p[2]!=9)return 4;
 for(int i=0;i<2;i++){
  calls=logs=0;seen=0;p[1]=(u8)(i?255:1);p[2]=0;returned=i?-17:42;
  r=func_003FCF70(&object,5,7);
  if(r!=returned||calls!=1||logs||seen!=&object||seen_n!=5||seen_x!=7||p[2]!=1)return 5;
 }
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_validations_and_results(self):
        self.assertEqual(self.run_case(),0)

    def test_lost_result_is_rejected(self):
        self.assertNotEqual(self.run_case('result'),0)

    def test_wrong_error_is_rejected(self):
        self.assertNotEqual(self.run_case('error'),0)
