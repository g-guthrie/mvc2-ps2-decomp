typedef signed char s8;
extern s8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_00123090(void);
extern void func_00122FE0(void);
extern void func_00123060(void);
extern void func_00151A20(int);
extern void func_001520E0(int);
extern void func_0016E080(void);
void func_00152570(void)
{
    if (D_004C2840[0x92] < 2) {
        func_00123090();
        func_00151A20(13); func_001520E0(13);
        func_00122FE0();
        func_00151A20(6); func_001520E0(6);
        func_00123060();
        func_00151A20(8); func_001520E0(8);
        func_00151A20(1); func_001520E0(1);
        func_0016E080();
    }
}
