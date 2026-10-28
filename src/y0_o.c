typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044F290[];

s32 func_001E92E0(u8 *p)
{
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    s32 v;
    s32 r;
    r = func_00189310(p, D_0044F290, p + 0x390);
    if (r == 0)
        return 0;

    if ((double)(*(f32 *)(p + 0x60)) < 0.0) {
        if (*(f32 *)(p + 0x38) - *(f32 *)(p + 0x430) < 102.85713958740234f)
            return 1;
    }
    if (p[0x210] == 0) {
        v = *(s8 *)(p + 0x1E8);
        if (v != 0)
            return 0;
        p[0x1E8] = v + 1;
    }
    func_0018A990(p, p + 0x390);
    p[0x1FD] = 3;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
