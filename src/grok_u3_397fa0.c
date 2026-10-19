typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C1E48[2];

void func_00397FA0(u8 *p)
{
    p[0x24] = 0;
    jtbl_004C1E48[p[6]](p);
}
