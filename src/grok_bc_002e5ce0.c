typedef unsigned char u8;

extern u8 D_0046B110[];
extern int func_00174170(void);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void residual_002E5CE0(u8 *p)
{
    u8 *q = p + 696;
    u8 m;
    p[6]++;
    m = p[32];
    if (m == 4)
        goto common;
    if (m == 3)
        goto common;
    if (m == 1)
        goto common;
    if (m == 2 || m == 0) {
        q[1] = D_0046B110[func_00174170() & 0xF];
        func_001757E0(p, 19, q[1]);
        func_001E3210(p, 10);
        return;
    }
    return;
common:
    func_001757E0(p, 19, 2);
}
