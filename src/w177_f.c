typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[0x36]; s8 b36[1]; } GI;
typedef struct { u8 p0[0x58]; s8 b58; } GJ;
typedef struct { u8 p0[2]; u8 b2; u8 p3[0x1B6-3]; u8 b1b6; u8 p1b7[0x1CC-0x1B7]; s32 w1cc; s32 w1d0; u8 p1d4[0x216-0x1D4]; u8 b216; u8 p217[0x427-0x217]; u8 b427; s32 w428; s32 w42c; u8 p430[4]; s16 h434; u8 p436[2]; s16 h438; } PM;
extern GI *D_004C2794;
extern GJ *D_004C2840;
extern s32 D_004D18A8[];
extern u8 D_004D18A7[];
extern s32 D_004D18AC[];
void func_0018FEB0(PM *p) {
    extern void func_00175C00(PM *, s32);
    extern void func_00327CF0(PM *, s32);
    extern void func_0016EDA0(s32, s32);
    p->h438 = 0;
    p->h434 = 0;
    D_004D18A8[0] = p->w1d0;
    D_004D18A7[0] = p->b1b6;
    D_004D18AC[0] = p->w1cc;
    if ((p->w428 & 0x100000) | (p->w42c & 0x4000000)) {
        p->b216 = 0;
        func_00175C00(p, 1);
    }
    if (D_004C2840->b58 != 0) {
        D_004C2794->b36[p->b2]++;
        if (p->b427 == 0) func_00327CF0(p, 3);
    } else {
        s8 v;
        v = D_004C2794->b36[p->b2] + 1;
        D_004C2794->b36[p->b2] = v;
        if (v < 3) func_00327CF0(p, 3);
    }
    func_0016EDA0(p->b2, 6);
}
