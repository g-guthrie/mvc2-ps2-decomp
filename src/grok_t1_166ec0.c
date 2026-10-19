typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0016B0C0(u8 *, u8 *, int);
extern int func_00174170(void);

void func_00166EC0(u8 *p, u8 *a1)
{
    u8 *base;
    u8 *q;
    int r;

    func_0016B0C0(p, a1, 0);
    base = *(u8 **)a1;
    q = base + *(u16 *)(a1 + 4);
    *(u16 *)(a1 + 4) = *(u16 *)(a1 + 4) + 4;
    r = func_00174170();
    p[1170] = q[r & 3];
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
}
