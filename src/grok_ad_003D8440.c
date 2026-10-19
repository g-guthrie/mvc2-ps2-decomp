typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840;
extern s16 D_004F24E4[];
extern s16 D_004F3054;
extern s16 D_004F3BC4;
extern s16 D_004F2A9C;
extern s16 D_004F360C;
extern s16 D_004F417C;
extern void func_003D86A0(void);
extern void func_003D8680(void);
extern void func_003D8690(void);

s32 func_003D8440(u8 *a0)
{
    s16 a3, a2;
    if (D_004C2840[0x58]) {
        a3 = D_004F24E4[a0[0x8B] * 0x5B8 / 2];
        a2 = D_004F24E4[a0[0x8A] * 0x5B8 / 2];
    } else {
        a2 = (s16)(D_004F3BC4 + D_004F24E4[0] + D_004F3054);
        a3 = (s16)(D_004F417C + D_004F2A9C + D_004F360C);
    }
    if ((s16)(a2 + a3) == 0) {
        func_003D86A0();
        return 0;
    }
    if (a3 == 0) {
        func_003D8680();
        return 0;
    }
    if (a2)
        return 0;
    func_003D8690();
    return 0;
}
