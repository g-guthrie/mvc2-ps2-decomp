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

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B1D68, D_004B1E28;
extern f32 D_004B1D20[], D_004B1D24[], D_004B1D28[];
extern f32 D_004B1D80[], D_004B1DC8[], D_004B1DCC[], D_004B1DD0[];
extern f32 D_004B1DE0[], D_004B1DE4[], D_004B1DE8[];

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
