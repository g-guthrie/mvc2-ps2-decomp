typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

/* MW 3.0: ./try30.sh src/se2_b.c "-O3 -Op -fp off -sdatathreshold 8"
   func_0032FC00, func_0032FE30 and func_0032FEB0 are static copies of the
   real contiguous run of functions immediately before func_0032FF00 in retail
   address order (func_0032FEB0 is also its callee); each verifies exact at its
   own address under these flags. The soft-float code in func_0032FC00 sets the
   register allocation that func_0032FF00 has in retail. */
typedef struct { u8 prefix[0x38]; f32 y; u8 pad3C[0x24]; f32 vy; } Motion;
typedef struct E28 { f32 v; u8 pad[24]; } E28;
extern E28 D_0045E48C[];

static void func_0032FC00(u8 *p)
{
    extern s32 func_003D90A0(s32);
    extern s32 func_00417A40(void);
    Motion *motion = (Motion *)p;
    switch (p[4]) {
    case 0:
        if (func_003D90A0(0)) {
            ++p[4];
            motion->vy = 20.0f;
            *(u32 *)(p + 0x40) = (u16)(s32)(0.5 + 65536.0 * (f64)(func_00417A40() % 5) / 360.0);
            *(s32 *)(p + 0x48) = *(s32 *)(p + 0x40) / 30;
        }
        break;
    case 1:
        motion->y += motion->vy;
        if (motion->vy <= 0.0f) motion->vy += -0.4000000059604645f;
        else { motion->vy += -2.0f; *(s32 *)(p + 0x44) += *(s32 *)(p + 0x40); *(s32 *)(p + 0x40) -= *(s32 *)(p + 0x48); }
        if (motion->y < 50.0f + D_0045E48C[0].v && motion->vy < 0.0f) { ++p[4]; motion->y = 50.0f + D_0045E48C[0].v; motion->vy = 0.0f; }
        break;
    case 2:
        motion->y += motion->vy;
        motion->vy += -0.4000000059604645f;
        if (motion->y < D_0045E48C[0].v) { motion->y = D_0045E48C[0].v; p[4] = 0; }
        break;
    }
}

typedef struct { f32 x, y, z; } Vec3;
extern E28 D_0045E488[];
extern void *D_004C283C;
static void func_0032FE30(void)
{
    extern u8 *func_003DA750(s32, s32, s32);
    u8 *p = func_003DA750(0, 0x6, 0x1);
    if (p) {
        p[0x13c] = 1; *(void (**)(u8 *))(p + 0x10) = func_0032FC00;
        *(s16 *)(p + 0xcc) = 0x3; *(void **)(p + 0x84) = D_004C283C; *(u32 *)(p + 0xd0) = 0x805;
        *(Vec3 *)(p + 0x34) = *(Vec3 *)D_0045E488;
    }
}
static void (*keep_0032FE30)(void) = func_0032FE30;

static void func_0032FEB0(f32 t, f32 *a, f32 *b, f32 *c) {
    f32 u = 1.0f - t;
    *a = 0.5f * u * u;
    *b = 0.5f + u * t;
    *c = 0.5f * t * t;
}

extern E28 D_0045E490[], D_0045E494[], D_0045E498[], D_0045E49C[];
extern E28 D_0045E4A0[], D_0045E4A4[], D_0045E4A8[], D_0045E4AC[], D_0045E4B0[], D_0045E4B4[], D_0045E4B8[];
extern E28 D_0045E4BC[], D_0045E4C0[], D_0045E4C4[], D_0045E4C8[], D_0045E4CC[], D_0045E4D0[], D_0045E4D4[];

typedef struct P {
    u8 _p0[0x1C];
    s16 h1c;
    s16 h1e;
    u8 _p2[0x14];
    f32 f34;
    f32 f38;
    f32 f3c;
    u32 w40;
    u32 w44;
    u32 w48;
} P;

void func_0032FF00(P *p)
{
    extern void func_003302E0(P *);
    f32 vx, vy, vz;
    s16 i;
    s16 h;

    h = p->h1e;
    func_0032FEB0((f32)p->h1c / (D_0045E4BC[h].v - D_0045E4A0[h].v), &vx, &vy, &vz);
    h = p->h1e;
    p->f34 = vx * D_0045E488[h].v + vy * D_0045E4A4[h].v + vz * D_0045E4C0[h].v;
    p->f38 = vx * D_0045E48C[h].v + vy * D_0045E4A8[h].v + vz * D_0045E4C4[h].v;
    p->f3c = vx * D_0045E490[h].v + vy * D_0045E4AC[h].v + vz * D_0045E4C8[h].v;
    p->w40 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E494[h].v + vy * D_0045E4B0[h].v + vz * D_0045E4CC[h].v) / 360.0) & 0xFFFF;
    p->w44 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E498[h].v + vy * D_0045E4B4[h].v + vz * D_0045E4D0[h].v) / 360.0) & 0xFFFF;
    p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)(vx * D_0045E49C[h].v + vy * D_0045E4B8[h].v + vz * D_0045E4D4[h].v) / 360.0) & 0xFFFF;
    i = p->h1c + 1;
    p->h1c = i;
    if ((f32)p->h1c >= D_0045E4BC[p->h1e].v - D_0045E4A0[p->h1e].v) {
        p->h1c = 0;
        i = p->h1e + 1;
        p->h1e = i;
        if ((u32)(p->h1e + 1) >= 0x22) {
            p->h1e = 1;
        }
    }
    func_003302E0(p);
}
