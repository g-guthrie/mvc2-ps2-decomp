"""Check motion initialization through the actual first-state dispatcher."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class ActorMotionStart002f8470Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / "src/actor_motion_start_002f8470.c").read_text()
        changes = {
            "facing": ("p[0x1E6]?", "!p[0x1E6]?"),
            "timer": ("=24", "=23"),
            "acceleration": ("*ax=0", "*ax=1"),
        }
        if mutation:
            old, new = changes[mutation]
            self.assertIn(old, body)
            body = body.replace(old, new, 1)
        root = states.function("src/composite_dispatch_heads.c", "func_002F8450")
        code = r"""
#include <string.h>
""" + body + r"""
void (*const jtbl_0045BE70[])(u8*) = {func_002F8470};
""" + root + r"""
int main(void) {
 _Alignas(16) u8 p[0x300];
 int faces[3] = {0, 1, 255};
 for (int i=0; i<3; i++) for (int wrap=0; wrap<2; wrap++) {
  memset(p,0,sizeof p); p[6]=wrap?255:0; p[0x1E6]=faces[i];
  *(s16*)(p+0x1C)=9; *(float*)(p+0x34)=100; *(float*)(p+0x38)=200;
  *(float*)(p+0x5C)=2; *(float*)(p+0x60)=3; *(float*)(p+0x68)=4; *(float*)(p+0x6C)=5;
  if(wrap) func_002F8470(p); else func_002F8450(p);
  float speed=faces[i]?13.333333015441895f:-13.333333015441895f;
  if(p[6]!=(u8)(wrap?0:1) || *(s16*)(p+0x1C)!=24 || *(float*)(p+0x34)!=100+speed ||
     *(float*)(p+0x38)!=200 || *(float*)(p+0x5C)!=speed || *(float*)(p+0x60)!=0 ||
     *(float*)(p+0x68)!=0 || *(float*)(p+0x6C)!=0) return 1;
 }
 return 0;
}
"""
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_motion_start(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case("facing"), 0)

    def test_wrong_timer_is_rejected(self):
        self.assertNotEqual(self.run_case("timer"), 0)

    def test_wrong_acceleration_is_rejected(self):
        self.assertNotEqual(self.run_case("acceleration"), 0)
