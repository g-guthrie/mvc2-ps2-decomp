typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00462B90[3];

void residual_00354AD0(u8 *p)
{
    jtbl_00462B90[p[4]](p, *(u8 **)(p + 0x18));
}
