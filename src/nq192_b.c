typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3b;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3b;
extern G3b *D_004C2794;
typedef struct { u8 pad[0x5C]; f32 f5c; } N5b;
extern s16 D_00473C80[][2];
extern s16 D_00473C82[][2];

void residual_003B0920(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B0B90(u8 *, u8 *);
    u32 t;
    u8 *pp;
    N5b *na;
    t = o[4];
    o[4] = t + 1;
    *(B3b *)(o + 0xEC) = *(B3b *)(q + 0xEC);
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
    if (o[0x21] & 1) {
        o[0x1B5] = 0x3B;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    } else {
        o[0x1B5] = 0x3C;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    *(s16 *)(o + 0x140) = 0;
    o[0x22] = 0x18;
    if (*(s16 *)(q + 0x140) != 0) {
        o[0x22] = 0x20 - *(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * (f32)D_00473C82[o[0x21]][0];
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    *(f32 *)(o + 0x5C) = 1.6666666269302368f * (f32)D_00473C80[o[0x21]][0];
    if (*(s16 *)(q + 0x140) != 0) {
        na = (N5b *)o;
        na->f5c = -na->f5c;
    }
    *(f32 *)(o + 0x34) += *(f32 *)(o + 0x5C);
    func_001757E0(o, 0x17, 1);
    func_003B0B90(o, q);
}
