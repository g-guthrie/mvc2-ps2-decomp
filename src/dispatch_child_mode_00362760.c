typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *, u8 *);
extern DispatchFn D_004C1C18[] __attribute__((section(".sdata")));
void func_00362760(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (q[4] >= 2) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        D_004C1C18[p[5]](p, q);
    }
}
