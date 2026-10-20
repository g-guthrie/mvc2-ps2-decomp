typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045D930[9];

void func_0031A6E0(u8 *p)
{
    p[0x1FE] = 1;
    jtbl_0045D930[p[0x20B]](p, *(u8 **)(p + 0x1DC));
}
