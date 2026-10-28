/* nearmiss residual_003A9320: ./try30.sh -O3 -Op -sdatathreshold 0, 11/66 words differ (loop-head reg naming: t/d and 0x78/n swapped a2<->t1, a1<->t0) */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_nq58;
typedef struct { s32 w[0x31]; } B_gr24;

void residual_003A9320(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s;
    s32 n;
    s32 *d;
    s32 k;
    f32 c;
    u8 *q = *(u8 **)(p + 0xD0);
    u32 t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x1C) = 0x78;
    *(s16 *)(p + 0x1E) = 8;
    *(B_gr24 *)(p + 0xEC) = *(B_gr24 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3_nq58 *)(p + 0x50) = *(V3_nq58 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    p[0x1B0] = 0;
    p[0x1B1] = 0;
    k = 0x20;
    if (*(s16 *)(p + 0x140) != 0) k = -0x20;
    c = 1.6666666269302368f;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34) + c * (f32)k;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    func_001757E0(p, 0x14, 4);
}
