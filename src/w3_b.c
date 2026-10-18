typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 a[6]; } S24;
typedef unsigned long long u64;
typedef long long s64;
typedef struct { s32 cls; s32 sign; s32 exp; s32 pad; u64 frac; } FP;

s32 func_00419310(s32 a, s32 b)
{
    extern s32 D_00633694, D_0063369C, D_006336A0, D_00633690;
    extern s32 D_00633670[];
    extern s32 func_001108F0();
    s32 *e;
    s32 i;
    if (D_00633694 != 0)
        return -1;
    if (a >= 2)
        return -1;
    if (b > 0)
        return -1;
    e = D_00633670 + (a + b) * 3;
    i = 0;
    do {
        if (func_001108F0(a, b, e, e + 1, e + 2) == 0) {
            D_0063369C = a;
            D_00633694 = 1;
            D_006336A0 = b;
            if (D_00633690 == 0)
                D_00633690 = 5;
            return 0;
        }
        i++;
    } while (i < 5);
    return -1;
}
