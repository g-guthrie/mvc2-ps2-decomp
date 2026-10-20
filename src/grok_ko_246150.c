typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C0370[] __attribute__((section(".sdata")));

void residual_00246150(u8 *p)
{
    if (p[525] == 2)
        p[6] = 1;
    jtbl_004C0370[p[6]](p);
}
