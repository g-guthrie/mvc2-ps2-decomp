#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001D4B40(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_001D4970(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    n = 0x31;
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
    p[4]++;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -2;
    p[0x13C] = 0;
    *(short *)(p + 0x140) = *(short *)(q + 0x140);
    func_001D4B40(p);
    func_001757E0(p, 0x17, 2);
}
