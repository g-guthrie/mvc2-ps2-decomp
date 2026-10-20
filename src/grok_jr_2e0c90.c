typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045AE10[3];
extern void func_00178F20(u8 *, u8 *);

void func_002E0C90(u8 *p)
{
    jtbl_0045AE10[p[0x20B] & 0x3F](p, *(u8 **)(p + 0x1DC));
}

void func_002E0CC0(u8 *p, u8 *q)
{
    p[0x208] = 2;
    func_00178F20(q, p);
}
