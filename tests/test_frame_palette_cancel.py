"""Exercise the full frame-palette cancel path and native input helper."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class FramePaletteCancelTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/frame_palette_cancel_0021d400.c').read_text()
        if mutation == 'guard':
            body = body.replace('p[0x1fd]==1', 'p[0x1fd]!=1')
        if mutation == 'count':
            body = body.replace('--*(unsigned short*)(work+0x22);', '++*(unsigned short*)(work+0x22);')
        code = r'''
#include <string.h>
typedef signed char s8;
''' + body + states.function('src/wave19.c', 'func_0018A990') + r'''
Frame D_004F54D0[5];
int main(void) {
 _Alignas(16) u8 p[0x600];
 for(int bad=0;bad<7;bad++) for(int direction=0;direction<2;direction++) {
  memset(p,0,sizeof p);memset(D_004F54D0,0,sizeof D_004F54D0);
  p[0x1E4]=21;p[0x1FD]=1;p[6]=2;p[5]=0;p[0x1B7]=7;p[0x212]=9;
  *(u16*)(p+0x2DA)=5;*(u16*)(p+0x35E)=0x20;
  *(u16*)(p+0x38E)=direction?0x160:0x240;
  *(float*)(p+0x5C)=1;*(float*)(p+0x60)=2;*(float*)(p+0x68)=3;*(float*)(p+0x6C)=4;
  if(bad==1)p[0x1E4]=20;
  if(bad==2)p[0x1FD]=0;
  if(bad==3)p[6]=1;
  if(bad==4)p[5]=1;
  if(bad==5)*(u16*)(p+0x2DA)=0;
  if(bad==6)*(u16*)(p+0x35E)=0;
  func_0021D400(p);
  int triggered=!bad && direction;
  if(p[6]!=(triggered?0:(bad==3?1:2)) || p[0x1B7]!=(bad?7:direction) ||
     *(u16*)(p+0x2DA)!=(bad==5?0:(triggered?4:5)) ||
     *(float*)(p+0x5C)!=(triggered?0:1) || *(float*)(p+0x60)!=(triggered?0:2) ||
     *(float*)(p+0x68)!=(triggered?0:3) || *(float*)(p+0x6C)!=(triggered?0:4)) return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_guards_and_real_input_helper(self):
        self.assertEqual(self.run_case(), 0)

    def test_bad_mode_guard_is_rejected(self):
        self.assertNotEqual(self.run_case('guard'), 0)

    def test_wrong_counter_direction_is_rejected(self):
        self.assertNotEqual(self.run_case('count'), 0)
