typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);

void residual_0039CE40(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        {
            u8 *q = *(u8 **)(p + 24);
            *(s8 *)(q + 0x1B2) = *(s8 *)(q + 0x1B2) - 1;
        }
    }
}
