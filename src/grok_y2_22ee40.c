typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_003D92F0(u8 *);
extern void func_001843A0(u8 *);

void residual_0022EE70(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        func_00175700(p);
}
