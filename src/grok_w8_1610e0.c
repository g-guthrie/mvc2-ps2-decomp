typedef unsigned char u8;

extern int func_00417A40(void);

void residual_001610E0(u8 *p)
{
    int n;

    p[4] = p[4] + 1;
    n = func_00417A40() % 4000;
    if (n % 2 == 0)
        n = -n;
    *(float *)(p + 0x34) = (float)n;
}
