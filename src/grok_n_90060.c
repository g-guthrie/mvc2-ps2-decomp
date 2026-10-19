typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);

void residual_00390060(u8 *p)
{
    u8 *q;
    func_00175700(p);
    if ((s8)p[0x151] < 0) {
        q = *(u8 **)(p + 0x18);
        if (q[0x1E4] != 0x14)
            p[0x22] = 1;
    }
    if ((s8)p[0x151] == 0)
        p[6]++;
}
