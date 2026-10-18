typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

extern u8 D_004BEFA0[], D_004BEFC0[], D_004BEFE0[], D_004BF000[], D_004BF020[];
extern void func_003DCAD0();
extern u8 D_0061C7A0[];
extern s32 func_003EA130();
s32 func_003EA0D0(u32 a0)
{
    u8 *p = D_0061C7A0 + (a0 - 1) * 64;
    if (a0 > 0x100) return 0;
    if (*(s16 *)(p + 0x2C) != 0) return func_003EA130(p);
    return 0;
}

extern u8 D_006207A0[];
extern s32 func_003E96A0();
s32 func_003E9580(s32 a0, u32 a1, s32 a2, s32 a3)
{
    u8 *p = D_006207A0 + (a1 - 1) * 64;
    if (a1 > 0x180) return 0;
    if (*(s16 *)(p + 0x2C) != 0) return func_003E96A0(a0, p, a2, a3, 0);
    return 0;
}
