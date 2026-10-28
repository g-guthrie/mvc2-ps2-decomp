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
extern s16 D_004C1C08[4];
typedef struct { u8 pad[0x5C]; f32 f5c; f32 f60; f32 f64; f32 f68; } NG;

void residual_00361A00(u8 *p, u8 *q) {
    extern s32 func_00174170(void);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_00361C40(u8 *, u8 *);
    u8 *o;
    NG *ng;
    u32 t;
    u32 z;
    s16 v;
    o = p + 0xD0;
    ng = (NG *)p;
    t = p[4];
    p[4] = t + 1;
    *(B3c *)(p + 0xEC) = *(B3c *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    *(s8 *)(p + 0x31) = -1;
    p[0x14F] = 0x10;
    p[0x14E] = 0x10;
    p[0x14D] = 0x10;
    p[0x14C] = 0x10;
    p[0x1B5] = 0x36;
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    z = p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    v = (s32)(1.6666666269302368f * (f32)D_004C1C08[p[0x21] & 3]);
    if (*(s16 *)(q + 0x140) != 0) {
        v = -v;
    }
    *(f32 *)(p + 0x34) += (f32)v;
    *(u32 *)(p + 0x5C) = 0xC2555555;
    *(u32 *)(p + 0x68) = 0x40D55555;
    *(u32 *)(p + 0x60) = 0x40AB6DB6;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s16 *)(q + 0x140) != 0) {
        ng->f5c = -ng->f5c;
        ng->f68 = -ng->f68;
    }
    func_00175910(p, 0x17, 0x16, func_00174170() & 0xF);
    o[8] = 0;
    *(f32 *)(o + 4) = *(f32 *)(p + 0x5C);
    func_00361C40(p, q);
}
