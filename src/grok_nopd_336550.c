typedef unsigned char u8;

extern unsigned int func_00174170(void);
extern void func_003359E0(u8 *);

void residual_00336550(u8 *p)
{
    p[5]++;
    p[6]++;
    if (p[6] == 1)
        p[6] = (func_00174170() & 1) ? 1 : 2;
    if (p[6] >= 4) {
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
        p[7] = 0;
        func_003359E0(p);
    }
}
