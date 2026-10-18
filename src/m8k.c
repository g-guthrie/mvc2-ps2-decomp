typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern f64 func_00119058(f32 x);
extern s32 func_00334440(void *p);

void func_003343B0(u8 *p) {
    *(u32 *)(p + 0x44) = (u16)(func_00119058(*(f32 *)(p + 0x6C)) * 65536.0 / 360.0 + 0.5);
    if (func_00334440(p)) {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 1;
    }
}
