typedef unsigned char u8;

extern int func_001757E0(u8 *, int, int);
extern void func_00360020(u8 *, u8 *);

void residual_0035FFC0(u8 *p, u8 *q)
{
    p[6]++;
    q[700] = 1;
    func_001757E0(p, 23, 2);
    func_00360020(p, q);
}
