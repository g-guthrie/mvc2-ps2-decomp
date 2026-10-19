typedef unsigned char u8;
typedef signed char s8;

extern void func_00175C00(u8 *, int);
extern u8 *D_004CB5D0;

void residual_00234B80(u8 *p)
{
    func_00175C00(p, 0);
    if (D_004CB5D0[0x8F]) {
        p[0x20] = 2;
        if (D_004CB5D0[0xA9] & (1 << (p[0x538] & 1)))
            p[0x20] = 1;
    } else {
        p[0x20] = 0;
        if ((s8)p[0x539] != 0)
            p[0x20] = 1;
    }
}
