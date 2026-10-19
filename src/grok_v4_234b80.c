typedef unsigned char u8;
typedef signed char s8;

extern void func_00175C00(u8 *, int);
extern s8 *D_004C2840;

void residual_00234B80(u8 *p)
{
    s8 *g;
    func_00175C00(p, 0);
    g = D_004C2840;
    if (g[0x8F]) {
        p[32] = 2;
        g = D_004C2840;
        if (g[0xA9] & (1 << ((s8)p[1336] & 1)))
            p[32] = 1;
    } else
        p[32] = *(s8 *)(p + 1337) ? 1 : 2;
}
