typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
extern s8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 D_00583B9B[];
extern s8 D_004F1F47;
extern void func_001E3F50(s8);
extern void func_001E4340(u32);
extern void func_001E3FE0(void);
extern void func_00136D50(void);
extern void func_001237A0(void);
extern void func_0013CA00(void);
void func_0032A3E0(void) {
    switch (D_004C2840[5]) {
    case 0:
        D_004C2840[5]++;
        D_00583B9B[0] = 0;
        func_001E3F50(0x16);
        func_001E4340(1);
        func_001E3FE0();
        func_00136D50();
        if (D_004F1F47 != 2 && D_004C2840[0x4C] != 1)
            func_001237A0();
        break;
    case 1:
        func_001237A0();
        if (D_004F1F47 == 2)
            D_004C2840[5]++;
        break;
    case 2:
        if (D_00583B9B[0] != 1)
            return;
        if (D_004C2840[0x4C] != 1)
            D_004C2840[3] = 3;
        else
            D_004C2840[3] = 2;
        D_004C2840[4] = 0;
        D_004C2840[5] = 0;
        D_00583B9B[0] = 0;
        D_004C2840[0x19] = 0;
        func_0013CA00();
        break;
    }
}
