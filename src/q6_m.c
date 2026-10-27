typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
#include "actor_inherited_state.h"
typedef ActorState S49;

static void func_00396EC0(u8 *p, u8 *q, u8 *r) {
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    *(f32 *)(p + 52) += *(f32 *)(r + 8);
    *(f32 *)(p + 56) += *(f32 *)(r + 12);
}

void func_00397030(u8 *p, u8 *q, u8 *r) {
    extern void func_00396D10(u8 *, u8 *);
    u32 t = p[4];
    p[4] = t + 1;
    *(S49 *)(p + 0xEC) = *(S49 *)(q + 0xEC);
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
    p[0x13C] = 0;
    func_00396EC0(p, q, r);
    *(s8 *)(p + 0x31) = -0x10;
    r[7] = 0;
    r[0] = 0;
    *(s16 *)(p + 0x1C) = 2;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    r[2] = 0;
    r[3] = 2;
    func_00396D10(p, r);
    *(u32 *)(p + 0x50) = 0x3F866666;
}

extern void (*D_004C1E40[2])(u8 *, u8 *, u8 *) __attribute__((section(".sdata")));

/* Provisional: callback table type and selector bounds require reconciliation. */
void func_00397140(u8 *p, u8 *q, u8 *r) {
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_00396EC0(p, q, r);
    D_004C1E40[p[5]](p, q, r);
}
