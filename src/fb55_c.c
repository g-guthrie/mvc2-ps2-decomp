typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct DS {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    s16 h1e;
    u8 _p2[0x20];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x2C];
    f32 f78;
    f32 f7c;
    f32 f80;
} DS;

extern f32 D_0045EC74[];

void func_0033BF80(DS *p)
{
    extern f32 func_00417440(u32);
    extern s32 func_00417A40();
    f64 k;

    p->h1c = p->h1c + 1;
    if (p->h1c >= 0x438) {
        p->h1c = 0;
    }
    p->f78 = 0.5f + 0.5f * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1c / 3.0f) / 360.0) & 0xFFFF);
    p->f7c = 0.5f + 0.5f * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)((f32)p->h1c / 2.0f) / 360.0) & 0xFFFF);
    p->f80 = 0.5f + 0.5f * func_00417440((u32)(s32)(0.5 + 65536.0 * (f64)p->h1c / 360.0) & 0xFFFF);
    p->h1e = p->h1e + 1;
    if (p->h1e >= 0x258) {
        p->h1e = 0;
        p->b4 = func_00417A40() % 3;
        if (p->b4 == 0) {
            p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)(180.0f + D_0045EC74[0]) / 360.0) & 0xFFFF;
        } else {
            k = 65536.0;
            p->w44 = (u32)(s32)(0.5 + k * (f64)D_0045EC74[0] / 360.0) & 0xFFFF;
        }
    }
}
