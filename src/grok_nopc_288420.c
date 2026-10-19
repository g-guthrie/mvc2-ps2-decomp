typedef unsigned char u8;

extern void func_00175C00(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_0028D910(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_002884A0(u8 *);

void residual_00288420(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_00176160(p, 7, 0x57 * p[0x25] + 0x39, 1);
    func_0028D910(p, 1);
    func_001757E0(p, 0x13, 0);
    func_002884A0(p);
}
