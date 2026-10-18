typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef long long s64;
s32 func_00407E10(u8 *p, s32 a1, s64 a2, s64 a3, s32 a4) {
    extern void func_00411288();
    extern void func_004112B0();
    s32 r = 0;
    func_00411288();
    if (*(s8 *)(p + 2) == 0 || *(s8 *)(p + 2) == 3 || *(s8 *)(p + 2) == 9) {
        p[2] = 1;
        *(s32 *)(p + 0x30) = a1;
        *(s32 *)(p + 0x18) = a4;
        *(s64 *)(p + 0x20) = a3;
        *(s64 *)(p + 0x28) = a2;
        r = 1;
        *(s32 *)(p + 4) = 0;
        p[1] = 2;
    }
    func_004112B0();
    return r;
}
