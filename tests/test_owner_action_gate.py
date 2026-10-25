"""Check real owner-ID gating and all four/two GP phase routes."""
import re
import unittest
from pathlib import Path
import test_owned_actor_states as owned_states
from test_owned_actor_states import function

ROOT=Path(__file__).resolve().parents[1]

class OwnerActionGateTests(unittest.TestCase):
    def run_gate(self,wrong_owner=False):
        gate=(ROOT/'src/actor_owner_gate_00197490.c').read_text()
        if wrong_owner:
            changed=gate.replace('func_00197470(p,owner)','func_00197470(p,p)').replace('func_00196E30(p,owner)','func_00196E30(p,p)')
            self.assertNotEqual(changed,gate);gate=changed
        gp=(ROOT/'src/composite_gp_dispatch_heads.c').read_text()
        decls=[]
        for name in ['jtbl_004BF598','jtbl_004BF5A8']:
            line=next(line for line in gp.splitlines() if line.startswith('extern const ControllerEffectCallback '+name+'['))
            decls.append(re.sub(r' __attribute__\(\(section\("\.sdata"\)\)\)','',line))
        leading=(ROOT/'src/wave17b.c').read_text()
        lead_decl=next(line for line in leading.splitlines() if line.startswith('extern void (*D_004BF538'))
        code=r'''
#include <string.h>
#include "owner_effect_callbacks.h"
'''+(ROOT/'src/actor_owner_acceleration_001971B0.c').read_text()+'\n'+gate+'\n'+'\n'.join(decls)+'\n'+lead_decl+'\n'
        code+=function('src/wave9.c','func_00197860')
        code+=function('src/composite_gp_dispatch_heads.c','func_00196E30')
        code+=function('src/composite_gp_dispatch_heads.c','func_00197470')
        code+=function('src/wave17b.c','func_00193B20')
        code+=r'''
static int tag,frameCalls,finishCalls;
static u8 *seenActor,*seenOwner;
#define PHASE(name,id) static void name(u8 *p,u8 *q) {tag=id;seenActor=p;seenOwner=q;}
PHASE(primary0,0)
PHASE(primary1,1)
PHASE(primary2,2)
PHASE(alternate0,4)
PHASE(alternate1,5)
PHASE(leading0,10)
PHASE(leading1,11)
const ControllerEffectCallback jtbl_004BF598[4]={primary0,primary1,primary2,func_001971B0};
const ControllerEffectCallback jtbl_004BF5A8[2]={alternate0,alternate1};
void (*D_004BF538[2])(u8*,u8*)={leading0,leading1};
int func_00175670(u8 *p) {frameCalls++;seenActor=p;return 0;}
void func_001975C0(u8 *p,u8 *q) {tag=3;finishCalls++;seenActor=p;seenOwner=q;}
#define F(p,n) (*(float*)((p)+(n)))
int main(void) {
 _Alignas(16) u8 actor[0x600],owner[0x600];
 const int styles[3]={0,1,255},ids[4]={0,1,-1,-128};
 int style,slot,kind,ownId,localId,i,ownerPhase;
 for(style=0;style<3;style++)for(slot=0;slot<(style?2:4);slot++)
 for(kind=28;kind<=29;kind++)for(ownId=0;ownId<4;ownId++)for(localId=0;localId<4;localId++) {
  int stopped=kind==29 && ids[ownId]!=0 && ids[ownId]!=ids[localId];
  int expected=style?4+slot:slot;
  memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
  actor[0x21]=styles[style];actor[5]=slot;owner[0x1e4]=kind;
  *(s8*)(owner+0x2c4)=ids[ownId];*(s8*)(actor+0x88)=ids[localId];
  owner[0x2c5]=0x6C;actor[0x89]=0x6B;
  F(actor,0x34)=1;F(actor,0x38)=2;F(actor,0xa0)=2;F(actor,0xa4)=3;
  F(owner,0x34)=10;F(owner,0x38)=20;
  tag=-1;frameCalls=finishCalls=0;seenActor=seenOwner=0;
  func_00197490(actor,owner);
  if(owner[0x2c5]!=0x6C || actor[0x89]!=0x6B)return 1;
  if(stopped) {
   if(owner[0x2c4] || actor[0x88] || tag!=-1 || frameCalls || finishCalls)return 2;
  } else {
   if(*(s8*)(owner+0x2c4)!=ids[ownId] || *(s8*)(actor+0x88)!=ids[localId])return 3;
   if(tag!=expected || seenActor!=actor || seenOwner!=owner)return 4;
   if(expected==3) {
    if(frameCalls!=1 || finishCalls!=1 || F(actor,0x98)!=12 || F(actor,0x9c)!=23)return 5;
    if(F(actor,0x34)!=1 || F(actor,0x38)!=2)return 6;
   } else if(frameCalls || finishCalls)return 7;
  }
 }
 for(slot=0;slot<2;slot++)for(ownerPhase=0;ownerPhase<2;ownerPhase++)for(kind=28;kind<=29;kind++) {
  memset(actor,0,sizeof(actor));memset(owner,0,sizeof(owner));
  actor[4]=255;actor[5]=slot;actor[0x13c]=9;owner[5]=ownerPhase;owner[0x1e4]=kind;
  tag=-1;seenActor=seenOwner=0;
  func_00193B20(actor,owner);
  if(ownerPhase || kind!=29) {
   if(actor[4] || actor[0x13c] || tag!=-1)return 8;
  } else if(actor[4]!=255 || actor[0x13c]!=9 || tag!=10+slot || seenActor!=actor || seenOwner!=owner)return 9;
 }
 return 0;
}
'''
        return owned_states.OwnedActorStateTests.compile_run(self,code)

    def test_identifiers_real_acceleration_and_every_route(self):
        self.assertEqual(self.run_gate(),0)

    def test_wrong_routed_owner_is_detected(self):
        self.assertNotEqual(self.run_gate(wrong_owner=True),0)
