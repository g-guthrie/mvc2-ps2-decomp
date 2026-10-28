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

void residual_003A1300(u8 *o) {
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    s32 v;
    u8 *a;
    u8 *q;
    t = o[4];
    a = *(u8 **)(o + 0x18);
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    q = o + 2;
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
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    v = o[0x20] ? 4 : -4;
    *(s8 *)(o + 0x31) += (s8)v;
    *(V3 *)(o + 0x34) = *(V3 *)(a + 0x34);
    *(f32 *)(o + 0x38) += 137.14285278320312f;
    o[0x21] = 0;
    if (o[0x20] == 0) {
        if (a[0x1FD] == 3) {
            o[0x1B5] = 0x38;
            o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        } else {
            o[0x1B5] = 0x41;
            o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
            *(s32 *)(o + 0x1D8) = 0;
            { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        }
        func_001E7F60(o);
    }
    func_001757E0(o, 0x17, (u8)(o[0x20] + 0x12));
}
