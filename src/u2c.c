typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern double D_004AC8C8[];

double func_0011EA30(s32 n) {
    double r = 1.0;
    if (n < 24) {
        return D_004AC8C8[n];
    }
    while (n > 0) {
        r *= 10.0;
        n--;
    }
    return r;
}
