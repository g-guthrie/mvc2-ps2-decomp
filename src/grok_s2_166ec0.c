typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0016B0C0(u8 *, u8 *, int);
extern int func_00174170(void);

void func_00166EC0(u8 *p, u8 *a1)
{
    u8 *q;
    func_0016B0C0(p, a1, 0);
    q = *(u8 **)a1 + *(u16 *)(a1 + 4);
    *(u16 *)(a1 + 4) += 4;
    p[1170] = q[func_00174170() & 3];
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
}
