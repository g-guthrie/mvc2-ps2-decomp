typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern s32 func_003F13E0(s32 a);
extern s32 func_003F1470(s32 a, s32 b);
s32 func_003F16D0(s32 a, s32 b) {
    if (b >= func_003F13E0(a)) {
        return 0;
    }
    return func_003F1470(a, b) * 64 + 16;
}

extern void func_003DCDC0(s32 a, s32 b, s32 c, s32 d);
extern void func_003DD1D0(s32 a, s32 b, s32 c);
void func_00416110(s32 a, s32 b, s32 *c) {
    func_003DCDC0(b, a, c[5] * (c[1] * c[2]), c[1]);
    if (c[5] == 4) {
        func_003DD1D0(b, c[1], c[2]);
    }
}

extern double func_001001E0(u64 a);
double func_00100230(u32 a) {
    return func_001001E0((u64)a);
}
