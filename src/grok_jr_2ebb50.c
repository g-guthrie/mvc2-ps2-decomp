typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C1188[2] __attribute__((section(".sdata")));

void func_002EBB50(u8 *p)
{
    if (p[0x20D] == 2)
        p[6] = 1;
    jtbl_004C1188[p[6]](p);
}
