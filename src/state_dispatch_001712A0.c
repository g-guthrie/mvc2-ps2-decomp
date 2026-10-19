typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef void (*Handler)(s32, s32, s32, s32);
extern s8 *D_004C2840;
extern const u32 jtbl_00446A80[7];

void func_001712A0(s32 a0, s32 a1, s32 a2, s32 a3)
{
    ((Handler)jtbl_00446A80[D_004C2840[3]])(a0, a1, a2, a3);
}

void func_001712D0(s32 a0, s32 a1, s32 a2, s32 a3)
{
}
