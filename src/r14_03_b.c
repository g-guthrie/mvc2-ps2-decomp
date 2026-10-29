typedef unsigned char u8;
typedef signed int s32;

extern s32 D_004399A0;
extern s32 D_004399D4;
extern volatile s32 D_004399B0;
extern s32 D_00439994;
extern s32 D_004C864C;
extern s32 D_00439990;
extern u8 D_004AB3C0[];
extern s32 D_004C8640;
extern volatile s32 D_004399D8;

void func_0010E770(void)
{
    extern void func_00103E20(s32);
    extern void func_00103C20(void);
    extern void func_00105E80(u8 *, s32, s32);
    for (;;) {
        func_00103E20(D_004399A0);
        if (D_004399D4 == -1) {
            D_004399B0 = 0;
            D_004399D4 = 0;
            D_00439994 = 0;
            D_004C864C = 0;
            func_00103C20();
        }
        if (D_00439990 > 0)
            func_00105E80(D_004AB3C0, D_004C8640, D_004399D8);
        if (D_004C8640 != 0 && D_004399D8 != 0)
            ((void (*)(s32))D_004C8640)(D_004399D8);
        D_004399B0 = 0;
    }
}
