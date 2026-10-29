/* r12_01: MW 3.0, -O3 -Op -fp off -sdatathreshold 8, built WARM after src/r3_2_a.c in the same mwccps2 invocation
   (MWWARM_30@src/r3_2_a.c). src/r3_2_a.c (func_001001E0, the nearest preceding MW double-arithmetic function,
   tools/nearwarm.py 0x122960 MWCCPS2) now uses native double arithmetic so it really lowers dpadd itself. Cold: 8 words (a0 temps where retail has a2). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;



extern u8 D_004F1CF4[], D_004F1CF5[], D_004F1CF6[];
extern u8 D_004F1CF8[], D_004F1CF9[], D_004F1CFA[];
extern u8 D_004F1CFC[], D_004F1CFD[], D_004F1CFE[];
extern s32 D_004F1CF0[];
extern s32 D_004F1CBC[];
extern f32 D_004F1D0C[], D_004F1D10[], D_004F1D14[];
typedef struct { u8 pad0[6]; u8 b6; u8 pad1[0x6F]; u8 b76; } G122960;
extern G122960 *D_004C2794;

void func_00122960(u32 *a0, u32 *a1, u32 *a2) {
    extern s32 func_0016D130();
    f32 r, g, b;
    if (func_0016D130(a0, a1, a2) != 0) {
        D_004F1CF0[0] = 0;
        *a0 = D_004F1CBC[0];
        return;
    }
    if (D_004C2794->b76 != 0 && D_004C2794->b6 != 0) {
        D_004F1CF0[0] = 0;
        *a0 = 0;
        return;
    }
    r = D_004F1D0C[0];
    g = D_004F1D10[0];
    b = D_004F1D14[0];
    switch (D_004F1CF0[0]) {
    case 3:
        *a2 = ((u8)(u32)(r * (f32)(u32)D_004F1CFE[0]) << 16) | ((u8)(u32)(g * (f32)(u32)D_004F1CFD[0]) << 8) | (u8)(u32)(b * (f32)(u32)D_004F1CFC[0]);
    case 2:
    case 1:
        *a1 = ((u8)(u32)(r * (f32)(u32)D_004F1CFA[0]) << 16) | ((u8)(u32)(g * (f32)(u32)D_004F1CF9[0]) << 8) | (u8)(u32)(b * (f32)(u32)D_004F1CF8[0]);
    case 0:
        *a0 = ((u8)(u32)(r * (f32)(u32)D_004F1CF6[0]) << 16) | ((u8)(u32)(g * (f32)(u32)D_004F1CF5[0]) << 8) | (u8)(u32)(b * (f32)(u32)D_004F1CF4[0]);
    }
}
