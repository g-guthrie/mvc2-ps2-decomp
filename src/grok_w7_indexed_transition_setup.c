typedef unsigned char u8;
typedef unsigned short u16;
/* Native code addresses this byte table through gp; its full bound is unresolved. */
extern u8 D_004C1324[] __attribute__((section(".sdata")));
extern int func_001757E0(u8 *, int, int);
extern void func_002F50D0(u8 *, void *);
void func_002F5070(u8 *p, void *q)
{
    p[6]++;
    func_001757E0(p, 21, D_004C1324[*(u16 *)q]);
    func_002F50D0(p, q);
}
