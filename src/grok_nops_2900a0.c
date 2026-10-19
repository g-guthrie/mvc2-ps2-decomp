typedef unsigned char u8;

extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_002900F0(u8 *);

void func_002900A0(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_001757E0(p, 0x13, 1);
    func_002900F0(p);
}
