typedef unsigned char u8;

extern void func_001E3710(u8 *, int);
extern void func_00389D00(u8 *, u8 *);

void residual_00389CA0(u8 *p, u8 *q)
{
    p[5]++;
    p[0x14C] = 8;
    p[0x14D] = 8;
    p[0x14E] = 8;
    p[0x14F] = 8;
    func_001E3710(p, 70);
    func_00389D00(p, q);
}
