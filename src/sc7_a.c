typedef unsigned char u8;
typedef signed char s8;

extern void (*jtbl_00473CB0[])(u8 *, u8 *);

void func_003B0B90(u8 *p, u8 *q)
{
    p[0x24] = *(s8 *)(q + 0x24);
    jtbl_00473CB0[p[5]](p, q);
}
