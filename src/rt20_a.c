typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh src/rt20_a.c "-O3 -Op -fp off -sdatathreshold 8" */

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

typedef struct { f32 x, y, z; } V3;
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

void func_003388E0(u8 *a) {
    u8 *o;
    V3 *q;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00338570;
        *(s16 *)(o + 0xCC) = 10;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x803;
        *(V3 *)(o + 0x34) = D_004B80B8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B80A0[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B80A4[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
    }
}


void func_00338FE0(u8 *a) {
    u8 *o;
    V3 *q;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00338C70;
        *(s16 *)(o + 0xCC) = 14;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B80E8;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B8100[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B8104[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
    }
}

void func_001449E0(s32 a) {
    u8 *o;
    V3 *q;
    s32 t;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        t = 1; if (a < 7) t = 0;
        o[0x13C] = 1;
        o[0x20] = a;
        *(void **)(o + 0x10) = func_00144BF0;
        o[0x22] = D_004B3368[a];
        q = &D_004B3200[a * 2];
        *(s16 *)(o + 0xCC) = o[0x22];
        *(s32 *)(o + 0x84) = D_004C2808;
        *(V3 *)(o + 0x34) = *q;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B3350 + t * 12) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B3354 + t * 12) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)*(f32 *)((u8 *)D_004B3358 + t * 12) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0xD0) = 0x813;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(f32 *)(o + 0x50) = 0.10000000149011612f;
        *(f32 *)(o + 0x54) = 0.10000000149011612f;
        *(f32 *)(o + 0x58) = 0.10000000149011612f;
        if (a < 2) func_00170DF0((u32)*(s32 *)(o + 0x84));
    }
}

