typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 count; s32 max_count; s32 init_count; s32 wait_threads; u32 attr; u32 option; } NqSema;
typedef struct { u8 pad[0x24]; s32 w24; } NqCd;
extern s32 D_0043B404;
extern NqCd D_004C8900;
extern u8 D_004C8980[];
extern s32 D_004C9EC0[];
extern u8 D_004AB5D8[];
extern u8 D_004AB5F0[];
extern u8 D_004AB618[];
extern s32 func_00103DE0(NqSema *);
extern void func_001107B8(s32, s32, s32);
extern void func_00103E20(s32);
extern void func_00106628(s32);
extern s32 func_00106C98(void *, u32, s32);
extern void func_00105E80();
extern s32 func_00106E68(void *, s32, s32, void *, s32, void *, s32, s32, s32);
extern void func_00103E00(s32);

s32 func_0010FD90(void) {
    NqSema s;
    s32 i;
    s32 r;
    if (D_0043B404 < 0) {
        s.init_count = 1;
        s.max_count = 1;
        s.option = 0;
        D_0043B404 = func_00103DE0(&s);
    }
    func_001107B8(0, 0, 0);
    func_00103E20(D_0043B404);
    func_00106628(0);
    while (1) {
        if (func_00106C98(&D_004C8900, 0x80000400, 0) < 0) {
            func_00105E80(D_004AB5D8);
            for (;;) __asm__ volatile("nop");
        }
        if (D_004C8900.w24 != 0) break;
        i = 0x100000;
        do {
            i--;
            __asm__ volatile("nop");
        } while (i != 0);
    }
    r = func_00106E68(&D_004C8900, 0xFE, 0, D_004C8980, 0x30, D_004C9EC0, 0xC, 0, 0);
    func_00103E00(D_0043B404);
    if (r < 0) {
        D_004C8900.w24 = 0;
        return r - 100;
    }
    if (D_004C9EC0[1] < 0x20A) {
        func_00105E80(D_004AB5F0);
        D_004C8900.w24 = 0;
        return -120;
    }
    if (D_004C9EC0[2] < 0x20E) {
        func_00105E80(D_004AB618);
        D_004C8900.w24 = 0;
        return -121;
    }
    return D_004C9EC0[0];
}
