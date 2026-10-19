typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void residual_001FEA20(u8 *p)
{
    if (p[0x15B])
        *(f32 *)(p + 0x38) += 1.0714285373687744f;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(unsigned int *)(p + 0x60) = 0x3F892492;
        *(unsigned int *)(p + 0x6C) = 0xBD892492;
    }
}
