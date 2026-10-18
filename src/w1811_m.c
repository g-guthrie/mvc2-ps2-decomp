typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GG {
    u8 pad0[0x7C];
    s16 f7c[1];
} GG;

typedef struct O {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x168 - 3];
    u8 b168;
    u8 pad169[0x1B2 - 0x169];
    u8 b1B2;
    u8 pad1B3[2];
    u8 b1B5;
    u8 pad1B6[5];
    u8 b1BB;
    u8 pad1BC[4];
    u16 s1C0;
    u8 pad1C2[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 pad1DC[0x1EA - 0x1DC];
    s8 b1EA;
    u8 pad1EB[0x1FC - 0x1EB];
    u8 b1FC;
    u8 pad1FD[0x210 - 0x1FD];
    u8 b210;
    u8 pad211[0x408 - 0x211];
    s32 *w408;
} O;

extern s32 D_004C07A4, D_004C07A8, D_004C07AC, D_004C07BC, D_004C07C0, D_004C07C4;
extern GG *D_004C2794;

void func_002743F0(O *p) {
    extern void func_001757E0(O *, s32, s32);
    u32 t;
    switch (p->b1FC) {
    case 0:
        p->b168 = 0;
        p->b1B5 = 0xF;
        if (p->b210 == 0) p->w408 = &D_004C07A4; else p->w408 = &D_004C07BC;
        p->b1BB = 0;
        break;
    case 1:
        p->b168 = 1;
        p->b1B5 = 0x10;
        if (p->b210 == 0) p->w408 = &D_004C07A8; else p->w408 = &D_004C07C0;
        p->b1BB = 1;
        break;
    case 2:
        p->b168 = 2;
        p->b1B5 = 0x11;
        if (p->b210 == 0) p->w408 = &D_004C07AC; else p->w408 = &D_004C07C4;
        p->b1BB = 2;
        break;
    }
    t = p->b1B5;
    p->b1B5 = t;
    p->b1B2 = p->s1C0 = 0;
    p->w1D8 = 0;
    D_004C2794->f7c[p->b2]++;
    func_001757E0(p, 0xC, p->b168);
    if ((p->b1EA & 0xF0) != 0) {
        p->b1EA = p->b1EA - 0x10;
    }
}
