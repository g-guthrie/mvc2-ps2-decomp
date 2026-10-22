typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x94]; u32 t; } TM;
extern TM *D_004C2840;
extern s8 D_004F1CD9[];
extern s32 D_004F1D24[];
extern f32 D_004F1D2C[];
extern s32 fptosi(f32);

void func_003D11E0(void) {
    s32 s = D_004F1CD9[0];
    f32 r;
    switch (s) {
    case 0:
        if (D_004C2840->t >= 0x7D0) D_004F1CD9[0] = s + 1;
        break;
    case 1: {
        u32 *p = &D_004C2840->t;
        r = (f32)(*p - 0x7D0) / 500.0f;
        D_004F1D24[0] = fptosi(82.0f + 18.0f * r);
        D_004F1D2C[0] = 12000.0f + 48000.0f * r;
        if (*p >= 0x9C4) D_004F1CD9[0] = D_004F1CD9[0] + 1;
        break;
    }
    case 2:
        if (D_004C2840->t >= 0x1194) D_004F1CD9[0] = s + 1;
        break;
    case 3: {
        u32 *p = &D_004C2840->t;
        r = (f32)(*p - 0x1194) / 1500.0f;
        D_004F1D24[0] = fptosi(100.0f + 20.0f * r);
        D_004F1D2C[0] = 60000.0f + 340000.0f * r;
        if (*p >= 0x1770) D_004F1CD9[0] = D_004F1CD9[0] + 1;
        break;
    }
    case 4:
        break;
    }
}
