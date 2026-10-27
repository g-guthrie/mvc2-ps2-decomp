typedef unsigned char u8;
typedef signed int s32;

extern s32 func_003299D0(void);
extern u8 D_004C2B58;
extern void (*D_0043CD0C)(s32, s32) __attribute__((section(".data")));
extern void func_0041C200(s32, s32);
extern u8 *D_004C2840;

void func_0041C460(s32 state_unused, s32 mode_unused)
{
    if (func_003299D0() == 0) {
        D_004C2B58 = 0;
        D_0043CD0C = func_0041C200;
        D_004C2840[3] = 1;
        D_004C2840[5] = 0;
    }
}
