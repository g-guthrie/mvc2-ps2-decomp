typedef unsigned char u8;
extern u8 D_004D18A0;
extern void func_0031D2B0(u8 *);
void func_0031D260(u8 *p)
{
    if (D_004D18A0 < 2) {
        p[0x13C] = 0;
    } else {
        p[6]++;
        p[0x13C] = 1;
        func_0031D2B0(p);
    }
}
