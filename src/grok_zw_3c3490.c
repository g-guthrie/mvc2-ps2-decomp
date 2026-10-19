#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, s32, s32);
extern void func_003C35B0(u8 *, u8 *);

void residual_003C3490(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t = p[4];
    n = 0x31;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    p[4] = t + 1;
    do {
        *d = *s;
        n--;
        s++;
        d++;


    } while (n > 0);
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
    p[0x24] = 0xB;
    *(s8 *)(p + 0x31) = -2;
    *(s16 *)(p + 0x140) = 0;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (p[0x21] == 0)
        p[0x168] = 0x13;
    else
        p[0x168] = 0x14;
    func_001757E0(p, 0x16, p[0x168]);
    func_003C35B0(p, q);
}
