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

typedef struct PB PB;
typedef struct PQ { u8 _p[0xD8]; s32 wD8; } PQ;
struct PB {
    u8 _p0[0x5];
    u8 b5;
    u8 b6;
    u8 _p1[0xD];
    PQ *p14;
    u8 _p2[0x6];
    s16 h1e;
    u8 _p3[0x20];
    u32 w40;
    u8 _p4[0xC];
    f32 f50;
    u8 _p5[0x78];
    s16 hCC;
    u8 _p6[2];
    u32 wD0;
    u8 _p7[4];
    s32 wD8;
    u8 _p8[4];
    s32 wE0;
    f32 fE4;
};

extern s32 D_004C283C;
extern s32 func_00153AA0(PB *);
extern void func_00170DA0(s32, s32, s32, s16);
extern s32 func_00332580(PB *);

void func_00332420(PB *p) {
    s32 v;
    func_00170DA0(D_004C283C, 7, func_00153AA0(p), p->hCC);
    p->wE0 = 0;
    p->fE4 = -0.019999999552965164f * (f32)p->h1e;
    p->wD0 |= 0x20000;
    v = p->p14->wD8;
    p->wD8 = v;
    switch (v) {
    case 0:
        break;
    case 1:
        p->h1e = p->h1e + 1;
        p->h1e = p->h1e % 50;
        break;
    case 2:
        p->h1e = p->h1e - 1;
        if (p->h1e < 0) p->h1e = 0x31;
        break;
    default:
        break;
    }
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)p->f50 / 360.0) & 0xFFFF;
    if (func_00332580(p) != 0) {
        p->b5 = 1;
        { u32 t = p->b6; p->b6 = t + 1; }
    }
}
