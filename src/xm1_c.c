typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0: ./try30.sh src/xm1_c.c "-O3 -Op -fp off -sdatathreshold 8"  (static func_00338670 first: file-position register effect) */
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
extern V3 D_004B80B8;
extern V3 D_004B3200[];

typedef struct { u8 pad0[7]; s8 b7; } G13CDE0;
typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad1[0x17];
    s16 h1c;
    u8 pad2[3];
    u8 b21;
    u8 pad3[0x12];
    f32 f34;
    u8 pad4[4];
    f32 f3c;
    u8 pad5[0x10];
    f32 f50;
    f32 f54;
    f32 f58;
    u8 pad6[0x74];
    u32 wD0;
    u8 pad7[0xC];
    u32 wE0;
    f32 fE4;
    u8 pad8[0x54];
    u8 b13C;
} P13CDE0;

extern G13CDE0 *D_004C2840;
extern f32 D_0043F498[];
extern f32 D_0043F490[];
extern u8 D_00583B90[];

void func_0013CDE0(P13CDE0 *p)
{
    extern void func_003DAA40();
    s32 i;
    s32 idx;
    u8 x;
    f32 *q;

    switch (p->b4) {
    case 0:
{
    p->f50 = 1.0f;
    p->f54 = 1.0f;
    p->f58 = 1.0f;
    p->f3c = (f32)(0.5 + (f64)D_0043F498[p->b21 * 3]);
    p->f34 = D_0043F490[p->b21 * 3];
    if (D_004C2840->b7 != 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->b13C = 0;
        return;
    }
    p->h1c = p->h1c + 1;
    if (p->h1c >= 500) p->h1c = 0;
    p->wD0 = p->wD0 | 0x20000;
    p->wE0 = 0;
    i = 0;
    p->fE4 = 0.002f * (f32)p->h1c;
    while ((s16)i < 2) {
        x = D_00583B90[(s16)i + 0x30];
        if (x != 0) {
            idx = (u8)((s8)x - 1);
            if (p->b21 == idx) {
                if (i != 0) {
                    p->f50 = 1.15f;
                    p->f54 = 1.15f;
                    p->f58 = 1.15f;
                    q = &D_0043F490[idx * 3];
                    p->f3c = (f32)(0.5 + (6.0 + (f64)q[2]));
                    if (p->f34 < 0.0f) {
                        p->f34 = q[0] - 2.0f;
                    } else {
                        p->f34 = 2.0f + q[0];
                    }
                } else {
                    p->f50 = 1.2f;
                    p->f54 = 1.2f;
                    p->f58 = 1.2f;
                    q = &D_0043F490[idx * 3];
                    p->f3c = (f32)(0.5 + (f64)(8.0f + q[2]));
                    if (p->f34 < 0.0f) {
                        p->f34 = q[0] - 2.0f;
                    } else {
                        p->f34 = 2.0f + q[0];
                    }
                }
            }
        }
        i = (s16)(i + 1);
    }
}
        break;
    case 1:
        func_003DAA40(p);
        break;
    default:
        break;
    }
}
