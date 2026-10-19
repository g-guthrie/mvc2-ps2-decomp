typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern f32 D_004BF3A8 __attribute__((section(".sdata")));
extern u8 D_004BF3AC __attribute__((section(".sdata")));
extern f32 D_004BF3B0 __attribute__((section(".sdata")));
extern u8 D_004BF3B4 __attribute__((section(".sdata")));
extern u8 *func_00147870(s32, s32);

void func_001489E0(s32 a, s32 b)
{
    f32 lo_f;
    u8 lo_b;
    f32 hi_f;
    u8 hi_b;
    s32 i;
    s32 x;
    u8 *o;
    u8 *slot;

    lo_f = D_004BF3A8;
    lo_b = D_004BF3AC;
    hi_f = D_004BF3B0;
    hi_b = D_004BF3B4;
    slot = (u8 *)&lo_f;
    for (i = 4; i >= 0; i--) {
        x = (i == 4) ? a : b;
        if (x < 9)
            o = func_00147870(0, (s8)slot[i]);
        else
            o = func_00147870(4, (s8)((u8 *)&hi_f)[i]);
        o[0x21] = (u8)x;
    }
    (void)lo_b;
    (void)hi_b;
}
