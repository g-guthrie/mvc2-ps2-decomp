typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045B290[3];

void func_002E6260(u8 *p)
{
    p[0x209] = 2;
    jtbl_0045B290[p[7]](p, p + 0x2B8);
}
