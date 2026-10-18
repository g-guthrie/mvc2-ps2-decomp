typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
extern s8 D_004872F0[];
extern volatile s32 D_0048732C;
extern s32 D_00487330;
extern s32 D_00487334;
extern void func_00411288();
extern void func_004112B0();
extern void func_004081C0(void *);
extern void func_00408348(void *);

void func_004084E8(void) {
    s8 *p = D_004872F0;
    func_00411288();
    if (D_0048732C == 1) {
        func_004112B0();
        return;
    }
    D_0048732C = 1;
    func_004112B0();
    if (p[1] == 1) {
        if (D_00487330 == 1) func_00411288();
        func_004081C0(p);
        if (D_00487330 == 1) func_004112B0();
    }
    if (p[1] == 2) {
        if (D_00487334 == 1) func_00411288();
        func_00408348(p);
        if (D_00487334 == 1) func_004112B0();
    }
    D_0048732C = 0;
}
