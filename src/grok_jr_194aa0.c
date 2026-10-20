typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0044A1D0[18];

void func_00194AA0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);

    p[0x13C] = 0;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    jtbl_0044A1D0[p[4]](p, q);
}
