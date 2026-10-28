typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3r;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3r;
extern G3r *D_004C2794;
extern u8 D_004C1BE0[8];
extern s16 D_004C1BE8[4];
extern s16 D_004C1BEA[3];

void residual_00360CC0(u8 *o, u8 *a)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00360F40(u8 *, u8 *);
    u8 *q;
    u32 t;
    s16 v;
    t = o[4];
    o[4] = t + 1;
    *(B3r *)(o + 0xEC) = *(B3r *)(a + 0xEC);
    o[0x13C] = 1;
    q = o + 2;
    o[2] = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    o[0x13C] = 0;
    *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(a + 0x3C);
    v = (s32)(1.6666666269302368f * (f32)D_004C1BE8[o[0x21] * 2]);
    if (*(s16 *)(a + 0x140) != 0) {
        v = -v;
    }
    *(f32 *)(o + 0x34) += (f32)v;
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)D_004C1BEA[o[0x21] * 2];
    o[0x22] = D_004C1BE0[o[0x21]];
    if (*(s16 *)(o + 0x140) != 0) {
        o[0x22] = 0x20 - *(s8 *)(o + 0x22);
        o[0x22] &= 0x1F;
    }
    if (o[0x21] == 0) {
        o[0x1B5] = *(s8 *)(a + 0x1B7) + 0x32;
        t = *(volatile u8 *)(o + 0x1B5);
        o[0x1B5] = t;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    } else {
        o[0x1B5] = *(s8 *)(a + 0x1B7) + 0x34;
        o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[*q]++;
    }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    func_001757E0(o, 0x17, 0x17);
    func_00360F40(o, a);
}
