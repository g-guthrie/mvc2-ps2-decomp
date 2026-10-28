/* MW 3.0 -O3 -Op -sdatathreshold 8, built after src/sa29_g.c in the same invocation (compiler-process soft-float state). */
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
extern u8 *D_004C2970;
extern f32 D_004F1F4C[];

#define PAR (*(u8 **)(o + 0x18))

void residual_00364F70(u8 *o, s32 a, s32 b) {
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    double goal;
    f32 f;
    t = o[4];
    o[4] = t + 1;
    o[0x13C] = 1;
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
    *(s16 *)(o + 0x140) = *(s16 *)(PAR + 0x140);
    *D_004C2970 = 1;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = 0x30;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { u32 ca = (u32)D_004C2794; u32 k = o[2] * 2; ca = k + ca; ++*(s16 *)(ca + 0x7C); }
    o[0x14E] = 0x40;
    o[0x14F] = 0x40;
    if (PAR[0x1E6])
        goal = D_004F1F4C[0] - 320.0f - 160.0f;
    else
        goal = 160.0 + (320.0 + (double)D_004F1F4C[0]);
    *(f32 *)(o + 0x34) = goal;
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x430);
    *(s16 *)(o + 0x1C) = 0x10;
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    if (*(s16 *)(o + 0x140))
        f = 10.0f;
    else
        f = -10.0f;
    *(f32 *)(o + 0x5C) = f;
    func_0015E630(o);
    o[0] = 1;
    func_001757E0(o, 0x17, 0);
}
