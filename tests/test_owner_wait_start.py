"""Exercise owner copies and all three actual nested callback contracts."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class OwnerWaitStartTests(unittest.TestCase):
    def run_start(self,wrong_owner=False,wide_random=False):
        source=(ROOT/'src/owner_wait_start_001d8190.c').read_text()
        if wrong_owner:
            changed=source.replace('func_001D7E50(p,q)','func_001D7E50(p,p)')
            self.assertNotEqual(changed,source);source=changed
        if wide_random:
            changed=source.replace('func_00174170()&3','func_00174170()&7')
            self.assertNotEqual(changed,source);source=changed
        root=states.function('src/argument_dispatch_heads.c','func_001D8160')
        root=root.replace('*(void **)(p + 24)','*(void **)(p + 0x580)')
        code=r'''
#include <string.h>
typedef int s32;
typedef float f32;
struct Object;
void func_003DAA40(struct Object*);
'''+source+'\n'+(ROOT/'src/data/jtbl_0044E6B0.c').read_text()+'\n'+(ROOT/'src/random_state_step.c').read_text()+'\n'
        code+=r'''
extern const Mvc2OwnerStateCallback jtbl_0044E6A0[3];
'''+root+states.function('src/composite_dispatch_heads.c','func_001D7E50')
        code+=states.function('src/w173_f.c','func_001D8000')
        code+=states.function('src/grok_w5_001d.c','func_001D8100')
        code+=states.function('src/straight_leaves.c','func_001D8550')
        code+=states.function('src/tail_leaves.c','func_001D8570')
        code+=r'''
u8 D_004C26AC,D_004C26B0;
static int animations,frames,forwarded,wrong,frameResult;
static int choices[2];static u8 *expected,*owner;
int func_001754A0(u8 *p,int a,int b){if(animations<2)choices[animations]=b;animations++;if(p!=expected||a!=27)wrong++;return 0;}
int func_00175670(u8 *p){frames++;if(p!=expected)wrong++;return frameResult;}
/* The first nested handler remains assembly; check its native input boundary. */
static void wait_native(u8 *p,void *q){forwarded++;if(p!=expected||q!=owner)wrong++;}
const Mvc2OwnerStateCallback jtbl_0044E6A0[3]={wait_native,func_001D8000,func_001D8100};
void func_001D82B0(u8 *p,void *q){(void)p;(void)q;}
void func_003DAA40(struct Object *p){(void)p;}
#define F(p,n) (*(float*)((p)+(n)))
#define H(p,n) (*(short*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x600],aux[0x600],want[0x600];
 int modes[3]={0,1,255};int mode,phase,negative,waiting,seed,i;
 for(mode=0;mode<3;mode++)for(phase=0;phase<3;phase++)for(negative=0;negative<2;negative++)for(waiting=0;waiting<2;waiting++)for(seed=0;seed<256;seed++) {
  unsigned state=(unsigned)seed|((255u-seed)<<8),step=(3*state)>>8;
  unsigned next=((seed+step)&255)|((step&255)<<8);
  int first=modes[mode]!=0,advance=phase==1&&(!waiting||!first),count=first+advance;
  for(i=0;i<0x600;i++){p[i]=(u8)(i*7+13);q[i]=(u8)(i*11+19);aux[i]=0;}
  p[4]=0;p[5]=phase;p[0x21]=modes[mode];H(p,0x1C)=25;
  *(u8**)(p+0x580)=q;*(u8**)(p+0xD8)=aux;
  F(q,0x50)=1.25f;F(q,0x54)=2.5f;F(q,0x58)=-4.5f;
  F(p,0x68)=1.5f;F(p,0x6C)=-2.5f;
  F(aux,0x34)=80;F(aux,0x38)=90;H(aux,0x140)=negative;
  aux[0x20D]=negative?3:1;aux[0x24]=0xF0;aux[0x247]=waiting?9:0;
  memcpy(want,p,sizeof(p));want[4]=1;memcpy(want+0xEC,q+0xEC,196);
  want[0x13C]=1;want[2]=q[2];want[1]=q[1];memcpy(want+0x50,q+0x50,12);
  want[0x1B7]=q[0x1B7];want[0x1B8]=q[0x1B8];want[0x30]=q[0x30];want[0x24]=q[0x24];
  if(first)want[0x31]=255;else{want[0x13C]=0;H(want,0x1C)=0;H(want,0x1E)=17;}
  if(phase==1){
   F(want,0x34)=80+(negative?-1.5f:1.5f);F(want,0x38)=90+(-2.5f/(negative?4:2));want[0x24]=0xF0;
   if(waiting)H(want,0x1C)--;
   if(advance)want[5]=2;
  }
  if(phase==2&&negative){want[4]=2;want[0x13C]=0;}
  D_004C26AC=seed;D_004C26B0=255-seed;
  animations=frames=forwarded=wrong=0;expected=p;owner=q;frameResult=negative?-1:0;
  func_001D8160(p);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(animations!=count||forwarded!=(phase==0)||wrong)return 2;
  if(first&&choices[0]!=(int)((next&3)+6))return 3;
  if(advance&&choices[first]!=(u8)(p[0x168]+4))return 4;
  if(frames!=(phase==1?1:phase==2?(negative?1:2):0))return 5;
  if((D_004C26AC|(D_004C26B0<<8))!=(first?next:state))return 6;
 }
 return 0;
}
'''
        code=code.replace('void func_001D8100(u8 *p,void *owner_context_unused)','int func_00175670(u8*);\nvoid func_001D8100(u8 *p,void *owner_context_unused)')
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_all_nested_phases_real_children_copy_and_random_selector(self):
        self.assertEqual(self.run_start(),0)

    def test_wrong_owner_forwarding_is_detected(self):
        self.assertNotEqual(self.run_start(wrong_owner=True),0)

    def test_widened_random_selector_is_detected(self):
        self.assertNotEqual(self.run_start(wide_random=True),0)
