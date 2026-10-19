typedef unsigned char u8;
typedef void (*OwnerStateCallback)(u8 *, void *);
extern OwnerStateCallback jtbl_0045BC20[];

void func_002F45E0(u8 *p)
{
    p[0x1B0] = 0;
    p[0x200] = 3;
    jtbl_0045BC20[p[6]](p, p + 0x2B8);
}
