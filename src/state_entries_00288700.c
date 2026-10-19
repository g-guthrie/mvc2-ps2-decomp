typedef unsigned char u8;

extern void func_00175C00(void *, int);
extern void func_00176160(u8 *, int, int, int);
extern int func_001757E0(void *, int, int);
extern void func_00288770(u8 *);

void func_00288700(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_00176160(p, 7, p[0x25] * 0x57 + 0x39, 1);
    func_001757E0(p, 0x13, 8);
    func_00288770(p);
}
