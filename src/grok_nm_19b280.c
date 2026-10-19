typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);
extern void func_0019B740(u8 *);

void residual_0019B280(u8 *p)
{
    if ((s8)func_00175670(p) < 0)
        func_0019B740(p);
}
