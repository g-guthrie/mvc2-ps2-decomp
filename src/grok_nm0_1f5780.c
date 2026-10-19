typedef unsigned char u8;

extern void func_001F0420(u8 *);
extern int func_001757E0(u8 *, int, int);

void residual_001F5780(u8 *p)
{
    p[6]++;
    func_001F0420(p);
    func_001757E0(p, 0x15, 0xE);
}
