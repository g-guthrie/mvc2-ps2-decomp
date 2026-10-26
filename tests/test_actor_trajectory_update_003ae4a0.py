"""Exercise the trajectory lifecycle with both complete native helpers."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorTrajectoryUpdate003ae4a0Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/actor_trajectory_update_003ae4a0.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p+0x18', 'p+0x500')
        native = 'typedef struct {u8 p0[0x18];Q*q;u8 p1[0x21-0x1C];u8 b21;u8 p2[0x34-0x22];V3 pos;u8 p3[0xD0-0x40];s32 i;u8 p4[0x140-0xD4];s16 flag;} H;'
        host = 'typedef struct {u8 p0[0x21];u8 b21;u8 p2[0x34-0x22];V3 pos;u8 p3[0xD0-0x40];s32 i;u8 p4[0x140-0xD4];s16 flag;u8 p142[0x500-0x142];Q*q;} H;'
        self.assertIn(native, body)
        body = body.replace(native, host)
        if mutation == 'timer':
            body = body.replace('--*(s16*)(p+0x1E)<=0', '--*(s16*)(p+0x1E)<0')
        if mutation == 'face':
            body = body.replace('if (p->flag != 0) t = -t;', 'if (p->flag == 0) t = -t;')
        if mutation == 'owner':
            body = body.replace('if(!p[0x21])', 'if(p[0x21])')
        if mutation == 'event':
            body = body.replace('e->value=0x3002', 'e->value=0x3003')
        code = r'''
#include <string.h>
''' + body + r'''
s16 D_004C1F50[4]={16,8,24,0};
signed char D_00473B80[16]={-16,0,31,0,-45,0,60,0,-60,0,75,0,0,0,0,0};
signed char D_00473B81[16]={53,0,53,0,63,0,63,0,84,0,84,0,0,0,0,0};
static Event event;static u8 *actor,*owner;static int allocs,frames,wrong,allow,mode,face,indexExpected,advanced;
void func_003AD6E0(u8*p) {(void)p;}
void *func_003DA750(void*ctx,int type,int init) {
 if(ctx || type!=1 || init!=1)wrong++;allocs++;return allow?&event:0;
}
int func_00175700(u8*p) {
 int k=indexExpected*4+mode*2;float dx=1.6666666269302368f*(float)D_00473B80[k];
 if(face)dx=-dx;
 float dy=2.142857074737549f*(float)D_00473B81[k];
 if(p!=actor || frames++ || *(int*)(p+0xD0)!=indexExpected ||
    *(float*)(p+0x34)!=100.0f+dx || *(float*)(p+0x38)!=200.0f+dy || *(float*)(p+0x3C)!=300.0f)wrong++;
 if(advanced && allow && (event.callback!=func_003AD6E0 || event.owner!=owner || event.field20!=8 ||
    event.field21!=mode || event.value!=0x3002 || event.pos.x!=1 || event.pos.y!=2 || event.pos.z!=3))wrong++;
 return 0;
}
int main(void) {
 _Alignas(16) u8 p[0x600],q[0x500];
 int timers[]={2,1,0,1,-1},indices[]={0,0,1,2,0},after[]={0,1,2,3,1},outTimers[]={1,8,24,0,8};
 for(int scenario=0;scenario<5;scenario++)for(mode=0;mode<2;mode++)for(face=0;face<2;face++)for(allow=0;allow<2;allow++) {
  memset(p,0,sizeof p);memset(q,0,sizeof q);memset(&event,0,sizeof event);actor=p;owner=q;allocs=frames=wrong=0;
  *(u8**)(p+0x500)=q;p[4]=255;p[0x21]=mode;*(s16*)(p+0x140)=face;*(s16*)(p+0x1E)=timers[scenario];
  *(int*)(p+0xD0)=indices[scenario];*(float*)(p+0x34)=1;*(float*)(p+0x38)=2;*(float*)(p+0x3C)=3;
  *(float*)(q+0x34)=100;*(float*)(q+0x38)=200;*(float*)(q+0x3C)=300;q[7]=5;
  indexExpected=after[scenario];advanced=(scenario==1 || scenario==2 || scenario==4);
  func_003AE4A0(p);
  int finished=(scenario==3);
  if(wrong || *(int*)(p+0xD0)!=after[scenario] || *(s16*)(p+0x1E)!=outTimers[scenario] ||
     p[4]!=(finished?0:255) || q[7]!=(finished&&!mode?2:5) ||
     allocs!=(advanced?1:0) || frames!=(finished?0:1))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_complete_lifecycle(self):
        self.assertEqual(self.run_case(), 0)

    def test_timer_boundary_is_checked(self):
        self.assertNotEqual(self.run_case('timer'), 0)

    def test_direction_is_checked(self):
        self.assertNotEqual(self.run_case('face'), 0)

    def test_owner_transition_is_checked(self):
        self.assertNotEqual(self.run_case('owner'), 0)

    def test_event_identity_is_checked(self):
        self.assertNotEqual(self.run_case('event'), 0)
