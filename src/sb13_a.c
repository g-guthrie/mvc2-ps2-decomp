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

extern V3 D_004B80B8;
extern V3 D_004B3200[];
extern f32 D_004B3350[];
extern f32 D_004B3354[];
extern f32 D_004B3358[];
extern s8 D_004B3368[];
extern s32 D_004C2808;
extern void func_00144BF0();
extern void func_00170DF0(s32);
extern f32 D_004B80A0[];
extern f32 D_004B80A4[];
extern s32 D_004C283C;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_00338570();
extern void func_00338C70();
extern V3 D_004B80E8;
extern f32 D_004B8100[];
extern f32 D_004B8104[];

static void func_00338FE0(u8 *a) {
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

static void func_003388E0(u8 *a) {
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



extern V3 D_004B8118;
extern f32 D_004B8130[];
extern f32 D_004B8134[];

void func_003394A0(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        extern void func_00339130();
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00339130;
        *(s16 *)(o + 0xCC) = 15;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_004B8118;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B8130[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_004B8134[0]) / 360.0) & 0xFFFF;
    }
}

extern V3 D_004B7A40;
extern f32 D_004B7A54[];

void func_00333470(u8 *a) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        extern void func_00333000();
        extern void func_00332B90(u8 *);
        extern void func_00331D10(u8 *);
        extern void func_00331820(u8 *);
        extern void func_00332630(u8 *);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00333000;
        *(s16 *)(o + 0xCC) = 3;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x803;
        *(V3 *)(o + 0x34) = D_004B7A40;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_004B7A54[0]) / 360.0) & 0xFFFF;
        *(u8 **)(o + 0x14) = a;
        *(u8 **)(o + 0xC8) = a + 0x88;
        func_00332B90(o);
        func_00331D10(o);
        func_00331820(o);
        func_00332630(o);
    }
}

extern V3 D_0045F968;
extern f32 D_0045F978[];
extern f32 D_0045F97C[];
extern f32 D_0045F980[];

void func_0033F890(void) {
    u8 *o;
    double k;
    if ((o = func_003DA750(0, 6, 0)) != 0) {
        extern void func_0033F790();
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033F790;
        *(s16 *)(o + 0xCC) = 6;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(V3 *)(o + 0x34) = D_0045F968;
        k = 65536.0;
        *(s32 *)(o + 0x40) = (u32)(s32)(0.5 + (k *= D_0045F978[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + (k *= D_0045F97C[0]) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + (k *= D_0045F980[0]) / 360.0) & 0xFFFF;
    }
}
