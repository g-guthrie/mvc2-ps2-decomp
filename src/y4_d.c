typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_004B8188;
extern f32 D_004B819C;

extern s32 D_004C2818;
void func_00140420(u8 *p) {
    extern f32 func_00417440(s32);
    extern void func_003DAA40(u8 *);
    f32 d = 0.0399999991059f;
    f32 r;
    s16 n;
    *(s16 *)(p + 0xCC) = 0x1A;
    *(s32 *)(p + 0x84) = D_004C2818;
    *(f32 *)(p + 0x50) += d;
    *(f32 *)(p + 0x54) += d;
    r = func_00417440((u16)((u32)(s32)(65536.0 * (*(s16 *)(p + 0x1C) * 3) / 360.0 + 0.5)));
    *(f32 *)(p + 0x78) = r;
    *(f32 *)(p + 0x7C) = r;
    *(f32 *)(p + 0x80) = *(f32 *)(p + 0x78);
    n = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = n;
    if (n >= 0x3C) func_003DAA40(p);
}
