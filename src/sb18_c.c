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

void func_00143DA0(void) {
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

void func_00140500(void) {
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
        o->pos = *D_004B1D20;
        k = 65536.0;
        o->w40 = (u32)(s32)(0.5 + k * (double)D_004B1D80[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w44 = (u32)(s32)(0.5 + k * (double)D_004B1D84[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w48 = (u32)(s32)(0.5 + k * (double)D_004B1D88[0] / 360.0) & 0xFFFF;
        o->pos2 = *D_004B1DE0;
        o->w78 = 0.30000001192092896f;
        o->w7c = 0.30000001192092896f;
        o->w80 = 0.30000001192092896f;
        func_00140BF0(o);
        func_00140D40(o);
    }
}

