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
typedef struct { u8 pad0[0x34]; f32 f34, f38, f3c; u8 pad1[0x5C - 0x40]; f32 f5c; s32 f60; u8 pad2[4]; f32 f68, f6c; } Of;
extern s16 D_004C27A4;
extern s16 D_004C1ED0[4];
extern s16 D_004C1ED2[4];
extern s32 D_00472DA0[], D_00472DA4[], D_00472DA8[];

void residual_003A5ED0(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003A5E10(u8 *, s32, s32);
    extern void func_003A6240(u8 *, u8 *);
    u32 t;
    Of *so = (Of *)o;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    o[0x13C] = 1;
    o[2] = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    o[0x13C] = 1;
    *(s8 *)(o + 0x31) = -2;
    t = a[0x2BA];
    a[0x2BA] = t + 1;
    o[0x1B5] = 0x32;
    t = *(volatile u8 *)(o + 0x1B5);
    o[0x1B5] = t;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(a + 0x3C);
    if (*(s16 *)(o + 0x140) == 0) {
        so->f34 += 1.6666666269302368f * (f32)D_004C1ED0[o[0x21] * 2];
    } else {
        so->f34 -= 1.6666666269302368f * (f32)D_004C1ED0[o[0x21] * 2];
    }
    so->f38 += 2.142857074737549f * (f32)D_004C1ED2[o[0x21] * 2];
    so->f5c = 1.6666666269302368f * (f32)D_00472DA0[a[0x1B7] * 3 + o[0x21] * 9] / 65536.0f;
    so->f68 = 1.6666666269302368f * (f32)D_00472DA4[a[0x1B7] * 3 + o[0x21] * 9] / 65536.0f;
    so->f60 = 0;
    so->f6c = 1.6666666269302368f * (f32)D_00472DA8[a[0x1B7] * 3 + o[0x21] * 9] / 65536.0f;
    if (*(s16 *)(o + 0x140) != 0) {
        so->f5c = -so->f5c;
        so->f68 = -so->f68;
    }
    func_001757E0(o, 0x17, 0xC);
    if (D_004C27A4 >= 4) {
        func_003A5E10(o, 1, 0);
        func_003A5E10(o, 1, 0);
        func_003A5E10(o, 1, 0);
        func_003A5E10(o, 1, 0);
    }
    func_003A6240(o, a);
}
