typedef unsigned char u8;

extern int func_001757E0(u8 *, int, int);
extern void func_00360020(u8 *, void *);

void func_0035FFC0(u8 *p, void *context)
{
    p[6]++;
    ((u8 *)context)[700] = 1;
    func_001757E0(p, 23, 2);
    func_00360020(p, context);
}
