typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_001919B0(s32 n) {
    s32 r = 0;
    s32 sh = 0;
    do {
        r += (n % 10) << sh;
        n /= 10;
        sh += 4;
    } while (n != 0);
    return r;
}

