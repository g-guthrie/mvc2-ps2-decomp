typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_004C1324;
extern int func_001757E0(u8 *, int, int);
extern void func_002F50D0(u8 *, u8 *);
void func_002F5070(u8 *p, u8 *q)
{
    p[6]++;
    func_001757E0(p, 21, (&D_004C1324)[*(u16 *)q]);
    func_002F50D0(p, q);
}
