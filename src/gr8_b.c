/* gr8: MW 3.0.3, ./try.sh src/gr8_b.c "-O3 -Op -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3b;

extern u8 D_0044B090[];
extern s16 D_0044B0B0[];
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_001A3C00(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    s8 t;

    s32 v;
    s16 *e; u8 *b;
    if (q[5] != 0 || q[0x1E4] != 0x15 || q[0x1FD] != 0 || q[0x169] != *(s16 *)(p + 0x1C)) {
        p[4] = 2;
        p[0x13C] = 0;
        return;
    }
    if (D_004D18DC & (1 << D_004D18DB)) {
        return;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -8;
    t = *(s8 *)(q + 0x150);
    if (t != 0) {
    p[0x13C] = 1;
    if (t != p[0x22]) {
        p[0x22] = t;
        v = (t & 0xF) * 4; b = D_0044B090 + (v + p[0x21]); func_001757E0(p, 0x17, *b);
        e = D_0044B0B0; e += ((p[0x22] & 0xF) - 1) * 8 + p[0x21] * 2;
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)e[0];
        *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)e[1];
        if (q[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
    *(V3b *)(p + 0x34) = *(V3b *)(q + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    } else {
        p[0x13C] = 0;
    }
}
