typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_00328E60(u8 *);

void func_0031ACA0(u8 *p, u8 *q)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[6]++;
        q[0x23E] = 3;
        q[0x23C] = 3;
        func_00328E60(q);
    }
}
