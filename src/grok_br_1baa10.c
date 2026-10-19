typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001754A0(u8 *, int, int);

void residual_001BAA10(u8 *p, u8 *q)
{
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    s = (s32 *)(q + 0xEC);
    n = 0x31;
    t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    d = (s32 *)(p + 0xEC);
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
    p[0x24] = 0;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_001754A0(p, 0x1B, 5);
    *(u32 *)(p + 0x118) = 0x3F800000;
}
