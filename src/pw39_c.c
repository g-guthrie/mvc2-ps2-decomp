typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long u64;

/* EE GCC 2.96 soft float: ./tryee.sh src/pw39_c.c sn 0 O2 -msoft-float */
double func_00118CD0(long long x) {
    double d = (int)(x >> 32);
    double l;
    int lo;
    d *= 65536.0;
    d *= 65536.0;
    lo = (int)(x & 0xFFFFFFFF);
    l = lo;
    if (lo < 0) l += 4294967296.0;
    return d + l;
}
