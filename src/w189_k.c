typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;

/* EE GCC 2.96 soft float: ./tryee.sh src/w189_k.c sn 0 O2 -msoft-float */
typedef struct FPN {
    s32 cls;
    u32 sign;
    s32 normal_exp;
    union { u64 ll; u32 bits[2]; } fraction;
} FPN;
extern double func_00119118(FPN *);
double func_00119B08(s32 a) {
    FPN in;
    in.cls = 3;
    in.sign = (u32)a >> 31;
    if (a == 0) {
        in.cls = 2;
    } else {
        in.normal_exp = 60;
        if (in.sign) {
            if (a == -2147483647 - 1) return -2147483648.0;
            in.fraction.ll = -a;
        } else {
            in.fraction.ll = a;
        }
        while (in.fraction.ll < ((u64)1 << 60)) {
            in.fraction.ll <<= 1;
            in.normal_exp -= 1;
        }
    }
    return func_00119118(&in);
}
