typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c; } T3;

extern T3 D_00463A10[];

void func_0036A650(u8 *p, u8 *q)
{
    f32 f;
    p[6]++;
    if (*(s16 *)(q + 0x140))
        f = D_00463A10[p[0x21]].a;
    else
        f = -D_00463A10[p[0x21]].a;
    *(f32 *)(q + 0x5C) = f;
    *(s32 *)(q + 0x68) = 0;
    *(f32 *)(q + 0x60) = D_00463A10[p[0x21]].b;
    *(f32 *)(q + 0x6C) = D_00463A10[p[0x21]].c;
    p[7] = 3;
}
