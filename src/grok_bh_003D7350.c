typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
extern s32 D_004C2A58;
extern u8 D_0058CC40[];
extern s32 func_00122340(char *, char *, char *);
void func_003D7350(u8 a, u8 b, u8 c, char *fmt, ...)
{
    u8 *dst;
    s32 n;
    if (D_004C2A58 == 0x80)
        return;
    dst = D_0058CC40 + (D_004C2A58 << 6);
    dst[0] = a;
    dst[1] = b;
    *(s16 *)(dst + 2) = c;
    n = func_00122340((char *)(dst + 4), fmt, (char *)__builtin_next_arg(fmt) - 56);
    dst[4 + n] = 0;
    D_004C2A58 = D_004C2A58 + 1;
}
