typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern void func_00423750(void);

f32 func_00404CC0(void) { return 0.0f; }

s32 func_0040F1D0(s32 *p)
{
    s32 v = p[6];
    p[4] = 0;
    p[3] = v;
    return v;
}

s32 func_0040F728(s32 *p)
{
    s32 v = p[8];
    p[13] = 0;
    p[4] = v;
    p[3] = 0;
    p[5] = 0;
    p[6] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    return v;
}

s32 func_00419FC0(void)
{
    func_00423750();
    return 1;
}

void func_0041DB80(void)
{
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
}
