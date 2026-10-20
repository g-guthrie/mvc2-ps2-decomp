typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern f32 D_00444960[];
extern f32 D_00444970[];
extern s16 *D_00444940[];
extern s32 D_004C2838;

void func_00153F70(f32 *a, s32 b, s32 c) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00153EB0();
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern s32 func_00417A40();
    u8 *o;
    u16 ang;
    s32 v;
    f32 *r, *k;
    f32 t;
    if ((o = func_003DA750(0, 0x2B, 1)) != 0) {
        o[0x13C] = 1;
        *(s32 *)(o + 0x10) = (s32)func_00153EB0;
        *(s32 *)(o + 0xD0) = 0x800119;
        *(V3 *)(o + 0x34) = *(V3 *)a;
        ang = (u16)((u32)(s32)((double)(c * 60) * 65536.0 / 360.0 + 0.5));
        t = func_00417440(ang);
        k = &D_00444960[b];
        *(f32 *)(o + 0x5C) = *k * t;
        *(f32 *)(o + 0x64) = *k * func_00417500(ang);
        v = func_00417A40() % 0x4000;
        *(s32 *)(o + 0x48) = v;
        r = &D_00444970[b * 3];
        *(V3 *)(o + 0x50) = *(V3 *)r;
        *(f32 *)(o + 0x50) *= 50.0f;
        *(f32 *)(o + 0x54) *= 50.0f;
        *(s16 *)(o + 0xCC) = D_00444940[0][*(s16 *)(o + 0x1C) * 2];
        *(s32 *)(o + 0x84) = D_004C2838;
        *(s16 *)(o + 0x1E) = 0;
    }
}
