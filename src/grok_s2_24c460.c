typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_0024D670(u8 *);
extern void func_00126400(void);

void func_0024C460(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (func_0024D670(p) || p[0x269] == 4 || p[0x269] == 5)
        p[6]++;
    else if ((s8)p[0x151] != 1) {
        p[6] = p[6] + 2;
        func_00126400();
    } else
        ;
}
