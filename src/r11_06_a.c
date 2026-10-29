typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 D_004C2870, D_004C2848, D_004C284C;
extern u8 D_004D17C2[];
extern u16 D_004F4480[], D_004F4494[];
void func_00170C30(void)
{
    extern s32 func_003EC160(s32, s32);
    extern void func_0012F4C0(void), func_00170BF0(void), func_003D6B70(void);
    extern s32 func_0012F460(void), func_0016ECC0(void);
    extern void func_0012F3E0(u16 *), func_003D7630(void), func_0012F450(void), func_0016EE50(void), func_00417FB0(void);
    extern void func_0012F440(void), func_001E42A0(void), func_003D6FF0(void), func_00170D30(void), func_003D7400(void);
    extern void func_003D7640(void), func_0012DD90(void), func_00170D70(void), func_003ECD00(s32);
    {
        s32 r;
        do {
            r = func_003EC160(0x280, 0x1E0);
        } while (r == 0);
    }
    func_0012F4C0();
    func_00170BF0();
    func_003D6B70();
    for (;;) {
        func_0012F460();
        func_0016ECC0();
        func_0012F3E0(D_004F4480);
        func_0012F3E0(D_004F4494);
        func_003D7630();
        func_0012F450();
        if (D_004C2870 == 1 && D_004D17C2[0] != 1) {
            func_0016EE50();
            func_00417FB0();
            func_0012F440();
            D_004C2870 = 0;
        }
        func_001E42A0();
        D_004C2848 = 0;
        D_004C284C = 0;
        func_003D6FF0();
        func_00170D30();
        func_003D7400();
        func_003D7640();
        func_0012DD90();
        func_00170D70();
        func_003ECD00(0);
    }
}
