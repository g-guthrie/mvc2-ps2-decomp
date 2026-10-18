typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310();
extern void func_0018A990();
extern u8 D_00450E40[];

s32 func_00216280(u8 *a) {
    if (func_00189310(a, D_00450E40, a + 0x3B8) == 0) return 0;
    if (**(s8 **)(a + 0x420) == 0) return 0;
    if (a[0x214] != 0) return 0;
    func_0018A990(a, a + 0x3B8);
    a[5] = 0;
    a[6] = 0;
    a[7] = 0;
    a[0x1FD] = 7;
    func_00186A60(a, 0x1D);
    return 1;
}
