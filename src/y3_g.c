typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x94]; u32 f94; } G3D_p;
extern G3D_p *D_004C2840;
extern s8 D_004F1CD9[];
extern f32 D_004F1D2C[];
void func_003D1410(void) {
    s32 c = D_004F1CD9[0];
    switch (c) {
    case 0:
        if (D_004C2840->f94 >= 0x2D0) {
            D_004F1CD9[0] = c + 1;
        }
        break;
    case 1: {
        G3D_p *g = D_004C2840;
        u32 *q = &g->f94;
        f32 f = (f32)(g->f94 - 0x2D0);
        D_004F1D2C[0] = 5000.0f + 100000.0f * (f / 480.0f);
        if (*q >= 0x4B0) {
            D_004F1CD9[0] = *(volatile s8 *)D_004F1CD9 + 1;
        }
        break;
    }
    }
}

