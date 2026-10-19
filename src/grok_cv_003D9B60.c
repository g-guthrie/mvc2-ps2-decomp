typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s8 *D_004C2840;
extern s8 D_004D18DE __attribute__((section(".bss")));
extern s8 D_004F25E9[];
extern s32 D_00477450[];
extern s8 D_004D18D6[];
extern void func_00131340(s32);

void func_003D9B60(s32 a0)
{
    s8 mode = D_004C2840[0x4C];
    s8 s0;
    if (mode == 1)
        return;
    s0 = D_004D18DE;
    if (s0 < 0)
        return;
    if (D_004F25E9[s0 * 0x5B8])
        return;
    a0 = D_00477450[a0];
    if (mode != 5)
        func_00131340(a0);
    a0 = (2 - D_004D18D6[s0]) * 50;
    mode = D_004C2840[0x4C];
    if (mode == 0 || mode == 7)
        func_00131340(a0);
}
