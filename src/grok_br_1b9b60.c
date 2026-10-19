typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, int, int);

void residual_001B9B60(u8 *p)
{
    s32 n;
    s32 *d;
    s32 *s;
    u8 *q;
    u32 t;
    d = (s32 *)(p + 0xEC);
    t = p[4];
    n = 0x31;
    p[4] = t + 1;
    p[0x13C] = 1;
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
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(p + 0x1C) = *(s16 *)(*(u8 **)(p + 0x18) + 0x1E);
    *(u32 *)(p + 0x118) = 0x3F000000;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    p[0x24] = 10;
    if (p[0x20] != 0)
        func_001754A0(p, 0x17, 4);
    else
        func_001754A0(p, 0x17, 3);
}
