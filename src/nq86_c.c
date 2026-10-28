#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
#include "actor_inherited_state.h"

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_nq86c;
extern G_nq86c *D_004C2794;

void func_003925E0(u8 *p, u8 *q) {
 extern void func_001757E0(u8 *, s32, u8);
 f32 v;
 u8 k;
 u8 *pp;
 p[4]++;
 *(ActorState *)(p+0xEC)=*(ActorState *)(q+0xEC);
 p[0x13C]=1;
 p[2]=q[2];p[1]=q[1];
 *(f32 *)(p+0x50)=*(f32 *)(q+0x50);
 *(f32 *)(p+0x54)=*(f32 *)(q+0x54);
 p[0x1B7]=q[0x1B7];p[0x1B8]=q[0x1B8];
 *(s8 *)(p+0x30)=*(s8 *)(q+0x30);
 *(V3 *)(p+0x50)=*(V3 *)(q+0x50);
 *(s8 *)(p+0x24)=*(s8 *)(q+0x24);
 p[0x13C]=0;
 p[0x24]=8;
 p[0x1B1]=p[0x1B0]=0x42;
 *(s16 *)(p+0x1C)=0x80;
 v = 40.0f;
 pp = p + 2;
 if (*(s16 *)(p+0x140) == 0) v = -v;
 *(f32 *)(p+0x5C)=v;
 *(s32 *)(p+0x68)=0;
 p[0x1B5]=0x53;
 p[0x1B2]=*(u16 *)(p+0x1C0)=0;
 *(s32 *)(p+0x1D8)=0;
 D_004C2794->f7c[*pp] += 1;
 p[0x14E]=0xFF;
 p[0x14F]=0x20;
 k = 0x14;
 if (p[0x20] > 5) k = 0x29;
 k += p[0x21];
 func_001757E0(p,0x17,k);
}
