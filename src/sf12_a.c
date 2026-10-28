typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
typedef long long s64;
typedef __int128 s128;
typedef struct { s32 x[6]; } S24;
extern S24 D_004F8020 __attribute__((aligned(16)));
void func_004177A0(s32 ang, f32 a, f32 b, f32 c)
{
    extern void func_003DD2E0(s32, f32, f32, f32, f32);
    extern void func_003DF850();
    S24 loc __attribute__((aligned(16)));
    S24 *d;
    f32 r;
    double t;
    loc = D_004F8020;
    t = (s32)(u16)ang;
    t = 6.283185307179586 * t;
    t = t / 65536.0;
    r = (f32)t;
    func_003DD2E0(0x20, c, b, r, a);
    func_003DF850(0x18, (u32)&loc);
}
