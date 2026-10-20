typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_0045D630[9];
extern void func_00179160(u8 *, u8 *);

void func_00316A20(u8 *p)
{
    jtbl_0045D630[p[6]](p, *(u8 **)(p + 0x1DC) + 0x2B8);
}

void func_00316A50(u8 *p)
{
    func_00179160(*(u8 **)(p + 0x1DC), p);
}
