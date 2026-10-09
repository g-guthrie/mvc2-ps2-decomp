/* Advance the two-byte state and return its updated low byte. */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 D_004C26AC;
extern u8 D_004C26B0;
int func_00174170(void)
{
    u16 value = D_004C26AC + (D_004C26B0 << 8);
    u16 step = (value * 3) / 256;
    D_004C26AC += step;
    D_004C26B0 = step;
    return D_004C26AC;
}
