"""Check cached owners, bounded timer cycles and unsigned partner acceleration."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class JitterPartnerStateTests(unittest.TestCase):
    def jitter_case(self,mutation=None):
        body=(ROOT/'src/actor_timed_jitter_001cc440.c').read_text().replace('__attribute__((section(".sdata")))','').replace('p+0x18','p+0x580')
        if mutation=='owner':body=body.replace('if(owner[0x425]','if((*(u8**)(p+0x580))[0x425]')
        if mutation=='sentinel':body=body.replace('*(short*)(p+0x1E)=0','*(short*)(p+0x1E)=1')
        code='#include <string.h>\n'+body+r'''
#define S(p,n) (*(short*)((p)+(n)))
short D_0044DC90[6]={16,19,13,23,30,-1};static u8 global[32];u8 *D_004C270C=global;
static u8 *actor,*alternate;static int wrong,frame,rng,move,spawn,seed,oldTimer,oldIndex,wantMove;
int func_00175670(u8*p){frame++;if(p!=actor||rng||move||spawn)wrong++;*(u8**)(p+0x580)=alternate;return -1;}
int func_00174170(void){int value=rng++?127-seed:seed;if(frame!=1||spawn)wrong++;return value|0x7F000000;}
void func_001548D0(u8*p,V3*v,int n){move++;float x=(seed-63)*1.6666666269302368f,y=((127-seed)-63)*2.142857074737549f;if(p!=actor||n||rng!=2||frame!=1||S(p,0x1C)!=oldTimer||p[0x22]!=4||v->x!=x||v->y!=y||v->z!=0)wrong++;}
void func_001CBE10(u8*p,int n,int index){spawn++;if(p!=actor||n!=3||index!=oldIndex||S(p,0x1C)!=0||move!=wantMove)wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600],r[0x600],expected[0x600];int times[]={0,1,2,-32768},counts[]={0,1,2,255},modes[]={-128,1,2,127},seeds[]={0,63,127};
 for(int t=0;t<4;t++)for(int c=0;c<4;c++)for(int index=0;index<5;index++)for(int flag=0;flag<2;flag++)for(int g=0;g<4;g++)for(int z=0;z<3;z++){
  memset(p,0xA5,sizeof p);memset(q,0,sizeof q);memset(r,0,sizeof r);actor=p;alternate=r;wrong=frame=rng=move=spawn=0;seed=seeds[z];oldTimer=times[t];oldIndex=index;wantMove=counts[c]==1;
  *(u8**)(p+0x580)=q;p[0x22]=counts[c];p[5]=255;S(p,0x1C)=oldTimer;S(p,0x1E)=index;q[0x425]=flag;r[0x425]=!flag;global[9]=(u8)modes[g];
  memcpy(expected,p,sizeof p);*(u8**)(expected+0x580)=r;expected[0x22]=wantMove?4:(u8)(counts[c]-1);S(expected,0x1C)=(short)(oldTimer-1);
  if(oldTimer==1){int next=index+1;if(D_0044DC90[next]<0)next=0;S(expected,0x1E)=next;S(expected,0x1C)=D_0044DC90[next];}
  if(flag||modes[g]>=2)expected[5]=0;
  func_001CC440(p);
  if(wrong||frame!=1||rng!=wantMove*2||move!=wantMove||spawn!=(oldTimer==1)||memcmp(p,expected,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def partner_case(self,mutation=None):
        body=(ROOT/'src/owner_partner_release_001d7e70.c').read_text().replace('__attribute__((section(".sdata")))','')
        if mutation=='signed':body=body.replace('(float)(((u32)func_00174170()&63)-32u)','(float)((int)((u32)func_00174170()&63)-32)')
        if mutation=='identity':body=body.replace('!=*(u16*)(owner+0x168)','==*(u16*)(owner+0x168)')
        root=states.function('src/composite_dispatch_heads.c','func_001D7E50')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef int s32;typedef float f32;
typedef void (*Mvc2OwnerStateCallback)(u8*,void*);
void func_001D7E70(u8*,void*);void func_001D8000(u8*,void*);
const Mvc2OwnerStateCallback jtbl_0044E6A0[3]={func_001D7E70,func_001D8000,0};
'''+root+body+states.function('src/w173_f.c','func_001D8000')+r'''
#define S(p,n) (*(short*)((p)+(n)))
#define F(p,n) (*(float*)((p)+(n)))
#define I(p,n) (*(int*)((p)+(n)))
static u8 global[64];u8 *D_004C2840=global;
static u8 *actor,*owner,atCall[0x600];static int wrong,rng,anim,frame,releases;static unsigned int values[3];
int func_00174170(void){if(anim||frame||rng>=3)wrong++;return (int)values[rng++%3];}
int func_001754A0(u8*p,int a,int b){anim++;if(p!=actor||a!=27||b!=9||rng!=3||memcmp(p,atCall,sizeof atCall))wrong++;return 0;}
int func_00175670(u8*p){frame++;if(p!=actor||anim!=1||rng!=3||memcmp(p,atCall,sizeof atCall))wrong++;return 0;}
void func_001D8570(u8*p,void*q){releases++;if(p!=actor||q!=owner||anim||rng||frame)wrong++;}
int main(void){
 _Alignas(16) u8 p[0x600],q[0x600],r[0x600],expected[0x600];unsigned int randoms[]={0,31,32,63,0xFFFFFFFFu};int widths[]={1,2,32,255},faces[]={0,1,-32768},vertical[]={1,2,3};
 for(int gate=0;gate<6;gate++)for(int z=0;z<5;z++)for(int w=0;w<4;w++)for(int f=0;f<3;f++)for(int k=0;k<3;k++){
  memset(p,0xA5,sizeof p);memset(q,0,sizeof q);memset(r,0,sizeof r);actor=p;owner=q;wrong=rng=anim=frame=releases=0;
  p[5]=0;I(p,0xD0)=0x1234;*(u16*)(q+0x168)=gate==0?0x1235:0x1234;
  *(u8**)(q+0x1C4)=r;q[0x1B2]=gate==1?0:1;r[5]=gate==2?2:3;*(u8**)(r+0x1C8)=gate==3?p:q;r[0x1B6]=gate==4?6:5;I(p,0xD4)=5;
  r[0x24]=0xFE;r[0x14C]=widths[w];S(r,0x140)=faces[f];r[0x20D]=vertical[k];r[0x247]=9;r[0x23E]=0;
  F(r,0x34)=10;F(r,0x38)=-20;values[0]=randoms[z];values[1]=randoms[z];values[2]=0xFFFFFFFEu;*(u32*)(global+0x1C)=7;
  memcpy(expected,p,sizeof p);memcpy(atCall,p,sizeof p);
  if(gate==5){
   atCall[5]=1;atCall[0x13C]=1;atCall[0x24]=r[0x24];S(atCall,0x1C)=(values[0]&63)+120;
   u32 wrapped=(values[1]&63)-32u;F(atCall,0x68)=(float)wrapped*1.6666666269302368f;F(atCall,0x6C)=(float)(values[2]%widths[w])*2.142857074737549f;*(u8**)(atCall+0xD8)=r;
   memcpy(expected,atCall,sizeof p);float dx=F(atCall,0x68);if(faces[f])dx=-dx;F(expected,0x34)=10+dx;
   float dy=F(atCall,0x6C);if(vertical[k]==1)dy/=2;if(vertical[k]==3)dy/=4;F(expected,0x38)=-20+dy;S(expected,0x1C)--;
  }
  func_001D7E50(p,q);
  if(wrong||rng!=(gate==5?3:0)||anim!=(gate==5)||frame!=(gate==5)||releases!=(gate==0)||memcmp(p,expected,sizeof p))return 1;
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_jitter_timers_and_cached_owner(self):self.assertEqual(self.jitter_case(),0)
    def test_reloaded_owner_rejected(self):self.assertNotEqual(self.jitter_case('owner'),0)
    def test_wrong_timer_reset_rejected(self):self.assertNotEqual(self.jitter_case('sentinel'),0)
    def test_partner_gates_and_unsigned_acceleration(self):self.assertEqual(self.partner_case(),0)
    def test_signed_acceleration_rejected(self):self.assertNotEqual(self.partner_case('signed'),0)
    def test_wrong_owner_identity_rejected(self):self.assertNotEqual(self.partner_case('identity'),0)
