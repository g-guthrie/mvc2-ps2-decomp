typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_0016B0C0(u8 *, u8 *, int);
extern s16 D_004D1802;

void func_00166FC0(u8 *p, u8 *a1)
{
    u8 *q;
    int i;
    func_0016B0C0(p, a1, 0);
    q = *(u8 **)a1 + *(u16 *)(a1 + 4);
    *(u16 *)(a1 + 4) += 7;
    i = 0;
    while (i < 3) {
        if (D_004D1802 >= q[1])
            break;
        i++;
        q += 2;
    }
    p[1170] = q[0];
    p[1172] = 1;
    p[1105] = 0;
    p[1106] = 0;
    p[1107] = 0;
}
