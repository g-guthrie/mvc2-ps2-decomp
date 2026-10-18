typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310();
extern void func_00186A60();
extern u8 D_0045C030[];

s32 func_002FC0B0(u8 *a) {
    u8 *q = a + 0x2B8;
    if (!func_00189310(a, D_0045C030, a + 0x390)) return 0;
    if (**(s8 **)(a + 0x420) == 0) return 0;
    if (*(s16 *)(q + 4) != 0) return 0;
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    a[0x1FD] = 2;
    func_00186A60(a, 0x1D);
    return 1;
}

