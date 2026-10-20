typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, unsigned int);

extern DispatchFn jtbl_004C1D18[] __attribute__((section(".sdata")));

void func_0037E080(u8 *p, unsigned int a1)
{
    jtbl_004C1D18[(u8)a1](p, a1);
}
