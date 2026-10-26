"""Check the eight bounded child rows and actual owner/frame dispatch chain."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class OwnerTableChildStartTests(unittest.TestCase):
    def run_case(self,mutation=None):
        source=(ROOT/'src/owner_table_child_start_001d7150.c').read_text()
        wrapper=states.function('src/boolean_state_dispatch.c','func_001D7340')
        root=states.function('src/argument_dispatch_heads.c','func_001D7120').replace('p + 24','p + 0x580')
        if mutation=='owner':wrapper=wrapper.replace('(p,owner)','(p,p)')
        if mutation=='row':source=source.replace('].y','].x')
        if mutation=='hidden_reset':source=source.replace('*(int*)(p+0xD8)=0','*(int*)(p+0xD8)=1')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef int s32;typedef float f32;
void func_001D7150(u8*,u8*);void func_001D7340(u8*,u8*);
void func_001D7380(u8*,u8*);void func_001D7450(u8*,u8*);
int func_00175670(u8*);void func_001D7510(u8*,u8*);
void (*const jtbl_0044E620[2])(u8*,u8*)={func_001D7150,func_001D7340};
'''+source+root+wrapper+states.function('src/pw24_j.c','func_001D7450')+r'''
Row D_0044E630[8]={{16,152,2,0},{20,160,1,0},{14,164,2,0},{15,172,3,0},{13,181,0,0},{17,190,2,0},{14,197,2,0},{17,203,2,0}};
#define F(p,n) (*(float*)((p)+(n)))
#define I(p,n) (*(int*)((p)+(n)))
static u8 *actor,*owner,initial[0x600],final[0x600];static int wrong,animations,frames,parentCalls,visible,ownerSignal,animation;
int func_001754A0(u8*p,int group,int index){
 animations++;
 if(p!=actor||group!=27)wrong++;
 if(animations==1){if(index!=animation+6||memcmp(p,initial,sizeof initial))wrong++;}
 else if(animations==2){if(index!=animation+10||memcmp(p,final,sizeof final))wrong++;}
 else wrong++;
 return 0;
}
int func_00175670(u8*p){frames++;if(p!=actor||animations!=1+ownerSignal||memcmp(p,final,sizeof final))wrong++;return 1;}
void func_001D7510(u8*p,u8*q){(void)p;(void)q;wrong++;}
void func_001D7380(u8*p,u8*q){parentCalls++;if(p!=actor||q!=owner||animations||frames||memcmp(p,final,sizeof final))wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600];int faces[]={0,1,-32768,256};
 int xs[8]={16,20,14,15,13,17,14,17},ys[8]={152,160,164,172,181,190,197,203},anims[8]={2,1,2,3,0,2,2,2};
 for(int mode=0;mode<2;mode++)for(int row=0;row<8;row++)for(int f=0;f<4;f++)for(int signal=0;signal<2;signal++)for(int wrap=0;wrap<2;wrap++){
  memset(p,0xA5,sizeof p);memset(q,0x12,sizeof q);actor=p;owner=q;wrong=animations=frames=parentCalls=0;
  visible=mode;ownerSignal=signal;animation=anims[row];p[4]=wrap?255:0;p[5]=0;p[0x20]=mode;I(p,0xD4)=row;*(u8**)(p+0x580)=q;
  *(short*)(q+0x140)=faces[f];F(q,0x34)=10;F(q,0x38)=-20;F(q,0x50)=2;F(q,0x54)=3;F(q,0x58)=4;I(q,0xD8)=signal;
  memcpy(initial,p,sizeof p);initial[4]=(u8)(initial[4]+1);memcpy(initial+0xEC,q+0xEC,196);initial[0x13C]=1;
  initial[2]=q[2];initial[1]=q[1];memcpy(initial+0x50,q+0x50,12);initial[0x1B7]=q[0x1B7];initial[0x1B8]=q[0x1B8];initial[0x30]=q[0x30];initial[0x24]=q[0x24];F(initial,0x34)=10;F(initial,0x38)=-20;
  if(!mode){initial[0x13C]=0;I(initial,0xD0)=I(initial,0xD4)=I(initial,0xD8)=0;}
  else{initial[0x24]=0;float dx=(float)(faces[f]?-xs[row]:xs[row]);F(initial,0x34)=10+dx*1.6666666269302368f;F(initial,0x38)=-20+ys[row]*2.142857074737549f;initial[0x21]=animation;}
  memcpy(final,initial,sizeof final);if(mode&&signal)final[5]=1;
  if(wrap)func_001D7150(p,q);else func_001D7120(p);
  if(wrong||animations!=(mode?(1+signal):0)||frames!=mode||parentCalls!=!mode||memcmp(p,final,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_rows_and_parent_child_dispatch(self):self.assertEqual(self.run_case(),0)
    def test_wrong_owner_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
    def test_wrong_vertical_column_rejected(self):self.assertNotEqual(self.run_case('row'),0)
    def test_wrong_hidden_reset_rejected(self):self.assertNotEqual(self.run_case('hidden_reset'),0)
