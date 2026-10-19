#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void (*jtbl_0044CEC0[])(u8 *);
extern void func_001C9B10(u8 *);

void residual_001C9530(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u8 one;
    n = 0x31;
    one = 1;
    p[4] = p[4] + 1;
    p[0x13C] = one;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    d = (s32 *)(p + 0xEC);
    do {
        *d = *s;
        n--;
        s++;
        d++;
        asm { nop }
        asm { nop }
    } while (n > 0);
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
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    jtbl_0044CEC0[p[0x20] + 4](p);
    func_001C9B10(p);
}
