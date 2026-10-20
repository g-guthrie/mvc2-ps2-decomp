typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2948 __attribute__((section(".sdata")));
extern u8 *D_004C2944 __attribute__((section(".sdata")));
extern DispatchFn jtbl_00462290[];

void func_0034DDD0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    D_004C2948 = p + 208;
    D_004C2944 = q + 696;
    jtbl_00462290[p[4]](p);
}
