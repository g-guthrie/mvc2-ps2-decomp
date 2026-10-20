typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00472800[];

void func_0039E550(u8 *p)
{
    *(u32 *)(p + 80) = 0x3F866666;
    *(u32 *)(p + 84) = 0x3F866666;
    jtbl_00472800[p[32]](p);
}
