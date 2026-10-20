typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00472F40[];

void func_003A8380(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    *(u32 *)(q + 772) = 2;
    jtbl_00472F40[p[4]](p);
}
