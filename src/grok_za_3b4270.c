typedef unsigned char u8;

extern void func_003B42F0(u8 *);
extern void func_003B47C0(u8 *);
extern void func_003B4A10(u8 *);

void residual_003B4270(u8 *p)
{
    *(unsigned int *)(p + 0x14C) = 0x20202020;
    if (!p[0x22]) {
        if (!p[0x20])
            func_003B42F0(p);
        else
            func_003B47C0(p);
    } else {
        if (!p[0x20])
            func_003B4A10(p);
        else
            func_003B47C0(p);
    }
}
