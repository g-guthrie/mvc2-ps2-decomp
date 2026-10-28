typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0: ./try30.sh SRC "-O3 -Op -fp off -sdatathreshold 8"
   The only static is func_00332580, the real retail function immediately
   before func_00332630 in address order (verified exact at its own address). */
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







extern double func_00119058(f32);

typedef struct P {
    u8 pad0[0x1C];
    s16 h1c;
    u8 pad1[0x40 - 0x1E];
    u32 w40;
    u32 w44;
    u8 pad2[0x54 - 0x48];
    f32 f54;
    u8 pad3[0xD4 - 0x58];
    s32 wd4;
} P;

/* Real address-order predecessor of func_00332630 (retail 0x00332580,
   matched globally in src/t7_e.c); verified exact at its own address. */
static s32 func_00332580(P *p) {
    p->h1c += 1;
    p->w40 += (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}
static s32 (*keep_00332580)(P *) = func_00332580;

extern V3 D_004B78A0;
extern f32 D_004B78B8[];
extern f32 D_004B78BC[];
extern f32 D_004B78C0[];

void func_00332630(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        extern void func_003320C0();
        extern void func_00331FE0(u8 *);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003320C0;
        *(s16 *)(o + 0xCC) = 6;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x803;
        *(V3 *)(o + 0x34) = D_004B78A0;
        *(u8 **)(o + 0xC8) = a + 0x88;
        *(u8 **)(o + 0x14) = a;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B78B8[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B78BC[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_004B78C0[0]) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xDC) = *(s32 *)(*(u8 **)(o + 0x14) + 0xDC);
        func_00331FE0(o);
    }
}
