typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
extern s16 D_004BFC20[4];

void func_001F2520(u8 *p)
{
    extern void func_00175700(u8 *);
    f32 z = 0.0f;
    u32 t;
    p[0x206] = 3;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x60) <= z) {
        t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x5C) = 1.66666663f * D_004BFC20[p[0x1B7]] / 256.0f;
        if (p[0x1E6] == 0)
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}
