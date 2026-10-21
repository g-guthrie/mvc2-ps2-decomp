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

extern u8 D_00473B50[][4];
extern u8 D_00473B60[];
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
void func_003AE020(u8 *p)
{
 u8 *owner,*q;
 p[4]++;
 owner=*(u8 **)(p+0x18);
 q=*(u8 **)(p+0x14);
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
 *(V3 *)(p+0x34)=*(V3 *)(owner+0x34);
 ((s8 *)p)[0x31]=5;
 p[0x168]=D_00473B50[p[0x21]][D_00473B60[*(s16 *)(p+0x1c)]];
 func_001757E0(p,23,p[0x168]);
 if(*(u32 *)(D_004C2840+0x1c)&1)p[0x13c]=1;
}
