"""Validate producer bounds, paired records and native callback ordering."""
import unittest
from pathlib import Path
import test_owned_actor_states as states
ROOT=Path(__file__).resolve().parents[1]

class PairedArcStartTests(unittest.TestCase):
    def run_case(self,mutation=None):
        body=(ROOT/'src/paired_arc_start_001e1c60.c').read_text()
        if mutation=='angle':body=body.replace('angles.angle[p[0x21]>>1]','angles.angle[p[0x21]%5]')
        if mutation=='owner':body=body.replace('if(*(s16*)(owner+0x140))dx=-dx','if(*(s16*)(p+0x140))dx=-dx')
        if mutation=='order':body=body.replace('func_001754A0(p,27,frames.frame[p[0x21]]);p[0]=1;p[0x159]=0;','p[0]=1;p[0x159]=0;func_001754A0(p,27,frames.frame[p[0x21]]);')
        source=(ROOT/'src/indexed_owner_child_spawns.c').read_text()
        start=source.index('void func_001E1620('); end=source.index('\n#pragma padloop off',start)
        producer=source[start:end].replace('p+0x10','p+0x500').replace('p+0x18','p+0x508')
        primary=states.function('src/grok_r2_001c.c','func_001E16A0').replace('p + 24','p + 0x508')
        dispatch=states.function('src/composite_dispatch_heads.c','func_001E1C40')
        code=r'''
#include <string.h>
typedef unsigned char u8;typedef int s32;
void func_001E1C60(u8*,u8*),func_001E16A0(u8*),func_001E1C40(u8*,u8*);
void func_001E16E0(u8*p,u8*q){(void)p;(void)q;}
u8 *func_003DA750(int,int,int);
void (*const jtbl_0044F040[4])(u8*,u8*)={func_001E1C60,0,0,0};
'''+dispatch+primary+producer+body+r'''
#define F(p,n) (*(float*)((p)+(n)))
#define S(p,n) (*(short*)((p)+(n)))
PairTable D_0044F050={{{64,0},{-64,0},{56,48},{-56,48},{48,80},{-48,80},{32,96},{-32,96},{16,112},{-16,112}}};
PairTable D_0044F090={{{2048,0},{-2048,0},{1792,256},{-1792,256},{1536,768},{-1536,768},{896,1280},{-896,1280},{256,1536},{-256,1536}}};
Frames D_0044F078={{15,15,18,18,18,18,17,17,17,17}};
Angles D_0044F0B8={{0,1024,-1024,0,-4096}};
static _Alignas(16) u8 pool[10][0x600];static u8 *actor,*owner,atFrame[0x600],atFinish[0x600];
static int calls,frames,finishes,wrong,mask,row;
u8 *func_003DA750(int key,int group,int mode){int n=calls++;if(key||group!=4||mode||n>=10){wrong++;return 0;}if(mask&(1<<n))return 0;memset(pool[n],0,0x600);return pool[n];}
int func_001754A0(u8*p,int a,int b){frames++;if(p!=actor||a!=27||b!=D_0044F078.frame[row]||memcmp(p,atFrame,sizeof atFrame))wrong++;p[0]=0x7F;p[0x159]=0x7F;return 0;}
void func_0015E630(u8*p){finishes++;if(p!=actor||frames!=1||memcmp(p,atFinish,sizeof atFinish))wrong++;}
int main(void){
 _Alignas(16) u8 q[0x600],savedOwner[0x600];int faces[]={0,1,-32768,32767},masks[]={0,0x155,0x3FF},timers[]={-32768,0,32767};
 for(int f=0;f<4;f++)for(int m=0;m<3;m++)for(int t=0;t<3;t++){
  memset(q,0x12,sizeof q);owner=q;calls=wrong=0;mask=masks[m];q[1]=3;q[2]=1;q[0x24]=0xFE;S(q,0x140)=faces[f];S(q,0x13E)=timers[t];
  F(q,0x34)=10;F(q,0x430)=200;F(q,0x50)=2;F(q,0x54)=3;F(q,0x58)=4;memcpy(savedOwner,q,sizeof q);
  func_001E1620(q);if(wrong||calls!=10||memcmp(q,savedOwner,sizeof q))return 1;
  for(row=0;row<10;row++){
   if(mask&(1<<row))continue;u8*p=pool[row];actor=p;frames=finishes=0;
   if(p[0x21]!=row||p[0x20]!=1||p[1]!=3||S(p,0x26)!=14851||*(u8**)(p+0x508)!=q||*(void (**)(u8*))(p+0x500)!=func_001E16A0)return 1;
   memcpy(atFrame,p,sizeof atFrame);atFrame[4]++;memcpy(atFrame+0xEC,q+0xEC,196);atFrame[0x13C]=1;atFrame[2]=q[2];atFrame[1]=q[1];memcpy(atFrame+0x50,q+0x50,12);
   atFrame[0x1B7]=q[0x1B7];atFrame[0x1B8]=q[0x1B8];atFrame[0x30]=q[0x30];atFrame[0x24]=15;S(atFrame,0x13E)=(short)(timers[t]+6);if(!(row&1))S(atFrame,0x140)^=1;
   float dx=D_0044F050.row[row].x;if(faces[f])dx=-dx;F(atFrame,0x34)=10+dx;F(atFrame,0x38)=200+D_0044F050.row[row].y;
   float vx=(1.6666666269302368f*D_0044F090.row[row].x)/256.0f;if(faces[f])vx=-vx;F(atFrame,0x5C)=vx;
   F(atFrame,0x60)=(2.142857074737549f*D_0044F090.row[row].y)/256.0f;F(atFrame,0x68)=F(atFrame,0x6C)=0;*(u32*)(atFrame+0x40)=*(u32*)(atFrame+0x44)=0;*(s32*)(atFrame+0x48)=D_0044F0B8.angle[row>>1];
   atFrame[0x14D]=atFrame[0x14C]=64;atFrame[0x14F]=atFrame[0x14E]=32;memcpy(atFinish,atFrame,sizeof atFinish);atFinish[0]=1;atFinish[0x159]=0;
   (*(void (**)(u8*))(p+0x500))(p);
   if(wrong||frames!=1||finishes!=1||memcmp(p,atFinish,sizeof atFinish)||memcmp(q,savedOwner,sizeof q))return 1;
  }
 }
 return 0;
}
'''
        return states.OwnedActorStateTests.compile_run(self,code)

    def test_ten_rows_and_producer_failures(self):self.assertEqual(self.run_case(),0)
    def test_wrong_angle_pair_rejected(self):self.assertNotEqual(self.run_case('angle'),0)
    def test_wrong_facing_source_rejected(self):self.assertNotEqual(self.run_case('owner'),0)
    def test_early_lifecycle_flags_rejected(self):self.assertNotEqual(self.run_case('order'),0)
