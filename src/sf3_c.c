typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0xD0]; u32 fD0; } PD;

extern u8 *D_00443960[];
extern u16 D_004435E0[];
extern f32 D_004435C8[];
extern V3 D_00442AA0;
extern s32 D_004C2804;
extern s32 D_004C27E8;
extern s32 D_004C27F8;
extern s32 D_004C27FC;

void func_00148010(u8 *p, u8 *q) {
    extern void func_003DAA40(u8 *, u8 *);
    u8 *s;
    u8 k;
    u8 a;
    u32 h;
    u32 t;
    t = p[4];
    p[4] = t + 1;
    p[5] = 2;
    p[0x13C] = 1;
    a = p[0x21];
    s = D_00443960[a];
    if (s == 0) {
        func_003DAA40(p, q);
        return;
    }
    k = p[0x20];
    s += k * 28;
    if (k == 4) {
        h = D_004435E0[a];
    } else {
        h = *(u16 *)(s + 0x18);
    }
    h = (u16)h;
    if ((u8)a == 0x12) {
        *(u16 *)(p + 0xCC) = h;
        *(s32 *)(p + 0x84) = D_004C2804;
    } else if ((u8)a == 0x13) {
        *(u16 *)(p + 0xCC) = h;
        *(s32 *)(p + 0x84) = D_004C27E8;
    } else if (!((u8)a < 0x10)) {
        *(u16 *)(p + 0xCC) = h;
        *(s32 *)(p + 0x84) = D_004C27F8;
    } else {
        *(u16 *)(p + 0xCC) = h;
        *(s32 *)(p + 0x84) = D_004C27FC;
    }
    *(V3 *)(p + 0x34) = *(V3 *)s;
    *(V3 *)(p + 0x50) = D_00442AA0;
    *(u32 *)(p + 0x48) = (u16)(s32)(0.5 + (65536.0 * (f64)D_004435C8[*(s8 *)(s + 0x1B)]) / 360.0);
    *(u32 *)(p + 0xD0) |= 0x428;
    *(u32 *)(p + 0x74) = 0x3F800000;
    *(f32 *)(p + 0x78) = *(f32 *)(s + 0xC);
    *(f32 *)(p + 0x7C) = *(f32 *)(s + 0x10);
    *(f32 *)(p + 0x80) = *(f32 *)(s + 0x14);
    if (p[0x20] == 0) {
        ((PD *)p)->fD0 |= 0x800000;
    }
}
