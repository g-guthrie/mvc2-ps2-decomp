typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn2)(u8 *, void *);
typedef struct { f32 x, y, z; } HK1V3;

extern DispatchFn2 jtbl_0044ECC0[];

void func_001DCF50(u8 *p, u8 *s) {
    s32 n;
    DispatchFn2 *t;
    u32 *d, *q;
    u32 tmp;

    q = (u32 *)(s + 0xEC);
    d = (u32 *)(p + 0xEC);

    tmp = p[4];
    p[4] = tmp + 1;
    n = 0x31;
    do {
        *d++ = *q++;
    } while (--n > 0);
    p[0x13C] = 1;
    t = jtbl_0044ECC0;
    p[2] = s[2];
    p[1] = s[1];
    *(f32 *)(p + 0x50) = *(f32 *)(s + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(s + 0x54);
    p[0x1B7] = s[0x1B7];
    p[0x1B8] = s[0x1B8];
    p[0x30] = *(s8 *)(s + 0x30);
    *(HK1V3 *)(p + 0x50) = *(HK1V3 *)(s + 0x50);
    p[0x24] = *(s8 *)(s + 0x24);
    p[0x24] = 8;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    t[p[0x20]](p, s);
}
