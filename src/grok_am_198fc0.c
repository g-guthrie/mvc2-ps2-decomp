typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00175580(u8 *, s32, s32);

void func_00198FC0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    s8 t = *(s8 *)(q + 0x161);
    s16 u;
    if (t == 0)
        return;
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(f32 *)(p + 0x118) = *(f32 *)(q + 0x118);
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    if (t < 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        t = (s8)(t & 0x7F);
    }
    u = t;
    if (*(s16 *)(p + 0x1C) != u) {
        func_00175580(p, 0x1B, (u8)(p[0x22] + 1));
        *(s16 *)(p + 0x1C) = u;
    } else {
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0;
    }
}
