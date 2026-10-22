typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct QA {
    u8 _p0[4];
    u8 b4;
    u8 _p1[0x19];
    s16 h1e;
    u8 _p2[2];
} QA;

typedef struct P3B {
    u8 _p0[4];
    u8 b4;
    u8 _p1[0xF];
    QA *q14;
    u8 _p5[4];
    s16 h1c;
    u8 _p3[2];
    u8 b20;
    u8 _p4[0x23];
    u32 w44;
} P3B;

extern f32 D_004C1928[2];
extern f32 D_004C1930[2];
typedef struct V3 { f32 x, y, z; } V3;
extern V3 D_0045ECBC[];
extern V3 D_0045ECA4[];

void func_0033B9D0(P3B *p)
{
    extern f32 func_00417440(s32);
    switch (p->b4) {
    case 0:
        if (p->q14->h1e != 0) break;
        if (p->q14->b4 == 2 || p->q14->b4 == p->b20) {
            { u32 t = *(volatile u8 *)&p->b4; p->b4 = t + 1; }
            p->h1c = 0;
        }
        break;
    case 1:
        p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)D_004C1928[p->b20] / 360.0) & 0xFFFF;
        p->h1c = p->h1c + 1;
        if (p->h1c < 20) break;
        { u32 t = *(volatile u8 *)&p->b4; p->b4 = t + 1; }
        p->h1c = 0;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)D_0045ECBC[p->b20].x / 360.0) & 0xFFFF;
        break;
    case 2: {
        f32 r = func_00417440((u16)(s32)(0.5 + 65536.0 * (f64)(p->h1c * 36) / 360.0));
        p->w44 = (u16)(s32)(0.5 + 65536.0 * (f64)(D_0045ECBC[p->b20].x + 10.0f * ((f32)(60 - p->h1c) / 60.0f) * r) / 360.0);
        p->h1c = p->h1c + 1;
        if (p->h1c < 60) break;
        { u32 t = *(volatile u8 *)&p->b4; p->b4 = t + 1; }
        p->h1c = 0;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)D_0045ECBC[p->b20].x / 360.0) & 0xFFFF;
        break;
    }
    case 3:
        p->h1c = p->h1c + 1;
        if (p->h1c < 60) break;
        { u32 t = *(volatile u8 *)&p->b4; p->b4 = t + 1; }
        p->h1c = 0;
        break;
    case 4:
        p->w44 += (u32)(s32)(0.5 + 65536.0 * (f64)D_004C1930[p->b20] / 360.0) & 0xFFFF;
        p->h1c = p->h1c + 1;
        if (p->h1c < 100) break;
        p->h1c = 0;
        p->b4 = 0;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)D_0045ECA4[p->b20].x / 360.0) & 0xFFFF;
        break;
    default:
        break;
    }
}
