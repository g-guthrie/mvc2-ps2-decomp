typedef unsigned char u8;
typedef signed short s16;

extern int func_001757E0(u8 *, int, int);
extern void func_0019BDD0(u8 *);

void func_00224510(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0x140) = 0;
    func_001757E0(p, 18, 0);
    func_0019BDD0(p);
}
