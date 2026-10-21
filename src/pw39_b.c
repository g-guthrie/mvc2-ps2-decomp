typedef unsigned short u16;
typedef signed short s16;
#include "runtime_span_types.h"
typedef float f32;
typedef unsigned long u64;

/* EE GCC 2.96, small-data 8: ./tryee8.sh src/pw39_b.c sn */
extern s32 D_004C24DC;
extern void func_0011D8F8(void *, s32, s32);
void func_0040FD38(void) {
    if (D_004C24DC == 0) func_0011D8F8(D_00494DD8, 0, 0xC00);
    D_004C24DC++;
}

extern volatile u64 D_004C2360;
extern volatile u64 D_004C2358;
extern volatile s32 D_004C2328;
extern s32 func_00103C70(s32, s32);
extern s32 func_00103D10(s32);
extern s32 func_00103D70(s32);
void func_003FE860(void) {
    if (D_004C2360 == 0) {
        do {
            D_004C2358 = 1;
            func_00103C70(D_004C2328, 1);
            func_00103D10(D_004C2328);
            func_00103D70(D_004C2328);
        } while (D_004C2360 == 0);
    }
    D_004C2360 = 0;
    D_004C2358 = 0;
    D_004C2328 = 0;
}
