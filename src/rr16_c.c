typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;

extern void *D_004C2838;
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

/* Provisional: this unrelated duplicate affects compiler allocation. */
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


void func_001551A0(f32 *pos, u32 n, f32 scale, int type) {
    extern u8 *func_003DA750(s32, u8, s32);
    extern void func_001553B0(u8 *);
    extern s32 func_00417A40();
    extern f32 func_00417440(u32);
    extern f32 func_00417500(u32);
    extern f32 func_00417F60();
    u8 *o;
    u16 ang;
    f32 k, r, t;
    if ((o = func_003DA750(0, ((u8)type == 9) ? 0x18 : 0x3C, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_001553B0;
        *(s16 *)(o + 0xCC) = func_00417A40() % 3 + 0x60;
        *(void **)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *(V3 *)pos;
        ang = (u16)(s32)(0.5 + 65536.0 * (double)(11.25f * (f32)n) / 360.0);
        k = 0.5f * func_00417440(ang);
        r = func_00417F60();
        *(f32 *)(o + 0x5C) = scale * (r - 0.5f + k);
        k = func_00417F60() - 0.5f;
        t = func_00417500(ang);
        *(f32 *)(o + 0x60) = scale * (k + 0.5f * t);
        *(f32 *)(o + 0x64) = scale * (0.5f * func_00417F60());
        *(f32 *)(o + 0x68) = -*(f32 *)(o + 0x5C) / 30.0f;
        *(f32 *)(o + 0x6C) = -*(f32 *)(o + 0x60) / 30.0f;
        *(f32 *)(o + 0x70) = -*(f32 *)(o + 0x64) / 30.0f;
        *(s32 *)(o + 0x74) = 0x3F800000;
        *(s32 *)(o + 0xD0) = 0x21;
    }
}
