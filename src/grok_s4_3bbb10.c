typedef unsigned char u8;
typedef signed char s8;

extern int func_003BD4C0(u8 *);
extern void func_003BB8F0(u8 *);
extern void (*D_004C20A0[])(u8 *);

void func_003BBB10(u8 *p)
{
    if (*(s8 *)(p + 0x1b3) != 0 || func_003BD4C0(p))
        func_003BB8F0(p);
    else
        D_004C20A0[p[5]](p);
}
