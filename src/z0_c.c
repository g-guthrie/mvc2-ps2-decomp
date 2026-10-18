typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
extern u8 D_004540E0[];

s32 func_00262600(u8 *p)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    if (func_00189310(p, D_004540E0, p + 0x398) == 0)
        return 0;
    if (*(s8 *)(*(u8 **)(p + 0x420)) == 0)
        return 0;
    if (p[0x20D] == 2) {
        if (*(s8 *)(p + 0x1E8) != 0)
            return 0;
        p[0x1E8] = *(s8 *)(p + 0x1E8) + 1;
    }
    func_0018A990(p, p + 0x398);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 4;
    func_00186A60(p, 0x1D);
    return 1;
}
