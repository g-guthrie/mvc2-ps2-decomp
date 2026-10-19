typedef unsigned char u8;

extern void func_003359E0(u8 *);

void residual_00336620(u8 *p)
{
    p[5]++;
    p[6]++;
    if (p[6] >= 3) {
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        func_003359E0(p);
    }
}
