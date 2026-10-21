/* Stage selector: two-player pad input and formatted stage-number display. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern u16 D_004C291C[2];
extern u8 D_004C27D0;
extern char D_004B7668[];
extern void func_003D7350(u8, u8, u8, const char *, ...);
void func_0032BDF0(u8 *p)
{
    u16 pad;
    int x;
    pad = D_004C291C[(s8)p[0x538]];
    if (pad & 0x800) D_004C27D0--;
    pad = D_004C291C[(s8)p[0x538]];
    if (pad & 0x400) D_004C27D0++;
    D_004C27D0 = (u8)((D_004C27D0 + 17) % 17);
    pad = D_004C291C[(s8)p[0x538]];
    if (pad & 0x3FC) p[4] = 11;
    x = (s8)p[0x538] == 1 ? 22 : 4;
    func_003D7350((u8)x, 22, 0, D_004B7668, D_004C27D0);
}
