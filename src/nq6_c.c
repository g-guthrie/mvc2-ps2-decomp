typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
extern u8 D_004D18A6;
extern void (*jtbl_00463130[])(u8 *, u8 *);

void func_0035A720(u8 *a, u8 *b)
{
    extern s32 func_0035AAA0(u8 *, u8 *);
    u8 *o = *(u8 **)(a + 0x18);
    o[0x2C6] = 1;
    if (D_004D18A6 & (1 << (o[2] ^ 1))) return;
    if (func_0035AAA0(a, b) != 0) return;
    jtbl_00463130[a[0x21]](a, b);
}
