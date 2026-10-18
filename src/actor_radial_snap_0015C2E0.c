typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004D18CC[];
extern u8 D_004D18A0[];
extern f32 D_004F1FD4[];

void func_0015C2E0(u8 *p)
{
    u8 *o;
    u32 c;

    o = D_004D18CC[0];
    p[0x13C] = 0;
    if (o[0] != 0 && o[0x269] == 8 && D_004D18A0[0] == 4 && *(s8 *)(o + 0x13C) != 0)
        p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    c = o[0x14C];
    *(f32 *)(p + 0x38) += 2.142857f * (f32)c * *(f32 *)(o + 0x54);
    *(f32 *)(p + 0x38) += 100.0f;
    *(f32 *)(p + 0x3C) += 3.0f;
    if (*(f32 *)(p + 0x38) <= 100.0f + D_004F1FD4[0])
        *(f32 *)(p + 0x38) = 100.0f + D_004F1FD4[0];
}
