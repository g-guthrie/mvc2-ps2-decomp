typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh SRC "-O3 -Op -fp off -sdatathreshold 8"
   FAILED (best honest attempt): 4 words differ, temp-register naming only
   ($a1/$a2 where retail has $a2/$a3 for the 0x800021 constant and the
   D_004C2838 load). Retail's register choice comes from earlier soft-float
   code in its object file, but no retail function before func_00159840 in
   address order (back to 0x001589A0) uses soft float, so no honest static
   prefix reproduces it. */
typedef struct { f32 x, y, z; } V3;

extern V3 D_00444D20;
extern s32 D_004C2838;
extern u8 *func_003DA750(s32, s32, s32);

void func_00159840(V3 *pos, s32 idx) {
    u8 *o;
    u32 ang;
    extern void func_001597D0();
    extern f32 func_00417440(u16);
    extern f32 func_00417500(u32);
    extern s32 func_00417A40();
    if ((o = func_003DA750(0, 0x21, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_001597D0;
        *(s16 *)(o + 0xCC) = 0x46;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(s32 *)(o + 0xD0) = 0x800021;
        *(V3 *)(o + 0x34) = *pos;
        *(V3 *)(o + 0x50) = D_00444D20;
        ang = (u32)(s32)(0.5 + 65536.0 * (f64)(idx * 36) / 360.0) & 0xFFFF;
        *(f32 *)(o + 0x5C) = 10.0f * func_00417440(ang);
        *(f32 *)(o + 0x60) = (f32)(func_00417A40() % 20 + 30);
        *(f32 *)(o + 0x64) = 10.0f * func_00417500(ang);
        *(f32 *)(o + 0x68) = -*(f32 *)(o + 0x5C) / 30.0f;
        *(f32 *)(o + 0x6C) = -*(f32 *)(o + 0x60) / 30.0f;
        *(f32 *)(o + 0x70) = -*(f32 *)(o + 0x64) / 30.0f;
        *(f32 *)(o + 0x74) = 1.0f;
    }
}
