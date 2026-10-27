/* hk10_b: EE GCC candidates */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed long long s64;

extern volatile s64 D_004C2368;
extern volatile s64 D_004C2308;
extern volatile s32 D_004C22E4;
extern volatile s32 D_004C22D8;
extern volatile s32 D_004C2334;
extern volatile s64 D_004C2370;

extern s64 func_00411AD0();
extern void func_003FE170();
extern s32 func_003FE4F0();
extern s32 func_003FE190(s32);
extern void func_003FE120(s32);
extern s32 func_00103C20();

s32 func_003FDF78(void)
{
    s64 r;
    s32 one;
    if (D_004C2368 == 0) {
        one = 1;
        do {
            D_004C2308++;
            D_004C22E4 = one;
            r = func_00411AD0();
            D_004C22E4 = 0;
            if (D_004C22D8 == one) {
                D_004C22D8 = 0;
                func_003FE170();
            }
            if (r == 0) {
                if (func_003FE4F0() == one) {
                    if (func_003FE190(D_004C2334) == D_004C2334) {
                        func_003FE120(D_004C2334);
                    }
                }
                func_003FE170();
            }
        } while (D_004C2368 == 0);
    }
    D_004C2370 = 1;
    return func_00103C20();
}
