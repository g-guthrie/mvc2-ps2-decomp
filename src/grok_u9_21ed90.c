typedef unsigned char u8;

extern void func_0021D280(u8 *);
extern u8 D_004D18A0;

void residual_0021ED90(u8 *p)
{
    func_0021D280(p);
    if (D_004D18A0 < 2)
        p[0x13C] = 0;
    else {
        p[6]++;
        p[0x13C] = 1;
    }
}
