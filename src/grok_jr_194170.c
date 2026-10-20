typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_004BF540[] __attribute__((section(".sdata")));

void func_00194170(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004BF540[p[0x20]](p, q);
}
