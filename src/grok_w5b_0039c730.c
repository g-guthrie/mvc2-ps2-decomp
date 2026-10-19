typedef unsigned char u8;
typedef unsigned short u16;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C1E68[2];
extern void func_0039E450(u8 *);

void residual_0039C730(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0x88))
        func_0039E450(p);
    else
        jtbl_004C1E68[p[4]](p);
}
