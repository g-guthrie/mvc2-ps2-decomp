typedef unsigned char u8;
typedef int s32;

extern s32 D_004C253C;
extern s32 D_006340C0[];
extern u8 D_00634030[];
extern void func_00423890(void);

s32 func_004238A0(s32 a, s32 b) {
    extern void func_00103E20(s32);
    extern void func_00103E00(s32);
    extern s32 func_00106E68(u8 *, s32, s32, void *, s32, void *, s32, void *, s32);
    func_00103E20(D_004C253C);
    D_006340C0[0] = b;
    if (func_00106E68(D_00634030, a, 1, D_006340C0, 0x10, D_006340C0, 0x10, func_00423890, D_004C253C) < 0) {
        func_00103E00(D_004C253C);
        return -9;
    }
    return 0;
}
