typedef unsigned char u8;

extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_002753E0(u8 *p)
{
    p[0x20]++;
    p[0x13C] = 1;
    func_001757E0(p, 18, 0);
    func_001E3210(p, 10);
}
