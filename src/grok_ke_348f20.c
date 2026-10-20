typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00461F00[10];

void func_00348F20(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_00461F00[p[4]](p, q);
}
