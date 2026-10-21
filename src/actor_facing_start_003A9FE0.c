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

typedef struct {u8 prefix[0x140];s16 facing;} ActorFacing;
extern void func_003AA0D0(u8 *);
void func_003A9FE0(u8 *p)
{
 ActorFacing *facing=(ActorFacing *)p;
 p[4]++;
  *(ActorState *)(p+0xec)=*(ActorState *)(*(u8 **)(p+0x18)+0xec);
    p[0x13C] = 1;
        p[2] = (*(u8 **)(p+0x18))[2];
    p[1] = (*(u8 **)(p+0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p+0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p+0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p+0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p+0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p+0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p+0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p+0x18) + 0x24);
 p[0x1b0]=69;p[0x1b1]=0;p[0x22]=255;
 facing->facing^=p[0x20];
 ((s8 *)p)[0x31]=-1;
 func_003AA0D0(p);
}
