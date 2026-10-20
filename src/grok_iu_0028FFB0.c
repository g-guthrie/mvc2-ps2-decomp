typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C0A18[2];

void func_0028FFB0(u8 *p)
{
    p[0x378] = 0;
    jtbl_004C0A18[p[6]](p);
}
