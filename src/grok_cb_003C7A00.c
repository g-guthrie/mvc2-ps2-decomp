typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);
extern void func_001E3210(u8 *, s32);

void residual_003C7A00(u8 *p, u8 *q)
{
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x68);
    f32 *c = (f32 *)(p + 0x60);
    f32 *d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))
        return;
    p[5]++;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *a = 0;
    *c = 0;
    *b = 0;
    *d = 0;
    func_001757E0(p, 0x14, 0x11);
    func_001E3210(q, 0x19);
}
