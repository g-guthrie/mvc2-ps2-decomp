/* nq94_c: MW 3.0: ./try30.sh src/nq94_c.c "-O3 -Op -sdatathreshold 8" */
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
typedef struct { u8 pad[2]; u8 b[2]; } O2;
extern s16 D_004C1988[4];

void func_00346AF0(u8 *o, u8 *a) {
    extern void func_00346DC0(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00346C50(u8 *, u8 *);
    u8 *q;
    u32 t;
    t = o[4];
    o[4] = t + 1;
    *(B3c *)(o + 0xEC) = *(B3c *)(a + 0xEC);
    o[0x13C] = 1;
    q = &o[2]; *q = a[2];
    o[1] = a[1];
    *(f32 *)(o + 0x50) = *(f32 *)(a + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(a + 0x54);
    o[0x1B7] = a[0x1B7];
    o[0x1B8] = a[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(a + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(a + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(a + 0x24);
    func_00346DC0(o, a);
    *(s16 *)(o + 0x1C) = D_004C1988[a[0x1B7]];
    *(u16 *)(o + 0x1E) = *(u16 *)(a + 0x168);
    o[0x1B0] = 0x42;
    o[0x1B1] = 0x42;
    func_001757E0(o, 0x14, 1);
    o[0x1B5] = 0x2B;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *q; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_00346C50(o, a);
}
