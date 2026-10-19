typedef unsigned char u8;

extern void func_001F0420(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001906C0(u8 *, int, int, int);

void residual_001F1ED0(u8 *p)
{
    p[6]++;
    func_001F0420(p);
    func_0018C4B0(p, 0x0A);
    if (p[0x269] == 8)
        func_001757E0(p, 0x0F, 0x3D);
    else
        func_001757E0(p, 0x0F, 0x16);
    func_001906C0(p, 0x0A, 0x1E, 0x3C);
}
