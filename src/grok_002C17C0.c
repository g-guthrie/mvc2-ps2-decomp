typedef unsigned char u8;
typedef signed short s16;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn const jtbl_004C0DE8[2] __attribute__((section(".sdata")));

void func_002C17C0(u8 *p)
{
    jtbl_004C0DE8[*(s16 *)(p + 0x1C)](p);
}
