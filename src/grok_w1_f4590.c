typedef unsigned char u8;

extern void func_001F0420(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001906C0(u8 *, int, int, int);

void residual_001F4590(u8 *p)
{
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    p[6]++;
    func_001F0420(p);
    func_001757E0(p, 0x0F, 0x35);
    func_001906C0(p, 0x0A, 0x3C, 0x3C);
}
