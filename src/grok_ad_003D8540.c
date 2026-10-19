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
extern void func_003D86A0(u8 *);
extern void func_003D8680(u8 *);
extern void func_003D8690(u8 *);

void func_003D8540(u8 *s0)
{
    s16 a2, a1;
    s0[3] = 1;
    if (D_004C2840[0x58]) {
        a2 = *(s16 *)((u8 *)D_004F24E4 + s0[0x8B] * 0x5B8);
        a1 = *(s16 *)((u8 *)D_004F24E4 + s0[0x8A] * 0x5B8);
    } else {
        a1 = (s16)(D_004F3BC4 + D_004F24E4[0] + D_004F3054);
        a2 = (s16)(D_004F417C + D_004F2A9C + D_004F360C);
    }
    if (a1 == a2)
        func_003D86A0(s0);
    else {
        if (a2 < a1)
            func_003D8680(s0);
        else
            func_003D8690(s0);
        {
            s8 a1b = (s8)s0[0x3E];
            u8 *obj = *(u8 **)(s0 + a1b * 12 + 0x18);
            if (D_004C2840[0x8F] == 0 && obj[1] == 0x19 && obj[0x539])
                s0[0x3E] = a1b ^ 1;
        }
    }
}
