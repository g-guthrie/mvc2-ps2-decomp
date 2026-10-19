typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void residual_001F3E90(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
