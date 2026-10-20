typedef unsigned char u8;
typedef signed int s32;

extern void (*jtbl_004457A0[])(u8 *, u8 *);

void func_00162640(u8 *p)
{
    u8 *self = p;
    jtbl_004457A0[p[4]](*(u8 **)(p + 0x18), self);
}
