#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"

extern int func_001757E0(u8 *,int,int);
extern void *func_003DA750(void *,s32,s32);
extern void func_001D4650(u8 *);
void func_001D4C10(u8 *p,void *owner) {
 u8 *work;
 s32 i;
 u8 *q=owner;
 work=q+0x2B8;
 *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[4]++;p[0x24]=7;
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 p[0x31]=127;
 for(i=1;i<17;i++) {
  u8 *r=func_003DA750(p,3,2);
  if(r) {
   *(s16 *)(r+0x26)=0x2D00;
   r[0x20]=4;r[0x21]=i;
   *(V3 *)(r+0x34)=*(V3 *)(p+0x34);
   *(s8 *)(r+0x31)=i-*(s8 *)(p+0x31);
   *(void (**)(u8 *))(r+0x10)=func_001D4650;
   *(u8 **)(r+0x18)=q;
   *(u8 **)(r+0x14)=p;
  } else {
   p[4]=2;p[0x13C]=0;*(s8 *)(work+7)=-1;
   return;
  }
 }
 func_001757E0(p,23,6);
}

extern const u8 D_0044E3E0[];
extern int func_00175910(u8 *,int,int,int);
void func_001D4EE0(u8 *p,void *owner) {
 u8 *q=owner;
 *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[4]++;p[0x24]=7;
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34);
 func_00175910(p,23,7,D_0044E3E0[p[0x21]]);
}
