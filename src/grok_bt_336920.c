typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;

extern u32 func_00174170(void);
extern f32 D_004F1FDC;

void residual_00336920(u8 *p)
{
    f32 r = (f32)(func_00174170() % 0x96u);
    *(f32 *)(p + 0x34) = D_004F1FDC + r;
    {
        u32 t = p[4];
        p[4] = t + 1;
    }
    *(f32 *)(p + 0x5C) = -5.0f;
    r = (f32)(func_00174170() % 10u);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) - r;
}
