typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00352FA0(u8 *d, u8 *s) {
    f32 x, y;
    switch (s[0x168]) {
    case 0: x = 96.66666412353516f; y = 132.8571319580078f; break;
    case 1: x = 123.33332824707031f; y = 216.42855834960938f; break;
    case 2: x = 80.0f; y = 274.28570556640625f; break;
    default: x = 126.66666412353516f; y = 231.42855834960938f; break;
    }
    if (*(s16 *)(s + 0x140) == 0) x = -x;
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) + x;
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + y;
}
