typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C1E38[] __attribute__((section(".sdata")));

void func_00396A40(u8 *p, u8 *q)
{
    *(s8 *)(p + 36) = *(s8 *)(q + 36);
    jtbl_004C1E38[p[5]](p);
}
