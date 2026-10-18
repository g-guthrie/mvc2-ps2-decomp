typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_00404438(s32 *p, s32 a1, s32 a2, s32 a3, s32 t0) {
    if (p[3] == 0) {
        p[6] = a1; p[7] = a2; p[5] = 2; p[8] = a3; p[9] = t0;
        return 1;
    }
    return 0;
}
