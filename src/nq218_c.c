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
extern G3c *D_004C2794;

/* MWCC 3.0: ./try30.sh src/nq218_c.c "-O3 -Op -sdatathreshold 8" */
#define PAR (*(u8 **)(o + 0x18))

void residual_0037BF60(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0037CB60(u8 *, u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001E3210(u8 *, s32);
    u8 *par;
    u8 *q;
    u8 *p2;
    u32 t;
    u32 z;
    f32 k;
    s32 v;
    par = PAR;
    q = o + 0xD0;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
    o[0x13C] = 1;
    o[2] = PAR[2];
    o[1] = PAR[1];
    *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
    o[0x1B7] = PAR[0x1B7];
    o[0x1B8] = PAR[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
    o[0x13C] = 1;
    *(V3 *)(o + 0x34) = *(V3 *)(PAR + 0x34);
    p2 = o + 2;
    if (par[0x20D] == 2) {
        if (*(s16 *)(o + 0x140) != 0) {
            k = 182.0f;
        } else {
            k = -182.0f;
        }
        *(f32 *)(o + 0x34) += k;
        *(f32 *)(o + 0x38) += 170.0f;
    } else {
        if (*(s16 *)(o + 0x140) != 0) {
            k = 182.0f;
        } else {
            k = -182.0f;
        }
        *(f32 *)(o + 0x34) += k;
        *(f32 *)(o + 0x38) += 170.0f;
    }
    *(f32 *)(o + 0x64) = *(f32 *)(o + 0x34);
    if (*(s16 *)(o + 0x140) != 0) {
        v = o[0x23] * 35;
    } else {
        v = -(o[0x23] * 35);
    }
    *(f32 *)(o + 0x34) += (f32)v;
    *(f32 *)(o + 0x70) = *(f32 *)(o + 0x38);
    if (o[0x23] != 0) {
        *(s8 *)(o + 0x24) = *(s8 *)(par + 0x24);
        o[0x31] = o[0x23];
    } else {
        *(s8 *)(o + 0x24) = 0;
        o[0x31] = o[0x23];
    }
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(s16 *)(o + 0x1C) = *(s16 *)(PAR + 0x1E);
    if (o[0x23] % 3 == 0) {
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        func_0037CB60(o, par);
        func_001E7F60(o);
    } else {
        o[0x1B0] = 0;
        o[0x1B1] = 0;
        o[0x1B5] = 0;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    *(s16 *)(q + 2) = 8;
    *(s32 *)(par + 0x2DC) = 0;
    if (o[0x23] == 0xF) {
        func_001757E0(o, 0x17, 7);
    } else if (o[0x23] == 0) {
        func_001757E0(o, 0x17, 6);
        func_001E3210(o, 0x23);
    } else {
        func_001757E0(o, 0x17, 5);
    }
}
