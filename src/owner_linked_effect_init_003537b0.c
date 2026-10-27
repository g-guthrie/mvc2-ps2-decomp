#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef unsigned int u32;

#include "actor_inherited_state.h"
typedef ActorState Fields;
typedef struct {float x,y,z;} V3;
extern void *func_003DA750(void *,int,int);
extern void func_003539A0(u8 *);
void func_003537B0(u8 *p)
{
 u8 *work=p+0x88;u8 *one,*two,*three,*owner;
 p[4]++;
 if(p[0x20]==0){
  work[2]=0;work[1]=0;*(u16 *)(work+8)=0;work[0xe]=0;work[3]=2;work[0x11]=1;work[0x10]=1;
  one=func_003DA750(0,1,1);
  if(one){*(void (**)(u8 *))(one+0x10)=*(void (**)(u8 *))(p+0x10);*(u8 **)(one+0x18)=*(u8 **)(p+0x18);*(u8 **)(one+0x14)=p;one[0x20]=1;one[0x21]=2;}
  if((two=func_003DA750(p,1,2))!=0){
   *(void (**)(u8 *))(two+0x10)=*(void (**)(u8 *))(p+0x10);*(u8 **)(two+0x18)=*(u8 **)(p+0x18);two[0x20]=1;two[0x21]=1;two[0x8a]=255;two[0x89]=255;*(u8 **)(two+0x8c)=p;
   three=func_003DA750(0,1,1);
   if(three){*(void (**)(u8 *))(three+0x10)=*(void (**)(u8 *))(p+0x10);*(u8 **)(three+0x18)=*(u8 **)(p+0x18);*(u8 **)(three+0x14)=two;three[0x20]=1;three[0x21]=2;}
  }
 }
 owner=*(u8 **)(p+0x18);
 *(Fields *)(p+0xec)=*(Fields *)(owner+0xec);p[0x13c]=1;
 p[2]=owner[2];p[1]=owner[1];*(float *)(p+0x50)=*(float *)(owner+0x50);*(float *)(p+0x54)=*(float *)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];p[0x30]=*(s8 *)(owner+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(owner+0x50);p[0x24]=*(s8 *)(owner+0x24);
 *(s8 *)(p+0x31)=-8;p[0x22]=*(s16 *)(owner+0x140)?4:12;p[0x1b0]=66;p[0x1b1]=66;
 *(u16 *)(work+0xa)=0;*(u16 *)(work+0xc)=0;
 func_003539A0(p);
}
