typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);
extern void func_003BD830(u8 *);
extern DispatchFn jtbl_004C20C0[] __attribute__((section(".sdata")));
void func_003BCAE0(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[0x25C])
        func_003BD830(p);
    else
        jtbl_004C20C0[p[4]](p);
}
