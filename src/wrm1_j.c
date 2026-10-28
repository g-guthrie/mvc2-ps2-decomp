typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* sd6_a: MW 3.0.3: ./try.sh SRC "-O3 -Op -fp off -sdatathreshold 8"
   Unmatched without a static prefix: off by $a0/$a2 temps (file-position
   effect). The honest predecessor run (0033AEE0..0033B1A0) needs 3.0 for
   func_0033B0E0's padded loop and 3.0.3 for func_0033AEE0. */
typedef struct { f32 x, y, z; } V3;
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


extern V3 D_004B80B8;
extern V3 D_004B3200[];
extern f32 D_004B3350[];
extern f32 D_004B3354[];
extern f32 D_004B3358[];
extern s8 D_004B3368[];
extern s32 D_004C2808;
extern void func_00144BF0();
extern void func_00170DF0(u32);
extern f32 D_004B80A0[];
extern f32 D_004B80A4[];
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00338570();
extern void func_00338C70();
extern V3 D_004B80E8;
extern f32 D_004B8100[];
extern f32 D_004B8104[];






extern V3 D_0045EC00[];
extern f32 D_0045EC34[];
extern void func_0033B1A0();

void func_0033B6E0(s32 a) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033B1A0;
        *(s16 *)(o + 0xCC) = a + 0x16;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(V3 *)(o + 0x34) = D_0045EC00[a];
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)D_0045EC34[a * 3] / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0x800C0B;
        o[0x20] = a;
        *(s16 *)(o + 0x1E) = a * 270;
    }
}
