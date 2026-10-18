typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed long s64;

extern void func_00402498();
extern void func_003FD928();
extern void func_00103C70();
extern void func_00103D10();
extern void func_00103D70();
extern volatile s32 D_004C2388;
extern volatile s64 D_004C2380;
extern volatile s64 D_004C2378;
extern volatile s32 D_004C2334;
extern volatile s32 D_004C24C8;

void func_003FECC0(void) {
    if (D_004C2388 == 0) {
        D_004C2388 = 1;
        func_00402498();
        func_003FD928();
        D_004C2388 = 0;
    }
}
