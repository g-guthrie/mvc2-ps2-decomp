typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern void func_0022C5C0(u8 *);
extern int func_00175700(u8 *);

void residual_0022B910(u8 *p)
{
    u8 *owner;

    func_0022C5C0(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6] = 0;
        p[0x151] = 0;
        p[0x20B] = 0xC3;
        owner = *(u8 **)(p + 0x1DC);
        owner[0x20B] = p[0x20B];
    }
}
