typedef unsigned char u8;

extern unsigned func_00174170(void);
extern void func_003B90B0(u8 *);

void residual_003B9070(u8 *p)
{
    unsigned r;
    p[6]++;
    r = func_00174170() & 0x1f;
    p[34] = (u8)r;
    func_003B90B0(p);
}
