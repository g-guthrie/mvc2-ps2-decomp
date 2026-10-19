typedef unsigned char u8;
typedef signed char s8;

extern int func_00175910(u8 *, int, int, int);
extern void func_003890E0(u8 *, u8 *);

void residual_00389080(u8 *p, u8 *q)
{
    p[7]++;
    func_00175910(p, 22, 36, (s8)p[337]);
    func_003890E0(p, q);
}
