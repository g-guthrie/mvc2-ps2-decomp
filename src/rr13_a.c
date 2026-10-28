typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;




extern double func_00119058(f32);

typedef struct P {
    u8 pad0[0x1C];
    s16 h1c;
    u8 pad1[0x40 - 0x1E];
    u32 w40;
    u32 w44;
    u8 pad2[0x54 - 0x48];
    f32 f54;
    u8 pad3[0xD4 - 0x58];
    s32 wd4;
} P;

static s32 func_00332580(P *p) {
    p->h1c += 1;
    p->w40 += (u16)((u32)(s32)(0.5 + 65536.0 * func_00119058(p->f54 * (f32)p->h1c) / 360.0));
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        return 1;
    }
    return 0;
}

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
    if (func_00332580((P *)p) != 0) {
        p->b5 = 1;
        { u32 t = p->b6; p->b6 = t + 1; }
    }
}
