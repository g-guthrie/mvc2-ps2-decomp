typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *D_004C2840;
extern void func_001757E0(u8 *, int, int);

void residual_00212160(u8 *p)
{
    u8 *g = D_004C2840;
    if ((*(u32 *)(g + 0x1C) & 1) == 0 || (signed char)g[0x8C] != 0) {
        p[6] = 3;
        p[0x168] = 1;
    } else {
        p[6]++;
        p[0x168] = 0;
    }
    func_001757E0(p, 0x13, p[0x168]);
}
