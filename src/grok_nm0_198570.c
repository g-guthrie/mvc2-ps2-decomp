typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void residual_00198570(u8 *p)
{
    *(s8 *)(p + 0x31) = -4;
    if ((s8)func_00175670(p) < 0) {
        p[0x13C] = 0;
        p[4]++;
    }
}
