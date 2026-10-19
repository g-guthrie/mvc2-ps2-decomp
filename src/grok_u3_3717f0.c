typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);

void residual_003717F0(u8 *p)
{
    if ((s8)p[0x153] < 0) {
        p[4]++;
        p[0x13C] = 0;
    } else
        func_00175700(p);
}
