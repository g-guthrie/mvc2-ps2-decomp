typedef unsigned char u8;

extern int func_00417A40(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002B49C0(u8 *p)
{
    unsigned char v = (unsigned char)func_00417A40(p);
    func_001757E0(p, 19, v & 1);
}
