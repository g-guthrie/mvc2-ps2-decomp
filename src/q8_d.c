typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0045B0F0[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
s32 func_002E4130(u8 *p) {
    u8 *q = p + 0x2B8;
    s32 r = 0;
    if (func_00189310(p, D_0045B0F0, p + 0x398) == 0) {
        return r;
    }
    if (**(s8 **)(p + 0x420) <= 2) {
        return r;
    }
    if (*(s8 *)(q + 9) != 0) {
        return r;
    }
    func_0018A990(p, p + 0x3A0);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    return 1;
}
