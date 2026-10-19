typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void residual_002A2750(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x12;
        p[0x151] = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -15.0f : 15.0f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? 0.4166666567325592f : -0.4166666567325592f;
        *(f32 *)(p + 0x60) = 10.714284896850586f;
        *(f32 *)(p + 0x6C) = -1.0714285373687744f;
    }
}
