typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003B1EF0(u8 *, u8, u8);

void func_003035D0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_003B1EF0(p, 0, 0);
        func_003B1EF0(p, 0, 1);
    }
}
