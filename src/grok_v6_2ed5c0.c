typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_003A6DC0(u8 *, u8, u8);

void residual_002ED5C0(u8 *p)
{
    u8 *q;

    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
    else {
        if ((*(s8 *)(p + 0x151) & 1) != 0) {
            *(s8 *)(p + 0x151) &= (s8)~1;
            func_003A6DC0(p, 1, 7);
        }
        if ((*(s8 *)(p + 0x151) & 2) != 0) {
            *(s8 *)(p + 0x151) &= (s8)~2;
            q = *(u8 **)(p + 0x1DC);
            q[0x20A] = 1;
            q[0x20D] = 2;
            q[0x1B5] = 0x21;
            p[0x1B5] = 0x21;
            q[0x1E6] = p[0x1E6];
            q[0x1E6] ^= 1;
        }
    }
}
