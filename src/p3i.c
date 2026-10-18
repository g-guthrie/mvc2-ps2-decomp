typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile long long D_004C2370;
extern volatile long long D_004C2368;
extern volatile s32 D_004C2330;
extern void func_00103C70(s32, s32);
extern void func_00103D10(s32);
extern s32 func_00103D70(s32);

void func_003FE7F0(void) {
    if (D_004C2370 == 0) {
        do {
            D_004C2368 = 1;
            func_00103C70(D_004C2330, 1);
            func_00103D10(D_004C2330);
            func_00103D70(D_004C2330);
        } while (D_004C2370 == 0);
    }
    D_004C2370 = 0;
    D_004C2368 = 0;
    D_004C2330 = 0;
}
