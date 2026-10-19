#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001BFFB0(u8 *);

void func_001BFEC0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    unsigned int t;
    t = p[4];
    p[4] = t + 1;
    d = (s32 *)(p + 0xEC);
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    n = 0x31;
    do {
        *d = *s;
        n--;
        s++;
        d++;
    } while (n > 0);
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    p[2] = q[2];
    q = *(u8 **)(p + 0x18);
    p[1] = q[1];
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    q = *(u8 **)(p + 0x18);
    p[0x1B7] = q[0x1B7];
    q = *(u8 **)(p + 0x18);
    p[0x1B8] = q[0x1B8];
    q = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    q = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    q = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x24] = 7;
    q = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_001BFFB0(p);
}
