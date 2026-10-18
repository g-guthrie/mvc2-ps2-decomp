typedef long s64;
typedef int s32;
extern volatile s64 D_004C2350;
extern volatile s64 D_004C2348;
extern volatile s32 D_004C2324;
extern void func_00103C70(s32, s32), func_00103D10(s32), func_00103D70(s32);
void func_003FE8D0(void) {
    if (D_004C2350 == 0) {
        do {
        register s64 j __asm__("$3");
        D_004C2348 = 1;
        func_00103C70(D_004C2324, 1);
        func_00103D10(D_004C2324);
        func_00103D70(D_004C2324);
        j = D_004C2350;
        if (j != 0) break;
        } while (1);
    }
    D_004C2350 = 0;
    D_004C2348 = 0;
    D_004C2324 = 0;
}
