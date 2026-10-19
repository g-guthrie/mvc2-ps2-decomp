typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef signed short s16;

extern s32 func_003CE510(s32, s32);
extern void func_004026B0(s32, s32);
extern double dpmul(double, double);
extern s32 func_00119CE8(double);
extern s32 func_001E1FF0(s32);
extern void func_004020D8(s32, s16);
extern s8 *D_004C2840;
extern s32 D_004BFAE4;
extern s32 D_004C2B50;
extern u8 D_004C272A;
extern u8 D_004C2726;

void func_001E3FE0(void)
{
    s8 *g = D_004C2840;
    if (!g[0x43] && *(s32 *)(g + 0x14) == 0x40)
        return;
    if (func_003CE510(3, 6))
        return;
    if (D_004C2840[0x2D])
        return;
    if (D_004BFAE4 < 0)
        return;
    if (!D_004C2B50)
        return;
    func_004026B0(D_004C2B50, 0);
    if (D_004BFAE4 >= 0 && D_004BFAE4 < 0xB)
        D_004C2726 = (u8)func_00119CE8(dpmul(0.8, (double)D_004C272A));
    else
        D_004C2726 = D_004C272A;
    func_004020D8(D_004C2B50, (s16)func_001E1FF0(D_004C2726));
    D_004BFAE4 = -1;
}
