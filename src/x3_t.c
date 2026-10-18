typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern f32 D_004455E0[];

void func_00160EB0(u8 *p) {
    extern void func_003DAA40();
    extern double func_00119058(f32);
    s32 v = *(s16 *)(p + 0x1C);
    if (v > 40) {
        func_003DAA40(p);
        return;
    }
    if (v >= 28) {
        *(f32 *)(p + 0x50) += 0.4166666567325592f;
        *(f32 *)(p + 0x54) -= 0.16333334147930145f;
    }
    if (func_00119058(*(f32 *)(p + 0x54)) < 0.02) *(u32 *)(p + 0x54) = 0x3CA3D70A;
    *(f32 *)(p + 0x74) = D_004455E0[*(s16 *)(p + 0x1C)];
    {
        s32 t = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = t + 1;
    }
}
