typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 v[4]; } G4;
typedef struct { f32 v[4]; } F4;
typedef union { G4 i; F4 f; } U4;
extern G4 D_004AA970;
extern F4 D_004A6F80[];
extern F4 D_004A88A0[];
extern s32 D_004C2888;
extern u8 D_004F7F52[];

s32 func_00422740(s8 *s, s32 x, s32 y, s32 z, s32 a5, s32 fp, s32 a7) {
    extern void func_00422BE0(s32 *, s32);
    extern void func_00421FB0(f32, s32, s32 *, f32 *, s32);
    U4 g;
    f32 out[4];
    G4 space;
    G4 h;
    s32 i;
    s32 adv;
    s32 dx;
    s32 dy;
    s32 c;
    s32 w;
    F4 *tab;
    u32 t;
    tab = D_004A6F80;
    space = D_004AA970;
    adv = 0;
    i = 0;
    for (;;) {
        dy = 0; dx = 0;
        c = s[i++];
        if (c == 0) break;
        if (c >= 0x30 && c < 0x3A) {
            g.f = *(F4 *)((u8 *)D_004A6F80 + 0x100 + (c - 0x30) * 16);
        } else if (c >= 0x41 && c < 0x5B) {
            g.f = *(F4 *)((u8 *)D_004A6F80 + 0x1A0 + (c - 0x41) * 16);
        } else if (c >= 0x61 && c < 0x7B) {
            g.f = *(F4 *)((u8 *)D_004A6F80 + 0x340 + (c - 0x61) * 16);
        } else if (c == 0x23) {
            g.f = D_004A88A0[0]; dx = 2; dy = 1;
        } else if (c == 0x24) {
            g.f = D_004A88A0[0]; dx = 2; dy = 1;
        } else if (c == 0x25) {
            g.f = D_004A88A0[0]; dx = 2; dy = 1;
        } else if (c == 0x3A) {
            g.f = *(F4 *)((u8 *)tab + 0x910);
        } else if (c == 0x2B) {
            g.f = *(F4 *)((u8 *)tab + 0x500);
        } else if (c == 0x2F) {
            g.f = *(F4 *)((u8 *)tab + 0x510);
        } else if (c == 0x2C) {
            g.f = *(F4 *)((u8 *)tab + 0x950); dy = 2;
        } else if (c == 0x20) {
            g.i = space;
        } else if (c == 0x2D) {
            g.f = *(F4 *)((u8 *)tab + 0x920);
        } else {
            continue;
        }
        out[1] = (f32)g.i.v[1] / (f32)fp;
        out[0] = (f32)g.i.v[0] / (f32)a7;
        out[2] = (f32)g.i.v[2] / (f32)fp;
        out[3] = (f32)g.i.v[3] / (f32)a7;
        h = g.i;
        g.i.v[0] = x + adv + dx;
        w = h.v[2] - h.v[0];
        g.i.v[1] = y + dy;
        g.i.v[2] = dx + (g.i.v[0] + w);
        g.i.v[3] = dy + (g.i.v[1] + (h.v[3] - h.v[1]));
        t = D_004F7F52[0];
        if (t != 0) func_00422BE0(&a5, (t & 0xFF) + 0x60);
        func_00421FB0((f32)z, D_004C2888, (s32 *)&g, out, a5);
        adv += w;
    }
    return 0;
}
