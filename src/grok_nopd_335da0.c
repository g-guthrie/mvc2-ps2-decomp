typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

extern unsigned int func_00174170(void);

void func_00335DA0(u8 *p)
{
    *(s16 *)(p + 0x1C) = (s16)(func_00174170() % 150);
    *(s16 *)(p + 0x1C) += 10;
    *(u32 *)(p + 0x5C) = 0x40400000;
    p[7]++;
}
