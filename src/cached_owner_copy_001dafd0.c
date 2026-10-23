/* Copy and inherit the cached owner state before entering the selected unary callback. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

typedef void (*OwnerCallback)(u8 *);
extern OwnerCallback jtbl_0044E920[];

void func_001DAFD0(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q=*(u8**)(p+0x18);
    u32 t = p[4];
    p[4] = t + 1;
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    s = (s32 *)(q + 0xEC);
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
    jtbl_0044E920[p[0x20]](p);
}
