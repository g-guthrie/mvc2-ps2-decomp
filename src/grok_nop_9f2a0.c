typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void residual_0019F2A0(u8 *p)
{
    u8 *q = *(u8 **)(p + 20);

    *(s8 *)(p + 36) = *(s8 *)(q + 36);
    *(s8 *)(p + 49) = *(s8 *)(q + 49) - 4;
    p[316] = 1;
    if ((s8)func_00175670(p) < 0) {
        p[316] = 0;
        p[4]++;
    }
}
