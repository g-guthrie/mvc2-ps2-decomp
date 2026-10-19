typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_00126400(int);
extern void func_001E3A40(u8 *);

void residual_0028D440(u8 *p)
{
    u8 *q;

    func_00175700(p);
    if ((s8)p[0x151] == 1) {
        p[6]++;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x1E6] = (u8)((s8)p[0x1E6] ^ 1);
        q[0x1B5] = 0x20;
        q[0x20A] = 1;
        func_00126400(1);
        func_001E3A40(p);
    }
}
