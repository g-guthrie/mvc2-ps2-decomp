typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern f32 D_0044B8B8[];
extern f32 D_0044B8D0[];
extern double func_00119B08(s32);
extern s32 dptoli(double);

void func_001ACBE0(f32 *a, s32 unused, s32 b, s32 c)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001ACB50();
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern s32 func_00417A40();
    u8 *o;
    u16 ang;
    s32 v;
    f32 *r, *k;
    f32 t;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(s32 *)(o + 0x10) = (s32)func_001ACB50;
        *(s32 *)(o + 0xD0) = 0x109;
        *(V3 *)(o + 0x34) = *(V3 *)a;
        ang = (u32)dptoli(0.5 + 65536.0 * func_00119B08(c * 60) / 360.0) & 0xFFFF;
        t = func_00417440(ang);
        k = &D_0044B8B8[b];
        *(f32 *)(o + 0x5C) = *k * t;
        *(f32 *)(o + 0x64) = *k * func_00417500(ang);
        v = func_00417A40() % 0x4000;
        *(s32 *)(o + 0x48) = v;
        r = &D_0044B8D0[b * 3];
        *(V3 *)(o + 0x50) = *(V3 *)r;
    }
}
