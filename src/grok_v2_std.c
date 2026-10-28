typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00126400(void);

void func_002B7D10(u8 *p)
{
    u8 *q;
    u8 v;

    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x220);
        *(u8 **)(q + 0x1c8) = p;
        (*(u8 **)(p + 0x220))[0x20a] = 1;
        v = p[0x1e6];
        (*(u8 **)(p + 0x220))[0x1e6] = v;
        (*(u8 **)(p + 0x220))[0x1b5] = 0x20;
        func_00126400();
    }
}
