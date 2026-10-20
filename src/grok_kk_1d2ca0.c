typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_0044E080[];

void func_001D2CA0(u8 *p)
{
    jtbl_0044E080[p[4]](p);
}
