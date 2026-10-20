typedef unsigned char u8;
typedef unsigned short u16;

extern void (*jtbl_00445A20[])(u8 *, u8 *);

void func_00163F40(u8 *p, u8 *a1)
{
    u8 *q;

    q = *(u8 **)a1;
    q += *(u16 *)(a1 + 4);
    jtbl_00445A20[q[0]](p, a1);
}
