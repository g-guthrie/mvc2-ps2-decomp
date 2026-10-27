typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


#include "actor_inherited_state.h"
typedef ActorState S31h;

typedef struct { f32 x, y, z; } V3h;

#define Q(p) (*(u8 **)((p) + 0x18))
void func_0039C9C0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    t = p[4];
    p[4] = t + 1;
    *(S31h *)(p + 0xEC) = *(S31h *)(Q(p) + 0xEC);
    p[0x13C] = 1;
    p[2] = Q(p)[2];
    p[1] = Q(p)[1];
    *(f32 *)(p + 0x50) = *(f32 *)(Q(p) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(Q(p) + 0x54);
    p[0x1B7] = Q(p)[0x1B7];
    p[0x1B8] = Q(p)[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(Q(p) + 0x30);
    *(V3h *)(p + 0x50) = *(V3h *)(Q(p) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(Q(p) + 0x24);
    p[0x13C] = 1;
    *(f32 *)(p + 0x38) = *(f32 *)(Q(p) + 0x38);
    *(f32 *)(p + 0x38) += 17.14285659790039f;
    func_001757E0(p, 0x17, 0x16);
}
