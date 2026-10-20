typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00472D60[];

void func_003A50C0(u8 *p)
{
    jtbl_00472D60[p[4]](p);
}
