typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_00174170(void);

void func_0027E5D0(u8 *p)
{
    s16 s;
    s32 r;
    f32 f1;

    switch (p[0x1B7]) {
    case 0:
        s = (s16)(0xA0 - (*(s16 *)(p + 0x1C) << 4));
        if (*(s16 *)(p + 0x1C) & 1)
            s = -s;
        break;
    case 1:
        s = (s16)((*(s16 *)(p + 0x1C) << 4) - 0xA0);
        break;
    case 2:
        s = (s16)(0xA0 - (*(s16 *)(p + 0x1C) << 4));
        break;
    default:
        s = 0;
        break;
    }
    s = (s16)(s + (s16)(0x20 - (func_00174170() & 0x3F)));
    f1 = 1.6666666269302368f * (f32)s * *(f32 *)(p + 0x50);
    if (*(s16 *)(p + 0x140) != 0)
        f1 = -f1;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x68) - f1;
    r = func_00174170();
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x6C) + 2.142857074737549f * (f32)(((u32)r % 3 - 1) << 3);
}
