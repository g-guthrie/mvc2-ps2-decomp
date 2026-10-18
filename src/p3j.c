typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile long long D_004C2378;
extern volatile long long D_004C2310;
extern volatile s32 D_004C22E8;
extern volatile s32 D_004C22D8;
extern volatile long long D_004C2380;
extern s32 func_00411AE8(void);
extern void func_003FE170(void);
extern void func_00103C20(void);

void func_003FE040(void) {
    s32 r;
    if (D_004C2378 == 0) {
        do {
            D_004C2310++;
            D_004C22E8 = 1;
            r = func_00411AE8();
            D_004C22E8 = 0;
            if (D_004C22D8 == 1) {
                D_004C22D8 = 0;
                func_003FE170();
            }
            if (r == 0) func_003FE170();
        } while (D_004C2378 == 0);
    }
    D_004C2380 = 1;
    func_00103C20();
}
