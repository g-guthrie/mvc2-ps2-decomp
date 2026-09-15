typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct {
    f32 x, y, z;
} V3;

extern f32 D_004F1F4C;
extern f32 D_004F1FE8;
extern f32 D_004F1FE0;
extern f32 D_004F1FD8;
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

f32 func_003DE590(V3 *a, V3 *b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

void func_00361900(u8 *d, u8 *s)
{
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34);
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38);
    *(f32 *)(d + 0x3c) = *(f32 *)(s + 0x3c);
    *(s32 *)(d + 0x50) = 0x3f99999a;
    *(f32 *)(d + 0x34) += *(f32 *)(d + 0x5c);
}

void func_002BD610(u8 *p, u8 *q)
{
    *(f32 *)(q + 4) = D_004F1F4C - *(f32 *)(p + 0x34);
    *(f32 *)(q + 8) = D_004F1FE8 - *(f32 *)(p + 0x38);
}

void func_00374CD0(u8 *p)
{
    s8 *q;

    q = *(s8 **)(p + 0x18);
    if (q[0x151] != 0) {
        p[5]++;
        q[0x151] = 0;
        p[0x13c] = 1;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    }
}

s32 func_0037BD80(u8 *p)
{
    return *(f32 *)(p + 0x38) >= D_004F1FE0;
}

void func_00336A00(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    if (*(f32 *)(p + 0x34) <= D_004F1FD8) {
        p[0x13c] = 0;
        p[4]++;
    }
}

f32 func_001A8CB0(u8 *p)
{
    if (*(s16 *)(p + 0x140) == 0)
        return *(f32 *)(p + 0x34) - D_004F1FC8;
    return D_004F1FCC - *(f32 *)(p + 0x34);
}

