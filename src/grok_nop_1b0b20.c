typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void func_001B0B20(u8 *p)
{
    func_00175670(p);
    if ((s8)p[339] < 0)
        p[4]++;
}
