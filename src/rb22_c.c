typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0027E5D0(u8 *p) {
    extern u32 func_00174170();
    s16 s0;
    s16 h;
    s16 x;
    f32 v;
    s32 k;
    switch (p[0x1B7]) {
    case 0:
        h = *(s16 *)(p + 0x1C);
        s0 = 0xA0 - (h << 4);
        if (h & 1) s0 = -s0;
        break;
    case 1:
        s0 = (*(s16 *)(p + 0x1C) * 16) - 0xA0;
        break;
    case 2:
        s0 = 0xA0 - (*(s16 *)(p + 0x1C) * 16);
        break;
    default:
        break;
    }
    x = 0x20 - (func_00174170() & 0x3F);
    s0 = s0 + x;
    v = 1.6666666269302368f * (f32)s0;
    v = v * *(f32 *)(p + 0x50);
    if (*(s16 *)(p + 0x140) != 0) v = -v;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x68) - v;
    k = ((s32)(func_00174170() % 3) - 1) << 3;
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x6C) + 2.1428570747375488f * (f32)k;
}
