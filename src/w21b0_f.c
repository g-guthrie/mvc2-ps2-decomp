typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3f;
extern f32 D_00444960[];
extern V3f D_00444970[];

void func_00154220(V3f *v, s32 a1, s32 a2) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00154190();
    extern f32 func_00417440(u16);
    extern f32 func_00417500(u16);
    extern s32 func_00417A40();
    u8 *o;
    u16 u;
    if ((o = func_003DA750(0, 0x13, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_00154190;
        *(s32 *)(o + 0xD0) = 0x800109;
        *(V3f *)(o + 0x34) = *v;
        u = (u16)(s32)((double)(a2 * 60) * 65536.0 / 360.0 + 0.5);
        *(f32 *)(o + 0x5C) = D_00444960[a1] * func_00417440(u);
        *(f32 *)(o + 0x64) = D_00444960[a1] * func_00417500(u);
        *(s32 *)(o + 0x48) = func_00417A40() % 0x4000;
        *(V3f *)(o + 0x50) = D_00444970[a1];
    }
}
