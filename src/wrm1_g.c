typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z; } V3;

extern V3 D_0043F180;
extern s32 D_004B1160[];
extern u32 D_004C2830;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00136A10();

u8 *func_00136830(u8 **out)
{
    u8 *o;
    u8 *first;
    u8 i;

    if ((first = func_003DA750(0, 6, 1)) == 0) return first;
    first[0x13C] = 1;
    *(void **)(first + 0x10) = func_00136A10;
    *(s16 *)(first + 0xCC) = 0;
    *(u32 *)(first + 0x84) = D_004C2830;
    *(V3 *)(first + 0x34) = D_0043F180;
    *(u32 *)(first + 0x44) = 0x8000;
    *(u32 *)(first + 0xD0) = 0x800805;
    *(f32 *)(first + 0x74) = 0.699999988079071f;
    *(f32 *)(first + 0x78) = 1.0f;
    *(f32 *)(first + 0x7C) = 1.0f;
    *(f32 *)(first + 0x80) = 1.0f;
    *(u32 *)(first + 0xDC) = 0;
    for (i = 1; i < 0x20; i++) {
        if ((o = func_003DA750(0, 6, 1)) == 0) return o;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00136A10;
        *(s16 *)(o + 0xCC) = 0;
        *(u32 *)(o + 0x84) = D_004C2830;
        *(V3 *)(o + 0x34) = D_0043F180;
        *(u32 *)(o + 0xD0) = 0x800805;
        *(u32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)(11.25f * (f32)D_004B1160[i - 1]) / 360.0) & 0xFFFF;
        *(u32 *)(o + 0xDC) = 0;
    }
    *out = first;
    return o;
}
