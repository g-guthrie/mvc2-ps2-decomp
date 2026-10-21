#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"

extern void func_0015E630(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_003C7880(u8 *p,void *context)
{
 u8 *q=context;
 p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(q+0xec);
    p[0x13C] = 1;
        p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
 ((s8 *)p)[0x31]=8;
 *(u8 **)(p+0x14)=*(u8 **)(q+0x1dc);
 p[0x14c]=128;p[0x14d]=0;p[0x14e]=96;p[0x14f]=64;
 *(f32 *)(p+0x38)=1028.5714111328125f;
 {f32 xOffset=160.0f;
 f32 speed=-3.3333332538604736f;
 if(*(s16 *)(p+0x140)) {xOffset=-xOffset;speed=-speed;}
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+xOffset;
 *(f32 *)(p+0x5c)=speed;
 }
 *(f32 *)(p+0x60)=-60.0f;
 *(f32 *)(p+0x6c)=0.0f;
 func_0015E630(p);
 p[0]=1;
 func_001757E0(p,20,15);
}
