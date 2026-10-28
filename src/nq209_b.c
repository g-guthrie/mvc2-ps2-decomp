typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x34]; f32 f34; } O34;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;
extern s16 D_00475C00[];
extern s16 D_00475C02[];
extern s8 D_00475C04[];
extern u8 D_00475C06[];
extern u8 D_00475C50[];
extern u8 D_00475C51[];
extern s16 D_00475C70[];

#define PAR par

void residual_003C0CE0(u8 *o, u8 *par) {
    extern void func_00174910(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C0FC0(u8 *, u8 *);
    u32 t;
    u32 z;
    u8 *q;
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
    *(s8 *)(o + 0x31) = -1;
    o[0x1B5] = *(s8 *)(o + 0x21) + 0x3C;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(PAR + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(PAR + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(PAR + 0x3C);
    if (*(s16 *)(o + 0x140) == 0) {
        ((O34 *)o)->f34 += 1.6666666269302368f * (f32)D_00475C00[o[0x21] * 4];
    } else {
        ((O34 *)o)->f34 -= 1.6666666269302368f * (f32)D_00475C00[o[0x21] * 4];
    }
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_00475C02[o[0x21] * 4];
    o[0x22] = D_00475C04[o[0x21] * 8];
    if (*(s16 *)(o + 0x140) != 0) {
        o[0x22] = 0x20 - *(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    q[0] = D_00475C50[o[0x21] * 2];
    q[1] = D_00475C51[o[0x21] * 2];
    func_00174910(o, D_00475C70[*(s8 *)(q + 1)]);
    func_001757E0(o, 0x17, D_00475C06[o[0x21] * 8]);
    *(s16 *)(o + 0x1C) = 0x14;
    func_003C0FC0(o, par);
}
