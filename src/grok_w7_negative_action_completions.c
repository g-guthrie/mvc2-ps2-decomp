typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern void func_001D45D0(u8 *, u8);
extern void func_00175C00(u8 *, int);

void func_002E5BF0(u8 *p)
{
    if ((s8)func_00175700(p) >= 0) return;
    p[6]++;
    func_001757E0(p, 1, 3);
    func_00183D50(p);
    func_001D45D0(p, 1);
}

void func_002E5C60(u8 *p)
{
    if ((s8)func_00175700(p) >= 0) return;
    p[5]++;
    func_001757E0(p, 0, 0);
    func_00175C00(p, 0);
}
