typedef unsigned char u8;

extern int func_00174170(u8 *);
extern void func_0028F830(u8 *);
extern u8 D_004C0A10[8];

void func_0028F7E0(u8 *p)
{
    int i;

    p[6]++;
    i = func_00174170(p) & 3;
    p[0x20] = D_004C0A10[i * 2];
    func_0028F830(p);
}
