typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern volatile u64 D_004C2380;
extern volatile u64 D_004C2378;
extern volatile s32 D_004C2334;
extern s32 func_00103C70(s32, s32);
extern s32 func_00103D10(s32);
extern s32 func_00103D70(s32);

void func_003FE780(void) {
    if (D_004C2380 == 0) {
        do {
            D_004C2378 = 1;
            func_00103C70(D_004C2334, 1);
            func_00103D10(D_004C2334);
            func_00103D70(D_004C2334);
        } while (D_004C2380 == 0);
    }
    D_004C2380 = 0;
    D_004C2378 = 0;
    D_004C2334 = 0;
}

extern volatile u64 D_004C2340;
extern volatile u64 D_004C2338;
extern volatile s32 D_004C2320;

void func_003FE940(void) {
    if (D_004C2340 == 0) {
        do {
            D_004C2338 = 1;
            func_00103C70(D_004C2320, 1);
            func_00103D10(D_004C2320);
            func_00103D70(D_004C2320);
        } while (D_004C2340 == 0);
    }
    D_004C2340 = 0;
    D_004C2338 = 0;
    D_004C2320 = 0;
}
