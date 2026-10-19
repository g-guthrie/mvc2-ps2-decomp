typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

extern void func_00170DF0(u32);
extern f64 func_00119568(f64, f64);
extern f32 func_00119C90(f64);

void residual_00151120(u8 *p)
{
    switch (p[4]) {
    case 0:
        p[4] = p[4] + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        func_00170DF0(*(u32 *)(p + 0x84));
        break;
    case 1:
        *(s16 *)(p + 0x1C) = (s16)(*(s16 *)(p + 0x1C) + 1);
        if (*(s16 *)(p + 0x1C) >= 0x3E8)
            *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = (s16)(*(s16 *)(p + 0x1E) + 1);
        if (*(s16 *)(p + 0x1E) >= 0x3E8)
            *(s16 *)(p + 0x1E) = 0;
        *(u32 *)(p + 0xD0) |= 0x20000;
        *(f32 *)(p + 0xE0) = func_00119C90(func_00119568(1.0, *(s16 *)(p + 0x1C) * 0.0012566370614359172));
        *(f32 *)(p + 0xE4) = func_00119C90(func_00119568(1.0, *(s16 *)(p + 0x1E) * 0.0012566370614359172));
        break;
    }
}
