typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00472E60[];

void func_003A6E70(u8 *p)
{
    jtbl_00472E60[p[4]](p);
}
