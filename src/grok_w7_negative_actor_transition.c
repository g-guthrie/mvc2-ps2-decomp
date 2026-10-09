typedef unsigned char u8;
typedef signed char s8;
extern u8 *D_004C28DC;
extern void func_0030A4B0(u8 *);
extern void func_0030A450(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_0030A330(u8 *p)
{
    func_0030A4B0(p);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        if (D_004C28DC[8] != 0)
            func_001757E0(p, 2, 4);
        else
            func_001757E0(p, 2, 5);
    }
    func_0030A450(p);
}
