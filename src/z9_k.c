typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004449E0[];
extern u8 D_00444A00[];
extern u8 D_00444A20[];
extern u8 D_00444A30[];

void func_00154E10(u8 *p) {
    extern void func_003DAA40();
    extern f32 func_00154710(u8 *, u8 *, s16);
    extern double func_00119058(f32);
    f32 f;
    if (*(s16 *)(p + 0x1C) > 10) {
        func_003DAA40();
        return;
    }
    *(f32 *)(p + 0x54) = func_00154710(D_004449E0, p + 4, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x58) = func_00154710(D_00444A00, p + 5, *(s16 *)(p + 0x1C));
    f = func_00154710(D_00444A20, p + 6, *(s16 *)(p + 0x1C));
    *(u32 *)(p + 0x40) = (u16)(65536.0 * func_00119058(f) / 360.0 + 0.5);
    f = func_00154710(D_00444A30, p + 7, *(s16 *)(p + 0x1C));
    *(f32 *)(p + 0x78) = f;
    *(f32 *)(p + 0x7C) = f;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    *(s16 *)(p + 0x1C) += 1;
}
