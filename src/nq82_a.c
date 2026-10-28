typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x24]; s32 w24; } Q;
extern s32 D_00439918;
extern s32 D_0043991C;
extern u8 D_004AB2B0[];
extern u8 D_004AB2D8[];
extern Q D_004C8380[];
extern s32 func_00106C98(void *, u32, s32);
extern s32 func_0010E510(void);
extern void func_00105E80();
extern s32 func_0010D4A0(s32);

s32 func_0010D360(s32 a) {
    s32 i;
    s32 r;
    s32 k;
    D_00439918 = 1;
    while (func_00106C98(&D_004C8380[0], 0x80000100, 0), D_004C8380[0].w24 == 0) {
        i = 0x10000;
        do {
            i--;
            __asm__ volatile("nop");
        } while (i != -1);
    }
    while (func_00106C98(&D_004C8380[1], 0x80000101, 0), D_004C8380[1].w24 == 0) {
        i = 0x10000;
        do {
            i--;
            __asm__ volatile("nop");
        } while (i != -1);
    }
    r = func_0010E510();
    k = r >> 8;
    if (k != 4) {
        if (D_0043991C != 0) {
            func_00105E80(D_004AB2B0);
            func_00105E80(D_004AB2D8, 4, 0, k, r & 0xFF);
        }
        return 0;
    } else {
        return func_0010D4A0(a);
    }
}
