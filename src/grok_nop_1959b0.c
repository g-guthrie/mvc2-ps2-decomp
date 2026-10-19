typedef unsigned char u8;

extern void func_00194CA0(u8 *);

void func_001959B0(u8 *p)
{
    p[5]++;
    if (p[33] < 4)
        func_00194CA0(p);
}
