typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0034ACF0(u8 *p, u8 *q)
{
    u8 *r = q + 0x2B8;
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 1;
        r[0xD] = 1;
        func_001757E0(p, 22, 22);
    }
}
