typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;


typedef struct { f32 x, y, z; } V3;


extern V3 D_004B12A0;
extern f32 D_004B14A0[];
extern f32 D_004B14A4[];
extern f32 D_004B14A8[];
extern s32 D_004C282C;
extern u8 *D_004C2840;
extern u8 *func_003DA750(s32, s32, s32);

void func_0013D6F0(u8 a) {
    u8 *o;
    double k;
    extern void func_0013D8A0();
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        o[0x20] = a;
        *(void **)(o + 0x10) = func_0013D8A0;
        *(s16 *)(o + 0xCC) = 0;
        *(s32 *)(o + 0x84) = D_004C282C;
        *(V3 *)(o + 0x34) = D_004B12A0;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B14A0[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B14A4[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B14A8[0]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1C) = (*(s16 *)(D_004C2840 + 0x10) & 0x1F) + 1;
        *(s16 *)(o + 0x1E) = 0;
    }
}
