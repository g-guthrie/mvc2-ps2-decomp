/* Initialize two owner-visible animation entries using the complete 196-byte inherited state assignment. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

#include "actor_inherited_state.h"
typedef ActorState InheritedState;


extern int func_001754A0(u8 *,int,int);
void func_001BA6B0(u8 *p,u8 *q)
{
    ++p[4];p[0x13C]=1;
    *(InheritedState*)(p+0xEC)=*(InheritedState*)(q+0xEC);
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
    p[0x24]=0;
    *(V3*)(p+0x34)=*(V3*)(q+0x34);
    func_001754A0(p,27,2);
}

void func_001BABC0(u8 *p,u8 *q)
{
    ++p[4];p[0x13C]=1;
    *(InheritedState*)(p+0xEC)=*(InheritedState*)(q+0xEC);
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
    p[0x24]=0;
    *(V3*)(p+0x34)=*(V3*)(q+0x34);
    func_001754A0(p,27,3);
}
