typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f; u8 b; } FB;

extern FB D_004BF3A8;
extern FB D_004BF3B0;
extern u8 *func_00147870(s32, s32);

void func_001489E0(s32 a, s32 b)
{
    FB lo;
    FB hi;
    s32 i;
    s32 x;
    u8 *o;

    lo = D_004BF3A8;
    hi = D_004BF3B0;
    for (i = 4; i >= 0; i--) {
        x = (i == 4) ? a : b;
        if (x < 9)
            o = func_00147870(0, ((s8 *)&lo)[i]);
        else
            o = func_00147870(4, ((s8 *)&hi)[i]);
        o[0x21] = (u8)x;
    }
}
