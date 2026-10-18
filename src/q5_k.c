typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004452A0[];

void func_0015D730(u8 *p) {
    extern void func_003DAA40();
    extern double func_00119058(f32);
    if (*(s16 *)(p + 0x1C) > 0xE) {
        func_003DAA40(p);
        return;
    }
    *(f32 *)(p + 0x74) = D_004452A0[*(s16 *)(p + 0x1C)];
    if (*(s16 *)(p + 0x1C) < 9) {
        *(f32 *)(p + 0x50) -= 0.10000000149011612f;
        *(f32 *)(p + 0x54) += 0.25f;
    }
    if (func_00119058(*(f32 *)(p + 0x50)) < 0.1) {
        *(f32 *)(p + 0x50) = 0.10000000149011612f;
    }
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
