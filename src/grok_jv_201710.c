typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004BFD60[4] __attribute__((section(".sdata")));

void func_00201710(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    jtbl_004BFD60[p[7]](p);
}
