typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef unsigned long long u64;
#define GET_HIGH_WORD(i,d) do { union { double d; u32 w[2]; } gh_u; gh_u.d = (d); (i) = gh_u.w[1]; } while (0)
#define SET_HIGH_WORD(d,v) do { union { double d; u32 w[2]; } sh_u; sh_u.d = (d); sh_u.w[1] = (v); (d) = sh_u.d; } while (0)
double func_001166D8(double x) {
    u32 high;
    GET_HIGH_WORD(high, x);
    SET_HIGH_WORD(x, high & 0x7FFFFFFF);
    return x;
}
