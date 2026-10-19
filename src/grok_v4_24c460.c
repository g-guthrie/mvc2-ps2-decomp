typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern int func_0024D670(u8 *);
extern void func_00126400(u8 *);

void func_0024C460(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (func_0024D670(p) || p[617] == 4 || p[617] == 5)
        p[6]++;
    else if ((s8)p[337] != 1) {
        p[6] += 2;
        func_00126400(p);
    }
}
