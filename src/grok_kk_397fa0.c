typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C1E48[] __attribute__((section(".sdata")));

void func_00397FA0(u8 *p)
{
    p[36] = 0;
    jtbl_004C1E48[p[6]](p);
}
