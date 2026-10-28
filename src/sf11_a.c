/* nearmiss residual_003852A0: MW 3.0 -O3 -Op -fp off -sdatathreshold 8, 36/140 words: temps a0/a1 vs retail a2/a3 (soft-float file-position effect; exact with func_00338670 static prefix, which is not an allowed neighbour) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { f32 a, b; } TB;
typedef struct { u8 a, b; } TC;
extern u8 D_004C1D60[8];
extern TB D_00464780[];
extern TC D_00464770[];
extern TB D_004647D0[];
extern TB D_004647D4[];
extern TC D_004647C0[];
extern TC D_004647C1[];
extern f32 D_004F1F4C[];
extern f32 D_004F1FE8[];

#define PAR (*(u8 **)(p + 0x18))


void residual_003852A0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003854D0(u8 *);
    f64 k;
    p[4]++;
    *(B3c *)(p + 0xEC) = *(B3c *)(PAR + 0xEC);
    p[0x13C] = 1;
    p[2] = PAR[2];
    p[1] = PAR[1];
    *(f32 *)(p + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(PAR + 0x54);
    p[0x1B7] = PAR[0x1B7];
    p[0x1B8] = PAR[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(PAR + 0x24);
    p[0x13C] = 0;
    *(s16 *)(p + 0x140) = 0;
    p[0x24] = 0xB;
    *(s16 *)(p + 0x1C) = D_004C1D60[p[0x21]];
    *(f32 *)(p + 0x34) = (f32)((f64)D_00464780[p[0x21]].a + ((f64)D_004F1F4C[0] - 320.0 - 106.66666412353516));
    k = 240.0;
    *(f32 *)(p + 0x38) = (f32)(34.28571319580078 + (k + (f64)D_004F1FE8[0]) - (f64)D_00464780[p[0x21]].b);
    p[0x168] = D_00464770[p[0x21]].a;
    func_001757E0(p, 0x17, p[0x168]);
    func_003854D0(p);
}


void residual_00385570(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    f64 k;
    p[4]++;
    *(B3c *)(p + 0xEC) = *(B3c *)(PAR + 0xEC);
    p[0x13C] = 1;
    p[2] = PAR[2];
    p[1] = PAR[1];
    *(f32 *)(p + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(PAR + 0x54);
    p[0x1B7] = PAR[0x1B7];
    p[0x1B8] = PAR[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(PAR + 0x24);
    p[0x13C] = 0;
    *(s16 *)(p + 0x140) = 0;
    p[0x24] = 0xC;
    *(s16 *)(p + 0x1C) = D_004647C0[p[0x21]].a;
    p[0x168] = D_004647C1[p[0x21]].a;
    *(f32 *)(p + 0x34) = (f32)((f64)D_004647D0[p[0x21]].a + ((f64)D_004F1F4C[0] - 320.0 - 106.66666412353516));
    k = 240.0;
    *(f32 *)(p + 0x38) = (f32)(34.28571319580078 + (k + (f64)D_004F1FE8[0]) - (f64)D_004647D4[p[0x21]].a);
    func_001757E0(p, 0x17, p[0x168]);
}

typedef struct { s32 w[0x31]; } CP199;
typedef struct { f32 x, y, z; } V199;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G199;
typedef struct { u8 pad[0x6C]; f32 f6c; } P6C;
extern G199 *D_004C2794;
extern u16 *D_004C29D0;
extern f32 D_004F1F4C[];

void residual_00392990(u8 *p) {
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o = *(u8 **)(p + 0x18);
    u8 *t = *(u8 **)(o + 0x220);
    f64 k;
    f32 g;
    f32 v;

    p[4]++;
    *(CP199 *)(p + 0xEC) = *(CP199 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[0x2] = (*(u8 **)(p + 0x18))[0x2];
    p[0x1] = (*(u8 **)(p + 0x18))[0x1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V199 *)(p + 0x50) = *(V199 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x24] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x50;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    if (*(s16 *)(p + 0x140) != 0) {
        k = -373.3333320617676;
    } else {
        k = 373.3333320617676;
    }
    g = D_004F1F4C[0];
    *(f32 *)(p + 0x34) = (f32)((f64)g + k);
    *(f32 *)(p + 0x38) = 373.33331298828125f + *(f32 *)(o + 0x430);
    *(f32 *)(p + 0x5C) = (f32)((f64)(*(f32 *)(t + 0x34) - *(f32 *)(p + 0x34)) / 32.0);
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0;
    v = (f32)((f64)(2.0f * (*(f32 *)(t + 0x38) - *(f32 *)(p + 0x38))) / 1024.0);
    {
        f32 lim = -0.8035714030265808f;
        *(f32 *)(p + 0x6C) = v;
        if (!(v <= lim)) {
            ((P6C *)p)->f6c = lim;
        }
    }
    *D_004C29D0 = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    p[0x22] = 0;
    func_0015E630(p);
    p[0] = 1;
    func_001757E0(p, 0x17, 4);
}

typedef struct { f32 a, b; } T52;
extern u8 *D_004C29D4;
extern T52 D_00471C30[];
extern T52 D_00471C34[];

static s32 func_00393390(u8 **p) { return p[6][1061] != 0; }

extern void func_00394770(u8 *p);
static void func_00394760(u8 *p) { p[4] = 3; p[316] = 0; func_00394770(p); }

void residual_00393520(u8 *o) {
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    u32 t;
    s32 v;
    f32 k;
    f64 c;
    q = *(u8 **)(o + 0x18);
    if (*D_004C29D0 != *(u16 *)(q + 0x168)) {
        func_00394760(o);
        return;
    }
    if (func_00393390((u8 **)o)) {
        func_00394760(o);
        return;
    }
    v = *(s8 *)((u8 *)D_004C29D4 + 8);
    if (v == 0) return;
    if ((s8)v != 1) {
        func_00394760(o);
        return;
    }
    t = o[5];
    q = *(u8 **)(q + 0x1DC);
    o[5] = t + 1;
    o[0x13C] = 1;
    o[0x14E] = 0x28;
    o[0x14F] = 0x28;
    if (*(s16 *)(o + 0x140)) k = D_00471C30[q[1]].a;
    else k = -D_00471C30[q[1]].a;
    *(f32 *)((u8 *)D_004C29D0 + 4) = *(f32 *)(q + 0x34) + k;
    *(f32 *)((u8 *)D_004C29D0 + 8) = *(f32 *)(q + 0x38) + D_00471C34[q[1]].a;
    if (*(s16 *)(o + 0x140)) c = 386.66666412353516;
    else c = -386.66666412353516;
    *(f32 *)(o + 0x34) = (f32)((f64)D_004F1F4C[0] + c);
    *(f32 *)(o + 0x38) = *(f32 *)((u8 *)D_004C29D0 + 8);
    *(f32 *)(o + 0x5C) = (f32)((f64)(*(f32 *)((u8 *)D_004C29D0 + 4) - *(f32 *)(o + 0x34)) / 16.0);
    *(s32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x60) = 0x41092492;
    *(u32 *)(o + 0x6C) = 0xBF892492;
    *(s16 *)(o + 0x1C) = 0x10;
    func_0015E630(o);
    o[0] = 1;
    func_001757E0(o, 0x17, 5);
}
