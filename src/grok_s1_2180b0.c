typedef unsigned char u8;
typedef signed char s8;

extern s8 *D_004C2840;
extern void func_001757E0(u8 *, int, int);

void residual_002180B0(u8 *p)
{
    u8 m;
    p[6]++;
    m = p[0x20];
    if (m == 4 || m == 3 || m == 1)
        goto same;
    if (m == 2)
        goto other;
    if (m == 0)
        goto other;
    return;
same:
    func_001757E0(p, 0x13, 2);
    return;
other:
    p[0x21] = D_004C2840[0x1C] & 1;
    func_001757E0(p, 0x13, p[0x21]);
}
