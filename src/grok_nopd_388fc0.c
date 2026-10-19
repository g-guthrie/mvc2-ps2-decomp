typedef unsigned char u8;
typedef signed char s8;

extern int func_00175910(u8 *, int, int, int);
extern void func_00389020(u8 *, u8 *);

void func_00388FC0(u8 *p, u8 *q)
{
    p[7]++;
    func_00175910(p, 22, 35, (s8)p[336]);
    func_00389020(p, q);
}
