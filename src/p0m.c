typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f32 func_003DE7D0(f32);
extern f64 litodp(long long);
f32 func_004175C0(u16 a) {
    return func_003DE7D0((f32)((6.283185307179586 * litodp(a)) / 65536.0));
}

extern s32 func_003F1410(u8 *, s32);
extern s32 func_003F14A0(u8 *, s32);
s32 func_003F1470(u8 *file, s32 index) {
    return func_003F14A0(file, func_003F1410(file, index));
}

