#include "actor_inherited_state.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[2]; u8 b2; u8 p3; u8 b4; u8 b5; u8 b6; u8 b7; u8 p8[0x1C-8]; s16 h1c; u8 p1e[0x34-0x1E]; f32 f34; f32 f38; u8 p3c[0x5C-0x3C]; f32 f5c; f32 f60; u8 p64[4]; f32 f68; f32 f6c; } PH;

typedef ActorState BL;
typedef struct { f32 x, y, z; } V91;
void func_00391090(u8 *p, u8 *q) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00391540(u8 *, u8 *);
    p[4]++;
    p[5] = 0;
    *(BL *)(p + 0xEC) = *(BL *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V91 *)(p + 0x50) = *(V91 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    *(s8 *)(p + 0x31) = -8;
    *(s16 *)(p + 0x1C) = 0;
    *(u16 *)(p + 0x1E) = func_00174170() & 3;
    *(u32 *)(p + 0xD0) = 0;
    func_001757E0(p, 0x17, 0x11);
    func_00391540(p, q);
}

typedef ActorState BM;
typedef struct { f32 x, y, z; } V1D;
void func_001D3950(u8 *p, u8 *q) {
    extern void func_001754A0(u8 *, s32, s32);
    extern s8 func_00175670(u8 *);
    extern void func_003DAA40(u8 *);
    if (p[4] == 0) {
        p[4]++;
        *(BM *)(p + 0xEC) = *(BM *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V1D *)(p + 0x50) = *(V1D *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        func_001754A0(p, 0x1B, 4);
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    if (func_00175670(p) < 0) {
        func_003DAA40(p);
    }
}
