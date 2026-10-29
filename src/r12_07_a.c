/* func_003D63B0: ./try.sh src/r12_07_a.c "-O3 -Op -sdatathreshold 8" (MW 3.0.3; 3.0 also exact) */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 *D_004C2840;
extern u8 *D_004C2794;
extern s32 D_004C288C;
extern s16 D_004F7F7C[];
extern u8 D_004F7F50[];
extern u8 D_004773C0[];

#pragma push
#pragma opt_dead_assignments off
void func_003D63B0(void)
{
    extern void func_003D3B40(void);
    extern void func_003EA660(s32, s32 *);
    extern void func_003DF850(s32, s32);
    extern void func_0016DA30(s32, u8 *, f32, f32, f32, f32);
    f32 off;
    f32 sc;
    u8 *b;
    u8 *s;
    s16 n;
    s32 i;
    s32 j;

    b = D_004F7F50;
    if (D_004F7F7C[0] == 0) return;
    func_003D3B40();
    if (D_004C2840[0xB2] != 0) off = -170.0f; else off = 0.0f;
    j = *(s16 *)(b + 0x2A);
    s = *(u8 **)(*(u8 **)((u8 *)((*(s16 *)(b + 0x2C) - 1) * 12) + (u32)D_004C2794 + 0x18) + 0x1AC);
    n = s[0];
    func_003EA660(1, &D_004C288C);
    func_003DF850(4, D_004C288C);
    i = 0;
    do {
        j = j % n;
        func_0016DA30(-1, s + *(u16 *)(s + j * 2 + 2) + 2, 32.0f, 18.0f + 32.0f * (f32)i,
                      0.09000000357627869f, 1.0f);
        i++;
        j++;
    } while (i < 3);
    sc = 0.09000000357627869f;
    func_0016DA30(-0xEF00F0, D_004773C0, 440.0f + off, 114.0f, sc, 0.699999988079071f);
}
#pragma pop
