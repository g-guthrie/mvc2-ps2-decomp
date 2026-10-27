typedef unsigned char u8;
typedef unsigned int u32;
typedef void (*DispatchFn)(u8 *, u8 *);

extern DispatchFn jtbl_004641C0[];

/* Provisional: scheduler context and the overlapping state table are unresolved. */
void func_0037D8D0(u8 *p, u8 *q)
{
    q[517] = 2;
    *(u32 *)(q + 728) = 3;
    jtbl_004641C0[p[5]](p, q);
}
