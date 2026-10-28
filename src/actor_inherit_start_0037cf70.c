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

extern int func_001757E0(u8 *, int, int);
void func_0037CF70(u8 *p,u8 *q)
{
 f32 offset;
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
 p[0x13c]=1;
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 if (*(s16 *)(q+0x140)) offset=117.0f;
 else offset=-117.0f;
 *(f32 *)(p+0x34)+=offset;
 *(f32 *)(p+0x38)+=129.0f;
 p[0x24]=0; *(s16 *)(p+0x1c)=14;
 func_001757E0(p,0x17,11);
 { f32 speed; if (*(s16 *)(p+0x140)) speed=10.0f; else speed=-10.0f; *(f32 *)(p+0x5c)=speed; }
 *(f32 *)(p+0x50)=1.0f; *(f32 *)(p+0x54)=1.0f;
}
