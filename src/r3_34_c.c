/* MWCC 3.0: ./try30.sh src/r3_34_c.c "-O3 -Op -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { u8 b[4][4]; } T16;
typedef struct { f32 f[3]; } T12;
typedef struct { u16 h[3]; } T6;
typedef struct { u8 b[8]; } T8;
typedef struct { u8 b[4]; } T4;
extern G3c *D_004C2794;
extern T16 D_00472F50 __attribute__((aligned(16)));
extern T12 D_00472F60;
extern T6 D_004C1F18;
extern T8 D_004C1F20;
extern T4 D_004C1F10;

void residual_003A83B0(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    T4 te = D_004C1F10;
    T16 ta __attribute__((aligned(16))) = D_00472F50;
    T12 tb = D_00472F60;
    T6 tc = D_004C1F18;
    T8 td = D_004C1F20;
    u32 t;
    u16 k;
    u16 j;
    s32 m;
    f32 f;
    u8 *q;
    u8 *p2;
    t = o[4];
    o[4] = t + 1;
    o[0x13C] = 1;
    o[0x14C] = 0x20;
    o[0x14D] = 0x28;
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    q = *(u8 **)(o + 0x18);
    *(B3c *)(o + 0xEC) = *(B3c *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    p2 = o + 2;
    o[0x24] = 8;
    o[7] = 3;
    k = tc.h[o[0x1B7]];
    if (o[0x20] != 0) k = 0x40;
    if (*(s32 *)(q + 0x2D4) == 2) k <<= 2;
    *(s16 *)(o + 0x1C) = k;
    *(s16 *)(o + 0x1E) = 100;
    o[0x23] = 0;
    j = o[0x20];
    if (j != 0) j = 4;
    j += *(u16 *)(q + 0x2D4);
    o[0x21] = td.b[j];
    m = *(s32 *)(q + 0x2D4);
    f = tb.f[o[0x1B7]];
    if (m == 1) f *= 1.5f;
    if (m == 3) f /= 0.75f;
    if (o[0x20] != 0) {
        f = -10.0f;
        if (m == 1) f *= 2.0f;
        if (m == 3) f /= 0.75f;
    }
    if (*(s16 *)(o + 0x140) != 0) f = -f;
    *(f32 *)(o + 0x5C) = f;
    *(s32 *)(o + 0x68) = 0;
    if (o[0x20] == 0) {
        *(u32 *)(o + 0x54) = 0x3F400000;
        *(u32 *)(o + 0x50) = 0x3F400000;
    }
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x22] = te.b[o[0x20]];
    o[0x1B5] = ta.b[o[0x20]][*(s32 *)(q + 0x2D4)];
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x15, 2);
}
