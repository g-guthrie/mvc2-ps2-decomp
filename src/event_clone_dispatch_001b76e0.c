typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044BE90[];

void func_001B76E0(u8 *p)
{
    jtbl_0044BE90[p[4]](p);
}
