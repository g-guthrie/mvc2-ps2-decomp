typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G;
typedef struct { s32 w[0x31]; } C;
typedef struct { u8 p0[8]; f32 f8, fC; } S88;
typedef struct P {
    u8 p0;
    u8 b1, b2, p3, b4;
    u8 p5[0x1C];
    u8 b21, p22, b23;
    s8 b24;
    u8 p25[0x30 - 0x25];
    s8 b30, b31;
    u8 p32[2];
    f32 f34, f38;
    u8 p3C[0x50 - 0x3C];
    f32 f50, f54, f58, f5C;
    u8 p60[0x68 - 0x60];
    f32 f68;
    u8 p6C[0x88 - 0x6C];
    S88 s88;
    u8 p98[0xEC - 0x98];
    C cEC;
    u8 p1B0[0x13C - 0xEC - sizeof(C)];
    u8 b13C;
    u8 p13D[3];
    s16 h140;
    u8 p142[0x1B0 - 0x142];
    u8 b1B0, b1B1, b1B2, p1B3[2], b1B5, p1B6, b1B7, b1B8;
    u8 p1B9[0x1C0 - 0x1B9];
    u16 h1C0;
    u8 p1C2[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 p1DC[0x269 - 0x1DC];
    u8 b269;
    u8 p26A[0x2B8 - 0x26A];
    u8 b2B8[8];
} P;
extern G *D_004C2794;
extern s32 D_00473E90[];
extern s32 D_00473E94[];
extern s32 D_00473E98[];
extern s32 D_00473E9C[];

void func_003B42F0(P *p, P *q) {
    extern void func_001757E0(P *, s32, s32);
    extern void func_001E7F60(P *);
    extern s32 func_003B4120(P *);
    u8 *r;
    S88 *w;
    u8 *pb;
    u32 t;
    r = q->b2B8;
    w = &p->s88;
    t = p->b4;
    p->b4 = t + 1;
    p->cEC = q->cEC;
    p->b13C = 1;
    p->b2 = q->b2;
    p->b1 = q->b1;
    p->f50 = q->f50;
    p->f54 = q->f54;
    p->b1B7 = q->b1B7;
    p->b1B8 = q->b1B8;
    p->b30 = q->b30;
    *(V3 *)&p->f50 = *(V3 *)&q->f50;
    p->b24 = q->b24;
    pb = &p->b2;
    switch (p->b23) {
    case 0:
        p->b21 = 9;
        if (q->b269 == 3) {
            p->b1B5 = 0x30;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7c[*pb]++;
        } else {
            p->b1B5 = 0x31;
            p->b1B2 = p->h1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->h7c[*pb]++;
        }
        break;
    case 1:
        p->b21 = 5;
        p->b1B5 = 0x30;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7c[*pb]++;
        break;
    case 2:
        p->b21 = 0xD;
        p->b1B5 = 0x2E;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7c[*pb]++;
        break;
    case 3:
        p->b21 = 9;
        p->b1B5 = 0x33;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7c[*pb]++;
        break;
    case 4:
        p->b21 = 5;
        p->b1B5 = 0x32;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7c[*pb]++;
        break;
    case 5:
        p->b21 = 0xD;
        p->b1B5 = 0x2F;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7c[*pb]++;
        break;
    }
    if (q->h140 == 0) {
        w->f8 = -(1.66666663f * (f32)D_00473E90[p->b23 * 4] / 65536.0f);
        w->fC = 2.14285707f * (f32)D_00473E94[p->b23 * 4] / 65536.0f;
        p->f5C = -(1.66666663f * (f32)D_00473E98[p->b23 * 4] / 65536.0f);
        p->f68 = -(1.66666663f * (f32)D_00473E9C[p->b23 * 4] / 65536.0f);
    } else {
        w->f8 = 1.66666663f * (f32)D_00473E90[p->b23 * 4] / 65536.0f;
        w->fC = 2.14285707f * (f32)D_00473E94[p->b23 * 4] / 65536.0f;
        p->f5C = 1.66666663f * (f32)D_00473E98[p->b23 * 4] / 65536.0f;
        p->f68 = 1.66666663f * (f32)D_00473E9C[p->b23 * 4] / 65536.0f;
    }
    p->f34 = q->f34 + w->f8;
    p->f38 = q->f38 + w->fC;
    p->b1B0 = 0x44;
    p->b1B1 = 1;
    func_001757E0(p, 0x15, p->b21);
    p->b31 = -2;
    func_001E7F60(p);
    if (func_003B4120(p) == 0) {
        p->b4 = 3;
        p->b13C = 0;
        r[4] = 1;
    }
}
