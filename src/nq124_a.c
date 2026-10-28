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

void func_0039F4B0(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0039F650(u8 *, u8 *);
    u32 t;
    s16 v;
    u8 *q2;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    q2 = o + 2;
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
    o[0x13C] = 0;
    v = o[0x21] * 64 + 0x58;
    if (a[0x1E6]) v = -v;
    *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34) - 1.6666666269302368f * (f32)v;
    *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
    o[0x24] = 8;
    *(s16 *)(o + 0x1C) = o[0x21] * 8 + 1;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    o[0x1B5] = *(s8 *)(o + 0x1B7) + 0x30;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q2; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x15, 0x1A);
    func_0039F650(o, a);
}
