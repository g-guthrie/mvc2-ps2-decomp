typedef unsigned char u8;

extern void func_0018C4B0(u8 *, int);
extern void func_001FED30(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_001FF970(u8 *p)
{
    p[6]++;
    func_0018C4B0(p, 5);
    func_001FED30(p);
    func_00183D10(p);
    func_001757E0(p, 0x15, 0x0F);
    p[0x2D4] = 1;
}
