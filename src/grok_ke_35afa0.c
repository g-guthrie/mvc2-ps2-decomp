typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00463160[8];

void func_0035AFA0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x14);

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_00463160[p[4]](p, q);
}
