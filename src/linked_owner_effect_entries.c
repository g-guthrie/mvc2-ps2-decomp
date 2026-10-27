/* Initialize two linked effects with inherited presentation state and opacity. */
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
extern void func_001BB650(u8 *,u8 *),func_001BB830(u8 *,u8 *);
void func_001BB530(u8 *p,u8 *q)
{
    u8 *linked=*(u8**)(p+0x14);
    p[4]=1;p[0x13C]=1;
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
    *(s8*)(p+0x24)=*(s8*)(linked+0x24);
    p[0x31]=1;
    *(V3*)(p+0x34)=*(V3*)(linked+0x34);
    func_001754A0(p,27,8);
    *(f32*)(p+0x118)=0.7f;
    *(s32*)(q+0x2D8)=2;
    func_001BB650(p,q);
}

void func_001BB710(u8 *p,u8 *q)
{
    u8 *linked=*(u8**)(p+0x14);
    p[4]=1;p[0x13C]=1;
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
    *(s8*)(p+0x24)=*(s8*)(linked+0x24);
    p[0x31]=1;
    *(V3*)(p+0x34)=*(V3*)(linked+0x34);
    func_001754A0(p,27,9);
    *(f32*)(p+0x118)=0.7f;
    *(s32*)(q+0x2D8)=2;
    func_001BB830(p,q);
}
