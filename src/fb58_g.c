typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct DS37 {
    u8 _p0[0x4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x5];
    u8 b23;
    u8 _p3[0x1C];
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p4[0x10];
    f32 f5c;
    f32 f60;
    f32 f64;
} DS37;

extern f32 D_00583BF0[];
extern f32 D_00583BF4[];
extern f32 D_00583BF8[];

void func_00337210(DS37 *p)
{
    p->h1c = p->h1c + 1;
    if (p->h1c > 100) {
        p->b4 = 0;
        p->h1c = 0;
        return;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f5c / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f60 / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f64 / 360.0) & 0xFFFF;
    p->w40 += (u32)(s32)(0.5 + 65536.0 * (f64)(*(f32 *)((u8 *)D_00583BF0 + p->b23 * 12) * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)(*(f32 *)((u8 *)D_00583BF4 + p->b23 * 12) * (f32)p->h1c) / 360.0) & 0xFFFF;
    p->w48 += (u32)(s32)(0.5 + 65536.0 * (f64)(*(f32 *)((u8 *)D_00583BF8 + p->b23 * 12) * (f32)p->h1c) / 360.0) & 0xFFFF;
}
