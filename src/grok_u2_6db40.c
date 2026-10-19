typedef unsigned char u8;

extern int func_001757E0(u8 *, int, int);

void residual_0026DB40(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[7]++;
    func_001757E0(p, 22, 5);
}
