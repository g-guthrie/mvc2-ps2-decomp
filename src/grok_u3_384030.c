typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_003859F0(u8 *);

void func_00384030(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_003859F0(p);
}
