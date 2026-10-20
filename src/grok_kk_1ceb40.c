typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2718 __attribute__((section(".sdata")));
extern DispatchFn jtbl_0044DE10[];

void func_001CEB40(u8 *p)
{
    D_004C2718 = p + 208;
    jtbl_0044DE10[p[4]](p);
}
