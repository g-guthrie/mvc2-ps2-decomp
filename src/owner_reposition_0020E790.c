typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 D_004F1F4C __attribute__((section(".bss")));
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_00351AE0(u8 *, u8);

void func_0020E790(u8 *p)
{
    p[0x208] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);

    if ((s8)func_00175700(p) < 0) {
        u32 count = p[6];
        p[6] = count + 1;
        if (p[0x269] == 8 || p[0x269] == 3) {
            *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x220) + 0x34);
        } else {
            *(f32 *)(p+0x34) = (f32)(((f64)D_004F1F4C - 320.0) + (f64)(p[0x1B7] ? 640.0f : 213.3333282470703125f));
        }

        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00351AE0(p, 1);
        {
            f32 horizontalOffset;
            if (p[0x1E6] != 0)
                horizontalOffset = -133.3333282470703125f;
            else
                horizontalOffset = 133.3333282470703125f;
            *(f32 *)(p + 0x34) += horizontalOffset;
        }
        *(f32 *)(p + 0x38) += 342.85711669921875f;
        func_001757E0(p, 0x15, 0x2F);
    }
}
