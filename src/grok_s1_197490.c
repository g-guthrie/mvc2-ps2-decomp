typedef unsigned char u8;
typedef signed char s8;

extern int func_00197860(u8 *, u8 *);
extern void func_00197470(u8 *, u8 *);
extern void func_00196E30(u8 *, u8 *);

void residual_00197490(u8 *p, u8 *q)
{
    u8 *r;
    u8 *s;
    r = q + 0x2B8;
    s = p + 0x88;
    if ((r[0] , func_00197860(p, q)) != 0) {
        r[0xC] = 0;
        s[0] = 0;
    } else if (p[0x21] != 0) {
        func_00197470(p, q);
    } else {
        func_00196E30(p, q);
    }
}
