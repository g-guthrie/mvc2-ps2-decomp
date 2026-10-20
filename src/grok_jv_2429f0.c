typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_00452A98[3];

void func_002429F0(u8 *p)
{
    p[0x209] = 1;
    jtbl_00452A98[p[6]](p, p + 0x2B8);
}
