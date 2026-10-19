typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void func_00289570(u8 *);
extern int func_00175700();
extern void func_00184540(u8 *);

void residual_0028D580(u8 *p)
{
    u8 *q;
    func_00289570(p);
    func_00175700();
    if ((s8)p[0x151] != 0) {
        p[6]++;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x21;
        q[0x1E6] = (s8)p[0x1E6] ^ 1;
        if (*(u16 *)(p + 0x160) == 0)
            func_00184540(p);
    }
}
