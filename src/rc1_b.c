typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

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

extern SA37_V3 D_004B1900[];
extern f32 D_004B1920[];
extern f32 D_004B1924[];
extern f32 D_004B1928[];
extern s32 D_004C2824;


extern f32 D_004B1E70[];
extern f32 D_004B1E74[];
extern f32 D_004B1E78[];
extern s32 D_004C2810;

static void func_00143DA0(void) {
    extern SA37_M0 *func_003DA750(s32, s32, s32);
    extern void func_00143F10();
    SA37_M0 *o;
    double k;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o->b13c = 1;
        o->w10 = (void *)func_00143F10;
        o->hcc = 0;
        o->w84 = D_004C2810;
        o->wd0 = 0x80E;
        o->b20 = 0;
        k = 65536.0;
        o->w40 = (u32)(s32)(0.5 + k * (double)D_004B1E70[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w44 = (u32)(s32)(0.5 + k * (double)D_004B1E74[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w48 = (u32)(s32)(0.5 + k * (double)D_004B1E78[0] / 360.0) & 0xFFFF;
    }
}

extern SA37_V3 D_004B1D20[];
extern SA37_V3 D_004B1DE0[];
extern f32 D_004B1D80[];
extern f32 D_004B1D84[];
extern f32 D_004B1D88[];
extern s32 D_004C2818;


static void (*keep_00143DA0)(void) = func_00143DA0;

typedef struct { f32 x, y, z; } V3bb;

extern s32 D_004B3110[];

void func_00143F10(u8 *p) {
    V3bb *a, *b;
    s32 h, h1, n;
    s16 v;
    double k;
    switch (p[4]) {
    case 0:
        h = *(s16 *)(p + 0x1E);
        h1 = h + 1;
        n = D_004B3110[h1] - D_004B3110[h];
        a = ((V3bb *)D_004B1E70) + h;
        b = ((V3bb *)D_004B1E70) + h1;
        k = 65536.0;
        *(u32 *)(p + 0x40) += (u32)(s32)(0.5 + k * (double)((b->x - a->x) / (f32)n) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(u32 *)(p + 0x44) += (u32)(s32)(0.5 + k * (double)((b->y - a->y) / (f32)n) / 360.0) & 0xFFFF;
        k = 65536.0;
        *(u32 *)(p + 0x48) += (u32)(s32)(0.5 + k * (double)((b->z - a->z) / (f32)n) / 360.0) & 0xFFFF;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < n) break;
        *(s16 *)(p + 0x1C) = 0;
        k = 65536.0;
        *(u32 *)(p + 0x40) = (u32)(s32)(0.5 + k * (double)b->x / 360.0) & 0xFFFF;
        k = 65536.0;
        *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + k * (double)b->y / 360.0) & 0xFFFF;
        k = 65536.0;
        *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + k * (double)b->z / 360.0) & 0xFFFF;
        v = *(s16 *)(p + 0x1E) + 1;
        *(s16 *)(p + 0x1E) = v;
        if ((u32)v < 0x31) break;
        p[4]++;
        break;
    case 1:
        break;
    }
}
