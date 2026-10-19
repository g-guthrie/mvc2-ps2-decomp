typedef unsigned char u8;

extern int func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
extern void (*jtbl_0044F710[])(u8 *);

void residual_001F03A0(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_0044F710[p[32]](p);
}
