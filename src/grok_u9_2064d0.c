typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_001757E0(u8 *, int, int);

void func_002064D0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x33C] = 5;
    if (--*(s16 *)(p + 0x1E) <= 0) {
        *(u8 *)(p + 6) = *(u8 *)(p + 6) + 1;
        if (*(u8 *)(p + 0x20D) != 2)
            func_001757E0(p, 22, 2);
        else
            func_001757E0(p, 22, 5);
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        *(u8 *)(p + 6) = *(u8 *)(p + 6) - 1;
        *(s16 *)(p + 0x1E) = 43;
    }
}
