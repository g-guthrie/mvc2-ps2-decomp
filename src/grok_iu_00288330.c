typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C0960[2];

void func_00288330(u8 *p)
{
    p[0x378] = 0;
    jtbl_004C0960[p[6]](p);
}
