typedef unsigned char u8;
typedef signed char s8;
extern int func_001757E0(u8 *, int, int);
extern void func_002F54C0(u8 *, void *);
void func_002F5440(u8 *p, void *q)
{
    p[0x40d] = 0;
    p[0x40c] = 0;
    p[0x33b] = 0;
    p[0x33c] = 0;
    p[0x1b0] = 0;
    p[0x200] = 3;
    ((s8 *)p)[0x1b1] = -128;
    p[0x201] = 0;
    func_001757E0(p, 22, 5);
    p[6]++;
    func_002F54C0(p, q);
}
