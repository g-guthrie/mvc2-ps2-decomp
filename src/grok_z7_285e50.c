typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001E3A40(u8 *);

void residual_00285E50(u8 *p)
{
    if ((s8)func_00175700(p) >= 0) {
        if ((s8)p[0x151] != 0) {
            u8 *q;
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 2;
            q[0x1B5] = 32;
            func_001E3A40(p);
        }
    } else {
        func_001843A0(p);
    }
}
