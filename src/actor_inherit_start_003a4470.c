/* Provisional: dispatcher bounds and owner lifetime need proof. */
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
extern int func_00174170(void);
extern int func_001757E0(u8 *, int, int);
void func_003A4470(u8 *p, void *parent)
{
 u8 *q = parent;
 f32 offset;
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
 p[4]++;
 p[0x1b0]=0x44; p[0x1b1]=0x44;
 p[0x20]=func_00174170()&3;
 p[0x21]=0;
 offset = -80.0f;
 if (*(s16 *)(p+0x140)) offset=-offset;
 *(f32 *)(p+0x34)=*(f32 *)(q+0x34)+offset;
 *(f32 *)(p+0x38)=*(f32 *)(q+0x430);
 func_001757E0(p,0x17,0x1a);
}
