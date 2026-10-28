typedef unsigned char u8;

extern int func_00174170(void);
extern void func_003B90B0(u8 *);

void func_003B9070(u8 *p)
{
    unsigned r;

    p[6]++;
    r = (unsigned)func_00174170() & 0x1F;
    p[0x22] = (u8)r;
    func_003B90B0(p);
}
