typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern s32 func_003FE780(void);
extern s32 func_003FE940(void);
extern s32 D_004C22CC;
extern s32 D_004C22D0;
extern s32 D_004C232C;
extern s32 D_004C239C;
extern s32 func_003FE7F0(void);
extern s32 func_003FE860(void);
extern s32 func_003FE8D0(void);
extern s32 func_00411898(s32, s32);
extern s32 func_004118A8(s32, s32);
extern s32 func_00411BC8(void);

void func_003FEEA8(void) {
    if (--D_004C22CC == 0) {
        func_003FE780();
        func_003FE7F0();
        func_003FE860();
        func_003FE8D0();
        func_003FE940();
        func_00103C70(D_004C232C, D_004C239C);
        func_00411898(0, 0);
        func_004118A8(0, 0);
        D_004C22D0 = 0;
        func_00411BC8();
        __asm__ volatile("");
    }
}
