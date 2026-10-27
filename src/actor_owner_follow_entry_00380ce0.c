#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef signed int s32;typedef unsigned int u32;typedef float f32;typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"
extern u8 *D_004C2794 __attribute__((section(".sdata")));extern int func_001757E0(u8 *,int,int);extern void func_00380E10(u8 *);
void func_00380CE0(u8 *p) {u8 *q=*(u8 **)(p+0x18);p[4]++;*(s16 *)(p+0x26)=0x1901;*(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
 p[0x13c]=1;p[2]=q[2];p[1]=q[1];*(f32 *)(p+0x50)=*(f32 *)(q+0x50);*(f32 *)(p+0x54)=*(f32 *)(q+0x54);p[0x1b7]=q[0x1b7];p[0x1b8]=q[0x1b8];*(s8 *)(p+0x30)=*(s8 *)(q+0x30);*(V3 *)(p+0x50)=*(V3 *)(q+0x50);*(s8 *)(p+0x24)=*(s8 *)(q+0x24);p[0x24]=9;p[0x1b0]=66;p[0x1b1]=66;p[0x1b5]=*(s8 *)(p+0x20)+55;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;{u32 a=(u32)D_004C2794;a=(p[2]<<1)+a;++*(s16 *)(a+0x7c);}func_001757E0(p,23,0);func_00380E10(p);}
