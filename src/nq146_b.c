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

void func_003B6AD0(u8 *o, u8 *a) {
    extern void func_003B6A30(u8 *, u8);
    extern void func_001E7F60(u8 *);
    extern void func_003B6F00(u8 *, u8 *);
    u32 t;
    u32 z;
    s32 i;
    u8 *q;
    u8 *r;
    *(u32 *)(o + 0x14C) = 0x10101010;
    q = o + 0x88;
    if (o[0x21] == 0) {
        i = 11;
        do {
            func_003B6A30(o, i);
            i--;
        } while (i > 0);
    }
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
    o[0x31] = 1;
    q[0xA] = 0;
    *(s16 *)(q + 0) = 0;
    *(s16 *)(q + 4) = 0;
    *(s16 *)(q + 2) = 0;
    *(s16 *)(q + 8) = 0;
    *(s16 *)(q + 6) = 1;
    *(u32 *)(o + 0x50) = 0x3F866666;
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x40;
    r = o + 2;
    if (o[0x20] == 2) {
        o[0x1B5] = 0x34;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *r; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    } else {
        o[0x1B5] = 2;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = *r; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    }
    func_001E7F60(o);
    func_003B6F00(o, a);
}
