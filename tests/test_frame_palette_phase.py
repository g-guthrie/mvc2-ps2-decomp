"""Test the real palette operation followed by the phase gate."""
import unittest
from pathlib import Path
import test_owned_actor_states as states

ROOT = Path(__file__).resolve().parents[1]

class FramePalettePhaseTests(unittest.TestCase):
    def run_case(self, mutation=None):
        body = (ROOT / 'src/frame_palette_phase_0021ed90.c').read_text()
        body = body.replace('__attribute__((section(".bss")))', '')
        if mutation == 'threshold':
            body = body.replace('D_004D18A0<2', 'D_004D18A0<3')
        if mutation == 'palette':
            body = body.replace('attribute&=0xFFF', 'attribute&=0xFFFF')
        code = r'''
#include <string.h>
''' + body + r'''
Frame D_004F54D0[5];
u8 D_004D18A0;
int main(void) {
 _Alignas(16) u8 p[0x300];
 int flags[]={0,1,2,255}, phases[]={0,254,255};
 for(int f=0;f<4;f++)for(int k=0;k<3;k++)for(int skip=0;skip<2;skip++) {
  memset(p,0,sizeof p); memset(D_004F54D0,0,sizeof D_004F54D0);
  D_004D18A0=flags[f];p[6]=phases[k];p[0x13C]=7;p[0x2C6]=8;
  *(s16*)(p+0x13E)=0;
  for(int i=0;i<5;i++)for(int j=0;j<16;j++) D_004F54D0[i].attributes[j]=0xA000+i*16+j;
  if(skip)D_004F54D0[1].attributes[1]=0xC011;
  func_0021ED90(p);
  if(p[6]!=(u8)(phases[k]+(flags[f]>=2)) || p[0x13C]!=(flags[f]>=2) || p[0x2C6]!=(skip?8:1)) return 1;
  for(int i=0;i<5;i++)for(int j=0;j<16;j++) {
   u16 expected=0xA000+i*16+j;
   if(skip && i==1 && j==1)expected=0xC011;
   if(!skip && (i==1||i==2) && j)expected=0xC000+i*16+j;
   if(D_004F54D0[i].attributes[j]!=expected)return 2;
  }
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self, code)

    def test_palette_and_phase(self):
        self.assertEqual(self.run_case(), 0)

    def test_wrong_phase_threshold_is_rejected(self):
        self.assertNotEqual(self.run_case('threshold'), 0)

    def test_palette_mask_error_is_rejected(self):
        self.assertNotEqual(self.run_case('palette'), 0)
