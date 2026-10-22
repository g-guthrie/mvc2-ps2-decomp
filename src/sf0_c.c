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


extern u8 *D_004C2840;

void func_00145780(u8 *p)
{
    extern void func_003DAA40(u8 *);
    u8 *q;
    if (*(s8 *)(D_004C2840 + 2) != 3) {
        func_003DAA40(p);
        return;
    }
    q = *(u8 **)(p + 0x18);
    if (q[6] == 0) {
        if (*(s16 *)(q + 0x1C) == 0 && *(s16 *)(q + 0x1E) <= 10) {
            p[0x13C] = 1;
            if (*(s16 *)(p + 0x1C) == 0) {
                *(V3 *)(p + 0x34) = *(V3 *)(p + 0x50);
                *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)(p + 0x5C) / 360.0) & 0xFFFF;
                *(s16 *)(p + 0x1C) = p[0x23] + 1;
                *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
                *(f32 *)(p + 0x5C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x5C);
            } else {
                *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
            }
        } else {
            p[0x13C] = 0;
            *(s16 *)(p + 0x1C) = 0;
            *(f32 *)(p + 0x5C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x5C);
        }
    } else {
        p[0x13C] = 0;
    }
}
