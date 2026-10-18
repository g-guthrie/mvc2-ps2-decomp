typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C22D4;
extern volatile s32 D_004C2320;
extern s32 D_004C2394;

void func_003FDCD0(void) {
    extern void func_003FE1F8(s32);
    extern s32 func_00103CD0();
    extern void func_00103C70(s32, s32);
    s32 v = D_004C22D4 - 1;
    D_004C22D4 = v;
    if (v == 0) {
        D_004C22D4 = 0;
        func_003FE1F8(D_004C2320);
        { register s32 j __asm__("$3"); j = D_004C2320; }
        func_00103C70(func_00103CD0(), D_004C2394);
    }
    if (D_004C22D4 < 0) D_004C22D4 = 0;
}
