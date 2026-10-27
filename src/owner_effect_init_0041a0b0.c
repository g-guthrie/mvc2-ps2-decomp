#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;

#include "actor_inherited_state.h"
typedef ActorState Fields;

typedef struct {float x,y,z;} V3;
typedef struct {s16 x[4],y[4];} Samples;
extern void func_0041A170(u8 *);
void func_0041A0B0(u8 *p)
{
 u8 *owner=*(u8 **)(p+0x18);
 ++p[4]; *(s16 *)(p+0x26)=0x1c06;
 *(Fields *)(p+0xec)=*(Fields *)(owner+0xec);p[0x13c]=1;
 p[2]=owner[2];p[1]=owner[1];
 *(float *)(p+0x50)=*(float *)(owner+0x50);*(float *)(p+0x54)=*(float *)(owner+0x54);
 p[0x1b7]=owner[0x1b7];p[0x1b8]=owner[0x1b8];p[0x30]=*(s8 *)(owner+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(owner+0x50);p[0x24]=*(s8 *)(owner+0x24);
 p[0x24]=8;p[0x13c]=1;func_0041A170(p);
}
