typedef unsigned char u8;

extern u8 *D_004C2794;
extern void func_003AD480(u8 *, int, int);
extern void func_001E3210(u8 *, int);

void func_002F3A30(u8 *p)
{
    if (D_004C2794[0] < 2)
        return;

    p[6]++;
    func_003AD480(p, 2, 0);
    func_003AD480(p, 2, 1);
    func_001E3210(p, 31);
}
