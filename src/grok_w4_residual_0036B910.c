typedef unsigned char u8;
typedef signed char s8;

extern void func_001E3710(u8 *, int);
extern void func_001E2490(int, int);
extern int func_00175700(u8 *);

void residual_0036B910(u8 *p)
{
    if ((s8)p[0x151] == 1) {
        p[5]++;
        p[0x151] = 0;
        func_001E3710(p, 0x4C);
        func_001E2490(6, 0x4C);
    }
    func_00175700(p);
}
