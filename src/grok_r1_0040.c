typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 func_00423750(s32);

f32 func_00404CC0(void) { return 0.0f; }

s32 func_00419FC0(s32 wait)
{
    func_00423750(wait);
    return 1;
}

void func_0041DB80(void)
{
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
}
