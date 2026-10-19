typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);

void residual_001D6D40(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[0x13C] = 0;
    }
}
