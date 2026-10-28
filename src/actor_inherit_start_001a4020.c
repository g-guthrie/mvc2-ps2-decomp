/* Provisional: speed-table index, dispatcher bounds and owner lifetime need proof. */
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

extern int func_001757E0(u8 *,int,int);
extern f32 data_u32_004BF698[2] __attribute__((section(".sdata")));
void func_001A4020(u8 *p, void *parent)
{
 u8 *q = parent;
 f32 speed;
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
 p[0x24]=12;
 *(V3 *)(p+0x34)=*(V3 *)(q+0x34);
 *(u32 *)(p+0x5c)=0; *(u32 *)(p+0x60)=0; *(u32 *)(p+0x68)=0; *(u32 *)(p+0x6c)=0;
 if (p[0x20]==0) {
  speed=data_u32_004BF698[q[0x1b7]];
  if (*(s16 *)(p+0x140)) speed=-speed;
  *(f32 *)(p+0x5c)=speed; *(f32 *)(p+0x68)=speed; *(s16 *)(p+0x1c)=8;
 } else p[5]=3;
 func_001757E0(p,0x17,0x13);
}
