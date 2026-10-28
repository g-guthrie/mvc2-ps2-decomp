typedef unsigned char u8;
typedef signed int s32;
typedef float f32;
typedef struct { s32 x0, x4, x8, xc, x10; f32 x14; } V24;
extern V24 D_004F8040;
extern V24 D_004F8020;
void func_00413E60(void)
{
    extern f32 func_003DE7D0(f32);
    extern f32 func_003DE6F0(f32);
    extern void func_003DD2E0(s32, f32, f32, f32, f32);
    extern void func_003DF850();
    f32 a, b;
    a = func_003DE7D0(0.37524578f);
    b = 2.0f * func_003DE6F0(240.0f / (320.0f / a));
    func_003DD2E0(0x20, 3000.0f, 1.0f, b, 1.0f);
    D_004F8040.x0 = 0;
    D_004F8040.x8 = 640;
    D_004F8040.xc = 480;
    D_004F8040.x14 = 1.0f;
    D_004F8040.x4 = 0;
    D_004F8040.x10 = 0;
    D_004F8020 = D_004F8040;
    func_003DF850(0x18, &D_004F8040);
}
