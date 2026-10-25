"""Check motion, post-animation contact and the real work-record helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT=Path(__file__).resolve().parents[1]

class ActorMotionContactTests(unittest.TestCase):
    def run_motion(self,stale_contact=False,wrong_work=False):
        source=(ROOT/'src/actor_motion_contact_002361f0.c').read_text()
        if stale_contact:
            changed=source.replace('void func_002361F0(u8 *p,u8 *work) {','void func_002361F0(u8 *p,u8 *work) {\n int contact=p[0x15B];').replace('if(p[0x15B])','if(contact)')
            self.assertNotEqual(changed,source);source=changed
        if wrong_work:
            changed=source.replace('func_00238B70(p,(float*)work)','func_00238B70(p,(float*)p)')
            self.assertNotEqual(changed,source);source=changed
        code=r'''
#include <string.h>
typedef short s16;
typedef signed char s8;
typedef int s32;
typedef float f32;
'''+source+'\n'+(ROOT/'src/data/jtbl_00452358.c').read_text()+'\n'+(ROOT/'src/data/data_raw_004520C0.c').read_text()+r'''
#define D_004520C0 data_raw_004520C0
extern const ContextCallback jtbl_00452358[3];
'''+states.function('src/preaction_dispatch_heads.c','func_002361C0')+states.function('src/g8b.c','func_00238B70')+r'''
static int frames,spawns,wrong,contact,marked,spawnResult;
static unsigned char oldPhase;
static u8 *expected,*workExpected;
static float workX,workY;
#define F(p,n) (*(float*)((p)+(n)))
int func_00175700(u8 *p) {
 frames++;
 if(p!=expected||F(p,0x34)!=12||F(p,0x5C)!=1.75f||F(p,0x38)!=-1||F(p,0x60)!=2.5f)wrong++;
 p[0x15B]=contact?255:0;p[0x1B7]=marked?255:0;return -1;
}
int func_001A1330(u8 *p,int n,u8 x) {
 spawns++;
 if(p!=expected||frames!=1||n!=(marked?10:8)||x||p[7]!=(u8)(oldPhase+1)||F(workExpected,36)!=workX||F(workExpected,40)!=workY)wrong++;
 return spawnResult;
}
void func_002362B0(u8 *p,u8 *w){(void)p;(void)w;}
void func_00236350(u8 *p,u8 *w){(void)p;(void)w;}
int main(void) {
 _Alignas(16) u8 p[0x600],want[0x600];int row,direction,wrap,result;
 int dirs[3]={0,1,255};
 for(row=0;row<44;row++)for(direction=0;direction<3;direction++)for(contact=0;contact<2;contact++)for(marked=0;marked<2;marked++)for(wrap=0;wrap<2;wrap++)for(result=0;result<2;result++) {
  memset(p,0x5A,sizeof(p));p[7]=wrap?255:0;oldPhase=p[7];p[0x151]=row;p[0x1E6]=dirs[direction];
  p[0x15B]=contact?0:255;p[0x1B7]=marked?0:255;p[0x209]=2;
  F(p,0x34)=10;F(p,0x5C)=2;F(p,0x68)=-0.25f;F(p,0x38)=-4;F(p,0x60)=3;F(p,0x6C)=-0.5f;
  memcpy(want,p,sizeof(p));F(want,0x34)=12;F(want,0x5C)=1.75f;F(want,0x38)=-1;F(want,0x60)=2.5f;
  want[0x15B]=contact?255:0;want[0x1B7]=marked?255:0;
  workX=(5.0f/3.0f)*data_raw_004520C0[row][0];if(dirs[direction])workX=-workX;
  workY=(15.0f/7.0f)*data_raw_004520C0[row][1];
  if(contact){want[7]=(u8)(p[7]+1);F(want,0x2DC)=workX;F(want,0x2E0)=workY;if(!result)want[6]=2;}
  expected=p;workExpected=p+0x2B8;spawnResult=result?2:0;frames=spawns=wrong=0;
  if(wrap)func_002361F0(p,p+0x2B8);else func_002361C0(p,p+0x2B8);
  if(memcmp(p,want,sizeof(p)))return 1;
  if(frames!=1||spawns!=contact||wrong)return 2;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_all_work_rows_motion_contact_reload_and_effect_results(self):
        self.assertEqual(self.run_motion(),0)

    def test_stale_contact_flag_is_detected(self):
        self.assertNotEqual(self.run_motion(stale_contact=True),0)

    def test_wrong_work_record_is_detected(self):
        self.assertNotEqual(self.run_motion(wrong_work=True),0)
