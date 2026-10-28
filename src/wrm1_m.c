typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* sd4_c: unmatched without a static prefix (off by $a0/$a2 temps). */

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


typedef struct { f32 x, y, z; } V3;
extern V3 D_00460560[];
extern f32 D_00460590[];
extern f32 D_00460594[];
extern f32 D_00460598[];
extern V3 D_004605C8;
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00341C20();

void func_003419F0(u8 *a, s32 n) {
    u8 *o;
    V3 *q;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00341C20;
        *(s16 *)(o + 0xCC) = n * 2 + 9;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_00460560[n];
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= *(f32 *)((u8 *)D_00460590 + n * 12)) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)((u8 *)D_00460594 + n * 12) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)((u8 *)D_00460598 + n * 12) / 360.0) & 0xFFFF;
        *(V3 *)(o + 0x50) = D_004605C8;
        *(s32 *)(o + 0xD0) = 0x80081F;
        o[0x20] = n;
        *(s16 *)(o + 0x1C) = n * 60;
        *(s16 *)(o + 0x1E) = n * 60;
        *(s32 *)(o + 0xD4) = n << 12;
        *(s32 *)(o + 0xD8) = (n * 3) << 12;
        *(s32 *)(o + 0xDC) = (n * 5) << 12;
        *(u8 **)(o + 0x14) = a;
    }
}
