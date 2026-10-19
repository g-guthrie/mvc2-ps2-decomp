typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(void *);
extern void func_00352670(u8 *, int, int, int);

void func_00215820(u8 *p)
{
    u8 *q;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        q = p + 0x2B8;
        p[6]++;
        q[1] = 0x40;
        *(s16 *)(q + 2) = 0;
        q[4] = 0xFF;
        q[0] = 0xC;
        func_00352670(p, 1, 2, 0);
        *(s16 *)(p + 0x1C) = 0x20;
        q[6] = 0;
    }
}
