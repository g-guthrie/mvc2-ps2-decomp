typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[4]; s8 b4; u8 b5; s8 b6; u8 p7; s16 h8; s16 hA; s16 hC; s16 hE; u8 p10[9]; u8 b19; } G6B;
extern G6B *D_004C2840;
extern u8 *D_004C2678;
extern u8 *D_004C2674;
extern u8 D_004C2670, D_004C2664, D_004C2668, D_004C266C;
extern u8 D_004B42B0[], D_00446250[], D_004462A0[];
extern u8 D_004F1D20[], D_004F1D24[], D_004F1D29[], D_004F1D2A[], D_004F1D2B[], D_004F1D2C[];

void func_0016B440(void)
{
    extern void func_001E23A0(void);
    extern void func_003DA410(void);
    extern void func_0016F040(void);
    extern void func_0016F090(u8 *);
    extern void func_0016F0C0(f32);
    extern void func_003D6D50(void);
    extern void func_003D6E20(void);
    extern void func_00170160(int);
    extern void func_00122DA0(void);
    extern void func_00122840(u32);
    extern void func_0016CDA0(void);
    extern void func_003298B0(s32, s32, s32);
    extern void func_0016D160(void);
    extern void func_0016D190(void);
    extern void func_001E3F50(s32);
    extern void func_001E4340(s32);
    extern void func_001E3FE0(void);
    if (D_004C2840->b6 == 0) {
        D_004C2840->b5 = 0;
        D_004C2840->b6 = D_004C2840->b6 + 1;
        D_004C2840->b19 = 1;
        D_004C2840->h8 = 0x1770;
        D_004C2840->hA = 0;
        D_004C2840->hC = 1;
        D_004C2840->hE = 0x3C;
        D_004C2678 = D_004B42B0;
        D_004C2674 = D_00446250;
        D_004C2670 = 1;
        D_004C2664 = 0;
        D_004C2668 = 0;
        D_004C266C = 0;
        func_001E23A0();
        func_003DA410();
        func_0016F040();
        func_0016F090(D_004462A0);
        func_0016F0C0(1.0f);
        func_003D6D50();
        func_003D6E20();
        func_00170160(9);
        func_00122DA0();
        func_00122840(0xFF000000);
        func_0016CDA0();
        func_003298B0(-1, 0x3C, 0);
        func_0016D160();
        D_004F1D20[0] = 0;
        *(s32 *)D_004F1D24 = 0x80;
        D_004F1D29[0] = 0;
        *(s32 *)D_004F1D2C = 0x460CA000;
        D_004F1D2A[0] = 0xB0;
        D_004F1D2B[0] = 0xE0;
        func_0016D190();
    } else {
        D_004C2840->b4 = D_004C2840->b4 + 1;
        D_004C2840->b6 = 0;
        func_001E3F50(0x14);
        func_001E4340(1);
        func_001E3FE0();
    }
}
