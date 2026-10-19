typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00175580(u8 *, int, int);

void func_00198FC0(u8 *p)
{
    u8 *self = p;
    u8 *q = *(u8 **)(self + 0x18);
    s8 t = *(s8 *)(q + 0x161);
    if (t == 0) {
        self[0x13C] = 0;
        *(s16 *)(self + 0x1C) = 0;
        return;
    }
    self[0x13C] = 1;
    *(V3 *)(self + 0x34) = *(V3 *)(q + 0x34);
    *(s16 *)(self + 0x140) = *(s16 *)(q + 0x140);
    *(f32 *)(self + 0x118) = *(f32 *)(q + 0x118);
    *(f32 *)(self + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(self + 0x54) = *(f32 *)(q + 0x54);
    if (t < 0) {
        *(f32 *)(self + 0x38) = *(f32 *)(q + 0x430);
        t = (s8)(t & 0x7F);
    }
    if (*(s16 *)(self + 0x1C) != t) {
        func_00175580(self, 0x1B, (u8)(self[0x22] + 1));
        *(s16 *)(self + 0x1C) = t;
    }
}
