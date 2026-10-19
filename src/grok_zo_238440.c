typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_0035C440(u8 *);

void func_00238440(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[7]++;
        if (!func_0035C440(p))
            p[6] = 2;
    }
}
