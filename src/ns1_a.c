/* func_0019DBB0: case body of func_0019DB80's dispatch; inherits the owner state then calls func_001757E0. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gns1a;
extern Gns1a *D_004C2794;

void func_0019DBB0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    s32 n;
    s32 *d;
    s32 *s;
    s32 one;
    s16 sv;
    s32 t;
    s32 v;
    u32 a;
    ++p[4];
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    one = 1;
    p[0x13C] = one;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    t = *(volatile u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    n = p[2];
    D_004C2794->f7c[n]++;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    sv = -1;
    if (p[0x21] & 1) sv = one;
    if (p[0x22] != 0) sv = -1;
    *(s16 *)(p + 0x1C) = sv;
    *(s16 *)(p + 0x1E) = 0x20;
    p[0x31] = *(s8 *)(p + 0x1C);
    a = (u8)(*(s8 *)(p + 0x21) + 3);
    if (p[0x22] != 0) a = (u8)(a + 4);
    func_001757E0(p, 0x17, a);
}
