typedef unsigned char u8;
typedef void (*DispatchFn)(u8 *);

extern DispatchFn jtbl_004C0A60[2];

void func_00294770(u8 *p)
{
    p[0x1FE] = 1;
    jtbl_004C0A60[p[0x20B] & 0x3F](p);
}
