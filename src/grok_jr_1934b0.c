typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_004BF528[] __attribute__((section(".sdata")));

void func_001934B0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_004BF528[p[0x20]](p, q);
}
