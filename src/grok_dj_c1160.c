typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00175580(u8 *, int, int, int);

void func_001C1160(u8 *p, u8 *q)
{
    s32 off;
    s16 face;
    f32 three = 3.0f;

    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    face = *(s16 *)(q + 0x140);
    off = face ? -20 : 20;
    *(f32 *)(p + 0x34) += (f32)off;
    *(f32 *)(p + 0x38) += three;
    face = *(s16 *)(q + 0x140) ^ 1;
    *(s16 *)(p + 0x140) = face;
    if (face != 0)
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    else
        *(f32 *)(p + 0x34) -= *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(s8 *)(q + 0x151) == 0)
        p[4]++;
    else
        func_00175580(p, 0x1B, 0x2A, *(s8 *)(q + 0x151) & 0xF);
}
