typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { u8 pad0[0x5C]; f32 f5C; u32 u60; u8 pad1[0x1C4-0x64]; s32 p1C4; } SX;
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);

void func_002B0550(u8 *p) {
    u8 *q;
    u32 *pm;
    f32 *pp;
    s32 h;
    f32 kk;
    s32 fl;
    SX *sa;
    sa = (SX *)p;
    p[0x40C] = 2;
    p[0x33C] = 5;
    fl = *(s8 *)(p + 0x1B2);
    if (fl == 0) {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            p[6] = 7;
            *(f32 *)(p + 0x68) = p[0x1E6] ? -0.4166666567325592f : 0.4166666567325592f;
            func_001757E0(p, 0x16, 2);
        }
    } else
    if (((s8)fl & 1) != 0 || *(u8 *)(*(s32 *)(p + 0x1C4) + 3) != 0) {
        p[6] = 8;
        p[0x20D] = 2;
        *(u32 *)(p + 0x5C) = 0x40555555;
        if (p[0x1E6] != 0) sa->f5C = -sa->f5C;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40D55555;
        if (p[0x1B7] != 0) sa->u60 = 0x41555555;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x16, 4);
    } else {
        p[6] = 10;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x68) = 0;
        pm = (u32 *)(p + 0x428);
        if ((*pm & 0x7000000) == 0) {
            *(u8 *)(sa->p1C4 + 0x20D) = 0;
            *(f32 *)(sa->p1C4 + 0x38) = *(f32 *)(p + 0x430);
            *(f32 *)(sa->p1C4 + 0x34) = *(f32 *)(p + 0x34);
        }
        *(u32 *)(p + 0x2B8) = 0x43055555;
        pp = (f32 *)(p + 0x2B8);
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *pp = -*pp;
        }
        if ((*pm & 0x7000000) == 0) {
            q = (u8 *)*(s32 *)(p + 0x1C4);
            if (*(s16 *)(q + 0x434) != 0) *(f32 *)(q + 0x34) = *(f32 *)(p + 0x34) - *(f32 *)(p + 0x2B8);
        }
        func_001757E0(p, 0x16, 0x11);
        q = (u8 *)*(s32 *)(p + 0x1C4);
        q[0x1B4] = 0x14;
        *(s32 *)(p + 0x2D0) = *(s32 *)(p + 0x1C4);
    }
}
