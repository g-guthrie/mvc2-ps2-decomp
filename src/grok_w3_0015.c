typedef signed char s8;
typedef signed int s32;

extern void func_00123090(void);
extern void func_00122FE0(void);
extern void func_00151A20(s32);
extern void func_001520E0(s32);
extern s8 *D_004C2840;

void func_00152600(void) {
    if (D_004C2840[0x92] < 2) {
        func_00123090();
        func_00151A20(13);
        func_001520E0(13);
        func_00122FE0();
        func_00151A20(6);
        func_001520E0(6);
    }
}
