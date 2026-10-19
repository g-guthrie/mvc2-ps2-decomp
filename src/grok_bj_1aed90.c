#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;

extern void func_001E3210(u8 *, s32);
extern void func_001754A0(u8 *, s32, s32);

void residual_001AED90(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    p[4]++;
    n = 0x31;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
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
    *(s8 *)(p + 0x31) = -1;
    p[0x13C] = 0;
    func_001E3210(p, 0x21);
    func_001754A0(p, 0x1B, 0x16);
}
