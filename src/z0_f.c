typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
extern f32 D_004452A0[];

void func_0015D810(u8 *p)
{
    extern double func_00119058(f32);
    extern void func_003DAA40();
    s32 n = *(s16 *)(p + 0x1C);
    if (n > 14) {
        func_003DAA40();
        return;
    }
    *(f32 *)(p + 0x74) = D_004452A0[n];
    if (*(s16 *)(p + 0x1C) < 9) {
        *(f32 *)(p + 0x50) += 0.25f;
        *(f32 *)(p + 0x54) -= 0.1f;
    }
    if (func_00119058(*(f32 *)(p + 0x54)) < 0.1)
        *(u32 *)(p + 0x54) = 0x3DCCCCCD;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
}
