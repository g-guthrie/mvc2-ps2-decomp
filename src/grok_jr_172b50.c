typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_00446B80[5];

void func_00172B50(u8 *p)
{
    jtbl_00446B80[(s8)p[0x4D0]](p);
}
