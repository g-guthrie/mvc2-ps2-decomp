typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32; typedef double f64;
typedef struct { u8 p0[0x140]; s16 h140; } G_sf4a;
typedef struct { u8 p0[4]; u8 b4; u8 p5[0xF]; u8 *p14; u8 p18[4]; s16 h1c; u8 p1e[0x2A]; u32 w48; } S_sf4a;
extern G_sf4a *D_004D18C4[];
extern void (*D_004BF460[2])();

void func_0015BBD0(S_sf4a *p) {
    G_sf4a *g = D_004D18C4[0];
    *((u8 *)p + 0x13C) = 0;
    if (*(s8 *)(p->p14 + 0x13C) == 0) {
        p->h1c = (g->h140 != 0) ? 0 : -0xB4;
        p->w48 = (u32)(s32)(0.5 + 65536.0 * (f64)p->h1c / 360.0) & 0xFFFF;
    } else {
        D_004BF460[p->b4](p, g);
    }
}
