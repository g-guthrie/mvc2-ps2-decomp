typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern unsigned int func_00174170(void);

void residual_00336140(u8 *p)
{
    *(s16 *)(p + 30) = (s16)(func_00174170() & 1);
    *(u32 *)(p + 68) = *(s16 *)(p + 320) ? 0 : 0x8000u;
    p[7]++;
    *(s16 *)(p + 28) = 15;
}
