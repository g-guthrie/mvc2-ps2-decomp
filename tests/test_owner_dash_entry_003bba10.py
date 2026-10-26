"""Exercise the initializer with both real owner-copy helpers."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class OwnerDashEntry003bba10Tests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/owner_dash_entry_003bba10.c').read_text()
        body = body.replace('__attribute__((section(".sdata")))', '').replace('p+0x18', 'p+0x500')
        parent = (ROOT / 'src/parent_state_copy.c').read_text().replace('p+0x18', 'p+0x500')
        helper = states.function('src/leaf_batch_b.c', 'func_003BD290').replace('a0 + 24', 'a0 + 0x500')
        if mutation == 'facing':
            body = body.replace('if(!owner[0x1E6])', 'if(owner[0x1E6])')
        if mutation == 'offset':
            body = body.replace('*(float*)(p+0x34)+=offset;', '*(float*)(p+0x34)-=offset;')
        if mutation == 'counter':
            body = body.replace('count[p[2]]', 'count[1-p[2]]')
        code = r'''
#include <string.h>
typedef signed char s8;
''' + body + parent + helper + r'''
static Counters bank;Counters *D_004C2794=&bank;
static u8 *actor;static int calls,wrong,face,team;
int func_001757E0(u8*p,int a,int b) {
 float offset=face?106.66666412353516f:-106.66666412353516f;
 float speed=face?3.3333332538604736f:-3.3333332538604736f;
 if(p!=actor || calls++ || a!=25 || b!=13 || p[5] || p[6] || p[2]!=team || p[1]!=44 ||
    p[0x13C]!=1 || *(s16*)(p+0x1C)!=96 || *(float*)(p+0x34)!=100.0f+offset ||
    *(float*)(p+0x38)!=200 || *(float*)(p+0x5C)!=speed || *(float*)(p+0x68)!=0 ||
    *(float*)(p+0x60)!=0 || *(float*)(p+0x6C)!=0 || p[0x1B0]!=68 || p[0x1B1]!=68 ||
    p[0xD4]!=0x63 || p[0xD5]!=0x62 || p[0xD6]!=44 || p[0xD7]!=255 || p[0xD8] ||
    p[0x1B5]!=21 || p[0x1B2] || *(u16*)(p+0x1C0) || *(int*)(p+0x1D8))wrong++;
 return 0;
}
int main(void) {
 _Alignas(16) u8 p[0x600],owner[0x600];
 for(face=0;face<2;face++)for(team=0;team<2;team++)for(int wrap=0;wrap<2;wrap++) {
  memset(p,0,sizeof p);memset(owner,0,sizeof owner);memset(&bank,0,sizeof bank);actor=p;calls=wrong=0;
  *(u8**)(p+0x500)=owner;p[4]=wrap?255:8;p[5]=9;p[6]=9;
  owner[1]=44;owner[2]=team;owner[0x1E6]=face;owner[0x168]=0x62;owner[0x169]=0x63;owner[0x2BC]=44;
  *(float*)(owner+0x34)=100;*(float*)(owner+0x38)=200;bank.count[team]=wrap?32767:5;
  func_003BBA10(p);
  if(wrong || calls!=1 || p[4]!=(wrap?0:9) || bank.count[team]!=(wrap?-32768:6) || bank.count[1-team])return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_real_helpers_and_callback(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_facing_is_rejected(self):
        self.assertNotEqual(self.run_case('facing'), 0)

    def test_wrong_offset_is_rejected(self):
        self.assertNotEqual(self.run_case('offset'), 0)

    def test_wrong_team_is_rejected(self):
        self.assertNotEqual(self.run_case('counter'), 0)
