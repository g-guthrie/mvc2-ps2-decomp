typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/w20b2_b.c "-O3 -sdatathreshold 8" */
typedef struct { s16 h0; s16 h2; s32 w4; s32 w8; s32 wc; } E_b;
typedef struct { s32 a; s32 b; } T_b;
extern s8 D_0057ED70[];
extern s32 D_0057FB70[];
extern T_b D_0057E570[];
extern s32 D_004C28A8;
extern s32 D_004C28A4;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G_g;
extern G_g *D_004C2794;
typedef struct {
    u8 pad0[2]; u8 b2; u8 pad3[3]; u8 b6; u8 pad7[0x1C - 7]; s16 h1c; s16 h1e;
    u8 pad20[0x151 - 0x20]; s8 b151; u8 pad152[0x15B - 0x152]; u8 b15b;
    u8 pad15c[0x1B2 - 0x15C]; u8 b1b2; u8 pad1b3[2]; u8 b1b5;
    u8 pad1b6[0x1C0 - 0x1B6]; u16 h1c0; u8 pad1c2[0x1D8 - 0x1C2]; s32 w1d8; s32 w1dc;
} P_g;

void func_0031AD00(P_g *p) {
    extern s32 func_00182E20(P_g *);
    extern s32 func_00182D30(s32);
    extern void func_00175700(P_g *);
    extern void func_0018FC10(s32, s32);
    extern void func_001266A0(P_g *, s32, s32);
    extern void func_001757E0(P_g *, s32, s32);
    extern void func_00175C00(P_g *, s32);
    extern void func_00176160(P_g *, s32, s32, s32);
    s32 v;
    if (p->h1e > 0) {
        s16 h = p->h1e - 1;
        p->h1e = h;
        if (h == 0) {
            p->h1e = 0;
            p->h1c = 0;
        }
    }
    if (func_00182E20(p) != 0) {
        if (p->h1e != 0) p->h1c = p->h1c + 1;
    }
    if (func_00182D30(p->w1dc) != 0) p->h1c = 0;
    func_00175700(p);
    if (p->b15b != 0) {
        s16 h;
        u32 t;
        p->b15b = 0;
        func_0018FC10(p->w1dc, -1);
        h = p->h1c - 1;
        p->h1c = h;
        if (h <= 0) {
            t = p->b6;
            p->b6 = t + 1;
            func_001266A0(p, 0, 0);
            p->b1b5 = 0x23;
            p->b1b2 = p->h1c0 = 0;
            p->w1d8 = 0;
            D_004C2794->h7c[p->b2] += 1;
            func_001757E0(p, 0xF, 4);
            func_00175C00(p, 0);
            return;
        }
    }
    v = p->b151;
    if (v != 0) {
        p->b151 = 0;
        if (v - 4 == 0) {
            func_00175C00(p, 0);
        } else {
            func_00176160(p, 0, 4, 1);
        }
    }
}
