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


typedef struct XB {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 b20;
    u8 _p1[0x1F];
    u32 w40;
    u8 _p2[4];
    u32 w48;
    u8 _p3[0x2C];
    f32 f78;
    f32 f7c;
    f32 f80;
} XB;

extern u8 D_004C27D0;
extern f32 func_00417440(u16);
extern f32 func_00417500(u16);

void func_0033B1A0(XB *p)
{
    f32 r;
    if (p->h1c >= 0x2D0) {
        p->h1c = 0;
    }
    if (p->h1e >= 0x438) {
        p->h1e = 0;
    }
    r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1c / 2.0f + (f32)(p->b20 * 90)) / 360.0));
    p->w40 = (u16)(s32)(0.5 + 65536.0 * (f64)(20.0f * r) / 360.0);
    r = func_00417500((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1c / 2.0f + (f32)(p->b20 * 90)) / 360.0));
    p->w48 = (u16)(s32)(0.5 + 65536.0 * (f64)(60.0f * r) / 360.0);
    if (D_004C27D0 == 3) {
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1e / 3.0f) / 360.0));
        p->f78 = 0.5f + 0.5f * r;
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1e / 2.0f) / 360.0));
        p->f7c = 0.5f + 0.5f * r;
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)p->h1e / 360.0));
        p->f80 = 0.5f + 0.5f * r;
    } else {
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1e / 3.0f) / 360.0));
        r = 0.1f * r; p->f78 = 0.5f + r;
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1e / 2.0f) / 360.0));
        r = 0.1f * r; p->f7c = 0.5f + r;
        r = func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)p->h1e / 360.0));
        r = 0.1f * r; p->f80 = 0.5f + r;
    }
    p->h1c++;
    p->h1e++;
}
