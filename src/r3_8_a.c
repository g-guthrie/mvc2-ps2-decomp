typedef unsigned char u8; typedef signed char s8; typedef int s32;
extern s8 D_004B55F0[][3];

s32 func_00173600(u8 *p, s8 i)
{
    s32 k;
    for (k = 0; k < 3; k++)
        p[0x544 + k] = D_004B55F0[i][k];
    p[0x547] = 0x2A;
    p[0x520] = 7;
    return 0;
}
