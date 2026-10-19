typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;

extern unsigned int func_00174170(void);

void func_00335AA0(u8 *p)
{
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = (s16)(func_00174170() % 90);
    *(s16 *)(p + 0x1C) += 10;
    p[7]++;
}
