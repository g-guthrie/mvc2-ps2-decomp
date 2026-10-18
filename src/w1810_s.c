typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_006300C0[];
extern s32 D_00489000, D_00489018;
extern u8 D_004BDCF0[], D_004BDD18[];
u32 func_0040AB68(u32 x, u32 y, u32 z, u32 w) {
    extern s32 func_0011D8F8(void *, s32, s32);
    extern void func_0040AA90(void);
    extern s32 func_0040A740(u32, void *);
    extern void func_0011EB60(void *, u32);
    extern void func_004098A8(s32, void *);
    extern u32 func_0040A610(u32, void *, u32, u32);
    extern u32 func_0040A838(u32, u32);
    u32 v;
    u32 d;
    func_0011D8F8(D_006300C0, 0, 0x1000);
    if (D_00489000 == 0) func_0040AA90();
    if (x == 0 || y == 0 || z == 0) {
        func_0040AA90();
        return 0;
    }
    if (func_0040A740(x, D_006300C0) == 0) {
        if (D_00489018 != 2) func_0011EB60(D_004BDCF0, x);
        func_004098A8(0, D_004BDD18);
        return 0;
    }
    d = w + 9;
    v = func_0040A610(y, D_006300C0, z / d, w);
    return (z / d) * 8 + func_0040A838(y, v) * (w + 1);
}
