typedef unsigned char u8;

extern void func_00290940(u8 *);
extern void func_00290020(u8 *);

void func_0028FFD0(u8 *p)
{
    p[6]++;
    if (p[0x20] == 0)
        func_00290940(p);
    func_00290020(p);
}
