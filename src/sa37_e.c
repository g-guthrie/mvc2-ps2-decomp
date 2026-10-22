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
    u8 pad1e[0x34 - 0x1E];
    SA37_V3 pos;
    u32 w40;
    u32 w44;
    u32 w48;
    u8 pad4c[0x84 - 0x4C];
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

void func_0013E330(void) {
    extern SA37_M0 *func_003DA750(s32, s32, s32);
    extern void func_0013E4D0();
    SA37_M0 *o;
    double k;
    if ((o = func_003DA750(0, 0x12, 1)) != 0) {
        o->b13c = 1;
        o->w10 = (void *)func_0013E4D0;
        o->hcc = 0;
        o->w84 = D_004C2824;
        o->pos = *D_004B1900;
        k = 65536.0;
        o->w40 = (u32)(s32)(0.5 + k * (double)D_004B1920[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w44 = (u32)(s32)(0.5 + k * (double)D_004B1924[0] / 360.0) & 0xFFFF;
        k = 65536.0;
        o->w48 = (u32)(s32)(0.5 + k * (double)D_004B1928[0] / 360.0) & 0xFFFF;
        o->wd0 = 0x200005;
        o->h1c = 0;
        o->h1c = 1;
    }
}
