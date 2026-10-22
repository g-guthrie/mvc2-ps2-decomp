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

static void (*keep_00338670)(DB *) = func_00338670;
typedef struct { f32 x, y, z; } V3;

extern s8 D_004D1900;

void func_0015C610(V3 *p, s32 a1, s32 a2, u32 n, s32 e) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0015C740();
    u8 *o;
    if ((o = func_003DA750(0, e, 1)) != 0) {
        D_004D1900++;
        o[0x13C] = 0;
        *(void **)(o + 0x10) = (void *)func_0015C740;
        *(V3 *)(o + 0x34) = *p;
        o[0x23] = e;
        *(s32 *)(o + 0x48) = ((u32)(s32)(0.5 + 65536.0 * (double)(11.25f * (f32)n) / 360.0) & 0xFFFF) + 0xC000;
        *(s32 *)(o + 0xD0) = 0x800189;
    }
}
