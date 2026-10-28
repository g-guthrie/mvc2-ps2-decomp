typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;

extern s16 D_00475B00[];

/* MWCC 3.0: ./try30.sh src/nq137_b.c "-O3 -Op -sdatathreshold 0" */
void residual_003BE320(u8 *o, u8 *a) {
    extern void func_001754A0(u8 *, s32, s32);
    extern void func_003BE4E0(u8 *, u8 *);
    u32 t;
    s16 v;
    s32 w;
    s16 *e;
    u8 *r;
    f32 fa, fb;
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
    o[0x1B0] = 0;
    o[0x1B1] = 0;
    e = &D_00475B00[o[0x21] * 4];
    *(s32 *)(o + 0xD0) = v = *e++;
    *(s32 *)(o + 0xD4) = w = *e++;
    if (*(s16 *)(o + 0x140) != 0) {
        v = -v;
    }
    r = *(u8 **)(o + 0xDC);
    fa = 1.6666666269302368f * (f32)v;
    fb = 2.142857074737549f * (f32)w;
    *(V3 *)(o + 0x50) = *(V3 *)(r + 0x50);
    *(f32 *)(o + 0x34) = *(f32 *)(r + 0x34) + fa * *(f32 *)(r + 0x50);
    *(f32 *)(o + 0x38) = *(f32 *)(r + 0x38) + fb * *(f32 *)(r + 0x54);
    if (*e++ != 0) {
        *(s16 *)(o + 0x140) ^= 1;
    }
    *(s8 *)(o + 0x24) = *(s8 *)e;
    func_001754A0(o, 0x1B, o[0x21]);
    func_003BE4E0(o, a);
}
