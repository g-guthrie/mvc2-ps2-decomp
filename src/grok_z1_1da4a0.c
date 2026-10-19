#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;

extern int func_001757E0(u8 *, s32, s32);
extern void func_001DA5A0(u8 *, u8 *);

void func_001DA4A0(u8 *p, void *owner)
{
    u8 *q = owner;
    s32 n;
    s32 *d;
    s32 *s;
    u32 t = p[4];
    p[4] = t + 1;
    n = 0x31;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
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
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(s8 *)(p + 0x31) = -1;
    func_001757E0(p, 0x17, 7);
    func_001DA5A0(p, q);
}
