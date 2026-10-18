typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Defined static so the compiler tracks its register footprint (keeps y in $a2). */
static double func_001173A0(double a, double b) { return a * b; }

void func_003DB7F0(u8 *p) {
    s16 y = *(s16 *)(p + 2);
    s16 x = *(s16 *)p;
    f32 r;
    if ((y | x) == 0) {
        r = 0.0f;
    } else {
        r = func_001173A0((double)(-y), (double)x);
        if (r < 0.0f) r += 6.2831855f;
    }
    *(f32 *)(p + 8) = r;
}
