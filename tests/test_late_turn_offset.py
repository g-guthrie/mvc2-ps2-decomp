"""Check that setup precedes facing changes and tail-state resets follow placement."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class LateTurnOffsetTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/actor_late_turn_offset_00242e50.c').read_text()
        if mutation=='early':body=body.replace('func_001266A0(p,5,5);','').replace('offset[0]=','func_001266A0(p,5,5);offset[0]=')
        if mutation=='reset':body=body.replace('p[7]=0;','')
        root=states.function('src/argument_dispatch_heads.c','func_00242E20')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef short s16;
void func_00242E50(u8*);extern void func_0015D090(u8*),func_001E3C40(u8*);
void (*const jtbl_00452AA8[3])(u8*)={func_00242E50,0,0};
'''+root+body+states.function('src/create_offset_effect_0015D010.c','func_0015D010')+r'''
#define F(p,n) (*(float*)((p)+(n)))
static u8 *actor,before[0x600],afterSetup[0x600],final[0x600];static int wrong,step,newFlags,newFace,newByte;static float xyz[3];
void func_001266A0(u8*p,int a,int b){if(p!=actor||a!=5||b!=5||step++!=0||memcmp(p,before,sizeof before))wrong++;*(unsigned short*)(p+0x20E)=newFlags;*(short*)(p+0x140)=newFace;p[0x1E6]=newByte;F(p,0x34)=100;F(p,0x38)=200;F(p,0x3C)=300;}
void func_0015D090(u8*p){float*v=(float*)p;if(step++!=1||v[0]!=xyz[0]||v[1]!=xyz[1]||v[2]!=xyz[2])wrong++;}
void func_001E3C40(u8*p){if(p!=actor||step++!=2||memcmp(p,afterSetup,sizeof afterSetup))wrong++;}
void func_0018C6E0(u8*p){if(p!=actor||step++!=3||memcmp(p,afterSetup,sizeof afterSetup))wrong++;p[6]=0x12;p[7]=0x34;}
int func_001757E0(u8*p,int a,int b){if(p!=actor||step++!=4||a!=15||b||memcmp(p,final,sizeof final))wrong++;return -1;}
int main(void){
 _Alignas(16) u8 p[0x600];int oldFlags[]={0,0x400},flags[]={0,0x200,0x400,0xFFFF},faces[]={0,1,-32768,32767},bytes[]={0,128,255};
 for(int o=0;o<2;o++)for(int n=0;n<4;n++)for(int f=0;f<4;f++)for(int b=0;b<3;b++){
  memset(p,0xA5,sizeof p);actor=p;wrong=step=0;newFlags=flags[n];newFace=faces[f];newByte=bytes[b];p[0x20B]=0xC0;*(unsigned short*)(p+0x20E)=oldFlags[o];*(short*)(p+0x140)=0;
  memcpy(before,p,sizeof p);memcpy(afterSetup,p,sizeof p);*(unsigned short*)(afterSetup+0x20E)=newFlags;*(short*)(afterSetup+0x140)=newFace;afterSetup[0x1E6]=newByte;
  F(afterSetup,0x34)=100;F(afterSetup,0x38)=200;F(afterSetup,0x3C)=300;
  if(newFlags&0x400){*(short*)(afterSetup+0x140)^=1;afterSetup[0x1E6]^=1;}
  memcpy(final,afterSetup,sizeof final);final[0x1B4]=10;final[6]=final[7]=0;
  xyz[0]=*(short*)(afterSetup+0x140)?100-(-146.66665649414062f):100+(-146.66665649414062f);xyz[1]=200+188.57142639160156f;xyz[2]=300;
  func_00242E20(p);
  if(wrong||step!=5||memcmp(p,final,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_post_setup_facing_and_real_offset_helper(self):self.assertEqual(self.run_case(),0)
    def test_pre_setup_flip_rejected(self):self.assertNotEqual(self.run_case('early'),0)
    def test_missing_subphase_reset_rejected(self):self.assertNotEqual(self.run_case('reset'),0)
