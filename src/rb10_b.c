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
extern V3 D_0045F9E0[];
extern f32 D_0045FA04[];
extern u8 D_004C2A40[8];
extern u8 D_004C2A41, D_004C2A42, D_004C2A43;
extern s32 D_004C283C;

void func_0033FE10(s32 a)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern s32 func_0010FC98(u8 *);
    extern void func_003D7220(u8 *);
    extern void func_0033FCE0();
    u8 *o;

    if ((o = func_003DA750(0, 6, 0)) != 0) {
        if (func_0010FC98(D_004C2A40) == 0) {
            D_004C2A43 = 0;
            D_004C2A42 = 0;
            D_004C2A41 = 0;
        }
        func_003D7220(D_004C2A40);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033FCE0;
        *(s16 *)(o + 0xCC) = a + 9;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_0045F9E0[a];
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (f64)*(f32 *)((u8 *)D_0045FA04 + a * 12) / 360.0) & 0xFFFF;
        o[0x20] = a;
    }
}
