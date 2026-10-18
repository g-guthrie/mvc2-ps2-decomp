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
    u8 pad3[3];
    u8 b6;
    u8 pad7[0x1C - 7];
    s16 s1C;
    u8 pad1E[0x23 - 0x1E];
    u8 b23;
    u8 pad24[0x38 - 0x24];
    f32 f38;
    u8 pad3C[0x60 - 0x3C];
    f32 f60;
    u8 pad64[0x6C - 0x64];
    f32 f6C;
    u8 pad70[0x151 - 0x70];
    s8 b151;
    u8 pad152[0x1B2 - 0x152];
    s8 b1B2;
    u8 pad1B3[2];
    s8 b1B5;
    u8 pad1B6;
    s8 b1B7;
    u8 pad1B8[0x1C0 - 0x1B8];
    u16 s1C0;
    u8 pad1C2[0x1D8 - 0x1C2];
    s32 w1D8;
} O;

extern GG *D_004C2794;

void func_002597B0(O *p) {
    extern void func_00175700(O *);
    extern void func_0036A8D0(O *, s32);
    s16 v;
    u32 t;
    if (p->f60 < 0.0f) {
        t = p->b6;
        p->b6 = t + 1;
        func_00175700(p);
        return;
    }
    v = p->s1C - 1;
    p->s1C = v;
    if (v == 0) {
        if (p->b1B2 != 0) {
            t = p->b23;
            p->b23 = t + 1;
        }
        if (p->b23 < 3) {
            if (p->b23 == 2) {
                p->b1B5 = p->b1B7 + 0x52;
                p->b1B2 = p->s1C0 = 0;
                p->w1D8 = 0;
                D_004C2794->f7c[p->b2]++;
            } else {
                p->b1B5 = p->b1B7 + 0x34;
                p->b1B2 = p->s1C0 = 0;
                p->w1D8 = 0;
                D_004C2794->f7c[p->b2]++;
            }
        }
        func_0036A8D0(p, 1);
        func_0036A8D0(p, 2);
        p->s1C = 6;
    }
    p->f38 += p->f60;
    p->f60 += p->f6C;
    if (p->b151 == 0) {
        func_00175700(p);
    }
}
