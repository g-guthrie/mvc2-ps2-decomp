typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct Nd { s32 a, b; struct Nd *next; s32 pad[118]; } Nd;
extern Nd D_004D3800[];
extern u32 D_004D3690[];
extern u32 D_004D3520[];
extern u16 D_004D3460[];
extern u8 D_004F1A1C[];
extern Nd *D_004C27AC;
extern u8 *D_004C27A8;
extern s16 D_004C27A4;
extern s16 D_004C27A0;

void func_003DA4A0(void) {
    extern void func_0011D8F8(void *, s32, s32);
    s32 i;
    D_004C27AC = D_004D3800;
    D_004C27A8 = D_004F1A1C;
    for (i = 0; i < 256; i++) {
        func_0011D8F8(&D_004D3800[i], 0, 0x1E4);
        if (i + 1 != 256) D_004D3800[i].next = &D_004D3800[i + 1];
    }
    for (i = 0; i < 92; i++) {
        D_004D3690[i] = 0;
        D_004D3520[i] = 0;
        D_004D3460[i] = 0;
    }
    D_004C27A4 = 0xF6;
    D_004C27A0 = 0x100;
}

typedef struct { s32 w[16]; } M21;
extern f32 D_006327B0[];
extern f32 D_006327B4[];
extern f32 D_006327B8[];
extern f32 D_006327BC[];
extern f32 D_006327C0[];
extern f32 D_006327C4[];
extern f32 D_006327C8[];
extern f32 D_006327CC[];
extern f32 D_006327D0[];
extern f32 D_006327D4[];
extern f32 D_006327D8[];
extern f32 D_006327DC[];
extern f32 D_006327E0[];
extern f32 D_006327E4[];
extern f32 D_006327E8[];
extern f32 D_006327EC[];
extern M21 *D_004C2B48;
extern s32 D_004C2B40, D_004C2B38, D_004C2B3C;

s32 func_00416AE0(f32 *p) {
    f32 *q0, *q1, *q2, *q3, *q4, *q5, *q6, *q7, *q8, *q9, *q10, *q11, *q12, *q13, *q14, *q15;
    D_004C2B48[D_004C2B38] = *(M21 *)&D_006327B0[D_004C2B40 * 16];
    if (p != 0) {
        s32 i = D_004C2B40 * 16;
        q0 = &D_006327B0[i];
        q1 = &D_006327B4[i];
        q2 = &D_006327B8[i];
        q3 = &D_006327BC[i];
        q4 = &D_006327C0[i];
        q5 = &D_006327C4[i];
        q6 = &D_006327C8[i];
        q7 = &D_006327CC[i];
        q8 = &D_006327D0[i];
        q9 = &D_006327D4[i];
        q10 = &D_006327D8[i];
        q11 = &D_006327DC[i];
        q12 = &D_006327E0[i];
        q13 = &D_006327E4[i];
        q14 = &D_006327E8[i];
        q15 = &D_006327EC[i];
        *q0 = p[0];
        *q1 = p[16];
        *q2 = p[32];
        *q3 = p[48];
        *q4 = p[64];
        *q5 = p[80];
        *q6 = p[96];
        *q7 = p[112];
        *q8 = p[128];
        *q9 = p[144];
        *q10 = p[160];
        *q11 = p[176];
        *q12 = p[192];
        *q13 = p[208];
        *q14 = p[224];
        *q15 = p[240];
    }
    D_004C2B38++;
    if (D_004C2B38 >= D_004C2B3C) {
        D_004C2B38--;
        return 0;
    }
    return 1;
}
