typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_0038F410(u8 *);
extern void func_0038EE40(u8 *);

void residual_0038F270(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_0038F410(p);
    }
    if ((s8)p[337] != 0) {
        p[337] = 0;
        func_0038EE40(p);
    }
}
