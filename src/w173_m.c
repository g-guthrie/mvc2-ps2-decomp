typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 D_004C265C;
extern u8 D_004B8950[];
extern u8 D_004B8C10[];

void func_0016BB50(void)
{
    extern s32 func_0016C280(s32, s32, f32, f32, f32, f32);
    extern void func_003298B0(u32, s32, s32);
    extern void func_0016E8F0();
    extern void func_0016E950();
    extern void func_0016D4B0(u8 *, s32, f32);
    extern void func_0016D190();
    u8 *t;
    s16 h;
    h = *(s16 *)(D_004C2840 + 8) - 1;
    *(s16 *)(D_004C2840 + 8) = h;
    if (h == 0) {
        D_004C2840[5] = 7;
        *(s16 *)(D_004C2840 + 8) = 0x78;
        D_004C265C = func_0016C280(0x914, 6, 0.0f, -80.0f, 1.25f, 1.25f);
        func_003298B0(0xFF000000, 2, 0);
    } else {
        if (*(s8 *)(D_004C2840 + 0x29) == 1) t = D_004B8C10; else t = D_004B8950;
        func_0016E8F0();
        while (t[0] < 100) {
            func_0016D4B0(t, 0, 1.0f);
            t += 0x40;
        }
        func_0016E950();
        if (*(s16 *)(D_004C2840 + 8) == 0x28) {
            func_003298B0(0xFF000000, 0x20, 1);
        }
    }
    func_0016D190();
}
