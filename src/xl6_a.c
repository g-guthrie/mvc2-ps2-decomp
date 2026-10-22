typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x49]; u8 f49; u8 pad1[0x3E]; s8 f88[8]; } G_a;
extern G_a *D_004C2794;
extern u8 *D_004C2840;
extern u8 D_004BF4B0[8];
extern u8 D_004BF4B8[8];
extern u8 D_00446EC0[];
extern u8 D_00446EE0[];
extern u8 D_00446F00[];
extern u8 D_00446F90[];
extern u8 *D_00449220[];
extern s16 D_00446F80[];

#define UF(x) ((f32)(u32)(x))

s32 func_0018B890(u8 *a0, u8 *a1, u8 *a2, s32 a3)
{
    extern s32 fptosi(f32);
    u8 *tbl;
    u8 idx;
    s32 i;
    s32 hp;
    u32 v;

    f32 g5, g6, f1, f3, g4, f2, f12;
    f2 = (f32)a3;
    if (*(s8 *)(a1 + 0x539) != 0) {
        f3 = UF(D_00446EC0[D_004C2794->f49]);
        f2 *= f3 / 32.0f;
    }
    idx = a0[0x284];
    if (idx > 0x13) idx = 0x13;
    f3 = 32.0f;
    if ((a2[0x12] & 8) == 0) {
        if (a2[2] & 0x20) {
            tbl = D_00449220[D_004C2794->f88[a1[2]]];
        } else {
            tbl = D_00446F00;
        }
        f3 = UF(tbl[idx]);
    }
    if (a0[0x425] != 0) f3 += 2.0f;
    g6 = f2 * f3;
    f3 = g6 / 32.0f;
    if (f3 < 1.0f) f3 = 1.0f;
    g5 = UF(D_00446F90[a0[1]]);
    g6 = g5 / 32.0f;
    if (*(s8 *)(a0 + 0x539) != 0) {
        g4 = UF(D_00446EE0[D_004C2794->f49]);
        g6 *= g4 / 32.0f;
    }
    i = 0;
    do {
        hp = *(s16 *)(a0 + 0x434);
        if (hp <= D_00446F80[i * 2]) break;
        i++;
    } while (i < 4);
    f1 = f3 * g6;
    g5 = (f32)D_00446F80[i * 2 + 1] / 32.0f;
    f2 = g5 * f1;
    g4 = UF(D_004BF4B0[*(s8 *)(D_004C2840 + 0x1B)]) / 32.0f;
    f2 = g4 * f2;
    g6 = UF(D_004BF4B8[a1[0x557]]) / 32.0f;
    f12 = g6 * f2;
    if (f12 < 1.0f) f12 = 1.0f;
    if (*(s8 *)(*(u8 **)(a0 + 0x220) + 0x26D) >= 2) {
        f12 *= 0.875f;
        if (f12 < 1.0f) f12 = 1.0f;
    }
    if (f12 < 1.0f) f12 = 1.0f;
    v = a1[0x219];
    if (v != 0) {
        f12 *= (f32)v / 32.0f;
    } else if ((v = a1[0x402]) != 0) {
        f12 *= (f32)v / 32.0f;
    }
    v = a0[0x21A];
    if (v != 0) {
        f12 *= (f32)v / 32.0f;
    } else if ((v = a0[0x403]) != 0) {
        f12 *= (f32)v / 32.0f;
    }
    if (f12 < 1.0f) f12 = 1.0f;
    return fptosi(f12);
}
