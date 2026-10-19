#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, s32, s32);

void residual_001CDF2C(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    unsigned int t;
    asm { nop }
    t = p[5];
    d = (s32 *)(p + 0xEC);
    n = 0x31;
    p[5] = t + 1;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
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
    p[0x24] = 0;
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) - 6.4285712242126465f;
    func_001757E0(p, 0x17, 0);
}
