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

typedef struct { u8 prefix[0x24]; s8 palette; } ActorPalette;
extern u8 D_004761E0[][4];
void func_003C81F0(u8 *p,u8 *q)
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
 {u32 index=p[0x20];
 p[0x14c]=D_004761E0[index][0];
 p[0x14d]=D_004761E0[index][1];
 p[0x14e]=D_004761E0[index][2];
 p[0x14f]=D_004761E0[index][3];
 }
 p[5]=0;
 if(p[0x21]==3)p[5]=1;
 p[6]=0;p[0x13c]=0;
}
