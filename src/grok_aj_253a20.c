typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_00178F20(u8 *, u8 *);

void residual_00253A20(u8 *p)
{
    u8 *q;
    f32 a;
    f32 b;
    f32 d;
    f32 n;

    p[6]++;
    q = *(u8 **)(p + 0x1DC);
    a = *(f32 *)(p + 0x34);
    b = *(f32 *)(q + 0x34);
    d = b - a;
    func_00178F20(p, q);
    q = *(u8 **)(p + 0x1DC);
    n = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x34) = a;
    q = *(u8 **)(p + 0x1DC);
    n = n - d;
    *(f32 *)(q + 0x34) = b;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    q = *(u8 **)(p + 0x1DC);
    *(int *)(q + 0x5C) = 0;
    q = *(u8 **)(p + 0x1DC);
    *(int *)(q + 0x60) = 0;
    q = *(u8 **)(p + 0x1DC);
    *(int *)(q + 0x68) = 0;
    q = *(u8 **)(p + 0x1DC);
    *(int *)(q + 0x6C) = 0;
    n = n / 16.0f;
    q = *(u8 **)(p + 0x1DC);
    *(f32 *)(q + 0x5C) = n;
    *(f32 *)(p + 0x5C) = -n;
    *(s16 *)(p + 0x1C) = 0x10;
}
