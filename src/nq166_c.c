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
extern f32 D_004F1FD0[];
extern u8 D_004C1B80[8];

void residual_0035E190(u8 *o, u8 *a)
{
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0035E3A0(u8 *, u8 *);
    u32 t;
    u8 *q;
    s32 v;

    t = o[4];
    q = *(u8 **)(o + 0x14);
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
    *(s8 *)(o + 0x31) = -1;
    o[0x1B5] = 0x52;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(o + 0x38) = D_004F1FD0[0];
    *(f32 *)(o + 0x3C) = *(f32 *)(q + 0x3C);
    *(f32 *)(o + 0x34) += 1.666666627f * (f32)(0x80 - (s16)(func_00174170() & 0xFF));
    *(f32 *)(o + 0x38) += 2.142857074737549f * (f32)(0x40 - (s16)(func_00174170() & 0x7F));
    v = -0x6A;
    if (*(s16 *)(o + 0x140) != 0) v = 0x6A;
    *(f32 *)(o + 0x34) += (f32)v;
    *(u32 *)(o + 0x60) = 0x414DB6DB;
    *(u32 *)(o + 0x6C) = 0xBFAB6DB6;
    func_001757E0(o, 0x17, D_004C1B80[func_00174170() & 7]);
    func_0035E3A0(o, a);
}
