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
extern s16 D_004C1FC0[2];
extern s16 D_004C1FC2[2];
extern s32 D_00473D20[];
extern s32 D_00473D24[];
extern s32 D_00473D28[];

typedef struct { u8 p0[0x21]; u8 b21; u8 p1[0x12]; f32 f34; f32 f38; u8 p2[0x20]; f32 f5c; s32 f60; u8 p3[4]; f32 f68; f32 f6c; u8 p4[0xD0]; s16 h140; } Ob;
void residual_003B2030(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003B1F70(u8 *, s32, s32);
    extern void func_003B2380(u8 *, u8 *);
    u32 t;
    Ob *so = (Ob *)o;
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
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
    *(f32 *)(o + 0x3C) = *(f32 *)(a + 0x3C);
    if (so->h140 == 0) {
        so->f34 += 1.6666666269302368f * (f32)D_004C1FC0[so->b21 * 2];
    } else {
        so->f34 -= 1.6666666269302368f * (f32)D_004C1FC0[so->b21 * 2];
    }
    so->f38 += 2.142857074737549f * (f32)D_004C1FC2[so->b21 * 2];
    so->f5c = 1.6666666269302368f * (f32)D_00473D20[a[0x1B7] * 3 + so->b21 * 9] / 65536.0f;
    so->f68 = 1.6666666269302368f * (f32)D_00473D24[a[0x1B7] * 3 + so->b21 * 9] / 65536.0f;
    so->f60 = 0;
    so->f6c = 1.6666666269302368f * (f32)D_00473D28[a[0x1B7] * 3 + so->b21 * 9] / 65536.0f;
    if (so->h140 != 0) {
        so->f5c = -so->f5c;
        so->f68 = -so->f68;
    }
    func_001757E0(o, 0x17, 0xC);
    func_003B1F70(o, 1, 0);
    func_003B1F70(o, 1, 0);
    func_003B1F70(o, 1, 0);
    func_003B1F70(o, 1, 0);
    func_003B2380(o, a);
}
