/* Provisional: callback table ABI, dispatcher bounds and owner lifetime need proof. */
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

extern void func_003C6EB0(u8 *, u8 *);
void func_003C6D80(u8 *p,u8 *q)
{
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
 p[0x13c]=0;
 *(f32 *)(p+0x38)=*(f32 *)(q+0x430);
 { f32 off=-186.666656494140625f, vel=-73.3333282470703125f;
 if (*(s16 *)(q+0x140)==0) { *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+off; *(f32 *)(p+0x5c)=vel; }
 else { *(f32 *)(p+0x34)=*(f32 *)(q+0x34)-off; *(f32 *)(p+0x5c)=-vel; } }
 *(s16 *)(p+0x1c)=0; *(s16 *)(p+0x1e)=2;
 p[0x14d]=0;p[0x14c]=0;p[0x14f]=48;p[0x14e]=48;
 func_003C6EB0(p,q);
}
