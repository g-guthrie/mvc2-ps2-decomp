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


typedef struct { f32 v; u8 pad[24]; } E28;
extern E28 D_004B7668[], D_004B766C[], D_004B7670[], D_004B7674[], D_004B7678[], D_004B767C[];
extern E28 D_004B7680[], D_004B7684[], D_004B7688[], D_004B768C[], D_004B7690[], D_004B7694[], D_004B7698[];
extern E28 D_004B769C[], D_004B76A0[], D_004B76A4[], D_004B76A8[], D_004B76AC[], D_004B76B0[], D_004B76B4[];
extern s32 D_004C283C;

typedef struct P {
    u8 _p0[4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    s16 h1e;
    u8 _p2[0x14];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x38];
    s32 w84;
    u8 _p4[0x44];
    s16 hcc;
    u8 _p5[0x6E];
    u8 b13c;
} P;

void func_0032E740(P *p)
{
    extern void func_0032FEB0(f32, f32 *, f32 *, f32 *);
    extern void func_003DAA40();
    f32 vx, vy, vz;
    s16 i;
    s16 h;
    u32 t;

    switch (p->b4) {
    case 0:
    h = p->h1e;
    if (h > 0x7D0 && h < 0x9C4) {
        p->b13c = 0;
    } else {
        p->b13c = 1;
        if (h <= 0x7D0) {
            p->hcc = 1;
            p->w84 = D_004C283C;
        } else {
            p->hcc = 0xE;
            p->w84 = D_004C283C;
        }
        i = h;
        func_0032FEB0((f32)p->h1c / (D_004B769C[i].v - D_004B7680[i].v), &vx, &vy, &vz);
        p->f34 = vx * D_004B7668[i].v + vy * D_004B7684[i].v + vz * D_004B76A0[i].v;
        p->f38 = vx * D_004B766C[i].v + vy * D_004B7688[i].v + vz * D_004B76A4[i].v;
        p->f3c = vx * D_004B7670[i].v + vy * D_004B768C[i].v + vz * D_004B76A8[i].v;
        p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_004B7674[i].v + vy * D_004B7690[i].v + vz * D_004B76AC[i].v) / 360.0) & 0xFFFF;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_004B7678[i].v + vy * D_004B7694[i].v + vz * D_004B76B0[i].v) / 360.0) & 0xFFFF;
        p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_004B767C[i].v + vy * D_004B7698[i].v + vz * D_004B76B4[i].v) / 360.0) & 0xFFFF;
    }
    i = p->h1c + 1;
    p->h1c = i;
    if ((f32)p->h1c < D_004B769C[p->h1e].v - D_004B7680[p->h1e].v) {
        return;
    }
    p->h1c = 0;
    i = p->h1e + 1;
    p->h1e = i;
    if ((u32)(p->h1e + 1) >= 9) {
        t = p->b4;
        p->b4 = t + 1;
    }
        break;
    case 1:
        func_003DAA40(p);
        break;
    }
}
