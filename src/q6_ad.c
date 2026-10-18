typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_00444FB0[];
extern u8 D_00444FC0[];
extern f32 func_00154710(void *, void *, s32);
extern double func_00119058(f32);
extern void func_003DAA40(void);

void func_0015A330(u8 *p) {
    f32 g;
    if (13 <= *(s16 *)(p + 0x1C)) {
        func_003DAA40();
        return;
    }
    {
        f32 f = func_00154710(D_00444FB0, p + 4, *(s16 *)(p + 0x1C));
        double d = func_00119058(f);
        *(u32 *)(p + 0x40) = (u16)(u32)(65536.0 * d / 360.0 + 0.5);
    }
    g = func_00154710(D_00444FC0, p + 5, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x78) = g;
    *(f32 *)(p + 0x7C) = g;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
