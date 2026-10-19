typedef unsigned char u8;

extern int D_0044FDE0[];
extern void func_001978B0(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);

void residual_001FE580(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    func_001978B0(p, 0);
    func_00176160(p, 2, D_0044FDE0[p[0x25]], 1);
    func_001757E0(p, 0x12, 0);
}
