typedef unsigned char u8;

extern void func_00179150(u8 *, u8 *);
extern void func_00178F20(u8 *, u8 *);

void residual_002A5AD0(u8 *p)
{
    u8 *q = p;
    u8 *r = *(u8 **)(p + 0x1DC);
    if (r[6] > 0)
        func_00179150(r, q);
    else
        func_00178F20(r, q);
}
