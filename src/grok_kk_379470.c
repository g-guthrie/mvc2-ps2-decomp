typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern u8 *D_004C2990 __attribute__((section(".sdata")));
extern DispatchFn jtbl_00464130[];

void func_00379470(u8 *p)
{
    D_004C2990 = p + 208;
    jtbl_00464130[p[4]](p);
}
