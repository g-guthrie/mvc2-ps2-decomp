#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { s32 w[0x31]; } W31;
typedef struct { f32 x, y, z; } V3;

extern void func_00175670(u8 *);
extern f64 func_00119058(f32);
extern f64 func_00119858(f64, f64);
extern f32 func_00119C90(f64);

void residual_001AD450(u8 *p)
{
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        p[5]++;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        *(f32 *)(p + 0x60) = func_00119C90(-func_00119858(func_00119058(*(f32 *)(p + 0x60)), 2.0));
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 2.0f;
        *(s16 *)(p + 0x1C) = 0x30;
    }
}
