/* s7d_b: MW 3.0 ./try30.sh "-O3 -Op -sdatathreshold 8" */
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
extern u8 D_00464B60[];

#define PAR (*(u8 **)(o + 0x18))

void residual_00389370(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00389510(u8 *);
    u8 *tb;
    u8 *q;
    u8 *p2;
    u32 t;
    u32 z;
    t = o[4];
    q = PAR;
    o[4] = t + 1;
    *(s16 *)(o + 0x26) = 0x1C08;
    *(B3c *)(o + 0xEC) = *(B3c *)(q + 0xEC);
    o[0x13C] = 1;
    p2 = o + 2;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(o + 0x1C) = 0;
    tb = D_00464B60 + o[0x20] * 2;
    *(s8 *)(o + 0x31) = *(s8 *)tb;
    if (o[0x20] == 0) {
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x4E;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    } else if (o[0x20] == 4) {
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x3F;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *p2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    func_001757E0(o, 0x16, tb[1]);
    func_00389510(o);
}

