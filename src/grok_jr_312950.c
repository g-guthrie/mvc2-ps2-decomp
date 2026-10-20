typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045D450[];

void residual_00312950(u8 *p)
{
    jtbl_0045D450[p[0x1FD]](p, p + 0x2B8);
}
