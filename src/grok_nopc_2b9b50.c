typedef unsigned char u8;

extern void func_002BFA70(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002B9B50(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    func_002BFA70(p);
    func_001757E0(p, 0x12, 0);
}
