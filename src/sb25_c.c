typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GGc {
    u8 pad[0x7C];
    s16 h7C[8];
} GGc;

typedef struct SSc {
    u8 pad0[2];
    u8 b2;
    u8 pad1[3];
    u8 b6;
    u8 b7;
    u8 pad2[0x1E - 8];
    s16 h1E;
    u8 pad3[0x5C - 0x20];
    s32 w5C;
    s32 w60;
    u8 pad4[0x68 - 0x64];
    s32 w68;
    s32 w6C;
    u8 pad5[0x1B2 - 0x70];
    u8 b1B2;
    u8 pad6[2];
    u8 b1B5;
    u8 pad7[0x1C0 - 0x1B6];
    u16 h1C0;
    u8 pad8[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 pad9[0x4F4 - 0x1DC];
    u16 h4F4;
} SSc;

extern GGc *D_004C2794;
extern u8 D_004F1F45[];
extern u8 D_004F1F46[];

s32 func_00267B00(SSc *p) {
    extern void func_001757E0(SSc *, s32, s32);
    extern void func_001E3210(SSc *, s32);
    extern void func_001E3710(SSc *, s32);
    u32 f = p->h4F4;
    if (f & 0x200) {
        p->b7 = 3;
        p->w5C = 0;
        p->w60 = 0;
        p->w68 = 0;
        p->w6C = 0;
        p->b1B5 = 0x43;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        func_001757E0(p, 0x16, 0x20);
        D_004F1F45[0] = 1;
        D_004F1F46[0] = 1;
        func_001E3210(p, 0x25);
        return 1;
    }
    if (f & 0x100) {
        p->b7 = 4;
        p->w5C = 0;
        p->w60 = 0;
        p->w68 = 0;
        p->w6C = 0;
        p->b1B5 = 0x44;
        p->b1B2 = p->h1C0 = 0;
        p->w1D8 = 0;
        D_004C2794->h7C[p->b2]++;
        func_001757E0(p, 0x16, 0x34);
        D_004F1F45[0] = 1;
        D_004F1F46[0] = 1;
        func_001E3210(p, 0x25);
        return 1;
    }
    if (f & 0x60) goto L;
    return 0;
L:
    p->b6 = 2;
    p->b7 = 0;
    p->h1E = 0;
    p->w5C = 0;
    p->w60 = 0;
    p->w68 = 0;
    p->w6C = 0;
    func_001757E0(p, 0x16, 0x21);
    func_001E3210(p, 0x25);
    func_001E3710(p, 0x4C);
    return 1;
}
