typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044EFB0[];

void func_001E0D70(u8 *p)
{
    jtbl_0044EFB0[p[4]](p);
}
