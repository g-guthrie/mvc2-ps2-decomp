typedef unsigned char u8;

extern void func_0018C4B0(u8 *, int);
extern void func_0022F190(u8 *);
extern int func_0035AEA0(u8 *, int, int);
extern void func_00230300(u8 *, u8 *);

void residual_0022FE50(u8 *p, u8 *q)
{
    p[6]++;
    func_0018C4B0(p, 10);
    func_0022F190(p);
    if (func_0035AEA0(q, 0, 1) == 0)
        p[6]++;
    func_00230300(p, q);
}
