/* MW 3.0 -O4,p -sdatathreshold 8 */
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

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_nq86b;
extern G_nq86b *D_004C2794;

void residual_003B1210(u8 *p, u8 *q) {
 extern void func_001757E0(u8 *, s32, s32);
 extern void func_001E3210(u8 *, s32);
 extern void func_003B1360(u8 *, u8 *);
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
 p[0x13C]=1;
 *(s8 *)(p+0x31)=-2;
 p[0x1B5]=*(s8 *)(p+0x1B7)+0x35;
 p[0x1B2]=*(u16 *)(p+0x1C0)=0;
 *(s32 *)(p+0x1D8)=0;
 { u8 *h = (u8 *)D_004C2794; h = (u8 *)((u32)(p[2] << 1) + (u32)h); *(s16 *)(h + 0x7C) += 1; }
 p[0x1B1]=p[0x1B0]=0x42;
 func_001757E0(p,0x17,5);
 *(s16 *)(p+0x1C)=1;
 func_001E3210(p,0x23);
 func_003B1360(p,q);
}
