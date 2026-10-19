typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);

void residual_001F6690(u8 *p)
{
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x20;
        p[0x1B5] = 0x20;
    }
}
