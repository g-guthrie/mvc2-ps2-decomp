typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004C283C;
extern u8 D_004C27D0;

typedef struct { f32 a, b, c; } V3;
extern V3 D_0045EB70[];

void func_0033AEE0(u8 *owner, s32 idx)
{
    extern u8 *func_003DA750(void *, s32, s32);
    extern void func_0033AED0(u8 *);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern double litodp(s32);
    extern double dpmul(double, double);
    extern double dpdiv(double, double);
    extern double dpadd(double, double);
    extern u32 dptoul(double);
    u8 *p;
    u16 ang;

    if ((p = func_003DA750(0, 6, 1)) != 0) {
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_0033AED0;
        *(s16 *)(p + 0xCC) = 10;
        *(u32 *)(p + 0x84) = D_004C283C;
        ang = (u16)(s32)(0.5 + 65536.0 * (double)(idx * 30) / 360.0);
        *(f32 *)(p + 0x38) = 2730.0f * func_00417500(ang);
        *(f32 *)(p + 0x3C) = 2730.0f * func_00417440(ang);
        *(f32 *)(p + 0x78) = D_0045EB70[idx].a;
        *(f32 *)(p + 0x7C) = D_0045EB70[idx].b;
        *(f32 *)(p + 0x80) = D_0045EB70[idx].c;
        if (D_004C27D0 == 12) {
            *(f32 *)(p + 0x78) *= 0.2f;
            *(f32 *)(p + 0x7C) *= 0.2f;
            *(f32 *)(p + 0x80) *= 0.2f;
            *(f32 *)(p + 0x78) += 0.45f;
            *(f32 *)(p + 0x7C) += 0.55f;
            *(f32 *)(p + 0x80) += 0.6f;
        }
        *(u32 *)(p + 0xD0) = 0xC03;
        *(u8 **)(p + 0xC8) = owner + 0x88;
    }
}
