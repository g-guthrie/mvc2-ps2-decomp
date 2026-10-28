typedef unsigned char u8;
typedef void (*OwnerDispatchFn)(u8 *, u8 *);

/* src/data/jtbl_0045D930.c: six states selected by p[0x20B]. */
extern const OwnerDispatchFn jtbl_0045D930[6];
/* src/data/jtbl_0045D948.c: three sub-states selected by p[6]. */
extern const OwnerDispatchFn jtbl_0045D948[3];

void func_0031A6E0(u8 *p)
{
    p[0x1FE] = 1;
    jtbl_0045D930[p[0x20B]](p, *(u8 **)(p + 0x1DC));
}

void func_0031A710(u8 *p, u8 *owner)
{
    jtbl_0045D948[p[6]](p, owner);
}
