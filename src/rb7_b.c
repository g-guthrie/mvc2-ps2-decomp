typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x85]; s8 f85; u8 pad2[2]; s8 f88; s8 f89; u8 pad3[0x25]; u8 fAF; } Gb;
extern Gb *D_004C2840;
extern u8 D_004C27D0;
extern u8 D_0045E350[];
extern s8 D_004F25D4[];
extern s8 D_004F2B8C[];

void func_0032E410(void)
{
    extern s32 func_00417A40();
    Gb *g;
    s32 m;
    s32 b;
    if ((m = (g = D_004C2840)->f89 | (b = g->f88)) == 3) {
        s32 r = func_00417A40() % 6;
        s32 k = func_00417A40() % 4;
        D_004C27D0 = (D_0045E350 + k * 8)[r];
        D_004C2840->fAF = 0;
        return;
    }
    if (m == 1) {
        D_004C27D0 = (D_0045E350 + D_004F25D4[0] * 8)[g->f85];
    } else {
        D_004C27D0 = (D_0045E350 + D_004F2B8C[0] * 8)[g->f85];
    }
    if (D_004C27D0 == 8) g->fAF = 1;
    else g->fAF = 0;
}
