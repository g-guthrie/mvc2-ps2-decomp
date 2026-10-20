typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044E470[];

void func_001D4680(u8 *p)
{
    jtbl_0044E470[p[4]](p);
}
