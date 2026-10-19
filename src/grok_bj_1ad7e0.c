typedef unsigned char u8;
typedef signed short s16;
typedef float f32;
typedef double f64;

extern f64 func_00119058(f32);
extern f64 dpdiv(f64, f64);
extern f32 func_00119C90(f64);

void func_001AD7E0(u8 *p)
{
    u8 *q;
    f32 t;
    t = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += t;
    t = *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) += t;
    t = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x38) += t;
    t = *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x60) += t;
    q = *(u8 **)(p + 0x18);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(f32 *)(p + 0x60) = func_00119C90(-dpdiv(func_00119058(*(f32 *)(p + 0x60)), 2.0));
        *(s16 *)(p + 0x1C) = 0x30;
    }
}
