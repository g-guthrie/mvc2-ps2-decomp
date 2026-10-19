typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1D20[];
extern s32 D_004F1D24[];
extern f32 D_004F1D2C[];
extern u8 D_004F1D29[];
extern u8 D_004F1D2A[];
extern u8 D_004F1D2B[];
extern u8 *D_004C2650;
extern u8 *D_004CACB0[];
extern signed char *D_004C2840;

extern void func_003DA410(void);
extern void func_003D6D50(void);
extern void func_003D6E20(void);
extern void func_0016CDA0(void);
extern void func_0016D160(void);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_001E2330(void);
extern void func_001E2130(void);
extern void func_00170160(s32);
extern void func_0012E780(s32);
extern void func_00143860(void);
extern void func_00143430(void);
extern void func_001434A0(void);
extern void func_001428E0(void);
extern void func_001E3F50(s32);

void func_00143920(void)
{
    s32 i;

    func_003DA410();
    func_003D6D50();
    func_003D6E20();
    func_0016CDA0();
    func_0016D160();
    D_004F1D20[0] = 0;
    D_004F1D24[0] = 6;
    D_004F1D2C[0] = 2800.0f;
    D_004F1D29[0] = 0x90;
    D_004F1D2A[0] = 0xB0;
    D_004F1D2B[0] = 0xC0;
    D_004C2650 = func_003DA750(0, 0xD, 1);
    for (i = 0; i < 0x28; i++) {
        D_004CACB0[i] = func_003DA750(0, 0xD, 1);
        D_004CACB0[i][0x24] = 0;
    }
    func_001E2330();
    func_001E2130();
    func_00170160(0xC);
    func_0012E780(5);
    *(s16 *)(D_004C2840 + 10) = 0;
    func_00143860();
    func_00143430();
    func_001434A0();
    func_001428E0();
    D_004C2840[2] = (signed char)(D_004C2840[2] + 1);
    func_001E3F50(0x13);
}
