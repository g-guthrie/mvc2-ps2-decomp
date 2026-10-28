typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef unsigned long long u64; typedef long long s64; typedef float f32;
extern f32 D_004625D0[];
extern f32 D_004625D4[];
void residual_00351D20(u8 *p) {
    extern void func_001757E0(u8 *, s32, u8);
    f32 f;
    p[0x13C] = 1;
    p[0x24] = 0xB;
    *(s16 *)(p + 0x1C) = 8;
    if (*(s16 *)(p + 0x140) != 0) f = D_004625D0[p[0x21] * 2];
    else f = -D_004625D0[p[0x21] * 2];
    *(f32 *)(p + 0x5C) = f;
    *(f32 *)(p + 0x60) = D_004625D4[p[0x21] * 2];
    func_001757E0(p, 0x15, p[0x21] + 0x1D);
}
