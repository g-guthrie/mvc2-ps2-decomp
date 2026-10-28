typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } V3;

extern s8 D_004D1900;

void func_0015C610(V3 *p, s32 a1, s32 a2, u32 n, s32 e) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0015C740();
    u8 *o;
    if ((o = func_003DA750(0, e, 1)) != 0) {
        D_004D1900++;
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_0015C740;
        *(V3 *)(o + 0x34) = *p;
        o[0x23] = e;
        *(s32 *)(o + 0x48) = ((u32)(s32)(0.5 + 65536.0 * (double)(11.25f * (f32)n) / 360.0) & 0xFFFF) + 0xC000;
        *(s32 *)(o + 0xD0) = 0x800189;
    }
}
