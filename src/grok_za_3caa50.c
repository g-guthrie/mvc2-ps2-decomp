typedef unsigned char u8;

extern void func_003CCFB0(u8 *);
extern void func_003CAAA0(u8 *, u8 *);

void residual_003CAA50(u8 *p, u8 *q)
{
    p[4]++;
    func_003CCFB0(p);
    p[0] = 1;
    func_003CAAA0(p, q);
}
