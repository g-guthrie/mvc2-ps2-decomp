typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_003B0540(u8 *p)
{
    if (p[7] == 0) {
        p[7]++;
        func_001757E0(p, 0x17, 2);
    } else {
        if ((s8)func_00175700(p) < 0) {
            p[0x13C] = 0;
            p[4] = 3;
        }
    }
}

void residual_003B0D90(u8 *p)
{
    if (p[7] == 0) {
        p[7]++;
        func_001757E0(p, 0x17, 2);
    } else {
        if ((s8)func_00175700(p) < 0) {
            p[0x13C] = 0;
            p[4] = 3;
        }
    }
}
