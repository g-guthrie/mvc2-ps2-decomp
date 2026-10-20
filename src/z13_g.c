typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef double f64;
typedef struct { f32 x, y, z; } Float3;
typedef struct { f32 a[4]; } V4;
extern V4 D_00442A10;
extern Float3 D_00442980[];
extern Float3 D_00442890;
extern s32 D_004C2804;

void func_001471A0(u8 *p)
{
    extern f64 func_00119058(f32);
    V4 tab;
    tab = D_00442A10;
    p[4]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0xCC) = 0x43;
    *(s32 *)(p + 0x84) = D_004C2804;
    *(Float3 *)(p + 0x34) = D_00442980[p[0x20]];
    *(Float3 *)(p + 0x50) = D_00442890;
    *(s32 *)(p + 0x48) = (u16)((u32)(s32)(func_00119058(tab.a[p[0x20]]) * 65536.0 / 360.0 + 0.5));
}
