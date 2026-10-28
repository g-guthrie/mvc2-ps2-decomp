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


typedef struct { f32 x, y, z; } V3;
extern V3 D_004B1D68, D_004B1E28;
extern f32 D_004B1D20[], D_004B1D24[], D_004B1D28[];
extern f32 D_004B1D80[], D_004B1DC8[], D_004B1DCC[], D_004B1DD0[];
extern f32 D_004B1DE0[], D_004B1DE4[], D_004B1DE8[];


typedef struct SA37_V3 { f32 x, y, z; } SA37_V3;

typedef struct SA37_M0 {
    u8 pad0[0x10];
    void *w10;
    u8 pad14[0x1C - 0x14];
    s16 h1c;
    u8 pad1e[2];
    u8 b20;
    u8 pad21[0x34 - 0x21];
    SA37_V3 pos;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 pad4c[0x50 - 0x4C];
    SA37_V3 pos2;
    u8 pad5c[0x78 - 0x5C];
    f32 w78;
    f32 w7c;
    f32 w80;
    s32 w84;
    u8 pad88[0xCC - 0x88];
    s16 hcc;
    u8 padce[2];
    s32 wd0;
    u8 padd4[0x13C - 0xD4];
    u8 b13c;
} SA37_M0;

extern f32 D_004B1D84[];
extern f32 D_004B1D88[];
extern s32 D_004C2818;

/* Real address-order predecessor of func_00140500 (0x00140420, also in src/y4_d.c). */
static void func_00140420(u8 *p) {
    extern f32 func_00417440(s32);
    extern void func_003DAA40(u8 *);
    f32 d = 0.0399999991059f;
    f32 r;
    s16 n;
    *(s16 *)(p + 0xCC) = 0x1A;
    *(s32 *)(p + 0x84) = D_004C2818;
    *(f32 *)(p + 0x50) += d;
    *(f32 *)(p + 0x54) += d;
    r = func_00417440((u16)((u32)(s32)(65536.0 * (*(s16 *)(p + 0x1C) * 3) / 360.0 + 0.5)));
    *(f32 *)(p + 0x78) = r;
    *(f32 *)(p + 0x7C) = r;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    n = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = n;
    if (n >= 0x3C) func_003DAA40(p);
}

/* Real address-order predecessor of func_001406D0 (0x00140500, also in src/sb18_c.c). */
static void func_00140500(void) {
    extern SA37_M0 *func_003DA750(s32, s32, s32);
    extern void func_001406D0();
    extern void func_00140BF0(SA37_M0 *);
    extern void func_00140D40(SA37_M0 *);
    SA37_M0 *o;
    double k;
    if ((o = func_003DA750(0, 0xD, 0)) != 0) {
        o->b13c = 1;
        o->w10 = (void *)func_001406D0;
        o->hcc = 0;
        o->w84 = D_004C2818;
        o->wd0 = 0xC17;
        o->pos = *(SA37_V3 *)D_004B1D20;
        k = 65536.0;
        o->w40 = (u32)(s32)(0.5 + k * (double)D_004B1D80[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w44 = (u32)(s32)(0.5 + k * (double)D_004B1D84[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w48 = (u32)(s32)(0.5 + k * (double)D_004B1D88[0] / 360.0) & 0xFFFF;
        o->pos2 = *(SA37_V3 *)D_004B1DE0;
        o->w78 = 0.30000001192092896f;
        o->w7c = 0.30000001192092896f;
        o->w80 = 0.30000001192092896f;
        func_00140BF0(o);
        func_00140D40(o);
    }
}

typedef struct G {
    u8 _p0[0xA];
    s16 hA;
} G;
extern G *D_004C2840;

typedef struct P {
    u8 _p0[4];
    u8 b4;
    u8 b5;
    u8 _p1[0x16];
    s16 h1c;
    u8 _p2[0x14];
    V3 v34;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 _p3[0x4];
    V3 v50;
    u8 _p4[0x1C];
    f32 f78;
    f32 f7c;
    f32 f80;
} P;

void func_001406D0(P *p)
{
    s16 i;
    u32 t;

    switch (p->b4) {
    case 0:
        p->v34.x = D_004B1D20[0] + (f32)p->h1c * ((D_004B1D68.x - D_004B1D20[0]) / 270.0f);
        p->v34.y = D_004B1D24[0] + (f32)p->h1c * ((D_004B1D68.y - D_004B1D24[0]) / 270.0f);
        p->v34.z = D_004B1D28[0] + (f32)p->h1c * ((D_004B1D68.z - D_004B1D28[0]) / 270.0f);
        p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)(D_004B1D80[0] + (f32)p->h1c * ((D_004B1DC8[0] - D_004B1D80[0]) / 270.0f)) / 360.0) & 0xFFFF;
        p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)(D_004B1D80[0] + (f32)p->h1c * ((D_004B1DC8[0] - D_004B1D80[0]) / 270.0f)) / 360.0) & 0xFFFF;
        p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)(D_004B1D80[0] + (f32)p->h1c * ((D_004B1DC8[0] - D_004B1D80[0]) / 270.0f)) / 360.0) & 0xFFFF;
        p->v50.x = D_004B1DE0[0] + (f32)p->h1c * ((D_004B1E28.x - D_004B1DE0[0]) / 270.0f);
        p->v50.y = D_004B1DE4[0] + (f32)p->h1c * ((D_004B1E28.y - D_004B1DE4[0]) / 270.0f);
        p->v50.z = D_004B1DE8[0] + (f32)p->h1c * ((D_004B1E28.z - D_004B1DE8[0]) / 270.0f);
        i = p->h1c + 1;
        p->h1c = i;
        if (i >= 270) {
            t = p->b4;
            p->b4 = t + 1;
            p->v34 = D_004B1D68;
            p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)D_004B1DC8[0] / 360.0) & 0xFFFF;
            p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)D_004B1DCC[0] / 360.0) & 0xFFFF;
            p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)D_004B1DD0[0] / 360.0) & 0xFFFF;
            p->v50 = D_004B1E28;
        }
        break;
    case 1:
        break;
    }
    switch (p->b5) {
    case 0:
        if (D_004C2840->hA >= 0x17C) {
            p->b5 = p->b5 + 1;
        }
        break;
    case 1:
        p->f78 += 0.1f;
        p->f7c += 0.1f;
        p->f80 += 0.1f;
        if (p->f78 < 1.0f) {
            break;
        }
        t = p->b5;
        p->b5 = t + 1;
        p->f78 = 1.0f;
        p->f7c = 1.0f;
        p->f80 = 1.0f;
        break;
    case 2:
        break;
    }
}
