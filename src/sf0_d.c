typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0.3: ./try.sh SRC "-O3 -Op -fp off -sdatathreshold 8"
   The three static functions below are verified copies of retail
   func_00338670/func_00338FE0/func_003388E0 (same flags); they prime the
   register allocator exactly as in src/rt20_a.c. */
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
