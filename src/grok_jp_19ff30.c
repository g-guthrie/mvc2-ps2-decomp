typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *, u8 *);

extern DispatchFn jtbl_0044ADF0[2];

void func_0019FF30(u8 *p)
{
    jtbl_0044ADF0[p[4]](p, p + 0xD0, *(u8 **)(p + 0x18));
}
