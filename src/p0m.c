typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern void func_003DE7D0(f32);
extern f64 litodp(long long);
void func_004175C0(u16 a) {
    func_003DE7D0((f32)((6.283185307179586 * litodp(a)) / 65536.0));
}

extern s32 func_003F1410(void *);
extern void func_003F14A0(void *, s32);
void func_003F1470(void *a0) {
    func_003F14A0(a0, func_003F1410(a0));
}

