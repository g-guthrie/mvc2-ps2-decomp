typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 *D_004C2840;
extern u8 D_004F1D20[];
extern s32 D_004F1D24[];
extern f32 D_004F1D2C[];
extern u8 D_004F1D29[];
extern u8 D_004F1D2A[];
extern u8 D_004F1D2B[];
extern u8 D_00477148[];

void residual_003D1A30(void)
{
    extern s32 func_0012E560(void);
    extern void func_003D6D50(void);
    extern void func_003D6E20(void);
    extern void func_001E2130(void);
    extern void func_001E2330(void);
    extern void func_00170160(s32);
    extern void func_003DA410(void);
    extern void func_00122DA0(void);
    extern void func_0016CDA0(void);
    extern void func_00329890(void);
    extern void func_00122840(s32);
    extern void func_0016F090(void *);
    extern void func_0016F0C0(f32);
    extern void func_0016D160(void);
    extern void func_00140500(void);
    extern void func_0013FE60(s32, s32);
    extern void func_00140E90(s32, s32);
    extern void func_0016D190(void);
    extern void func_003298B0(s32, s32, s32);
    extern void func_003D1F90(void);
    extern void func_003D7310(void *);
    extern void func_00152790(void);

    if (func_0012E560() != 0) {
        D_004C2840[2]++;
        *(s16 *)(D_004C2840 + 8) = 0x348;
        *(s16 *)(D_004C2840 + 0xA) = -0x5A;
        func_003D6D50();
        func_003D6E20();
        func_001E2130();
        func_001E2330();
        func_00170160(0x19);
        func_003DA410();
        func_00122DA0();
        func_0016CDA0();
        func_00329890();
        func_00122840(0);
        func_0016F090(D_00477148);
        func_0016F0C0(1.0f);
        func_0016D160();
        D_004F1D20[0] = 1;
        D_004F1D24[0] = 0x5B;
        D_004F1D2C[0] = 1780.0f;
        D_004F1D29[0] = 0x13;
        D_004F1D2A[0] = 0x18;
        D_004F1D2B[0] = 0x5B;
        func_00140500();
        func_0013FE60(0x800, 0);
        func_00140E90(0x800, 0);
        func_0016D190();
        func_003298B0(-1, 0x3C, 0);
        func_003D1F90();
        func_003D7310(func_00152790);
    }
}
