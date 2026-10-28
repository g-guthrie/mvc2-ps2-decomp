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
typedef struct { u8 pad[0x5C]; f32 f5c; u8 pad2[8]; f32 f68; } N5;

void residual_003C6840(u8 *o, u8 *a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C4990(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    u32 t;
    u8 *q;
    s32 v;
    N5 *sa;
    sa = (N5 *)o;
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
    o[0x14C] = 0x30;
    o[0x14D] = 0x10;
    o[0x14E] = 0x30;
    o[0x14F] = 0x70;
    *(s8 *)(o + 0x31) = -0x10;
    o[0x1B5] = 0x44;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    q = *(u8 **)(o + 0x14);
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(f32 *)(o + 0x5C) = -6.666666507720947f;
    *(f32 *)(o + 0x68) = -0.4166666567325592f;
    *(f32 *)(o + 0x38) = 137.14285278320312f + *(f32 *)(q + 0x38);
    v = -0x180000;
    if ((*(s16 *)(o + 0x140) = *(s16 *)(q + 0x140)) != 0) {
        sa->f5c = -sa->f5c;
        sa->f68 = -sa->f68;
        v = 0x180000;
    }
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * (f32)v / 65536.0f;
    func_001757E0(o, 0x15, 0x1A);
    func_003C4990(o, 0xE, 0);
    func_001E3210(a, 0x19);
}
