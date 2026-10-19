typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*StateDispatchFn)(u8 *);
typedef void (*ContextDispatchFn)(u8 *, void *);

extern const u32 jtbl_0045D930[9];
extern const u32 jtbl_0045D948[3];

void func_0031A6E0(u8 *p)
{
    p[0x1FE] = 1;
    ((ContextDispatchFn *)jtbl_0045D930)[p[0x20B]](
        p, *(void **)(p + 0x1DC));
}

void func_0031A710(u8 *p)
{
    ((StateDispatchFn *)jtbl_0045D948)[p[6]](p);
}
