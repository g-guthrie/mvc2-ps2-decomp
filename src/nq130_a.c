typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 D_004F1D24[];
extern u8 D_004F1D29[];
extern u8 D_004F1D2A[];
extern u8 D_004F1D2B[];
extern f32 D_004F1D2C[];
extern u16 D_004F4480[];
extern u16 D_004F4494[];

void func_00176770(void)
{
    extern void func_0016F0D0(void);
    extern void func_0016D190(void);
    u8 *g;
    s16 *h;

    h = (s16 *)(D_004C2840 + 0xE);
    if (*h != 0) {
        *h = *h - 1;
        D_004F1D24[0] = (*(s16 *)(D_004C2840 + 0xE) << 5) / 60 + 10;
        D_004F1D2C[0] = 5.0f + 8995.0f / (f32)(2 << (60 - *(s16 *)(D_004C2840 + 0xE)));
        D_004F1D29[0] -= 4;
        D_004F1D2A[0] -= 4;
        D_004F1D2B[0] -= 4;
        if (D_004F1D2C[0] < 5.0f) {
            *(s16 *)(D_004C2840 + 0xE) = 0;
            D_004F1D24[0] = 10;
            D_004F1D2C[0] = 5.0f;
            D_004F1D29[0] = 0;
            D_004F1D2A[0] = 0;
            D_004F1D2B[0] = 0;
        }
    }
    func_0016F0D0();
    func_0016D190();
    h = (s16 *)(D_004C2840 + 0x8);
    if (*h != 0) {
        *h = *h - 1;
    }
    g = D_004C2840;
    if (*(s8 *)(g + 0x2A) == 0 && *(s8 *)(g + 0x18) != 0) return;
    if ((D_004F4480[0] & 0x8000) == 0 && (D_004F4494[0] & 0x8000) == 0 && *(s16 *)(g + 8) != 0) return;
    *(s8 *)(g + 3) = *(s8 *)(g + 3) + 1;
}
