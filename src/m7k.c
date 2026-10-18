typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_00458B40[];
extern s32 func_0018AA10();
s32 func_002AC030(u8 *a) {
    s16 v;
    if (!func_00189310(a, D_00458B40, a + 0x3A8)) return 0;
    if (!func_0018AA10(a, 0x300, &v) && !func_0018AA10(a, 0x60, &v)) return 0;
    func_0018A990(a, a + 0x3A8);
    a[0x1FD] = 0x10;
    a[5] = 0;
    func_00186A60(a, 0x1D);
    a[7] = 0;
    a[6] = 0;
    return 1;
}
