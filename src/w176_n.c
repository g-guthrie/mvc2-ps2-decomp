typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


#include "actor_inherited_state.h"
typedef ActorState S196;

typedef struct { f32 x, y, z; } V3;

void func_001A4E80(u8 *p, u8 *q) {
    extern void func_00185960(u8 *, u8 *);
    s32 i;
    s32 n;
    u8 *s0;
    n = *(s16 *)(p + 0x1E);
    for (i = 0; i < n; i++) {
        {
            s0 = p;
            *(S196 *)(p + 0xEC) = *(S196 *)(q + 0xEC);
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
            p[0x13C] = (p[0x21] != 0) ? 1 : 0;
            *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
            p[0x31] = 8;
            *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
            p = *(u8 **)(p + 0xC);
        }
    }
    func_00185960(q, s0);
    s0[0x13C] = 1;
    *(s8 *)(s0 + 0x16A) = -1;
}
