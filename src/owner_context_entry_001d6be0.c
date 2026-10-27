/* Run the selected owner-context initializer before the standard owner handler. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;


#include "actor_inherited_state.h"
typedef ActorState State;

typedef void (*OwnerCallback)(u8 *,u8 *);
extern OwnerCallback jtbl_004BFA90[2] __attribute__((section(".sdata")));
extern void func_001D6D10(u8 *);
void func_001D6BE0(u8 *p, u8 *owner_unused)
{
    u8 *q;
    ++p[4];p[0x13C]=1;
    q=*(u8**)(p+0x18);
    *(State*)(p+0xEC)=*(State*)(q+0xEC);
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
    *(s8*)(p+0x31)=-1;
    jtbl_004BFA90[p[0x20]](p,q);
    func_001D6D10(p);
}
