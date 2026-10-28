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
extern u8 D_004C1F60[8];

/* MWCC: ./try30.sh src/nq162_a.c "-O3 -Op -sdatathreshold 8" */
void residual_003AFAB0(u8 *o, u8 *q) {
    extern s32 fptosi(f32);
    extern void func_00174910(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003AFCB0(u8 *, u8 *);
    u32 t;
    u32 z;
    s16 *s;
    s = (s16 *)(o + 0xD0);
    t = o[4];
    o[4] = t + 1;
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
    o[0x13C] = 1;
    *(s8 *)(o + 0x31) = -1;
    o[0x14F] = 0x10;
    o[0x14E] = 0x10;
    o[0x14D] = 0x10;
    o[0x14C] = 0x10;
    o[0x1B5] = 0x32;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x22] = D_004C1F60[o[0x21]];
    if (*(s16 *)(q + 0x140) != 0) {
        o[0x22] = 0x20 - *(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    s[0] = fptosi(*(f32 *)(q + 0x34));
    s[1] = fptosi(137.14285278320312f + *(f32 *)(q + 0x38));
    *(f32 *)(o + 0x34) = s[0];
    *(f32 *)(o + 0x38) = s[1];
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    func_00174910(o, 0x1900);
    func_001757E0(o, 0x17, 1);
    func_003AFCB0(o, q);
}
