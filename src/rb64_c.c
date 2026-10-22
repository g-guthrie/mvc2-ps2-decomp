typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct DB {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x22];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
} DB;

extern f32 D_00583C48[];
extern f32 D_00583C4C[];
extern f32 D_00583C50[];

static void func_00338670(DB *p)
{
    p->h1c = p->h1c + 1;
    if (p->h1c > 150) {
        p->b4 = 0;
        p->h1c = 0;
        return;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f5c / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f60 / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f64 / 360.0) & 0xFFFF;
    p->w40 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C48[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C4C[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w48 += (u32)(s32)(0.5 + 65536.0 * (f64)(D_00583C50[0] * (f32)p->h1c) / 360.0) & 0xFFFF;
}
static void (*keep_00338670)(DB *) = func_00338670;

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
