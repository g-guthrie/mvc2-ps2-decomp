typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C09A0[2];

void func_0028D3F0(u8 *p)
{
    p[0x1FE] = 1;
    jtbl_004C09A0[p[0x20B] & 0x3F](p);
}
