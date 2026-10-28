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

void func_003C55A0(u8 *o, u8 *a) {
    extern s32 fptosi(f32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0015E630(u8 *);
    u32 t;
    u32 z;
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
    o[0x1B1] = 0x44;
    o[0x1B0] = 0x44;
    o[0x14F] = 0x40;
    o[0x14E] = 0x40;
    o[0x14D] = 0x40;
    o[0x14C] = 0x40;
    *(s8 *)(o + 0x31) = -8;
    o[0x1B5] = 0x42;
    z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(s16 *)(o + 0x1E) = fptosi(*(f32 *)(a + 0x430));
    *(f32 *)(o + 0x38) = 205.7142791748047f + *(f32 *)(a + 0x430);
    if ((*(s16 *)(o + 0x140) = *(s16 *)(a + 0x140)) != 0) {
        *(f32 *)(o + 0x34) = 26.66666603088379f + *(f32 *)(a + 0x34);
        *(u32 *)(o + 0x5C) = 0x40D55555;
    } else {
        *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34) - 26.66666603088379f;
        *(u32 *)(o + 0x5C) = 0xC0D55555;
    }
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x6C) = 0xBF4DB6DB;
    *(s16 *)(o + 0x1C) = 2;
    func_001757E0(o, 0x15, 0x12);
    func_0015E630(o);
    o[0] = 1;
}
