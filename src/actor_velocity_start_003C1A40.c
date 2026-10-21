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

typedef struct {u8 prefix[0x5c];f32 vx;} ActorVelocity;
typedef struct {s16 x,y;} VelocityPair;
extern VelocityPair D_00475CA0[];
extern s8 D_004C20F0[] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
extern void func_003C1BD0(u8 *,u8 *);
void func_003C1A40(u8 *p,void *context)
{
 u8 *q=context;
 ActorVelocity *motion=(ActorVelocity *)p;
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
 ((s8 *)p)[0x31]=-1;
 *(f32 *)(p+0x3c)=*(f32 *)(q+0x3c);
 motion->vx=1.6666666269302368f*D_00475CA0[p[0x21]].x;
 *(f32 *)(p+0x60)=2.142857074737549f*D_00475CA0[p[0x21]].y;
 if(*(s16 *)(p+0x140))motion->vx=-motion->vx;
 func_001757E0(p,22,3);
 *(s16 *)(p+0x1c)=D_004C20F0[p[0x21]];
 func_003C1BD0(p,q);
}
