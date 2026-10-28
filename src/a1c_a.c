typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
extern G3a *D_004C2794;
extern s16 D_00463460[][2];
extern s16 D_00463462[][2];
extern u8 D_004634A0[];
extern u8 D_00463450[];

void residual_003605F0(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00360860(u8 *, u8 *);
    u32 t;
    s16 r;
    u8 *pp;
    t = o[4];
    o[4] = t + 1;
    *(B3a *)(o + 0xEC) = *(B3a *)(q + 0xEC);
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
    pp = o + 2;
    if (o[0x20] == 0) {
        o[0x1B5] = 0x30;
    } else {
        o[0x1B5] = 0x38;
    }
    t = *(volatile u8 *)(o + 0x1B5);
    o[0x1B5] = t;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_00463462[o[0x21]][0];
    r = (s32)(1.6666666269302368f * (f32)D_00463460[o[0x21]][0]);
    if (*(s16 *)(q + 0x140) != 0) r = -r;
    *(f32 *)(o + 0x34) += (f32)r;
    o[0x22] = D_004634A0[o[0x21]];
    if (*(s16 *)(o + 0x140) != 0) {
        o[0x22] = 0x20 - *(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    func_001757E0(o, 0x17, D_00463450[o[0x21]]);
    func_00360860(o, q);
}
