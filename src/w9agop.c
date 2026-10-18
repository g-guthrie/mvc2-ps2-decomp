typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 D_004C283C;
extern s32 func_00153AA0(void *p);
extern void func_00170DA0(s32 a, s32 b, s32 c, s32 d);
s32 func_0033DAD0(u8 *p) {
    s32 r;
    s32 z;
    if (p[4] != 0) return z;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) >= 1000) *(s16 *)(p + 0x1C) = 0;
    r = func_00153AA0(p);
    func_00170DA0(D_004C283C, 0x23, r, *(s16 *)(p + 0xCC));
    *(u32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = -0.001f * (f32)*(s16 *)(p + 0x1C);
    *(u32 *)(p + 0xD0) |= 0x20000;
}
