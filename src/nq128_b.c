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

void func_0035F040(u8 *o, u8 *a) {
    extern s32 func_00174470(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    u32 z;
    f32 f;
    u8 *q, *r;
    q = a + 0x2B8;
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
    t = o[4];
    o[4] = t + 1;
    o[0x1B0] = 0x46;
    o[0x1B1] = 0x46;
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    *(s8 *)(o + 0x31) = -8;
    *(s16 *)(o + 0x1C) = 0;
    f = -160.0f;
    r = o + 2;
    if (*(s16 *)(o + 0x140) != 0) f = -f;
    *(f32 *)(o + 0x34) += f;
    o[0x14E] = 0x20;
    o[0x14F] = 0x20;
    if (func_00174470(o) == 0 || o[0x20] >= 7 || *(s8 *)(q + 5) <= 0) {
        o[5] = 2;
        o[0x13C] = 0;
        *(s16 *)(o + 0x1E) = 0x14;
    } else {
        o[0x1B5] = 0x3E;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *r; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        func_001E7F60(o);
        func_001757E0(o, 0x17, 0x12);
    }
}
