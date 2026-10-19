typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);

void func_00272E90(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
    }
}
