#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;

void func_0019E750(u8 *p)
{
    s16 timer = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = timer;
    if (timer == 0) {
        p[5]++;
        p[0x13C] = 1;
    }
}
