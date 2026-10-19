typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_001E3710(u8 *, int);
extern void func_00154390(f32 *, int);

void func_001B2D00(u8 *p)
{
    f32 tmp[3];
    s16 t;
    u8 *q;
    {
        f32 v;
        v = *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x38) += v;
        v = *(f32 *)(p + 0x6C);
        *(f32 *)(p + 0x60) += v;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t > 0) {
        f32 a;
        a = *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x34) += a;
    }
    q = *(u8 **)(p + 0x18);
    if (!(*(f32 *)(q + 0x38) <= *(f32 *)(p + 0x38))) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
        tmp[0] = *(f32 *)(p + 0x34);
        tmp[1] = *(f32 *)(p + 0x38);
        tmp[2] = *(f32 *)(p + 0x3C);
        func_001E3710(p, 0x34);
        func_00154390(tmp, 0);
    }
}
